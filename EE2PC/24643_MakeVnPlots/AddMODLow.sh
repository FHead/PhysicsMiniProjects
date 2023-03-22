#!/bin/bash

cp $1 TempInput.pdf
xelatex LatexTemplateLow.tex
mv LatexTemplateLow.pdf $1
rm TempInput.pdf LatexTemplateLow.aux LatexTemplateLow.log
