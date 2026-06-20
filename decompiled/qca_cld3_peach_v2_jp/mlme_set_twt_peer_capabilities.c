__int64 __fastcall mlme_set_twt_peer_capabilities(__int64 a1, unsigned __int8 *a2, char a3)
{
  _QWORD *peer_by_mac; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  __int64 v28; // x7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 2u);
  if ( peer_by_mac )
  {
    v14 = (__int64)peer_by_mac;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0);
    if ( comp_private_obj )
    {
      *(_BYTE *)(comp_private_obj + 40) = a3;
      return wlan_objmgr_peer_release_ref(v14, 2u, v16, v17, v18, v19, v20, v21, v22, v23);
    }
    else
    {
      wlan_objmgr_peer_release_ref(v14, 2u, v16, v17, v18, v19, v20, v21, v22, v23);
      return qdf_trace_msg(
               0x1Fu,
               8u,
               "%s: peer mlme object is NULL",
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               "mlme_set_twt_peer_capabilities");
    }
  }
  else
  {
    if ( a2 )
    {
      v25 = *a2;
      v26 = a2[1];
      v27 = a2[2];
      v28 = a2[5];
    }
    else
    {
      v27 = 0;
      v25 = 0;
      v26 = 0;
      v28 = 0;
    }
    return qdf_trace_msg(
             0x1Fu,
             8u,
             "%s: Peer object not found %02x:%02x:%02x:**:**:%02x",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "mlme_set_twt_peer_capabilities",
             v25,
             v26,
             v27,
             v28);
  }
}
