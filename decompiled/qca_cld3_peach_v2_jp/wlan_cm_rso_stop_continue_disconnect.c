__int64 __fastcall wlan_cm_rso_stop_continue_disconnect(__int64 a1, __int64 a2, char a3)
{
  unsigned __int8 v4; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  unsigned int *v15; // x8
  unsigned int *v16; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x4
  __int64 v34; // x5
  unsigned int v35; // w21

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
  if ( v5 )
  {
    v14 = v5;
    v16 = (unsigned int *)_qdf_mem_malloc(0x18u, "wlan_cm_rso_stop_continue_disconnect", 604);
    if ( v16 )
    {
      if ( (cm_get_active_disconnect_req(v14, (__int64)v16, v17, v18, v19, v20, v21, v22, v23, v24) & 1) != 0 )
      {
        if ( (a3 & 1) != 0 )
        {
          v33 = *((unsigned __int8 *)v16 + 4);
          v34 = *v16;
          *((_QWORD *)v16 + 1) = 0xFFF000000008LL;
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: vdev %d cm_id 0x%x: Updating source(%d) and reason code (%d) to RSO reason and source as ho fail is rece"
            "ived in RSO stop",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "wlan_cm_rso_stop_continue_disconnect",
            v33,
            v34,
            8,
            65520);
        }
        wlan_cm_disc_cont_after_rso_stop(v14, v16);
        v35 = 0;
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev: %d: Active disconnect not found",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "wlan_cm_rso_stop_continue_disconnect",
          v4);
        v35 = 14;
      }
    }
    else
    {
      v35 = 2;
    }
    wlan_objmgr_vdev_release_ref(v14, 1u, v15, v17, v18, v19, v20, v21, v22, v23, v24);
    _qdf_mem_free((__int64)v16);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev_id: %d vdev not found",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_cm_rso_stop_continue_disconnect",
      v4);
    return 29;
  }
  return v35;
}
