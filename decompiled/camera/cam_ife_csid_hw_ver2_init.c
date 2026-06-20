__int64 __fastcall cam_ife_csid_hw_ver2_init(_DWORD *a1, const void *a2, char a3)
{
  unsigned __int64 v3; // x21
  __int64 (__fastcall *v5)(_QWORD); // x8
  char *v6; // x23
  char v7; // w19
  unsigned int v8; // w0
  __int64 v9; // x6
  const char *v10; // x5
  unsigned int v11; // w19
  __int64 v12; // x4
  __int64 result; // x0
  unsigned __int64 v14; // x22
  __int64 v15; // x19
  char v16; // w8
  __int64 v17; // x8
  unsigned int inited; // w0
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x27
  int v22; // w0
  unsigned int v23; // w22
  __int64 v24; // x6
  const char *v25; // x5
  __int64 v26; // x4
  unsigned int v27; // w0
  const char *v28; // x5
  unsigned int v29; // w7
  __int64 v30; // x6
  __int64 v31; // x4
  unsigned int v32; // w0
  _DWORD *v33; // x8
  unsigned int v34; // w0
  unsigned int v35; // w0
  unsigned int v36; // w0
  __int64 v37; // x26
  _DWORD *v38; // x8
  __int64 v39; // x0
  __int64 v40; // x8
  _QWORD *v41; // x9
  __int64 v42; // x28
  const char *v43; // x5
  __int64 v44; // x6
  __int64 v45; // x4
  unsigned int v46; // w0
  __int64 v47; // x21
  __int64 v48; // x0
  __int64 v49; // x24
  _QWORD *v50; // x27
  __int64 v51; // x0
  __int64 v52; // x8
  _QWORD *v53; // x9
  unsigned int v54; // w0
  __int64 v55; // x11
  __int64 v56; // x9
  __int64 *v57; // x10
  __int64 *v58; // x1
  __int64 *v59; // x10
  __int64 v60; // x11
  __int64 v61; // x9
  __int64 *v62; // x1
  __int64 v63; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v65; // x26
  char s[8]; // [xsp+20h] [xbp-20h] BYREF
  __int64 v67; // [xsp+28h] [xbp-18h]
  int v68; // [xsp+30h] [xbp-10h]
  __int64 v69; // [xsp+38h] [xbp-8h]

  v3 = (unsigned __int64)a2;
  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_hw_ver2_init",
      9701,
      "Invalid parameters intf: %pK hw_info: %pK",
      a1,
      a2);
    result = 4294967274LL;
    goto LABEL_46;
  }
  if ( !*(_QWORD *)a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_hw_ver2_init",
      9709,
      "No register description available");
    result = 4294967274LL;
    goto LABEL_46;
  }
  v5 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)a2 + 248LL);
  v6 = *((char **)a1 + 14);
  if ( v5 )
  {
    v7 = a3;
    if ( *((_DWORD *)v5 - 1) != -1066802076 )
      __break(0x8228u);
    v8 = v5(a2);
    if ( v8 )
    {
      v9 = (unsigned int)a1[1];
      v10 = "CSID [%u] override failed";
      v11 = v8;
      v12 = 9716;
LABEL_31:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_hw_ver2_init",
        v12,
        v10,
        v9);
      result = v11;
      goto LABEL_46;
    }
    a3 = v7;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_hw_ver2_init",
        9720,
        "CSID [%u] override called",
        a1[1]);
      a3 = v7;
    }
  }
  LOBYTE(v14) = a3;
  if ( mem_trace_en != 1 )
  {
    v15 = _kvmalloc_node_noprof(32264, 0, 3520, 0xFFFFFFFFLL);
    if ( v15 )
      goto LABEL_16;
LABEL_28:
    v24 = (unsigned int)a1[1];
    v25 = "Csid core %d hw allocation fails";
    v26 = 9727;
    goto LABEL_29;
  }
  v15 = cam_mem_trace_alloc(32264, 0xCC0u, 0, "cam_ife_csid_hw_ver2_init", 0x25FBu);
  if ( !v15 )
    goto LABEL_28;
  while ( 1 )
  {
LABEL_16:
    *((_QWORD *)v6 + 460) = v15;
    v16 = debug_mdl;
    *(_QWORD *)(v15 + 31120) = a1;
    *(_QWORD *)(v15 + 31128) = v6;
    *(_QWORD *)(v15 + 31136) = v3;
    if ( (v16 & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v16 & 8,
        4,
        "cam_ife_csid_hw_ver2_init",
        9737,
        "type %d index %d",
        *a1,
        a1[1]);
      v6 = *(char **)(v15 + 31128);
    }
    *(_BYTE *)(v15 + 2148) = 0;
    *((_DWORD *)v6 + 23) = 0;
    _mutex_init(*(_QWORD *)(v15 + 31128), "&csid_hw->hw_info->hw_mutex", &cam_ife_csid_hw_ver2_init___key);
    *(_DWORD *)(*(_QWORD *)(v15 + 31128) + 48LL) = 0;
    v17 = *(_QWORD *)(v15 + 31128);
    *(_DWORD *)(v15 + 30968) = 0;
    *(_DWORD *)(v17 + 56) = 0;
    _init_swait_queue_head(v17 + 64, "&x->wait", &init_completion___key_5);
    *(_DWORD *)(v15 + 32248) = 0;
    inited = cam_ife_csid_init_soc_resources(
               *(_QWORD *)(v15 + 31128) + 96LL,
               (__int64)cam_ife_csid_irq_0,
               (__int64)cam_ife_csid_ver2_cpas_cb,
               v15,
               v14 & 1);
    if ( (inited & 0x80000000) != 0 )
    {
      v9 = (unsigned int)a1[1];
      v10 = "CSID:%u Failed to init_soc";
      v11 = inited;
      v12 = 9751;
      goto LABEL_31;
    }
    if ( (((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))cam_cpas_is_feature_supported)(0, 0, 0) & 1) != 0 )
      *(_BYTE *)(v15 + 2149) = 1;
    if ( (cam_cpas_query_domain_id_security_support() & 1) != 0 )
      *(_BYTE *)(v15 + 2162) = 1;
    *(_QWORD *)(*(_QWORD *)(v15 + 31120) + 8LL) = cam_ife_csid_ver2_get_hw_caps;
    v19 = *(_QWORD *)(v15 + 31120);
    *(_QWORD *)s = 0;
    v67 = 0;
    *(_QWORD *)(v19 + 16) = &cam_ife_csid_ver2_init_hw;
    v20 = *(_QWORD *)(v15 + 31120);
    v68 = 0;
    *(_QWORD *)(v20 + 24) = cam_ife_csid_ver2_deinit_hw;
    *(_QWORD *)(*(_QWORD *)(v15 + 31120) + 32LL) = cam_ife_csid_ver2_reset;
    *(_QWORD *)(*(_QWORD *)(v15 + 31120) + 40LL) = cam_ife_csid_ver2_reserve;
    *(_QWORD *)(*(_QWORD *)(v15 + 31120) + 48LL) = cam_ife_csid_ver2_release;
    *(_QWORD *)(*(_QWORD *)(v15 + 31120) + 56LL) = &cam_ife_csid_ver2_start;
    *(_QWORD *)(*(_QWORD *)(v15 + 31120) + 64LL) = cam_ife_csid_ver2_stop;
    *(_QWORD *)(*(_QWORD *)(v15 + 31120) + 72LL) = cam_ife_csid_ver2_read;
    *(_QWORD *)(*(_QWORD *)(v15 + 31120) + 80LL) = cam_ife_csid_ver2_write;
    *(_QWORD *)(*(_QWORD *)(v15 + 31120) + 88LL) = cam_ife_csid_ver2_process_cmd;
    *(_QWORD *)(*(_QWORD *)(v15 + 31120) + 104LL) = cam_ife_csid_ver2_irq_line_test;
    v21 = **(_QWORD **)(v15 + 31136);
    v3 = *(_QWORD *)(*(_QWORD *)(v15 + 31128) + 384LL);
    if ( !*(_DWORD *)(v21 + 656) )
      goto LABEL_38;
    v6 = (char *)cam_ife_csid_ver2_top_reg_name;
    LOBYTE(v14) = 8;
    snprintf(s, 0x14u, "csid%d_%s", *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL), cam_ife_csid_ver2_top_reg_name[0]);
    v22 = cam_irq_controller_init(s, v3, *(unsigned int **)v21, (__int64 *)(v15 + 30984));
    if ( v22 )
      goto LABEL_26;
    if ( *(_DWORD *)(v21 + 656) < 2u )
      goto LABEL_38;
    v6 = (char *)off_30090;
    snprintf(s, 0x14u, "csid%d_%s", *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL), off_30090[0]);
    v22 = cam_irq_controller_init(s, v3, (unsigned int *)(*(_QWORD *)v21 + 32LL), (__int64 *)(v15 + 30992));
    if ( v22 )
    {
LABEL_26:
      v23 = v22;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_hw_init_irq",
        9539,
        "CSID:%u Failed to init CSID %s irq controller rc = %d",
        *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL),
        *(const char **)v6,
        v22);
      goto LABEL_45;
    }
    if ( *(_DWORD *)(v21 + 656) <= 2u )
    {
LABEL_38:
      if ( !*(_DWORD *)(v21 + 660) )
        break;
      LOBYTE(v14) = 24;
      snprintf(s, 0x14u, "csid%d_%s", *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL), cam_ife_csid_ver2_rx_reg_name[0]);
      v27 = cam_irq_controller_init(s, v3, *(unsigned int **)(v21 + 8), (__int64 *)(v15 + 31000));
      if ( v27 )
        goto LABEL_37;
      if ( *(_DWORD *)(v21 + 660) < 2u )
        break;
      snprintf(s, 0x14u, "csid%d_%s", *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL), off_300A0);
      v27 = cam_irq_controller_init(s, v3, (unsigned int *)(*(_QWORD *)(v21 + 8) + 32LL), (__int64 *)(v15 + 31008));
      if ( v27 )
      {
LABEL_37:
        v28 = "CSID:%u Failed to init CSID rx irq controller rc = %d";
        v29 = v27;
        v30 = *(unsigned int *)(*(_QWORD *)(v15 + 31120) + 4LL);
        v31 = 9552;
LABEL_43:
        v23 = v29;
        goto LABEL_44;
      }
      if ( *(_DWORD *)(v21 + 660) <= 2u )
        break;
    }
