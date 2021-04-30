#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

//Constantes du problème :
const double sig = 10.0; //nombre de Prandtl
const double bet = 8.0/3.0; //paramètre beta


//Posons la classe qui nous servira à définir un point dans l'espace des phases (x,y,z) \in R³
//Classe vecteur :
class vecteur 
{
    private :
        double t; //instant t de l'itération
        double x,y,z; //coordonnées R³
    public :
        vecteur();
        vecteur(double, double, double, double);
        vecteur(const vecteur &);
        ~vecteur(){};
        void initialise(double, double, double, double);
        void affiche();
        //accesseurs:
        double Gettime() const {return t;}
        double Getx() const {return x;}
        double Gety() const {return y;}
        double Getz() const {return z;}
        //mutateurs:
        void Settime(double _t) {t = _t;}
        void Setx(double _x) {x = _x;}
        void Sety(double _y) {y = _y;}
        void Setz(double _z) {z = _z;}

};
//Définitions des méthodes de la classe:
vecteur::vecteur()
{
    t=0;
    x=0;
    y=0;
    z=0;
}

vecteur::vecteur(double _t, double _x, double _y, double _z)
{
    t=_t;
    x=_x;
    y=_y;
    z=_z;
}

vecteur::vecteur(const vecteur& X_i)
//X_i désigne le vecteur de R*R³ ayant pour coordonées (t,x,y,z)
{
    t=X_i.Gettime();
    x=X_i.Getx();
    y=X_i.Gety();
    z=X_i.Getz();
}

void vecteur::initialise(double _t, double _x, double _y, double _z)
{
    t=_t;
    x=_x;
    y=_y;
    z=_z;
}

void vecteur::affiche()
{
    cout<<"t,x,y,z = "<<t<<","<<x<<","<<y<<","<<z<<endl;
}

//Nous devons maintenant définir la fonction F telle que dX/dt=F(X)
//Fonction Function:
vecteur Function(vecteur X_i, double rho)
//On considère ici X_i tel que défini dans le constructeurs de recopie
{
    vecteur F(X_i.Gettime(),sig*(X_i.Gety()-X_i.Getx()),(rho-X_i.Getz())*X_i.Getx() - X_i.Gety(),X_i.Getx()*X_i.Gety()-bet*X_i.Getz());
    return F;
}

//Programmons alors la méthode d'Euler:
vecteur Euler(vecteur X_i, vecteur F, double h, double rho)
//Arguments : deux "vecteurs" de "dimension" 4 X_i et F, un pas d'itération h et le nombre de Rayleigh rho
//Renvoie : un "vecteur" de "dimension" 4 X_j, avec j=i+1, calculé par : X_j = X_i + F*h
//Attention : Cette opération ne s'applique qu'aux coordonnées (x,y,z),
//pas à t qui lui sera itéré par "t=t+h"
{
    vecteur X_j(X_i.Gettime()+h,X_i.Getx()+F.Getx()*h,X_i.Gety()+F.Gety()*h,X_i.Getz()+F.Getz()*h);
    return X_j;
}

//Une dernière méthode utile à coder est la distance euclidienne entre 2 vecteurs :
double distance(vecteur X_i,vecteur X_j)
//Arguments : deux "vecteurs" de "dimension" 4 X_i et X_j
//Renvoie : la distance euclidienne entre ces deux vecteurs pour les coordonnées spatiales
{
    return(sqrt(pow(X_i.Getx()-X_j.Getx(),2)+pow(X_i.Gety()-X_j.Gety(),2)+pow(X_i.Getz()-X_j.Getz(),2)));
} 

int main()
{
    ifstream ifile("file.in"); 
    //Le fichier d'entrée "file.in" doit contenir : 
    //un temps initial, un temps final, des valeurs initiales (x,y,z)
    //le nombre de Rayleigh rho, un pas h
    ofstream ofile("file.out");
    //Ce fichier de sortie contiendra:
    //l'ensemble des valeurs de X_i calculés pour les conditions intiales données, par la méthode d'Euler, que l'on pourra utiliser dans un script gnuplot
    ofstream oofile("file+.out");
    //Ce fichier de sortie contiendra:
    //l'ensemble des valeurs de X_i calculé pour les coordonnées initiales décalées d'un certain d, par la méthode d'Euler, que l'on pourra utiliser dans un script gnuplot
    ofstream dfile("distance.out");
    //Ce fichier de sortie contiendra :
    //Le temps et la distance entre 2 vecteurs au temps t

    //Introduction des paramètres et objets utilisés:
    double t0,tf;//temps initial et final
    double x0,y0,z0;//coordonnées initiales
    double X0,Y0,Z0;//coordonnées initiales décalées
    double rho; //nombre de Rayleigh
    double h;//pas d'itération en temps
    double _t;//un instant
    double d=0.1;//un décalage sur les conditions initiales
    double D;//la distance entre deux vecteurs

    //Lecture du fichier d'entrée:
    ifile>>t0>>tf;
    ifile>>x0>>y0>>z0;
    ifile>>rho;
    ifile>>h;

    _t=t0;

    //Coordonnées décalées
    X0=x0+d;
    Y0=y0+d;
    Z0=z0+d;
    
    vecteur X_0(t0,x0,y0,z0);//Le vecteur de conditions initiales "normales"
    ofile<<X_0.Gettime()<<" "<<X_0.Getx()<<" "<<X_0.Gety()<<" "<<X_0.Getz()<<endl;//Intégration de X_0 dans le fichier de sortie
    vecteur X_0p(t0,X0,Y0,Z0);//Le vecteur de conditions initiales décalées
    oofile<<X_0p.Gettime()<<" "<<X_0p.Getx()<<" "<<X_0p.Gety()<<" "<<X_0p.Getz()<<endl;//Intégration de X_0p (pour prime) dans le fichier de sortie

    D=distance(X_0,X_0p);//calcul de la distance au temps initial
    dfile<<_t<<" "<<D<<endl;//intégration dans un fichier de sortie
    
    //Boucle de calcul des X_i et intégration dans le fichier de sortie "file.out"
    while(_t<tf)
    {
        _t=_t+h;

        vecteur F(Function(X_0,rho));//Applcation de F à X_0
        vecteur Fp(Function(X_0p,rho));
        vecteur X_1(Euler(X_0,F,h,rho));//Création du "vecteur" X_1 par la méthode d'Euler
        vecteur X_1p(Euler(X_0p,Fp,h,rho));//Création du "vecteur" X_1p par la méthode d'Euler

        ofile<<X_1.Gettime()<<" "<<X_1.Getx()<<" "<<X_1.Gety()<<" "<<X_1.Getz()<<endl;//Intégration de X_1 dans le fichier de sortie
        oofile<<X_1p.Gettime()<<" "<<X_1p.Getx()<<" "<<X_1p.Gety()<<" "<<X_1p.Getz()<<endl;//Intégration de X_1p dans le fichier de sortie

        D=distance(X_1,X_1p);//calcul de la distance entre X_i et X_ip
        dfile<<_t<<" "<<D<<endl;//intégration dans un fichier de sortie

        X_0=X_1;//X_0 devient X_1 et "X_1 devient X_2"
        X_0p=X_1p;
    }
    return 0;
}    