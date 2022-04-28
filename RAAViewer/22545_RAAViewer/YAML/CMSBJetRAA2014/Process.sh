HEPData=https://www.hepdata.net/record/ins1269454
HEPTable=https://www.hepdata.net/download/table/ins1269454

for i in `seq 7 13`
do
   echo $i
   # curl $HEPTable/Table$i/1/yaml > YAML${i}.yaml
done

# vs PT
for i in 7 10 11 12 13
do
   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX
   grep '^[ ]*value' YAML${i}.yaml | awk '{print $2}' | grep -v "^$" | tr '\n' ',' | sed "s/,$//" > Y
   grep ' stat' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYStat
   grep ' sys' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYSysLow
   grep ' sys' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYSysHigh
   grep 'sys,global pp' YAML${i}.yaml | awk '{print $7}' | tr -d '}%' | awk '{print $1*0.01}' | head -n1 > Global1
   grep 'sys,global PbPb' YAML${i}.yaml | awk '{print $8}' | tr -d '}%' | awk '{print $1*0.01}' | head -n1 > Global2
   grep ' CENTRALITY' YAML${i}.yaml | awk '{print $7}' | tr -d "'}" | sed "s/\.0//g" > Centrality

   FileLineAppend Global1 Global2 GlobalTemp
   (awk '{print sqrt($1*$1+$2*$2)}' < GlobalTemp) | head -n1 > Global

   FileName=CMSBJetRAA2014-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"PbPb\"," >> $FileName
   echo "   \"Energy\": \"2.76 TeV\"," >> $FileName
   echo "   \"Subject\": \"BJetR3\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"PT\"," >> $FileName
   echo "   \"Centrality\": \"`cat Centrality`%\"," >> $FileName
   echo "   \"Record\": \"CMS 2014\"," >> $FileName
   echo "   \"Selection\": \"eta < 2.0\"," >> $FileName
   echo "   \"Comment\": \"$HEPData\"," >> $FileName
   echo "   \"X\": ["`cat X`"]," >> $FileName
   echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
   echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
   echo "   \"Y\": ["`cat Y`"]," >> $FileName
   echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYSysLow\": ["`cat EYSysLow`"]," >> $FileName
   echo "   \"EYSysHigh\": ["`cat EYSysHigh`"]," >> $FileName
   echo "   \"GlobalUncertainty\": `cat Global`" >> $FileName
   echo "}," >> $FileName
done

# vs centrality
for i in 8 9
do
   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX
   grep ' \- {value:' YAML${i}.yaml | awk '{print $3}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > N
   grep ' \- {value:' YAML${i}.yaml | awk '{print 0}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EN
   grep '^[ ]*value' YAML${i}.yaml | awk '{print $2}' | grep -v "^$" | tr '\n' ',' | sed "s/,$//" > Y
   grep ' stat' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYStat
   grep ' sys' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYSysLow
   grep ' sys' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYSysHigh
   grep 'sys,global pp' YAML${i}.yaml | awk '{print $7}' | tr -d '}%' | awk '{print $1*0.01}' | head -n1 > Global1
   grep 'sys,global PbPb' YAML${i}.yaml | awk '{print $8}' | tr -d '}%' | awk '{print $1*0.01}' | head -n1 > Global2

   FileLineAppend Global1 Global2 GlobalTemp
   (awk '{print sqrt($1*$1+$2*$2)}' < GlobalTemp) | head -n1 > Global

   grep 'name: PT' YAML${i}.yaml | awk '{print $9}' | tr -d '}' | sed "s/\.0//g" > PTRange

   FileName=CMSBJetRAA2014-${i}-1.json

   echo "{" > $FileName
   echo "   \"System\": \"PbPb\"," >> $FileName
   echo "   \"Energy\": \"2.76 TeV\"," >> $FileName
   echo "   \"Subject\": \"BJetR3\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"Centrality\"," >> $FileName
   echo "   \"Centrality\": \"0-100%\"," >> $FileName
   echo "   \"Record\": \"CMS 2014\"," >> $FileName
   echo "   \"Selection\": \"eta < 2.0, PT = `cat PTRange`\"," >> $FileName
   echo "   \"Comment\": \"$HEPData\"," >> $FileName
   echo "   \"X\": ["`cat X`"]," >> $FileName
   echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
   echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
   echo "   \"Y\": ["`cat Y`"]," >> $FileName
   echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYSysLow\": ["`cat EYSysLow`"]," >> $FileName
   echo "   \"EYSysHigh\": ["`cat EYSysHigh`"]," >> $FileName
   echo "   \"GlobalUncertainty\": `cat Global`" >> $FileName
   echo "}," >> $FileName

   FileName=CMSBJetRAA2014-${i}-2.json

   echo "{" > $FileName
   echo "   \"System\": \"PbPb\"," >> $FileName
   echo "   \"Energy\": \"2.76 TeV\"," >> $FileName
   echo "   \"Subject\": \"BJetR3\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"NPart\"," >> $FileName
   echo "   \"Centrality\": \"0-100%\"," >> $FileName
   echo "   \"Record\": \"CMS 2014\"," >> $FileName
   echo "   \"Selection\": \"eta < 2.0, PT = `cat PTRange`\"," >> $FileName
   echo "   \"Comment\": \"$HEPData\"," >> $FileName
   echo "   \"X\": ["`cat N`"]," >> $FileName
   echo "   \"EXLow\": ["`cat EN`"]," >> $FileName
   echo "   \"EXHigh\": ["`cat EN`"]," >> $FileName
   echo "   \"Y\": ["`cat Y`"]," >> $FileName
   echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYSysLow\": ["`cat EYSysLow`"]," >> $FileName
   echo "   \"EYSysHigh\": ["`cat EYSysHigh`"]," >> $FileName
   echo "   \"GlobalUncertainty\": `cat Global`" >> $FileName
   echo "}," >> $FileName
done
