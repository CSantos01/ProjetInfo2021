set title "Tracé dans l'espace des phases pour 2 conditions initiales"
set xlabel "x(t)"
set ylabel "y(t)"
set zlabel "z(t)"
splot "file.out" using 2:3:4 with lines linecolor 2 title "Condition Initiale"
replot "file+.out" using 2:3:4 with lines linecolor 3 title "Condition Initiale décalée"
set terminal postscript color
set output "AttracteurLorenz2Points.ps"
replot
set terminal x11