__int64 __fastcall cam_sfe_bus_wr_init(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4, _QWORD *a5)
{
  unsigned __int64 v9; // x23
  char *v10; // x28
  __int64 v11; // x0
  _QWORD *v12; // x19
  __int64 v13; // x0
  _DWORD *v14; // x20
  int v15; // w8
  __int64 v16; // x8
  int v17; // w8
  int v18; // w8
  __int64 v19; // x9
  unsigned int cpas_hw_version; // w0
  unsigned int v21; // w24
  _QWORD *v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  unsigned int v27; // w0
  _QWORD *v28; // x0
  __int64 v29; // x0
  char *v30; // x8
  int v31; // w9
  __int64 v32; // x9
  __int64 v33; // x8
  __int64 v34; // x8
  unsigned int v35; // w6
  __int64 v36; // x0
  int v37; // w9
  int v38; // w9
  int v39; // w9
  unsigned int v40; // w8
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x8
  _DWORD *v44; // x9
  _QWORD *v45; // x10
  __int64 v46; // x11
  _QWORD *v47; // x1
  __int64 result; // x0
  __int64 v49; // x21
  __int64 v50; // x8
  __int64 v51; // x23
  __int64 v52; // x25
  bool v53; // cc
  __int64 v54; // x8
  _QWORD *v55; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v57; // x27
  _QWORD *v58; // x0
  const char *v59; // [xsp+20h] [xbp-20h]
  bool v60; // [xsp+28h] [xbp-18h]
  __int64 v61; // [xsp+30h] [xbp-10h]
  __int64 v62; // [xsp+38h] [xbp-8h]

  v9 = a1;
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_wr_init",
      3602,
      "Enter");
    if ( v9 )
      goto LABEL_4;
LABEL_101:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_wr_init",
      3607,
      "Inval_prms soc_info:%pK hw_intf:%pK hw_info%pK",
      (const void *)v9,
      (const void *)a2,
      (const void *)a3);
    return 4294967274LL;
  }
  if ( !a1 )
    goto LABEL_101;