LABEL_123:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v65 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_ife_csid_hw_ver2_init__alloc_tag;
    v15 = _kvmalloc_node_noprof(32264, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v65;
    if ( !v15 )
      goto LABEL_28;
  }
  snprintf(s, 0x14u, "csid%d_buf_done", *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL));
  v32 = cam_irq_controller_init(s, v3, *(unsigned int **)(v21 + 16), (__int64 *)(v15 + 31112));
  if ( v32 )
  {
    v28 = "CSID:%u Failed to init CSID buf_done irq controller rc = %d";
    v29 = v32;
    v30 = *(unsigned int *)(*(_QWORD *)(v15 + 31120) + 4LL);
    v31 = 9562;
    goto LABEL_43;
  }
  v33 = *(_DWORD **)(v21 + 120);
  if ( !v33[126] )
    goto LABEL_127;
  snprintf(s, 0x14u, "csid%d_ipp%d", *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL), 0);
  v34 = cam_irq_controller_init(s, v3, *(unsigned int **)(v21 + 64), (__int64 *)(v15 + 31056));
  if ( v34 )
  {
    v23 = v34;
LABEL_50:
    v28 = "CSID:%u Failed to init CSID ipp%d irq controller rc = %d";
    v30 = *(unsigned int *)(*(_QWORD *)(v15 + 31120) + 4LL);
    v31 = 9597;
    goto LABEL_44;
  }
  v33 = *(_DWORD **)(v21 + 120);
  if ( v33[126] < 2u )
    goto LABEL_127;
  snprintf(s, 0x14u, "csid%d_ipp%d", *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL), 1);
  v35 = cam_irq_controller_init(s, v3, *(unsigned int **)(v21 + 104), (__int64 *)(v15 + 31096));
  if ( v35 )
  {
    v23 = v35;
    goto LABEL_50;
  }
  v33 = *(_DWORD **)(v21 + 120);
  if ( v33[126] < 3u )
    goto LABEL_127;
  snprintf(s, 0x14u, "csid%d_ipp%d", *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL), 2);
  v36 = cam_irq_controller_init(s, v3, *(unsigned int **)(v21 + 112), (__int64 *)(v15 + 31104));
  if ( v36 )
  {
    v23 = v36;
    goto LABEL_50;
  }
  v33 = *(_DWORD **)(v21 + 120);
  if ( v33[126] > 3u )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_hw_init_irq",
      9584,
      "CSID: %d Invalid res_id idx:%d",
      *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL),
      3);
    cam_ife_csid_hw_deinit_irq(v15);
  }
  else
  {
LABEL_127:
    if ( v33[127] )
    {
      snprintf(s, 0x14u, "csid%d_ppp", *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL));
      v46 = cam_irq_controller_init(s, v3, *(unsigned int **)(v21 + 72), (__int64 *)(v15 + 31064));
      if ( v46 )
      {
        v28 = "CSID:%u Failed to init CSID ppp irq controller rc = %d";
        v29 = v46;
        v30 = *(unsigned int *)(*(_QWORD *)(v15 + 31120) + 4LL);
        v31 = 9611;
        goto LABEL_43;
      }
      v33 = *(_DWORD **)(v21 + 120);
    }
    if ( v33[125] )
    {
      v14 = 0;
      v6 = (char *)(v15 + 31016);
      while ( 1 )
      {
        snprintf(s, 0x14u, "csid%d_rdi%d", *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL), v14);
        if ( v14 == 12 )
          goto LABEL_123;
        v54 = cam_irq_controller_init(s, v3, *(unsigned int **)(v21 + 24 + 8 * v14), (__int64 *)v6);
        if ( v54 )
          break;
        ++v14;
        v6 += 8;
        if ( v14 >= *(unsigned int *)(*(_QWORD *)(v21 + 120) + 500LL) )
          goto LABEL_95;
      }
      v28 = "CSID:%u Failed to init CSID rdi%d irq controller rc = %d";
      v30 = *(unsigned int *)(*(_QWORD *)(v15 + 31120) + 4LL);
      v31 = 9625;
      v23 = v54;
