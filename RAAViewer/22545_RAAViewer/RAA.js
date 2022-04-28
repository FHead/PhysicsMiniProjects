var Chart;
var Plot;
var PlotData;
var XY;
var HashLockdown;
var CurveUpdateLock;
var LatestPosition;
var PositionTimeout = null;
var OldCurveCount = -1;
var OldPlotDataLength = -1;
var MinAnimationTime = 150;
var AnimationTime = 300;

function CentralitySort(List)
{
   Ns = [];
   for(var i = 0; i < List.length; i++)
   {
      Low = List[i].split(/[-%]/)[0];
      High = List[i].split(/[-%]/)[1];

      if(isNaN(Low) == true || isNaN(High) == true)
         Low = 99, High = 100;

      Ns.push([Number(Low), Number(High), List[i]]);
   }

   Ns = Ns.sort(function(a,b)
   {
      if(a[0] - b[0] < 0) return -1;
      if(a[0] - b[0] > 0) return 1;
      if(a[1] - b[1] < 0) return -1;
      if(a[1] - b[1] > 0) return 1;
      return a[2] < b[2];
   });

   List.length = 0;
   for(var i = 0; i < Ns.length; i++)
      List.push(Ns[i][2]);

   return List;
}

function UniqueValues(List, Field, Item)
{
   var Values = [];
   for(Index in List)
      Values.push(List[Index][Field]);
   Results = Values.filter(function(value, index, self) {return self.indexOf(value) == index;}).sort();
   if(Field == "Centrality")
      Results = CentralitySort(Results);

   CurrentValue = Item.val();

   Item.empty();
   for(var Index in Results)
      Item.append("<option value = \"" + Results[Index] + "\">" + Results[Index] + "</option>");

   if(Results.includes(CurrentValue))
      Item.val(CurrentValue);
}

function FindRecord(Subject, Observable, System, Energy, Dependency, Centrality, Record, Selection)
{
   return Data.filter(function(item)
   {
      return (Subject == "NoMatch" || item.Subject == Subject)
         && (Observable == "NoMatch" || item.Observable == Observable)
         && (System == "NoMatch" || item.System == System)
         && (Energy == "NoMatch" || item.Energy == Energy)
         && (Dependency == "NoMatch" || item.Dependency == Dependency)
         && (Centrality == "NoMatch" || item.Centrality == Centrality)
         && (Record == "NoMatch" || item.Record == Record)
         && (Selection == "NoMatch" || item.Selection == Selection);
   });
}

function SetListOfSubjects(Index)
{
   UniqueValues(Data, "Subject", $('#Subject'+Index));
   SetListOfObservables(Index);
}

function SetListOfObservables(Index)
{
   Subject = $('#Subject'+Index).val();
   UniqueValues(FindRecord(Subject, "NoMatch", "NoMatch", "NoMatch", "NoMatch", "NoMatch", "NoMatch", "NoMatch"),
      "Observable", $('#Observable'+Index));
   SetListOfSystems(Index);
}

function SetListOfSystems(Index)
{
   Subject = $('#Subject'+Index).val();
   Observable = $('#Observable'+Index).val();
   UniqueValues(FindRecord(Subject, Observable, "NoMatch", "NoMatch", "NoMatch", "NoMatch", "NoMatch", "NoMatch"),
      "System", $('#System'+Index));
   SetListOfEnergies(Index);
}

function SetListOfEnergies(Index)
{
   Subject = $('#Subject'+Index).val();
   Observable = $('#Observable'+Index).val();
   System = $('#System'+Index).val();
   UniqueValues(FindRecord(Subject, Observable, System, "NoMatch", "NoMatch", "NoMatch", "NoMatch", "NoMatch"),
      "Energy", $('#Energy'+Index));
   SetListOfDependencies(Index);
}

function SetListOfDependencies(Index)
{
   Subject = $('#Subject'+Index).val();
   Observable = $('#Observable'+Index).val();
   System = $('#System'+Index).val();
   Energy = $('#Energy'+Index).val();
   UniqueValues(FindRecord(Subject, Observable, System, Energy, "NoMatch", "NoMatch", "NoMatch", "NoMatch"),
      "Dependency", $('#Dependency'+Index));
   SetListOfCentralities(Index);
}

