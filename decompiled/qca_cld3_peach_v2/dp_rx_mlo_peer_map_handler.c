__int64 __fastcall dp_rx_mlo_peer_map_handler(
        __int64 a1,
        unsigned __int16 a2,
        unsigned __int8 *a3,
        __int16 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v14; // x7
  int v15; // w8
  int v16; // w9
  int v17; // w10
  __int16 v18; // w22
  __int16 v19; // w23
  __int64 add_id; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  __int64 v30; // x21
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6
  __int64 v36; // x7
  void (__fastcall *v37)(__int64, __int64, __int64, __int64, __int64); // x8
  __int64 v38; // x2
  __int64 v39; // x3

  if ( a3 )
  {
    v14 = *a3;
    v15 = a3[1];
    v16 = a3[2];
    v17 = a3[5];
  }
  else
  {
    v16 = 0;
    v14 = 0;
    v15 = 0;
    v17 = 0;
  }
  v18 = *a4;
  v19 = *((unsigned __int8 *)a4 + 5);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: mlo_peer_map_event (soc:%pK): peer_id %d ml_peer_id %d, peer_mac %02x:%02x:%02x:**:**:%02x",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "dp_rx_mlo_peer_map_handler",
    a1,
    a2,
    (unsigned __int16)((1 << *(_DWORD *)(a1 + 13328)) | *(_WORD *)(a1 + 13332) & a2),
    v14,
    v15,
    v16,
    v17);
  if ( a1 )
    ++*(_DWORD *)(a1 + 17572);
  add_id = dp_peer_find_add_id(a1, (int)a3);
  if ( add_id )
  {
    v29 = *(_QWORD *)(add_id + 24);
    v30 = add_id;
    if ( *(_DWORD *)(v29 + 32) == 3 )
    {
      if ( (unsigned int)qdf_mem_cmp((const void *)(add_id + 44), (const void *)(v29 + 104), 6u) )
      {
        qdf_trace_msg(
          0x81u,
          5u,
          "%s: %pK: STA vdev bss_peer!!!!",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "dp_rx_mlo_peer_map_handler",
          a1);
        v31 = *(_QWORD *)v30;
        *(_BYTE *)(v30 + 120) |= 1u;
        if ( v31 )
          *(_BYTE *)(v31 + 88) |= 2u;
      }
    }
    v32 = *(_QWORD *)(v30 + 24);
    if ( *(_DWORD *)(v32 + 32) == 3 )
    {
      *(_WORD *)(v32 + 76) = v19;
      *(_WORD *)(v32 + 78) = v18;
    }
    if ( !*(_QWORD *)(v30 + 32) )
    {
      if ( a3 )
      {
        v33 = *a3;
        v34 = a3[1];
        v35 = a3[2];
        v36 = a3[5];
      }
      else
      {
        v35 = 0;
        v33 = 0;
        v34 = 0;
        v36 = 0;
      }
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Add self ast from map %02x:%02x:%02x:**:**:%02x",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "dp_rx_mlo_peer_map_handler",
        v33,
        v34,
        v35,
        v36);
    }
    v37 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(*(_QWORD *)(a1 + 8) + 360LL);
    if ( v37 )
    {
      v38 = *(unsigned __int16 *)(v30 + 16);
      v39 = *(unsigned __int8 *)(*(_QWORD *)(v30 + 24) + 59LL);
      if ( *((_DWORD *)v37 - 1) != -1684742716 )
        __break(0x8228u);
      v37(a1, 1, v38, v39, v30 + 44);
    }
  }
  return 0;
}
