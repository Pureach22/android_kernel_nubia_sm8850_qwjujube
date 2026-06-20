__int64 __fastcall dp_vdev_obj_create_notification(
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
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 comp_private_obj; // x0
  __int64 (__fastcall *v21)(_QWORD); // x8
  __int64 v22; // x21
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x22
  __int64 intf_by_netdev; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x19
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v54; // x8
  __int16 v55; // w8
  int v56; // w9
  unsigned __int64 v57; // x8
  __int64 v58; // x8
  char v59; // w9
  unsigned int v60; // w0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  const char *v69; // x2
  unsigned int v70; // w19
  int v72; // w8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned __int64 v81; // x8
  __int64 v82; // x8

  qdf_trace_msg(
    0x45u,
    5u,
    "%s: DP VDEV OBJ create notification, vdev_id %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_vdev_obj_create_notification",
    *(unsigned __int8 *)(a1 + 104));
  v18 = *(_QWORD *)(a1 + 152);
  if ( !v18 || (v19 = *(_QWORD *)(v18 + 80)) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to get psoc",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_vdev_obj_create_notification");
    return 4;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v19, 0x2Eu);
  v21 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 384);
  v22 = comp_private_obj;
  if ( *((_DWORD *)v21 - 1) != 1052358515 )
    __break(0x8228u);
  v23 = v21(a1 + 74);
  if ( !v23 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to get intf mac:%02x:%02x:%02x:**:**:%02x",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "dp_vdev_obj_create_notification",
      *(unsigned __int8 *)(a1 + 74),
      *(unsigned __int8 *)(a1 + 75),
      *(unsigned __int8 *)(a1 + 76),
      *(unsigned __int8 *)(a1 + 79));
    return 4;
  }
  v32 = v23;
  intf_by_netdev = dp_get_intf_by_netdev(v22, v23);
  if ( !intf_by_netdev )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to get dp intf dev: %s",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "dp_vdev_obj_create_notification",
      v32 + 296);
    return 4;
  }
  v42 = intf_by_netdev;
  v43 = _qdf_mem_malloc(0x80u, "dp_vdev_obj_create_notification", 1424);
  if ( v43 )
  {
    v52 = v43;
    *(_QWORD *)(v43 + 112) = 0;
    *(_BYTE *)(v43 + 88) = 0;
    *(_QWORD *)(v43 + 120) = v43 + 112;
    *(_QWORD *)(v43 + 16) = 0x5F44505F4C494E4BLL;
    *(_QWORD *)(v43 + 32) = v42;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v42 + 3672);
    }
    else
    {
      raw_spin_lock_bh(v42 + 3672);
      *(_QWORD *)(v42 + 3680) |= 1uLL;
    }
    qdf_list_insert_front((_QWORD *)(v42 + 3688), (_QWORD *)v52);
    v54 = *(_QWORD *)(v42 + 3680);
    ++*(_BYTE *)(v42 + 3661);
    if ( (v54 & 1) != 0 )
    {
      *(_QWORD *)(v42 + 3680) = v54 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v42 + 3672);
    }
    else
    {
      raw_spin_unlock(v42 + 3672);
    }
    v55 = *(_WORD *)(a1 + 78);
    v56 = *(_DWORD *)(a1 + 74);
    *(_DWORD *)(v52 + 48) = 0;
    *(_WORD *)(v52 + 29) = v55;
    *(_DWORD *)(v52 + 25) = v56;
    *(_QWORD *)(v52 + 56) = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v57 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v57 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v57 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v52 + 48);
      v58 = *(_QWORD *)(v52 + 56);
    }
    else
    {
      raw_spin_lock_bh(v52 + 48);
      v58 = *(_QWORD *)(v52 + 56) | 1LL;
      *(_QWORD *)(v52 + 56) = v58;
    }
    v59 = *(_BYTE *)(a1 + 104);
    *(_QWORD *)(v52 + 40) = a1;
    *(_BYTE *)(v52 + 24) = v59;
    if ( (v58 & 1) != 0 )
    {
      *(_QWORD *)(v52 + 56) = v58 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v52 + 48);
    }
    else
    {
      raw_spin_unlock(v52 + 48);
    }
    v60 = wlan_objmgr_vdev_component_obj_attach(a1, 0x2Eu, v52, 0);
    if ( v60 )
    {
      v69 = "%s: Failed to attach dp_link with vdev";
LABEL_22:
      v70 = v60;
      qdf_trace_msg(0x45u, 2u, v69, v61, v62, v63, v64, v65, v66, v67, v68, "dp_vdev_obj_create_notification");
      return v70;
    }
    wlan_dp_resource_mgr_notify_vdev_creation(*(_QWORD *)(v22 + 3000), a1);
    v72 = *(_DWORD *)(a1 + 16);
    *(_DWORD *)(v42 + 28) = v72;
    if ( (v72 | 2) == 3 )
      *(_DWORD *)(v52 + 80) = 3;
    if ( *(_BYTE *)(v42 + 3661) == 1 )
    {
      *(_QWORD *)(v42 + 3664) = v52;
      *(_DWORD *)(v42 + 3576) = 0;
      dp_nud_ignore_tracking(v42, 0);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Enable the MIC error work",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        "dp_mic_enable_work");
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v81 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v81 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v81 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v42 + 3464);
      }
      else
      {
        raw_spin_lock_bh(v42 + 3464);
        *(_QWORD *)(v42 + 3472) |= 1uLL;
      }
      if ( *(_DWORD *)(v42 + 3448) == 3 )
        *(_DWORD *)(v42 + 3448) = 1;
      v82 = *(_QWORD *)(v42 + 3472);
      if ( (v82 & 1) != 0 )
      {
        *(_QWORD *)(v42 + 3472) = v82 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v42 + 3464);
      }
      else
      {
        raw_spin_unlock(v42 + 3464);
      }
      dp_fpm_init(v42);
      dp_fim_init(v42);
      wlan_dp_spm_intf_ctx_init(v42);
      dp_telemetry_init(v42);
      if ( (*(_DWORD *)(v42 + 28) | 2) == 3 )
      {
        *(_BYTE *)(v42 + 3580) = 1;
        v60 = qdf_event_create((_DWORD *)(v42 + 3616));
        if ( v60 )
        {
          v69 = "%s: eap frm done event init failed!!";
          goto LABEL_22;
        }
        qdf_mem_set((void *)(v42 + 2888), 0xB8u, 0);
      }
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: DP link(%02x:%02x:%02x:**:**:%02x) memory alloc failed",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "dp_vdev_obj_create_notification",
      *(unsigned __int8 *)(a1 + 74),
      *(unsigned __int8 *)(a1 + 75),
      *(unsigned __int8 *)(a1 + 76),
      *(unsigned __int8 *)(a1 + 79));
    return 2;
  }
}
