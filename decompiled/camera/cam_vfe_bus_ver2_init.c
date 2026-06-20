__int64 __fastcall cam_vfe_bus_ver2_init(unsigned __int64 a1, char *a2, const char *a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x22
  unsigned __int64 v9; // x27
  char *v10; // x21
  __int64 v11; // x28
  _QWORD *v12; // x19
  __int64 v13; // x0
  __int64 v14; // x20
  int v15; // w9
  _QWORD *v16; // x24
  __int64 v17; // x8
  char v18; // w8
  int v19; // w0
  const char *v20; // x19
  __int64 v21; // x0
  _QWORD *v22; // x8
  char *v23; // x10
  __int64 v24; // x9
  unsigned __int64 v25; // x27
  __int64 v26; // x22
  __int64 v27; // x19
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x9
  _QWORD *v31; // x0
  __int64 *v32; // x10
  _QWORD *v33; // x1
  _QWORD *v34; // x8
  unsigned int v35; // w19
  unsigned int v36; // w6
  __int64 v37; // x27
  __int64 v38; // x0
  int v39; // w8
  int v40; // w8
  __int64 v41; // x8
  unsigned int v42; // w9
  __int64 v43; // x9
  _QWORD *v44; // x12
  _QWORD *v45; // x11
  _QWORD *v46; // x13
  __int64 v47; // x8
  void *v48; // x0
  void **v49; // x1
  __int64 result; // x0
  int v51; // w6
  int v52; // w7
  _QWORD *v53; // x0
  __int64 v54; // x9
  __int64 v55; // x19
  bool v56; // cc
  _QWORD *v57; // x8
  __int64 v58; // x9
  _QWORD *v59; // x0
  __int64 v60; // x10
  _QWORD *v61; // x10
  __int64 v62; // x19
  __int64 v63; // x8
  __int64 v64; // x20
  _QWORD *v65; // x0
  _QWORD *v66; // x0
  __int64 v67; // x19
  unsigned __int64 StatusReg; // x19
  __int64 v69; // x20
  __int64 v70; // x0
  __int64 v71; // x8
  _QWORD *v72; // [xsp+20h] [xbp-10h]
  _QWORD *v73; // [xsp+28h] [xbp-8h]

  v5 = (__int64)&unk_393000;
  v9 = a1;
  v10 = (char *)&unk_393000;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v67 = a5;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_ver2_init",
      3835,
      "Enter");
    a5 = v67;
    if ( v9 )
      goto LABEL_4;
LABEL_114:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver2_init",
      3840,
      "Inval_prms soc_info:%pK hw_intf:%pK hw_info%pK",
      (const void *)v9,
      a2,
      a3);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver2_init",
      3841,
      "controller: %pK",
      (const void *)a4);
    return 4294967274LL;
  }
  if ( !a1 )
    goto LABEL_114;