function SetListOfCentralities(Index)
{
   Subject = $('#Subject'+Index).val();
   Observable = $('#Observable'+Index).val();
   System = $('#System'+Index).val();
   Energy = $('#Energy'+Index).val();
   Dependency = $('#Dependency'+Index).val();
   UniqueValues(FindRecord(Subject, Observable, System, Energy, Dependency, "NoMatch", "NoMatch", "NoMatch"),
      "Centrality", $('#Centrality'+Index));
   SetListOfRecords(Index);
}

function SetListOfRecords(Index)
{
   Subject = $('#Subject'+Index).val();
   Observable = $('#Observable'+Index).val();
   System = $('#System'+Index).val();
   Energy = $('#Energy'+Index).val();
   Dependency = $('#Dependency'+Index).val();
   Centrality = $('#Centrality'+Index).val();
   UniqueValues(FindRecord(Subject, Observable, System, Energy, Dependency, Centrality, "NoMatch", "NoMatch"),
      "Record", $('#Record'+Index));
   SetListOfSelections(Index);
}

function SetListOfSelections(Index)
{
   Subject = $('#Subject'+Index).val();
   Observable = $('#Observable'+Index).val();
   System = $('#System'+Index).val();
   Energy = $('#Energy'+Index).val();
   Dependency = $('#Dependency'+Index).val();
   Centrality = $('#Centrality'+Index).val();
   Record = $('#Record'+Index).val();
   UniqueValues(FindRecord(Subject, Observable, System, Energy, Dependency, Centrality, Record, "NoMatch"),
      "Selection", $('#Selection'+Index));

   UpdateLink(Index);
}

function SubjectChange(Index)    {SetListOfObservables(Index); UpdateCurves(); UpdateHash();}
function ObservableChange(Index) {SetListOfSystems(Index); UpdateCurves(); UpdateHash();}
function SystemChange(Index)     {SetListOfEnergies(Index); UpdateCurves(); UpdateHash();}
function EnergyChange(Index)     {SetListOfDependencies(Index); UpdateCurves(); UpdateHash();}
function DependencyChange(Index) {SetListOfCentralities(Index); UpdateCurves(); UpdateHash();}
function CentralityChange(Index) {SetListOfRecords(Index); UpdateCurves(); UpdateHash();}
function RecordChange(Index)     {SetListOfSelections(Index); UpdateCurves(); UpdateHash();}
function SelectionChange(Index)  {UpdateLink(Index); UpdateCurves(); UpdateHash();}

function UpdateLink(Index)
{
   Subject = $('#Subject'+Index).val();
   Observable = $('#Observable'+Index).val();
   System = $('#System'+Index).val();
   Energy = $('#Energy'+Index).val();
   Dependency = $('#Dependency'+Index).val();
   Centrality = $('#Centrality'+Index).val();
   Record = $('#Record'+Index).val();
   Selection = $('#Selection'+Index).val();

   Items = FindRecord(Subject, Observable, System, Energy, Dependency, Centrality, Record, Selection)
   if(Items.length == 0)
   {
      $('#Link'+Index).addClass("nolink");
      $('#Link'+Index+'>a').attr('href', '');
      return;
   }

   if(Items[0]['HEPData'] != undefined && Items[0]['HEPData'].startsWith("http"))
   {
      $('#Link'+Index).removeClass("nolink");
      $('#Link'+Index+'>a').attr('href', Items[0]['HEPData']);
   }
   else
   {
      $('#Link'+Index).addClass('nolink');
      $('#Link'+Index+'>a').attr('href', '');
   }
}

