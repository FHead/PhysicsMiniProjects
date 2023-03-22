#!/bin/bash

qpdf --empty --pages $1 2 -- TempInput.pdf
xelatex LatexTemplate.tex
mv LatexTemplate.pdf DataMC_$1

qpdf --empty --pages $1 3 -- TempInput.pdf
xelatex LatexTemplate.tex
mv LatexTemplate.pdf Difference_$1

rm TempInput.pdf LatexTemplate.aux LatexTemplate.log
