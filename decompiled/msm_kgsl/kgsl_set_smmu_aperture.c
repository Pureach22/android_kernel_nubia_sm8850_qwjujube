__int64 __fastcall kgsl_set_smmu_aperture(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  unsigned int v6; // w19

  if ( (*(_QWORD *)(a1 + 104) & 0x20) == 0 )
    return 0;
  result = qcom_scm_kgsl_set_smmu_aperture(*(unsigned int *)(a2 + 16));
  if ( (_DWORD)result == -16 )
    result = qcom_scm_kgsl_set_smmu_aperture(*(unsigned int *)(a2 + 16));
  if ( (_DWORD)result )
  {
    v5 = *(_QWORD *)(a1 + 11168);
    v6 = result;
    dev_err(
      v5 + 16,
      "Unable to set the SMMU aperture: %d. The aperture needs to be set to use per-process pagetables\n",
      result);
    return v6;
  }
  return result;
}