LABEL_4:
  if ( !a2 || !a3 )
    goto LABEL_101;
  v10 = (char *)&unk_2FD000;
  if ( mem_trace_en == 1 )
    v11 = cam_mem_trace_alloc(128, 0xCC0u, 0, "cam_sfe_bus_wr_init", 0xE1Cu);
  else
    v11 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
  v12 = (_QWORD *)v11;
  if ( !v11 )
  {
LABEL_103:
    result = 4294967284LL;
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_bus_wr_init",
        3614,
        "Failed to alloc for sfe_bus");
      return 4294967284LL;
    }
    return result;
  }
  while ( 1 )
  {
    if ( v10[2904] == 1 )
      v13 = cam_mem_trace_alloc(27624, 0xCC0u, 0, "cam_sfe_bus_wr_init", 0xE24u);
    else
      v13 = _kvmalloc_node_noprof(27624, 0, 3520, 0xFFFFFFFFLL);
    v14 = (_DWORD *)v13;
    if ( !v13 )
    {
      v21 = -12;
      if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x40000000,
          4,
          "cam_sfe_bus_wr_init",
          3622,
          "Failed to alloc for sfe_bus_priv");
      goto LABEL_109;
    }
    *v12 = v13;
    *(_DWORD *)(v13 + 27544) = *(_DWORD *)(a3 + 176);
    *(_DWORD *)(v13 + 27548) = *(_DWORD *)(a3 + 2084);
    *(_DWORD *)(v13 + 27552) = *(_DWORD *)(a3 + 3176);
    *(_DWORD *)(v13 + 27556) = *(_DWORD *)(a3 + 3164);
    v15 = *(_DWORD *)(a3 + 3172);
    *(_QWORD *)(v13 + 27424) = 0;
    *(_DWORD *)(v13 + 27560) = v15;
    *(_DWORD *)v13 = *(_DWORD *)(v9 + 20);
    if ( *(_DWORD *)(v9 + 480) )
      v16 = *(_QWORD *)(v9 + 288);
    else
      v16 = 0;
    *(_QWORD *)(v13 + 8) = v16;
    *(_QWORD *)(v13 + 16) = a2;
    *(_QWORD *)(v13 + 48) = a3;
    *(_DWORD *)(v13 + 27436) = *(_DWORD *)(a3 + 3168);
    *(_DWORD *)(v13 + 27440) = *(_DWORD *)(a3 + 3180);
    v17 = *(_DWORD *)(a3 + 3184);
    *(_BYTE *)(v13 + 27448) = 0;
    *(_QWORD *)(v13 + 24) = a4;
    *(_DWORD *)(v13 + 27444) = v17;
    *(_DWORD *)(v13 + 27464) = *(_DWORD *)(a3 + 3192);
    v18 = *(_DWORD *)(a3 + 3188);
    *(_QWORD *)(v13 + 27528) = v9;
    *(_DWORD *)(v13 + 27468) = v18;
    v19 = *(_QWORD *)(a3 + 3096);
    *(_QWORD *)(v13 + 27608) = a3 + 2088;
    *(_QWORD *)(v13 + 27616) = a3;
    *(_QWORD *)(v13 + 27600) = v19;
    cpas_hw_version = cam_cpas_get_cpas_hw_version((_DWORD *)(v13 + 4));
    if ( cpas_hw_version )
    {
      v21 = cpas_hw_version;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_wr_init",
        3653,
        "Failed to get hw_version rc:%d",
        cpas_hw_version);
      goto LABEL_19;
    }
    if ( v10[2904] == 1 )
    {
      v23 = cam_mem_trace_alloc(152LL * (unsigned int)v14[6889], 0xCC0u, 0, "cam_sfe_bus_wr_init", 0xE4Au);
      *((_QWORD *)v14 + 3446) = v23;
      if ( !v23 )
        goto LABEL_114;
    }
    else
    {
      v24 = _kvmalloc_node_noprof(152LL * (unsigned int)v14[6889], 0, 3520, 0xFFFFFFFFLL);
      *((_QWORD *)v14 + 3446) = v24;
      if ( !v24 )
      {
LABEL_114:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_wr_init",
          3660,
          "Failed to alloc for bus comp groups");
        v21 = -12;
        goto LABEL_19;
      }
    }
    if ( v10[2904] == 1 )
    {
      v25 = cam_mem_trace_alloc(2736, 0xCC0u, 0, "cam_sfe_bus_wr_init", 0xE52u);
      *((_QWORD *)v14 + 3447) = v25;
      if ( !v25 )
        goto LABEL_115;
    }
    else
    {
      v26 = _kvmalloc_node_noprof(2736, 0, 3520, 0xFFFFFFFFLL);
      *((_QWORD *)v14 + 3447) = v26;
      if ( !v26 )
      {
LABEL_115:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_wr_init",
          3668,
          "Failed to alloc for bus out res");
        v21 = -12;
        goto LABEL_116;
      }
    }
    _mutex_init(v14 + 6844, "&bus_priv->common_data.bus_mutex", &cam_sfe_bus_wr_init___key);
    v27 = cam_irq_controller_init("sfe_bus_wr", *((_QWORD *)v14 + 1), (unsigned int *)(a3 + 72), (__int64 *)v14 + 5);
    if ( v27 )
    {
      v21 = v27;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_wr_init",
        3679,
        "Init bus_irq_controller failed");
      goto LABEL_32;
    }
    if ( !v14[6889] )
      break;
    v9 = 0;
    a4 = a3 + 3120;
    v10 = (_BYTE *)&unk_70;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      a2 = *((_QWORD *)v14 + 3446);
      if ( mem_trace_en == 1 )
      {
        v29 = cam_mem_trace_alloc(48, 0xCC0u, 0, "cam_sfe_bus_wr_init_comp_grp", 0x491u);
        if ( !v29 )
          goto LABEL_44;
      }
      else
      {
        v29 = _kvmalloc_node_noprof(48, 0, 3520, 0xFFFFFFFFLL);
        if ( !v29 )
        {
LABEL_44:
          v21 = -12;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_bus_wr_init",
            3690,
            "SFE:%d init comp_grp:%d failed rc:%d",
            *v14,
            v9,
            -12);
          v10 = (char *)&unk_2FD000;
          goto LABEL_92;
        }
      }
      v30 = &v10[a2];
      *((_DWORD *)v30 - 26) = 1;
      *((_QWORD *)v30 - 11) = v29;
      *(_DWORD *)v29 = v9;
      *(_QWORD *)(v29 + 8) = v14;
      *(_DWORD *)(v29 + 24) = 2;
      if ( v10 == byte_6F8 )
        break;
      v31 = *(_DWORD *)(a4 + 4 * v9++);
      v10 += 152;
      *(_DWORD *)(v29 + 4) = v31;
      *(_QWORD *)v30 = 0;
      *((_QWORD *)v30 - 12) = *((_QWORD *)v14 + 2);
      if ( v9 >= (unsigned int)v14[6889] )
        goto LABEL_45;
    }
