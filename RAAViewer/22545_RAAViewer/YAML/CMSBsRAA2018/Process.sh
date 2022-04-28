HEPData=https://www.hepdata.net/record/ins1697571
HEPTable=https://www.hepdata.net/download/table/ins1697571

for i in 4
do
   # curl $HEPTable/Table$i/1/yaml > YAML${i}.yaml

   grep '{value:' YAML${i}.yaml | awk '{print $3}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > X
   grep '{value:' YAML${i}.yaml | awk '{print 0}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EX

   grep '^[ ]*- value' YAML${i}.yaml | awk '{print $3}' | grep -v "^$" | tr '\n' ',' | sed "s/,$//" > Y
   grep ' stat' YAML${i}.yaml | awk '{print $3}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYStat
   grep ' sys' YAML${i}.yaml | awk '{print $3}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYSys

   FileName=CMSBsRAA2018-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"PbPb\"," >> $FileName
   echo "   \"Energy\": \"5.02 TeV\"," >> $FileName
   echo "   \"Subject\": \"Bs0\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"PT\"," >> $FileName
   echo "   \"Centrality\": \"Inclusive\"," >> $FileName
   echo "   \"Record\": \"CMS 2018\"," >> $FileName
   echo "   \"Selection\": \"y < 2.4\"," >> $FileName
   echo "   \"Comment\": \"$HEPData\"," >> $FileName
   echo "   \"X\": ["`cat X`"]," >> $FileName
   echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
   echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
   echo "   \"Y\": ["`cat Y`"]," >> $FileName
   echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYSysLow\": ["`cat EYSys`"]," >> $FileName
   echo "   \"EYSysHigh\": ["`cat EYSys`"]," >> $FileName
   echo "   \"GlobalUncertainty\": 0" >> $FileName
   echo "}," >> $FileName
done