LABEL_4:
  if ( !a2 || !a3 || !a4 )
    goto LABEL_114;
  v11 = a5;
  if ( mem_trace_en == 1 )
  {
    v12 = (_QWORD *)cam_mem_trace_alloc(128, 0xCC0u, 0, "cam_vfe_bus_ver2_init", 0xF06u);
    if ( !v12 )
      goto LABEL_116;
  }
  else
  {
    v12 = (_QWORD *)_kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
    if ( !v12 )
      goto LABEL_116;
  }
  while ( 1 )
  {
    if ( mem_trace_en == 1 )
      v13 = cam_mem_trace_alloc(42672, 0xCC0u, 0, "cam_vfe_bus_ver2_init", 0xF0Eu);
    else
      v13 = _kvmalloc_node_noprof(42672, 0, 3520, 0xFFFFFFFFLL);
    v14 = v13;
    if ( !v13 )
    {
      v71 = *(_QWORD *)(v5 + 3664);
      LODWORD(v5) = -12;
      if ( (v71 & 8) != 0 && !*((_DWORD *)v10 + 919) )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v71 & 8,
          4,
          "cam_vfe_bus_ver2_init",
          3856,
          "Failed to alloc for vfe_bus_priv");
      goto LABEL_122;
    }
    *v12 = v13;
    v10 = (char *)(v13 + 33512);
    *(_DWORD *)(v13 + 33616) = *((_DWORD *)a3 + 24);
    *(_DWORD *)(v13 + 33620) = *((_DWORD *)a3 + 530);
    *(_DWORD *)(v13 + 33624) = *((_DWORD *)a3 + 534);
    v15 = *((_DWORD *)a3 + 536);
    v16 = (_QWORD *)(v13 + 42600);
    *(_QWORD *)(v13 + 33584) = 0;
    *(_DWORD *)(v13 + 42664) = v15;
    *(_DWORD *)v13 = *(_DWORD *)(v9 + 20);
    if ( *(_DWORD *)(v9 + 480) )
      v17 = *(_QWORD *)(v9 + 288);
    else
      v17 = 0;
    *(_QWORD *)(v13 + 8) = v17;
    *(_QWORD *)(v13 + 16) = a2;
    *(_QWORD *)(v13 + 32) = a4;
    *(_QWORD *)(v13 + 40) = a3;
    *(_DWORD *)(v13 + 33592) = 0xFFFFFF;
    *(_BYTE *)(v13 + 33608) = 0;
    v18 = a3[2140];
    *(_BYTE *)(v13 + 33610) = 0;
    *(_BYTE *)(v13 + 33609) = v18;
    _mutex_init(v13 + 33536, "&bus_priv->common_data.bus_mutex", &cam_vfe_bus_ver2_init___key);
    v19 = cam_irq_controller_init("vfe_bus", *(_QWORD *)(v14 + 8), (unsigned int *)a3 + 6, (__int64 *)(v14 + 24));
    if ( v19 )
    {
      LODWORD(v5) = v19;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_ver2_init",
        3887,
        "cam_irq_controller_init failed");
      goto LABEL_110;
    }
    a4 = v14 + 42616;
    v72 = (_QWORD *)v11;
    v73 = v12;
    *v16 = v16;
    *(_QWORD *)(v14 + 42608) = v14 + 42600;
    *(_QWORD *)(v14 + 42616) = v14 + 42616;
    *(_QWORD *)(v14 + 42624) = v14 + 42616;
    *(_QWORD *)(v14 + 42632) = v14 + 42632;
    *(_QWORD *)(v14 + 42640) = v14 + 42632;
    if ( *(_DWORD *)(v14 + 33616) )
      break;
LABEL_33:
    v25 = 0;
    a2 = (char *)(a3 + 2024);
    v26 = 37400;
    v27 = 37312;
    v11 = 37288;
    _ReadStatusReg(SP_EL0);
    do
    {
      if ( mem_trace_en == 1 )
        v28 = cam_mem_trace_alloc(56, 0xCC0u, 0, "cam_vfe_bus_init_comp_grp", 0x7C4u);
      else
        v28 = _kvmalloc_node_noprof(56, 0, 3520, 0xFFFFFFFFLL);
      v29 = v28;
      if ( !v28 )
      {
        v5 = 4294967284LL;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver2_init",
          3908,
          "Init Comp Grp failed rc=%d",
          -12);
        if ( (int)v25 >= 1 )
        {
          v35 = v25 - 1;
LABEL_89:
          a3 = "cam_vfe_bus_deinit_comp_grp";
          v54 = v14 + 152LL * v35;
          v55 = v35 + 1LL;
          a4 = v54 + 37288;
          do
          {
            v57 = *(_QWORD **)(a4 + 32);
            *(_QWORD *)(a4 + 8) = 0;
            v58 = a4 + 24;
            *(_QWORD *)(a4 + 80) = 0;
            *(_QWORD *)(a4 + 88) = 0;
            v59 = *(_QWORD **)(a4 + 16);
            *(_QWORD *)(a4 + 104) = 0;
            *(_QWORD *)(a4 + 112) = 0;
            if ( a4 + 24 == *v57 && (v60 = *(_QWORD *)v58, v58 == *(_QWORD *)(*(_QWORD *)v58 + 8LL)) )
            {
              *(_QWORD *)(v60 + 8) = v57;
              *v57 = v60;
            }
            else
            {
              _list_del_entry_valid_or_report(a4 + 24);
              v59 = v61;
            }
            *(_QWORD *)(a4 + 24) = a4 + 24;
            *(_QWORD *)(a4 + 32) = v58;
            *(_DWORD *)a4 = 0;
            *(_QWORD *)(a4 + 16) = 0;
            if ( v59 )
            {
              if ( mem_trace_en == 1 )
                cam_mem_trace_free(v59, 0);
              else
                kvfree(v59);
            }
            else
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                8,
                1,
                "cam_vfe_bus_deinit_comp_grp",
                2037,
                "comp_grp_priv is NULL");
            }
            v56 = v55-- <= 1;
            a4 -= 152;
          }
          while ( !v56 );
        }
        v9 = *(unsigned int *)(v14 + 33616);
        goto LABEL_101;
      }
      v30 = v14 + v26;
      v31 = (_QWORD *)(v14 + v27);
      *(_QWORD *)(v30 - 96) = v29;
      *(_DWORD *)(v14 + v11) = 1;
      v32 = (__int64 *)(v14 + v26 - 88);
      *(_QWORD *)(v30 - 88) = v32;
      *(_QWORD *)(v30 - 80) = v14 + v27;
      *(_DWORD *)v29 = v25;
      *(_QWORD *)(v29 + 8) = v14;
      *(_QWORD *)(v29 + 16) = a2;
      *(_DWORD *)(v29 + 36) = 3;
      if ( v25 >= 6 )
      {
        v33 = *(_QWORD **)(v14 + 42624);
        if ( v31 != v33 && *v33 == a4 )
        {
          *(_QWORD *)(v14 + 42624) = v31;
          *v32 = a4;
          goto LABEL_45;
        }
      }
      else
      {
        v33 = *(_QWORD **)(v14 + 42608);
        if ( v31 != v33 && (_QWORD *)*v33 == v16 )
        {
          *(_QWORD *)(v14 + 42608) = v31;
          *v32 = (__int64)v16;
LABEL_45:
          *(_QWORD *)(v30 - 80) = v33;
          *v33 = v31;
          goto LABEL_46;
        }
      }
      _list_add_valid_or_report(v31);
