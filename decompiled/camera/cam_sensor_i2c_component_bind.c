__int64 __fastcall cam_sensor_i2c_component_bind(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w21
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x10
  unsigned int v8; // w0
  unsigned int v9; // w0
  const char *v10; // x3
  const char *v11; // x5
  __int64 v12; // x4
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  _QWORD *v22; // x9
  _QWORD *v23; // x9
  _QWORD *v24; // x9
  _QWORD *v25; // x9
  __int64 v26; // x9
  __int64 v27; // x8
  _QWORD *v28; // x0
  _QWORD *v29; // x0
  _QWORD *v30; // x0
  _QWORD *v31; // x0
  _QWORD v33[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v34[3]; // [xsp+18h] [xbp-18h] BYREF

  v34[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34[0] = 0;
  v34[1] = 0;
  v33[0] = 0;
  v33[1] = 0;
  ktime_get_real_ts64(v34);
  if ( a1 == 32 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_i2c_component_bind",
      327,
      "Invalid Args client: %pK",
      nullptr);
    v3 = -22;
    goto LABEL_53;
  }
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(7976, 0xCC0u, 0, "cam_sensor_i2c_component_bind", 0x14Cu);
  else
    v2 = _kvmalloc_node_noprof(7976, 0, 3520, 0xFFFFFFFFLL);
  v4 = v2;
  if ( !v2 )
  {
    v3 = -12;
    goto LABEL_53;
  }
  if ( mem_trace_en == 1 )
  {
    v5 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_sensor_i2c_component_bind", 0x151u);
    *(_QWORD *)(v4 + 6488) = v5;
    if ( !v5 )
      goto LABEL_36;
  }
  else
  {
    v6 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v4 + 6488) = v6;
    if ( !v6 )
    {
LABEL_36:
      v3 = -12;
LABEL_50:
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)v4, 0);
      else
        kvfree(v4);
      goto LABEL_53;
    }
  }
  *(_QWORD *)(a1 + 152) = v4;
  **(_QWORD **)(v4 + 6488) = a1 - 32;
  *(_QWORD *)(v4 + 40) = a1;
  *(_QWORD *)(v4 + 56) = a1 - 28;
  v7 = *(_QWORD *)(a1 + 744);
  *(_DWORD *)(v4 + 6480) = 2;
  *(_BYTE *)(v4 + 6548) = 0;
  *(_QWORD *)(v4 + 6560) = v7;
  *(_DWORD *)(v4 + 7552) = 0;
  v8 = cam_sensor_parse_dt(v4);
  if ( (v8 & 0x80000000) != 0 )
  {
    v3 = v8;
    v10 = "cam_sensor_i2c_component_bind";
    v11 = "cam_sensor_parse_dt rc %d";
    v12 = 361;
    goto LABEL_15;
  }
  *(_QWORD *)(v4 + 6968) = &cam_sensor_internal_ops;
  *(_QWORD *)(v4 + 6960) = &cam_sensor_subdev_ops;
  *(_QWORD *)(v4 + 6976) = v4;
  strcpy((char *)v4, "cam-sensor-driver");
  *(_DWORD *)(v4 + 6984) = 12;
  *(_DWORD *)(v4 + 7000) = 65537;
  *(_QWORD *)(v4 + 6992) = v4;
  *(_DWORD *)(v4 + 7032) = 2;
  v9 = cam_register_subdev(v4 + 6568);
  if ( v9 )
  {
    v3 = v9;
    v10 = "cam_sensor_init_subdev_params";
    v11 = "Fail with cam_register_subdev rc: %d";
    v12 = 162;
LABEL_15:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      32,
      1,
      v10,
      v12,
      v11,
      v3);
    goto LABEL_47;
  }
  if ( mem_trace_en == 1 )
  {
    v13 = cam_mem_trace_alloc(1536, 0xCC0u, 0, "cam_sensor_i2c_component_bind", 0x173u);
    *(_QWORD *)(v4 + 7288) = v13;
    if ( !v13 )
      goto LABEL_46;
  }
  else
  {
    v14 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v4 + 7288) = v14;
    if ( !v14 )
    {
LABEL_46:
      cam_unregister_subdev(v4 + 6568);
      v3 = -12;
LABEL_47:
      v31 = *(_QWORD **)(v4 + 6488);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v31, 0);
      else
        kvfree(v31);
      goto LABEL_50;
    }
  }
  if ( mem_trace_en == 1 )
  {
    v15 = cam_mem_trace_alloc(1536, 0xCC0u, 0, "cam_sensor_i2c_component_bind", 0x17Bu);
    *(_QWORD *)(v4 + 7304) = v15;
    if ( !v15 )
    {
LABEL_43:
      v30 = *(_QWORD **)(v4 + 7288);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v30, 0);
      else
        kvfree(v30);
      goto LABEL_46;
    }
  }
  else
  {
    v16 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v4 + 7304) = v16;
    if ( !v16 )
      goto LABEL_43;
  }
  if ( mem_trace_en == 1 )
  {
    v17 = cam_mem_trace_alloc(1536, 0xCC0u, 0, "cam_sensor_i2c_component_bind", 0x183u);
    *(_QWORD *)(v4 + 7296) = v17;
    if ( !v17 )
    {
LABEL_40:
      v29 = *(_QWORD **)(v4 + 7304);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v29, 0);
      else
        kvfree(v29);
      goto LABEL_43;
    }
  }
  else
  {
    v18 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v4 + 7296) = v18;
    if ( !v18 )
      goto LABEL_40;
  }
  if ( mem_trace_en == 1 )
  {
    v19 = cam_mem_trace_alloc(1536, 0xCC0u, 0, "cam_sensor_i2c_component_bind", 0x18Bu);
    *(_QWORD *)(v4 + 7312) = v19;
    if ( !v19 )
    {
LABEL_37:
      v28 = *(_QWORD **)(v4 + 7296);
      if ( (mem_trace_en & 1) != 0 )
        cam_mem_trace_free(v28, 0);
      else
        kvfree(v28);
      goto LABEL_40;
    }
  }
  else
  {
    v20 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v4 + 7312) = v20;
    if ( !v20 )
      goto LABEL_37;
  }
  v21 = 0;
  *(_QWORD *)(v4 + 7048) = v4 + 7048;
  *(_QWORD *)(v4 + 7056) = v4 + 7048;
  *(_QWORD *)(v4 + 7096) = v4 + 7096;
  *(_QWORD *)(v4 + 7104) = v4 + 7096;
  *(_QWORD *)(v4 + 7144) = v4 + 7144;
  *(_QWORD *)(v4 + 7152) = v4 + 7144;
  *(_QWORD *)(v4 + 7192) = v4 + 7192;
  *(_QWORD *)(v4 + 7200) = v4 + 7192;
  *(_QWORD *)(v4 + 7320) = v4 + 7320;
  *(_QWORD *)(v4 + 7328) = v4 + 7320;
  *(_QWORD *)(v4 + 7368) = v4 + 7368;
  *(_QWORD *)(v4 + 7376) = v4 + 7368;
  *(_QWORD *)(v4 + 7240) = v4 + 7240;
  *(_QWORD *)(v4 + 7248) = v4 + 7240;
  do
  {
    v22 = (_QWORD *)(*(_QWORD *)(v4 + 7296) + v21);
    *v22 = v22;
    v22[1] = v22;
    v23 = (_QWORD *)(*(_QWORD *)(v4 + 7288) + v21);
    *v23 = v23;
    v23[1] = v23;
    v24 = (_QWORD *)(*(_QWORD *)(v4 + 7304) + v21);
    *v24 = v24;
    v24[1] = v24;
    v25 = (_QWORD *)(*(_QWORD *)(v4 + 7312) + v21);
    v21 += 48;
    *v25 = v25;
    v25[1] = v25;
  }
  while ( v21 != 1536 );
  ((void (__fastcall *)(__int64, __int64))cam_sensor_module_add_i2c_device)(v4, 4);
  *(_DWORD *)(v4 + 7456) = -1;
  *(_DWORD *)(v4 + 7464) = -1;
  *(_QWORD *)(v4 + 7480) = cam_sensor_establish_link;
  *(_QWORD *)(v4 + 7488) = cam_sensor_apply_request;
  *(_QWORD *)(v4 + 7496) = cam_sensor_notify_frame_skip;
  *(_QWORD *)(v4 + 7504) = cam_sensor_flush_request;
  *(_QWORD *)(v4 + 7472) = cam_sensor_publish_dev_info;
  v26 = *(_QWORD *)(v4 + 3656);
  *(_QWORD *)(v4 + 7512) = cam_sensor_process_evt;
  v27 = *(_QWORD *)(v4 + 40);
  *(_QWORD *)(v4 + 7520) = cam_sensor_dump_request;
  *(_QWORD *)(v26 + 112) = v27;
  ktime_get_real_ts64(v33);
  cam_record_bind_latency();
  v3 = 0;
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return v3;
}
