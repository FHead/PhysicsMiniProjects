#!/bin/bash

for i in `ls MollyInput20220523/`
do
   echo $i
	./Execute --Input MollyInput20220523/$i \
      --Output MollyOutput20220523/$i \
		--Prior MC \
      --DoBayes true --DoRepeatedBayes true --DoSVD false --DoInvert true --DoTUnfold false --DoFit true
done
