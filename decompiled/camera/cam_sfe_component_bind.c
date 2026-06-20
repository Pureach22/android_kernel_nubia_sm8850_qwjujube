__int64 __fastcall cam_sfe_component_bind(_QWORD *a1)
{
  unsigned int v2; // w0
  __int64 v3; // x0
  unsigned int v4; // w22
  __int64 v5; // x19
  _QWORD *v6; // x0
  __int64 v7; // x20
  int v8; // w7
  int v9; // w8
  __int64 v10; // x0
  _QWORD *v11; // x24
  __int64 matched; // x0
  unsigned int inited; // w0
  unsigned int v14; // w0
  __int64 v15; // x8
  __int64 v16; // x10
  _DWORD *v17; // x9
  int v18; // w11
  __int64 v19; // x10
  __int64 v20; // x10
  __int64 v21; // x10
  __int64 v22; // x10
  int v23; // w8
  _QWORD *v24; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v26; // x22
  _QWORD v28[2]; // [xsp+10h] [xbp-30h] BYREF
  _QWORD v29[2]; // [xsp+20h] [xbp-20h] BYREF
  int v30; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v29[0] = 0;
  v29[1] = 0;
  v28[0] = 0;
  v28[1] = 0;
  ktime_get_real_ts64(v29);
  v2 = of_property_read_variable_u32_array(a1[93], "cell-index", &v30, 1, 0);
  if ( (v2 & 0x80000000) != 0 )
  {
    v4 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_component_bind",
      48,
      "Failed to read cell-index of SFE HW, rc: %d",
      v2);
    goto LABEL_65;
  }
  if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))cam_cpas_is_feature_supported)(9, 1LL << v30, 0) & 1) != 0 )
  {
    if ( mem_trace_en == 1 )
      v3 = cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_sfe_component_bind", 0x3Bu);
    else
      v3 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
    v5 = v3;
    if ( !v3 )
    {
LABEL_54:
      v4 = -12;
      goto LABEL_65;
    }
    while ( 1 )
    {
      if ( mem_trace_en == 1 )
        v6 = (_QWORD *)cam_mem_trace_alloc(3688, 0xCC0u, 0, "cam_sfe_component_bind", 0x41u);
      else
        v6 = (_QWORD *)_kvmalloc_node_noprof(3688, 0, 3520, 0xFFFFFFFFLL);
      v7 = (__int64)v6;
      if ( !v6 )
      {
        v4 = -12;
        goto LABEL_62;
      }
      v6[13] = a1;
      v6[12] = a1 - 2;
      v8 = v30;
      v6[15] = *(a1 - 2);
      *(_QWORD *)(v5 + 8) = cam_sfe_get_hw_caps;
      *(_QWORD *)(v5 + 16) = cam_sfe_init_hw;
      *(_QWORD *)(v5 + 24) = cam_sfe_deinit_hw;
      *(_QWORD *)(v5 + 32) = cam_sfe_reset;
      *(_QWORD *)(v5 + 40) = cam_sfe_reserve;
      *(_QWORD *)(v5 + 48) = cam_sfe_release;
      *(_QWORD *)(v5 + 56) = cam_sfe_start;
      *(_QWORD *)(v5 + 64) = cam_sfe_stop;
      *(_QWORD *)(v5 + 72) = cam_sfe_read;
      *(_QWORD *)(v5 + 80) = cam_sfe_write;
      *(_DWORD *)v5 = 7;
      *(_DWORD *)(v5 + 4) = v8;
      *(_QWORD *)(v5 + 88) = cam_sfe_process_cmd;
      v9 = debug_mdl;
      *(_QWORD *)(v5 + 104) = cam_sfe_test_irq_line;
      *(_QWORD *)(v5 + 112) = v6;
      if ( (v9 & 0x40000000) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          v9 & 0x40000000,
          4,
          "cam_sfe_component_bind",
          91,
          "SFE component bind type %d index %d",
          7);
      a1[19] = v5;
      if ( mem_trace_en == 1 )
        v10 = cam_mem_trace_alloc(48, 0xCC0u, 0, "cam_sfe_component_bind", 0x60u);
      else
        v10 = _kvmalloc_node_noprof(48, 0, 3520, 0xFFFFFFFFLL);
      v11 = (_QWORD *)v10;
      *(_QWORD *)(v7 + 3680) = v10;
      if ( !v10 )
      {
        v4 = -12;
        if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x40000000,
            4,
            "cam_sfe_component_bind",
            98,
            "Failed to alloc for core");
LABEL_59:
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v7, 0);
        else
          kvfree(v7);
LABEL_62:
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v5, 0);
        else
          kvfree(v5);
        goto LABEL_65;
      }
      matched = of_match_device(*(_QWORD *)(a1[17] + 40LL), a1);
      if ( !matched )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_component_bind",
          107,
          "Of_match Failed");
        v4 = -22;
        goto LABEL_49;
      }
      a1 = *(_QWORD **)(matched + 192);
      *v11 = a1;
      inited = cam_sfe_init_soc_resources(v7 + 96, (__int64)cam_sfe_irq, v7);
      if ( (inited & 0x80000000) != 0 )
      {
        v4 = inited;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_component_bind",
          117,
          "Failed to init soc rc=%d",
          inited);