LABEL_102:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v57 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_sfe_bus_wr_init__alloc_tag;
    v12 = (_QWORD *)_kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v57;
    if ( !v12 )
      goto LABEL_103;
  }
LABEL_45:
  if ( !v14[6887] )
  {
LABEL_72:
    v44 = v14 + 182;
    v45 = v14 + 188;
    v46 = 256;
    v14[186] = 0;
    *((_QWORD *)v14 + 91) = v14 + 182;
    *((_QWORD *)v14 + 92) = v14 + 182;
    do
    {
      *v45 = v45;
      v45[1] = v45;
      v47 = *((_QWORD **)v14 + 92);
      if ( v45 == v47 || (_DWORD *)*v47 != v44 )
      {
        _list_add_valid_or_report(v45);
      }
      else
      {
        *((_QWORD *)v14 + 92) = v45;
        *v45 = v44;
        v45[1] = v47;
        *v47 = v45;
      }
      --v46;
      v45 += 13;
    }
    while ( v46 );
    v12[14] = 0;
    v12[15] = 0;
    result = 0;
    v12[5] = cam_sfe_bus_acquire_sfe_out;
    v12[6] = cam_sfe_bus_release_sfe_out;
    v12[7] = cam_sfe_bus_wr_start_hw;
    v12[8] = cam_sfe_bus_wr_stop_hw;
    v12[2] = cam_sfe_bus_wr_init_hw;
    v12[3] = cam_sfe_bus_wr_deinit_hw;
    v12[11] = cam_sfe_bus_wr_process_cmd;
    v14[6896] = 0;
    v14[6868] = 0;
    *a5 = v12;
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_bus_wr_init",
        3728,
        "Exit");
      return 0;
    }
    return result;
  }
  v32 = 0;
  a4 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v34 = *((_QWORD *)v14 + 3451);
    v62 = v32;
    if ( !v34 )
    {
      v35 = 18;
      v10 = (char *)&unk_2FD000;
LABEL_84:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_init_sfe_out_resource",
        1808,
        "Init SFE Out failed, Invalid type=%d",
        v35);
      v21 = -22;
      goto LABEL_88;
    }
    v35 = *(_DWORD *)(v34 + v32);
    v10 = (char *)&unk_2FD000;
    if ( v35 >= 0x12 )
      goto LABEL_84;
    v9 = *((_QWORD *)v14 + 3447) + 152LL * v35;
    if ( *(_DWORD *)(v9 + 8) || *(_QWORD *)(v9 + 24) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_init_sfe_out_resource",
        1816,
        "sfe_out_type %d has already been initialized",
        v35);
      v21 = -14;
      goto LABEL_88;
    }
    v61 = a4;
    if ( mem_trace_en == 1 )
      v36 = cam_mem_trace_alloc(112, 0xCC0u, 0, "cam_sfe_bus_init_sfe_out_resource", 0x71Du);
    else
      v36 = _kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
    a2 = v36;
    if ( !v36 )
    {
      v21 = -12;
      goto LABEL_88;
    }
    *(_QWORD *)(v9 + 24) = v36;
    *(_DWORD *)v9 = 12;
    *(_DWORD *)(v9 + 8) = 1;
    *(_QWORD *)(v9 + 32) = v9 + 32;
    *(_QWORD *)(v9 + 40) = v9 + 32;
    if ( v62 == 1008 )
      goto LABEL_102;
    *(_DWORD *)(v36 + 4) = *(_DWORD *)(a3 + v62 + 2100);
    v37 = *(_DWORD *)(a3 + v62 + 2088);
    *(_QWORD *)(v36 + 8) = v14;
    *(_DWORD *)v36 = v37;
    *(_DWORD *)(v36 + 76) = *(_DWORD *)(a3 + v62 + 2092);
    v38 = *(_DWORD *)(a3 + v62 + 2096);
    *(_DWORD *)(v36 + 96) = 0;
    *(_DWORD *)(v36 + 80) = v38;
    v39 = (unsigned __int8)mem_trace_en;
    v40 = *(_DWORD *)(a3 + v62 + 2124);
    *(_DWORD *)(v36 + 24) = v40;
    if ( v39 == 1 )
      v41 = cam_mem_trace_alloc(152LL * v40, 0xCC0u, 0, "cam_sfe_bus_init_sfe_out_resource", 0x736u);
    else
      v41 = _kvmalloc_node_noprof(152LL * *(unsigned int *)(v36 + 24), 0, 3520, 0xFFFFFFFFLL);
    v10 = (char *)v41;
    *(_QWORD *)(a2 + 32) = v41;
    if ( !v41 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_init_sfe_out_resource",
        1848,
        "Failed to alloc for wm_res");
      v21 = -12;
      goto LABEL_87;
    }
    a4 = *(unsigned int *)(a3 + v62 + 2128);
    v59 = *(const char **)(a3 + v62 + 2136);
    v60 = *(_DWORD *)(a3 + v62 + 2132) != 0;
    if ( mem_trace_en != 1 )
      break;
    v42 = cam_mem_trace_alloc(128, 0xCC0u, 0, "cam_sfe_bus_init_wm_resource", 0x3CBu);
    if ( !v42 )
      goto LABEL_68;
