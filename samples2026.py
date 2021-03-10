path2026 = "/scratchssd/thakore/PROD_2_2/" #reduced JES

samples={

"vbfHmm_2026POWPY" : {"xsec": 0.0008229632, "files": ["/scratchssd/thakore/PROD_2_2/vbfHmm_2026POWPY.root"] }, 

"ggHmm_2026POWPY" : {"xsec": 0.011907072, "files": ["/scratchssd/thakore/PROD_2_2/ggHmm_2026POWPY.root"] }, 

"EWKZ2JetsZToLL_2026MGPY" : {"xsec": 4.38, "files": ["/scratchssd/thakore/PROD_2_2/EWKZ2JetsZToLL_2026MGPY.root"] },

"TT_2026POWPY" : {"xsec": 864.4, "files": ["/scratchssd/thakore/PROD_2_2/TT_2026POWPY.root"] },

"DY50HT70_2026MGPY" : {"xsec": 161.6, "files": ["/scratchssd/thakore/PROD_2_2/DY50HT70_2026MGPY.root"] },

"DY50HT100_2026MGPY" : {"xsec": 150, "files": ["/scratchssd/thakore/PROD_2_2/DY50HT100_2026MGPY.root"] },

"DY50HT200_2026MGPY" : {"xsec": 32.95, "files": ["/scratchssd/thakore/PROD_2_2/DY50HT200_2026MGPY.root"] },

"DY50HT400_2026MGPY" : {"xsec": 3.911, "files": ["/scratchssd/thakore/PROD_2_2/DY50HT400_2026MGPY.root"] },

"DY50HT600_2026MGPY" : {"xsec": 0.8301, "files": ["/scratchssd/thakore/PROD_2_2/DY50HT600_2026MGPY.root"] },

"DY50HT800_2026MGPY" : {"xsec": 0.3852, "files": ["/scratchssd/thakore/PROD_2_2/DY50HT800_2026MGPY.root"] },

"DY50HT1200_2026MGPY" : {"xsec": 0.08874, "files": ["/scratchssd/thakore/PROD_2_2/DY50HT1200_2026MGPY.root"] },

"DY50HT2500_2026MGPY" : {"xsec": 0.001755, "files": ["/scratchssd/thakore/PROD_2_2/DY50HT2500_2026MGPY.root"] },

#####################################################################################################################

"TTlep_2026MGPY" : {"xsec": 67.75, "files": ["/scratchssd/thakore/PROD_2_2/TTlep_2026MGPY.root"] },

"DY50_2026MGPY" : {"xsec": 5711, "files": ["/scratchssd/thakore/PROD_2_2/DY50_2026MGPY.root"] },

"DY100_2026MGPY" : {"xsec": 246.5, "files": ["/scratchssd/thakore/PROD_2_2/DY100_2026MGPY.root"] },

"DY0J50_2026MGPY" : {"xsec": 3728, "files": ["/scratchssd/thakore/PROD_2_2/DY0J50_2026MGPY.root"] },

"DY0J50_2026MGPY_FNAL" : {"xsec": 4451, "files": ["/scratchssd/thakore/PROD_2_2/DY0J50_2026MGPY_FNAL.root"] },

"DY1J50_2026MGPY" : {"xsec": 1096, "files": ["/scratchssd/thakore/PROD_2_2/DY1J50_2026MGPY.root"] },

"DY2J50_2026MGPY" : {"xsec": 384, "files": ["/scratchssd/thakore/PROD_2_2/DY2J50_2026MGPY.root"] },

"DY3J50_2026MGPY" : {"xsec": 165.6, "files": ["/scratchssd/thakore/PROD_2_2/DY3J50_2026MGPY.root"] },

"DY3J50_2026MGPY_FNAL" : {"xsec": 165.6, "files": ["/scratchssd/thakore/PROD_2_2/DY3J50_2026MGPY_FNAL.root"] },

}


## Add "files" automatically if not defined
for sample in samples:
    if not "files" in list(samples[sample].keys()):
        if "nameforfile" in list(samples[sample].keys()) :
            samples[sample]["files"] = [path2026+samples[sample]["nameforfile"]+".root"]
        else:
            samples[sample]["files"] = [path2026+sample+".root"]
