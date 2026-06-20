__int64 __fastcall cam_soc_util_request_platform_resource(__int64 a1, __int64 a2, _QWORD *a3)
{
  unsigned int v4; // w6
  __int64 v5; // x25
  __int64 v6; // x26
  __int64 v7; // x28
  __int64 v8; // x21
  __int64 *v9; // x8
  __int64 v10; // x23
  __int64 v11; // x22
  const char *v12; // x24
  __int64 v13; // x2
  __int64 v14; // x0
  __int64 v15; // x8
  unsigned __int64 v16; // x10
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x27
  unsigned __int64 v19; // x24
  const char *v20; // x25
  __int64 v21; // x26
  unsigned __int64 v22; // x26
  unsigned int v23; // w23
  unsigned int v25; // w22
  int v26; // w0
  int v27; // w6
  __int64 v28; // x21
  __int64 v29; // x20
  unsigned int v30; // w20
  unsigned int v31; // w8
  unsigned int v32; // w22
  unsigned int v33; // w8
  __int64 v34; // x28
  __int64 v35; // x25
  __int64 v36; // x26
  __int64 v37; // x22
  __int64 v38; // x21
  __int64 *v39; // x20
  unsigned __int64 v40; // x23
  __int64 v41; // x21
  unsigned int v42; // w0
  unsigned int v43; // w21
  int v44; // w21
  const char *v45; // x22
  int v46; // w27
  _UNKNOWN **v47; // x25
  unsigned int v48; // w8
  int v49; // w9
  int v50; // w10
  unsigned int v51; // w0
  __int64 v52; // x0
  _QWORD *v53; // x26
  __int64 *v54; // x1
  __int64 v55; // x0
  _QWORD *v56; // x26
  unsigned int v57; // w0
  _UNKNOWN **v58; // x2
  _QWORD *v59; // x1
  int v60; // w8
  int v61; // w9
  unsigned int v62; // w0
  const char *v63; // x5
  __int64 v64; // x4
  unsigned int v65; // w0
  __int64 v66; // x22
  __int64 v67; // x0
  unsigned int v68; // w0
  const void *v69; // x0
  __int64 v70; // x24
  __int64 v71; // x21
  __int64 v72; // x8
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x21
  __int64 v76; // x22
  __int64 v77; // x0
  unsigned __int64 v78; // x21
  __int64 v79; // x25
  __int64 v80; // x24
  __int64 v81; // x26
  __int64 v82; // x27
  __int64 v83; // x8
  __int64 v84; // x6
  __int64 v85; // x7
  const char *v86; // x5
  __int64 v87; // x4
  _QWORD *v88; // [xsp+30h] [xbp-60h]
  __int64 v89; // [xsp+50h] [xbp-40h]
  __int64 v92; // [xsp+68h] [xbp-28h] BYREF
  __int64 v93; // [xsp+70h] [xbp-20h]
  __int64 v94; // [xsp+78h] [xbp-18h] BYREF
  __int64 v95; // [xsp+80h] [xbp-10h]
  __int64 v96; // [xsp+88h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !*(_QWORD *)(a1 + 8) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_request_platform_resource",
      4389,
      "Invalid parameters");
