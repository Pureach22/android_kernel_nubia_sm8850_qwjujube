__int64 __fastcall sch_beacon_edca_process(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x22
  char follow_ap_edca_flag; // w0
  int v16; // w9
  char v17; // w10
  char v18; // w10
  char v19; // w10
  __int64 v20; // x8
  char v21; // w10
  char v22; // w11
  char v23; // w12
  char v24; // w8
  char v25; // w9
  char v26; // w10
  char v27; // w11
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x21
  unsigned int v38; // w1
  unsigned int v39; // w10
  unsigned int v40; // w12
  unsigned int v41; // w13
  unsigned int v42; // w15
  unsigned int v43; // w2

  if ( *(_QWORD *)(a1 + 8) )
  {
    v14 = a3 + 4096;
    follow_ap_edca_flag = mlme_get_follow_ap_edca_flag(*(_QWORD *)(a3 + 16), a4, a5, a6, a7, a8, a9, a10, a11);
    *(_BYTE *)(v14 + 3060) = *(_BYTE *)(a2 + 2) & 0xF;
    v16 = *(_DWORD *)(a2 + 4);
    *(_BYTE *)(v14 + 3004) = *(_BYTE *)(a2 + 8);
    *(_DWORD *)(v14 + 3000) = v16;
    v17 = *(_BYTE *)(a2 + 13);
    *(_DWORD *)(v14 + 3005) = *(_DWORD *)(a2 + 9);
    *(_BYTE *)(v14 + 3009) = v17;
    v18 = *(_BYTE *)(a2 + 18);
    *(_DWORD *)(v14 + 3010) = *(_DWORD *)(a2 + 14);
    *(_BYTE *)(v14 + 3014) = v18;
    v19 = *(_BYTE *)(a2 + 23);
    *(_DWORD *)(v14 + 3015) = *(_DWORD *)(a2 + 19);
    *(_BYTE *)(v14 + 3019) = v19;
    v20 = *(_QWORD *)(a1 + 8);
    if ( *(_BYTE *)(v20 + 976) == 1 && (follow_ap_edca_flag & 1) == 0 )
    {
      v21 = *(_BYTE *)(v14 + 3011);
      v22 = *(_BYTE *)(v14 + 3006);
      v23 = *(_BYTE *)(v14 + 3001);
      *(_BYTE *)(v14 + 3015) = *(_BYTE *)(v14 + 3015) & 0xF0 | *(_BYTE *)(v20 + 988) & 0xF;
      *(_BYTE *)(v14 + 3010) = *(_BYTE *)(v14 + 3010) & 0xF0 | *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1000LL) & 0xF;
      *(_BYTE *)(v14 + 3005) = *(_BYTE *)(v14 + 3005) & 0xF0 | *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1012LL) & 0xF;
      *(_BYTE *)(v14 + 3000) = *(_BYTE *)(v14 + 3000) & 0xF0 | *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1024LL) & 0xF;
      v24 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 980LL);
      *(_BYTE *)(v14 + 3016) = *(_BYTE *)(v14 + 3016) & 0xF0 | v24 & 0xF;
      v25 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 992LL);
      *(_BYTE *)(v14 + 3011) = v21 & 0xF0 | v25 & 0xF;
      v26 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1004LL);
      *(_BYTE *)(v14 + 3006) = v22 & 0xF0 | v26 & 0xF;
      v27 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1016LL);
      *(_BYTE *)(v14 + 3001) = v23 & 0xF0 | v27 & 0xF;
      *(_BYTE *)(v14 + 3016) = v24 & 0xF | (16 * *(_BYTE *)(*(_QWORD *)(a1 + 8) + 984LL));
      *(_BYTE *)(v14 + 3011) = v25 & 0xF | (16 * *(_BYTE *)(*(_QWORD *)(a1 + 8) + 996LL));
      *(_BYTE *)(v14 + 3006) = v26 & 0xF | (16 * *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1008LL));
      *(_BYTE *)(v14 + 3001) = v27 & 0xF | (16 * *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1020LL));
    }
    v28 = _qdf_mem_malloc(0x1Cu, "sch_beacon_edca_process", 1176);
    if ( v28 )
    {
      v37 = v28;
      host_diag_log_set_code(v28, 5274);
      host_diag_log_set_length(v37, 28);
      *(_BYTE *)(v37 + 12) = (*(_BYTE *)(v14 + 3000) >> 5) & 3;
      *(_BYTE *)(v37 + 13) = *(_BYTE *)(v14 + 3001);
      *(_WORD *)(v37 + 14) = *(_WORD *)(a3 + 7098);
      *(_BYTE *)(v37 + 16) = (*(_BYTE *)(v14 + 3005) >> 5) & 3;
      *(_BYTE *)(v37 + 17) = *(_BYTE *)(v14 + 3006);
      *(_WORD *)(v37 + 18) = *(_WORD *)(v14 + 3007);
      *(_BYTE *)(v37 + 20) = (*(_BYTE *)(v14 + 3010) >> 5) & 3;
      *(_BYTE *)(v37 + 21) = *(_BYTE *)(v14 + 3011);
      *(_WORD *)(v37 + 22) = *(_WORD *)(a3 + 7108);
      *(_BYTE *)(v37 + 24) = (*(_BYTE *)(v14 + 3015) >> 5) & 3;
      *(_BYTE *)(v37 + 25) = *(_BYTE *)(v14 + 3016);
      *(_WORD *)(v37 + 26) = *(_WORD *)(v14 + 3017);
      host_diag_log_submit(v37);
      _qdf_mem_free(v37);
    }
    v38 = *(unsigned __int8 *)(v14 + 3011);
    v39 = *(unsigned __int8 *)(v14 + 3001);
    v40 = *(unsigned __int8 *)(v14 + 3005);
    v41 = *(unsigned __int8 *)(v14 + 3006);
    v42 = *(unsigned __int8 *)(v14 + 3010);
    v43 = *(unsigned __int8 *)(v14 + 3015);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Vdev_id: %d Edca param enabled %d. Updating Local Params to: AC_BE: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxO"
      "p %d  AC_BK: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxOp %d  AC_VI: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxOp %d"
      "  AC_VO: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxOp %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "sch_beacon_edca_process",
      *(unsigned __int8 *)(a3 + 10),
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 976LL),
      *(_BYTE *)(v14 + 3000) & 0xF,
      (*(unsigned __int8 *)(v14 + 3000) >> 4) & 1,
      v39 & 0xF,
      v39 >> 4,
      *(unsigned __int16 *)(a3 + 7098),
      v40 & 0xF,
      (v40 >> 4) & 1,
      v41 & 0xF,
      v41 >> 4,
      *(unsigned __int16 *)(v14 + 3007),
      v42 & 0xF,
      (v42 >> 4) & 1,
      v38 & 0xF,
      v38 >> 4,
      *(unsigned __int16 *)(a3 + 7108),
      v43 & 0xF,
      (v43 >> 4) & 1,
      *(_BYTE *)(v14 + 3016) & 0xF,
      *(unsigned __int8 *)(v14 + 3016) >> 4,
      *(unsigned __int16 *)(v14 + 3017));
    return 0;
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: invalid mlme cfg", a4, a5, a6, a7, a8, a9, a10, a11, "sch_beacon_edca_process");
    return 16;
  }
}
