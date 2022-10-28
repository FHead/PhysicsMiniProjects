#!/bin/bash

for T in Beam Thrust # ThrustWide
do
   for R in 10_20 20_30 30_40 40_50 50_None
   do
      Min=`echo $R | cut -d "_" -f 1`
      Max=`echo $R | cut -d "_" -f 2`

      echo $Min $Max

      if [[ $Max == "None" ]]; then
         String="N_{track} #geq $Min"
      else
         String="${Min} #leq N_{track} < ${Max}"
      fi

      echo $String

      Type=${T/Wide/}

      for VN in 1 2 3
      do
         ./Execute \
            --File Graphs.root,Graphs.root \
            --Curve Data_${T}_Multiplicity_${R}_v${VN},MC_${T}_Multiplicity_${R}_v${VN} \
            --Label Data,"Archived MC" \
            --Type 1,0 \
            --Output Plots/${T}_Multiplicity_${R}_v${VN} \
            --Title ";p_{T} (GeV);v_{$VN}" \
            --XMin 0 --XMax 4.5 --YMin -1.5 --YMax 1.5 \
            --Color -${VN},-${VN} \
            --Marker 20,1 \
            --Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"$String",0.15,0.76,"$Type axis" \
            --LegendX 0.15 --LegendY 0.15
         
         ./Execute \
            --File Graphs.root \
            --Curve Data_${T}_Multiplicity_${R}_v${VN} \
            --DoShift true \
            --ShiftFile Graphs.root \
            --ShiftCurve MC_${T}_Multiplicity_${R}_v${VN} \
            --Label "Data - Archived MC" \
            --Type 1 \
            --Output Plots/${T}_Multiplicity_${R}_v${VN}_Shift \
            --Title ";p_{T} (GeV);#Deltav_{$VN}" \
            --XMin 0 --XMax 4.5 --YMin -0.5 --YMax 0.5 \
            --Color -${VN} \
            --Marker 20 \
            --Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"$String",0.15,0.76,"$Type axis" \
            --LegendX 0.15 --LegendY 0.15
         
         ./Execute \
            --File Graphs.root \
            --Curve Data_${T}_Multiplicity_${R}_v${VN} \
            --DoShift true \
            --ShiftFile Graphs.root \
            --ShiftCurve MC_${T}_Multiplicity_${R}_v${VN} \
            --Label "Data - Archived MC" \
            --Type 1 \
            --Output Plots/${T}_Multiplicity_${R}_v${VN}_ShiftZoom \
            --Title ";p_{T} (GeV);#Deltav_{$VN}" \
            --XMin 0 --XMax 4.5 --AutoY true \
            --Color -${VN} \
            --Marker 20 \
            --Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"$String",0.15,0.76,"$Type axis" \
            --LegendX 0.15 --LegendY 0.15
         
         ./Execute \
            --File Graphs.root \
            --Curve Data_${T}_Multiplicity_${R}_v${VN} \
            --DoSquareShift true \
            --ShiftFile Graphs.root \
            --ShiftCurve MC_${T}_Multiplicity_${R}_v${VN} \
            --Label "Data - Archived MC" \
            --Type 1 \
            --Output Plots/${T}_Multiplicity_${R}_v${VN}_SquareShiftZoom \
            --Title ";p_{T} (GeV);sign(#DeltaV_{$VN}) #sqrt{|#DeltaV_{$VN}|}" \
            --XMin 0 --XMax 4.5 --AutoY true \
            --Color -${VN} \
            --Marker 20 \
            --Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"$String",0.15,0.76,"$Type axis" \
            --LegendX 0.15 --LegendY 0.15
      done
   
      ./Execute \
         --File Graphs.root,Graphs.root,Graphs.root,Graphs.root,Graphs.root,Graphs.root \
         --Curve Data_${T}_Multiplicity_${R}_v1,Data_${T}_Multiplicity_${R}_v2,Data_${T}_Multiplicity_${R}_v3,MC_${T}_Multiplicity_${R}_v1,MC_${T}_Multiplicity_${R}_v2,MC_${T}_Multiplicity_${R}_v3 \
         --Label "Data v_{1}","v_{2}","v_{3}","Archived MC","None","None" \
         --Type 1,1,1,0,0,0 \
         --Output Plots/${T}_Multiplicity_${R}_v123 \
         --Title ";p_{T} (GeV);v_{n}" \
         --XMin 0 --XMax 4.5 --YMin -3.0 --YMax 3.0 \
         --Color -1,-2,-3,-1,-2,-3 \
         --Marker 20,20,20,1,1,1 \
         --Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"$String",0.15,0.76,"$Type axis" \
         --LegendX 0.14 --LegendY 0.14
  
      ./Execute \
         --File Graphs.root,Graphs.root,Graphs.root,Graphs.root,Graphs.root,Graphs.root \
         --Curve Data_${T}_Multiplicity_${R}_v1,Data_${T}_Multiplicity_${R}_v2,Data_${T}_Multiplicity_${R}_v3,MC_${T}_Multiplicity_${R}_v1,MC_${T}_Multiplicity_${R}_v2,MC_${T}_Multiplicity_${R}_v3 \
         --Label "Data v_{1}","v_{2}","v_{3}","Archived MC","None","None" \
         --Type 1,1,1,0,0,0 \
         --Output Plots/${T}_Multiplicity_${R}_v123_Zoom \
         --Title ";p_{T} (GeV);v_{n}" \
         --XMin 0 --XMax 4.5 --AutoY true --WideAutoY true \
         --Color -1,-2,-3,-1,-2,-3 \
         --Marker 20,20,20,1,1,1 \
         --Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"$String",0.15,0.76,"$Type axis" \
         --LegendX 0.14 --LegendY 0.14
   done