LABEL_29:
    v23 = -22;
    goto LABEL_30;
  }
  v4 = *(_DWORD *)(a1 + 104);
  if ( v4 > 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_request_platform_resource",
      4395,
      "Invalid irq count: %u Max IRQ per device: %d",
      v4,
      2);
    goto LABEL_29;
  }
  if ( *(_DWORD *)(a1 + 120) )
  {
    v5 = 0;
    v6 = 48;
    v7 = 128;
    while ( 1 )
    {
      if ( v5 == 192 )
        goto LABEL_180;
      v8 = a1 + v7;
      v9 = *(__int64 **)(a1 + v7 + 96);
      v10 = *v9;
      v11 = v9[1] - *v9;
      if ( *(_DWORD *)(a1 + 484) )
      {
        v12 = *(const char **)(a1 + v7);
        if ( !_request_region(&iomem_resource, v10, v11 + 1, v12, 0) )
          break;
      }
      if ( arm64_use_ng_mappings )
        v13 = 0x68000000000F13LL;
      else
        v13 = 0x68000000000713LL;
      v14 = ioremap_prot(v10, v11 + 1, v13);
      if ( !v14 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_get_mem_base",
          4241,
          "get mem base failed");
LABEL_37:
        v30 = v6 - 48;
        *(_QWORD *)(a1 + v5 + 288) = 0;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_request_platform_resource",
          4411,
          "i= %d base NULL",
          v6 - 48);
        v23 = -12;
        goto LABEL_159;
      }
      v15 = a1 + v5;
      v5 += 24;
      v7 += 8;
      *(_QWORD *)(v15 + 288) = v14;
      *(_DWORD *)(v15 + 296) = *(_DWORD *)(a1 + 4 * v6);
      v16 = v6 - 47;
      ++v6;
      *(_QWORD *)(v15 + 304) = *(_QWORD *)(*(_QWORD *)(v8 + 96) + 8LL) - **(_QWORD **)(v8 + 96) + 1LL;
      v17 = *(unsigned int *)(a1 + 120);
      ++*(_DWORD *)(a1 + 480);
      if ( v16 >= v17 )
        goto LABEL_14;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_mem_base",
      4233,
      "Error Mem region request Failed:%s",
      v12);
    goto LABEL_37;
  }
