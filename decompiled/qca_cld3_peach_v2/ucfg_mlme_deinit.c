__int64 ucfg_mlme_deinit()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w19

  mlme_unregister_mlo_ext_ops();
  if ( (unsigned int)wlan_objmgr_unregister_peer_destroy_handler(
                       0,
                       (__int64)mlme_peer_object_destroyed_notification,
                       v0,
                       v1,
                       v2,
                       v3,
                       v4,
                       v5,
                       v6,
                       v7) )
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: unable to unregister peer destroy handle",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "ucfg_mlme_deinit");
  result = wlan_objmgr_unregister_peer_create_handler(
             0,
             (__int64)mlme_peer_object_created_notification,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15);
  if ( (_DWORD)result )
  {
    v25 = result;
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: unable to unregister peer create handle",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ucfg_mlme_deinit");
    return v25;
  }
  return result;
}
