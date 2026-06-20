__int64 __fastcall pmo_core_config_modulated_dtim(__int64 a1, unsigned int a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int ref; // w22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w20
  unsigned int v30; // w8
  __int64 comp_private_obj; // x0
  __int64 v32; // x22
  unsigned __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v38; // x8
  unsigned int updated; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int *v48; // x8
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
  const char *v65; // x3
  unsigned int v66; // w20
  __int64 v67; // x0
  __int64 v68; // x23
  __int64 v69; // x0
  __int64 v70; // x20
  unsigned __int64 v71; // x8
  __int64 v72; // x8
  __int64 v74; // x22
  unsigned __int16 vdev_beacon_interval; // w0
  unsigned int v76; // w24
  unsigned int v77; // w8
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int v86; // w9
  char v87; // w10
  unsigned int v88; // w24
  unsigned __int64 v89; // x8
  int v90; // w25
  unsigned __int8 vdev_dtim_period; // w0
  __int64 v92; // x8
  unsigned __int8 v93; // w23
  unsigned int *v94; // x8
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  unsigned int v103; // w21
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 v112; // x0
  unsigned __int64 v113; // x8
  unsigned int *v114; // x8
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  unsigned int v123; // w0
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 v132; // x0
  __int64 v133; // x20
  unsigned __int64 v134; // x8
  __int64 v135; // x8

  if ( *(_BYTE *)(*(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u) + 956LL) == 1 )
  {
    qdf_trace_msg(0x4Du, 8u, "%s: enter", v4, v5, v6, v7, v8, v9, v10, v11, "pmo_core_config_li_offload_modulated_dtim");
    ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( ref )
    {
LABEL_30:
      v65 = "pmo_core_config_li_offload_modulated_dtim";
      goto LABEL_31;
    }
    v29 = *(unsigned __int8 *)(a1 + 104);
    v30 = *(unsigned __int8 *)(*(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u) + 29LL);
    if ( v30 < a2 )
      a2 = v30;
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
    v32 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v33 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v33 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v33 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
      v34 = *(_QWORD *)(v32 + 1064);
      *(_DWORD *)(v32 + 1036) = a2;
      if ( (v34 & 1) == 0 )
      {
LABEL_9:
        raw_spin_unlock(v32 + 1056);
LABEL_10:
        v35 = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
        v36 = v35;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v35 + 1056);
          v38 = *(_QWORD *)(v36 + 1064);
        }
        else
        {
          raw_spin_lock_bh(v35 + 1056);
          v38 = *(_QWORD *)(v36 + 1064) | 1LL;
          *(_QWORD *)(v36 + 1064) = v38;
        }
        *(_BYTE *)(v36 + 1040) = 1;
        if ( (v38 & 1) != 0 )
        {
          *(_QWORD *)(v36 + 1064) = v38 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v36 + 1056);
        }
        else
        {
          raw_spin_unlock(v36 + 1056);
        }
        if ( (ucfg_pmo_is_vdev_connected(a1) & 1) != 0 )
        {
          updated = pmo_tgt_vdev_update_param_req(a1, 3, a2);
          if ( updated )
          {
            ref = updated;
            qdf_trace_msg(
              0x4Du,
              2u,
              "%s: Failed to Set modulated dtim for vdev id %d",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "pmo_core_config_li_offload_modulated_dtim",
              v29);
LABEL_29:
            wlan_objmgr_vdev_release_ref(a1, 0xAu, v48, v49, v50, v51, v52, v53, v54, v55, v56);
            goto LABEL_30;
          }
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: Set modulated dtim for vdev id %d",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "pmo_core_config_li_offload_modulated_dtim",
            v29);
          v112 = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
          v70 = v112;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (v113 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v113 + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(v113 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v112 + 1056);
            v72 = *(_QWORD *)(v70 + 1064);
          }
          else
          {
            raw_spin_lock_bh(v112 + 1056);
            v72 = *(_QWORD *)(v70 + 1064) | 1LL;
            *(_QWORD *)(v70 + 1064) = v72;
          }
          *(_BYTE *)(v70 + 1041) = 1;
          if ( (v72 & 1) != 0 )
            goto LABEL_56;
LABEL_27:
          raw_spin_unlock(v70 + 1056);
LABEL_28:
          ref = 0;
          goto LABEL_29;
        }
        v69 = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
        v70 = v69;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v71 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v71 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v71 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v69 + 1056);
          v72 = *(_QWORD *)(v70 + 1064);
          *(_BYTE *)(v70 + 1041) = 0;
          if ( (v72 & 1) == 0 )
            goto LABEL_27;
        }
        else
        {
          raw_spin_lock_bh(v69 + 1056);
          v72 = *(_QWORD *)(v70 + 1064) | 1LL;
          *(_QWORD *)(v70 + 1064) = v72;
          *(_BYTE *)(v70 + 1041) = 0;
          if ( (v72 & 1) == 0 )
            goto LABEL_27;
        }