LABEL_14:
  if ( *(_DWORD *)(a1 + 488) )
  {
    v18 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      if ( v18 == 10 )
        goto LABEL_180;
      v19 = a1 + 8 * v18;
      v20 = *(const char **)(v19 + 496);
      if ( !v20 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_request_platform_resource",
          4427,
          "can't find regulator name");
        v23 = 0;
        goto LABEL_151;
      }
      v21 = *(_QWORD *)(a1 + 8);
      v94 = 0;
      v95 = 0;
      v92 = 0;
      v93 = 0;
      if ( (debug_bypass_drivers & 1) != 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x20000,
          2,
          "cam_wrapper_regulator_get",
          446,
          "Bypass regulator get");
        v22 = 3735928559LL;
      }
      else
      {
        if ( clk_rgltr_bus_ops_profiling == 1 )
          ktime_get_real_ts64(&v94);
        v22 = regulator_get(v21, v20);
        if ( clk_rgltr_bus_ops_profiling == 1 )
          ktime_get_real_ts64(&v92);
      }
      *(_QWORD *)(v19 + 744) = v22;
      if ( !v22 || v22 >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( (_DWORD)v22 )
          v23 = v22;
        else
          v23 = -22;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_get_regulator",
          3877,
          "Regulator %s get failed %d",
          v20,
          v23);
        *(_QWORD *)(v19 + 744) = 0;
        goto LABEL_151;
      }
      ++v18;
    }
    while ( v18 < *(unsigned int *)(a1 + 488) );
  }
  if ( *(_DWORD *)(a1 + 104) )
  {
    v25 = *(_DWORD *)(a1 + 80);
    v26 = devm_request_threaded_irq(*(_QWORD *)(a1 + 8), v25, a2, 0, 1, *(_QWORD *)(a1 + 40), *a3);
    if ( v26 )
    {
      v27 = v26;
      v28 = 0;
LABEL_34:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_request_irq",
        4264,
        "irq request fail rc %d",
        v27);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_request_platform_resource",
        4445,
        "irq request fail for irq name: %s dev: %s",
        *(const char **)(a1 + 40 + 8 * v28),
        *(const char **)(a1 + 24));
      v23 = -16;
      LODWORD(v29) = v28;
      goto LABEL_142;
    }
    disable_irq(v25);
    v31 = *(_DWORD *)(a1 + 104);
    *(_QWORD *)(a1 + 88) = *a3;
    if ( v31 >= 2 )
    {
      v32 = *(_DWORD *)(a1 + 84);
      v28 = 1;
      v27 = devm_request_threaded_irq(*(_QWORD *)(a1 + 8), v32, a2, 0, 1, *(_QWORD *)(a1 + 48), a3[1]);
      if ( v27 )
        goto LABEL_34;
      disable_irq(v32);
      v33 = *(_DWORD *)(a1 + 104);
      *(_QWORD *)(a1 + 96) = a3[1];
      if ( v33 > 2 )
        goto LABEL_180;
    }
  }
  if ( !*(_DWORD *)(a1 + 868) )
  {
    LODWORD(v34) = 0;
LABEL_118:
    if ( *(_BYTE *)(a1 + 3309) == 1 && (v62 = cam_soc_util_register_with_opp_framework(a1)) != 0 )
    {
      v23 = v62;
      v63 = "Failed in registering with OPP, rc: %d";
      v64 = 4540;
    }
    else
    {
      v65 = cam_soc_util_request_pinctrl(a1);
      if ( v65 )
      {
        v23 = v65;
        v63 = "Failed in requesting Pinctrl, rc: %d";
        v64 = 4547;
      }
      else
      {
        v68 = cam_soc_util_request_gpio_table(a1, 1);
        if ( !v68 )
        {
          if ( *(_BYTE *)(a1 + 3288) == 1 )
            cam_soc_util_create_clk_lvl_debugfs(a1);
          v23 = 0;
          goto LABEL_30;
        }
        v23 = v68;
        v63 = "Failed in request gpio table, rc=%d";
        v64 = 4553;
      }
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_request_platform_resource",
      v64,
      v63,
      v23);
    v69 = *(const void **)(a1 + 3192);
    if ( !v69 )
      goto LABEL_130;
LABEL_129:
    cam_soc_util_unregister_mmrm_client(v69);
    *(_QWORD *)(a1 + 3192) = 0;
    goto LABEL_130;
  }
  v34 = 0;
  v35 = a1 + 872;
  v36 = a1 + 2664;
  v88 = (_QWORD *)(a1 + 3192);
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( v34 == 32 )
      goto LABEL_180;
    v37 = *(_QWORD *)(a1 + 8);
    v38 = *(_QWORD *)(v35 + 8 * v34);
    v94 = 0;
    v95 = 0;
    v39 = (__int64 *)(a1 + 1128 + 8 * v34);
    v92 = 0;
    v93 = 0;
    if ( (debug_bypass_drivers & 4) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x20000,
        2,
        "cam_wrapper_clk_get",
        345,
        "Bypass clk get");
      *v39 = 3735928559LL;
      v40 = 3735928559LL;
    }
    else
    {
      if ( clk_rgltr_bus_ops_profiling == 1 )
        ktime_get_real_ts64(&v94);
      v40 = clk_get(v37, v38);
      if ( clk_rgltr_bus_ops_profiling == 1 )
        ktime_get_real_ts64(&v92);
      *v39 = v40;
      if ( v40 >= 0xFFFFFFFFFFFFF001LL )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_request_platform_resource",
          4460,
          "get failed for %s",
          *(const char **)(v35 + 8 * v34));
        v23 = -2;
        v69 = *(const void **)(a1 + 3192);
        if ( !v69 )
          goto LABEL_130;
        goto LABEL_129;
      }
      if ( !v40 )
      {
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20000,
            4,
            "cam_soc_util_request_platform_resource",
            4465,
            "%s handle is NULL skip get",
            *(const char **)(v35 + 8 * v34));
        goto LABEL_49;
      }
    }
    if ( (*(_DWORD *)(a1 + 2792) & (1 << v34)) != 0 )
    {
      v41 = *(unsigned int *)(a1 + 2872);
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_request_platform_resource",
          4476,
          "Dev %s, clk %s, id %d register wrapper entry for shared clk",
          *(const char **)(a1 + 24),
          *(const char **)(v35 + 8 * v34),
          *(_DWORD *)(v36 + 4 * v34));
        if ( (unsigned int)v41 > 9 )
          goto LABEL_180;
      }
      else if ( (unsigned int)v41 > 9 )
      {
        goto LABEL_180;
      }
      v42 = cam_soc_util_clk_wrapper_register_entry(
              *(_DWORD *)(v36 + 4 * v34),
              *v39,
              v34 == *(unsigned int *)(a1 + 2796),
              a1,
              (void *)*(int *)(a1 + 1384 + (v41 << 7) + 4 * v34),
              *(const char **)(v35 + 8 * v34));
      if ( v42 )
      {
        v84 = *(_QWORD *)(a1 + 24);
        v85 = *(unsigned int *)(v36 + 4 * v34);
        v23 = v42;
        v86 = "Failed in registering shared clk Dev %s id %d";
        v87 = 4487;
LABEL_166:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_request_platform_resource",
          v87,
          v86,
          v84,
          v85);
        v67 = *v39;
        goto LABEL_167;
      }
      goto LABEL_49;
    }
    if ( (*(_DWORD *)(a1 + 3568) & (1 << v34)) != 0 )
      break;
    if ( v34 == *(_DWORD *)(a1 + 2796) )
    {
      v51 = cam_soc_util_register_mmrm_client(
              *(_DWORD *)(v36 + 4 * v34),
              v40,
              *(_BYTE *)(a1 + 32),
              a1,
              *(const char **)(v35 + 8 * v34),
              v88);
      if ( v51 )
      {
        v84 = *(_QWORD *)(a1 + 24);
        v85 = *(unsigned int *)(v36 + 4 * v34);
        v23 = v51;
        v86 = "Failed in register mmrm client Dev %s clk id %d";
        v87 = 4527;
        goto LABEL_166;
      }
    }
