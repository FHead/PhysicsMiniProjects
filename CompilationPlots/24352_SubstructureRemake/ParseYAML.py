from urllib.request import urlopen
import re, sys, ssl, yaml, os, math, argparse

parser = argparse.ArgumentParser()
parser.add_argument("--HEPDataID",          default = "1672011")
parser.add_argument("--TableVersion",       default = "2")
parser.add_argument("--TableNumber",        default = "4")
parser.add_argument("--FileNameBase",       default = "CMSPsi2SpPb2019")
parser.add_argument("--System",             default = "PbPb")
parser.add_argument("--Energy",             default = "5.02 TeV")
parser.add_argument("--Record",             default = "CMS 2019")
parser.add_argument("--Object",             default = "Psi2S")
parser.add_argument("--Unique",             default = "")
parser.add_argument("--Global",             default = "0.00")
parser.add_argument("--CentralityOverride", default = "")
parser.add_argument("--YNameOverride",      default = "")
parser.add_argument("--FileNumber",         default = "")
parser.add_argument("--IgnoreColumn",       default = "")
args = parser.parse_args()

if ',' in args.Object:
   args.Object = args.Object.split(',')
else:
   args.Object = [args.Object]

if ',' in args.Global:
   args.Global = args.Global.split(',')
else:
   args.Global = [args.Global]

if ',' in args.IgnoreColumn:
   args.IgnoreColumn = args.IgnoreColumn.split(',')
else:
   args.IgnoreColumn = [args.IgnoreColumn]

if ';' in args.Unique:
   args.Unique = args.Unique.split(';')
else:
   args.Unique = [args.Unique]

if ';' in args.YNameOverride:
   args.YNameOverride = args.YNameOverride.split(';')
else:
   args.YNameOverride = [args.YNameOverride]

if args.TableNumber.isdigit() == False:
   DataURL = "https://www.hepdata.net/download/table/ins" + args.HEPDataID + \
      "/" + args.TableNumber + "/" + args.TableVersion + "/yaml"
   if args.FileNumber == "":
      args.FileNumber = "0"
else:
   DataURL = "https://www.hepdata.net/download/table/ins" + args.HEPDataID + \
      "/Table" + args.TableNumber + "/" + args.TableVersion + "/yaml"
   if args.FileNumber == "":
      args.FileNumber = args.TableNumber

# ET^HF|\eta|>4

