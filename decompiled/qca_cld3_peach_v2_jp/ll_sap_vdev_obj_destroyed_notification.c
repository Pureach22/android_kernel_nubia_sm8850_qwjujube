__int64 __fastcall ll_sap_vdev_obj_destroyed_notification(__int64 a1)
{
  __int64 v1; // x29
  __int64 v2; // x30
  __int64 v3; // x8
  __int64 v5; // x0
  __int64 comp_private_obj; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  unsigned int v35; // w21
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // [xsp+0h] [xbp-30h]
  __int64 v45; // [xsp+8h] [xbp-28h]

  if ( *(_DWORD *)(a1 + 16) != 1 )
    return 0;
  v44 = v1;
  v45 = v2;
  v3 = *(_QWORD *)(a1 + 152);
  if ( v3 )
    v5 = *(_QWORD *)(v3 + 80);
  else
    v5 = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v5, 0x34u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: psoc_ll_sap_obj is null",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "ll_sap_vdev_obj_destroyed_notification",
      v1,
      v45);
    return 4;
  }
  if ( *(unsigned __int8 *)(comp_private_obj + 208) == *(unsigned __int8 *)(a1 + 104) )
  {
    v16 = comp_private_obj;
    if ( (unsigned int)qdf_mc_timer_get_current_state(comp_private_obj + 40) == 21 )
      qdf_mc_timer_stop(v16 + 40);
  }
  ll_lt_sap_deinit(a1, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( !a1 )
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev is null",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ll_sap_get_vdev_priv_obj",
      v1,
      v45);
    goto LABEL_17;
  }
  v25 = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x34u);
  if ( !v25 )
  {
LABEL_17:
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d ll sap obj null",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "ll_sap_vdev_obj_destroyed_notification",
      *(unsigned __int8 *)(a1 + 104),
      v44,
      v45);
    return 4;
  }
  v34 = v25;
  v35 = wlan_objmgr_vdev_component_obj_detach(a1, 0x34u, v25);
  if ( v35 )
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d ll sap obj detach failed, status %d",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "ll_sap_vdev_obj_destroyed_notification",
      *(unsigned __int8 *)(a1 + 104),
      v35,
      v1,
      v45);
  _qdf_mem_free(v34);
  return v35;
}
