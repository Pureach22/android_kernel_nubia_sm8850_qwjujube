__int64 __fastcall cam_ife_csid_component_bind(_QWORD *a1)
{
  unsigned int v2; // w0
  __int64 v3; // x0
  unsigned int v4; // w22
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 matched; // x0
  int v10; // w8
  __int64 v11; // x8
  unsigned int v12; // w0
  char v13; // w8
  __int64 v14; // x8
  _QWORD v15[2]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v16[2]; // [xsp+10h] [xbp-20h] BYREF
  int v17; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v16[0] = 0;
  v16[1] = 0;
  v15[0] = 0;
  v15[1] = 0;
  ktime_get_real_ts64(v16);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_component_bind",
      38,
      "Binding IFE CSID component");
  v2 = of_property_read_variable_u32_array(a1[93], "cell-index", &v17, 1, 0);
  if ( (v2 & 0x80000000) != 0 )
  {
    v4 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_component_bind",
      43,
      "Failed to read cell-index of IFE CSID HW, rc: %d",
      v2);
  }
  else if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))cam_cpas_is_feature_supported)(4, 1LL << v17, 0) & 1) != 0
         && (((__int64 (__fastcall *)(__int64, __int64, _QWORD))cam_cpas_is_feature_supported)(6, 1LL << v17, 0) & 1) != 0 )
  {
    if ( mem_trace_en == 1 )
      v3 = cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_ife_csid_component_bind", 0x38u);
    else
      v3 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
    v6 = v3;
    if ( !v3 )
    {
      v4 = -12;
      goto LABEL_13;
    }
    if ( mem_trace_en == 1 )
      v7 = cam_mem_trace_alloc(3688, 0xCC0u, 0, "cam_ife_csid_component_bind", 0x3Eu);
    else
      v7 = _kvmalloc_node_noprof(3688, 0, 3520, 0xFFFFFFFFLL);
    v8 = v7;
    if ( v7 )
    {
      matched = of_match_device(*(_QWORD *)(a1[17] + 40LL), a1);
      if ( matched )
      {
        v10 = v17;
        *(_QWORD *)(v6 + 112) = v8;
        *(_DWORD *)v6 = 3;
        *(_DWORD *)(v6 + 4) = v10;
        *(_QWORD *)(v8 + 96) = a1 - 2;
        *(_QWORD *)(v8 + 104) = a1;
        v11 = *(a1 - 2);
        *(_DWORD *)(v8 + 116) = v17;
        *(_QWORD *)(v8 + 120) = v11;
        v12 = cam_ife_csid_hw_probe_init(v6, *(_QWORD *)(matched + 192), 0);
        if ( v12 )
        {
          v4 = v12;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_csid_component_bind",
            93,
            "CSID[%d] probe init failed",
            v17);
        }
        else
        {
          a1[19] = v6;
          v13 = debug_mdl;
          *(_DWORD *)(v8 + 3400) = *(_DWORD *)(v8 + 116) + 13568;
          if ( (v13 & 8) != 0 && !debug_priority )
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v13 & 8,
              4,
              "cam_ife_csid_component_bind",
              107,
              "CSID:%d component bound successfully",
              *(_DWORD *)(v6 + 4));
          ktime_get_real_ts64(v15);
          cam_record_bind_latency();
          v14 = *(unsigned int *)(v6 + 4);
          if ( (unsigned int)v14 <= 7 )
          {
            v4 = 0;
            cam_ife_csid_hw_list[v14] = v6;
            goto LABEL_13;
          }
          v4 = 0;
        }
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_component_bind",
          72,
          "No matching table for the IFE CSID HW!");
        v4 = -22;
      }
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)v8, 0);
      else
        kvfree(v8);
    }
    else
    {
      v4 = -12;
    }
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v6, 0);
    else
      kvfree(v6);
  }
  else
  {
    v4 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_component_bind",
        51,
        "CSID[%d] not supported based on fuse",
        v17);
      v4 = 0;
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v4;
}
