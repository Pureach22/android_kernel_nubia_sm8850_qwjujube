__int64 __fastcall lim_check_mcs_set(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2
  unsigned int v21; // w1
  __int64 result; // x0
  size_t v23; // [xsp+0h] [xbp-20h] BYREF
  __int64 v24; // [xsp+8h] [xbp-18h] BYREF
  __int64 v25; // [xsp+10h] [xbp-10h]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 8);
  v24 = 0;
  v25 = 0;
  v23 = *(_QWORD *)(v11 + 3104);
  if ( (unsigned int)wlan_mlme_get_cfg_str(&v24, v11 + 3096, &v23, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    v20 = "%s: could not retrieve Basic MCS rateset";
    v21 = 2;
  }
  else
  {
    if ( ((unsigned __int8)v24 & ~*a2) == 0
      && (BYTE1(v24) & ~a2[1]) == 0
      && (BYTE2(v24) & ~a2[2]) == 0
      && (BYTE3(v24) & ~a2[3]) == 0
      && (BYTE4(v24) & ~a2[4]) == 0
      && (BYTE5(v24) & ~a2[5]) == 0
      && (BYTE6(v24) & ~a2[6]) == 0
      && (HIBYTE(v24) & ~a2[7]) == 0
      && ((unsigned __int8)v25 & ~a2[8]) == 0
      && (BYTE1(v25) & (unsigned __int8)~a2[9] & 0x1F) == 0 )
    {
      result = 1;
      goto LABEL_15;
    }
    v20 = "%s: One of Basic MCS Set Rates is not supported by the Station";
    v21 = 3;
  }
  qdf_trace_msg(0x35u, v21, v20, v12, v13, v14, v15, v16, v17, v18, v19, "lim_check_mcs_set");
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