function GetXY()
{
   var CurveCount = parseInt($("#CurveCount").val());

   Xs = [];
   Ys = [];
   XMin = 999;
   XMax = -999;
   YMin = 999;
   YMax = -999;

   XMode = "";
   YMode = "";
   if($('#LogX').hasClass("On"))   XMode = "log";
   if($('#LogY').hasClass("On"))   YMode = "log";

   for(Index = 0; Index < CurveCount; Index++)
   {
      if($('#Color'+(Index+1)).hasClass('hide'))
         continue;
      
      Subject    = $('#Subject'+(Index+1)).val();
      Observable = $('#Observable'+(Index+1)).val();
      System     = $('#System'+(Index+1)).val();
      Energy     = $('#Energy'+(Index+1)).val();
      Dependency = $('#Dependency'+(Index+1)).val();
      Centrality = $('#Centrality'+(Index+1)).val();
      Record     = $('#Record'+(Index+1)).val();
      Selection  = $('#Selection'+(Index+1)).val();

      Item = FindRecord(Subject, Observable, System, Energy, Dependency, Centrality, Record, Selection);
      if(Item.length == 0)
         continue;

      Xs.push(Item[0].Dependency);
      Ys.push(Item[0].Observable);

      N = Item[0].X.length;
      for(i = 0; i < N; i++)
      {
         if(XMode == "log")
         {
            if(Item[0].X[i] > 0)
               if(Item[0].X[i] < XMin)
                  XMin = Item[0].X[i];
            if(Item[0].X[i] - Item[0].EXLow[i] > 0)
               if(Item[0].X[i] - Item[0].EXLow[i] < XMin)
                  XMin = Item[0].X[i] - Item[0].EXLow[i];
         }
         else
            if(Item[0].X[i] - Item[0].EXLow[i] < XMin)
               XMin = Item[0].X[i] - Item[0].EXLow[i];
         if(Item[0].X[i] + Item[0].EXHigh[i] > XMax)
            XMax = Item[0].X[i] + Item[0].EXHigh[i];

         if(YMode == "log")
         {
            if(Item[0].Y[i] > 0)
               if(Item[0].Y[i] < YMin)
                  YMin = Item[0].Y[i];
            if(Item[0].Y[i] - Item[0].EYStatLow[i] > 0)
               if(Item[0].Y[i] - Item[0].EYStatLow[i] < YMin)
                  YMin = Item[0].Y[i] - Item[0].EYStatLow[i];
            if(Item[0].Y[i] - Item[0].EYSysLow[i] > 0)
               if(Item[0].Y[i] - Item[0].EYSysLow[i] < YMin)
                  YMin = Item[0].Y[i] - Item[0].EYSysLow[i];
         }
         else
         {
            if(Item[0].Y[i] - Item[0].EYStatLow[i] < YMin)
               YMin = Item[0].Y[i] - Item[0].EYStatLow[i];
            if(Item[0].Y[i] - Item[0].EYSysLow[i] < YMin)
               YMin = Item[0].Y[i] - Item[0].EYSysLow[i];
         }
         if(Item[0].Y[i] + Item[0].EYStatHigh[i] > YMax)
            YMax = Item[0].Y[i] + Item[0].EYStatHigh[i];
         if(Item[0].Y[i] + Item[0].EYSysHigh[i] > YMax)
            YMax = Item[0].Y[i] + Item[0].EYSysHigh[i];
      }
   }

   DataXMin = XMin;
   DataXMax = XMax;
   DataYMin = YMin;
   DataYMax = YMax;

   if(XMode == "")
   {
      DX = XMax - XMin;
      if(XMin != 0)
         XMin = XMin - DX * 0.05;
      XMax = XMax + DX * 0.05;
   }
   else
   {
      DX = Math.log(XMax) - Math.log(XMin);
      if(XMax / XMin < 10)
         DX = Math.log(10);
      XMin = XMin / Math.exp(DX * 0.05);
      XMax = XMax * Math.exp(DX * 0.05);
   }

   if(YMode == "")
   {
      DY = YMax - YMin;
      if(YMin != 0)
         YMin = YMin - DY * 0.05;
      YMax = YMax + DY * 0.05;
   }
   else
   {
      DY = Math.log(YMax) - Math.log(YMin);
      if(YMax / YMin < 10)
      {
         DY = Math.log(10);
         YMax = YMax * Math.exp(DY * 0.05);
         YMin = YMin / Math.exp(DY * 0.05);
      }
      else
      {
         YMin = YMin / Math.exp(DY * 0.05);
         YMax = YMax * Math.exp(DY * 0.05);
      }
   }

   Xs = Xs.filter(function(value, index, self) {return self.indexOf(value) == index;});
   Ys = Ys.filter(function(value, index, self) {return self.indexOf(value) == index;});

   XLabel = '';
   for(i = 0; i < Xs.length; i++)
   {
      if(i != 0)
         XLabel += ',';
      XLabel += Xs[i];
   }
   YLabel = '';
   for(i = 0; i < Ys.length; i++)
   {
      if(i != 0)
         YLabel += ',';
      YLabel += Ys[i];
   }

   return {X: XLabel, Y: YLabel, XMin: XMin, XMax: XMax, YMin: YMin, YMax: YMax, XMode: XMode, YMode: YMode, DataXMin: DataXMin, DataXMax: DataXMax, DataYMin: DataYMin, DataYMax: DataYMax};
}

