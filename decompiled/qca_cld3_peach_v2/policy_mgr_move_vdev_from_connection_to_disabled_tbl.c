__int64 __fastcall policy_mgr_move_vdev_from_connection_to_disabled_tbl(__int64 a1, unsigned int a2)
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
  unsigned int operation_chan_freq_vdev_id; // w22
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x9
  char *v62; // x9
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7

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
             "policy_mgr_move_vdev_from_connection_to_disabled_tbl");
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
             "policy_mgr_move_vdev_from_connection_to_disabled_tbl",
             (unsigned __int8)a2,
             opmode_from_vdev_id);
  v24 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( !v24 )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: vdev %d is not ML",
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             "policy_mgr_move_vdev_from_connection_to_disabled_tbl",
             (unsigned __int8)a2);
  v33 = v24;
  is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v24, v25, v26, v27, v28, v29, v30, v31, v32);
  wlan_objmgr_vdev_release_ref(v33, 0x18u, v35, v36, v37, v38, v39, v40, v41, v42, v43);
  if ( (is_mlo_vdev & 1) == 0 )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: vdev %d is not ML",
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             "policy_mgr_move_vdev_from_connection_to_disabled_tbl",
             (unsigned __int8)a2);
  operation_chan_freq_vdev_id = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(v13 + 8), a2);
  if ( (unsigned int)policy_mgr_check_conn_with_mode_and_vdev_id(a1, 0, (unsigned __int8)a2) )
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Connection tbl dont have vdev %d in STA mode, Add it in disabled tbl",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "policy_mgr_move_vdev_from_connection_to_disabled_tbl",
      (unsigned __int8)a2);
  else
    policy_mgr_decr_session_set_pcl(a1, 0, a2);
  qdf_mutex_acquire(v13 + 56);
  if ( pm_disabled_ml_links[0] != 1 )
  {
    if ( byte_8D4FD0 == 1 )
    {
      v62 = pm_disabled_ml_links;
      if ( (unsigned __int8)byte_8D4FDC == (unsigned __int8)a2 )
      {
LABEL_16:
        v61 = 1;
        goto LABEL_17;
      }
    }
    else
    {
      v62 = pm_disabled_ml_links;
    }
LABEL_22:
    v62[12] = a2;
    *v62 = 1;
    *((_DWORD *)v62 + 1) = 0;
    *((_DWORD *)v62 + 2) = operation_chan_freq_vdev_id;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Disabled link added vdev id: %d freq: %d pm_mode %d",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "policy_mgr_add_to_disabled_links",
      (unsigned __int8)a2,
      operation_chan_freq_vdev_id,
      0);
    qdf_mutex_release(v13 + 56);
    return policy_mgr_dump_current_concurrency(a1);
  }
  if ( (unsigned __int8)byte_8D4FCC != (unsigned __int8)a2 )
  {
    v62 = &byte_8D4FD0;
    if ( (byte_8D4FD0 & 1) != 0 )
    {
      if ( (unsigned __int8)byte_8D4FDC != (unsigned __int8)a2 )
      {
        qdf_mutex_release(v13 + 56);
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: No empty entry found to disable link for vdev %d",
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          "policy_mgr_add_to_disabled_links",
          (unsigned __int8)a2);
        return policy_mgr_dump_current_concurrency(a1);
      }
      goto LABEL_16;
    }
    goto LABEL_22;
  }
  v61 = 0;
LABEL_17:
  *(_DWORD *)&pm_disabled_ml_links[16 * v61 + 8] = operation_chan_freq_vdev_id;
  qdf_mutex_release(v13 + 56);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: Disabled link already present vdev %d, pm_mode %d, update freq %d",
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    "policy_mgr_add_to_disabled_links",
    (unsigned __int8)a2,
    0,
    operation_chan_freq_vdev_id);
  return policy_mgr_dump_current_concurrency(a1);
}
