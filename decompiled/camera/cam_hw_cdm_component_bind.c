__int64 __fastcall cam_hw_cdm_component_bind(__int64 a1)
{
  _DWORD *v2; // x19
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  unsigned int dt_properties; // w0
  __int64 v7; // x0
  unsigned __int8 *v8; // x26
  __int64 v9; // x21
  unsigned int v10; // w8
  unsigned int handle; // w0
  __int64 v12; // x26
  __int64 v13; // x25
  void *v14; // x23
  _DWORD *v15; // x27
  __int64 v16; // x21
  size_t v17; // x0
  unsigned __int64 v18; // x2
  int v19; // w0
  __int64 v20; // x3
  __int64 v21; // x0
  unsigned int v22; // w8
  unsigned int v23; // w0
  _QWORD *v24; // x0
  _QWORD *v25; // x0
  int v26; // w8
  __int64 result; // x0
  int v28; // w8
  const char *v29; // x22
  int v30; // w10
  unsigned int v31; // w0
  const char *v32; // x5
  __int64 v33; // x4
  unsigned int v34; // w0
  const char *v35; // x5
  __int64 v36; // x4
  unsigned int cdm_config; // w0
  __int64 v38; // x4
  __int64 v39; // x7
  unsigned int v40; // w0
  int v41; // w8
  int v42; // w8
  _UNKNOWN **ops; // x0
  _DWORD *v44; // [xsp+8h] [xbp-208h]
  __int64 v45; // [xsp+10h] [xbp-200h]
  unsigned int v46; // [xsp+1Ch] [xbp-1F4h]
  __int64 v47; // [xsp+20h] [xbp-1F0h]
  _QWORD v48[2]; // [xsp+28h] [xbp-1E8h] BYREF
  _QWORD v49[2]; // [xsp+38h] [xbp-1D8h] BYREF
  __int64 v50; // [xsp+48h] [xbp-1C8h] BYREF
  __int64 v51; // [xsp+50h] [xbp-1C0h]
  _QWORD v52[16]; // [xsp+58h] [xbp-1B8h] BYREF
  char s[8]; // [xsp+D8h] [xbp-138h] BYREF
  __int64 v54; // [xsp+E0h] [xbp-130h]
  __int64 v55; // [xsp+E8h] [xbp-128h]
  __int64 v56; // [xsp+F0h] [xbp-120h]
  __int64 v57; // [xsp+F8h] [xbp-118h]
  __int64 v58; // [xsp+100h] [xbp-110h]
  __int64 v59; // [xsp+108h] [xbp-108h]
  __int64 v60; // [xsp+110h] [xbp-100h]
  __int64 v61; // [xsp+118h] [xbp-F8h]
  __int64 v62; // [xsp+120h] [xbp-F0h]
  __int64 v63; // [xsp+128h] [xbp-E8h]
  __int64 v64; // [xsp+130h] [xbp-E0h]
  __int64 v65; // [xsp+138h] [xbp-D8h]
  __int64 v66; // [xsp+140h] [xbp-D0h]
  __int64 v67; // [xsp+148h] [xbp-C8h]
  __int64 v68; // [xsp+150h] [xbp-C0h]
  _QWORD v69[16]; // [xsp+158h] [xbp-B8h] BYREF
  __int64 v70; // [xsp+1D8h] [xbp-38h]
  __int64 v71; // [xsp+1E0h] [xbp-30h]
  _DWORD *v72; // [xsp+1E8h] [xbp-28h]
  __int64 (__fastcall *v73)(__int64, __int64, _DWORD *); // [xsp+1F0h] [xbp-20h]
  __int64 v74; // [xsp+1F8h] [xbp-18h]
  __int64 v75; // [xsp+200h] [xbp-10h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v73 = nullptr;
  v74 = 0;
  v71 = 0;
  v72 = nullptr;
  v70 = 0;
  memset(v69, 0, sizeof(v69));
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  *(_QWORD *)s = 0;
  v54 = 0;
  memset(v52, 0, sizeof(v52));
  v50 = 0;
  v51 = 0;
  v49[0] = 0;
  v49[1] = 0;
  v48[0] = 0;
  v48[1] = 0;
  ktime_get_real_ts64(v49);
  if ( mem_trace_en == 1 )
  {
    v2 = (_DWORD *)cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_hw_cdm_component_bind", 0x912u);
    if ( !v2 )
      goto LABEL_164;
  }
  else
  {
    v2 = (_DWORD *)_kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
    if ( !v2 )
    {
LABEL_164:
      result = 4294967284LL;
      goto LABEL_165;
    }
  }
  if ( mem_trace_en == 1 )
    v3 = cam_mem_trace_alloc(3688, 0xCC0u, 0, "cam_hw_cdm_component_bind", 0x916u);
  else
    v3 = _kvmalloc_node_noprof(3688, 0, 3520, 0xFFFFFFFFLL);
  v4 = v3;
  if ( !v3 )
  {
    if ( !mem_trace_en )
    {
LABEL_27:
      kvfree(v2);
      goto LABEL_164;
    }
LABEL_163:
    cam_mem_trace_free(v2, 0);
    goto LABEL_164;
  }
  if ( !mem_trace_en )
  {
    v7 = _kvmalloc_node_noprof(4880, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v4 + 3680) = v7;
    if ( v7 )
      goto LABEL_11;
LABEL_14:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v4, 0);
    else
      kvfree(v4);
    if ( mem_trace_en != 1 )
      goto LABEL_27;
    goto LABEL_163;
  }
  v5 = cam_mem_trace_alloc(4880, 0xCC0u, 0, "cam_hw_cdm_component_bind", 0x91Du);
  *(_QWORD *)(v4 + 3680) = v5;
  if ( !v5 )
    goto LABEL_14;
