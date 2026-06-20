__int64 sub_B358()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return qcom_scm_restore_sec_cfg_available();
}
