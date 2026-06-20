__int64 __fastcall mlme_get_twt_peer_capabilities(__int64 a1, unsigned __int8 *a2)
{
  _QWORD *peer_by_mac; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  __int64 comp_private_obj; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7

  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 2u);
  if ( peer_by_mac )
  {
    v12 = (__int64)peer_by_mac;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0);
    wlan_objmgr_peer_release_ref(v12, 2u, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( comp_private_obj )
      return *(unsigned __int8 *)(comp_private_obj + 40);
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: peer mlme object is NULL",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "mlme_get_twt_peer_capabilities");
  }
  else
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
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: Peer object not found %02x:%02x:%02x:**:**:%02x",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlme_get_twt_peer_capabilities",
      v31,
      v32,
      v33,
      v34);
  }
  return 0;
}
