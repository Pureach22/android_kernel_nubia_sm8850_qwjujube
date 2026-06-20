__int64 __fastcall pmo_core_psoc_bus_resume_req(
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
  unsigned int ref; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  __int64 comp_private_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v32; // x8
  unsigned int v33; // w21
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned __int64 v66; // x8
  unsigned __int64 v67; // x23
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int v76; // w0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // w24
  unsigned int pending_cmnds; // w22
  unsigned int host_credits; // w0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  unsigned int v104; // w20
  unsigned int v105; // w0
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  unsigned int v114; // w22
  unsigned int v115; // w0
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  unsigned __int64 v124; // x8
  __int64 v125; // x8
  unsigned __int64 v126; // x8
  __int64 v127; // x8
  unsigned __int64 v128; // x8
  unsigned __int64 v129; // x8
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x4Du, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_psoc_bus_resume_req");
    return 29;
  }
  ref = wlan_objmgr_psoc_try_get_ref(a1, 0xAu, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( ref )
  {
    v19 = ref;
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: pmo cannot get the reference out of psoc",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "pmo_core_psoc_bus_resume_req");
    return v19;
  }
  pmo_core_psoc_get_hif_handle(a1);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  v30 = comp_private_obj;
  if ( !comp_private_obj )
  {
    qdf_trace_msg(0x4Du, 2u, "%s: psoc_ctx is null", v22, v23, v24, v25, v26, v27, v28, v29, "pmo_core_is_wow_enabled");
    v33 = 0;
    goto LABEL_13;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(comp_private_obj + 1040);
      v32 = *(_QWORD *)(v30 + 1048) | 1LL;
      *(_QWORD *)(v30 + 1048) = v32;
      v33 = *(unsigned __int8 *)(v30 + 488);
      if ( (v32 & 1) == 0 )
        goto LABEL_10;
LABEL_49:
      *(_QWORD *)(v30 + 1048) = v32 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v30 + 1040);
      goto LABEL_11;
    }
  }
  raw_spin_lock(comp_private_obj + 1040);
  v32 = *(_QWORD *)(v30 + 1048);
  v33 = *(unsigned __int8 *)(v30 + 488);
  if ( (v32 & 1) != 0 )
    goto LABEL_49;
LABEL_10:
  raw_spin_unlock(v30 + 1040);
LABEL_11:
  qdf_trace_msg(0x4Du, 8u, "%s: WoW enable %d", v34, v35, v36, v37, v38, v39, v40, v41, "pmo_core_is_wow_enabled", v33);
LABEL_13:
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: wow mode %d",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    "pmo_core_psoc_bus_resume_req",
    v33);
  *(_DWORD *)(v30 + 580) = 0;
  if ( (qdf_is_fw_down(v50, v51, v52, v53, v54, v55, v56, v57) & 1) != 0 || (pmo_tgt_is_target_suspended(a1) & 1) == 0 )
  {
    wlan_objmgr_psoc_release_ref(a1, 0xAu, v58, v59, v60, v61, v62, v63, v64, v65);
    return 3;
  }
  __isb(0xFu);
  v66 = _ReadStatusReg(CNTVCT_EL0);
  if ( 10 * v66 >= v66 )
  {
    v67 = 10 * v66 / 0xC0;
    if ( !v33 )
    {
LABEL_17:
      qdf_event_reset(v30 + 536);
      if ( !(unsigned int)pmo_tgt_psoc_send_target_resume_req(a1) )
      {
        v76 = qdf_wait_single_event(v30 + 536, 0xFA0u);
        if ( v76 )
        {
          v85 = v76;
          qdf_trace_msg(
            0x4Du,
            1u,
            "%s: Timeout waiting for resume event from FW",
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            "pmo_core_psoc_resume_target");
          pending_cmnds = pmo_tgt_psoc_get_pending_cmnds(a1);
          host_credits = pmo_tgt_psoc_get_host_credits(a1);
          qdf_trace_msg(
            0x4Du,
            1u,
            "%s: Pending commands %d credits %d",
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            v94,
            v95,
            "pmo_core_psoc_resume_target",
            pending_cmnds,
            host_credits);
          if ( (*(_BYTE *)(v30 + 573) & 1) == 0 )
            goto LABEL_29;
          goto LABEL_30;
        }
        qdf_trace_msg(
          0x4Du,
          8u,
          "%s: Host wakeup received",
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          "pmo_core_psoc_resume_target");
        pmo_tgt_update_target_suspend_flag(a1, 0);
        pmo_tgt_update_target_suspend_acked_flag(a1, 0);
LABEL_42:
        v104 = 0;
        goto LABEL_43;
      }
      goto LABEL_25;
    }
  }
  else
  {
    v67 = 10 * (v66 / 0xC0);
    if ( !v33 )
      goto LABEL_17;
  }
  if ( !pmo_core_psoc_get_hif_handle(a1) )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: hif_ctx is NULL",
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      "pmo_core_psoc_send_host_wakeup_ind_to_fw");
    v104 = 4;
    goto LABEL_43;
  }
  qdf_event_reset(v30 + 536);
  if ( !(unsigned int)pmo_tgt_psoc_send_host_wakeup_ind(a1) )
  {
    qdf_trace_msg(
      0x4Du,
      4u,
      "%s: Host wakeup indication sent to fw",
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      "pmo_core_psoc_send_host_wakeup_ind_to_fw");
    v105 = qdf_wait_for_event_completion(v30 + 536, 0xFA0u);
    if ( v105 )
    {
      v85 = v105;
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: Timeout waiting for resume event from FW",
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        "pmo_core_psoc_send_host_wakeup_ind_to_fw");
      v114 = pmo_tgt_psoc_get_pending_cmnds(a1);
      v115 = pmo_tgt_psoc_get_host_credits(a1);
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: Pending commands %d credits %d",
        v116,
        v117,
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        "pmo_core_psoc_send_host_wakeup_ind_to_fw",
        v114,
        v115);
      if ( (*(_BYTE *)(v30 + 573) & 1) == 0 )
