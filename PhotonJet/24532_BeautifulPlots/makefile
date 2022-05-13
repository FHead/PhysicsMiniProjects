default: RunTest

Prepare:
	rm -f Input
	ln -sf ../24513_ActualUnfold/Output Input
	mkdir -p Plots

Deploy:
	mkdir -p ../FinalResult/UnfoldedPartial
	cp Plots/*png ../FinalResult/UnfoldedPartial

RunTest: RunAll

RunAll: Execute
	bash RunAll.sh

RunTestPP: Execute
	./Execute --Input Input/PPDPhi.root \
		--Systematic "None" \
		--Output Plots/PPDPhi.pdf \
		--FinalOutput Plots/ResultPPDPhi.pdf \
		--MCFile "" \
		--MCHistogram "" \
		--MCLabel "" \
		--PrimaryName HUnfoldedBayes5 \
		--DoSelfNormalize true \
		--GenPrimaryMin 0 --GenPrimaryMax 1 \
		--WorldXMin 0 --WorldXMax 0.999 \
		--WorldYMin 0 --WorldYMax 9.99 \
		--WorldRMin 0.901 --WorldRMax 1.099 --LogY false \
		--XLabel "" --YLabel "" --Binning "Jet" \
		--LegendX 0.48 --LegendY 0.4 --LegendSize 0.075 \
		--XAxis 305 --YAxis 505 --RAxis 305 --MarkerModifier 1.25 \
		--Texts 0,0.41,0.75," ",0,0.41,0.68," ",0,0.41,0.61," ",0,0.41,0.54," " \
		--Group 0,1,2,3,4,5,6,7,8 --Row 3 --Column 4
		
Execute: MakePaperPlot.cpp
	CompileRootMacro MakePaperPlot.cpp Execute

