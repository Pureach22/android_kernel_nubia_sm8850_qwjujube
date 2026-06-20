__int64 __fastcall mlme_add_twt_session(__int64 a1, unsigned __int8 *a2, char a3)
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
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 2u);
  if ( peer_by_mac )
  {
    v14 = (__int64)peer_by_mac;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0);
    if ( !comp_private_obj )
    {
      wlan_objmgr_peer_release_ref(v14, 2u, v6, v7, v8, v9, v10, v11, v12, v13);
      return qdf_trace_msg(
               0x1Fu,
               2u,
               "%s: peer mlme component object is NULL",
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               "mlme_add_twt_session");
    }
    if ( *(_BYTE *)(comp_private_obj + 41) )
    {
      if ( *(unsigned __int8 *)(comp_private_obj + 44) == 255 )
      {
        *(_BYTE *)(comp_private_obj + 44) = a3;
      }
      else if ( *(_BYTE *)(comp_private_obj + 41) != 1 )
      {
        __break(0x5512u);
        goto LABEL_7;
      }
    }
    return wlan_objmgr_peer_release_ref(v14, 2u, v6, v7, v8, v9, v10, v11, v12, v13);
  }
LABEL_7:
  if ( a2 )
  {
    v16 = *a2;
    v17 = a2[1];
    v18 = a2[2];
    v19 = a2[5];
  }
  else
  {
    v18 = 0;
    v16 = 0;
    v17 = 0;
    v19 = 0;
  }
  return qdf_trace_msg(
           0x1Fu,
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
           "mlme_add_twt_session",
           v16,
           v17,
           v18,
           v19);
}
