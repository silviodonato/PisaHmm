import ROOT
import imp
import os

#combineTool.py -M FitDiagnostics -m 125 -d datacard2018H.txt --there --cminDefaultMinimizerStrategy 0 --saveWorkspace
#text2workspace.py workspace/datacard2018H.txt --dump-datacard | grep "DC.systs =" > datacard2018H.py | cut -c 3-

#aa = os.popen('text2workspace.py workspace/datacard2018H.txt --dump-datacard | grep "DC\." | sed  's/DC.//g' | head -n -1 > datacard2018H.py')
#aa.read()


f = ROOT.TFile.Open("workspaceBak/fitDiagnostics.Test.root")
fit_res = f.Get("fit_s")

bin = "LeadMuon_pt___SignalRegion"

datacardPy = "datacard2018H.py"

#~ class Datacard(): pass
#~ DCsysts = imp.load_source('datacard', datacardPy).systs

#~ nuisances = {}
#~ for nuis in DCsysts:
    #~ (name, boh, type, boh2, datacardValues) = nuis
    #~ nuisances[name] = (boh, type, boh2, datacardValues)

params = fit_res.floatParsFinal()

#~ def typeNuisance(name):
    #~ if name in nuisances:
        #~ return nuisances["name"][1]
    #~ else:
        #~ print("Nuisance not found!",name)
        #~ return

postFitNuisancePy = """
outputFit={
"""

print(len(params))
for i in range(len(params)):
    name   = params[i].GetName()
    v      = params[i].getValV()
    v_up   = params[i].getErrorLo()
    v_down = params[i].getErrorHi()
    print( "%s = %f +%f - %f"%(name, v, v_up, v_down))
    #~ if name in nuisances:
        #~ if nuisances[name][1] is "lnN":
            #~ print nuisances[name][3][bin]
    #~ elif "prop_bin" in name:
        #~ print("Skipping MC stat",name)
    #~ elif name is "r":
        #~ print("Skipping r")
    #~ else:
        #~ print("Nuisance not found!",name)
        #~ break
    
    postFitNuisancePy += '"%s" : (%f, %f, %f),\n'%(name, v, v_up, v_down)

postFitNuisancePy += """
}
"""

#postFitNuisancePy += str(nuisances)

print(postFitNuisancePy)

outputFile = open("altro2.py","w+") 
outputFile.write(postFitNuisancePy)
outputFile.close()