LABEL_56:
        *(_QWORD *)(v70 + 1064) = v72 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v70 + 1056);
        goto LABEL_28;
      }
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      v34 = *(_QWORD *)(v32 + 1064) | 1LL;
      *(_QWORD *)(v32 + 1064) = v34;
      *(_DWORD *)(v32 + 1036) = a2;
      if ( (v34 & 1) == 0 )
        goto LABEL_9;
    }
    *(_QWORD *)(v32 + 1064) = v34 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v32 + 1056);
    goto LABEL_10;
  }
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: enter",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "pmo_core_config_non_li_offload_modulated_dtim");
  ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, v57, v58, v59, v60, v61, v62, v63, v64);
  if ( ref )
  {
LABEL_20:
    v65 = "pmo_core_config_non_li_offload_modulated_dtim";
LABEL_31:
    qdf_trace_msg(0x4Du, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, v65);
    return ref;
  }
  v66 = *(unsigned __int8 *)(a1 + 104);
  v67 = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v68 = *(_QWORD *)v67;
  if ( *(_BYTE *)(*(_QWORD *)v67 + 30LL) != 1 )
  {
    v74 = v67;
    vdev_beacon_interval = pmo_core_get_vdev_beacon_interval(a1);
    if ( vdev_beacon_interval < 0x64u )
      v76 = 1;
    else
      v76 = vdev_beacon_interval / 0x64u;
    v77 = v76 * (unsigned __int8)pmo_core_get_vdev_dtim_period(a1);
    if ( !v77 )
    {
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: Invalid dtim period",
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        "pmo_core_config_non_li_offload_modulated_dtim");
      wlan_objmgr_vdev_release_ref(a1, 0xAu, v114, v115, v116, v117, v118, v119, v120, v121, v122);
      return 4;
    }
    v86 = *(unsigned __int8 *)(v68 + 29);
    v87 = _ReadStatusReg(DAIF);
    if ( v77 > v86 )
      v88 = 1;
    else
      v88 = v86 / v77;
    if ( v87 < 0
      || (v89 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v89 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v89 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v74 + 1056);
    }
    else
    {
      raw_spin_lock_bh(v74 + 1056);
      *(_QWORD *)(v74 + 1064) |= 1uLL;
    }
    v90 = *(unsigned __int8 *)(v74 + 1040);
    *(_DWORD *)(v74 + 1036) = a2;
    *(_BYTE *)(v74 + 1040) = a2 != 1;
    vdev_dtim_period = pmo_core_get_vdev_dtim_period(a1);
    v92 = *(_QWORD *)(v74 + 1064);
    v93 = vdev_dtim_period;
    if ( v88 >= a2 )
      v88 = a2;
    if ( (v92 & 1) != 0 )
    {
      *(_QWORD *)(v74 + 1064) = v92 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v74 + 1056);
      if ( a2 == 1 )
      {
LABEL_48:
        if ( !v90 )
          goto LABEL_67;
      }
    }
    else
    {
      raw_spin_unlock(v74 + 1056);
      if ( a2 == 1 )
        goto LABEL_48;
    }
    v103 = v88 * v93;
    if ( (unsigned int)pmo_tgt_vdev_update_param_req(a1, 0, v103) )
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: Failed to set Listen Interval for vdev id %d",
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        "pmo_core_config_non_li_offload_modulated_dtim",
        v66);
    else
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: Set Listen Interval %d for  vdev id %d",
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        "pmo_core_config_non_li_offload_modulated_dtim",
        v103,
        v66);
    v123 = pmo_tgt_vdev_update_param_req(a1, 1, 2);
    if ( v123 )
    {
      ref = v123;
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: Failed to set Normal DTIM for vdev id %d",
        v124,
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        v131,
        "pmo_core_config_non_li_offload_modulated_dtim",
        v66);
LABEL_68:
      wlan_objmgr_vdev_release_ref(a1, 0xAu, v94, v95, v96, v97, v98, v99, v100, v101, v102);
      goto LABEL_20;
    }
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: Set DTIM Policy to Normal for vdev id %d",
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      "pmo_core_config_non_li_offload_modulated_dtim",
      v66);
    v132 = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
    v133 = v132;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v134 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v134 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v134 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v132 + 1056);
      v135 = *(_QWORD *)(v133 + 1064);
    }
    else
    {
      raw_spin_lock_bh(v132 + 1056);
      v135 = *(_QWORD *)(v133 + 1064) | 1LL;
      *(_QWORD *)(v133 + 1064) = v135;
    }
    *(_BYTE *)(v133 + 1048) = 1;
    if ( (v135 & 1) != 0 )
    {
      *(_QWORD *)(v133 + 1064) = v135 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v133 + 1056);
    }
    else
    {
      raw_spin_unlock(v133 + 1056);
    }
LABEL_67:
    ref = 0;
    goto LABEL_68;
  }
  return (unsigned int)pmo_core_config_forced_dtim(a1, a2);
}
