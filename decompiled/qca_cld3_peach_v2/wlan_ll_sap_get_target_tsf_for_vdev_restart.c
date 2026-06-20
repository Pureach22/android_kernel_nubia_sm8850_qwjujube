__int64 __fastcall wlan_ll_sap_get_target_tsf_for_vdev_restart(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  v1 = *(_QWORD *)(a1 + 216);
  if ( !v1 )
    return 0;
  result = *(_QWORD *)(v1 + 80);
  if ( !result )
    return result;
  if ( !policy_mgr_is_vdev_ll_lt_sap(result, *(unsigned __int8 *)(a1 + 168)) )
    return 0;
  if ( !a1 )
  {
    qdf_trace_msg(0xA1u, 2u, "%s: vdev is null", v4, v5, v6, v7, v8, v9, v10, v11, "ll_sap_get_vdev_priv_obj");
    goto LABEL_11;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x34u);
  if ( !comp_private_obj )
  {
LABEL_11:
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d ll_sap obj null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_ll_sap_get_target_tsf",
      *(unsigned __int8 *)(a1 + 168));
    wlan_objmgr_vdev_release_ref(a1, 0x69u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
    return 4;
  }
  v21 = comp_private_obj;
  result = *(_QWORD *)(comp_private_obj + 16);
  if ( !result )
    return *(_QWORD *)(v21 + 24);
  return result;
}
