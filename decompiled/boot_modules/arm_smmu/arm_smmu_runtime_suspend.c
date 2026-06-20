__int64 __fastcall arm_smmu_runtime_suspend(__int64 a1)
{
  arm_smmu_power_off(*(_QWORD *)(a1 + 152), *(_QWORD *)(*(_QWORD *)(a1 + 152) + 304LL));
  return 0;
}
