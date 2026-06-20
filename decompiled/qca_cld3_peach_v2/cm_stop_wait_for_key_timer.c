__int64 __fastcall cm_stop_wait_for_key_timer(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w20
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 cmpt_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  v2 = a2;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( !v4 )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev is NULL for vdev id %d",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "cm_stop_wait_for_key_timer",
             v2);
  v13 = v4;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v4, v5, v6, v7, v8, v9, v10, v11, v12);
  if ( cmpt_obj )
  {
    v23 = cmpt_obj;
    if ( mlme_get_psoc_ext_obj_fl(a1) )
      qdf_mc_timer_stop(*(_QWORD *)(v23 + 536) + 24280LL);
    else
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: psoc mlme obj is NULL for vdev id %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "cm_stop_wait_for_key_timer",
        v2);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev priv mlme obj is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "cm_stop_wait_for_key_timer");
  }
  return wlan_objmgr_vdev_release_ref(v13, 0x4Du, v32, v33, v34, v35, v36, v37, v38, v39, v40);
}
