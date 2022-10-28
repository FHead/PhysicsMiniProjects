
DeployBase = ~/DropBox/Work/EE2PC/20220708

default: TestRun

TestRun: Execute
	./Execute --Data ../outRC/EnergyCut_ge_100_wideEtaRange_thrust/BELLE_data_LEP2Data_plotout_extType0_Corrected.root \
		--MC ../outRC/EnergyCut_ge_100_wideEtaRange_thrust/BELLE_tgen_LEP2MC_plotout_extType0.root \
		--DataHistogram ratio2PC_0_0_999_0_0 \
		--MCHistogram ratio2PC_0_0_999_0_0 \
		--Output Difference2PC_0_999.pdf \
		--Track "N_{track} > 0" \
		--Axis "Thrust axis"

Execute: PlotDifference.cpp
	CompileRootMacro PlotDifference.cpp Execute
	
RunAll: Execute
	bash RunAll.sh

Deploy:
	mkdir -p $(DeployBase)/2DDifference/
	cp Difference2PC_*.pdf $(DeployBase)/2DDifference