function UpdateCurves()
{
   if(CurveUpdateLock == true)
      return;

   console.log("UpdateCurves called");

   // Set up plotting related stuff

   XY = GetXY();

   PlotOption =
   {
      xaxis:     {axisLabel: XY.X, min: XY.XMin, max: XY.XMax,
         datamin: XY.DataXMin, datamax: XY.DataXMax, mode: XY.XMode},
      yaxis:     {axisLabel: XY.Y, min: XY.YMin, max: XY.YMax,
         datamin: XY.DataYMin, datamax: XY.DataYMax, mode: XY.YMode},
      grid:      {margin: 20, hoverable: true, clickable: true},
      crosshair: {mode: "xy", color: "rgba(0,0,0,0.75)", lineWidth: 1},
      selection: {mode: "xy"}
   };
   if(XY.XMode == "log")
   {
      PlotOption.xaxis["transform"] = function(v) {return v > 0 ? Math.log(v) / Math.LN10 : null;};
      PlotOption.xaxis["inverseTransform"] = function(v) {return Math.pow(10, v);};
   }
   if(XY.YMode == "log")
   {
      PlotOption.yaxis["transform"] = function(v) {return (v > 0) ? Math.log(v) / Math.LN10 : null;};
      PlotOption.yaxis["inverseTransform"] = function(v) {return Math.pow(10, v);};
   }

   var CurveCount = $("#CurveCount").val();

   PlotData = [];

   for(Index = 0; Index < CurveCount; Index++)
   {
      if($('#Color'+(Index+1)).hasClass('hide'))
         continue;

      Subject    = $('#Subject'+(Index+1)).val();
      Observable = $('#Observable'+(Index+1)).val();
      System     = $('#System'+(Index+1)).val();
      Energy     = $('#Energy'+(Index+1)).val();
      Dependency = $('#Dependency'+(Index+1)).val();
      Centrality = $('#Centrality'+(Index+1)).val();
      Record     = $('#Record'+(Index+1)).val();
      Selection  = $('#Selection'+(Index+1)).val();

      Item = FindRecord(Subject, Observable, System, Energy, Dependency, Centrality, Record, Selection);
      if(Item.length == 0)
         continue;

      N = Item[0]["X"].length;

      var DTotal = [];
      var DStat = [];
      for(i = 0; i < N; i++)
      {
         DStat.push([Item[0].X[i], Item[0].Y[i],
            Item[0].EXLow[i], Item[0].EXHigh[i],
            Item[0].EYStatLow[i], Item[0].EYStatHigh[i]]);

         EYStatLow  = Item[0].EYStatLow[i];
         EYStatHigh = Item[0].EYStatHigh[i];
         EYSysLow   = Item[0].EYSysLow[i];
         EYSysHigh  = Item[0].EYSysHigh[i];
         Global     = Item[0].GlobalUncertainty * Item[0].Y[i];

         EYLow = Math.sqrt(EYStatLow * EYStatLow + EYSysLow * EYSysLow + Global * Global);
         EYHigh = Math.sqrt(EYStatHigh * EYStatHigh + EYSysHigh * EYSysHigh + Global * Global);
         
         DTotal.push([Item[0].X[i], Item[0].Y[i],
            Item[0].EXLow[i], Item[0].EXHigh[i],
            EYLow, EYHigh]);
      }
      var DPStat =
      {
         show: true,
         radius: 5,
         fillColor: DefaultColors[Index],
         errorbars: "xy",
         xerr: {show: true, asymmetric: true},
         yerr: {show: true, asymmetric: true, upperCap: '-', lowerCap: '-'}
      };
      var DPTotal =
      {
         show: true,
         radius: 5,
         fillColor: DefaultColors[Index],
         errorbars: "xy",
         xerr: {show: true, asymmetric: true},
         yerr: {show: true, asymmetric: true}
      };

      PlotData.push({color: DefaultColors[Index], points: DPStat, data: DStat});
      PlotData.push({color: DefaultColors[Index], points: DPTotal, data: DTotal});
   }

   if(PlotData.length == 0 && OldPlotDataLength > 0)
   {
      $('#ChartDiv').stop().fadeOut(AnimationTime, function()
      {
         $('#ChartEmpty').stop().fadeIn(AnimationTime);
      });
      $('#ChartDiv').delay(AnimationTime - 1, function()
      {
         Plot = $.plot("#ChartDiv", PlotData, PlotOption);
      });
   }
   else if(OldPlotDataLength == 0 && PlotData.length > 0)
   {
      $('#ChartEmpty').stop().fadeOut(AnimationTime, function()
      {
         $('#ChartDiv').stop().fadeTo(1, 0.01, function()
         {
            Plot = $.plot("#ChartDiv", PlotData, PlotOption);
         }).fadeTo(AnimationTime - 1, 1.00);
      });
   }
   else
      Plot = $.plot("#ChartDiv", PlotData, PlotOption);

   OldPlotDataLength = PlotData.length;

   // if(PlotData.length == 0)
   // {
   //    $('#ChartDiv').hide();
   //    $('#ChartEmpty').show();
   // }
   // else
   // {
   //    $('#ChartDiv').show();
   //    $('#ChartEmpty').hide();
   // }   
}

