#!/bin/bash

for i in v2/*/*txt
do
   Axis=Thrust
   if [[ "$i" == *"beam"* ]]; then
      Axis=Beam
   fi

   Type=MC
   if [[ "$i" == *"Data"* ]]; then
      Type=Data
   fi

   Range=
   if [[ "$i" == *"wideEtaRange"* ]]; then
      Range=Wide
   fi

   Temp=`echo $i | grep -o "TransPtCut_\([0-9._]*\)"`
   PTMin=`echo $Temp | cut -d '_' -f 2`
   PTMax=`echo $Temp | cut -d '_' -f 3`

   if [[ "$PTMax" == "" ]]; then
      PTMax=None
   fi

   ./Execute \
      --Input $i \
      --DHFile vn.dh \
      --MultiplicityMin 10,20,30,40,50 \
      --MultiplicityMax 20,30,40,50,None \
      --PTMin $PTMin --PTMax $PTMax \
      --Type $Type --Axis $Axis$Range
done

