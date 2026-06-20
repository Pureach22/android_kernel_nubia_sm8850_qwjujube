void __fastcall dp_cfr_filter_2_0(
        __int64 a1,
        char a2,
        char a3,
        unsigned __int16 *a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x20
  __int64 v14; // x21
  __int64 v15; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x5
  int v27; // w8
  unsigned __int64 v28; // x9
  _QWORD v29[9]; // [xsp+8h] [xbp-98h] BYREF
  __int128 v30; // [xsp+50h] [xbp-50h]
  __int64 v31; // [xsp+60h] [xbp-40h]
  __int64 v32; // [xsp+68h] [xbp-38h]
  __int64 v33; // [xsp+70h] [xbp-30h]
  __int64 v34; // [xsp+78h] [xbp-28h]
  __int64 v35; // [xsp+80h] [xbp-20h]
  __int64 v36; // [xsp+88h] [xbp-18h]
  __int64 v37; // [xsp+90h] [xbp-10h]
  __int64 v38; // [xsp+98h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v31 = 0;
  v30 = 0u;
  memset(v29, 0, sizeof(v29));
  if ( a2 || (v13 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    qdf_trace_msg(0x92u, 2u, "%s: pdev is NULL", a6, a7, a8, a9, a10, a11, a12, a13, "dp_cfr_filter_2_0");
  }
  else if ( *(_QWORD *)(*(_QWORD *)(v13 + 96456) + 16LL) )
  {
    *(_BYTE *)(v13 + 95936) = (a3 & 1) != 0 && (a5 & 1) != 0;
  }
  else
  {
    v14 = *(_QWORD *)(v13 + 8);
    v15 = *(_QWORD *)(a1 + 72);
    *(_BYTE *)(v13 + 95936) = 0;
    dp_rx_mon_filter_h2t_setup(v15, (__int64)v29, a6, a7, a8, a9, a10, a11, a12, a13);
    v26 = *a4;
    if ( LOBYTE(v29[0]) )
      v27 = 0x8000;
    else
      v27 = 0;
    *(_DWORD *)((char *)&v30 + 6) = *(_DWORD *)((_BYTE *)&v30 + 6) & 0xFFFF7FFF | v27;
    qdf_trace_msg(
      0x92u,
      5u,
      "%s: enable : %d, mode: 0x%x",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "dp_cfr_filter_2_0",
      a3 & 1,
      v26);
    if ( (a3 & 1) != 0 )
    {
      *(_BYTE *)(v13 + 95936) = 1;
      v28 = a4[2] | ((unsigned __int64)a4[3] << 32) | ((unsigned __int64)a4[5] << 16) | ((unsigned __int64)a4[6] << 48);
      *(_QWORD *)((char *)v29 + 4) = HIDWORD(v29[0]) & 0xFFDE307E
                                   | (unsigned __int64)((*a4 & 1u) << 14)
                                   | (((*a4 >> 1) & 1LL) << 16)
                                   | ((unsigned __int64)a4[1] << 32)
                                   | ((unsigned __int64)a4[4] << 48)
                                   | 0xF81;
      *(_QWORD *)((char *)&v29[1] + 4) = v28;
    }
    dp_mon_ht2_rx_ring_cfg(v14, (unsigned __int8 *)v13, 3, (int *)v29 + 1);
  }
  _ReadStatusReg(SP_EL0);
}
