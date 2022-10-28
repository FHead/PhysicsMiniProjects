#!/bin/bash

cp $1 TempInput.pdf
xelatex LatexTemplate.tex
mv LatexTemplate.pdf $1
rm TempInput.pdf LatexTemplate.aux LatexTemplate.log
