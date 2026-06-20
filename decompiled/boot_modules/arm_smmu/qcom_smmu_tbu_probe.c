__int64 __fastcall qcom_smmu_tbu_probe(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 608) )
  {
    _pm_runtime_set_status(a1 + 16, 0);
    pm_runtime_enable(a1 + 16);
  }
  return 0;
}
