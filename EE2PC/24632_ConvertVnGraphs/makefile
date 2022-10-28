



default: TestRunGraph

RunAll: Execute
	bash RunAll.sh

TestRun: Execute
	./Execute \
		--Input v2/EnergyCut_ge_100_TransPtCut_0.0_beam/BELLE_data_LEP2Data_plotout_extType0_LongRangePlotAndFit.txt \
		--DHFile vn.dh \
		--MultiplicityMin 5,10,20,30,35,40,41,42,43,44,45,46,47,48,49,50 \
		--MultiplicityMax 10,20,30,None,None,None,None,None,None,None,None,None,None,None,None,None \
		--PTMin 0.0 --PTMax None \
		--Type Data --Axis Beam

TestRunGraph: ExecuteGraph
	./ExecuteGraph --DHFile vn.dh --Output Graphs.root

Execute: ConvertToDHFile.cpp
	CompileRootMacro ConvertToDHFile.cpp Execute

ExecuteGraph: ConvertToGraph.cpp
	CompileRootMacro ConvertToGraph.cpp ExecuteGraph
