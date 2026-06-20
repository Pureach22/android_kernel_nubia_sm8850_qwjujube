__int64 __fastcall hdd_send_dscp_up_map_to_fw(__int64 a1)
{
  __int64 vdev_by_user; // x0
  unsigned int *v2; // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52824), 0x46u, (__int64)"hdd_send_dscp_up_map_to_fw");
  if ( vdev_by_user )
    _hdd_objmgr_put_vdev_by_user(
      vdev_by_user,
      0x46u,
      (__int64)"hdd_send_dscp_up_map_to_fw",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10);
  return 0;
}
