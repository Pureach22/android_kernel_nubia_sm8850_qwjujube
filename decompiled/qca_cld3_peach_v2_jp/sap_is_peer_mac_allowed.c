__int64 __fastcall sap_is_peer_mac_allowed(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  int v35; // w8
  const char *v36; // x2
  unsigned int v37; // w1
  __int64 v38; // [xsp+8h] [xbp-18h]

  if ( *(_DWORD *)(a1 + 824) == 3 )
    return 0;
  v38 = v11;
  if ( (sap_search_mac_list(a1 + 828, *(_WORD *)(a1 + 1020), a2, nullptr, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
    return 0;
  if ( (sap_search_mac_list(a1 + 1022, *(_WORD *)(a1 + 1214), a2, nullptr, v15, v16, v17, v18, v19, v20, v21, v22) & 1) != 0 )
  {
    if ( a2 )
    {
      v31 = *a2;
      v32 = a2[1];
      v33 = a2[2];
      v34 = a2[5];
    }
    else
    {
      v33 = 0;
      v31 = 0;
      v32 = 0;
      v34 = 0;
    }
    v36 = "%s: Peer %02x:%02x:%02x:**:**:%02x in deny list";
    v37 = 2;
  }
  else
  {
    v35 = *(_DWORD *)(a1 + 824);
    if ( v35 == 2 )
    {
      sap_signal_hdd_event(a1, 0, 0xBu, a2, v23, v24, v25, v26, v27, v28, v29, v30);
      if ( a2 )
      {
        v31 = *a2;
        v32 = a2[1];
        v36 = "%s: Peer %02x:%02x:%02x:**:**:%02x denied, Mac filter mode is eSAP_SUPPORT_ACCEPT_AND_DENY";
        v33 = a2[2];
        v34 = a2[5];
      }
      else
      {
        v33 = 0;
        v31 = 0;
        v32 = 0;
        v34 = 0;
        v36 = "%s: Peer %02x:%02x:%02x:**:**:%02x denied, Mac filter mode is eSAP_SUPPORT_ACCEPT_AND_DENY";
      }
    }
    else
    {
      if ( v35 != 1 )
        return 0;
      if ( a2 )
      {
        v31 = *a2;
        v32 = a2[1];
        v33 = a2[2];
        v34 = a2[5];
      }
      else
      {
        v33 = 0;
        v31 = 0;
        v32 = 0;
        v34 = 0;
      }
      v36 = "%s: Peer %02x:%02x:%02x:**:**:%02x denied, Mac filter mode is eSAP_DENY_UNLESS_ACCEPTED";
    }
    v37 = 8;
  }
  qdf_trace_msg(
    0x39u,
    v37,
    v36,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "sap_is_peer_mac_allowed",
    v31,
    v32,
    v33,
    v34,
    v10,
    v38);
  return 16;
}
