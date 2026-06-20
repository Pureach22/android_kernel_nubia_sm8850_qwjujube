__int64 __fastcall csr_init_chan_list(
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
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x0
  int *v20; // x20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w8
  __int64 v38; // x9
  int v39; // t1
  __int64 result; // x0
  unsigned __int8 v41[4]; // [xsp+0h] [xbp-10h] BYREF
  __int16 v42; // [xsp+4h] [xbp-Ch] BYREF
  char v43; // [xsp+6h] [xbp-Ah]
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 21624);
  v43 = 0;
  v42 = 0;
  wlan_reg_read_current_country(v10, &v42, a2, a3, a4, a5, a6, a7, a8, a9);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: init time country code %.2s",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "csr_init_chan_list",
    &v42);
  v19 = *(_QWORD *)(a1 + 21632);
  v20 = (int *)(a1 + 15404);
  v41[0] = 0;
  if ( (unsigned int)wlan_reg_get_channel_list_with_power_for_freq(
                       v19,
                       a1 + 15404,
                       v41,
                       v21,
                       v22,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28)
    || (v37 = v41[0]) == 0 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: failed to get channels",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "csr_get_channel_and_power_list");
    result = 16;
  }
  else
  {
    if ( v41[0] >= 0x65u )
    {
      v37 = 100;
      v41[0] = 100;
    }
    v38 = 0;
    do
    {
      if ( v38 == 400 )
        __break(0x5512u);
      v39 = *v20;
      v20 += 3;
      *(_DWORD *)(a1 + 16608 + v38) = v39;
      v38 += 4;
    }
    while ( 4LL * v37 != v38 );
    result = 0;
    *(_BYTE *)(a1 + 16604) = v37;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
