__int64 __fastcall vdevmgr_mlme_ext_hdl_create(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  __int64 v36; // x9
  __int64 v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w4
  char v47; // w8
  __int64 result; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w20
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7

  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: vdev id = %d ",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "vdevmgr_mlme_ext_hdl_create",
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL));
  v10 = _qdf_mem_malloc(0x61D8u, "vdevmgr_mlme_ext_hdl_create", 1712);
  *(_QWORD *)(a1 + 520) = v10;
  if ( !v10 )
    return 2;
  mlme_init_rate_config(a1, v11, v12, v13, v14, v15, v16, v17, v18);
  mlme_init_connect_chan_info_config(a1, v19, v20, v21, v22, v23, v24, v25, v26);
  mlme_cm_alloc_roam_stats_info(a1);
  v35 = "%s: vdev or wait for key is NULL";
  *(_QWORD *)(*(_QWORD *)(a1 + 520) + 24080LL) = 0;
  v36 = *(_QWORD *)(a1 + 504);
  if ( v36 )
  {
    v37 = *(_QWORD *)(a1 + 520);
    if ( v37 != -24272 )
    {
      *(_QWORD *)(v37 + 24272) = v36;
      if ( !(unsigned int)qdf_mc_timer_init(v37 + 24280, 0, (__int64)cm_wait_for_key_time_out_handler, v37 + 24272) )
        goto LABEL_7;
      v35 = "%s: cannot allocate memory for WaitForKey time out timer";
    }
  }
  qdf_trace_msg(0x68u, 2u, v35, v27, v28, v29, v30, v31, v32, v33, v34, "mlme_init_wait_for_key_timer");
LABEL_7:
  _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)(a1 + 520) + 24600LL), (__int64)"bss_color_change_wakelock");
  _qdf_runtime_lock_init(
    (__int64 *)(*(_QWORD *)(a1 + 520) + 24800LL),
    "&vdev_mlme->ext_vdev_ptr->bss_color_change_runtime_lock");
  _qdf_runtime_lock_init(
    (__int64 *)(*(_QWORD *)(a1 + 520) + 24808LL),
    "&vdev_mlme->ext_vdev_ptr->disconnect_runtime_lock");
  sme_get_vdev_type_nss(*(unsigned int *)(*(_QWORD *)(a1 + 504) + 16LL), a1 + 24, a1 + 25);
  v46 = *(_DWORD *)(*(_QWORD *)(a1 + 504) + 16LL);
  *(_WORD *)(a1 + 163) = 0;
  if ( v46 > 5 )
  {
    if ( v46 <= 7 )
    {
      if ( v46 != 6 )
      {
        *(_WORD *)(a1 + 163) = 257;
        goto LABEL_31;
      }
      v47 = 4;
      goto LABEL_30;
    }
    switch ( v46 )
    {
      case 8:
        v47 = 6;
        goto LABEL_30;
      case 11:
        v47 = 7;
        goto LABEL_30;
      case 16:
        v47 = 5;
        goto LABEL_30;
    }
LABEL_34:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Invalid device mode %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "mlme_get_vdev_types");
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Get vdev type failed; status:%d",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "vdevmgr_mlme_ext_hdl_create",
      4);
    mlme_ext_handler_destroy(a1);
    return 4;
  }
  if ( v46 <= 1 )
  {
    if ( !v46 )
    {
      v47 = 2;
      goto LABEL_30;
    }
    if ( v46 == 1 )
    {
      v47 = 1;
      goto LABEL_30;
    }
    goto LABEL_34;
  }
  if ( v46 == 2 )
  {
    *(_WORD *)(a1 + 163) = 514;
    goto LABEL_31;
  }
  if ( v46 == 3 )
  {
    *(_WORD *)(a1 + 163) = 769;
    goto LABEL_31;
  }
  if ( v46 != 5 )
    goto LABEL_34;
  v47 = 3;
LABEL_30:
  *(_BYTE *)(a1 + 163) = v47;
LABEL_31:
  *(_DWORD *)(*(_QWORD *)(a1 + 520) + 25040LL) = 0;
  _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)(a1 + 520) + 24832LL), (__int64)"peer_set_key");
  _qdf_runtime_lock_init(
    (__int64 *)(*(_QWORD *)(a1 + 520) + 25032LL),
    "&vdev_mlme->ext_vdev_ptr->peer_set_key_rt_wakelock");
  result = vdev_mgr_create_send(a1, v49, v50, v51, v52, v53, v54, v55, v56);
  if ( (_DWORD)result )
  {
    v65 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to create vdev for vdev id %d",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "vdevmgr_mlme_ext_hdl_create",
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL));
    vdevmgr_mlme_ext_hdl_destroy(a1);
    return v65;
  }
  return result;
}
