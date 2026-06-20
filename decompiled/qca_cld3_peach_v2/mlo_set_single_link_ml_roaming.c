__int64 __fastcall mlo_set_single_link_ml_roaming(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int *v13; // x8
  char v14; // w1
  __int64 v15; // x19

  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
  if ( !v4 )
    return qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: VDEV is null",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "mlo_set_single_link_ml_roaming");
  v13 = (unsigned int *)*(unsigned __int8 *)(v4 + 60);
  if ( ((unsigned __int8)v13 & 2) == 0 )
  {
    v14 = a3 & 1;
    v15 = v4;
    mlme_set_single_link_mlo_roaming(v4, v14, v5, v6, v7, v8, v9, v10, v11, v12);
    v4 = v15;
  }
  return wlan_objmgr_vdev_release_ref(v4, 1u, v13, v5, v6, v7, v8, v9, v10, v11, v12);
}