LABEL_65:
    *((_QWORD *)v10 + 3) = v42;
    *(_DWORD *)v42 = a4;
    *(_BYTE *)(v42 + 124) = v60;
    if ( (unsigned int)a4 >= 0x12 )
      goto LABEL_102;
    v43 = a3 + 180 + 112LL * (unsigned int)a4;
    *(_QWORD *)(v42 + 8) = v14;
    *(_QWORD *)(v42 + 16) = v43;
    *(_QWORD *)(a2 + 40) = *((_QWORD *)v14 + 3446) + 152LL * *(unsigned int *)(v43 + 108);
    *((_DWORD *)v10 + 2) = 1;
    *((_QWORD *)v10 + 4) = v10 + 32;
    *((_QWORD *)v10 + 5) = v10 + 32;
    *((_QWORD *)v10 + 11) = cam_sfe_bus_start_wm;
    *((_QWORD *)v10 + 12) = cam_sfe_bus_stop_wm;
    *((_QWORD *)v10 + 14) = cam_sfe_bus_handle_wm_done_top_half;
    *((_QWORD *)v10 + 15) = cam_sfe_bus_handle_wm_done_bottom_half;
    *((_QWORD *)v10 + 2) = *((_QWORD *)v14 + 2);
    if ( v59 )
      scnprintf(v10 + 128, 16, "%s", v59);
    *(_QWORD *)(v9 + 104) = 0;
    *(_QWORD *)(v9 + 88) = cam_sfe_bus_start_sfe_out;
    *(_QWORD *)(v9 + 96) = cam_sfe_bus_stop_sfe_out;
    *(_QWORD *)(v9 + 112) = cam_sfe_bus_handle_sfe_out_done_top_half;
    *(_QWORD *)(v9 + 120) = cam_sfe_bus_handle_sfe_out_done_bottom_half;
    v33 = *((_QWORD *)v14 + 2);
    *(_DWORD *)(v9 + 64) = 0;
    *(_QWORD *)(v9 + 16) = v33;
    a4 = v61 + 1;
    v32 = v62 + 56;
    if ( v61 + 1 >= (unsigned __int64)(unsigned int)v14[6887] )
      goto LABEL_72;
  }
  v42 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
  if ( v42 )
    goto LABEL_65;
