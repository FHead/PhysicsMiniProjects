HEPData=https://www.hepdata.net/record/ins1343112
HEPTable=https://www.hepdata.net/download/table/ins1343112

for i in `seq 6 7`
do
   echo $i
   curl $HEPTable/Table$i/1/yaml > YAML${i}.yaml

   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX
   grep '^[ ]*value' YAML${i}.yaml | awk '{print $2}' | grep -v "^$" | tr '\n' ',' | sed "s/,$//" > Y
   grep ' stat' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYStat
   grep 'sys,shape' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > EYSys1
   grep 'sys,corr' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > EYSys2
   FileLineAppend EYSys1 EYSys2 EYSys
   (awk '{print sqrt($1*$1+$2*$2)}' < EYSys) | tr '\n' ',' | sed "s/,$//" > EYSysLow
   (awk '{print sqrt($1*$1+$2*$2)}' < EYSys) | tr '\n' ',' | sed "s/,$//" > EYSysHigh
   grep 'sys,$T' YAML${i}.yaml | awk '{print $6}' | tr -d '}%' | awk '{print $1*0.01}' | head -n1 > Global
   grep ' CENTRALITY' YAML${i}.yaml | awk '{print $7}' | tr -d "}'" | sed "s/\.0//g" > Centrality

   FileName=ALICEJetRAA2015-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"PbPb\"," >> $FileName
   echo "   \"Energy\": \"2.76 TeV\"," >> $FileName
   echo "   \"Subject\": \"JetR2\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"PT\"," >> $FileName
   echo "   \"Centrality\": \"`cat Centrality`%\"," >> $FileName
   echo "   \"Record\": \"ALICE 2015\"," >> $FileName
   echo "   \"Selection\": \"eta < 0.5\"," >> $FileName
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