LABEL_46:
      v34 = (_QWORD *)(v14 + v26);
      *(v34 - 4) = 0;
      *(v34 - 3) = 0;
      ++v25;
      v26 += 152;
      *(v34 - 1) = cam_vfe_bus_handle_comp_done_top_half;
      *v34 = 0;
      a2 += 8;
      v27 += 152;
      v11 += 152;
      *(v34 - 13) = *(_QWORD *)(v14 + 16);
    }
    while ( v25 != 12 );
    if ( !*(_DWORD *)(v14 + 33620) )
    {
LABEL_64:
      *(_DWORD *)(v14 + 33528) = 0;
      v43 = 0;
      v44 = &unk_393000;
      *(_QWORD *)v10 = v10;
      *(_QWORD *)(v14 + 33520) = v14 + 33512;
      v46 = v72;
      v45 = v73;
      do
      {
        v47 = v14 + v43;
        v48 = (void *)(v47 + 744);
        *(_QWORD *)(v47 + 744) = v47 + 744;
        *(_QWORD *)(v47 + 752) = v47 + 744;
        v49 = *(void ***)(v14 + 33520);
        if ( (void **)(v14 + v43 + 744) == v49 || *v49 != v10 )
        {
          _list_add_valid_or_report(v48);
        }
        else
        {
          *(_QWORD *)(v14 + 33520) = v48;
          *(_QWORD *)(v47 + 744) = v10;
          *(_QWORD *)(v47 + 752) = v49;
          *v49 = v48;
        }
        v43 += 128;
      }
      while ( v43 != 0x8000 );
      result = 0;
      v45[5] = cam_vfe_bus_acquire_vfe_out;
      v45[6] = &cam_vfe_bus_release_vfe_out;
      v45[7] = cam_vfe_bus_start_hw;
      v45[8] = cam_vfe_bus_stop_hw;
      v45[2] = cam_vfe_bus_init_hw;
      v45[3] = cam_vfe_bus_deinit_hw;
      v45[14] = cam_vfe_bus_ver2_handle_irq;
      v45[15] = 0;
      v45[11] = _cam_vfe_bus_process_cmd;
      *v46 = v45;
      if ( (v44[458] & 8) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v44[458] & 8LL,
          4,
          "cam_vfe_bus_ver2_init",
          3942,
          "Exit");
        return 0;
      }
      return result;
    }
    a4 = 0xFFFFFFFFLL;
    a2 = (char *)&_ksymtab_cam_cdm_detect_hang_error;
    v11 = 152;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v36 = *(_DWORD *)&a2[*((_QWORD *)a3 + 266) - 24];
      if ( v36 >= 0x17 )
        break;
      v37 = v14 + 39104 + 152LL * v36;
      if ( *(_DWORD *)(v37 + 8) || *(_QWORD *)(v37 + 24) )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_init_vfe_out_resource",
          2492,
          "Error. Looks like same resource is init again");
        v5 = 4294967282LL;
        goto LABEL_76;
      }
      if ( mem_trace_en == 1 )
      {
        v38 = cam_mem_trace_alloc(128, 0xCC0u, 0, "cam_vfe_bus_init_vfe_out_resource", 0x9C1u);
        if ( !v38 )
          goto LABEL_63;
      }
      else
      {
        v38 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
        if ( !v38 )
        {
LABEL_63:
          v5 = 4294967284LL;
          goto LABEL_76;
        }
      }
      *(_QWORD *)(v37 + 24) = v38;
      *(_DWORD *)v37 = 6;
      *(_DWORD *)(v37 + 8) = 1;
      *(_QWORD *)(v37 + 32) = v37 + 32;
      *(_QWORD *)(v37 + 40) = v37 + 32;
      v39 = *(_DWORD *)&a2[*((_QWORD *)a3 + 266) - 24];
      *(_QWORD *)(v38 + 8) = v14;
      *(_DWORD *)v38 = v39;
      *(_DWORD *)(v38 + 76) = *(_DWORD *)&a2[*((_QWORD *)a3 + 266) - 20];
      v40 = *(_DWORD *)&a2[*((_QWORD *)a3 + 266) - 16];
      *(_DWORD *)(v38 + 96) = 0;
      *(_DWORD *)(v38 + 80) = v40;
      *(_QWORD *)(v37 + 104) = cam_vfe_bus_process_cmd;
      *(_QWORD *)(v37 + 88) = cam_vfe_bus_start_vfe_out;
      *(_QWORD *)(v37 + 96) = cam_vfe_bus_stop_vfe_out;
      v41 = *(_QWORD *)(v14 + 16);
      *(_QWORD *)(v37 + 112) = &cam_vfe_bus_handle_vfe_out_done_top_half;
      *(_QWORD *)(v37 + 120) = cam_vfe_bus_handle_vfe_out_done_bottom_half;
      v42 = a4 + 2;
      a4 = (unsigned int)(a4 + 1);
      *(_QWORD *)(v37 + 16) = v41;
      *(_DWORD *)(v37 + 64) = 0;
      *(_DWORD *)(v38 + 112) = *(_DWORD *)&a2[*((_QWORD *)a3 + 266) - 12];
      *(_DWORD *)(v38 + 116) = *(_DWORD *)&a2[*((_QWORD *)a3 + 266) - 8];
      *(_DWORD *)(v38 + 120) = *(_DWORD *)&a2[*((_QWORD *)a3 + 266) - 4];
      LODWORD(v41) = *(_DWORD *)&a2[*((_QWORD *)a3 + 266)];
      a2 += 28;
      *(_DWORD *)(v38 + 124) = v41;
      if ( v42 >= *(_DWORD *)(v14 + 33620) )
        goto LABEL_64;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_init_vfe_out_resource",
      2484,
      "Init VFE Out failed, Invalid type=%d",
      v36);
    v5 = 4294967274LL;
