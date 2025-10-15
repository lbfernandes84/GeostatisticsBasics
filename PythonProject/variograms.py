import config

class SphericalVariogram:

    def __init__(self, nugget, sill, range):    
        self._variogram = config.geo.SphericalVariogram_Create(nugget, sill, range)
    
    def compute(self, h):
        return config.geo.SphericalVariogram_Compute(self._variogram, 12.5)
    
    def get_pointer(self):
        return self._variogram

    def __del__(self):
        config.geo.SphericalVariogram_Destroy(self._variogram)

class ExponentialVariogram:

    def __init__(self, nugget, sill, range):    
        self._variogram = config.geo.ExponentialVariogram_Create(nugget, sill, range)
    
    def compute(self, h):
        return config.geo.ExponentialVariogram_Compute(self._variogram, 12.5)

    def get_pointer(self):
        return self._variogram

    def __del__(self):
        config.geo.ExponentialVariogram_Destroy(self._variogram)