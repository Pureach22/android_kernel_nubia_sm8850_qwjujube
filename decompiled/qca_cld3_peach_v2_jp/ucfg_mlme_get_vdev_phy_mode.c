__int64 __fastcall ucfg_mlme_get_vdev_phy_mode(__int64 a1, __int64 a2)
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
  __int64 cmpt_obj; // x0
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w20

  v2 = a2;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( v3 )
  {
    v12 = v3;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v3, v4, v5, v6, v7, v8, v9, v10, v11);
    if ( cmpt_obj )
    {
      v23 = *(_DWORD *)(cmpt_obj + 176);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: failed to get mlme_obj vdev_id: %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "ucfg_mlme_get_vdev_phy_mode",
        v2);
      v23 = 0;
    }
    wlan_objmgr_vdev_release_ref(v12, 0x43u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: get vdev failed for vdev_id: %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "ucfg_mlme_get_vdev_phy_mode",
      v2);
    return 0;
  }
  return v23;
}
