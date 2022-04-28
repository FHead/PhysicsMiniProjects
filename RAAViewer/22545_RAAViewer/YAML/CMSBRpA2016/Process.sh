HEPData=https://www.hepdata.net/record/ins1390110
HEPTable=https://www.hepdata.net/download/table/ins1390110

for i in 4 5
do
   # curl $HEPTable/Table$i/1/yaml > YAML${i}.yaml

   # grep '^[ ]*- {value: ' YAML${i}.yaml | awk '{print $3}' | tr -d '}' | tr '\n' ',' | sed "s/,$//" > X
   # grep '^[ ]*- {value: ' YAML${i}.yaml | awk '{print 0}' | tr -d '}' | tr '\n' ',' | sed "s/,$//" > EX
   grep high YAML${i}.yaml | grep low | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep high YAML${i}.yaml | grep low | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX

   grep '^[ ]*value:' YAML${i}.yaml | awk '{print $2}' | grep -v "^$" | tr '\n' ',' | sed "s/,$//" > Y
   grep ' stat' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYStat
   grep 'sys,data' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > EYSys1
   grep 'asymerror' YAML${i}.yaml | awk '{print $4,$6}' | tr -d ',}' > EYSys2

   FileLineAppend EYSys1 EYSys2 EYSysTemp

   cat EYSysTemp | awk '{print sqrt($1*$1+$2*$2)}' | tr '\n' ',' | sed "s/,$//" > EYSysLow
   cat EYSysTemp | awk '{print sqrt($1*$1+$3*$3)}' | tr '\n' ',' | sed "s/,$//" > EYSysHigh

   Object=B0
   if [ $i == "4" ]; then
      Object=BPlus
   fi

   FileName=CMSBRpA2016-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"pPb\"," >> $FileName
   echo "   \"Energy\": \"5.02 TeV\"," >> $FileName
   echo "   \"Subject\": \"$Object\"," >> $FileName
   echo "   \"Observable\": \"RpA\"," >> $FileName
   echo "   \"Dependency\": \"PT\"," >> $FileName
   echo "   \"Centrality\": \"Inclusive\"," >> $FileName
   echo "   \"Record\": \"CMS 2016\"," >> $FileName
   echo "   \"Selection\": \"y < 2.4\"," >> $FileName
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


