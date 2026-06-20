__int64 __fastcall wlan_key_get_link_vdev(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v4; // w19
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  __int64 vdev_by_link_id; // x20

  v4 = a2;
  result = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), a2, "wlan_key_get_link_vdev");
  if ( result )
  {
    v14 = result;
    if ( (wlan_vdev_mlme_is_mlo_vdev(result, v6, v7, v8, v9, v10, v11, v12, v13) & 1) != 0 )
    {
      vdev_by_link_id = mlo_get_vdev_by_link_id(v14, a3, v4);
      _hdd_objmgr_put_vdev_by_user(v14, v4, "wlan_key_get_link_vdev");
      return vdev_by_link_id;
    }
    else
    {
      return v14;
    }
  }
  return result;
}