LABEL_11:
  *(_DWORD *)(v4 + 92) = 0;
  *(_QWORD *)(v4 + 96) = a1 - 16;
  *(_QWORD *)(v4 + 104) = a1;
  *(_QWORD *)(v4 + 120) = *(_QWORD *)(a1 - 16);
  *v2 = 1;
  *(_DWORD *)(v4 + 88) = 0;
  _mutex_init(v4, "&cdm_hw->hw_mutex", &cam_hw_cdm_component_bind___key);
  *(_DWORD *)(v4 + 48) = 0;
  *(_DWORD *)(v4 + 56) = 0;
  _init_swait_queue_head(v4 + 64, "&x->wait", &init_completion___key_3);
  dt_properties = cam_hw_cdm_soc_get_dt_properties(v4, (__int64)&msm_cam_hw_cdm_dt_match);
  if ( dt_properties )
  {
    v46 = dt_properties;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_component_bind",
      2354,
      "Failed to get dt properties");
LABEL_78:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v2, 0);
    else
      kvfree(v2);
    v25 = *(_QWORD **)(v4 + 3680);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v25, 0);
    else
      kvfree(v25);
    v26 = (unsigned __int8)mem_trace_en;
    *(_QWORD *)(v4 + 3680) = 0;
    if ( v26 == 1 )
      cam_mem_trace_free((_QWORD *)v4, 0);
    else
      kvfree(v4);
    result = v46;
    goto LABEL_165;
  }
  v2[1] = *(_DWORD *)(v4 + 116);
  v8 = *(unsigned __int8 **)(v4 + 3392);
  v9 = *(_QWORD *)(v4 + 3680);
  *(_DWORD *)(v9 + 136) = *v8 ^ 1;
  v47 = v9;
  if ( strnstr(v9 + 4, "qcom,cam170-cpas-cdm0", 21)
    || strnstr(v9 + 4, "qcom,cam-cpas-cdm1_0", 20)
    || strnstr(v9 + 4, "qcom,cam-cpas-cdm1_1", 20)
    || strnstr(v9 + 4, "qcom,cam-cpas-cdm1_2", 20) )
  {
    goto LABEL_20;
  }
  if ( strnstr(v9 + 4, "qcom,cam-ife-cdm1_2", 19) )
  {
    v10 = 3;
    goto LABEL_21;
  }
  if ( strnstr(v9 + 4, "qcom,cam-cpas-cdm2_0", 20) )
    goto LABEL_20;
  if ( strnstr(v9 + 4, "qcom,cam-ope-cdm2_0", 19) )
  {
    v10 = 5;
    goto LABEL_21;
  }
  if ( strnstr(v9 + 4, "qcom,cam-cpas-cdm2_1", 20) )
  {
LABEL_20:
    v10 = 2;
  }
  else if ( strnstr(v9 + 4, "qcom,cam-rt-cdm2_1", 18) )
  {
    v10 = 10;
  }
  else if ( strnstr(v9 + 4, "qcom,cam-ope-cdm2_1", 19) )
  {
    v10 = 5;
  }
  else if ( strnstr(v9 + 4, "qcom,cam-rt-cdm2_2", 18) )
  {
    v10 = 10;
  }
  else
  {
    v10 = 11;
  }
