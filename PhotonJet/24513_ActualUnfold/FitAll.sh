#!/bin/bash

for i in `ls MollyInput20220518/ | grep Nominal`
do
   echo $i
	./Execute --Input MollyInput20220518/$i \
      --Output MollyOutput20220518/$i \
		--Prior MC \
      --DoBayes true --DoRepeatedBayes true --DoSVD false --DoInvert true --DoTUnfold false --DoFit true
done