function ResetRange()
{
   $.each(Plot.getXAxes(), function(_,axis)
   {
      var opts = axis.options;
      opts.min = XY.XMin;
      opts.max = XY.XMax;
   });
   $.each(Plot.getYAxes(), function(_,axis)
   {
      var opts = axis.options;
      opts.min = XY.YMin;
      opts.max = XY.YMax;
   });
   Plot.setupGrid();
   Plot.draw();
   Plot.clearSelection();
}

function ShowHideSelector()
{
   var CurveCount = parseInt($('#CurveCount').val());
   if(CurveCount > MaxCurveCount || CurveCount <= 0)
      CurveCount = 1;

   if(OldCurveCount > 0 && CurveCount > OldCurveCount)
   {
      CurveUpdateLock = true;
      for(var i = OldCurveCount + 1; i <= CurveCount; i++)
      {
         $('#Subject'+i).val($('#Subject'+(i-1)).val());
         SubjectChange(i);
         $('#Observable'+i).val($('#Observable'+(i-1)).val());
         ObservableChange(i);
         $('#System'+i).val($('#System'+(i-1)).val());
         SystemChange(i);
         $('#Energy'+i).val($('#Energy'+(i-1)).val());
         EnergyChange(i);
         $('#Dependency'+i).val($('#Dependency'+(i-1)).val());
         DependencyChange(i);
         $('#Centrality'+i).val($('#Centrality'+(i-1)).val());
         CentralityChange(i);
         $('#Record'+i).val($('#Record'+(i-1)).val());
         RecordChange(i);
         $('#Selection'+i).val($('#Selection'+(i-1)).val());
         SelectionChange(i);

         // $('#Color'+i).removeClass("hide");
      }
      CurveUpdateLock = false;
   }

   if(CurveCount < OldCurveCount)   // hide some
   {
      var ToChange = OldCurveCount - CurveCount;
      var ToChange = CurveCount - OldCurveCount;
      var AnimationEach = AnimationTime / ToChange;
      if(AnimationEach < MinAnimationTime)
         AnimationEach = MinAnimationTime;
      for(var i = OldCurveCount - 1; i >= CurveCount; i--)
      {
         $('#Selector'+(i+1)).stop().delay(AnimationEach * (OldCurveCount - 1 - i)).fadeOut(AnimationEach);
      }
   }
   else if(CurveCount > OldCurveCount)   // show some
   {
      if(OldCurveCount < 0)
         OldCurveCount = 0;
      var ToChange = CurveCount - OldCurveCount;
      var AnimationEach = AnimationTime / ToChange;
      if(AnimationEach < MinAnimationTime)
         AnimationEach = MinAnimationTime;
      for(var i = OldCurveCount; i < CurveCount; i++)
      {
         $('#Selector'+(i+1)).css('display', "table-row").css('opacity', 0.01);
         $('#Selector'+(i+1)).stop().delay(AnimationTime).delay(AnimationEach * (i - OldCurveCount)).fadeTo(AnimationEach, 1.00);
      }
   }

   OldCurveCount = CurveCount;
}

