__int64 __fastcall mlme_set_twt_session_state(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3, unsigned int a4)
{
  unsigned __int8 *v6; // x22
  _QWORD *peer_by_mac; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  __int64 comp_private_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  v6 = a2;
  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 2u);
  if ( peer_by_mac )
  {
    v16 = (__int64)peer_by_mac;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0);
    if ( !comp_private_obj )
    {
      wlan_objmgr_peer_release_ref(v16, 2u, v18, v19, v20, v21, v22, v23, v24, v25);
      return qdf_trace_msg(
               0x68u,
               2u,
               "%s:  peer mlme component object is NULL",
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               "mlme_set_twt_session_state");
    }
    v6 = (unsigned __int8 *)comp_private_obj;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: set_state:%d for dialog_id:%d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "mlme_set_twt_session_state",
      a4,
      a3);
    if ( v6[41] )
    {
      if ( a3 == 255 || v6[44] == a3 )
      {
        v6[45] = a4;
      }
      else if ( v6[41] != 1 )
      {
        __break(0x5512u);
        goto LABEL_8;
      }
    }
    return wlan_objmgr_peer_release_ref(v16, 2u, v8, v9, v10, v11, v12, v13, v14, v15);
  }
LABEL_8:
  if ( v6 )
  {
    v26 = *v6;
    v27 = v6[1];
    v28 = v6[2];
    v29 = v6[5];
  }
  else
  {
    v28 = 0;
    v26 = 0;
    v27 = 0;
    v29 = 0;
  }
  return qdf_trace_msg(
           0x1Fu,
           2u,
           "%s: Peer object not found %02x:%02x:%02x:**:**:%02x",
           v8,
           v9,
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           "mlme_set_twt_session_state",
           v26,
           v27,
           v28,
           v29);
}
