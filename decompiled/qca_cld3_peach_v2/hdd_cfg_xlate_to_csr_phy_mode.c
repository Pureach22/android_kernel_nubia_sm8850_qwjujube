__int64 __fastcall hdd_cfg_xlate_to_csr_phy_mode(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( cds_is_sub_20_mhz_enabled(a2, a3, a4, a5, a6, a7, a8, a9) )
    return 1;
  if ( a1 > 0xE )
    return 16;
  return dword_AF7544[a1];
}
