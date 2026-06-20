__int64 __fastcall wlan_mlme_get_bssid_vdev_id(__int64 a1, char a2, void *a3)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  unsigned int bss_peer_mac; // w19
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  if ( !a1 )
    return 4;
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 7u);
  if ( !vdev_by_id_from_pdev )
    return 4;
  v13 = (__int64)vdev_by_id_from_pdev;
  bss_peer_mac = wlan_vdev_get_bss_peer_mac((__int64)vdev_by_id_from_pdev, a3, v5, v6, v7, v8, v9, v10, v11, v12);
  wlan_objmgr_vdev_release_ref(v13, 7u, v15, v16, v17, v18, v19, v20, v21, v22, v23);
  return bss_peer_mac;
}
