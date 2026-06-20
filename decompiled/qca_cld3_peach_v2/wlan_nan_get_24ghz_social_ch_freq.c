__int64 __fastcall wlan_nan_get_24ghz_social_ch_freq(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  result = wlan_nan_get_disc_24g_ch_freq(*(_QWORD *)(a1 + 80), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !(_DWORD)result )
  {
    if ( (wlan_reg_is_freq_enabled(a1, 0x985u, v11, v12, v13, v14, v15, v16, v17, v18) & 1) != 0 )
      return 2437;
    else
      return 0;
  }
  return result;
}
