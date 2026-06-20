__int64 __fastcall extract_peer_oper_mode_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        int a11,
        __int64 a12)
{
  __int64 v12; // x13
  int v13; // w12
  int v14; // w14
  int v15; // w15
  int v16; // w16
  int v17; // w8
  int v18; // w9
  int v19; // w10
  int v20; // w11
  int v21; // w13
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  __int64 v25; // x4

  if ( a10 && a11 )
  {
    v12 = *a10;
    v13 = *(_DWORD *)(*a10 + 4);
    *(_BYTE *)a12 = v13;
    v14 = *(_DWORD *)(v12 + 4);
    *(_BYTE *)(a12 + 1) = BYTE1(v14);
    v15 = *(_DWORD *)(v12 + 4);
    *(_BYTE *)(a12 + 2) = BYTE2(v15);
    *(_BYTE *)(a12 + 3) = *(_BYTE *)(v12 + 7);
    *(_BYTE *)(a12 + 4) = *(_DWORD *)(v12 + 8);
    v16 = *(_DWORD *)(v12 + 8);
    *(_BYTE *)(a12 + 5) = BYTE1(v16);
    v17 = *(_DWORD *)(v12 + 12);
    *(_DWORD *)(a12 + 8) = v17;
    v18 = *(_DWORD *)(v12 + 16);
    *(_DWORD *)(a12 + 12) = v18;
    v19 = *(_DWORD *)(v12 + 20);
    *(_DWORD *)(a12 + 16) = v19;
    v20 = *(_DWORD *)(v12 + 24);
    *(_DWORD *)(a12 + 20) = v20;
    v21 = *(_DWORD *)(v12 + 28);
    *(_DWORD *)(a12 + 24) = v21;
    if ( a12 )
    {
      v22 = BYTE1(v14);
      v23 = BYTE2(v15);
      v24 = BYTE1(v16);
      v25 = (unsigned __int8)v13;
    }
    else
    {
      v23 = 0;
      v25 = 0;
      v22 = 0;
      v24 = 0;
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: peer_mac_addr: %02x:%02x:%02x:**:**:%02x ind_type: %d new_rxnss: %d new_bw: %d new_txnss: %d new_disablemu: %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_peer_oper_mode_event_tlv",
      v25,
      v22,
      v23,
      v24,
      v17,
      v18,
      v19,
      v20,
      v21);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Empty operating mode change event",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_peer_oper_mode_event_tlv");
    return 16;
  }
}