LABEL_29:
        _qdf_trigger_self_recovery();
LABEL_30:
      v104 = v85;
      goto LABEL_43;
    }
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: Host wakeup received",
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      "pmo_core_psoc_send_host_wakeup_ind_to_fw");
    pmo_tgt_update_target_suspend_flag(a1, 0);
    pmo_tgt_update_target_suspend_acked_flag(a1, 0);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v124 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v124 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v124 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v30 + 1040);
      v125 = *(_QWORD *)(v30 + 1048);
      *(_BYTE *)(v30 + 489) = 0;
      if ( (v125 & 1) == 0 )
        goto LABEL_36;
    }
    else
    {
      raw_spin_lock_bh(v30 + 1040);
      v125 = *(_QWORD *)(v30 + 1048) | 1LL;
      *(_QWORD *)(v30 + 1048) = v125;
      *(_BYTE *)(v30 + 489) = 0;
      if ( (v125 & 1) == 0 )
      {
LABEL_36:
        raw_spin_unlock(v30 + 1040);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
          goto LABEL_39;
LABEL_37:
        v126 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v126 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v126 + 16) & 0xFF00) == 0 )
        {
          raw_spin_lock_bh(v30 + 1040);
          v127 = *(_QWORD *)(v30 + 1048) | 1LL;
          *(_QWORD *)(v30 + 1048) = v127;
          *(_BYTE *)(v30 + 490) = 0;
          if ( (v127 & 1) == 0 )
            goto LABEL_40;
          goto LABEL_54;
        }
LABEL_39:
        raw_spin_lock(v30 + 1040);
        v127 = *(_QWORD *)(v30 + 1048);
        *(_BYTE *)(v30 + 490) = 0;
        if ( (v127 & 1) == 0 )
        {
LABEL_40:
          raw_spin_unlock(v30 + 1040);
LABEL_41:
          pmo_tgt_psoc_update_wow_bus_suspend_state(a1, 0);
          pmo_unpause_all_vdev(a1, v30);
          goto LABEL_42;
        }
LABEL_54:
        *(_QWORD *)(v30 + 1048) = v127 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v30 + 1040);
        goto LABEL_41;
      }
    }
    *(_QWORD *)(v30 + 1048) = v125 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v30 + 1040);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_39;
    goto LABEL_37;
  }
LABEL_25:
  v104 = 16;
LABEL_43:
  __isb(0xFu);
  v128 = _ReadStatusReg(CNTVCT_EL0);
  if ( 10 * v128 >= v128 )
    v129 = 10 * v128 / 0xC0;
  else
    v129 = 10 * (v128 / 0xC0);
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: fw took total time %lu microseconds to disable wow",
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    "pmo_core_psoc_bus_resume_req",
    v129 - v67);
  wlan_objmgr_psoc_release_ref(a1, 0xAu, v130, v131, v132, v133, v134, v135, v136, v137);
  return v104;
}