def NotationCleanUp(name):
   name = name.replace('CENTRALITY', 'Centrality')
   name = name.replace('\it', '')
   name = name.replace('$', '')
   name = name.replace('{', '')
   name = name.replace('}', '')
   name = name.replace('\\textrm', '')
   name = name.replace('\\mathrm', '')
   name = name.replace('\\rm', '')
   name = name.replace(' range ', ' ')
   name = name.replace('[GEV]', '')
   name = name.replace('[GeV]', '')
   name = name.replace('(GeV)', '')
   name = name.replace('GEV/C', '')
   name = name.replace('GEV/c', '')
   name = name.replace('GeV/c', '')
   name = name.replace('GeV', '')
   name = name.replace('[]', '')
   name = name.replace('()', '')
   name = name.replace('\u27E8', '')
   name = name.replace('\u27E9', '')
   name = re.sub('([0-9])-', r'\1 - ', name)
   name = name.replace('p_T', 'PT')
   name = name.replace('pT', 'PT')
   name = name.replace('E_T', 'ET')
   name = name.replace(' TO ', ' - ')
   name = name.replace(' to ', ' - ')
   name = re.sub('PT\([A-Za-z0-9= -]*\)', 'PT', name)
   name = re.sub('^[A-Za-z0-9-]* PT', 'PT', name)
   name = name.replace("(RF=CM)", "")
   name = name.replace("(RF=LAB)", "")
   name = name.replace('y_CM', 'y')
   name = name.replace('YRAP', 'y')
   name = re.sub('RAPIDITY\([A-Za-z0-9]*\)', 'y', name)
   name = name.replace('RAP', 'y')
   name = name.replace('ABS(y)', 'y')
   name = name.replace('ABS(Y)', 'y')
   name = name.replace('YSTAR', 'y*')
   name = name.replace('<PT>', 'PT')
   name = name.replace('<y*>', 'y*')
   name = name.replace('\\eta', 'eta')
   name = name.replace('ETA', 'eta')
   name = name.replace('Eta', 'eta')
   name = name.replace('eta Range = ', '')
   name = name.replace('|1|', '1.0')
   name = name.replace('etaRAP', 'eta')
   name = name.replace('etay', 'eta')
   name = name.replace('TRACK eta', 'eta')
   name = re.sub('eta\([A-Za-z0-9= -]*\)', 'eta', name)
   name = re.sub('ET\([A-Za-z0-9= -]*\)', 'ET', name)
   name = name.replace('ABS(eta)', 'eta')
   name = re.sub("R\^W\^[+-]", "R", name)
   name = name.replace('p+A', 'pA')
   name = name.replace('R_pA', 'RpA')
   name = name.replace('R_p_Pb', 'RpA')
   name = name.replace('R_pPb', 'RpA')
   name = name.replace('RpPb', 'RpA')
   name = name.replace('RPPB', 'RpA')
   name = name.replace('R_FB', 'RFB')
   name = name.replace('N_part', "NPart")
   name = name.replace('y = |y|', 'y')
   name = name.replace('|y|', 'y')
   name = re.sub('^[ ]*R_AA', 'RAA', name)
   name = re.sub('RpA[ ]*\([A-Za-z0-9= -]*\)', 'RpA', name)
   name = re.sub('RpA[ ]*\([A-Za-z0-9= -]*\)', 'RpA', name)
   name = re.sub('RpA[ ]*\([A-Za-z0-9= -]*\)', 'RpA', name)
   name = re.sub('RpA[ ]*\([A-Za-z0-9= -]*\)', 'RpA', name)
   name = re.sub("\^([A-Za-z|><0-9]*)", " (\\1)", name)
   name = re.sub('RpA[ ]*\([A-Za-z0-9= -]*\)', 'RpA', name)
   name = re.sub(r'[A-Za-z()0-9]*[\\/ ]RAA', 'RAA', name)
   name = re.sub(r'[A-Za-z()0-9]*[\\/ ]RAA', 'RAA', name)
   name = re.sub(r'[A-Za-z()0-9]*[\\/ ]RAA', 'RAA', name)
   name = re.sub(r'[A-Za-z()0-9]*[\\/ ]RAA', 'RAA', name)
   name = name.replace("rAA", "RAA")
   name = name.replace('RpA (Z)', 'RpA')
   name = name.replace(' = < ', ' < ')
   name = name.replace(' = <', ' < ')
   name = name.replace(' = > ', ' > ')
   name = name.replace(' = >', ' > ')
   name = name.replace("< dNch/deta >", "dNdEta")
   name = re.sub('RAA [ ]*\([A-Za-z0-9= -]*\)', 'RAA', name)
   name = name.replace("R_ AA", "RAA")
   name = name.replace("M(MU+ MU-)", "M")
   name = name.replace("p_ T", "PT")
   name = name.replace(" <= PT < ", " - ")
   name = re.sub('[ ]*,', ',', name)
   name = name.replace("(stat)", "")
   name = name.replace("(systUncorr)", "")
   name = name.replace("(systCorr)", "")
   name = re.sub('RAA[ +-]*', 'RAA', name)
   name = name.replace('()', '')
   name = name.replace('ET \gamma', 'ET')
   name = name.replace('|eta \gamma|', 'eta')
   name = name.replace('v22', 'v2{2}')
   name = name.replace('v24', 'v2{4}')
   name = name.replace('v26', 'v2{6}')
   name = name.replace('v28', 'v2{8}')
   name = name.replace('v32', 'v3{2}')
   name = name.replace('v34', 'v3{4}')
   name = name.replace('v36', 'v3{6}')
   name = name.replace('v38', 'v3{8}')
   name = name.replace('Range = ', '')
   name = name.replace('PTjet', 'PT')
   return name.strip()

context = ssl._create_unverified_context()
response = urlopen(DataURL, context = context)
content = response.read().decode('utf-8')
yaml_data = yaml.safe_load(re.sub('\t$', '\n', content))

# print('independent')
# print(yaml_data['independent_variables'][0])

# print('dependent[0]')
# print(yaml_data['dependent_variables'])

