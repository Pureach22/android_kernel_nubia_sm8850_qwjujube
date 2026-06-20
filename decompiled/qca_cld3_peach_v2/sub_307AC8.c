__int64 sub_307AC8()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return cds_is_wakelock_enabled();
}
