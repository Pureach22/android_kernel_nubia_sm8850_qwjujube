__int64 __fastcall hdd_hostapd_sap_fill_peer_ml_info(__int64 a1, __int64 a2)
{
  __int64 vdev_by_user; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 5, "hdd_hostapd_sap_fill_peer_ml_info");
  if ( !vdev_by_user )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Failed to get link id, VDEV NULL",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "hdd_hostapd_sap_fill_peer_ml_info");
  *(_BYTE *)(a2 + 226) = -1;
  return _hdd_objmgr_put_vdev_by_user(vdev_by_user, 5, "hdd_hostapd_sap_fill_peer_ml_info");
}
