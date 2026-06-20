__int64 __fastcall cam_vfe_component_bind(_QWORD *a1)
{
  unsigned int v2; // w0
  __int64 v3; // x0
  unsigned int v4; // w23
  __int64 v6; // x19
  _QWORD *v7; // x0
  __int64 v8; // x20
  int v9; // w7
  char v10; // w8
  __int64 v11; // x0
  _QWORD *v12; // x24
  __int64 matched; // x0
  __int64 v14; // x8
  unsigned int inited; // w0
  __int64 v16; // x3
  unsigned int hw_query; // w0
  __int64 v18; // x6
  const char *v19; // x5
  __int64 v20; // x4
  __int64 (__fastcall *v21)(_QWORD); // x8
  unsigned int v22; // w0
  _QWORD *v23; // x0
  unsigned int v24; // w0
  __int64 v25; // x8
  __int64 v26; // x10
  _DWORD *v27; // x9
  int v28; // w11
  __int64 v29; // x10
  __int64 v30; // x10
  __int64 v31; // x10
  __int64 v32; // x10
  char v33; // w8
  unsigned __int64 StatusReg; // x20
  __int64 v35; // x22
  _QWORD v36[2]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v37[2]; // [xsp+18h] [xbp-28h] BYREF
  int v38; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v39[2]; // [xsp+30h] [xbp-10h] BYREF

  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39[0] = 0;
  v38 = 0;
  v37[0] = 0;
  v37[1] = 0;
  v36[0] = 0;
  v36[1] = 0;
  ktime_get_real_ts64(v37);
  v2 = of_property_read_variable_u32_array(a1[93], "cell-index", &v38, 1, 0);
  if ( (v2 & 0x80000000) != 0 )
  {
    v4 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_component_bind",
      44,
      "Failed to read cell-index of IFE HW, rc: %d",
      v2);
    goto LABEL_10;
  }
  if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))cam_cpas_is_feature_supported)(4, 1LL << v38, 0) & 1) != 0
    && (((__int64 (__fastcall *)(__int64, __int64, _QWORD))cam_cpas_is_feature_supported)(6, 1LL << v38, 0) & 1) != 0 )
  {
    if ( mem_trace_en == 1 )
      v3 = cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_vfe_component_bind", 0x39u);
    else
      v3 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
    v6 = v3;
    if ( !v3 )
    {
LABEL_76:
      v4 = -12;
      goto LABEL_10;
    }
    while ( 1 )
    {
      if ( mem_trace_en == 1 )
        v7 = (_QWORD *)cam_mem_trace_alloc(3688, 0xCC0u, 0, "cam_vfe_component_bind", 0x3Fu);
      else
        v7 = (_QWORD *)_kvmalloc_node_noprof(3688, 0, 3520, 0xFFFFFFFFLL);
      v8 = (__int64)v7;
      if ( !v7 )
      {
        v4 = -12;
        goto LABEL_84;
      }
      v7[13] = a1;
      v7[12] = a1 - 2;
      v9 = v38;
      v7[15] = *(a1 - 2);
      *(_QWORD *)(v6 + 8) = cam_vfe_get_hw_caps;
      *(_QWORD *)(v6 + 16) = cam_vfe_init_hw;
      *(_QWORD *)(v6 + 24) = cam_vfe_deinit_hw;
      *(_QWORD *)(v6 + 32) = cam_vfe_reset;
      *(_QWORD *)(v6 + 40) = cam_vfe_reserve;
      *(_QWORD *)(v6 + 48) = cam_vfe_release;
      *(_QWORD *)(v6 + 56) = cam_vfe_start;
      *(_QWORD *)(v6 + 64) = cam_vfe_stop;
      *(_QWORD *)(v6 + 72) = cam_vfe_read;
      *(_QWORD *)(v6 + 80) = cam_vfe_write;
      *(_DWORD *)v6 = 2;
      *(_DWORD *)(v6 + 4) = v9;
      *(_QWORD *)(v6 + 88) = cam_vfe_process_cmd;
      v10 = debug_mdl;
      *(_QWORD *)(v6 + 104) = cam_vfe_test_irq_line;
      *(_QWORD *)(v6 + 112) = v7;
      if ( (v10 & 8) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          v10 & 8,
          4,
          "cam_vfe_component_bind",
          89,
          "VFE component bind, type %d index %d",
          2);
      a1[19] = v6;
      if ( mem_trace_en == 1 )
        v11 = cam_mem_trace_alloc(48, 0xCC0u, 0, "cam_vfe_component_bind", 0x5Eu);
      else
        v11 = _kvmalloc_node_noprof(48, 0, 3520, 0xFFFFFFFFLL);
      v12 = (_QWORD *)v11;
      *(_QWORD *)(v8 + 3680) = v11;
      if ( !v11 )
      {
        v4 = -12;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_component_bind",
            96,
            "Failed to alloc for core");
LABEL_81:
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v8, 0);
        else
          kvfree(v8);
LABEL_84:
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v6, 0);
        else
          kvfree(v6);
        goto LABEL_10;
      }
      matched = of_match_device(*(_QWORD *)(a1[17] + 40LL), a1);
      if ( !matched || (v14 = *(_QWORD *)(matched + 192)) == 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_component_bind",
          105,
          "Of_match Failed");
        v4 = -22;
        goto LABEL_47;
      }
      v39[0] = *(_QWORD *)(matched + 192);
      *v12 = v14;
      inited = cam_vfe_init_soc_resources(v8 + 96, (__int64)cam_vfe_irq, v8);
      if ( (inited & 0x80000000) != 0 )
      {
        v4 = inited;
        v19 = "Failed to init soc rc=%d";
        v20 = 117;
        v18 = inited;
        goto LABEL_46;
      }
      v16 = v39[0];
      if ( *(_BYTE *)(v39[0] + 104LL) == 1 && (*(_BYTE *)(v39[0] + 105LL) & 1) == 0 )
      {
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_component_bind",
            123,
            "VFE[%u] calling read hw query",
            *(_DWORD *)(v6 + 4));
          v16 = v39[0];
        }
        hw_query = cam_vfe_core_read_hw_query(v8 + 96, v16);
        if ( hw_query )
        {
          v18 = *(unsigned int *)(v6 + 4);
          v4 = hw_query;
          v19 = "VFE[%u]Read hw query failed";
          v20 = 126;
          goto LABEL_46;
        }
        v16 = v39[0];
        *(_BYTE *)(v39[0] + 105LL) = 1;
      }
      v21 = *(__int64 (__fastcall **)(_QWORD))(v16 + 88);
      if ( v21 && (*(_BYTE *)(v16 + 106) & 1) == 0 )
      {
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_component_bind",
            133,
            "VFE[%u] calling override",
            *(_DWORD *)(v6 + 4));
          v21 = *(__int64 (__fastcall **)(_QWORD))(v39[0] + 88LL);
        }
        if ( *((_DWORD *)v21 - 1) != 726081083 )
          __break(0x8228u);
        v22 = v21(v39);
        if ( v22 )
        {
          v18 = *(unsigned int *)(v6 + 4);
          v4 = v22;
          v19 = "VFE[%u] Failed to override";
          v20 = 137;
LABEL_46:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_component_bind",
            v20,
            v19,
            v18);
