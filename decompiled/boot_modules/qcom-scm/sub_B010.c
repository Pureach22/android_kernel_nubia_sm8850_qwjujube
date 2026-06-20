__int64 sub_B010()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return qcom_scm_is_mode_switch_available();
}
