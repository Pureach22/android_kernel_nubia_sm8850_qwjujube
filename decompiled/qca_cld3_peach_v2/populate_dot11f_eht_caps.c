__int64 __fastcall populate_dot11f_eht_caps(__int64 a1, __int64 a2, _BYTE *a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  char config; // w0
  __int64 v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _BYTE v26[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a3 = 1;
  if ( a2 )
  {
    qdf_mem_copy(a3, (const void *)(a2 + 10072), 0x5Cu);
    v14 = *(_QWORD *)(a3 + 1);
    if ( *(_DWORD *)(a2 + 7176) != 7 )
    {
      v14 &= 0xFFFFFFFE3FFDFFFFLL;
      *(_QWORD *)(a3 + 1) = v14;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: 320 MHz support %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "populate_dot11f_revise_eht_caps",
      ((unsigned int)v14 >> 17) & 1);
    config = wlan_epcs_get_config(*(_QWORD *)(a2 + 16));
    v16 = *(_QWORD *)(a3 + 1);
    v26[0] = 0;
    *(_QWORD *)(a3 + 1) = v16 & 0xFFFFFFFFFFFFFFFELL | config & 1;
    wlan_twt_get_rtwt_support(*(_QWORD *)(a1 + 21624), v26);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: rTWT support: %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "populate_dot11f_rtwt_eht_cap",
      v26[0]);
    *(_QWORD *)(a3 + 1) = *(_QWORD *)(a3 + 1) & 0xFFFFFFFFFFFFFFEFLL | (16LL * (v26[0] & 1));
  }
  else
  {
    qdf_mem_copy(a3, (const void *)(*(_QWORD *)(a1 + 8) + 1500LL), 0x5Cu);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
