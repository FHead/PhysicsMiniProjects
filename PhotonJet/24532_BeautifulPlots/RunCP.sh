#!/bin/bash

./Execute --Input MollyOutput20220518/PPNominal0.root \
   --Systematic "None" \
   --Output Plots/AANominalCP.pdf \
   --FinalOutput Plots/ResultAANominalCP.pdf \
   --MCFile MollyOutput20220518/AANominal0.root,MollyOutput20220518/AANominal1.root,MollyOutput20220518/AANominal2.root,MollyOutput20220518/AANominal3.root \
   --MCHistogram HUnfoldedBayes2,HUnfoldedBayes2,HUnfoldedBayes2,HUnfoldedBayes2 \
   --MCLabel "50-90%","30-50%","10-30%","0-10%" \
   --PrimaryName HUnfoldedBayes2 \
   --DoSelfNormalize true \
   --GenPrimaryMin 0 --GenPrimaryMax 0.3 \
   --WorldXMin 0 --WorldXMax 0.299 \
   --WorldYMin 0 --WorldYMax 39.99 \
   --WorldRMin 0.801 --WorldRMax 1.199 --LogY false \
   --XLabel "#deltaj" --YLabel "1/N dN/d#deltaj" --Binning "p_{T}" \
   --LegendX 0.48 --LegendY 0.4 --LegendSize 0.075 \
   --XAxis 305 --YAxis 505 --RAxis 305 --MarkerModifier 1.25 \
   --Texts 0,0.41,0.75," ",0,0.41,0.68," ",0,0.41,0.61," ",0,0.41,0.54," " \
   --Group 0,1,2,3,4,5,6,7,8,9 --Row 3 --Column 4

./Execute --Input MollyOutput20220518/PPNominal0.root \
   --Systematic "None" \
   --Output Plots/AANominalCPLog.pdf \
   --FinalOutput Plots/ResultAANominalCPLog.pdf \
   --MCFile MollyOutput20220518/AANominal0.root,MollyOutput20220518/AANominal1.root,MollyOutput20220518/AANominal2.root,MollyOutput20220518/AANominal3.root \
   --MCHistogram HUnfoldedBayes2,HUnfoldedBayes2,HUnfoldedBayes2,HUnfoldedBayes2 \
   --MCLabel "50-90%","30-50%","10-30%","0-10%" \
   --PrimaryName HUnfoldedBayes2 \
   --DoSelfNormalize true \
   --GenPrimaryMin 0 --GenPrimaryMax 0.3 \
   --WorldXMin 0 --WorldXMax 0.299 \
   --WorldYMin 0.0011 --WorldYMax 99.99 \
   --WorldRMin 0.801 --WorldRMax 1.199 --LogY true \
   --XLabel "#deltaj" --YLabel "1/N dN/d#deltaj" --Binning "p_{T}" \
   --LegendX 0.48 --LegendY 0.4 --LegendSize 0.075 \
   --XAxis 305 --YAxis 101 --RAxis 305 --MarkerModifier 1.25 \
   --Texts 0,0.41,0.75," ",0,0.41,0.68," ",0,0.41,0.61," ",0,0.41,0.54," " \
   --Group 0,1,2,3,4,5,6,7,8,9 --Row 3 --Column 4

./Execute --Input MollyOutput20220518/PPNominal0.root \
   --Systematic "None" \
   --Output Plots/AANominalCPReco.pdf \
   --FinalOutput Plots/ResultAANominalCPReco.pdf \
   --MCFile MollyOutput20220518/AANominal0.root,MollyOutput20220518/AANominal1.root,MollyOutput20220518/AANominal2.root,MollyOutput20220518/AANominal3.root \
   --MCHistogram HInput,HInput,HInput,HInput \
   --MCLabel "50-90%","30-50%","10-30%","0-10%" \
   --PrimaryName HInput \
   --DoSelfNormalize true \
   --DoReco true --RecoPrimaryMin 0 --RecoPrimaryMax 0.3 \
   --WorldXMin 0 --WorldXMax 0.299 \
   --WorldYMin 0 --WorldYMax 39.99 \
   --WorldRMin 0.001 --WorldRMax 1.999 --LogY false \
   --XLabel "#deltaj" --YLabel "1/N dN/d#deltaj" --Binning "p_{T}" \
   --LegendX 0.48 --LegendY 0.4 --LegendSize 0.075 --DataLabel "pp data" \
   --XAxis 305 --YAxis 505 --RAxis 305 --MarkerModifier 1.25 \
   --Texts 0,0.41,0.75," ",0,0.41,0.68," ",0,0.41,0.61," ",0,0.41,0.54," " \
   --Group 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 --Row 4 --Column 4

./Execute --Input MollyOutput20220518/PPNominal0.root \
   --Systematic "None" \
   --Output Plots/PPRefoldCheck.pdf \
   --FinalOutput Plots/ResultPPRefoldCheck.pdf \
   --MCFile MollyOutput20220518/PPNominal0.root \
   --MCHistogram HInput \
   --MCLabel "Input" \
   --PrimaryName HRefoldedBayes2 \
   --DoSelfNormalize true \
   --DoReco true --RecoPrimaryMin 0 --RecoPrimaryMax 0.3 \
   --WorldXMin 0 --WorldXMax 0.299 \
   --WorldYMin 0 --WorldYMax 39.99 \
   --WorldRMin 0.001 --WorldRMax 1.999 --LogY false \
   --XLabel "#deltaj" --YLabel "1/N dN/d#deltaj" --Binning "p_{T}" \
   --LegendX 0.48 --LegendY 0.4 --LegendSize 0.075 --DataLabel "Refolded" \
   --XAxis 305 --YAxis 505 --RAxis 305 --MarkerModifier 1.25 \
   --Texts 0,0.41,0.75," ",0,0.41,0.68," ",0,0.41,0.61," ",0,0.41,0.54," " \
   --Group 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 --Row 4 --Column 4

for C in 0 1 2 3
do
   ./Execute --Input MollyOutput20220518/AANominal${C}.root \
      --Systematic "None" \
      --Output Plots/AARefoldCheck${C}.pdf \
      --FinalOutput Plots/ResultAARefoldCheck${C}.pdf \
      --MCFile MollyOutput20220518/AANominal${C}.root \
      --MCHistogram HInput \
      --MCLabel "Input" \
      --PrimaryName HRefoldedBayes3 \
      --DoSelfNormalize true \
      --DoReco true --RecoPrimaryMin 0 --RecoPrimaryMax 0.3 \
      --WorldXMin 0 --WorldXMax 0.299 \
      --WorldYMin 0 --WorldYMax 39.99 \
      --WorldRMin 0.001 --WorldRMax 1.999 --LogY false \
      --XLabel "#deltaj" --YLabel "1/N dN/d#deltaj" --Binning "p_{T}" \
      --LegendX 0.48 --LegendY 0.4 --LegendSize 0.075 --DataLabel "Refolded" \
      --XAxis 305 --YAxis 505 --RAxis 305 --MarkerModifier 1.25 \
      --Texts 0,0.41,0.75," ",0,0.41,0.68," ",0,0.41,0.61," ",0,0.41,0.54," " \
      --Group 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 --Row 4 --Column 4
done





