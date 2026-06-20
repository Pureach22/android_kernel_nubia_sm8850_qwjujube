__int64 __fastcall populate_dot11f_eht_caps_by_band(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _BYTE v35[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
    v15 = 22064;
  else
    v15 = 22156;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: is_2g %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "populate_dot11f_eht_caps_by_band",
    a2 & 1);
  qdf_mem_copy((void *)a3, (const void *)(a1 + v15), 0x5Cu);
  if ( a4 )
  {
    v24 = *(_QWORD *)(a3 + 1);
    if ( *(_DWORD *)(a4 + 7176) != 7 )
    {
      v24 &= 0xFFFFFFFE3FFDFFFFLL;
      *(_QWORD *)(a3 + 1) = v24;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: 320 MHz support %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "populate_dot11f_revise_eht_caps",
      ((unsigned int)v24 >> 17) & 1);
    *(_QWORD *)(a3 + 1) = *(_QWORD *)(a3 + 1) & 0xFFFFFFFFFFFFFFFELL | wlan_epcs_get_config(*(_QWORD *)(a4 + 16)) & 1;
  }
  v25 = *(_QWORD *)(a1 + 21624);
  v35[0] = 0;
  wlan_twt_get_rtwt_support(v25, v35);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: rTWT support: %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "populate_dot11f_rtwt_eht_cap",
    v35[0]);
  *(_QWORD *)(a3 + 1) = *(_QWORD *)(a3 + 1) & 0xFFFFFFFFFFFFFFEFLL | (16LL * (v35[0] & 1));
  _ReadStatusReg(SP_EL0);
  return 0;
}
