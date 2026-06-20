__int64 __fastcall qcom_sdm845_smmu500_reset(__int64 *a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  unsigned int v4; // w19

  arm_mmu500_reset(a1);
  result = qcom_scm_qsmmu500_wait_safe_toggle(0);
  if ( (_DWORD)result )
  {
    v3 = *a1;
    v4 = result;
    dev_warn(v3, "Failed to turn off SAFE logic\n");
    return v4;
  }
  return result;
}
