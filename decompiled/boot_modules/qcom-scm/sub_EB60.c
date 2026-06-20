__int64 sub_EB60()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return qcom_scm_lmh_dcvsh_available();
}