LABEL_21:
  *(_DWORD *)(v9 + 132) = v10;
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_component_bind",
      2368,
      "cdm_name %s",
      (const char *)(v9 + 4));
    if ( *(_DWORD *)(v9 + 132) >= 0xBu )
      goto LABEL_24;
  }
  else if ( v10 >= 0xB )
  {
LABEL_24:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_component_bind",
      2372,
      "Failed to get CDM HW name for %s",
      (const char *)(v9 + 4));
    v46 = 0;
LABEL_74:
    v24 = *(_QWORD **)(v4 + 3392);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v24, 0);
    else
      kvfree(v24);
    *(_QWORD *)(v4 + 3392) = 0;
    goto LABEL_78;
  }
  *(_DWORD *)(v9 + 144) = 0;
  _init_swait_queue_head(v9 + 152, "&x->wait", &init_completion___key_3);
  *((_QWORD *)v2 + 9) = 0;
  *((_QWORD *)v2 + 10) = 0;
  *((_QWORD *)v2 + 1) = cam_cdm_get_caps;
  *((_QWORD *)v2 + 2) = cam_hw_cdm_init;
  *((_QWORD *)v2 + 3) = cam_hw_cdm_deinit;
  *((_QWORD *)v2 + 7) = cam_cdm_stream_start;
  *((_QWORD *)v2 + 8) = cam_cdm_stream_stop;
  *((_QWORD *)v2 + 11) = cam_cdm_process_cmd;
  *((_QWORD *)v2 + 13) = cam_cdm_test_irq_line;
  *((_QWORD *)v2 + 14) = v4;
  mutex_lock(v4);
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_component_bind",
      2390,
      "type %d index %d",
      *v2,
      v2[1]);
  *(_QWORD *)(a1 + 152) = v2;
  snprintf(s, 0x80u, "%s", *(const char **)(v4 + 152));
  handle = cam_smmu_get_handle(s, (int *)(v9 + 224));
  if ( (handle & 0x80000000) != 0 )
  {
    if ( handle != -114 )
    {
      v46 = handle;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char *))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_component_bind",
        2401,
        "%s get iommu handle failed, rc = %d",
        s);
LABEL_73:
      mutex_unlock(v4);
      goto LABEL_74;
    }
    v44 = v8;
    v45 = v4 + 96;
    v46 = 0;
  }
  else
  {
    v44 = v8;
    v45 = v4 + 96;
    v46 = handle;
  }
  cam_smmu_set_client_page_fault_handler(*(_DWORD *)(v9 + 224), (__int64)cam_hw_cdm_iommu_fault_handler, v4);
  v12 = 0;
  v13 = 0;
  v14 = &init_completion___key_3;
  v15 = (_DWORD *)&unk_80;
  *(_DWORD *)(v9 + 228) = -1;
  do
  {
    v16 = v9 + v12;
    *(_QWORD *)(v16 + 2336) = v16 + 2336;
    *(_QWORD *)(v16 + 2344) = v16 + 2336;
    _mutex_init(v16 + 2352, "&cdm_core->bl_fifo[i].fifo_lock", &cam_hw_cdm_component_bind___key_177);
    *(_DWORD *)(v16 + 2296) = 0;
    _init_swait_queue_head(v16 + 2304, "&x->wait", &init_completion___key_3);
    *(_DWORD *)(v16 + 2928) = 0;
    memset((void *)(v16 + 2416), 0, 0x200u);
    v9 = *(_QWORD *)(v4 + 152);
    v17 = strnlen((const char *)v9, 0x80u);
    if ( v17 == -1 )
      goto LABEL_156;
    if ( v17 == 128 )
      v18 = 128;
    else
      v18 = v17 + 1;
    if ( v18 >= 0x81 )
      goto LABEL_157;
    v19 = sized_strscpy(v52, v9);
    v9 = v47;
    if ( (unsigned __int64)v19 > 0x80 )
      goto LABEL_158;
    snprintf((char *)v52 + v19, 128LL - v19, "%d_%d", *(_DWORD *)(v4 + 116), v13);
    v21 = alloc_workqueue(v52, 74, 5, v20);
    *(_QWORD *)(v47 + v12 + 2328) = v21;
    if ( !v21 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_component_bind",
        2430,
        "Workqueue allocation failed for FIFO %d, cdm %s",
        v13,
        (const char *)(v47 + 4));
      goto LABEL_57;
    }
    if ( (debug_mdl & 1) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_hw_cdm_component_bind",
        2434,
        "wq %s",
        (const char *)v52);
    ++v13;
    v12 += 640;
  }
  while ( v13 != 4 );
  v22 = *(_DWORD *)(v4 + 200);
  if ( !v22 )
  {
    LODWORD(v13) = 0;
    goto LABEL_69;
  }
  v50 = v4;
  if ( v22 == 1 )
  {
    LODWORD(v13) = 1;
    goto LABEL_69;
  }
  v51 = v4;
  if ( v22 > 2 )
    goto LABEL_158;
  LODWORD(v13) = 2;
