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
  __int64 v10; // x22
  __int64 v12; // x8
  int v13; // w9
  __int64 v14; // x11
  __int64 v15; // x20
  __int64 v16; // x10
  _QWORD *v17; // x13
  __int64 v18; // x12
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w2
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int16 (__fastcall *v45)(_QWORD); // x8

  v9 = *(_QWORD *)(a1 + 24);
  v10 = *(_QWORD *)a1;
  v12 = 0;
  v13 = 0;
  v14 = *(_QWORD *)a1;
  v15 = *(_QWORD *)(*(_QWORD *)(v9 + 24) + 8LL);
  v16 = 288;
  do
  {
    v17 = (_QWORD *)(v14 + v16);
    v16 += 120;
    v18 = *(_QWORD *)(a1 + 88) + v12;
    v12 += 144;
    *(_DWORD *)v18 = v13;
    *(_WORD *)(v18 + 72) = 0;
    *(_DWORD *)(v18 + 68) = 0;
    *(v17 - 6) = 0;
    *(v17 - 7) = 0;
    *((_DWORD *)v17 - 28) = v13++;
    *(v17 - 8) = v17 - 7;
    *((_DWORD *)v17 - 2) = 0;
    *(v17 - 13) = 0;
    *(v17 - 12) = 0;
    v14 = *(_QWORD *)a1;
    *v17 = *(_QWORD *)a1;
  }
  while ( v16 != 2328 );
  dp_rx_tid_setup_wifi3(a1, 0x10000u, 1u, 0, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( *(_DWORD *)(v9 + 64) || (*(_BYTE *)(v10 + 88) & 1) != 0 )
  {
    v45 = *(unsigned __int16 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v15 + 1128) + 74392LL) + 1160LL);
    if ( *((_DWORD *)v45 - 1) != 769334334 )
      __break(0x8228u);
    v27 = v45(0);
  }
  else
  {
    v27 = 1;
  }
  dp_rx_tid_setup_wifi3(a1, 1u, v27, 0, v19, v20, v21, v22, v23, v24, v25, v26);
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: Sett up tid_bitmap 0x%x for peer %pK peer->local_id %d",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "dp_peer_setup_remaining_tids",
    65534,
    a1,
    *(unsigned __int16 *)(a1 + 122));
  return dp_rx_tid_setup_wifi3(a1, 0xFFFEu, 1u, 0, v36, v37, v38, v39, v40, v41, v42, v43);
}
