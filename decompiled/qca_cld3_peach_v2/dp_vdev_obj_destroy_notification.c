__int64 __fastcall dp_vdev_obj_destroy_notification(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 comp_private_obj; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 *v27; // x21
  __int64 v28; // x19
  __int64 v29; // x25
  unsigned __int64 StatusReg; // x8
  __int64 v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned __int64 v49; // x8
  __int64 v50; // x8
  __int64 v51; // x1
  unsigned int v52; // w22
  __int64 v53; // x28
  unsigned __int64 v54; // x8
  __int64 v55; // x8
  unsigned int v56; // w0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  const char *v65; // x2
  unsigned __int64 v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x5
  __int64 v76; // x6
  __int64 v77; // x7
  __int64 *v78; // x9
  __int64 v79; // x8
  __int64 v80; // x8
  unsigned int v81; // w19

  qdf_trace_msg(
    0x45u,
    5u,
    "%s: DP VDEV OBJ destroy notification, vdev_id %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_vdev_obj_destroy_notification",
    *(unsigned __int8 *)(a1 + 168));
  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", v10, v11, v12, v13, v14, v15, v16, v17, "dp_get_vdev_priv_obj");
    goto LABEL_16;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
LABEL_16:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to get DP link obj",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "dp_vdev_obj_destroy_notification");
    return 4;
  }
  v27 = *(__int64 **)(comp_private_obj + 32);
  v28 = comp_private_obj;
  v29 = *v27;
  wlan_dp_resource_mgr_notify_vdev_deletion(*(_QWORD *)(*v27 + 3000), a1);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v27 + 459);
  }
  else
  {
    raw_spin_lock_bh(v27 + 459);
    v27[460] |= 1uLL;
  }
  qdf_list_remove_node((__int64)(v27 + 461), (_QWORD *)v28);
  v31 = v27[460];
  --*((_BYTE *)v27 + 3661);
  if ( (v31 & 1) != 0 )
  {
    v27[460] = v31 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v27 + 459);
  }
  else
  {
    raw_spin_unlock(v27 + 459);
  }
  if ( (*((_DWORD *)v27 + 7) | 2) == 3 )
    *(_DWORD *)(v28 + 80) |= 1u;
  if ( !*((_BYTE *)v27 + 3661) )
  {
    wlan_dp_spm_intf_ctx_deinit(v27);
    dp_fim_deinit(v27);
    dp_fpm_deinit(v27);
    dp_telemetry_deinit(v27);
    dp_nud_ignore_tracking(v27, 1);
    dp_nud_reset_tracking(v27);
    dp_nud_flush_work(v27);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Flush the MIC error work",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "dp_mic_flush_work");
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v49 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v49 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v49 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v27 + 433);
    }
    else
    {
      raw_spin_lock_bh(v27 + 433);
      v27[434] |= 1uLL;
    }
    if ( *((_DWORD *)v27 + 862) == 2 )
    {
      v50 = v27[434];
      *((_DWORD *)v27 + 862) = 3;
      if ( (v50 & 1) != 0 )
      {
        v27[434] = v50 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v27 + 433);
      }
      else
      {
        raw_spin_unlock(v27 + 433);
      }
      flush_work(v27 + 425);
    }
    else
    {
      v80 = v27[434];
      if ( (v80 & 1) != 0 )
      {
        v27[434] = v80 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v27 + 433);
      }
      else
      {
        raw_spin_unlock(v27 + 433);
      }
    }
    if ( (*((_DWORD *)v27 + 7) | 2) == 3 )
    {
      v56 = qdf_event_destroy((__int64)(v27 + 452), v51);
      if ( v56 )
      {
        v65 = "%s: eap frm done event destroy failed!!";
        goto LABEL_52;
      }
      v27[8] = 0;
      *((_BYTE *)v27 + 3580) = 1;
    }
  }
  qdf_mem_set((void *)(v28 + 64), 0xEu, 0);
  if ( v27[458] == v28 )
  {
    v27[458] = dp_intf_get_next_deflink_candidate(v27, v28);
    if ( !*((_DWORD *)v27 + 894) )
    {
LABEL_31:
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v54 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v54 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v54 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v28 + 48);
        v55 = *(_QWORD *)(v28 + 56);
        *(_QWORD *)(v28 + 40) = 0;
        if ( (v55 & 1) == 0 )
        {
LABEL_35:
          raw_spin_unlock(v28 + 48);
          goto LABEL_36;
        }
      }
      else
      {
        raw_spin_lock_bh(v28 + 48);
        v55 = *(_QWORD *)(v28 + 56) | 1LL;
        *(_QWORD *)(v28 + 56) = v55;
        *(_QWORD *)(v28 + 40) = 0;
        if ( (v55 & 1) == 0 )
          goto LABEL_35;
      }
      *(_QWORD *)(v28 + 56) = v55 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v28 + 48);
