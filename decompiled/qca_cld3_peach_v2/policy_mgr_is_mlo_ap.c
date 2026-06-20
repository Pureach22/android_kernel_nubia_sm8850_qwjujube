__int64 __fastcall policy_mgr_is_mlo_ap(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int *v11; // x8
  __int64 v12; // x20
  char is_mlo_vdev; // w19

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v2 )
  {
    v11 = (unsigned int *)*(unsigned int *)(v2 + 16);
    if ( (_DWORD)v11 == 1 )
    {
      v12 = v2;
      is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v2, v3, v4, v5, v6, v7, v8, v9, v10);
      v2 = v12;
    }
    else
    {
      is_mlo_vdev = 0;
    }
    wlan_objmgr_vdev_release_ref(v2, 0x18u, v11, v3, v4, v5, v6, v7, v8, v9, v10);
  }
  else
  {
    is_mlo_vdev = 0;
  }
  return is_mlo_vdev & 1;
}