LABEL_44:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_hw_init_irq",
        v31,
        v28,
        v30);
LABEL_45:
      cam_ife_csid_hw_deinit_irq(v15);
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_hw_ver2_init",
        9779,
        "Failed to init CSID irq");
      result = v23;
      goto LABEL_46;
    }
LABEL_95:
    v55 = 256;
    *(_DWORD *)(v15 + 30972) = 0;
    v56 = v15 + 30952;
    v57 = (__int64 *)(v15 + 16600);
    *(_QWORD *)(v15 + 30952) = v15 + 30952;
    *(_QWORD *)(v15 + 30960) = v15 + 30952;
    do
    {
      *v57 = (__int64)v57;
      v57[1] = (__int64)v57;
      v58 = *(__int64 **)(v15 + 30960);
      if ( v57 == v58 || *v58 != v56 )
      {
        _list_add_valid_or_report(v57);
      }
      else
      {
        *(_QWORD *)(v15 + 30960) = v57;
        *v57 = v56;
        v57[1] = (__int64)v58;
        *v58 = (__int64)v57;
      }
      --v55;
      v57 += 7;
    }
    while ( v55 );
    v59 = (__int64 *)(v15 + 2264);
    v60 = 256;
    v61 = v15 + 30936;
    *(_DWORD *)(v15 + 30976) = 0;
    *(_QWORD *)(v15 + 30936) = v15 + 30936;
    *(_QWORD *)(v15 + 30944) = v15 + 30936;
    do
    {
      *v59 = (__int64)v59;
      v59[1] = (__int64)v59;
      v62 = *(__int64 **)(v15 + 30944);
      if ( v59 == v62 || *v62 != v61 )
      {
        _list_add_valid_or_report(v59);
      }
      else
      {
        *(_QWORD *)(v15 + 30944) = v59;
        *v59 = v61;
        v59[1] = (__int64)v62;
        *v62 = (__int64)v59;
      }
      --v60;
      v59 += 7;
    }
    while ( v60 );
  }
  v37 = **(_QWORD **)(v15 + 31136);
  v38 = *(_DWORD **)(v37 + 120);
  if ( !v38[126] )
  {
LABEL_73:
    if ( v38[127] )
    {
      v47 = *(_QWORD *)(v15 + 31120);
      if ( mem_trace_en == 1 )
      {
        v48 = cam_mem_trace_alloc(272, 0xCC0u, 0, "cam_ife_ver2_hw_alloc_res", 0x247Fu);
        if ( !v48 )
          goto LABEL_121;
      }
      else
      {
        v48 = _kvmalloc_node_noprof(272, 0, 3520, 0xFFFFFFFFLL);
        if ( !v48 )
        {
LABEL_121:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_csid_ver2_hw_init_path_res",
            9421,
            "CSID: %u PPP res init fail",
            *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL));
          goto LABEL_122;
        }
      }
      *(_QWORD *)(v15 + 928) = v47;
      *(_DWORD *)(v15 + 920) = 1;
      *(_QWORD *)(v15 + 912) = 0x600000003LL;
      *(_QWORD *)(v15 + 936) = v48;
      *(_QWORD *)(v48 + 264) = *(_QWORD *)(v37 + 184);
      scnprintf(v15 + 1040, 16, "PPP");
      v38 = *(_DWORD **)(v37 + 120);
    }
    if ( v38[125] )
    {
      v49 = 0;
      v3 = 0;
      v50 = (_QWORD *)(v37 + 136);
      v6 = "RDI_%d";
      _ReadStatusReg(SP_EL0);
      while ( v49 != 1976 )
      {
        v14 = *(_QWORD *)(v15 + 31120);
        if ( mem_trace_en == 1 )
        {
          v51 = cam_mem_trace_alloc(272, 0xCC0u, 0, "cam_ife_ver2_hw_alloc_res", 0x247Fu);
          if ( !v51 )
            goto LABEL_88;
        }
        else
        {
          v51 = _kvmalloc_node_noprof(272, 0, 3520, 0xFFFFFFFFLL);
          if ( !v51 )
          {
LABEL_88:
            v43 = "CSID: %u RDI[%d] res init fail";
            v44 = *(unsigned int *)(*(_QWORD *)(v15 + 31120) + 4LL);
            v45 = 9443;
            goto LABEL_117;
          }
        }
        v52 = v15 + v49;
        *(_DWORD *)v52 = 3;
        *(_DWORD *)(v52 + 4) = v3;
        *(_DWORD *)(v52 + 8) = 1;
        v53 = (_QWORD *)(v37 + 640);
        *(_QWORD *)(v52 + 16) = v14;
        *(_QWORD *)(v52 + 24) = v51;
        if ( (*(_BYTE *)(v37 + 666) & 1) == 0 )
        {
          v53 = v50;
          if ( v49 == 1824 )
            goto LABEL_123;
        }
        *(_QWORD *)(v51 + 264) = *v53;
        scnprintf(v52 + 128, 16, "RDI_%d", v3);
        v38 = *(_DWORD **)(v37 + 120);
        ++v3;
        ++v50;
        v49 += 152;
        if ( v3 >= (unsigned int)v38[125] )
          goto LABEL_109;
      }
    }
    else
    {
LABEL_109:
      if ( !v38[124] )
      {
LABEL_119:
        result = 0;
        *(_DWORD *)(v15 + 2168) = 0;
        *(_DWORD *)(v15 + 2136) = 0;
        *(_BYTE *)(v15 + 2214) = 0;
        *(_DWORD *)(v15 + 2208) = 0;
        goto LABEL_46;
      }
      v3 = 0;
      v14 = v15 + 1192;
      _ReadStatusReg(SP_EL0);
      while ( v3 != 6 )
      {
        v6 = *(char **)(v15 + 31120);
        if ( mem_trace_en == 1 )
        {
          v63 = cam_mem_trace_alloc(272, 0xCC0u, 0, "cam_ife_ver2_hw_alloc_res", 0x247Fu);
          if ( !v63 )
            goto LABEL_116;
        }
        else
        {
          v63 = _kvmalloc_node_noprof(272, 0, 3520, 0xFFFFFFFFLL);
          if ( !v63 )
          {
LABEL_116:
            v43 = "CSID: %u UDI[%d] res init fail";
            v44 = *(unsigned int *)(*(_QWORD *)(v15 + 31120) + 4LL);
            v45 = 9467;
            goto LABEL_117;
          }
        }
        *(_QWORD *)(v14 - 112) = v6;
        *(_QWORD *)(v14 - 104) = v63;
        *(_DWORD *)(v14 - 128) = 3;
        *(_DWORD *)(v14 - 124) = v3 + 7;
        *(_DWORD *)(v14 - 120) = 1;
        scnprintf(v14, 16, "UDI_%d", v3++);
        v14 += 152LL;
        if ( v3 >= *(unsigned int *)(*(_QWORD *)(v37 + 120) + 496LL) )
          goto LABEL_119;
      }
    }
    goto LABEL_123;
  }
  v3 = 0;
  v6 = "IPP_%d";
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (unsigned int)v3 > 2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_hw_init_path_res",
        9388,
        "CSID: %d Invalid res_id idx:%d",
        *(_DWORD *)(*(_QWORD *)(v15 + 31120) + 4LL),
        v3);
      cam_ife_csid_ver2_free_res(v15);
      goto LABEL_119;
    }
    v14 = dword_44C5CC[v3];
    v42 = *(_QWORD *)(v15 + 31120);
    if ( mem_trace_en != 1 )
      break;
    v39 = cam_mem_trace_alloc(272, 0xCC0u, 0, "cam_ife_ver2_hw_alloc_res", 0x247Fu);
    if ( !v39 )
      goto LABEL_69;
