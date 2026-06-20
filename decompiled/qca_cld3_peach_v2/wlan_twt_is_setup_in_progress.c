__int64 __fastcall wlan_twt_is_setup_in_progress(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3)
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
  _BYTE *v24; // x20
  int v25; // w9
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v35; // x4
  __int64 v36; // x5
  __int64 v37; // x6
  __int64 v38; // x7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7

  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 0x5Eu);
  if ( peer_by_mac )
  {
    v14 = (__int64)peer_by_mac;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0x2Cu);
    if ( comp_private_obj )
    {
      v24 = (_BYTE *)comp_private_obj;
      qdf_mutex_acquire(comp_private_obj);
      if ( v24[65] )
      {
        v25 = (unsigned __int8)v24[72];
        if ( v25 == a3 && v25 != 255 && (v24[74] & 1) == 0 )
        {
          qdf_mutex_release((__int64)v24);
          wlan_objmgr_peer_release_ref(v14, 0x5Eu, v26, v27, v28, v29, v30, v31, v32, v33);
          return 1;
        }
        if ( v24[65] != 1 )
        {
          __break(0x5512u);
          JUMPOUT(0x7063D0);
        }
      }
      qdf_mutex_release((__int64)v24);
      wlan_objmgr_peer_release_ref(v14, 0x5Eu, v47, v48, v49, v50, v51, v52, v53, v54);
    }
    else
    {
      wlan_objmgr_peer_release_ref(v14, 0x5Eu, v16, v17, v18, v19, v20, v21, v22, v23);
      qdf_trace_msg(
        0x96u,
        2u,
        "%s: peer twt component object is NULL",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "wlan_twt_is_setup_in_progress");
    }
  }
  else
  {
    if ( a2 )
    {
      v35 = *a2;
      v36 = a2[1];
      v37 = a2[2];
      v38 = a2[5];
    }
    else
    {
      v37 = 0;
      v35 = 0;
      v36 = 0;
      v38 = 0;
    }
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: Peer object not found %02x:%02x:%02x:**:**:%02x",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_twt_is_setup_in_progress",
      v35,
      v36,
      v37,
      v38);
  }
  return 0;
}
