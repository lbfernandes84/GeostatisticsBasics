import Entities
import variograms
import OrdinaryKriging

def create_simple_samples():
    p1 = Entities.Point(0,0,0)
    p2 = Entities.Point(10,0,0)
    samples =  Entities.SampleSet()
    samples.add_sample(p1.get_pointer())
    samples.add_sample(p2.get_pointer())
    return samples

def create_samples_values():
    sampleValues = Entities.SampleValues(2)
    sampleValues.set_value(0, 10.)    
    sampleValues.set_value(1, 20.)    
    return sampleValues

def create_variogram(nugget, sill, range_):
    return variograms.SphericalVariogram(nugget, sill, range_)
    
if __name__ == '__main__':
    spherical_variogram = create_variogram(0.0, 1.0, 10.0)
    samples_points = create_simple_samples()
    samples_values = create_samples_values()
    target = Entities.Point(5.0, 0.0, 0.0)
    ok = OrdinaryKriging.OrdinaryKriging(samples_points.get_pointer())
    ok.estimate(spherical_variogram.get_pointer(), samples_values.get_pointer(), target.get_pointer())
    result = OrdinaryKriging.OKEstimateResult(ok.get_result_pointer())
    print(result.get_estimate())
    print(result.get_variance())
    print(result.get_lagrange())
