__int64 __fastcall dp_txrx_peer_attach(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  unsigned int v5; // w22
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 v8; // x8
  char v9; // w8
  int v10; // w10
  __int64 v11; // x8
  __int64 result; // x0
  char v13; // w10
  _BYTE *v14; // x8
  __int64 v15; // x3
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // [xsp+0h] [xbp-20h] BYREF
  __int64 v25; // [xsp+8h] [xbp-18h]
  __int64 v26; // [xsp+10h] [xbp-10h]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 40);
  v25 = 0;
  v26 = 0;
  v24 = 0;
  if ( (wlan_cfg_is_peer_link_stats_enabled(v4) & 1) != 0 && *(_DWORD *)(a2 + 408) == 2 )
    v5 = 5;
  else
    v5 = 1;
  v6 = _qdf_mem_malloc(4072LL * v5 + 2288, "dp_txrx_peer_attach", 6113);
  if ( v6 )
  {
    *(_WORD *)(v6 + 8) = -1;
    v7 = v6;
    v8 = *(_QWORD *)(a2 + 24);
    *(_BYTE *)(v6 + 2281) = v5;
    *(_DWORD *)(v6 + 2216) = 5;
    *(_QWORD *)v6 = v8;
    qdf_mem_set((void *)(v6 + 2288), 4072 * v5, 0);
    if ( *(_DWORD *)(a2 + 408) != 1 || *(_QWORD *)(a2 + 416) )
      *(_BYTE *)(v7 + 10) |= 8u;
    *(_DWORD *)(v7 + 120) = 0;
    *(_QWORD *)(v7 + 128) = 0;
    *(_DWORD *)(v7 + 136) = 64;
    *(_QWORD *)(v7 + 96) = v7 + 96;
    *(_QWORD *)(v7 + 104) = v7 + 96;
    v9 = *(_BYTE *)(v7 + 10);
    v10 = *(unsigned __int16 *)(v7 + 168);
    *(_QWORD *)(v7 + 112) = 0x4000000000LL;
    *(_BYTE *)(v7 + 10) = v9 & 0xFB;
    if ( v10 )
      *(_BYTE *)(v7 + 88) &= ~4u;
    qdf_mem_set((void *)(v7 + 176), 0x7F8u, 0);
    *(_DWORD *)(v7 + 248) = 0;
    *(_QWORD *)(v7 + 256) = 0;
    *(_DWORD *)(v7 + 368) = 0;
    *(_QWORD *)(v7 + 376) = 0;
    *(_DWORD *)(v7 + 488) = 0;
    *(_QWORD *)(v7 + 496) = 0;
    *(_DWORD *)(v7 + 608) = 0;
    *(_QWORD *)(v7 + 616) = 0;
    *(_DWORD *)(v7 + 728) = 0;
    *(_QWORD *)(v7 + 736) = 0;
    *(_DWORD *)(v7 + 848) = 0;
    *(_QWORD *)(v7 + 856) = 0;
    *(_DWORD *)(v7 + 968) = 0;
    *(_QWORD *)(v7 + 976) = 0;
    *(_DWORD *)(v7 + 1088) = 0;
    *(_QWORD *)(v7 + 1096) = 0;
    *(_DWORD *)(v7 + 1208) = 0;
    *(_QWORD *)(v7 + 1216) = 0;
    *(_DWORD *)(v7 + 1328) = 0;
    *(_QWORD *)(v7 + 1336) = 0;
    *(_DWORD *)(v7 + 1448) = 0;
    *(_QWORD *)(v7 + 1456) = 0;
    *(_DWORD *)(v7 + 1568) = 0;
    *(_QWORD *)(v7 + 1576) = 0;
    *(_DWORD *)(v7 + 1688) = 0;
    *(_QWORD *)(v7 + 1696) = 0;
    *(_DWORD *)(v7 + 1808) = 0;
    *(_QWORD *)(v7 + 1816) = 0;
    *(_DWORD *)(v7 + 1928) = 0;
    *(_QWORD *)(v7 + 1936) = 0;
    *(_DWORD *)(v7 + 2048) = 0;
    *(_QWORD *)(v7 + 2056) = 0;
    *(_DWORD *)(v7 + 2168) = 0;
    *(_QWORD *)(v7 + 2176) = 0;
    dp_txrx_peer_attach_add(a1, a2, v7);
    v11 = *(_QWORD *)(a2 + 24);
    result = 0;
    if ( *(_DWORD *)(v11 + 32) != 3 )
    {
      if ( (*(_BYTE *)(a2 + 120) & 1) == 0 )
      {
        v13 = *(_BYTE *)(v11 + 59);
        v14 = *(_BYTE **)(v11 + 24);
        v25 = a2 + 44;
        v15 = *(unsigned __int16 *)(a2 + 16);
        LOBYTE(v24) = v13;
        LOBYTE(v26) = 0;
        BYTE1(v26) = *v14;
        dp_wdi_event_handler(299, a1, &v24, v15, 0xFFFFFFFFLL);
        wlan_minidump_log(v16, v17, v18, v19, v20, v21, v22, v23, v7, 2288, *(_QWORD *)(a1 + 16));
      }
      result = 0;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
