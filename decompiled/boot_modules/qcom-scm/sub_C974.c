__int64 sub_C974()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return qcom_scm_dcvs_core_available();
}
