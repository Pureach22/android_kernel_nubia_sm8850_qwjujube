__int64 etm_perf_exit()
{
  return perf_pmu_unregister(&etm_pmu);
}
