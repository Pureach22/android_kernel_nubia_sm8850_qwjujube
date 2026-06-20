__int64 __fastcall dp_peer_legacy_setup(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x0
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  __int64 v16; // x9
  char v17; // w8
  int v18; // w10
  __int64 v19; // x8
  char v20; // w10
  _BYTE *v21; // x8
  __int64 v22; // x3
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // [xsp+0h] [xbp-20h] BYREF
  __int64 v32; // [xsp+8h] [xbp-18h]
  __int64 v33; // [xsp+10h] [xbp-10h]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)a2 )
  {
    v4 = *(_QWORD *)(a1 + 40);
    v32 = 0;
    v33 = 0;
    v31 = 0;
    wlan_cfg_is_peer_link_stats_enabled(v4);
    v6 = _qdf_mem_malloc(0x1568u, "dp_txrx_peer_attach", 6113);
    if ( !v6 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: peer txrx ctx alloc failed",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "dp_peer_legacy_setup");
      result = 16;
      goto LABEL_3;
    }
    v15 = v6;
    *(_WORD *)(v6 + 8) = -1;
    v16 = *(_QWORD *)(a2 + 24);
    *(_BYTE *)(v6 + 2221) = 1;
    *(_DWORD *)(v6 + 2216) = 5;
    *(_QWORD *)v6 = v16;
    qdf_mem_set((void *)(v6 + 2224), 0xCB8u, 0);
    *(_DWORD *)(v15 + 120) = 0;
    *(_QWORD *)(v15 + 128) = 0;
    *(_DWORD *)(v15 + 136) = 64;
    *(_QWORD *)(v15 + 96) = v15 + 96;
    *(_QWORD *)(v15 + 104) = v15 + 96;
    v17 = *(_BYTE *)(v15 + 10);
    v18 = *(unsigned __int16 *)(v15 + 168);
    *(_QWORD *)(v15 + 112) = 0x4000000000LL;
    *(_BYTE *)(v15 + 10) = v17 & 0xFB;
    if ( v18 )
      *(_BYTE *)(v15 + 88) &= ~4u;
    qdf_mem_set((void *)(v15 + 176), 0x7F8u, 0);
    *(_DWORD *)(v15 + 248) = 0;
    *(_QWORD *)(v15 + 256) = 0;
    *(_DWORD *)(v15 + 368) = 0;
    *(_QWORD *)(v15 + 376) = 0;
    *(_DWORD *)(v15 + 488) = 0;
    *(_QWORD *)(v15 + 496) = 0;
    *(_DWORD *)(v15 + 608) = 0;
    *(_QWORD *)(v15 + 616) = 0;
    *(_DWORD *)(v15 + 728) = 0;
    *(_QWORD *)(v15 + 736) = 0;
    *(_DWORD *)(v15 + 848) = 0;
    *(_QWORD *)(v15 + 856) = 0;
    *(_DWORD *)(v15 + 968) = 0;
    *(_QWORD *)(v15 + 976) = 0;
    *(_DWORD *)(v15 + 1088) = 0;
    *(_QWORD *)(v15 + 1096) = 0;
    *(_DWORD *)(v15 + 1208) = 0;
    *(_QWORD *)(v15 + 1216) = 0;
    *(_DWORD *)(v15 + 1328) = 0;
    *(_QWORD *)(v15 + 1336) = 0;
    *(_DWORD *)(v15 + 1448) = 0;
    *(_QWORD *)(v15 + 1456) = 0;
    *(_DWORD *)(v15 + 1568) = 0;
    *(_QWORD *)(v15 + 1576) = 0;
    *(_DWORD *)(v15 + 1688) = 0;
    *(_QWORD *)(v15 + 1696) = 0;
    *(_DWORD *)(v15 + 1808) = 0;
    *(_QWORD *)(v15 + 1816) = 0;
    *(_DWORD *)(v15 + 1928) = 0;
    *(_QWORD *)(v15 + 1936) = 0;
    *(_DWORD *)(v15 + 2048) = 0;
    *(_QWORD *)(v15 + 2056) = 0;
    *(_DWORD *)(v15 + 2168) = 0;
    *(_QWORD *)(v15 + 2176) = 0;
    dp_txrx_peer_attach_add(a1, a2, v15);
    v19 = *(_QWORD *)(a2 + 24);
    if ( *(_DWORD *)(v19 + 32) != 3 && (*(_BYTE *)(a2 + 120) & 1) == 0 )
    {
      v20 = *(_BYTE *)(v19 + 59);
      v21 = *(_BYTE **)(v19 + 24);
      v32 = a2 + 44;
      v22 = *(unsigned __int16 *)(a2 + 16);
      LOBYTE(v31) = v20;
      LOBYTE(v33) = 0;
      BYTE1(v33) = *v21;
      v23 = dp_wdi_event_handler(298, a1, &v31, v22, 0xFFFFFFFFLL);
      wlan_minidump_log(v23, v24, v25, v26, v27, v28, v29, v30, v15, 2224, *(_QWORD *)(a1 + 16));
    }
  }
  result = 0;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
