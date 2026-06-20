__int64 __fastcall wlan_vdev_id_is_11n_allowed(__int64 a1, char a2)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  __int64 v3; // x20
  int param; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned __int64 v13; // x8
  unsigned int v14; // w19

  if ( a1 && (vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 7u)) != nullptr )
  {
    v3 = (__int64)vdev_by_id_from_pdev;
    param = wlan_crypto_get_param((__int64)vdev_by_id_from_pdev, 1u);
    v13 = (param & 0xFFFE7FFC) != 0 || (param & 0x18003) == 0;
    if ( param == -1 )
      v14 = 1;
    else
      v14 = v13;
    wlan_objmgr_vdev_release_ref(v3, 7u, (unsigned int *)v13, v5, v6, v7, v8, v9, v10, v11, v12);
  }
  else
  {
    return 1;
  }
  return v14;
}