done

for T in Beam Thrust #ThrustWide
do
   for R in 0.0_0.5 0.5_1.0 1.0_2.0 2.0_3.0 3.0_None
   do
      Min=`echo $R | cut -d "_" -f 1`
      Max=`echo $R | cut -d "_" -f 2`

      echo $Min $Max

      if [[ $Max == "None" ]]; then
         String="p_{T} > $Min GeV"
      else
         String="${Min} < p_{T} < ${Max} GeV"
      fi

      echo $String

      for VN in 1 2 3
      do
         ./Execute \
            --File Graphs.root,Graphs.root \
            --Curve Data_${T}_PT_${R}_v${VN},MC_${T}_PT_${R}_v${VN} \
            --Label Data,"Archived MC" \
            --Type 1,0 \
            --Output Plots/${T}_PT_${R}_v${VN} \
            --Title ";Multiplicity;v_{$VN}" \
            --XMin 9 --XMax 75 --YMin -1.5 --YMax 1.5 \
            --Color -${VN},-${VN} \
            --Marker 20,1 \
            --Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"$String",0.15,0.76,"$Type axis" \
            --LegendX 0.15 --LegendY 0.15
         
         ./Execute \
            --File Graphs.root \
            --Curve Data_${T}_PT_${R}_v${VN} \
            --DoShift true \
            --ShiftFile Graphs.root \
            --ShiftCurve MC_${T}_PT_${R}_v${VN} \
            --Label "Data - Archived MC" \
            --Type 1 \
            --Output Plots/${T}_PT_${R}_v${VN}_Shift \
            --Title ";Multiplicity;#Deltav_{$VN}" \
            --XMin 9 --XMax 75 --YMin -0.5 --YMax 0.5 \
            --Color -${VN} \
            --Marker 20 \
            --Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"$String",0.15,0.76,"$Type axis" \
            --LegendX 0.15 --LegendY 0.15

         ./Execute \
            --File Graphs.root \
            --Curve Data_${T}_PT_${R}_v${VN} \
            --DoShift true \
            --ShiftFile Graphs.root \
            --ShiftCurve MC_${T}_PT_${R}_v${VN} \
            --Label "Data - Archived MC" \
            --Type 1 \
            --Output Plots/${T}_PT_${R}_v${VN}_ShiftZoom \
            --Title ";Multiplicity;#Deltav_{$VN}" \
            --XMin 9 --XMax 75 --AutoY true \
            --Color -${VN} \
            --Marker 20 \
            --Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"$String",0.15,0.76,"$Type axis" \
            --LegendX 0.15 --LegendY 0.15

         ./Execute \
            --File Graphs.root \
            --Curve Data_${T}_PT_${R}_v${VN} \
            --DoSquareShift true \
            --ShiftFile Graphs.root \
            --ShiftCurve MC_${T}_PT_${R}_v${VN} \
            --Label "Data - Archived MC" \
            --Type 1 \
            --Output Plots/${T}_PT_${R}_v${VN}_SquareShiftZoom \
            --Title ";Multiplicity;sign(#DeltaV_{$VN}) #sqrt{|#DeltaV_{$VN}|}" \
            --XMin 9 --XMax 75 --AutoY true \
            --Color -${VN} \
            --Marker 20 \
            --Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"$String",0.15,0.76,"$Type axis" \
            --LegendX 0.15 --LegendY 0.15
      done

      ./Execute \
         --File Graphs.root,Graphs.root,Graphs.root,Graphs.root,Graphs.root,Graphs.root \
         --Curve Data_${T}_PT_${R}_v1,Data_${T}_PT_${R}_v2,Data_${T}_PT_${R}_v3,MC_${T}_PT_${R}_v1,MC_${T}_PT_${R}_v2,MC_${T}_PT_${R}_v3 \
         --Label "Data v_{1}","v_{2}","v_{3}","Archived MC","None","None" \
         --Type 1,1,1,0,0,0 \
         --Output Plots/${T}_PT_${R}_v123 \
         --Title ";Multiplicity;v_{n}" \
         --XMin 9 --XMax 75 --YMin -3.0 --YMax 3.0 \
         --Color -1,-2,-3,-1,-2,-3 \
         --Marker 20,20,20,1,1,1 \
         --Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"$String",0.15,0.76,"$Type axis" \
         --LegendX 0.14 --LegendY 0.14

      ./Execute \
         --File Graphs.root,Graphs.root,Graphs.root,Graphs.root,Graphs.root,Graphs.root \
         --Curve Data_${T}_PT_${R}_v1,Data_${T}_PT_${R}_v2,Data_${T}_PT_${R}_v3,MC_${T}_PT_${R}_v1,MC_${T}_PT_${R}_v2,MC_${T}_PT_${R}_v3 \
         --Label "Data v_{1}","v_{2}","v_{3}","Archived MC","None","None" \
         --Type 1,1,1,0,0,0 \
         --Output Plots/${T}_PT_${R}_v123_Zoom \
         --Title ";Multiplicity;v_{n}" \
         --XMin 9 --XMax 75 --AutoY true --WideAutoY true \
         --Color -1,-2,-3,-1,-2,-3 \
         --Marker 20,20,20,1,1,1 \
         --Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"$String",0.15,0.76,"$Type axis" \
         --LegendX 0.14 --LegendY 0.14
   done
done