LABEL_62:
    v40 = v15 + 152LL * (unsigned int)v14;
    *(_DWORD *)v40 = 3;
    *(_DWORD *)(v40 + 4) = v14;
    *(_DWORD *)(v40 + 8) = 1;
    *(_QWORD *)(v40 + 16) = v42;
    *(_QWORD *)(v40 + 24) = v39;
    if ( *(_BYTE *)(v37 + 666) )
      v41 = (_QWORD *)(v37 + 632);
    else
      v41 = (_QWORD *)(v37 + 136 + 8 * v14);
    *(_QWORD *)(v39 + 264) = *v41;
    scnprintf(v40 + 128, 16, "IPP_%d", (unsigned int)v3);
    v38 = *(_DWORD **)(v37 + 120);
    if ( (unsigned int)++v3 >= v38[126] )
      goto LABEL_73;
  }
  v39 = _kvmalloc_node_noprof(272, 0, 3520, 0xFFFFFFFFLL);
  if ( v39 )
    goto LABEL_62;
LABEL_69:
  v43 = "CSID: %d IPP_%d res init fail";
  v44 = *(unsigned int *)(*(_QWORD *)(v15 + 31120) + 4LL);
  v45 = 9397;
LABEL_117:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver2_hw_init_path_res",
    v45,
    v43,
    v44,
    (unsigned int)v3);
LABEL_122:
  cam_ife_csid_ver2_free_res(v15);
  v24 = (unsigned int)a1[1];
  v25 = "CSID[%u] Probe Init failed";
  v26 = 9787;
LABEL_29:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_hw_ver2_init",
    v26,
    v25,
    v24);
  result = 4294967284LL;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
