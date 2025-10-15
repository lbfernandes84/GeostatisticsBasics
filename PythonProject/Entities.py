import config

class Point:

    def __init__(self, x, y, z):
        self._point = config.geo.EntitiesPoint_Create(x, y, z)

    def get_pointer(self):
        return self._point

class SampleSet:

    def __init__(self):
        self._sample_set = config.geo.EntitiesSampleSet_Create()

    def add_sample(self, sample):
        config.geo.EntitiesSampleSet_AddSample(self._sample_set, sample)

    def get_pointer(self):
        return self._sample_set

class SampleValues:

    def __init__(self, num_samples):
        self._sample_values = config.geo.EntitiesSampleValues_Create(num_samples)

    def set_value(self, index, value):
        config.geo.EntitiesSampleValues_Setvalue(self._sample_values, index, value)
    
    def get_pointer(self):      
        return self._sample_values
