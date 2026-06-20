__int64 __fastcall wlan_twt_set_peer_capabilities(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3)
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
  __int64 v14; // x19
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v42; // x4
  __int64 v43; // x5
  __int64 v44; // x6
  __int64 v45; // x7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7

  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 0x5Eu);
  if ( peer_by_mac )
  {
    v14 = (__int64)peer_by_mac;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0x2Cu);
    if ( comp_private_obj )
    {
      v24 = comp_private_obj;
      qdf_mutex_acquire(comp_private_obj);
      *(_BYTE *)(v24 + 64) = a3;
      qdf_mutex_release(v24);
      qdf_trace_msg(
        0x96u,
        8u,
        "%s: set peer cap: 0x%x",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "wlan_twt_set_peer_capabilities",
        a3);
      wlan_objmgr_peer_release_ref(v14, 0x5Eu, v33, v34, v35, v36, v37, v38, v39, v40);
      return 0;
    }
    wlan_objmgr_peer_release_ref(v14, 0x5Eu, v16, v17, v18, v19, v20, v21, v22, v23);
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: peer twt component object is NULL",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "wlan_twt_set_peer_capabilities");
  }
  else
  {
    if ( a2 )
    {
      v42 = *a2;
      v43 = a2[1];
      v44 = a2[2];
      v45 = a2[5];
    }
    else
    {
      v44 = 0;
      v42 = 0;
      v43 = 0;
      v45 = 0;
    }
    qdf_trace_msg(
      0x96u,
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
      "wlan_twt_set_peer_capabilities",
      v42,
      v43,
      v44,
      v45);
  }
  return 16;
}