LABEL_69:
  v12 = (__int64)v44;
  v14 = (void *)v45;
  v15 = &unk_393000;
  v23 = cam_soc_util_request_platform_resource(v45, (__int64)cam_hw_cdm_irq, &v50);
  if ( v23 )
  {
    v46 = v23;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_component_bind",
      2446,
      "Failed to request platform resource for %s%u",
      *(const char **)(v4 + 152),
      *(_DWORD *)(v4 + 116));
LABEL_71:
    cam_smmu_set_client_page_fault_handler(*(_DWORD *)(v9 + 224), 0, v4);
    if ( (unsigned int)cam_smmu_destroy_handle(*(_DWORD *)(v9 + 224)) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_component_bind",
        2571,
        "Release iommu secure hdl failed");
    goto LABEL_73;
  }
  v28 = *(_DWORD *)(v4 + 116);
  v73 = cam_cdm_cpas_cb;
  v29 = *(const char **)(v4 + 152);
  v30 = *(_DWORD *)(v4 + 116);
  *(_DWORD *)(v4 + 3400) = v28 + 13056;
  LODWORD(v70) = v30;
  v71 = a1;
  v72 = v2;
  v17 = strnlen(v29, 0x80u);
  if ( v17 == -1 )
  {
LABEL_156:
    _fortify_panic(2, -1, v17 + 1);
LABEL_157:
    _fortify_panic(7, 128, v18);
LABEL_158:
    __break(0x5512u);
    goto LABEL_159;
  }
  if ( v17 == 128 )
    v18 = 128;
  else
    v18 = v17 + 1;
  if ( v18 >= 0x81 )
    goto LABEL_157;
  sized_strscpy(v69, v29);
  v31 = cam_cpas_register_client((__int64)v69);
  if ( v31 )
  {
    v46 = v31;
    v32 = "Virtual CDM CPAS registration failed";
    v33 = 2466;
    goto LABEL_142;
  }
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_component_bind",
      2470,
      "CPAS registration successful handle=%d",
      v74);
  *(_DWORD *)(v47 + 4868) = v74;
  v34 = cam_cdm_util_cpas_start(v4);
  if ( v34 )
  {
    v46 = v34;
    v35 = "CPAS start failed";
    v36 = 2476;
    goto LABEL_139;
  }
  cdm_config = cam_hw_cdm_get_cdm_config(v4);
  if ( cdm_config )
  {
    v46 = cdm_config;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_component_bind",
      2483,
      "Failed to get cdm configuration rc = %d",
      cdm_config);
LABEL_137:
    if ( (unsigned int)cam_cpas_stop(*(_DWORD *)(v9 + 4868)) )
    {
      v35 = "CPAS stop failed";
      v36 = 2554;
LABEL_139:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_component_bind",
        v36,
        v35);
    }
LABEL_140:
    if ( (unsigned int)cam_cpas_unregister_client(*(_DWORD *)(v9 + 4868)) )
    {
      v32 = "CPAS unregister failed";
      v33 = 2558;
LABEL_142:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_component_bind",
        v33,
        v32);
    }
    if ( (unsigned int)cam_soc_util_release_platform_resource((__int64)v14) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_component_bind",
        2561,
        "Release platform resource failed");
