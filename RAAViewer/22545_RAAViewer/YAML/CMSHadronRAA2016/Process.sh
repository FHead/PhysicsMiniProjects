HEPData=https://www.hepdata.net/record/ins1496050
HEPTable=https://www.hepdata.net/download/table/ins1496050

for i in `seq 8 15`
do
   echo $i
   # curl $HEPTable/Table$i/2/yaml > YAML${i}.yaml

   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX
   grep '^[ ]*value' YAML${i}.yaml | awk '{print $2}' | grep -v "^$" | tr '\n' ',' | sed "s/,$//" > Y
   grep ' stat' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYStat
   grep ' sys, ' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > EYSys1
   grep ' asymerror: ' YAML${i}.yaml | awk '{print $4,$6}' | tr -d ',}' > EYSys2
   grep 'sys,lumi' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > EYSys3
   FileLineAppend EYSys1 EYSys2 Meow
   FileLineAppend Meow EYSys3 EYSys
   (awk '{print sqrt($1*$1+$2*$2+$4*$4)}' < EYSys) | tr '\n' ',' | sed "s/,$//" > EYSysLow
   (awk '{print sqrt($1*$1+$3*$3+$4*$4)}' < EYSys) | tr '\n' ',' | sed "s/,$//" > EYSysHigh
   grep ' CENTRALITY' YAML${i}.yaml | awk '{print $5}' | tr -d "}'" | sed "s/\.0//g" > Centrality

   System=PbPb
   Observable=RAA
   if [ $i == "16" ]; then
      System=pPb
      Observable=RpA
      echo "Inclusive" > Centrality
   fi

   FileName=CMSHadronRAA2016-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"$System\"," >> $FileName
   echo "   \"Energy\": \"5.02 TeV\"," >> $FileName
   echo "   \"Subject\": \"Hadron\"," >> $FileName
   echo "   \"Observable\": \"$Observable\"," >> $FileName
   echo "   \"Dependency\": \"PT\"," >> $FileName
   echo "   \"Centrality\": \"`cat Centrality`\"," >> $FileName
   echo "   \"Record\": \"CMS 2016\"," >> $FileName
   echo "   \"Selection\": \"eta < 1\"," >> $FileName
   echo "   \"Comment\": \"$HEPData\"," >> $FileName
   echo "   \"X\": ["`cat X`"]," >> $FileName
   echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
   echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
   echo "   \"Y\": ["`cat Y`"]," >> $FileName
   echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYSysLow\": ["`cat EYSysLow`"]," >> $FileName
   echo "   \"EYSysHigh\": ["`cat EYSysHigh`"]," >> $FileName
   echo "   \"GlobalUncertainty\": 0" >> $FileName
   echo "}," >> $FileName
done

for i in 16
do
   echo $i
   # curl $HEPTable/Table$i/2/yaml > YAML${i}.yaml

   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX
   grep '^[ ]*value' YAML${i}.yaml | awk '{print $2}' | grep -v "^$" | tr '\n' ',' | sed "s/,$//" > Y
   grep ' stat' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYStat
   grep ' asymerror: ' YAML${i}.yaml | awk '{print $4,$6}' | tr -d ',}' | Reformat 4 > EYSys1
   grep 'sys,lumi' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > EYSys2
   FileLineAppend EYSys1 EYSys2 EYSys
   (awk '{print sqrt($1*$1+$3*$3+$5*$5)}' < EYSys) | tr '\n' ',' | sed "s/,$//" > EYSysLow
   (awk '{print sqrt($2*$2+$4*$4+$5*$5)}' < EYSys) | tr '\n' ',' | sed "s/,$//" > EYSysHigh
   grep ' CENTRALITY' YAML${i}.yaml | awk '{print $5}' | tr -d "}'" | sed "s/\.0//g" > Centrality

   System=PbPb
   Observable=RAA
   if [ $i == "16" ]; then
      System=pPb
      Observable=RpA
      echo "Inclusive" > Centrality
   fi

   FileName=CMSHadronRAA2016-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"$System\"," >> $FileName
   echo "   \"Energy\": \"5.02 TeV\"," >> $FileName
   echo "   \"Subject\": \"Hadron\"," >> $FileName
   echo "   \"Observable\": \"$Observable\"," >> $FileName
   echo "   \"Dependency\": \"PT\"," >> $FileName
   echo "   \"Centrality\": \"`cat Centrality`\"," >> $FileName
   echo "   \"Record\": \"CMS 2016\"," >> $FileName
   echo "   \"Selection\": \"eta < 1\"," >> $FileName
   echo "   \"Comment\": \"$HEPData\"," >> $FileName
   echo "   \"X\": ["`cat X`"]," >> $FileName
   echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
   echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
   echo "   \"Y\": ["`cat Y`"]," >> $FileName
   echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYSysLow\": ["`cat EYSysLow`"]," >> $FileName
   echo "   \"EYSysHigh\": ["`cat EYSysHigh`"]," >> $FileName
   echo "   \"GlobalUncertainty\": 0" >> $FileName
   echo "}," >> $FileName
done
