__int64 sub_2D38AC()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return cds_is_sub_20_mhz_enabled();
}
