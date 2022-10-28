#!/bin/bash

# DataFile=../outRC/EnergyCut_ge_100_wideEtaRange_thrust/BELLE_data_LEP2Data_plotout_extType0_Corrected.root
# MCFile=../outRC/EnergyCut_ge_100_wideEtaRange_thrust/BELLE_tgen_LEP2MC_plotout_extType0.root

DataFile=../outRC/EnergyCut_ge_100_thrust/BELLE_data_LEP2Data_plotout_extType0_Corrected.root
MCFile=../outRC//EnergyCut_ge_100_thrust/BELLE_tgen_LEP2MC_plotout_extType0.root

for i in 0_999 10_20 20_30 30_40 40_50 50_999
do
   Min=`echo $i | cut -d '_' -f 1`
   Max=`echo $i | cut -d '_' -f 2`

   Track="$Min #leq N_{track} < $Max"
   if [[ $Max == 999 ]]; then
      Track="N_{track} #geq $Min"
   fi

   ./Execute --Data $DataFile \
      --MC $MCFile \
      --DataHistogram ratio2PC_0_${i}_0_0 \
      --MCHistogram ratio2PC_0_${i}_0_0 \
      --Output Difference2PC_${i}.pdf \
      --Track "$Track" \
      --Axis "Thrust axis"

   bash AddMOD.sh Difference2PC_${i}.pdf
done
