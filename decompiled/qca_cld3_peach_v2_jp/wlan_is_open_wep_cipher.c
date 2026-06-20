bool __fastcall wlan_is_open_wep_cipher(__int64 a1, unsigned __int8 a2)
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
  _BOOL4 v13; // w19

  if ( a1 && (vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 7u)) != nullptr )
  {
    v3 = (__int64)vdev_by_id_from_pdev;
    param = wlan_crypto_get_param((__int64)vdev_by_id_from_pdev, 1u);
    v13 = (param & 0x18001) != 0 || (param & 0xFFFDFFFF) == 0;
    wlan_objmgr_vdev_release_ref(v3, 7u, dword_18001, v5, v6, v7, v8, v9, v10, v11, v12);
  }
  else
  {
    return 0;
  }
  return v13;
}
