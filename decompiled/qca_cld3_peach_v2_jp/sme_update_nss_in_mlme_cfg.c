__int64 __fastcall sme_update_nss_in_mlme_cfg(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  if ( a4 <= 7 && ((1 << a4) & 0x8C) != 0 )
  {
    sme_modify_nss_in_mlme_cfg(a1, a2, a3, 2u, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    sme_modify_nss_in_mlme_cfg(a1, a2, a3, 3u, a5, v17, v18, v19, v20, v21, v22, v23, v24);
    a4 = 7;
  }
  return sme_modify_nss_in_mlme_cfg(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
}
