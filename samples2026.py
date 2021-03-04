path2026 = "/scratchssd/thakore/PROD_2_2/" #reduced JES

samples={

"vbfHmm_2026POWPY" : {"xsec": 0.0008210722, "files": ["/scratchssd/thakore/PROD_2_2/vbfHmm_2026POWPY.root"] }, #xsec need to be set later on with actual values

"ggHmm_2026POWPY" : {"xsec": 0.0008210722, "files": ["/scratchssd/thakore/PROD_2_2/ggHmm_2026POWPY.root"] }, #xsec need to be set later on with actual values

"DY50HT200_2026MGPY" : {"xsec": 32.95, "files": ["/scratchssd/thakore/PROD_2_2/DY50HT200_2026MGPY.root"] },

"EWKZ2JetsZToLL_2026MGPY" : {"xsec": 4.38, "files": ["/scratchssd/thakore/PROD_2_2/EWKZ2JetsZToLL_2026MGPY.root"] },

"DY50_2026MGPY" : {"xsec": 5711, "files": ["/scratchssd/thakore/PROD_2_2/DY50_2026MGPY.root"] }, 

"DY100_2026MGPY" : {"xsec": 246.5, "files": ["/scratchssd/thakore/PROD_2_2/DY100_2026MGPY.root"] },

"TT_2026POWPY" : {"xsec": 864.4, "files": ["/scratchssd/thakore/PROD_2_2/TT_2026POWPY.root"] },

}


## Add "files" automatically if not defined
for sample in samples:
    if not "files" in list(samples[sample].keys()):
        if "nameforfile" in list(samples[sample].keys()) :
            samples[sample]["files"] = [path2026+samples[sample]["nameforfile"]+".root"]
        else:
            samples[sample]["files"] = [path2026+sample+".root"]
