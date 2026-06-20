__int64 __fastcall wlan_twt_set_setup_done(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3, char a4)
{
  _QWORD *peer_by_mac; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  __int64 comp_private_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _BYTE *v26; // x22
  __int64 v27; // x0
  __int64 v28; // x1
  __int64 v29; // x2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x6
  __int64 v41; // x7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7

  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 0x5Eu);
  if ( peer_by_mac )
  {
    v16 = (__int64)peer_by_mac;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0x2Cu);
    if ( !comp_private_obj )
    {
      wlan_objmgr_peer_release_ref(v16, 0x5Eu, v18, v19, v20, v21, v22, v23, v24, v25);
      return qdf_trace_msg(
               0x96u,
               2u,
               "%s:  peer twt component object is NULL",
               v42,
               v43,
               v44,
               v45,
               v46,
               v47,
               v48,
               v49,
               "wlan_twt_set_setup_done");
    }
    v26 = (_BYTE *)comp_private_obj;
    v27 = qdf_mutex_acquire(comp_private_obj);
    if ( !v26[65] )
      goto LABEL_12;
    if ( (unsigned __int8)v26[72] == a3 )
    {
      v26[74] = a4 & 1;
      qdf_trace_msg(
        0x96u,
        8u,
        "%s: setup done:%d dialog:%d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "wlan_twt_set_setup_done",
        a4 & 1,
        a3);
LABEL_12:
      qdf_mutex_release((__int64)v26);
      return wlan_objmgr_peer_release_ref(v16, 0x5Eu, v51, v52, v53, v54, v55, v56, v57, v58);
    }
    if ( v26[65] == 1 )
      goto LABEL_12;
    __break(0x5512u);
    return wlan_twt_set_wait_for_notify(v27, v28, v29);
  }
  else
  {
    if ( a2 )
    {
      v38 = *a2;
      v39 = a2[1];
      v40 = a2[2];
      v41 = a2[5];
    }
    else
    {
      v40 = 0;
      v38 = 0;
      v39 = 0;
      v41 = 0;
    }
    return qdf_trace_msg(
             0x96u,
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
             "wlan_twt_set_setup_done",
             v38,
             v39,
             v40,
             v41);
  }
}
