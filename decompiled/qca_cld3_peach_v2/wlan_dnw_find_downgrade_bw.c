__int64 __fastcall wlan_dnw_find_downgrade_bw(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v13; // w22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  __int64 v26; // [xsp+8h] [xbp-18h]
  __int64 v27; // [xsp+10h] [xbp-10h]
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v25 = 0;
  if ( a4 )
  {
    v13 = a3;
    qdf_trace_msg(
      0x98u,
      8u,
      "%s: freq %d bw %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_dnw_find_downgrade_bw",
      a2,
      a3,
      v25,
      v26,
      v27,
      v28);
    wlan_reg_set_create_punc_bitmap((__int64)&v25, 1);
    LODWORD(v25) = v13;
    while ( 1 )
    {
      LODWORD(v25) = v25 - 1;
      if ( !(_DWORD)v25 )
        break;
      if ( (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                           a1,
                           a2,
                           (int *)&v25,
                           0,
                           v16,
                           v17,
                           v18,
                           v19,
                           v20,
                           v21,
                           v22,
                           v23) != 2 )
      {
        result = 1;
        *a4 = v25;
        goto LABEL_8;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x98u,
      8u,
      "%s: NULL dg_ch_width or pdev",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_dnw_find_downgrade_bw",
      v25,
      v26,
      v27,
      v28);
  }
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
