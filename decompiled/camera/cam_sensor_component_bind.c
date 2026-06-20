__int64 __fastcall cam_sensor_component_bind(__int64 a1)
{
  _QWORD *v2; // x8
  _QWORD *v3; // x0
  __int64 v4; // x8
  __int64 v5; // x9
  _QWORD *v6; // x19
  unsigned int v7; // w0
  int v8; // w8
  unsigned int v9; // w0
  unsigned int v10; // w21
  const char *v11; // x3
  const char *v12; // x5
  __int64 v13; // x4
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  _QWORD *v23; // x9
  _QWORD *v24; // x9
  _QWORD *v25; // x9
  _QWORD *v26; // x9
  __int64 v27; // x8
  char v28; // w8
  unsigned int v29; // w8
  char *v30; // x8
  unsigned __int64 StatusReg; // x26
  __int64 v32; // x27
  __int64 v33; // x0
  _QWORD *v34; // x0
  _QWORD *v35; // x0
  _QWORD *v36; // x0
  _QWORD v38[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v39[3]; // [xsp+18h] [xbp-18h] BYREF

  v39[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39[0] = 0;
  v39[1] = 0;
  v38[0] = 0;
  v38[1] = 0;
  ktime_get_real_ts64(v39);
  v3 = devm_kmalloc(v2, a1, 7976, 3520);
  if ( !v3 )
  {
    v10 = -12;
    goto LABEL_47;
  }
  v4 = *(_QWORD *)(a1 - 16);
  v5 = *(_QWORD *)(a1 + 744);
  v6 = v3;
  *((_DWORD *)v3 + 1888) = 0;
  v3[7] = v4;
  *((_BYTE *)v3 + 6548) = 0;
  v3[820] = v5;
  v3[4] = a1 - 16;
  v3[5] = a1;
  v3[3] = a1 - 16;
  *((_DWORD *)v3 + 1620) = 1;
  v7 = cam_sensor_parse_dt(v3);
  if ( (v7 & 0x80000000) != 0 )
  {
    v10 = v7;
    v11 = "cam_sensor_component_bind";
    v12 = "failed: cam_sensor_parse_dt rc %d";
    v13 = 597;
    goto LABEL_10;
  }
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_component_bind",
      601,
      "Master Type: %u",
      *((_DWORD *)v6 + 1620));
  v8 = *((_DWORD *)v6 + 13);
  v6[871] = &cam_sensor_internal_ops;
  *(_DWORD *)(a1 - 8) = v8;
  v6[870] = &cam_sensor_subdev_ops;
  strcpy((char *)v6, "cam-sensor-driver");
  *((_DWORD *)v6 + 1746) = 12;
  *((_DWORD *)v6 + 1750) = 65537;
  v6[872] = v6;
  v6[874] = v6;
  *((_DWORD *)v6 + 1758) = 2;
  v9 = cam_register_subdev((__int64)(v6 + 821));
  if ( v9 )
  {
    v10 = v9;
    v11 = "cam_sensor_init_subdev_params";
    v12 = "Fail with cam_register_subdev rc: %d";
    v13 = 162;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      32,
      1,
      v11,
      v13,
      v12,
      v10);
    goto LABEL_46;
  }
  if ( mem_trace_en == 1 )
  {
    v14 = cam_mem_trace_alloc(1536, 0xCC0u, 0, "cam_sensor_component_bind", 0x264u);
    v6[911] = v14;
    if ( v14 )
      goto LABEL_15;
    goto LABEL_45;
  }
  v15 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
  v6[911] = v15;
  if ( !v15 )
    goto LABEL_45;
  while ( 1 )
  {
LABEL_15:
    if ( mem_trace_en == 1 )
    {
      v16 = cam_mem_trace_alloc(1536, 0xCC0u, 0, "cam_sensor_component_bind", 0x26Cu);
      v6[913] = v16;
      if ( !v16 )
        goto LABEL_42;
    }
    else
    {
      v17 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
      v6[913] = v17;
      if ( !v17 )
        goto LABEL_42;
    }
    if ( mem_trace_en == 1 )
    {
      v18 = cam_mem_trace_alloc(1536, 0xCC0u, 0, "cam_sensor_component_bind", 0x274u);
      v6[912] = v18;
      if ( !v18 )
        goto LABEL_39;
    }
    else
    {
      v19 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
      v6[912] = v19;
      if ( !v19 )
        goto LABEL_39;
    }
    if ( mem_trace_en != 1 )
      break;
    v20 = cam_mem_trace_alloc(1536, 0xCC0u, 0, "cam_sensor_component_bind", 0x27Cu);
    v6[914] = v20;
    if ( !v20 )
      goto LABEL_36;
LABEL_27:
    v22 = 0;
    v6[881] = v6 + 881;
    v6[882] = v6 + 881;
    v6[887] = v6 + 887;
    v6[888] = v6 + 887;
    v6[893] = v6 + 893;
    v6[894] = v6 + 893;
    v6[899] = v6 + 899;
    v6[900] = v6 + 899;
    v6[915] = v6 + 915;
    v6[916] = v6 + 915;
    v6[921] = v6 + 921;
    v6[922] = v6 + 921;
    v6[905] = v6 + 905;
    v6[906] = v6 + 905;
    do
    {
      v23 = (_QWORD *)(v6[912] + v22);
      *v23 = v23;
      v23[1] = v23;
      v24 = (_QWORD *)(v6[911] + v22);
      *v24 = v24;
      v24[1] = v24;
      v25 = (_QWORD *)(v6[913] + v22);
      *v25 = v25;
      v25[1] = v25;
      v26 = (_QWORD *)(v6[914] + v22);
      v22 += 48;
      *v26 = v26;
      v26[1] = v26;
    }
    while ( v22 != 1536 );
    ((void (__fastcall *)(_QWORD *, __int64))cam_sensor_module_add_i2c_device)(v6, 4);
    *((_DWORD *)v6 + 1864) = -1;
    *((_DWORD *)v6 + 1866) = -1;
    v6[935] = cam_sensor_establish_link;
    v6[936] = cam_sensor_apply_request;
    v6[937] = cam_sensor_notify_frame_skip;
    v6[938] = cam_sensor_flush_request;
    v6[939] = cam_sensor_process_evt;
    v27 = v6[457];
    v6[934] = cam_sensor_publish_dev_info;
    v6[940] = cam_sensor_dump_request;
    *(_QWORD *)(v27 + 112) = a1;
    *(_QWORD *)(a1 + 152) = v6;
    v28 = debug_mdl;
    *((_DWORD *)v6 + 1636) = 0;
    if ( (v28 & 0x20) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v28 & 0x20,
        4,
        "cam_sensor_component_bind",
        673,
        "Component bound successfully for %s",
        *(const char **)(a1 - 16));
    v29 = *((_DWORD *)v6 + 13);
    if ( v29 < 0x10 )
    {
      v30 = (char *)&g_i3c_sensor_data + 40 * v29;
      *(_QWORD *)v30 = v6;
      *((_DWORD *)v30 + 2) = 0;
      _init_swait_queue_head(v30 + 16, "&x->wait", &init_completion___key_22);
      ktime_get_real_ts64(v38);
      cam_record_bind_latency();
      v10 = 0;
      goto LABEL_47;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v32 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_sensor_component_bind__alloc_tag;
    v33 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v32;
    v6[911] = v33;
    if ( !v33 )
      goto LABEL_45;
  }
  v21 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
  v6[914] = v21;
  if ( v21 )
    goto LABEL_27;
LABEL_36:
  v34 = (_QWORD *)v6[912];
  if ( (mem_trace_en & 1) != 0 )
    cam_mem_trace_free(v34, 0);
  else
    kvfree(v34);
LABEL_39:
  v35 = (_QWORD *)v6[913];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v35, 0);
  else
    kvfree(v35);
LABEL_42:
  v36 = (_QWORD *)v6[911];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v36, 0);
  else
    kvfree(v36);
LABEL_45:
  cam_unregister_subdev((__int64)(v6 + 821));
  v10 = -12;
LABEL_46:
  devm_kfree(a1);
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return v10;
}
