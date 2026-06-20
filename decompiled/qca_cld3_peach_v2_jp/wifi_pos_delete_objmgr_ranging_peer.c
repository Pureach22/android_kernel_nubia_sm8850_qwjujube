void __fastcall wifi_pos_delete_objmgr_ranging_peer(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 vdev_priv_obj; // x0
  unsigned __int8 v21; // w9
  __int64 v22; // x4
  const char *v23; // x2
  const char *v24; // x3

  if ( !a10 )
  {
    v23 = "%s: Peer is NULL";
LABEL_12:
    v24 = "wifi_pos_delete_objmgr_ranging_peer";
LABEL_13:
    qdf_trace_msg(0x25u, 2u, v23, a1, a2, a3, a4, a5, a6, a7, a8, v24);
    return;
  }
  if ( *(_DWORD *)(a10 + 68) != 12 )
    return;
  if ( !a11 )
  {
    v23 = "%s: VDEV is NULL";
    goto LABEL_12;
  }
  if ( *(unsigned __int8 *)(a11 + 104) != *(unsigned __int8 *)(*(_QWORD *)(a10 + 88) + 104LL) )
    return;
  if ( (unsigned int)wlan_objmgr_peer_obj_delete(a10, a1, a2, a3, a4, a5, a6, a7, a8) )
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Failed to delete peer",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wifi_pos_delete_objmgr_ranging_peer");
  vdev_priv_obj = wifi_pos_get_vdev_priv_obj(a11);
  if ( !vdev_priv_obj )
  {
    v23 = "%s: Wifi pos vdev priv obj is null";
    v24 = "wifi_pos_update_pasn_peer_count";
    goto LABEL_13;
  }
  if ( *(_BYTE *)(vdev_priv_obj + 12264) )
  {
    v21 = *(_BYTE *)(vdev_priv_obj + 12264) - 1;
    *(_BYTE *)(vdev_priv_obj + 12264) = v21;
    v22 = v21;
  }
  else
  {
    v22 = 0;
  }
  qdf_trace_msg(
    0x25u,
    8u,
    "%s: Pasn peer count:%d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "wifi_pos_update_pasn_peer_count",
    v22);
}
