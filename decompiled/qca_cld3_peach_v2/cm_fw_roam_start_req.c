__int64 __fastcall cm_fw_roam_start_req(__int64 a1, __int64 a2)
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
  __int64 v11; // x19
  unsigned int *v12; // x8
  unsigned int v13; // w20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
  if ( v2 )
  {
    v11 = v2;
    v13 = cm_sm_deliver_event(v2, 0x11u, 0, 0, v3, v4, v5, v6, v7, v8, v9, v10);
    if ( v13 )
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: EV ROAM START not handled",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "cm_fw_roam_start_req");
    wlan_objmgr_vdev_release_ref(v11, 1u, v12, v14, v15, v16, v17, v18, v19, v20, v21);
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev object is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "cm_fw_roam_start_req");
    return 29;
  }
  return v13;
}
