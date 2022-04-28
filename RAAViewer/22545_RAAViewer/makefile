

default: DeployTest Deploy
	echo Hello

CombineAll:
	bash Combine.sh
	ls -lh Data.json

DeployTest: CombineAll
	cp -r * ~/public/html/RAAViewerTest/

Deploy: CombineAll
	cp -r * ~/public/html/RAAViewer/
