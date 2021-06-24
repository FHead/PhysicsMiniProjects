
default: TestRun

TestRun: Execute
	./Execute --Mean 12,11,10,9,8 --RMS 2,2,2,2,2 --Output JetType1.root
	./Execute --Mean 8,9,10,11,12 --RMS 2,2,2,2,2 --Output JetType2.root

Execute: GenerateExample.cpp
	CompileRootMacro GenerateExample.cpp Execute

