
bdtbinning= [0 , 0.404 , 0.488 , 0.534 , 0.567333333333 , 0.595333333333 , 0.62 , 0.642 , 0.662 , 0.680666666667 , 0.698 , 0.714666666667 , 0.730666666667 , 0.746666666667 , 0.762666666667 , 0.778 , 0.793333333333 , 0.809333333333 , 0.825333333333 , 0.841333333333 , 0.858 , 0.875333333333 , 0.894 , 0.913333333333 , 0.934 , 0.956666666667 , 0.980666666667 , 1.00733333333 , 1.03733333333 , 1.072 , 1.11333333333 , 1.16666666667 , 1.238 , 1.35133333333 , 2.0 ]

dnnbinning=[0 , 0.340277777778 , 0.741666666667 , 1.01388888889 , 1.22361111111 , 1.39583333333 , 1.54722222222 , 1.68611111111 , 1.81111111111 , 1.93194444444 , 2.04722222222 , 2.15833333333 , 2.27361111111 , 2.38888888889 , 2.50833333333 , 2.63194444444 , 2.76666666667 , 2.91527777778 , 3.08055555556 , 3.28472222222 , 3.57361111111 , 5.0 ]

abc=[0 , 0.17333333333, 0.346666666667 , 0.575 , 0.746666666667 , 0.88 , 1.01 , 1.135 , 1.255 , 1.36833333333 , 1.475 , 1.57833333333 , 1.68 , 1.785 , 1.89166666667 , 2.00333333333 , 2.11833333333 , 2.24166666667 , 2.38333333333 , 2.54833333333 , 2.77833333333 , 4.0 ]


rebin = {   
    "BDTAtan" : bdtbinning,
    "DNNAtan" : dnnbinning,
    "DNNAtanNoMass" : dnnbinning,
    "BDTAtanNoMass" : bdtbinning,
    "BDTAtanNoMassNoNSJ" : bdtbinning,
    "DNN18Atan": abc,
    "DNN18AtanNoQGL": abc,
    "DNN18AtanNoMass": abc
}
