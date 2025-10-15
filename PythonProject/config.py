import ctypes

DLL_NAME = "C:\\Personal\\Projects\\GeostatisticsBasics\\DllWrapper\\bin\\x64\\Release\\DllWrapper.dll"

geo = ctypes.CDLL(DLL_NAME)
#---------------------------------------------------------Entities-----------------------------------------------------------------------

#Point::Create
geo.EntitiesPoint_Create.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double]
geo.EntitiesPoint_Create.restype = ctypes.c_void_p

#SampleSet::Create
geo.EntitiesSampleSet_Create.argtypes = []
geo.EntitiesSampleSet_Create.restype = ctypes.c_void_p

#SampleSet::AddSample
geo.EntitiesSampleSet_AddSample.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
geo.EntitiesSampleSet_AddSample.restype = None

#SampleValues::Create
geo.EntitiesSampleValues_Create.argtypes = [ctypes.c_int]
geo.EntitiesSampleValues_Create.restype = ctypes.c_void_p

#SampleValues::SetValue
geo.EntitiesSampleValues_Setvalue.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_double]
geo.EntitiesSampleValues_Setvalue.restype = None

#---------------------------------------------------------Variograms-----------------------------------------------------------------------
#Variogram Spherical

#Create
geo.SphericalVariogram_Create.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double]
geo.SphericalVariogram_Create.restype = ctypes.c_void_p

#Compute
geo.SphericalVariogram_Compute.argtypes = [ctypes.c_void_p, ctypes.c_double]
geo.SphericalVariogram_Compute.restype = ctypes.c_double

#Destroy
geo.SphericalVariogram_Destroy.argtypes = [ctypes.c_void_p]
geo.SphericalVariogram_Destroy.restype = None


#Variogram Exponential

#Create
geo.ExponentialVariogram_Create.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double]
geo.ExponentialVariogram_Create.restype = ctypes.c_void_p

#Compute
geo.ExponentialVariogram_Compute.argtypes = [ctypes.c_void_p, ctypes.c_double]
geo.ExponentialVariogram_Compute.restype = ctypes.c_double

#Destroy
geo.ExponentialVariogram_Destroy.argtypes = [ctypes.c_void_p]
geo.ExponentialVariogram_Destroy.restype = None

#---------------------------------------------------------Ordinary Kriging-----------------------------------------------------------------------
#Ordinary Kriging Estimator:Create
geo.OrdinaryKrigingEstimate_Create.argtypes = [ctypes.c_void_p]
geo.OrdinaryKrigingEstimate_Create.restype = ctypes.c_void_p

#Ordinary Kriging Estimator:Estimate
geo.OrdinaryKrigingEstimate_Estimate.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p]
geo.OrdinaryKrigingEstimate_Estimate.restype = None

#Ordinary Kriging Result:Create
geo.OKEstimationResult_Create.argtypes = []
geo.OKEstimationResult_Create.restype = ctypes.c_void_p

#Ordinary Kriging Result:Estimate
geo.OKEstimationResult_GetEstimate.argtypes = [ctypes.c_void_p]
geo.OKEstimationResult_GetEstimate.restype = ctypes.c_double

#Ordinary Kriging Result:variance
geo.OKEstimationResult_GetVariance.argtypes = [ctypes.c_void_p]
geo.OKEstimationResult_GetVariance.restype = ctypes.c_double

#Ordinary Kriging Result:lagrange
geo.OKEstimationResult_GetLagrange.argtypes = [ctypes.c_void_p]
geo.OKEstimationResult_GetLagrange.restype = ctypes.c_double