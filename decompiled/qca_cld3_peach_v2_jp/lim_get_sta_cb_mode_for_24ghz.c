__int64 __fastcall lim_get_sta_cb_mode_for_24ghz(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  unsigned int *v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v2 = *(_DWORD *)(a1 + 17120);
  v3 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)(a1 + 21552),
         a2,
         1);
  if ( v3 )
  {
    v12 = v3;
    if ( (wlan_cm_get_force_20mhz_in_24ghz(v3, v4, v5, v6, v7, v8, v9, v10, v11) & 1) != 0 )
      v2 = 0;
    wlan_objmgr_vdev_release_ref(v12, 1u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
  }
  return v2;
}
