__int64 init_module()
{
  __int64 result; // x0

  result = _cpuhp_setup_state(193, "perf/arm/smmupmu:online", 0, 0, smmu_pmu_offline_cpu, 1);
  cpuhp_state_num = result;
  if ( (result & 0x80000000) == 0 )
    return _platform_driver_register(smmu_pmu_driver, &_this_module);
  return result;
}