LABEL_49:
    if ( ++v34 >= (unsigned __int64)*(unsigned int *)(a1 + 868) )
      goto LABEL_118;
  }
  v43 = *(_DWORD *)(a1 + 2872);
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_soc_util_request_platform_resource",
      4499,
      "Dev %s, clk %s, id %d register entry for aggregate clk",
      *(const char **)(a1 + 24),
      *(const char **)(v35 + 8 * v34),
      *(_DWORD *)(v36 + 4 * v34));
    v40 = *v39;
    if ( v43 > 9 )
      goto LABEL_180;
  }
  else if ( v43 > 9 )
  {
    goto LABEL_180;
  }
  v44 = *(_DWORD *)(v36 + 4 * v34);
  v45 = *(const char **)(v35 + 8 * v34);
  v89 = *(unsigned int *)(a1 + 2796);
  v46 = *(_DWORD *)(a1 + 3312 + 8 * v34 + 4);
  mutex_lock(&aggregate_lock);
  v47 = &aggregate_clk_list;
  v48 = debug_mdl;
  v49 = debug_priority;
  do
  {
    v47 = (_UNKNOWN **)*v47;
    v50 = (v49 == 0) & (v48 >> 17);
    if ( v47 == &aggregate_clk_list )
    {
      if ( v50 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          *(_QWORD *)&v48 & 0x20000LL,
          4,
          "cam_soc_util_clk_aggregate_register_entry",
          1084,
          "Adding new entry for aggregate clk, cmn clk id %d, client clk id %d, clk name %s",
          v46,
          v44,
          v45);
      if ( mem_trace_en == 1 )
        v52 = cam_mem_trace_alloc(224, 0xCC0u, 0, "cam_soc_util_clk_aggregate_register_entry", 0x43Du);
      else
        v52 = _kvmalloc_node_noprof(224, 0, 3520, 0xFFFFFFFFLL);
      v47 = (_UNKNOWN **)v52;
      if ( !v52 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_clk_aggregate_register_entry",
          1089,
          "Failed in allocating new clk entry %d",
          v44);
LABEL_175:
        v23 = -12;
        goto LABEL_124;
      }
      *(_DWORD *)(v52 + 216) = v46;
      *(_DWORD *)(v52 + 16) = -1;
      *(_QWORD *)(v52 + 24) = 0;
      *(_QWORD *)v52 = v52;
      *(_QWORD *)(v52 + 8) = v52;
      *(_QWORD *)(v52 + 32) = v52 + 32;
      *(_QWORD *)(v52 + 40) = v52 + 32;
      v54 = (__int64 *)off_3F40;
      if ( (_UNKNOWN **)v52 == &aggregate_clk_list
        || off_3F40 == (_UNKNOWN *)v52
        || *(_UNKNOWN ***)off_3F40 != &aggregate_clk_list )
      {
        _list_add_valid_or_report(v52);
      }
      else
      {
        off_3F40 = (_UNKNOWN *)v52;
        *(_QWORD *)v52 = &aggregate_clk_list;
        *(_QWORD *)(v52 + 8) = v54;
        *v54 = v52;
      }
LABEL_96:
      if ( mem_trace_en == 1 )
        v55 = cam_mem_trace_alloc(40, 0xCC0u, 0, "cam_soc_util_clk_aggregate_register_entry", 0x44Eu);
      else
        v55 = _kvmalloc_node_noprof(40, 0, 3520, 0xFFFFFFFFLL);
      v56 = (_QWORD *)v55;
      if ( !v55 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_clk_aggregate_register_entry",
          1105,
          "Failed in allocating new client entry %d for clk %s",
          v44,
          v45);
        goto LABEL_175;
      }
      *(_QWORD *)(v55 + 16) = a1;
      *(_QWORD *)(v55 + 24) = v40;
      if ( v34 == v89 && !*v88 )
      {
        v57 = cam_soc_util_register_mmrm_client(v44, v40, *(_BYTE *)(a1 + 32), a1, v45, v88);
        if ( v57 )
        {
          v23 = v57;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x20000,
            1,
            "cam_soc_util_clk_aggregate_register_entry",
            1119,
            "Failed in register mmrm client Dev %s clk id %d",
            *(const char **)(a1 + 24),
            v44);
          v66 = a1 + 2664;
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v56, 0);
          else
            kvfree(v56);
          goto LABEL_125;
        }
      }
      *v56 = v56;
      v58 = v47 + 4;
      v56[1] = v56;
      v59 = v47[5];
      if ( v56 == v47 + 4 || v59 == v56 || (_UNKNOWN **)*v59 != v58 )
      {
        _list_add_valid_or_report(v56);
      }
      else
      {
        v47[5] = v56;
        *v56 = v58;
        v56[1] = v59;
        *v59 = v56;
      }
      v60 = debug_mdl;
      v61 = *((_DWORD *)v47 + 12) + 1;
      *((_DWORD *)v47 + 12) = v61;
      if ( (v60 & 0x20000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          *(_QWORD *)&v60 & 0x20000LL,
          4,
          "cam_soc_util_clk_aggregate_register_entry",
          1132,
          "Adding new client %s for aggregate clk[%d], clk name: %s, clk id %d, num clients %d",
          *(const char **)(a1 + 24),
          v46,
          v45,
          v44,
          v61);
      mutex_unlock(&aggregate_lock);
      v36 = a1 + 2664;
      v35 = a1 + 872;
      goto LABEL_49;
    }
    if ( v50 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(_QWORD *)&v48 & 0x20000LL,
        4,
        "cam_soc_util_clk_aggregate_register_entry",
        1059,
        "Aggregate clk cmn clk id %d num clients %d",
        *((_DWORD *)v47 + 54),
        *((_DWORD *)v47 + 12));
      v48 = debug_mdl;
      v49 = debug_priority;
    }
  }
  while ( *((_DWORD *)v47 + 54) != v46 );
  v53 = v47 + 4;
  do
  {
    v53 = (_QWORD *)*v53;
    if ( v53 == v47 + 4 )
      goto LABEL_96;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_clk_aggregate_register_entry",
        1068,
        "Aggregate clk cmn clk id %d entry client %s",
        *((_DWORD *)v47 + 54),
        *(const char **)(v53[2] + 24LL));
  }
  while ( v53[2] != a1 );
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_soc_util_clk_aggregate_register_entry",
    1072,
    "Register with same soc info, cmn clk id %d, clk id %d, client %s",
    v46,
    v44,
    *(const char **)(a1 + 24));
  v23 = -22;
