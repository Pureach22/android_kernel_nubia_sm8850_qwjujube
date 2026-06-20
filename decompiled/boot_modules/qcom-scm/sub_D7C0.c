__int64 sub_D7C0()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return qcom_scm_ice_available();
}
