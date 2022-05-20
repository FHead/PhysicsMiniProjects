


default: TestRun

TestRun: Execute
	./Execute --Input Input/0000/HiForestMiniAOD_14.root --Output Test.json

RunAll: Execute
	./Execute --Input `ls Input/*/*root | tr '\n' ','` --Output all.json

Execute: RemakeJSON.cpp
	g++ RemakeJSON.cpp -o Execute -I$(HOME)/RootMacros/ `root-config --cflags --glibs`


