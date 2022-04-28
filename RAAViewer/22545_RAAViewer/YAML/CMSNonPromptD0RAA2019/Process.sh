HEPData=https://www.hepdata.net/record/ins1700575
HEPTable=https://www.hepdata.net/download/table/ins1700575

for i in 4
do
   curl $HEPTable/Table$i/1/yaml > YAML${i}.yaml

   grep high YAML${i}.yaml | grep low | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep high YAML${i}.yaml | grep low | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX

   grep '^[ ]*value:' YAML${i}.yaml | awk '{print $2}' | grep -v "^$" | tr '\n' ',' | sed "s/,$//" > Y
   grep ' stat' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYStat
   grep ' sys' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYSys

   FileName=CMSNonPromptD0RAA2019-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"PbPb\"," >> $FileName
   echo "   \"Energy\": \"5.02 TeV\"," >> $FileName
   echo "   \"Subject\": \"NonPromptD0\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"PT\"," >> $FileName
   echo "   \"Centrality\": \"Inclusive\"," >> $FileName
   echo "   \"Record\": \"CMS 2019\"," >> $FileName
   echo "   \"Selection\": \"y < 1.0\"," >> $FileName
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


