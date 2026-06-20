__int64 __fastcall wma_set_peer_pmf_status(__int64 a1, unsigned __int8 *a2)
{
  __int64 peer; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x5
  __int64 v22; // x6
  __int64 v23; // x7
  int v24; // w8
  __int64 v25; // x4
  const char *v26; // x2
  unsigned int v27; // w1
  int v29; // [xsp+0h] [xbp-10h]

  peer = wlan_objmgr_get_peer(*(_QWORD *)(a1 + 24), *(_BYTE *)(*(_QWORD *)(a1 + 32) + 40LL), a2, 8u);
  if ( peer )
  {
    v12 = peer;
    mlme_set_peer_pmf_status(peer, 1);
    wlan_objmgr_peer_release_ref(v12, 8u, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( a2 )
    {
      v21 = *a2;
      v22 = a2[1];
      v23 = a2[2];
      v24 = a2[5];
    }
    else
    {
      v23 = 0;
      v21 = 0;
      v22 = 0;
      v24 = 0;
    }
    v26 = "%s: set is_pmf_enabled %d for %02x:%02x:%02x:**:**:%02x";
    v27 = 8;
    v25 = 1;
    v29 = v24;
  }
  else
  {
    if ( a2 )
    {
      v25 = *a2;
      v21 = a2[1];
      v22 = a2[2];
      v23 = a2[5];
    }
    else
    {
      v22 = 0;
      v25 = 0;
      v21 = 0;
      v23 = 0;
    }
    v26 = "%s: Peer of peer_mac %02x:%02x:%02x:**:**:%02x not found";
    v27 = 2;
  }
  return qdf_trace_msg(
           0x36u,
           v27,
           v26,
           v4,
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           "wma_set_peer_pmf_status",
           v25,
           v21,
           v22,
           v23,
           v29);
}
