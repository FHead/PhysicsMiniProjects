default: TestRun

TestRun: Execute
	./Execute --Input Graphs.root \
		--Data Data_Thrust_Multiplicity_50_None_v2 \
		--MC MC_Thrust_Multiplicity_50_None_v2

Execute: ExportCovariance.cpp
	CompileRootMacro ExportCovariance.cpp Execute
