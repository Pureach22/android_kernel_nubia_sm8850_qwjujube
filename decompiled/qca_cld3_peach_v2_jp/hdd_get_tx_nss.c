__int64 __fastcall hdd_get_tx_nss(__int64 a1, _BYTE *a2)
{
  __int64 *v4; // x21
  __int64 vdev_by_user; // x0
  __int64 v6; // x19
  unsigned int sta_tx_nss; // w20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  if ( (*(_DWORD *)(*(_QWORD *)a1 + 40LL) | 2) == 3 )
    return hdd_get_sap_tx_nss(a1, a2);
  v4 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_get_sta_tx_nss");
  if ( !vdev_by_user )
    return 4;
  v6 = vdev_by_user;
  sta_tx_nss = wlan_mlme_get_sta_tx_nss(*v4, vdev_by_user, a2);
  if ( sta_tx_nss )
    qdf_trace_msg(0x33u, 2u, "%s: Failed to get sta_tx_nss", v8, v9, v10, v11, v12, v13, v14, v15, "hdd_get_sta_tx_nss");
  _hdd_objmgr_put_vdev_by_user(v6, 6, "hdd_get_sta_tx_nss");
  return sta_tx_nss;
}