LABEL_57:
    if ( (int)v13 >= 1 )
    {
      _flush_workqueue(*(_QWORD *)(v9 + 2328));
      destroy_workqueue(*(_QWORD *)(v9 + 2328));
      if ( (_DWORD)v13 != 1 )
      {
        _flush_workqueue(*(_QWORD *)(v9 + 2968));
        destroy_workqueue(*(_QWORD *)(v9 + 2968));
        if ( (_DWORD)v13 != 2 )
        {
          _flush_workqueue(*(_QWORD *)(v9 + 3608));
          destroy_workqueue(*(_QWORD *)(v9 + 3608));
          if ( (_DWORD)v13 != 3 )
          {
            _flush_workqueue(*(_QWORD *)(v9 + 4248));
            destroy_workqueue(*(_QWORD *)(v9 + 4248));
          }
        }
      }
    }
    goto LABEL_71;
  }
  if ( !(*(_DWORD *)(v47 + 216) >> 29) )
  {
    LODWORD(v9) = 64;
    *(_DWORD *)(v47 + 2404) = 64;
    if ( (debug_mdl & 1) == 0 || debug_priority )
    {
LABEL_105:
      *(_DWORD *)(v47 + 3044) = v9;
      if ( (debug_mdl & 1) != 0 && !v15[919] )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_hw_cdm_component_bind",
          2492,
          "Setting FIFO%d length to %d",
          1,
          64);
      *(_DWORD *)(v47 + 3684) = v9;
      if ( (debug_mdl & 1) != 0 && !v15[919] )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_hw_cdm_component_bind",
          2492,
          "Setting FIFO%d length to %d",
          2,
          64);
      *(_DWORD *)(v47 + 4324) = v9;
      v9 = v47;
      if ( (debug_mdl & 1) != 0 && !v15[919] )
      {
        v38 = 2492;
        v39 = 64;
LABEL_161:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
          3,
          1,
          4,
          "cam_hw_cdm_component_bind",
          v38,
          "Setting FIFO%d length to %d",
          3,
          v39);
        goto LABEL_125;
      }
      goto LABEL_125;
    }
LABEL_159:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_component_bind",
      2492,
      "Setting FIFO%d length to %d",
      0,
      64);
    goto LABEL_105;
  }
  *(_DWORD *)(v47 + 2404) = v44[1];
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_component_bind",
      2499,
      "Setting FIFO%d length to %d",
      0);
  *(_DWORD *)(v47 + 3044) = v44[2];
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_component_bind",
      2499,
      "Setting FIFO%d length to %d",
      1);
  *(_DWORD *)(v47 + 3684) = v44[3];
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_component_bind",
      2499,
      "Setting FIFO%d length to %d",
      2);
  v39 = (unsigned int)v44[4];
  *(_DWORD *)(v47 + 4324) = v39;
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    v38 = 2499;
    goto LABEL_161;
  }
LABEL_125:
  v40 = *(_DWORD *)(v9 + 216);
  v41 = *(_DWORD *)(v9 + 132);
  *(_QWORD *)(v9 + 4856) = 0;
  if ( v41 == 2 )
    v42 = 1;
  else
    v42 = 2;
  if ( !(v40 >> 29) )
    v42 = 0;
  *(_DWORD *)(v9 + 4872) = v42;
  ops = cam_cdm_get_ops(v40, nullptr, 0);
  *(_QWORD *)(v9 + 240) = ops;
  if ( !ops )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_component_bind",
      2514,
      "Failed to util ops for %s%u HW",
      *(const char **)(v4 + 152),
      *(_DWORD *)(v4 + 116));
LABEL_136:
    LODWORD(v13) = 4;
    v46 = -22;
    goto LABEL_137;
  }
  if ( (cam_cdm_set_cam_hw_version(*(_DWORD *)(v9 + 216), v9 + 200) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_component_bind",
      2521,
      "Failed to set cam hw version for hw");
    goto LABEL_136;
  }
  v46 = cam_cpas_stop(*(_DWORD *)(v9 + 4868));
  if ( v46 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_component_bind",
      2529,
      "CPAS stop failed");
    LODWORD(v13) = 4;
    goto LABEL_140;
  }
  v46 = cam_cdm_intf_register_hw_cdm((__int64)v2, v12, 1, (int *)v9);
  if ( v46 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_component_bind",
      2537,
      "HW CDM Interface registration failed");
    v9 = v47;
    LODWORD(v13) = 4;
    goto LABEL_140;
  }
  mutex_unlock(v4);
  ktime_get_real_ts64(v48);
  cam_record_bind_latency();
  result = 0;
  if ( (debug_mdl & 1) != 0 && !v15[919] )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_component_bind",
      2547,
      "%s component bound successfully",
      (const char *)(v47 + 4));
    result = 0;
  }
LABEL_165:
  _ReadStatusReg(SP_EL0);
  return result;
}
