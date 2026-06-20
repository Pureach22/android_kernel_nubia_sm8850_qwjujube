bool __fastcall wlan_vdev_mlme_get_is_mlo_vdev(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w20
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  unsigned int *v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _BOOL4 v22; // w20

  v2 = a2;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( v3 )
  {
    v12 = v3;
    if ( (wlan_vdev_mlme_is_mlo_vdev(v3, v4, v5, v6, v7, v8, v9, v10, v11) & 1) != 0 )
    {
      v13 = (unsigned int *)*(unsigned __int8 *)(v12 + 60);
      v22 = ((unsigned __int8)v13 & 2) == 0;
    }
    else
    {
      v22 = 0;
    }
    wlan_objmgr_vdev_release_ref(v12, 0x43u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL for vdev %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_vdev_mlme_get_is_mlo_vdev",
      v2);
    return 0;
  }
  return v22;
}
