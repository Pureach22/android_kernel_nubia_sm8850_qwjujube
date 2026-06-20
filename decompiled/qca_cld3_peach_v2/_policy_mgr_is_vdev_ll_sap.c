bool __fastcall policy_mgr_is_vdev_ll_sap(__int64 a1, unsigned int a2, int a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  double ap_policy; // d0
  int v26; // w0
  int v27; // w21
  unsigned int *v28; // x8
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w8
  bool v37; // cf

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid pm_ctx", v7, v8, v9, v10, v11, v12, v13, v14, "_policy_mgr_is_vdev_ll_sap");
    return 0;
  }
  if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(context + 8), a2) != 1 )
    return 0;
  v15 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v15 )
  {
    v24 = v15;
    ap_policy = wlan_mlme_get_ap_policy();
    v27 = v26;
    wlan_objmgr_vdev_release_ref(v24, 0x18u, v28, ap_policy, v29, v30, v31, v32, v33, v34, v35);
    v36 = v27 - 1;
    if ( a3 == 2 )
      v37 = v36 >= 3;
    else
      v37 = v36 >= 2;
    return !v37;
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: vdev %d: invalid vdev",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "_policy_mgr_is_vdev_ll_sap",
      a2);
    return 0;
  }
}
