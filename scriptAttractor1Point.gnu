set title "Tracé de l'Attracteur de Lorenz"
set xlabel "x(t)"
set ylabel "y(t)"
set zlabel "z(t)"
splot "file.out" using 2:3:4 with lines title "(x,y,z)"
set terminal postscript color
set output "AttracteurLorenz1Point.ps"
replot
set terminal x11