HasN = False
HasX = False
N = []
ENLow = []
ENHigh = []

for iX in yaml_data['independent_variables']:
   if "NPART" in iX['header']['name'] or "Npart" in iX['header']['name'] or "NPart" in NotationCleanUp(iX['header']['name']) or ('units' in iX['header'] and 'NPART' in iX['header']['units']):
      HasN = True
      N = [((i['low'] + i['high'])/2 if 'high' in i else i['value']) for i in iX['values']]
      ENLow = [((i['high'] - i['low'])/2 if 'high' in i else 0) for i in iX['values']]
      ENHigh = ENLow
   else:
      HasX = True
      NRow = len(iX['values'])
      XName = iX['header']['name']
      X = [((i['low'] + i['high'])/2 if 'high' in i else i['value']) for i in iX['values']]
      EXLow = [((i['high'] - i['low'])/2 if 'high' in i else 0) for i in iX['values']]
      EXHigh = EXLow

if HasX == True:
   for iX in range(0, len(X)):
      if '+-' in str(X[iX]):
         print(X[iX])
         Temp = list(map(float, re.findall('[0-9\.]+', X[iX])))
         print(Temp)
         X[iX] = Temp[0]
         EXLow[iX] = Temp[1]
         EXHigh[iX] = Temp[1]
      elif '%' in str(X[iX]) and '-' in str(X[iX]):
         print(X[iX])
         Temp = list(map(float, re.findall('[0-9\.]+', X[iX])))
         print(Temp)
         X[iX] = (Temp[0] + Temp[1]) / 2
         EXLow[iX] = X[iX] - min(Temp[0], Temp[1])
         EXHigh[iX] = max(Temp[0], Temp[1]) - X[iX]

NCol = len(yaml_data['dependent_variables'])
# print("Number of dependent variables = " + str(NCol))

for iR in range(0, NCol):
   if yaml_data['dependent_variables'][iR]['header']['name'] == 'NPART' or \
      'Npart' in yaml_data['dependent_variables'][iR]['header']['name']:
      HasN = True

      N = [i['value'] for i in yaml_data['dependent_variables'][iR]['values']]
      ENLow = [abs(i['errors'][0]['asymerror']['minus']) for i in yaml_data['dependent_variables'][iR]['values']]
      ENHigh = [abs(i['errors'][0]['asymerror']['plus']) for i in yaml_data['dependent_variables'][iR]['values']]

if HasN == True:
   for iN in range(0, len(N)):
      if '+-' in str(N[iN]):
         Temp = list(map(float, re.findall('[0-9\.]+', N[iN])))
         print(Temp)
         N[iN] = Temp[0]
         ENLow[iN] = Temp[1]
         ENHigh[iN] = Temp[1]
      elif '+' in str(N[iN]) and '-' in str(N[iN]):
         Temp = list(map(float, re.findall('[0-9\.+-]+', N[iN])))
         print(Temp)
         N[iN] = Temp[0]
         ENLow[iN] = -min(Temp[1], Temp[2])
         ENHigh[iN] = max(Temp[1], Temp[2])

