DeployBase = ~/Dropbox/Work/EE2PC/20220708/

default: RunAll

RunAll: Execute
	bash RunAll.sh

AddAllMOD:
	bash AddAllMOD.sh

TestRun: Execute
	./Execute --Data ThrustData.root --DataHistogram h_deltaphi4_0_30_40_0_0 \
		--MC ThrustMC.root --MCHistogram h_deltaphi4_0_30_40_0_0 \
		--Output Thrust_30_40.pdf \
		--Selection "Thrust axis","1.6 < |#Delta#eta| < 3.2","30 #leq N_{track} < 40"

Execute: MakePlot.cpp
	CompileRootMacro MakePlot.cpp Execute

Deploy:
	mkdir -p $(DeployBase)/2PCDifference
	cp DataMC*pdf $(DeployBase)/2PCDifference/
	cp Difference*pdf $(DeployBase)/2PCDifference/
