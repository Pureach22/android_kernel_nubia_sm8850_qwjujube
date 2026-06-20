__int64 sub_D028()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return icnss_is_fw_down();
}