for iR in range(0, NCol):
   if yaml_data['dependent_variables'][iR]['header']['name'] == 'NPART':
      continue
   if 'Npart' in yaml_data['dependent_variables'][iR]['header']['name']:
      continue
   if 'sigma' in yaml_data['dependent_variables'][iR]['header']['name']:
      continue
   if str(iR + 1) in args.IgnoreColumn:
      continue
   Values = yaml_data['dependent_variables'][iR]['values']

   YName = yaml_data['dependent_variables'][iR]['header']['name']
   Y = [(i['value'] if i['value'] != 'empty' else '--') for i in Values]
   Errors = [(i['errors'] if 'errors' in i else ['placeholder']) for i in Values]

   Global = []
   GlobalTAA = 0
   if 'qualifiers' in yaml_data['dependent_variables'][iR]:
      for i in yaml_data['dependent_variables'][iR]['qualifiers']:
         if 'GLOBAL UNCERT' in i['name'] or 'Global uncert' in i['name']:
            GlobalItem = i['value']
            GlobalItem = re.findall('[0-9\.+-]+', str(GlobalItem))
            Global.append(GlobalItem)
         if 'T_{AA}' in i['name']:
            GlobalTAA = i['value']
            GlobalTAA = float(re.findall('[0-9\.+-]+', GlobalTAA)[0]) * 0.01
   if iR < len(args.Global):
      GlobalTAA = math.sqrt(GlobalTAA**2 + float(args.Global[iR])**2)
   else:
      GlobalTAA = math.sqrt(GlobalTAA**2 + float(args.Global[0])**2)

   Centrality = 'Inclusive'
   if 'qualifiers' in yaml_data['dependent_variables'][iR]:
      for i in yaml_data['dependent_variables'][iR]['qualifiers']:
         if 'CENT' in i['name'] or 'Centrality' in i['name']:
            CentralityList = re.findall('[0-9\.]+', i['value'])
            print(len(CentralityList))
            if len(CentralityList) <= 2:
               Centrality = '-'.join(CentralityList)
               Centrality = Centrality + "%"
            else:
               Centrality = CentralityList[0] + '-' + CentralityList[1] + '% / ' \
                  + CentralityList[2] + '-' + CentralityList[3] + '%'
            Centrality = re.sub('\.0', '', Centrality)
   if args.CentralityOverride != '':
      Centrality = args.CentralityOverride
   print("centrality:", Centrality)

   Unique = []
   if 'qualifiers' in yaml_data['dependent_variables'][iR]:
      for i in yaml_data['dependent_variables'][iR]['qualifiers']:
         IsUnique = True
         if 'RE' == i['name']:
            IsUnique = False
         if 'CENT' in i['name']:
            IsUnique = False
         if 'LUMI' in i['name']:
            IsUnique = False
         if 'Centrality' in i['name']:
            IsUnique = False
         if 'SQRT' in i['name']:
            IsUnique = False
         if 'sqrt' in i['name']:
            IsUnique = False
         if 'GLOBAL' in i['name']:
            IsUnique = False
         if 'Global' in i['name']:
            IsUnique = False
         if i['name'] == 'R':
            IsUnique = False
         if 'R(JET)' in i['name']:
            IsUnique = False
         if 'R(JETS)' in i['name']:
            IsUnique = False
         if 'T_{AA}' in i['name']:
            IsUnique = False
         if i['name'] == '' or i['value'] == '':
            IsUnique = False
         if str(i['value']) == "0":
            IsUnique = False
         if str(i['value']) == "0.0":
            IsUnique = False
         if 'Particle' in i['name']:
            IsUnique = False
         if 'Range' in i['name']:
            IsUnique = False

         InAll = True
         Ignored = 0
         for j in range(0, NCol):
            if str(j + 1) in args.IgnoreColumn:
               Ignored = Ignored + 1
               continue
            if iR != j:
               if 'qualifiers' in yaml_data['dependent_variables'][j] and \
                  i not in yaml_data['dependent_variables'][j]['qualifiers'] and \
                  'sigma' not in yaml_data['dependent_variables'][j]['header']['name']:
                  InAll = False
         if NCol - Ignored > 1 and InAll == True:
            IsUnique = False

         if IsUnique == True:
            Unique.append(i)
   if iR < len(args.Unique):
      if args.Unique[iR] != "":
         Unique.append(args.Unique[iR])
   else:
      if args.Unique[0] != "":
         Unique.append(args.Unique[0])
   print("Unique")
   print(Unique)

   UniqueString = ''
   UniqueArray = [((i["name"] + " = " + str(i["value"])) if 'name' in i else i) for i in Unique]
   UniqueArray = [i for i in UniqueArray if "jet radius = " not in i]
   UniqueArray = [i for i in UniqueArray if "jet method = " not in i]
   if len(UniqueArray) > 0:
      print(UniqueArray)
      UniqueArray = [i.replace(' = < ', ' < ').strip() for i in UniqueArray]
      UniqueString = ', '.join(UniqueArray)
   if UniqueString == '':
      UniqueString = "--";

   GlobalUncertainty = GlobalTAA
   for GlobalItem in Global:
      if len(GlobalItem) == 1:
         ThisUncertainty = float(GlobalItem[0]) * 0.01
         GlobalUncertainty = math.sqrt(GlobalUncertainty**2 + ThisUncertainty**2)
   print('Global')
   print(Global)

   EYStatLow = []
   EYStatHigh = []
   EYSysLow = []
   EYSysHigh = []

   for ii, i in enumerate(Errors):
      StatLow = 0
      StatHigh = 0
      SysLow = 0
      SysHigh = 0

      CurrentY = float(Y[ii]) if (Y[ii] != '--' and Y[ii] != '-') else 0

      if i[0] != 'placeholder':
         for j in i:
            if 'symerror' in j and '%' in str(j['symerror']):
               j['symerror'] = float(re.findall('[0-9\.]+', j['symerror'])[0]) * 0.01 * CurrentY
            if 'asymerror' in j and '%' in str(j['asymerror']['minus']):
               j['asymerror']['minus'] = float(re.findall('[0-9\.]+', j['asymerror']['minus'])[0]) * 0.01 * CurrentY
            if 'asymerror' in j and '%' in str(j['asymerror']['plus']):
               j['asymerror']['plus'] = float(re.findall('[0-9\.]+', j['asymerror']['plus'])[0]) * 0.01 * CurrentY

            if 'label' in j:
               if 'stat' in j['label'] and 'symerror' in j:
                  StatLow = j['symerror']
                  StatHigh = j['symerror']
               if 'stat' in j['label'] and 'asymerror' in j:
                  StatLow = j['asymerror']['minus']
                  StatHigh = j['asymerror']['plus']
               if 'stat' not in j['label'] and 'symerror' in j:
                  SysLow = math.sqrt(SysLow **2 + float(j['symerror'])**2)
                  SysHigh = math.sqrt(SysHigh **2 + float(j['symerror'])**2)
               if 'stat' not in j['label'] and 'asymerror' in j:
                  SysLow = math.sqrt(SysLow **2 + float(j['asymerror']['minus'])**2)
                  SysHigh = math.sqrt(SysHigh**2 + float(j['asymerror']['plus'])**2)

      for GlobalItem in Global:
         if len(GlobalItem) > 1:
            GlobalLow = min(map(float, GlobalItem)) * 0.01
            GlobalHigh = max(map(float, GlobalItem)) * 0.01
            SysLow = math.sqrt(SysLow**2 + GlobalLow**2 * CurrentY**2)
            SysHigh = math.sqrt(SysHigh**2 + GlobalHigh**2 * CurrentY**2)

      EYStatLow.append(StatLow)
      EYStatHigh.append(StatHigh)
      EYSysLow.append(SysLow)
      EYSysHigh.append(SysHigh)

   Indices = []
   for i, x in enumerate(Y):
      if x == '--' or x == '-':
         Indices.append(i)

   if HasX == True:
      XTemp      = [j for i, j in enumerate(X) if i not in Indices]
      EXLowTemp  = [j for i, j in enumerate(EXLow) if i not in Indices]
      EXHighTemp = [j for i, j in enumerate(EXHigh) if i not in Indices]
   if HasN == True:
      NTemp      = [j for i, j in enumerate(N) if i not in Indices]
      ENLowTemp  = [j for i, j in enumerate(ENLow) if i not in Indices]
      ENHighTemp = [j for i, j in enumerate(ENHigh) if i not in Indices]
   Y          = [j for i, j in enumerate(Y) if i not in Indices]
   EYStatLow  = [j for i, j in enumerate(EYStatLow) if i not in Indices]
   EYStatHigh = [j for i, j in enumerate(EYStatHigh) if i not in Indices]
   EYSysLow   = [j for i, j in enumerate(EYSysLow) if i not in Indices]
   EYSysHigh  = [j for i, j in enumerate(EYSysHigh) if i not in Indices]

   # print('X[', iR, '] = ', XTemp)
   # print('EXLow[', iR, '] = ', EXLowTemp)
   # print('EXHigh[', iR, '] = ', EXHighTemp)
   # print('Y[', iR, '] = ', Y)
   # print('EYStatLow[', iR, '] = ', EYStatLow)
   # print('EYStatHigh[', iR, '] = ', EYStatHigh)
   # print('EYSysLow[', iR, '] = ', EYSysLow)
   # print('EYSysHigh[', iR, '] = ', EYSysHigh)

   Object = args.Object[iR] if iR < len(args.Object) else args.Object[0]

   if YName == "NUCLEAR MODIFICATION FACTOR" or YName == "Nuclear Modification Factor":
      if args.System == 'PbPb':
         YName = 'RAA'
      if args.System == 'pPb':
         YName = 'RpA'
   if NotationCleanUp(YName) == 'RAA' and args.System == 'pPb':
      YName = 'RpA'
   if NotationCleanUp(YName) == 'RpA' and args.System == 'PbPb':
      YName = 'RAA'

   if iR < len(args.YNameOverride):
      if args.YNameOverride[iR] != '':
         YName = args.YNameOverride[iR]
   else:
      if args.YNameOverride[0] != '':
         YName = args.YNameOverride[0]

   if HasX == True:
      with open('Fragments/' + args.FileNameBase + "-" + args.FileNumber + '-' + str(iR+1) + '.json', 'w') as f:
         f.write('{\n')
         f.write('   "System": "' + args.System + '",\n')
         f.write('   "Energy": "' + args.Energy + '",\n')
         f.write('   "Subject": "' + Object + '",\n')
         f.write('   "Observable": "' + NotationCleanUp(YName) + '",\n')
         f.write('   "Dependency": "' + NotationCleanUp(XName) + '",\n')
         f.write('   "Centrality": "' + Centrality + '",\n')
         f.write('   "Record": "' + args.Record + '",\n')
         f.write('   "Selection": "' + NotationCleanUp(UniqueString) + '",\n')
         f.write('   "Comment": "",\n')
         f.write('   "HEPData": "https://www.hepdata.net/record/ins' + args.HEPDataID + '",\n')
         f.write('   "X": [' + ','.join(map(str, XTemp)) + '],\n')
         f.write('   "EXLow": [' + ','.join(map(str, EXLowTemp)) + '],\n')
         f.write('   "EXHigh": [' + ','.join(map(str, EXHighTemp)) + '],\n')
         f.write('   "Y": [' + ','.join(map(str, Y)) + '],\n')
         f.write('   "EYStatLow": [' + ','.join(map(str, EYStatLow)) + '],\n')
         f.write('   "EYStatHigh": [' + ','.join(map(str, EYStatHigh)) + '],\n')
         f.write('   "EYSysLow": [' + ','.join(map(str, EYSysLow)) + '],\n')
         f.write('   "EYSysHigh": [' + ','.join(map(str, EYSysHigh)) + '],\n')
         f.write('   "GlobalUncertainty": ' + str(GlobalUncertainty) + ',\n')
         f.write('},\n')
         f.close()

   if HasN == True:
      with open('Fragments/' + args.FileNameBase + "-" + args.FileNumber + '-' + str(iR+1) + '-N.json', 'w') as f:
         f.write('{\n')
         f.write('   "System": "' + args.System + '",\n')
         f.write('   "Energy": "' + args.Energy + '",\n')
         f.write('   "Subject": "' + Object + '",\n')
         f.write('   "Observable": "' + NotationCleanUp(YName) + '",\n')
         f.write('   "Dependency": "NPart",\n')
         f.write('   "Centrality": "' + Centrality + '",\n')
         f.write('   "Record": "' + args.Record + '",\n')
         f.write('   "Selection": "' + NotationCleanUp(UniqueString) + '",\n')
         f.write('   "Comment": "",\n')
         f.write('   "HEPData": "https://www.hepdata.net/record/ins' + args.HEPDataID + '",\n')
         f.write('   "X": [' + ','.join(map(str, N)) + '],\n')
         f.write('   "EXLow": [' + ','.join(map(str, ENLow)) + '],\n')
         f.write('   "EXHigh": [' + ','.join(map(str, ENHigh)) + '],\n')
         f.write('   "Y": [' + ','.join(map(str, Y)) + '],\n')
         f.write('   "EYStatLow": [' + ','.join(map(str, EYStatLow)) + '],\n')
         f.write('   "EYStatHigh": [' + ','.join(map(str, EYStatHigh)) + '],\n')
         f.write('   "EYSysLow": [' + ','.join(map(str, EYSysLow)) + '],\n')
         f.write('   "EYSysHigh": [' + ','.join(map(str, EYSysHigh)) + '],\n')
         f.write('   "GlobalUncertainty": ' + str(GlobalUncertainty) + ',\n')
         f.write('},\n')
         f.close()


