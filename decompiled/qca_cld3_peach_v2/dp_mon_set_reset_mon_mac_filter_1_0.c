__int64 __fastcall dp_mon_set_reset_mon_mac_filter_1_0(
        __int64 a1,
        __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  __int64 v22; // x27
  __int64 v23; // x8
  __int64 v24; // x23
  __int64 v25; // x8
  int v26; // w25
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x9
  __int64 v36; // x10
  __int64 v37; // x8
  __int64 v38; // x9
  __int64 v39; // x12
  __int64 v40; // x10
  __int64 v41; // x11
  __int64 v42; // x12
  __int64 v43; // x9
  __int128 v44; // kr00_16
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  char v53; // w10
  unsigned __int64 v54; // x9
  __int16 v55; // w8
  __int64 result; // x0
  __int64 v57; // x11
  __int64 v58; // x10
  __int64 v59; // x12
  __int64 v60; // x8
  __int64 v61; // x9
  __int64 v62; // x11
  __int64 v63; // x12
  __int64 v64; // x10
  __int128 v65; // kr10_16
  __int128 v66; // [xsp+8h] [xbp-68h] BYREF
  __int64 v67; // [xsp+18h] [xbp-58h]
  __int64 v68; // [xsp+20h] [xbp-50h]
  __int64 v69; // [xsp+28h] [xbp-48h]
  __int64 v70; // [xsp+30h] [xbp-40h]
  __int64 v71; // [xsp+38h] [xbp-38h]
  __int64 v72; // [xsp+40h] [xbp-30h]
  __int64 v73; // [xsp+48h] [xbp-28h]
  __int64 v74; // [xsp+50h] [xbp-20h]
  __int64 v75; // [xsp+58h] [xbp-18h]
  int v76; // [xsp+60h] [xbp-10h]
  __int64 v77; // [xsp+68h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v76 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v67 = 0;
  v66 = 0u;
  if ( a1 )
  {
    v11 = *(_QWORD *)(a1 + 96456);
    qdf_trace_msg(
      0x73u,
      8u,
      "%s: Updating monitor buffer filter",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_mon_set_reset_mon_mac_filter_1_0");
    if ( (a2 & 1) != 0 )
      v21 = "%s: Set monitor filter settings";
    else
      v21 = "%s: Reset monitor filter settings";
    LOBYTE(v66) = 1;
    if ( (a2 & 1) != 0 )
      v22 = 0x8000;
    else
      v22 = 0;
    qdf_trace_msg(0x73u, 8u, v21, v13, v14, v15, v16, v17, v18, v19, v20, "dp_mon_set_reset_mon_filter");
    v23 = *(_QWORD *)(a1 + 8);
    LOBYTE(v76) = a2 & 1;
    v24 = *(_QWORD *)(a1 + 96456);
    *(_QWORD *)((char *)&v66 + 4) = v22;
    v25 = *(_QWORD *)(v23 + 40);
    HIWORD(v67) = (__int16)(a2 << 15) >> 15;
    LOWORD(v68) = HIWORD(v67);
    v26 = *(unsigned __int8 *)(v25 + 633);
    WORD2(v67) = 0;
    dp_mon_filter_set_mon_cmn(a1, &v66);
    ((void (__fastcall *)(__int64, _QWORD, __int128 *))dp_mon_filter_show_filter)(v24, 0, &v66);
    v35 = 184;
    if ( !v26 )
      v35 = 0;
    v36 = v72;
    v37 = **(_QWORD **)(v24 + 37064) + v35;
    v39 = v69;
    v38 = v70;
    *(_QWORD *)(v37 + 48) = v71;
    *(_QWORD *)(v37 + 56) = v36;
    *(_QWORD *)(v37 + 32) = v39;
    *(_QWORD *)(v37 + 40) = v38;
    v41 = v74;
    v40 = v75;
    v42 = v73;
    *(_DWORD *)(v37 + 88) = v76;
    *(_QWORD *)(v37 + 72) = v41;
    *(_QWORD *)(v37 + 80) = v40;
    *(_QWORD *)(v37 + 64) = v42;
    v43 = v68;
    v44 = v66;
    *(_QWORD *)(v37 + 16) = v67;
    *(_QWORD *)(v37 + 24) = v43;
    *(_OWORD *)v37 = v44;
    qdf_trace_msg(
      0x73u,
      8u,
      "%s: Updating monitor status cmn filter",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "dp_mon_set_reset_mon_mac_filter_1_0");
    qdf_mem_set(&v66, 0x5Cu, 0);
    LOBYTE(v66) = 1;
    dp_mon_filter_set_status_cmn(v11, &v66);
    if ( (a2 & 1) != 0 )
    {
      qdf_trace_msg(
        0x73u,
        8u,
        "%s: Set monitor filter settings",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "dp_mon_set_reset_mon_filter");
      v53 = 1;
      v54 = *(_QWORD *)((char *)&v66 + 4) | 0x8000LL;
      v55 = -1;
    }
    else
    {
      qdf_trace_msg(
        0x73u,
        8u,
        "%s: Reset monitor filter settings",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "dp_mon_set_reset_mon_filter");
      v53 = 0;
      v55 = 0;
      v54 = *(_QWORD *)((_BYTE *)&v66 + 4) & 0xFFFFFFFFFFFF7FFFLL;
    }
    LOBYTE(v76) = v53;
    *(_QWORD *)((char *)&v66 + 4) = v54;
    HIWORD(v67) = v55;
    LOWORD(v68) = v55;
    WORD2(v67) = 0;
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int128 *))dp_mon_filter_show_filter)(v11, 0, &v66);
    v57 = v70;
    v59 = v71;
    v58 = v72;
    v60 = **(_QWORD **)(v11 + 37064);
    *(_QWORD *)(v60 + 124) = v69;
    *(_QWORD *)(v60 + 148) = v58;
    *(_QWORD *)(v60 + 140) = v59;
    *(_QWORD *)(v60 + 132) = v57;
    v61 = v73;
    v62 = v74;
    v63 = v75;
    *(_DWORD *)(v60 + 180) = v76;
    *(_QWORD *)(v60 + 156) = v61;
    *(_QWORD *)(v60 + 172) = v63;
    *(_QWORD *)(v60 + 164) = v62;
    v64 = v67;
    v65 = v66;
    *(_QWORD *)(v60 + 116) = v68;
    *(_QWORD *)(v60 + 108) = v64;
    *(_OWORD *)(v60 + 92) = v65;
  }
  else
  {
    result = qdf_trace_msg(
               0x73u,
               2u,
               "%s: pdev Context is null",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "dp_mon_set_reset_mon_mac_filter_1_0");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