LABEL_36:
      v56 = wlan_objmgr_vdev_component_obj_detach(a1, 0x2Eu, v28);
      if ( v56 )
      {
        v65 = "%s: Failed to detach dp_link with vdev";
LABEL_52:
        v81 = v56;
        qdf_trace_msg(0x45u, 2u, v65, v57, v58, v59, v60, v61, v62, v63, v64, "dp_vdev_obj_destroy_notification");
        return v81;
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v66 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v66 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v66 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v29 + 1536);
      }
      else
      {
        raw_spin_lock_bh(v29 + 1536);
        *(_QWORD *)(v29 + 1544) |= 1uLL;
      }
      v75 = *(unsigned __int8 *)(v28 + 24);
      v76 = *(unsigned __int8 *)(v28 + 25);
      v77 = *(unsigned __int8 *)(v28 + 26);
      if ( *(_QWORD *)(v28 + 112) )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Add to inactive list dp_link %pK id %d (%02x:%02x:%02x:**:**:%02x)",
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          "dp_link_handle_cdp_vdev_delete",
          v28,
          v75,
          v76,
          v77,
          *(unsigned __int8 *)(v28 + 27),
          *(unsigned __int8 *)(v28 + 30));
        *(_QWORD *)(v28 + 96) = 0;
        v78 = *(__int64 **)(v29 + 1528);
        *(_QWORD *)(v28 + 104) = v78;
        *v78 = v28;
        *(_QWORD *)(v29 + 1528) = v28 + 96;
        *(_BYTE *)(v28 + 88) = 1;
        v79 = *(_QWORD *)(v29 + 1544);
        if ( (v79 & 1) == 0 )
        {
LABEL_45:
          raw_spin_unlock(v29 + 1536);
          return 0;
        }
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Free dp_link %pK id %d (%02x:%02x:%02x:**:**:%02x)",
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          "dp_link_handle_cdp_vdev_delete",
          v28,
          v75,
          v76,
          v77,
          *(unsigned __int8 *)(v28 + 27),
          *(unsigned __int8 *)(v28 + 30));
        *(_QWORD *)(v28 + 16) = 0;
        _qdf_mem_free(v28);
        v79 = *(_QWORD *)(v29 + 1544);
        if ( (v79 & 1) == 0 )
          goto LABEL_45;
      }
      *(_QWORD *)(v29 + 1544) = v79 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v29 + 1536);
      return 0;
    }
  }
  else if ( !*((_DWORD *)v27 + 894) )
  {
    goto LABEL_31;
  }
  v52 = 99;
  while ( v52 )
  {
    v53 = jiffies;
    if ( dp_intf_wait_for_task_complete___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Waiting for DP task to complete: %d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "dp_intf_wait_for_task_complete",
        v52);
      dp_intf_wait_for_task_complete___last_ticks = v53;
    }
    qdf_sleep();
    --v52;
    if ( !*((_DWORD *)v27 + 894) )
      goto LABEL_31;
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Timed-out waiting for DP task completion",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "dp_intf_wait_for_task_complete");
  return 15;
}
