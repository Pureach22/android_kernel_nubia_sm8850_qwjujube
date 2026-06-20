__int64 __fastcall wlan_get_vdev_link_removed_flag_by_vdev_id(__int64 a1, __int64 a2)
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
  unsigned int v22; // w20
  __int64 ap_link_by_link_id; // x0
  __int64 v24; // x20

  v2 = a2;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( v3 )
  {
    v12 = v3;
    if ( (mlo_is_mld_sta(v3) & 1) != 0 )
    {
      v22 = *(unsigned __int8 *)(v12 + 93);
      ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(v12 + 1360), *(unsigned __int8 *)(v12 + 93));
      if ( ap_link_by_link_id )
      {
        v24 = *(_QWORD *)(ap_link_by_link_id + 16);
LABEL_8:
        wlan_objmgr_vdev_release_ref(v12, 0x43u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
        return v24 & 1;
      }
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: link info null, id %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_get_vdev_link_removed_flag",
        v22);
    }
    LOBYTE(v24) = 0;
    goto LABEL_8;
  }
  qdf_trace_msg(
    0x1Fu,
    2u,
    "%s: get vdev failed for id %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "wlan_get_vdev_link_removed_flag_by_vdev_id",
    v2);
  LOBYTE(v24) = 0;
  return v24 & 1;
}
