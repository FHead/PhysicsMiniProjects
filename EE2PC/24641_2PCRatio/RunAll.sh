#!/bin/bash

for i in Thrust Beam # ThrustWide
do
   for j in 0_999 10_20 20_30 30_40 40_50 50_999
   do
      Min=`echo $j | cut -d '_' -f 1`
      Max=`echo $j | cut -d '_' -f 2`
      String="$Min #leq N_{track} < $Max"
      if [[ "$Max" == "999" ]]; then
         String="N_{track} #geq $Min"
      fi

      MaxEta=3.2
      if [[ "$i" == *"Wide" ]];
      then
         MaxEta=10.0
      fi

      ./Execute --Data ${i}Data.root --DataHistogram h_deltaphi4_0_${j}_0_0 \
         --MC ${i}MC.root --MCHistogram h_deltaphi4_0_${j}_0_0 \
         --Output ${i}_${j}.pdf \
         --Selection "${i/Wide/} axis","1.6 < |#Delta#eta| < $MaxEta","$String"
   done
done