LABEL_76:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver2_init",
      3917,
      "Init VFE Out failed rc=%d",
      v5);
    if ( (a4 & 0x80000000) != 0 )
    {
      v35 = 11;
      goto LABEL_89;
    }
    a3 = "cam_vfe_bus_deinit_vfe_out_resource";
    a2 = (char *)((unsigned int)a4 + 1LL);
    v35 = 11;
    v9 = v14 + 152LL * (unsigned int)a4 + 39112;
    while ( (unsigned int)a4 <= 0x17 )
    {
      if ( *(_DWORD *)v9 )
      {
        v53 = *(_QWORD **)(v9 + 16);
        *(_DWORD *)(v9 + 56) = 0;
        *(_DWORD *)v9 = 0;
        *(_QWORD *)(v9 + 80) = 0;
        *(_QWORD *)(v9 + 88) = 0;
        *(_QWORD *)(v9 + 104) = 0;
        *(_QWORD *)(v9 + 112) = 0;
        *(_QWORD *)(v9 + 24) = v9 + 24;
        *(_QWORD *)(v9 + 32) = v9 + 24;
        *(_QWORD *)(v9 + 8) = 0;
        *(_QWORD *)(v9 + 16) = 0;
        if ( v53 )
        {
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v53, 0);
          else
            kvfree(v53);
        }
      }
      else if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_deinit_vfe_out_resource",
          2543,
          "HW%d Res %d already deinitialized",
          v51,
          v52);
      }
      --a2;
      v9 -= 152LL;
      if ( !a2 )
        goto LABEL_89;
    }
