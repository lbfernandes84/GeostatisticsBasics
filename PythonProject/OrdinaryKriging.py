import config

class OrdinaryKriging:
    
    def __init__(self, sample_set):
        self._ordinary_kriging = config.geo.OrdinaryKrigingEstimate_Create(sample_set)
        self._estimator_result = config.geo.OKEstimationResult_Create()

    def estimate(self, variogram, sample_values, target):
        config.geo.OrdinaryKrigingEstimate_Estimate(self._ordinary_kriging, variogram, sample_values, target, self._estimator_result)

    def get_result_pointer(self):
        return self._estimator_result

class OKEstimateResult:

    def __init__(self, pointer):
        self._estimator_result = pointer

    def get_estimate(self):
        return config.geo.OKEstimationResult_GetEstimate(self._estimator_result)

    def get_variance(self):
        return config.geo.OKEstimationResult_GetVariance(self._estimator_result)

    def get_lagrange(self):
        return config.geo.OKEstimationResult_GetLagrange(self._estimator_result)