LABEL_47:
          v23 = *(_QWORD **)(v8 + 3680);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v23, 0);
          else
            kvfree(v23);
          goto LABEL_81;
        }
        *(_BYTE *)(v39[0] + 106LL) = 1;
      }
      v24 = cam_vfe_core_init(v12, v8 + 96, v6);
      if ( (v24 & 0x80000000) != 0 )
      {
        v4 = v24;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_component_bind",
          146,
          "Failed to init core rc=%d",
          v24);
        if ( (unsigned int)cam_vfe_deinit_soc_resources(v8 + 96) )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_component_bind",
            180,
            "Failed to deinit soc");
        goto LABEL_47;
      }
      *(_DWORD *)(v8 + 92) = 0;
      _mutex_init(v8, "&vfe_hw->hw_mutex", &cam_vfe_component_bind___key);
      *(_DWORD *)(v8 + 48) = 0;
      *(_DWORD *)(v8 + 56) = 0;
      _init_swait_queue_head(v8 + 64, "&x->wait", &init_completion___key_7);
      v25 = *(unsigned int *)(v6 + 4);
      if ( (unsigned int)v25 >= 8 )
        goto LABEL_74;
      *((_QWORD *)&cam_vfe_hw_list + 4 * v25) = v6;
      v26 = *(unsigned int *)(v6 + 4);
      if ( (unsigned int)v26 > 7 )
        goto LABEL_74;
      if ( ((32 * v26) | 8uLL) <= 0x100 )
      {
        v27 = *(_DWORD **)(v8 + 3392);
        v28 = v27[10];
        *((_DWORD *)&cam_vfe_hw_list + 8 * v26 + 2) = v28;
        if ( !v28 )
          goto LABEL_68;
        v29 = *(unsigned int *)(v6 + 4);
        if ( (unsigned int)v29 > 7 )
          goto LABEL_74;
        if ( ((32 * v29) | 0xCuLL) <= 0x100 )
        {
          *((_DWORD *)&cam_vfe_hw_list + 8 * v29 + 3) = v27[11];
          if ( v27[10] < 2u )
            goto LABEL_68;
          v30 = *(unsigned int *)(v6 + 4);
          if ( (unsigned int)v30 > 7 )
            goto LABEL_74;
          if ( ((32 * v30) | 0x10uLL) <= 0x100 )
          {
            *((_DWORD *)&cam_vfe_hw_list + 8 * v30 + 4) = v27[12];
            if ( v27[10] < 3u )
              goto LABEL_68;
            v31 = *(unsigned int *)(v6 + 4);
            if ( (unsigned int)v31 > 7 )
              goto LABEL_74;
            if ( ((32 * v31) | 0x14uLL) <= 0x100 )
            {
              *((_DWORD *)&cam_vfe_hw_list + 8 * v31 + 5) = v27[13];
              if ( v27[10] < 4u )
                goto LABEL_68;
              v32 = *(unsigned int *)(v6 + 4);
              if ( (unsigned int)v32 > 7 )
                goto LABEL_74;
              if ( ((32 * v32) | 0x18uLL) <= 0x100 )
                break;
            }
          }
        }
      }
LABEL_75:
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v35 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_vfe_component_bind__alloc_tag;
      v6 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v35;
      if ( !v6 )
        goto LABEL_76;
    }
    *((_DWORD *)&cam_vfe_hw_list + 8 * v32 + 6) = v27[14];
    if ( v27[10] <= 4u )
    {
LABEL_68:
      v33 = debug_mdl;
      *(_DWORD *)(v8 + 3400) = *(_DWORD *)(v8 + 116) + 13824;
      if ( (v33 & 8) != 0 && !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v33 & 8,
          4,
          "cam_vfe_component_bind",
          172,
          "VFE:%d component bound successfully",
          *(_DWORD *)(v6 + 4));
      ktime_get_real_ts64(v36);
      cam_record_bind_latency();
      v4 = 0;
      goto LABEL_10;
    }
LABEL_74:
    __break(0x5512u);
    goto LABEL_75;
  }
  v4 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_component_bind",
      52,
      "IFE:%d is not supported",
      v38);
    v4 = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v4;
}