LABEL_115:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v69 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_vfe_bus_ver2_init__alloc_tag;
    v70 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v69;
    v12 = (_QWORD *)v70;
    if ( !v70 )
    {
LABEL_116:
      result = 4294967284LL;
      if ( (*(_QWORD *)(v5 + 3664) & 8) != 0 && !*((_DWORD *)v10 + 919) )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          *(_QWORD *)(v5 + 3664) & 8LL,
          4,
          "cam_vfe_bus_ver2_init",
          3848,
          "Failed to alloc for vfe_bus");
        return 4294967284LL;
      }
      return result;
    }
  }
  v9 = 0;
  v20 = a3 + 104;
  v5 = 33640;
  v11 = 33720;
  a2 = (_BYTE *)&unk_8380;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( v9 == 25 )
      goto LABEL_115;
    if ( mem_trace_en == 1 )
    {
      v21 = cam_mem_trace_alloc(144, 0xCC0u, 0, "cam_vfe_bus_init_wm_resource", 0x5D6u);
      if ( !v21 )
        break;
      goto LABEL_27;
    }
    v21 = _kvmalloc_node_noprof(144, 0, 3520, 0xFFFFFFFFLL);
    if ( !v21 )
      break;
LABEL_27:
    v22 = (_QWORD *)(v14 + v11);
    v23 = &a2[v14];
    *(v22 - 8) = v21;
    v11 += 152;
    a2 += 152;
    *(_DWORD *)v21 = v9++;
    *(_QWORD *)(v21 + 8) = v14;
    *(_QWORD *)(v21 + 16) = v20;
    v20 += 80;
    *(_DWORD *)(v14 + v5) = 1;
    v5 += 152;
    *(v22 - 7) = v22 - 7;
    *(v22 - 6) = v23;
    *v22 = 0;
    v22[1] = 0;
    v24 = *(_QWORD *)(v14 + 16);
    v22[3] = cam_vfe_bus_handle_wm_done_top_half;
    v22[4] = cam_vfe_bus_handle_wm_done_bottom_half;
    *(v22 - 9) = v24;
    if ( v9 >= *(unsigned int *)(v14 + 33616) )
      goto LABEL_33;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_init_wm_resource",
      1496,
      "Failed to alloc for WM res priv");
  v5 = 4294967284LL;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_bus_ver2_init",
    3899,
    "Init WM failed rc=%d",
    -12);
LABEL_101:
  v62 = (unsigned int)(v9 - 1);
  if ( (int)v9 - 1 >= 0 )
  {
    v63 = v14 + 152LL * (unsigned int)v62;
    v64 = v62 + 1;
    v10 = (char *)(v63 + 33640);
    while ( (unsigned int)v62 <= 0x18 )
    {
      *(_DWORD *)v10 = 0;
      *((_QWORD *)v10 + 3) = v10 + 24;
      *((_QWORD *)v10 + 4) = v10 + 24;
      v65 = *((_QWORD **)v10 + 2);
      *((_QWORD *)v10 + 10) = 0;
      *((_QWORD *)v10 + 11) = 0;
      *((_QWORD *)v10 + 13) = 0;
      *((_QWORD *)v10 + 14) = 0;
      *((_QWORD *)v10 + 1) = 0;
      *((_QWORD *)v10 + 2) = 0;
      if ( v65 )
      {
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v65, 0);
        else
          kvfree(v65);
      }
      --v64;
      v10 -= 152;
      if ( !v64 )
        goto LABEL_109;
    }
    goto LABEL_115;
  }
LABEL_109:
  v12 = v73;
LABEL_110:
  v66 = (_QWORD *)*v12;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v66, 0);
  else
    kvfree(v66);
LABEL_122:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v12, 0);
  else
    kvfree(v12);
  return (unsigned int)v5;
}
