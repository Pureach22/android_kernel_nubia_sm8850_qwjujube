__int64 __fastcall wlan_cfg80211_tdls_configure_mode(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  __int64 v21; // [xsp+8h] [xbp-18h]
  __int64 v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_7;
  v21 = 0;
  v22 = 0;
  if ( (unsigned int)(a2 - 1) >= 2 )
  {
    if ( a2 == 6 )
    {
      qdf_trace_msg(
        0x48u,
        4u,
        "%s: cfg80211 tdls trigger mode %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_cfg80211_tdls_configure_mode",
        6);
      LODWORD(v22) = 0;
      LODWORD(v21) = 4;
      BYTE4(v21) = 0;
      v20 = a1;
      result = ucfg_tdls_set_operating_mode((__int64)&v20, v12, v13, v14, v15, v16, v17, v18, v19);
      goto LABEL_8;
    }
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Invalid TDLS trigger mode",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_cfg80211_tdls_configure_mode");
LABEL_7:
    result = 4294967274LL;
    goto LABEL_8;
  }
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
