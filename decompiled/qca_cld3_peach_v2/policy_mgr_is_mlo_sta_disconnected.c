__int64 __fastcall policy_mgr_is_mlo_sta_disconnected(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x20
  double v4; // d0
  char v5; // w0
  char v6; // w19
  unsigned int *v7; // x8
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v2 )
  {
    v3 = v2;
    v4 = ucfg_mlo_is_mld_disconnected();
    v6 = v5;
    wlan_objmgr_vdev_release_ref(v3, 0x18u, v7, v4, v8, v9, v10, v11, v12, v13, v14);
  }
  else
  {
    v6 = 1;
  }
  return v6 & 1;
}
