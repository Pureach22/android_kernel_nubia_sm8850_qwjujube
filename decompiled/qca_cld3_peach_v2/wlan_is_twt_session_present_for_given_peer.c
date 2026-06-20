bool __fastcall wlan_is_twt_session_present_for_given_peer(__int64 a1, unsigned __int8 *a2)
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
  __int64 v12; // x19
  __int64 comp_private_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _BOOL4 v22; // w20
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7

  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 0x5Eu);
  if ( peer_by_mac )
  {
    v12 = (__int64)peer_by_mac;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0x2Cu);
    if ( comp_private_obj )
    {
      v22 = *(_BYTE *)(comp_private_obj + 65) != 0;
    }
    else
    {
      qdf_trace_msg(
        0x96u,
        2u,
        "%s:  peer twt component object is NULL",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_is_twt_session_present_for_given_peer");
      v22 = 0;
    }
    wlan_objmgr_peer_release_ref(v12, 0x5Eu, v14, v15, v16, v17, v18, v19, v20, v21);
  }
  else
  {
    if ( a2 )
    {
      v23 = *a2;
      v24 = a2[1];
      v25 = a2[2];
      v26 = a2[5];
    }
    else
    {
      v25 = 0;
      v23 = 0;
      v24 = 0;
      v26 = 0;
    }
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: peer is null for %02x:%02x:%02x:**:**:%02x",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_is_twt_session_present_for_given_peer",
      v23,
      v24,
      v25,
      v26);
    return 0;
  }
  return v22;
}