LABEL_124:
  v66 = a1 + 2664;
LABEL_125:
  mutex_unlock(&aggregate_lock);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_soc_util_request_platform_resource",
    4511,
    "Failed in registering aggregate clk Dev %s id %d",
    *(const char **)(a1 + 24),
    *(_DWORD *)(v66 + 4 * v34));
  v67 = *v39;
LABEL_167:
  cam_wrapper_clk_put(v67);
  *v39 = 0;
  v69 = *(const void **)(a1 + 3192);
  if ( v69 )
    goto LABEL_129;
LABEL_130:
  v29 = (unsigned int)(v34 - 1);
  if ( (int)v34 >= 1 )
  {
    v70 = v29 + 666;
    v71 = 8LL * (unsigned int)(v34 - 1) + 1128;
    while ( (unsigned int)v34 <= 0x20 )
    {
      if ( *(_QWORD *)(a1 + v71) )
      {
        if ( (*(_DWORD *)(a1 + 2792) & (1 << v29)) != 0 )
          cam_soc_util_clk_wrapper_unregister_entry(*(_DWORD *)(a1 + 4 * v70), (const char **)a1);
        if ( (*(_DWORD *)(a1 + 3568) & (1 << v29)) != 0 )
          cam_soc_util_clk_aggregate_unregister_entry(*(unsigned int *)(a1 + 4 * v70), a1, v29);
        cam_wrapper_clk_put(*(_QWORD *)(a1 + v71));
        *(_QWORD *)(a1 + v71) = 0;
      }
      v72 = v70 - 666;
      --v70;
      LODWORD(v29) = v29 - 1;
      v71 -= 8;
      if ( v72 <= 0 )
        goto LABEL_141;
    }
LABEL_180:
    __break(0x5512u);
  }
  if ( !(_DWORD)v34 )
