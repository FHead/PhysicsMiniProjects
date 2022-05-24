
default: RunTest

Prepare:
	rm -f Input
	ln -sf ../24513_UnfoldingPreparation/Output Input
	mkdir -p Output Plots

DeepClean: Clean
	rm -rf RooUnfold
	rm -rf TUnfold
	rm -f TUnfoldV17.9.tgz

Clean:
	rm -f Output/*root
	rm -f Plots/*pdf

SetupPrerequisites: SetupRooUnfold SetupTUnfold

SetupRooUnfold:
	git clone ssh://git@gitlab.cern.ch:7999/RooUnfold/RooUnfold.git
	(cd RooUnfold/ && make -j4)

SetupTUnfold:
	curl https://www.desy.de/~sschmitt/TUnfold/TUnfold_V17.9.tgz -o TUnfold_V17.9.tgz
	mkdir -p TUnfold/
	tar zxvf TUnfold_V17.9.tgz --directory TUnfold/
	(cd TUnfold && make lib)

Execute: Unfold1D.cpp
	# CompileRootMacro Unfold1D.cpp Execute -lUnfold
	g++ Unfold1D.cpp -o Execute \
		-IRooUnfold/src -LRooUnfold/ -lRooUnfold \
		-ITUnfold/ -LTUnfold/  -lunfold \
		`root-config --cflags --glibs`
		# RooUnfold/build/*/obj/*.o
		# TUnfold/*.o RooUnfold/build/*/obj/*.o

RunTest: Execute
	./Execute --Input Input/PPDPhi.root --Output Output/PPDPhi.root \
		--Prior MC --DoBayes true --DoSVD false --DoInvert true --DoTUnfold false --DoFit true
	./Execute --Input Input/PPDR.root --Output Output/PPDR.root \
		--Prior MC --DoBayes true --DoSVD false --DoInvert true --DoTUnfold false --DoFit true
	./Execute --Input Input/AADPhi0.root --Output Output/AADPhi0.root \
		--Prior MC --DoBayes true --DoSVD false --DoInvert true --DoTUnfold false --DoFit true
	./Execute --Input Input/AADPhi1.root --Output Output/AADPhi1.root \
		--Prior MC --DoBayes true --DoSVD false --DoInvert true --DoTUnfold false --DoFit true
	./Execute --Input Input/AADPhi2.root --Output Output/AADPhi2.root \
		--Prior MC --DoBayes true --DoSVD false --DoInvert true --DoTUnfold false --DoFit true
	./Execute --Input Input/AADPhi3.root --Output Output/AADPhi3.root \
		--Prior MC --DoBayes true --DoSVD false --DoInvert true --DoTUnfold false --DoFit true
	./Execute --Input Input/AADR0.root --Output Output/AADR0.root \
		--Prior MC --DoBayes true --DoSVD false --DoInvert true --DoTUnfold false --DoFit true
	./Execute --Input Input/AADR1.root --Output Output/AADR1.root \
		--Prior MC --DoBayes true --DoSVD false --DoInvert true --DoTUnfold false --DoFit true
	./Execute --Input Input/AADR2.root --Output Output/AADR2.root \
		--Prior MC --DoBayes true --DoSVD false --DoInvert true --DoTUnfold false --DoFit true
	./Execute --Input Input/AADR3.root --Output Output/AADR3.root \
		--Prior MC --DoBayes true --DoSVD false --DoInvert true --DoTUnfold false --DoFit true