LABEL_68:
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_init_wm_resource",
      973,
      "Failed to alloc for WM res priv");
  v21 = -12;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x40000000,
    1,
    "cam_sfe_bus_init_sfe_out_resource",
    1862,
    "SFE:%d init WM:%d failed rc:%d",
    *v14,
    0,
    -12);
LABEL_87:
  LODWORD(a4) = v61;
  v10 = (char *)&unk_2FD000;
LABEL_88:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x40000000,
    1,
    "cam_sfe_bus_wr_init",
    3701,
    "SFE:%d init out_type:0x%X failed rc:%d",
    *v14,
    a4,
    v21);
  if ( (_DWORD)v62 )
  {
    v49 = 152LL * (unsigned int)(a4 - 1);
    do
    {
      cam_sfe_bus_deinit_sfe_out_resource(*((_QWORD *)v14 + 3447) + v49);
      v49 -= 152;
    }
    while ( v49 != -152 );
  }
  LODWORD(v9) = v14[6889];
LABEL_92:
  v50 = (unsigned int)(v9 - 1);
  if ( (int)v9 - 1 >= 0 )
  {
    v51 = 152LL * (unsigned int)v50;
    v52 = v50 + 1;
    do
    {
      v54 = *((_QWORD *)v14 + 3446) + v51;
      v55 = *(_QWORD **)(v54 + 24);
      *(_DWORD *)(v54 + 8) = 0;
      *(_QWORD *)(v54 + 16) = 0;
      *(_QWORD *)(v54 + 24) = 0;
      *(_QWORD *)(v54 + 88) = 0;
      *(_QWORD *)(v54 + 96) = 0;
      *(_QWORD *)(v54 + 112) = 0;
      *(_QWORD *)(v54 + 120) = 0;
      if ( v55 )
      {
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v55, 0);
        else
          kvfree(v55);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_deinit_comp_grp",
          1205,
          "comp_grp_priv is NULL");
      }
      v53 = v52-- <= 1;
      v51 -= 152;
    }
    while ( !v53 );
  }
LABEL_32:
  v28 = *((_QWORD **)v14 + 3447);
  if ( v10[2904] == 1 )
    cam_mem_trace_free(v28, 0);
  else
    kvfree(v28);
LABEL_116:
  v58 = *((_QWORD **)v14 + 3446);
  if ( v10[2904] == 1 )
    cam_mem_trace_free(v58, 0);
  else
    kvfree(v58);
LABEL_19:
  v22 = (_QWORD *)*v12;
  if ( v10[2904] == 1 )
    cam_mem_trace_free(v22, 0);
  else
    kvfree(v22);
LABEL_109:
  if ( v10[2904] == 1 )
    cam_mem_trace_free(v12, 0);
  else
    kvfree(v12);
  return v21;
}
