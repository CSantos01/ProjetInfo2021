# ProjetInfo2021

Ce projet a pour objectif de simuler un système chaotique : le modèle météorologique de Lorenz.

#main.cpp:
  Code principal. 
  Prend en argument un fichier d'entrée 'file.in' contenant : un temps initial, un temps final, 3 coordoonées initiales, le paramètre rho et un pas de calcul
  Renvoie :
    Un premier fichier de sortie 'file.out' avec les conditions initiales "normales"
    Un second fichier de sortie 'file+.out' avec les conditions initiales "shiftés"
    Un troisième fichier 'distance.out' avec la distance entre les deux points en fonction du temps
  Le tout est calculé par la méthode d'Euler appliquée au système du modèle de Lorenz
  
#scriptAttractor2Points.gnu:
  Script permettant de tracer les attracteurs de Lorenz pour 2 fichiers de sortie
  Arguments:
    Deux fichiers de sortie avec 4 colonnes dont : le temps et 3 coordonnées spatiales au temps t
   Renvoie :
    Un fichier postscript .ps avec le tracé des attracteurs
    
#scriptTracéTemporel.gnu:

#script
