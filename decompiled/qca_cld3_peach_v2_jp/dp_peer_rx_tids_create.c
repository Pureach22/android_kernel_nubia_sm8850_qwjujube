__int64 __fastcall dp_peer_rx_tids_create(
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
  void *v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
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
  __int64 v36; // x8

  if ( *(_QWORD *)(a1 + 88) )
  {
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: peer rx_tid mem already exist",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_peer_rx_tids_create");
    return 16;
  }
  else
  {
    v11 = (void *)_qdf_mem_malloc(0x990u, "dp_peer_rx_tids_create", 2132);
    *(_QWORD *)(a1 + 88) = v11;
    if ( v11 )
    {
      qdf_mem_set(v11, 0x990u, 0);
      v20 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v20 + 88) = 0;
      *(_QWORD *)(v20 + 96) = 0;
      v21 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v21 + 232) = 0;
      *(_QWORD *)(v21 + 240) = 0;
      v22 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v22 + 376) = 0;
      *(_QWORD *)(v22 + 384) = 0;
      v23 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v23 + 520) = 0;
      *(_QWORD *)(v23 + 528) = 0;
      v24 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v24 + 664) = 0;
      *(_QWORD *)(v24 + 672) = 0;
      v25 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v25 + 808) = 0;
      *(_QWORD *)(v25 + 816) = 0;
      v26 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v26 + 952) = 0;
      *(_QWORD *)(v26 + 960) = 0;
      v27 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v27 + 1096) = 0;
      *(_QWORD *)(v27 + 1104) = 0;
      v28 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v28 + 1240) = 0;
      *(_QWORD *)(v28 + 1248) = 0;
      v29 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v29 + 1384) = 0;
      *(_QWORD *)(v29 + 1392) = 0;
      v30 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v30 + 1528) = 0;
      *(_QWORD *)(v30 + 1536) = 0;
      v31 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v31 + 1672) = 0;
      *(_QWORD *)(v31 + 1680) = 0;
      v32 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v32 + 1816) = 0;
      *(_QWORD *)(v32 + 1824) = 0;
      v33 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v33 + 1960) = 0;
      *(_QWORD *)(v33 + 1968) = 0;
      v34 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v34 + 2104) = 0;
      *(_QWORD *)(v34 + 2112) = 0;
      v35 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v35 + 2248) = 0;
      *(_QWORD *)(v35 + 2256) = 0;
      v36 = *(_QWORD *)(a1 + 88);
      *(_DWORD *)(v36 + 2392) = 0;
      *(_QWORD *)(v36 + 2400) = 0;
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: fail to alloc tid for peer%02x:%02x:%02x:**:**:%02x",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "dp_peer_rx_tids_create",
        *(unsigned __int8 *)(a1 + 44),
        *(unsigned __int8 *)(a1 + 45),
        *(unsigned __int8 *)(a1 + 46),
        *(unsigned __int8 *)(a1 + 49));
      return 2;
    }
  }
}
