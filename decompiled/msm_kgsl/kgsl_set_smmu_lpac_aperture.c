__int64 __fastcall kgsl_set_smmu_lpac_aperture(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  unsigned int v6; // w19

  if ( (a1[13] & 0x20) == 0 )
    return 0;
  if ( (*(_BYTE *)(a1[1783] + 33LL) & 0x40) == 0 )
    return 0;
  result = qcom_scm_kgsl_set_smmu_lpac_aperture(*(unsigned int *)(a2 + 16));
  if ( (_DWORD)result == -16 )
    result = qcom_scm_kgsl_set_smmu_lpac_aperture(*(unsigned int *)(a2 + 16));
  if ( (_DWORD)result )
  {
    v5 = a1[1396];
    v6 = result;
    dev_err(
      v5 + 16,
      "Unable to set the LPAC SMMU aperture: %d. The aperture needs to be set to use per-process pagetables\n",
      result);
    return v6;
  }
  return result;
}