LABEL_141:
    LODWORD(v29) = *(_DWORD *)(a1 + 104);
LABEL_142:
  LODWORD(v18) = v29 - 1;
  if ( (int)v29 - 1 < 0 )
  {
    if ( !(_DWORD)v29 )
      goto LABEL_150;
  }
  else
  {
    if ( (unsigned int)v18 > 1 )
      goto LABEL_180;
    v73 = *(unsigned int *)(a1 + 80 + 4LL * (unsigned int)v18);
    if ( (int)v73 >= 1 )
      disable_irq(v73);
    if ( (_DWORD)v29 == 2 )
    {
      v74 = *(unsigned int *)(a1 + 80);
      if ( (int)v74 >= 1 )
        disable_irq(v74);
    }
LABEL_150:
    LODWORD(v18) = *(_DWORD *)(a1 + 488);
  }
LABEL_151:
  v30 = v18 - 1;
  if ( (int)v18 - 1 >= 0 )
  {
    v75 = 8LL * (unsigned int)(v18 - 1);
    while ( v30 <= 9 )
    {
      v76 = a1 + v75;
      v77 = *(_QWORD *)(a1 + v75 + 744);
      if ( v77 )
      {
        cam_wrapper_regulator_disable(v77);
        cam_wrapper_regulator_put(*(_QWORD *)(v76 + 744), *(_QWORD *)(v76 + 496));
        *(_QWORD *)(v76 + 744) = 0;
      }
      v75 -= 8;
      if ( v75 == -8 )
        goto LABEL_158;
    }
    goto LABEL_180;
  }
  if ( !(_DWORD)v18 )
LABEL_158:
    v30 = *(_DWORD *)(a1 + 480);
LABEL_159:
  v78 = v30 - 1;
  if ( (int)(v30 - 1) >= 0 )
  {
    v79 = 38;
    v80 = a1 + 224 + 24LL * (unsigned int)v78;
    v81 = 36;
    do
    {
      if ( *(_DWORD *)(a1 + 484) )
      {
        if ( v78 > 7 )
          goto LABEL_180;
        _release_region(&iomem_resource);
      }
      else if ( v78 > 7 )
      {
        goto LABEL_180;
      }
      v82 = v80 + 8 * v81;
      iounmap(*(_QWORD *)(v82 - 224));
      v83 = v80 + 8 * v79;
      --v78;
      v79 -= 3;
      v81 -= 3;
      *(_QWORD *)(v82 - 224) = 0;
      *(_QWORD *)(v83 - 224) = 0;
    }
    while ( v78 != -1 );
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v23;
}
