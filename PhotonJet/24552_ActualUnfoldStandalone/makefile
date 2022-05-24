
default: RunTest

Prepare:
	rm -f Input
	ln -sf ../24513_UnfoldingPreparation/Output Input
	mkdir -p Output Plots

DeepClean: Clean
	rm -rf RooUnfold

Clean:
	rm -f Output/*root
	rm -f Plots/*pdf

SetupPrerequisites: SetupRooUnfold

SetupRooUnfold:
	git clone ssh://git@gitlab.cern.ch:7999/RooUnfold/RooUnfold.git
	(cd RooUnfold/ && make -j4)

SetupRooUnfoldCMake:
	git clone ssh://git@gitlab.cern.ch:7999/RooUnfold/RooUnfold.git
	(cd RooUnfold/ && mkdir -p build && cd build/ && cmake .. && make -j4)

Execute: Unfold1D.cpp
	g++ Unfold1D.cpp -o Execute \
		-IRooUnfold/src -LRooUnfold/ -lRooUnfold \
		`root-config --cflags --glibs`

# If you use the CMake version
# Execute: Unfold1D.cpp
# 	g++ Unfold1D.cpp -o Execute \
# 		-IRooUnfold/build -LRooUnfold/build -lRooUnfold \
# 		`root-config --cflags --glibs`

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

