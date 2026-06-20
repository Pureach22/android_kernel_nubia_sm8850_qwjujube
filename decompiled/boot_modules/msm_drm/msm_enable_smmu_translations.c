__int64 __fastcall msm_enable_smmu_translations(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  unsigned int v3; // w19

  v1 = *(_QWORD *)(a1 + 40);
  if ( !v1 )
    return 4294967277LL;
  if ( !*(_QWORD *)(v1 + 24) )
    return 4294967277LL;
  result = qcom_iommu_enable_s1_translation();
  if ( (_DWORD)result )
  {
    v3 = result;
    _drm_err("enable iommu s1 translations failed:%d\n", result);
    return v3;
  }
  return result;
}
