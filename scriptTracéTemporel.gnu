set title "Tracé temporel des trois coordonnées"
set xlabel "t"
plot "file.out" using 1:2 linecolor 1 title "x" with lines
replot "file.out" using 1:3 linecolor 2 title "y" with lines
replot "file.out" using 1:4 linecolor 3 title "z" with lines
set terminal postscript color
set output "TracéTemporel.ps"
replot
set terminal x11