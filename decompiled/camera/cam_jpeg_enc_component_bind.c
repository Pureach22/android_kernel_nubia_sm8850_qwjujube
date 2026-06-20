__int64 __fastcall cam_jpeg_enc_component_bind(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  _QWORD *v4; // x0
  _QWORD *v5; // x20
  __int64 v6; // x0
  __int64 v7; // x23
  __int64 matched; // x0
  __int64 v9; // x8
  unsigned int inited; // w0
  unsigned int v11; // w21
  int v12; // w8
  unsigned int v13; // w0
  _QWORD *v14; // x0
  int *v15; // x8
  int v16; // w9
  unsigned __int64 StatusReg; // x20
  __int64 v18; // x22
  _QWORD v20[2]; // [xsp+0h] [xbp-D0h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-C0h] BYREF
  _QWORD v22[16]; // [xsp+20h] [xbp-B0h] BYREF
  __int64 v23; // [xsp+A0h] [xbp-30h]
  __int64 v24; // [xsp+A8h] [xbp-28h]
  __int64 v25; // [xsp+B0h] [xbp-20h]
  __int64 v26; // [xsp+B8h] [xbp-18h]
  __int64 v27; // [xsp+C0h] [xbp-10h]
  __int64 v28; // [xsp+C8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  v21[1] = 0;
  v20[0] = 0;
  v20[1] = 0;
  ktime_get_real_ts64(v21);
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_jpeg_enc_component_bind", 0x54u);
  else
    v2 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
  v3 = v2;
  if ( v2 )
  {
    while ( 1 )
    {
      of_property_read_variable_u32_array(a1[93], "cell-index", v3 + 4, 1, 0);
      if ( mem_trace_en == 1 )
        v4 = (_QWORD *)cam_mem_trace_alloc(3688, 0xCC0u, 0, "cam_jpeg_enc_component_bind", 0x5Bu);
      else
        v4 = (_QWORD *)_kvmalloc_node_noprof(3688, 0, 3520, 0xFFFFFFFFLL);
      v5 = v4;
      if ( !v4 )
      {
        v11 = -12;
        goto LABEL_36;
      }
      v4[13] = a1;
      v4[12] = a1 - 2;
      v4[15] = *(a1 - 2);
      *(_QWORD *)(v3 + 16) = &cam_jpeg_enc_init_hw;
      *(_QWORD *)(v3 + 24) = cam_jpeg_enc_deinit_hw;
      *(_DWORD *)v3 = 0;
      *(_QWORD *)(v3 + 56) = cam_jpeg_enc_start_hw;
      *(_QWORD *)(v3 + 64) = cam_jpeg_enc_stop_hw;
      *(_QWORD *)(v3 + 32) = cam_jpeg_enc_reset_hw;
      *(_QWORD *)(v3 + 88) = &cam_jpeg_enc_process_cmd;
      *(_QWORD *)(v3 + 104) = cam_jpeg_enc_test_irq_line;
      *(_QWORD *)(v3 + 112) = v4;
      a1[19] = v3;
      if ( mem_trace_en == 1 )
        v6 = cam_mem_trace_alloc(136, 0xCC0u, 0, "cam_jpeg_enc_component_bind", 0x70u);
      else
        v6 = _kvmalloc_node_noprof(136, 0, 3520, 0xFFFFFFFFLL);
      v7 = v6;
      v5[460] = v6;
      if ( !v6 )
      {
        v11 = -12;
        goto LABEL_33;
      }
      matched = of_match_device(*(_QWORD *)(a1[17] + 40LL), a1);
      if ( !matched )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_enc_component_bind",
          123,
          " No jpeg_enc hardware info");
        v11 = -22;
        goto LABEL_19;
      }
      v9 = *(_QWORD *)(matched + 192);
      *(_DWORD *)v7 = 0;
      *(_QWORD *)(v7 + 8) = v9;
      _mutex_init(v7 + 64, "&core_info->core_mutex", &cam_jpeg_enc_component_bind___key);
      inited = cam_jpeg_enc_init_soc_resources(v5 + 12, cam_jpeg_enc_irq, v5);
      if ( inited )
      {
        v11 = inited;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_enc_component_bind",
          136,
          " failed to init_soc %d",
          inited);
        goto LABEL_19;
      }
      v12 = *(_DWORD *)(v3 + 4);
      v26 = 0;
      v27 = 0;
      v24 = 0;
      v25 = 0;
      v23 = 0;
      v24 = v5[13];
      memset(&v22[1], 0, 120);
      v22[0] = *(_QWORD *)"jpeg-enc";
      LODWORD(v23) = v12;
      v13 = cam_cpas_register_client((__int64)v22);
      if ( v13 )
        break;
      *(_DWORD *)(v7 + 16) = v27;
      *((_DWORD *)v5 + 23) = 0;
      _mutex_init(v5, "&jpeg_enc_dev->hw_mutex", &cam_jpeg_enc_component_bind___key_14);
      *((_DWORD *)v5 + 12) = 0;
      *((_DWORD *)v5 + 14) = 0;
      _init_swait_queue_head(v5 + 8, "&x->wait", &init_completion___key_15);
      if ( (debug_mdl & 0x200) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x200,
          4,
          "cam_jpeg_enc_component_bind",
          150,
          "JPEG-Encoder component bound successfully");
      v15 = (int *)v5[424];
      v16 = *v15;
      *(_DWORD *)(v7 + 112) = *v15;
      if ( !v16
        || (*(_DWORD *)(v7 + 116) = v15[1], (unsigned int)*v15 <= 1)
        || (*(_DWORD *)(v7 + 120) = v15[2], (unsigned int)*v15 <= 2) )
      {
        *(_DWORD *)(v7 + 124) = v15[3];
        *(_DWORD *)(v7 + 128) = v15[4];
        ktime_get_real_ts64(v20);
        cam_record_bind_latency();
        v11 = 0;
        goto LABEL_39;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v18 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_jpeg_enc_component_bind__alloc_tag;
      v3 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v18;
      if ( !v3 )
        goto LABEL_30;
    }
    v11 = v13;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_enc_register_cpas",
      47,
      "cpas_register failed: %d",
      v13);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_enc_component_bind",
      143,
      " failed to reg cpas %d",
      v11);
    cam_soc_util_release_platform_resource((__int64)(v5 + 12));
LABEL_19:
    v14 = (_QWORD *)v5[460];
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v14, 0);
    else
      kvfree(v14);
LABEL_33:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v5, 0);
    else
      kvfree(v5);
LABEL_36:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v3, 0);
    else
      kvfree(v3);
  }
  else
  {
LABEL_30:
    v11 = -12;
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return v11;
}