function UpdateHash()
{
   if(HashLockdown == true)
      return;

   var HashString = "";
   var CurveCount = $('#CurveCount').val();

   for(var i = 0; i < MaxCurveCount; i++)
   {
      if(CurveCount <= i)
         continue;
      if(i != 0)
         HashString = HashString + "&";
      HashString = HashString
         + $('#Subject'+(i+1)).val() + ";"
         + $('#Observable'+(i+1)).val() + ";"
         + $('#System'+(i+1)).val() + ";"
         + $('#Energy'+(i+1)).val() + ";"
         + $('#Dependency'+(i+1)).val() + ";"
         + $('#Centrality'+(i+1)).val() + ";"
         + $('#Record'+(i+1)).val() + ";"
         + $('#Selection'+(i+1)).val() + ";"
         + "Hidden=" + $('#Color'+(i+1)).hasClass('hide');
   }

   HashString = HashString + "?" + "LogX=" + $('#LogX').hasClass("On");
   HashString = HashString + "&" + "LogY=" + $('#LogY').hasClass("On");

   HashString = encodeURI(HashString);

   window.location.hash = HashString;
}

function LoadFromHash()
{
   var HashString = window.location.hash;
   HashString = HashString.replace(/^#/, "");
   HashString = decodeURI(HashString);

   HashLockdown = true;

   if(HashString == "")
   {
      LoadDefaultSetup();
      return;
   }

   var BigSplit = HashString.split('?');

   var Curves = HashString.split('?')[0].split("&");
   var ExtraInformation = (BigSplit.length > 1) ? HashString.split('?')[1].split("&") : [];

   CurveCount = Curves.length;
   if(CurveCount > MaxCurveCount)
      CurveCount = MaxCurveCount;
   $('#CurveCount').val(CurveCount);

   var Error = false;

   for(var i = 0; i < MaxCurveCount; i++)
   {
      if(CurveCount <= i)
         continue;

      var Split = Curves[i].split(';');
      var Items = FindRecord(Split[0], Split[1], Split[2], Split[3], Split[4], Split[5], Split[6], "NoMatch");
      if(Items.length == 0)
      {
         console.log(Split);
         Error = true;
         break;
      }
      else if(Items.length == 1)
      {
         Split[7] = Items[0].Selection;
      }
      else if(Items.length > 1)
      {
         Items = FindRecord(Split[0], Split[1], Split[2], Split[3], Split[4], Split[5], Split[6], Split[7]);
         if(Items.length == 0)
         {
            console.log(Split);
            Error = true;
            break;
         }
      }

      $('#Subject'+(i+1)).val(Split[0]);
      SubjectChange(i + 1);
      $('#Observable'+(i+1)).val(Split[1]);
      ObservableChange(i + 1);
      $('#System'+(i+1)).val(Split[2]);
      SystemChange(i + 1);
      $('#Energy'+(i+1)).val(Split[3]);
      EnergyChange(i + 1);
      $('#Dependency'+(i+1)).val(Split[4]);
      DependencyChange(i + 1);
      $('#Centrality'+(i+1)).val(Split[5]);
      CentralityChange(i + 1);
      $('#Record'+(i+1)).val(Split[6]);
      RecordChange(i + 1);
      $('#Selection'+(i+1)).val(Split[7]);
      SelectionChange(i + 1);

      if(Split[8] == "Hidden=true")
         $('#Color'+(i+1)).addClass('hide');
      else
         $('#Color'+(i+1)).removeClass('hide');
   }

   if(Error == true)
   {
      LoadDefaultSetup();
      return;
   }

   for(var i = 0; i < ExtraInformation.length; i++)
   {
      if(ExtraInformation[i] == "LogX=false")
         $('#LogX').removeClass("On");
      if(ExtraInformation[i] == "LogX=true")
         $('#LogX').addClass("On");
      if(ExtraInformation[i] == "LogY=false")
         $('#LogY').removeClass("On");
      if(ExtraInformation[i] == "LogY=true")
         $('#LogY').addClass("On");
      if(ExtraInformation[i] == "LogX=0")
         $('#LogX').removeClass("On");
      if(ExtraInformation[i] == "LogX=1")
         $('#LogX').addClass("On");
      if(ExtraInformation[i] == "LogY=0")
         $('#LogY').removeClass("On");
      if(ExtraInformation[i] == "LogY=1")
         $('#LogY').addClass("On");
   }

   HashLockdown = false;
}

function CheckContains(Item, Value)
{
   var N = Item.children('option').length;

   for(var i = 0; i < N; i++)
      if(Item.children('option')[i].value == Value)
         return true;

   return false;
}

function SetValue(Item, Value)
{
   if(CheckContains(Item, Value))
      Item.val(Value);
   else
      Item.prop("selectedIndex", 0);
}

function LoadDefaultSetup()
{
   $('#CurveCount').val(2);

   SetValue($('#Subject1'), 'Hadron');
   SubjectChange(1);
   SetValue($('#Observable1'), 'RAA');
   ObservableChange(1);
   SetValue($('#System1'), "PbPb");
   SystemChange(1);
   SetValue($('#Energy1'), "5.02 TeV");
   EnergyChange(1);
   SetValue($('#Dependency1'), 'PT');
   DependencyChange(1);
   SetValue($('#Centrality1'), '0-5%');
   CentralityChange(1);
   SetValue($('#Record1'), 'CMS 2016');
   RecordChange(1);
   SetValue($('#Selection1'), 'eta = -1.0 - 1.0');
   SelectionChange(1);

   SetValue($('#Subject2'), 'Hadron');
   SubjectChange(2);
   SetValue($('#Observable2'), 'RAA');
   ObservableChange(2);
   SetValue($('#System2'), "PbPb");
   SystemChange(2);
   SetValue($('#Energy2'), "5.02 TeV");
   EnergyChange(2);
   SetValue($('#Dependency2'), 'PT');
   DependencyChange(2);
   SetValue($('#Centrality2'), '0-5%');
   CentralityChange(2);
   SetValue($('#Record2'), 'ALICE 2018');
   RecordChange(2);
   SetValue($('#Selection2'), 'eta = -0.8 - 0.8');
   SelectionChange(2);

   $('#LogX').addClass("On");
   $('#LogY').removeClass("On");

   HashLockdown = false;
}

function UpdateLocation()
{
   PositionTimeout = null;

   var Text = "Mouse over the plot to see coordinates";

   var Position = LatestPosition;
   var Axes = Plot.getAxes();

   if(Position.x > Axes.xaxis.min && Position.x < Axes.xaxis.max
      && Position.y > Axes.yaxis.min && Position.y < Axes.yaxis.max)
      Text = "Cursor location (" + Position.x.toPrecision(5) + ", " + Position.y.toPrecision(5) + ")";

   $('#MouseLocation').html(Text);
}

function Initialize()
{
   console.log('starting initialize function');

   CurveUpdateLock = true;
   HashLockdown = false;

   for(i = 1; i <= MaxCurveCount; i++)
   {
      SelectorTR = "";
      SelectorTR += '<tr class="SelectorLine" id="Selector' + i + '" style="display: none;">';
      SelectorTR += '   <td><div class="color" id="Color' + i + '" title="Show/Hide"></td>';
      SelectorTR += '   <td><span class="SelectorLabel">Object</span></td><td><select id="Subject' + i + '"></select></td>';
      SelectorTR += '   <td><span class="SelectorLabel">Observable</span></td><td><select id="Observable' + i + '"></select></td>';
      SelectorTR += '   <td><span class="SelectorLabel">System</span></td><td><select id="System' + i + '"></select></td>';
      SelectorTR += '   <td><span class="SelectorLabel">Energy</span></td><td><select id="Energy' + i + '"></select></td>';
      SelectorTR += '   <td><span class="SelectorLabel">XAxis</span></td><td><select id="Dependency' + i + '"></select></td>';
      SelectorTR += '   <td><span class="SelectorLabel">Centrality</span></td><td><select id="Centrality' + i + '"></select></td>';
      SelectorTR += '   <td><span class="SelectorLabel">Record</span></td><td><select id="Record' + i + '"></select></td>';
      SelectorTR += '   <td><span class="SelectorLabel">Selection</span></td><td><select id="Selection' + i + '"></select></td>';
      SelectorTR += '   <td><div class="entrylink" id="Link' + i + '"><a href="" target="_blank"></a></div></td>';
      SelectorTR += '</tr>';
      $('div.SelectorTableContainer > table').append(SelectorTR);

      $('#Selector'+i+' select').attr("Index", i);
      $('#Selector'+i+' select').css('border-color', DefaultColors[i-1]);
      
      $('#Color'+i).css('background-color', DefaultColors[i-1]);
      $('#Color'+i).css('border-color', DefaultColors[i-1]);
      $('#Subject'+i)   .change(function(){SubjectChange($(this).attr("Index"));});
      $('#Observable'+i).change(function(){ObservableChange($(this).attr("Index"));});
      $('#System'+i)    .change(function(){SystemChange($(this).attr("Index"));});
      $('#Energy'+i)    .change(function(){EnergyChange($(this).attr("Index"));});
      $('#Dependency'+i).change(function(){DependencyChange($(this).attr("Index"));});
      $('#Centrality'+i).change(function(){CentralityChange($(this).attr("Index"));});
      $('#Record'+i)    .change(function(){RecordChange($(this).attr("Index"));});
      $('#Selection'+i) .change(function(){SelectionChange($(this).attr("Index"));});

      $('#Color'+i).click(function(){$(this).toggleClass('hide'); UpdateCurves(); UpdateHash();});

      SetListOfSubjects(i);
   }

   LoadFromHash();

   CurveUpdateLock = false;

   $('#CurveCount').change(function(){ShowHideSelector(); UpdateCurves(); UpdateHash();});
   ShowHideSelector();
   UpdateCurves();
   UpdateHash();

   $('#ChartDiv').bind("plotselected", function(event, ranges)
   {
      $.each(Plot.getXAxes(), function(_,axis)
      {
         var opts = axis.options;
         opts.min = ranges.xaxis.from;
         opts.max = ranges.xaxis.to;
      });
      $.each(Plot.getYAxes(), function(_,axis)
      {
         var opts = axis.options;
         opts.min = ranges.yaxis.from;
         opts.max = ranges.yaxis.to;
      });
      Plot.setupGrid();
      Plot.draw();
      Plot.clearSelection();
   });
   $('#ChartDiv').bind("plothover", function(event, pos, item)
   {
      LatestPosition = pos;
      if(PositionTimeout == null)
         PositionTimeout = setTimeout(UpdateLocation, 50);
   });

   $('#LogX').click(function(){$(this).toggleClass("On"); UpdateCurves(); UpdateHash();});
   $('#LogY').click(function(){$(this).toggleClass("On"); UpdateCurves(); UpdateHash();});

   $('#ChartDiv').bind("contextmenu", function(){ResetRange(); return false;});
   $('#ZoomOutButton').click(function() {ResetRange();});

   $('#DownloadButton').click(function(e)
   {
      e.preventDefault();
      html2canvas($('#ChartDiv')[0]).then(canvas =>
      {
         document.body.appendChild(canvas);
         
         var Width = $('#ChartDiv').width() / 48.0;
         var Height = $('#ChartDiv').height() / 48.0 - 0.2;
         var PdfFile = new jsPDF({orientation: 'landscape', unit: 'in', format: [Width, Height],
            compressPdf: true});
         PdfFile.addImage({imageData: canvas.toDataURL("image/png"), x: -0.25, y: -0.1, compression: 'SLOW'});
         PdfFile.save('HIChart.pdf');

         document.body.removeChild(canvas);
      });
   });
}

$(window).on('load', Initialize);



