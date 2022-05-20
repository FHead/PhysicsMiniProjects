
default: RunTest

Prepare:
	rm -f Input
	ln -sf ../24513_UnfoldingPreparation/Output Input
	mkdir -p Output Plots

Clean:
	rm -f Output/*root
	rm -f Plots/*pdf

Execute: Unfold1D.cpp
	g++ `root-config --cflags --glibs` Unfold1D.cpp -o Execute \
		-lUnfold -lRooFitCore -lRooFit -lMinuit -lFoam -lRooStats \
		-I/Users/yichen/Programs/RooUnfold/RooUnfold/build \
		-L/Users/yichen/Programs/RooUnfold/RooUnfold/build -lRooUnfold

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


