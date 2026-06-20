__int64 __fastcall policy_mgr_move_vdev_from_disabled_to_connection_tbl(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  unsigned int opmode_from_vdev_id; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x22
  char is_mlo_vdev; // w23
  unsigned int *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  char *v60; // x8
  const char *v61; // x2
  __int64 v62; // x4
  unsigned int v63; // w1

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid pm_ctx",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "policy_mgr_move_vdev_from_disabled_to_connection_tbl");
  v13 = context;
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(context + 8), a2);
  if ( opmode_from_vdev_id )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: vdev %d opmode %d is not STA",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "policy_mgr_move_vdev_from_disabled_to_connection_tbl",
             (unsigned __int8)a2,
             opmode_from_vdev_id);
  v24 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( !v24
    || (v33 = v24,
        is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v24, v25, v26, v27, v28, v29, v30, v31, v32),
        wlan_objmgr_vdev_release_ref(v33, 0x18u, v35, v36, v37, v38, v39, v40, v41, v42, v43),
        (is_mlo_vdev & 1) == 0) )
  {
    if ( (wlan_cm_is_roam_sync_in_progress(a1, a2) & 1) == 0 )
    {
      v61 = "%s: vdev %d is not ML";
      v62 = (unsigned __int8)a2;
      v63 = 2;
      return qdf_trace_msg(
               0x4Fu,
               v63,
               v61,
               v44,
               v45,
               v46,
               v47,
               v48,
               v49,
               v50,
               v51,
               "policy_mgr_move_vdev_from_disabled_to_connection_tbl",
               v62);
    }
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: vdev %d is not ML in roam sync",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "policy_mgr_move_vdev_from_disabled_to_connection_tbl",
      (unsigned __int8)a2);
  }
  qdf_mutex_acquire(v13 + 56);
  v60 = &pm_disabled_ml_links;
  if ( pm_disabled_ml_links == 1 && (unsigned __int8)byte_8D4FCC == (unsigned __int8)a2
    || (v60 = &byte_8D4FD0, byte_8D4FD0 == 1) && (unsigned __int8)byte_8D4FDC == (unsigned __int8)a2 )
  {
    *v60 = 0;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Disabled link removed for vdev %d",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "policy_mgr_delete_from_disabled_links",
      (unsigned __int8)a2);
    qdf_mutex_release(v13 + 56);
    return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))policy_mgr_incr_active_session)(a1, 0, a2, 0);
  }
  qdf_mutex_release(v13 + 56);
  v61 = "%s: Disabled link not found for vdev %d";
  v62 = (unsigned __int8)a2;
  v63 = 8;
  return qdf_trace_msg(
           0x4Fu,
           v63,
           v61,
           v44,
           v45,
           v46,
           v47,
           v48,
           v49,
           v50,
           v51,
           "policy_mgr_move_vdev_from_disabled_to_connection_tbl",
           v62);
}
