#!/bin/bash

./Execute --Input Input/PPDPhi.root \
   --Systematic "None" \
   --Output Plots/PPDPhi.pdf \
   --FinalOutput Plots/ResultPPDPhi.pdf \
   --MCFile "" \
   --MCHistogram "" \
   --MCLabel "" \
   --PrimaryName HUnfoldedBayes3 \
   --DoSelfNormalize true \
   --GenPrimaryMin 0 --GenPrimaryMax 1 \
   --WorldXMin 0 --WorldXMax 0.999 \
   --WorldYMin 0 --WorldYMax 9.99 \
   --WorldRMin 0.901 --WorldRMax 1.099 --LogY false \
   --XLabel "#phi^{#gammaj}" --YLabel "1/N dN/d#phi^{#gammaj}" --Binning "p_{T}" \
   --LegendX 0.48 --LegendY 0.4 --LegendSize 0.075 \
   --XAxis 305 --YAxis 505 --RAxis 305 --MarkerModifier 1.25 \
   --Texts 0,0.41,0.75," ",0,0.41,0.68," ",0,0.41,0.61," ",0,0.41,0.54," " \
   --Group 0,1,2,3,4,5,6,7,8,9 --Row 3 --Column 4

./Execute --Input Input/PPDR.root \
   --Systematic "None" \
   --Output Plots/PPDR.pdf \
   --FinalOutput Plots/ResultPPDR.pdf \
   --MCFile "" \
   --MCHistogram "" \
   --MCLabel "" \
   --PrimaryName HUnfoldedBayes3 \
   --DoSelfNormalize true \
   --GenPrimaryMin 0 --GenPrimaryMax 0.3 \
   --WorldXMin 0 --WorldXMax 0.299 \
   --WorldYMin 0 --WorldYMax 29.99 \
   --WorldRMin 0.801 --WorldRMax 1.199 --LogY false \
   --XLabel "#deltaj" --YLabel "1/N dN/d#deltaj" --Binning "p_{T}" \
   --LegendX 0.48 --LegendY 0.4 --LegendSize 0.075 \
   --XAxis 305 --YAxis 505 --RAxis 305 --MarkerModifier 1.25 \
   --Texts 0,0.41,0.75," ",0,0.41,0.68," ",0,0.41,0.61," ",0,0.41,0.54," " \
   --Group 0,1,2,3,4,5,6,7,8,9 --Row 3 --Column 4

for Centrality in 0 1 2 3
do
   ./Execute --Input Input/AADPhi${Centrality}.root \
      --Systematic "None" \
      --Output Plots/AADPhi${Centrality}.pdf \
      --FinalOutput Plots/ResultAADPhi${Centrality}.pdf \
      --MCFile "" \
      --MCHistogram "" \
      --MCLabel "" \
      --PrimaryName HUnfoldedBayes3 \
      --DoSelfNormalize true \
      --GenPrimaryMin 0 --GenPrimaryMax 1 \
      --WorldXMin 0 --WorldXMax 0.999 \
      --WorldYMin 0 --WorldYMax 9.99 \
      --WorldRMin 0.901 --WorldRMax 1.099 --LogY false \
      --XLabel "#phi^{#gammaj}" --YLabel "1/N dN/d#phi^{#gammaj}" --Binning "p_{T}" \
      --LegendX 0.48 --LegendY 0.4 --LegendSize 0.075 \
      --XAxis 305 --YAxis 505 --RAxis 305 --MarkerModifier 1.25 \
      --Texts 0,0.41,0.75," ",0,0.41,0.68," ",0,0.41,0.61," ",0,0.41,0.54," " \
      --Group 0,1,2,3,4,5,6,7,8,9 --Row 3 --Column 4

   ./Execute --Input Input/AADR${Centrality}.root \
      --Systematic "None" \
      --Output Plots/AADR${Centrality}.pdf \
      --FinalOutput Plots/ResultAADR${Centrality}.pdf \
      --MCFile "" \
      --MCHistogram "" \
      --MCLabel "" \
      --PrimaryName HUnfoldedBayes3 \
      --DoSelfNormalize true \
      --GenPrimaryMin 0 --GenPrimaryMax 0.3 \
      --WorldXMin 0 --WorldXMax 0.299 \
      --WorldYMin 0 --WorldYMax 29.99 \
      --WorldRMin 0.801 --WorldRMax 1.199 --LogY false \
      --XLabel "#deltaj" --YLabel "1/N dN/d#deltaj" --Binning "p_{T}" \
      --LegendX 0.48 --LegendY 0.4 --LegendSize 0.075 \
      --XAxis 305 --YAxis 505 --RAxis 305 --MarkerModifier 1.25 \
      --Texts 0,0.41,0.75," ",0,0.41,0.68," ",0,0.41,0.61," ",0,0.41,0.54," " \
      --Group 0,1,2,3,4,5,6,7,8,9 --Row 3 --Column 4
done




