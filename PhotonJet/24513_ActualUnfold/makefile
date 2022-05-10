
default: RunTest

Prepare:
	rm -f Input
	ln -sf ../24513_UnfoldingPreparation/Output Input
	mkdir -p Output Plots

Clean:
	rm -f Output/*root
	rm -f Plots/*pdf

Execute: Unfold1D.cpp
	CompileRootMacro Unfold1D.cpp Execute -lUnfold

RunTest: Execute
	./Execute --Input Input/AATest.root --Output Output/AATest.root \
		--Prior MC --DoBayes true --DoSVD true --DoInvert true --DoTUnfold false --DoFit true


