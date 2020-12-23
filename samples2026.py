path2026 = "/home/sdonato/fileSkimFromNanoAOD/PROD_13_4/" #reduced JES

samples={

"DY105VBF_2026AMCPY"  : {"xsec": 2.03, "filter": "VBFFilterFlag" },# "files":["/scratchssd/mandorli/Hmumu/fileSkimFromNanoAOD/PROD_7_2/DY105VBF_2026AMCPY.root"], "training":False}, #this name has to change
"DY105VBF_2026MGPY"   : {"xsec": 2.03, "filter": "VBFFilterFlag"},

"EWKZ105_2026MGPYDIPOLE"   : {"xsec": 0.0789, "files":["/home/sdonato/fileSkimFromNanoAOD/PROD_13_4/EWKZ105_2026MGPYDIPOLE.root"]},

#data2026V16": {"lumi":59970.,"data":True},


"vbfHmm_2026POWPYDIPOLE"  : {"xsec":0.0008210722},

"data2026": {"lumi":59970.,"data":True,"files":["/home/sdonato/fileSkimFromNanoAOD/PROD_13_4/data2026.root"]},

}

## Add "files" automatically if not defined
for sample in samples:
    if not "files" in list(samples[sample].keys()):
        if "nameforfile" in list(samples[sample].keys()) :
            samples[sample]["files"] = [path2026+samples[sample]["nameforfile"]+".root"]
        else:
            samples[sample]["files"] = [path2026+sample+".root"]
