__int64 __fastcall dp_peer_rx_tid_setup(
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
  __int64 v9; // x21
  __int64 v11; // x20
  __int64 v12; // x8
  __int64 *v13; // x9
  __int64 v14; // x22
  __int64 v15; // x9
  int v16; // w8
  __int64 v17; // x10
  _QWORD *v18; // x11
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w2
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned __int16 (__fastcall *v62)(_QWORD); // x8

  v9 = *(_QWORD *)(a1 + 24);
  v11 = *(_QWORD *)(*(_QWORD *)(v9 + 24) + 8LL);
  if ( *(_DWORD *)(a1 + 408) == 1 )
  {
    v12 = *(_QWORD *)(a1 + 416);
    if ( v12 )
      v13 = *(__int64 **)(a1 + 416);
    else
      v13 = (__int64 *)a1;
    v14 = *v13;
    if ( v12 )
      goto LABEL_12;
    v15 = *(_QWORD *)a1;
  }
  else
  {
    v15 = *(_QWORD *)a1;
    v14 = *(_QWORD *)a1;
  }
  v16 = 0;
  v17 = 288;
  do
  {
    v18 = (_QWORD *)(v15 + v17);
    v17 += 120;
    *((_DWORD *)v18 - 2) = 0;
    *(v18 - 7) = 0;
    *(v18 - 8) = v18 - 7;
    *(v18 - 13) = 0;
    *(v18 - 12) = 0;
    *(v18 - 6) = 0;
    *((_DWORD *)v18 - 28) = v16++;
    v15 = *(_QWORD *)a1;
    *v18 = *(_QWORD *)a1;
  }
  while ( v17 != 2328 );
  if ( *(_DWORD *)(a1 + 408) != 1 || !*(_QWORD *)(a1 + 416) )
    goto LABEL_13;
LABEL_12:
  if ( (*(_BYTE *)(a1 + 128) & 1) != 0 )
  {
LABEL_13:
    v19 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)v19 = 0;
    *(_WORD *)(v19 + 72) = 0;
    *(_DWORD *)(v19 + 68) = 0;
    v20 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v20 + 144) = 1;
    *(_WORD *)(v20 + 216) = 0;
    *(_DWORD *)(v20 + 212) = 0;
    v21 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v21 + 288) = 2;
    *(_WORD *)(v21 + 360) = 0;
    *(_DWORD *)(v21 + 356) = 0;
    v22 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v22 + 432) = 3;
    *(_WORD *)(v22 + 504) = 0;
    *(_DWORD *)(v22 + 500) = 0;
    v23 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v23 + 576) = 4;
    *(_WORD *)(v23 + 648) = 0;
    *(_DWORD *)(v23 + 644) = 0;
    v24 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v24 + 720) = 5;
    *(_WORD *)(v24 + 792) = 0;
    *(_DWORD *)(v24 + 788) = 0;
    v25 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v25 + 864) = 6;
    *(_WORD *)(v25 + 936) = 0;
    *(_DWORD *)(v25 + 932) = 0;
    v26 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v26 + 1008) = 7;
    *(_WORD *)(v26 + 1080) = 0;
    *(_DWORD *)(v26 + 1076) = 0;
    v27 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v27 + 1152) = 8;
    *(_WORD *)(v27 + 1224) = 0;
    *(_DWORD *)(v27 + 1220) = 0;
    v28 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v28 + 1296) = 9;
    *(_WORD *)(v28 + 1368) = 0;
    *(_DWORD *)(v28 + 1364) = 0;
    v29 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v29 + 1440) = 10;
    *(_WORD *)(v29 + 1512) = 0;
    *(_DWORD *)(v29 + 1508) = 0;
    v30 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v30 + 1584) = 11;
    *(_WORD *)(v30 + 1656) = 0;
    *(_DWORD *)(v30 + 1652) = 0;
    v31 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v31 + 1728) = 12;
    *(_WORD *)(v31 + 1800) = 0;
    *(_DWORD *)(v31 + 1796) = 0;
    v32 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v32 + 1872) = 13;
    *(_WORD *)(v32 + 1944) = 0;
    *(_DWORD *)(v32 + 1940) = 0;
    v33 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v33 + 2016) = 14;
    *(_WORD *)(v33 + 2088) = 0;
    *(_DWORD *)(v33 + 2084) = 0;
    v34 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v34 + 2160) = 15;
    *(_WORD *)(v34 + 2232) = 0;
    *(_DWORD *)(v34 + 2228) = 0;
    v35 = *(_QWORD *)(a1 + 88);
    *(_DWORD *)(v35 + 2304) = 16;
    *(_WORD *)(v35 + 2376) = 0;
    *(_DWORD *)(v35 + 2372) = 0;
  }
  dp_rx_tid_setup_wifi3(a1, 0x10000u, 1u, 0, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( *(_DWORD *)(v9 + 64) || (*(_BYTE *)(v14 + 88) & 1) != 0 )
  {
    v62 = *(unsigned __int16 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v11 + 1128) + 74392LL) + 1160LL);
    if ( *((_DWORD *)v62 - 1) != 769334334 )
      __break(0x8228u);
    v44 = v62(0);
  }
  else
  {
    v44 = 1;
  }
  dp_rx_tid_setup_wifi3(a1, 1u, v44, 0, v36, v37, v38, v39, v40, v41, v42, v43);
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: Sett up tid_bitmap 0x%x for peer %pK peer->local_id %d",
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    "dp_peer_setup_remaining_tids",
    65534,
    a1,
    *(unsigned __int16 *)(a1 + 122));
  return dp_rx_tid_setup_wifi3(a1, 0xFFFEu, 1u, 0, v53, v54, v55, v56, v57, v58, v59, v60);
}
