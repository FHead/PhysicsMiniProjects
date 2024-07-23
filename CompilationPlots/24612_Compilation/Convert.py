#!/usr/local/bin/python3

import json5
import re
import sys

# InputFileName  = 'Fragments/CMSJetRAA2016-8a-1.json'
# OutputFileName = 'CMSJetRAA2016-8a-1.config'
# State          = 'CMSJetRAA2016'

if len(sys.argv) < 3:
    print('Need exactly three arguments: input state')
    exit()

InputFileName  = sys.argv[1]
OutputFileName = 'temp.config'
State          = sys.argv[2]

with open(InputFileName, 'r') as file:
    data = file.read().replace('\n', '')
    data = re.sub(r',$', r'', data)

    data = json5.loads(data)

    with open(OutputFileName, 'w') as outputfile:
        for Key in data:
            outputfile.write(State + ' ' + Key + ' string ' + str(data[Key]) + '\n')

