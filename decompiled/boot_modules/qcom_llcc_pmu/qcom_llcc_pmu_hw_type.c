__int64 __fastcall qcom_llcc_pmu_hw_type(_DWORD *a1)
{
  int v1; // w9

  if ( !llccpmu )
    return 4294966779LL;
  v1 = *(_DWORD *)(llccpmu + 64);
  if ( !v1 )
    return 4294966779LL;
  *a1 = v1;
  return 0;
}
