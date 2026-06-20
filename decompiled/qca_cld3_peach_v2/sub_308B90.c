__int64 sub_308B90()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return cds_is_pm_fw_debug_enable();
}