LABEL_49:
        v24 = *(_QWORD **)(v7 + 3680);
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v24, 0);
        else
          kvfree(v24);
        goto LABEL_59;
      }
      v14 = cam_sfe_core_init(v11, v7 + 96, v5, a1);
      if ( (v14 & 0x80000000) != 0 )
      {
        v4 = v14;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_component_bind",
          124,
          "Failed to init core rc=%d",
          v14);
        if ( (unsigned int)cam_sfe_deinit_soc_resources(v7 + 96) )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_component_bind",
            159,
            "Failed to deinit soc");
        goto LABEL_49;
      }
      *(_DWORD *)(v7 + 92) = 0;
      _mutex_init(v7, "&sfe_info->hw_mutex", &cam_sfe_component_bind___key);
      *(_DWORD *)(v7 + 48) = 0;
      *(_DWORD *)(v7 + 56) = 0;
      _init_swait_queue_head(v7 + 64, "&x->wait", &init_completion___key_6);
      v15 = *(unsigned int *)(v5 + 4);
      if ( (unsigned int)v15 >= 3 )
        goto LABEL_52;
      *((_QWORD *)&cam_sfe_hw_list + 4 * v15) = v5;
      v16 = *(unsigned int *)(v5 + 4);
      if ( (unsigned int)v16 > 2 )
        goto LABEL_52;
      if ( ((32 * v16) | 8uLL) <= 0x60 )
      {
        v17 = *(_DWORD **)(v7 + 3392);
        v18 = v17[3];
        *((_DWORD *)&cam_sfe_hw_list + 8 * v16 + 2) = v18;
        if ( !v18 )
          goto LABEL_41;
        v19 = *(unsigned int *)(v5 + 4);
        if ( (unsigned int)v19 > 2 )
          goto LABEL_52;
        if ( ((32 * v19) | 0xCuLL) <= 0x60 )
        {
          *((_DWORD *)&cam_sfe_hw_list + 8 * v19 + 3) = v17[4];
          if ( v17[3] < 2u )
            goto LABEL_41;
          v20 = *(unsigned int *)(v5 + 4);
          if ( (unsigned int)v20 > 2 )
            goto LABEL_52;
          if ( ((32 * v20) | 0x10uLL) <= 0x60 )
          {
            *((_DWORD *)&cam_sfe_hw_list + 8 * v20 + 4) = v17[5];
            if ( v17[3] < 3u )
              goto LABEL_41;
            v21 = *(unsigned int *)(v5 + 4);
            if ( (unsigned int)v21 > 2 )
              goto LABEL_52;
            if ( ((32 * v21) | 0x14uLL) <= 0x60 )
            {
              *((_DWORD *)&cam_sfe_hw_list + 8 * v21 + 5) = v17[6];
              if ( v17[3] < 4u )
                goto LABEL_41;
              v22 = *(unsigned int *)(v5 + 4);
              if ( (unsigned int)v22 > 2 )
                goto LABEL_52;
              if ( ((32 * v22) | 0x18uLL) <= 0x60 )
                break;
            }
          }
        }
      }
LABEL_53:
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v26 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_sfe_component_bind__alloc_tag;
      v5 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v26;
      if ( !v5 )
        goto LABEL_54;
    }
    *((_DWORD *)&cam_sfe_hw_list + 8 * v22 + 6) = v17[7];
    if ( v17[3] <= 4u )
    {
LABEL_41:
      v23 = debug_mdl;
      *(_DWORD *)(v7 + 3400) = *(_DWORD *)(v7 + 116) + 13312;
      if ( (v23 & 0x40000000) != 0 && !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v23 & 0x40000000,
          4,
          "cam_sfe_component_bind",
          150,
          "SFE%d bound successfully",
          *(_DWORD *)(v5 + 4));
      ktime_get_real_ts64(v28);
      cam_record_bind_latency();
      v4 = 0;
      goto LABEL_65;
    }
LABEL_52:
    __break(0x5512u);
    goto LABEL_53;
  }
  v4 = 0;
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_component_bind",
      54,
      "SFE:%d is not supported",
      v30);
    v4 = 0;
  }
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return v4;
}
