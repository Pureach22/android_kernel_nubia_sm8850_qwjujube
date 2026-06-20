__int64 __fastcall hdd_disable_default_pkt_filters(
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
  int v9; // w8
  unsigned __int8 pkt_filter_bitmap; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int8 v21; // w21
  unsigned int v22; // w24
  int v23; // w26
  unsigned int v24; // w8
  __int64 v25; // [xsp+0h] [xbp-70h] BYREF
  __int64 v26; // [xsp+8h] [xbp-68h]
  __int64 v27; // [xsp+10h] [xbp-60h]
  __int64 v28; // [xsp+18h] [xbp-58h]
  __int64 v29; // [xsp+20h] [xbp-50h]
  __int64 v30; // [xsp+28h] [xbp-48h]
  __int64 v31; // [xsp+30h] [xbp-40h]
  __int64 v32; // [xsp+38h] [xbp-38h]
  __int64 v33; // [xsp+40h] [xbp-30h]
  __int64 v34; // [xsp+48h] [xbp-28h]
  __int64 v35; // [xsp+50h] [xbp-20h]
  __int128 v36; // [xsp+58h] [xbp-18h]
  __int64 v37; // [xsp+68h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_DWORD *)(a1 + 3260);
  *(_QWORD *)((char *)&v36 + 7) = 0;
  v35 = 0;
  *(_QWORD *)&v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  if ( v9 )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: user has defined pkt filter run hence skipping default packet filter rule",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_disable_default_pkt_filters",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      (_QWORD)v36,
      *((_QWORD *)&v36 + 1),
      v37);
  }
  else
  {
    pkt_filter_bitmap = ucfg_pmo_get_pkt_filter_bitmap(*(_QWORD *)a1);
    if ( pkt_filter_bitmap )
    {
      v21 = pkt_filter_bitmap;
      v22 = 1;
      v23 = 1;
      do
      {
        if ( (v21 & 1) != 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Clearing filter[%d], of id = %d",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "hdd_disable_default_pkt_filters",
            v22,
            (unsigned __int8)v23);
          LOBYTE(v25) = 2;
          BYTE1(v25) = v23;
          wlan_hdd_set_filter((__int64 *)a1, (unsigned __int8 *)&v25);
          ++v23;
        }
        v24 = v21;
        v21 >>= 1;
        ++v22;
      }
      while ( v24 > 1 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
