__int64 sub_309FD0()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return cds_get_gmac_mmie_size();
}
