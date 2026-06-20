__int64 __fastcall smmu_pmu_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  perf_pmu_unregister(v1 + 2152);
  return _cpuhp_state_remove_instance((unsigned int)cpuhp_state_num, v1, 0);
}
