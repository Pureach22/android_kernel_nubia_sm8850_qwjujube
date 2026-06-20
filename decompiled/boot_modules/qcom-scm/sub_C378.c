__int64 __fastcall sub_C378(_QWORD *a1)
{
  __int64 v1; // x13

  *a1 = v1;
  return qcom_scm_kgsl_set_smmu_lpac_aperture((char *)a1 + 217);
}
