#!/bin/bash

Tag=20220601
mkdir -p MollyOutput$Tag

echo Running tag $Tag
echo

for i in `ls MollyInput$Tag/ | grep Fine`
do
   echo $i
	./Execute --Input MollyInput$Tag/$i \
      --Output MollyOutput$Tag/$i \
		--Prior MC \
      --DoBayes true --DoRepeatedBayes false --DoSVD false --DoTSVD false --DoInvert true --DoTUnfold false --DoFit true
done
