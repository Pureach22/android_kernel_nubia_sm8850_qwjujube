__int64 __fastcall policy_mgr_is_mlo_ap(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  unsigned int *v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v2 )
    wlan_objmgr_vdev_release_ref(v2, 0x18u, v3, v4, v5, v6, v7, v8, v9, v10, v11);
  return 0;
}
