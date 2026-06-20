__int64 __fastcall hdd_get_tdls_connected_peer_count(__int64 a1)
{
  __int64 vdev_by_user; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x20
  unsigned int tdls_conn_peer_count; // w19
  unsigned int *v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x57u, (__int64)"hdd_get_tdls_connected_peer_count");
  if ( vdev_by_user )
  {
    v10 = vdev_by_user;
    tdls_conn_peer_count = ucfg_get_tdls_conn_peer_count(vdev_by_user, v2, v3, v4, v5, v6, v7, v8, v9);
    wlan_objmgr_vdev_release_ref(v10, 0x57u, v12, v13, v14, v15, v16, v17, v18, v19, v20);
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid vdev", v2, v3, v4, v5, v6, v7, v8, v9, "hdd_get_tdls_connected_peer_count");
    return 65514;
  }
  return tdls_conn_peer_count;
}
