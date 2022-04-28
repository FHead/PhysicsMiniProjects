for i in `seq 19 26`
do
   echo $i
   curl https://www.hepdata.net/download/table/ins1673184/Table$i/1/yaml > YAML${i}.yaml

   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($2-$1)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX
   grep ' - value' YAML${i}.yaml | awk '{print $3}' | tr '\n' ',' | sed "s/,$//" > Y
   grep ' stat' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYStat
   grep ' sys TAA ' YAML${i}.yaml | awk '{print $7}' | tr -d ',}' | head -n1 > EYTAA
   grep ' asymerror:' YAML${i}.yaml | awk '{print $4,$6}' | tr -d ',}' > EYSysTemp
   grep ' sys lumi' YAML${i}.yaml | awk '{print $7}' | tr -d ',}' > EYLumiTemp
   FileLineAppend EYSysTemp EYLumiTemp EYSys
   (awk '{print sqrt($1*$1+$3*$3)}' < EYSys) | tr '\n' ',' | sed "s/,$//" > EYSysLow
   (awk '{print sqrt($2*$2+$3*$3)}' < EYSys) | tr '\n' ',' | sed "s/,$//" > EYSysHigh
   grep ' CENTRALITY' YAML${i}.yaml | awk '{print $5}' | tr -d "'" > Centrality

   FileName=ATLASJetRAA2018-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"PbPb\"," >> $FileName
   echo "   \"Energy\": \"5.02 TeV\"," >> $FileName
   echo "   \"Subject\": \"Jet\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"PT\"," >> $FileName
   echo "   \"Centrality\": \"`cat Centrality`%\"," >> $FileName
   echo "   \"Record\": \"ATLAS 2018\"," >> $FileName
   echo "   \"Selection\": \"y < 2.8\"," >> $FileName
   echo "   \"Comment\": \"https://www.hepdata.net/record/ins1673184\"," >> $FileName
   echo "   \"X\": ["`cat X`"]," >> $FileName
   echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
   echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
   echo "   \"Y\": ["`cat Y`"]," >> $FileName
   echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYSysLow\": ["`cat EYSysLow`"]," >> $FileName
   echo "   \"EYSysHigh\": ["`cat EYSysHigh`"]," >> $FileName
   echo "   \"GlobalUncertainty\": `cat EYTAA`" >> $FileName
   echo "}," >> $FileName
done
