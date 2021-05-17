# ProjetInfo2021

Ce projet a pour objectif de simuler un système chaotique : le modèle météorologique de Lorenz.
Le code principal se situe dans 'main.cpp'.
Les fichiers 'file.in' et 'file.out' correspondent aux fichier d'entrée et de sortie.
Les fichiers .gnu sont des scripts pour plots diverses choses.

#main.cpp:
  Code principal. 
  Prend en argument un fichier d'entrée 'file.in' contenant : un temps initial, un temps final, trois coordoonées initiales, le paramètre rho et un pas de calcul
  Renvoie :
    Un premier fichier de sortie 'file.out' avec les conditions initiales "normales"
    Un second fichier de sortie 'file+.out' avec les conditions initiales "shiftés"
    Un troisième fichier 'distance.out' avec la distance entre les deux points en fonction du temps
  Le tout est calculé par la méthode d'Euler appliquée au système du modèle de Lorenz
  
#scriptAttractor1Point.gnu:
  Script permettant de tracer l'attracteur de Lorenz pour un fichier de sortie

#scriptAttractor2Points.gnu:
  Script permettant de tracer les attracteurs de Lorenz pour deux fichiers de sortie
  Arguments:
    Deux fichiers de sortie avec quatre colonnes dont : le temps et 3 coordonnées spatiales au temps t
   Renvoie :
    Un fichier postscript .ps avec le tracé des attracteurs
    
#scriptTracéTemporel.gnu:
  Script permettant de tracer, en fonction du temps, x,y et z. Renvoie un fichier postscript .ps

#scriptTracéx2ConditionsInitiales.gnu:
  Script permettant de tracer la variable x du système pour deux conditions initiales. Renvoie un fichier postscript .ps
  
#scriptDistanceConditionsInitiales.gnu:
  Script permettant de tracer la distance entre deux conditions initiales dans le temps. Renvoie un fichier postscript .ps
