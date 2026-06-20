__int64 __fastcall cam_actuator_i2c_component_bind(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w22
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  _QWORD *v8; // x20
  _QWORD *v9; // x8
  unsigned int v10; // w0
  unsigned int v11; // w0
  const char *v12; // x3
  const char *v13; // x5
  __int64 v14; // x4
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  _QWORD *v18; // x9
  _QWORD *v19; // x0
  _QWORD *v20; // x0
  _QWORD v22[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v23[3]; // [xsp+18h] [xbp-18h] BYREF

  v23[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  v23[1] = 0;
  v22[0] = 0;
  v22[1] = 0;
  ktime_get_real_ts64(v23);
  if ( a1 == 32 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_i2c_component_bind",
      201,
      "Failed to get i2c client");
    v3 = -14;
    goto LABEL_46;
  }
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(4832, 0xCC0u, 0, "cam_actuator_i2c_component_bind", 0xCEu);
  else
    v2 = _kvmalloc_node_noprof(4832, 0, 3520, 0xFFFFFFFFLL);
  v4 = v2;
  if ( !v2 )
  {
    v3 = -12;
    goto LABEL_46;
  }
  if ( mem_trace_en == 1 )
  {
    v5 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_actuator_i2c_component_bind", 0xD3u);
    *(_QWORD *)(v4 + 40) = v5;
    if ( !v5 )
      goto LABEL_38;
LABEL_11:
    *(_QWORD *)(a1 + 152) = v4;
    if ( mem_trace_en == 1 )
      v7 = cam_mem_trace_alloc(96, 0xCC0u, 0, "cam_actuator_i2c_component_bind", 0xDCu);
    else
      v7 = _kvmalloc_node_noprof(96, 0, 3520, 0xFFFFFFFFLL);
    v8 = (_QWORD *)v7;
    if ( !v7 )
    {
      v3 = -12;
LABEL_40:
      v20 = *(_QWORD **)(v4 + 40);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v20, 0);
      else
        kvfree(v20);
      goto LABEL_43;
    }
    v9 = *(_QWORD **)(v4 + 40);
    *(_QWORD *)(v4 + 3392) = v7;
    *v9 = a1 - 32;
    *(_QWORD *)(v4 + 104) = a1;
    *(_QWORD *)(v4 + 120) = a1 - 28;
    *(_DWORD *)(v4 + 32) = 2;
    v10 = cam_actuator_parse_dt(v4, a1);
    if ( (v10 & 0x80000000) != 0 )
    {
      v3 = v10;
      v12 = "cam_actuator_i2c_component_bind";
      v13 = "failed: cam_actuator_parse_dt rc %d";
      v14 = 238;
      goto LABEL_19;
    }
    *(_QWORD *)(v4 + 4136) = &cam_actuator_internal_ops;
    *(_QWORD *)(v4 + 4128) = &cam_actuator_subdev_ops;
    *(_QWORD *)(v4 + 4144) = v4;
    *(_QWORD *)(v4 + 4160) = v4;
    strcpy((char *)v4, "cam-actuator-driver");
    *(_DWORD *)(v4 + 4152) = 12;
    *(_DWORD *)(v4 + 4168) = 65545;
    *(_DWORD *)(v4 + 4200) = 1;
    v11 = cam_register_subdev(v4 + 3736);
    if ( v11 )
    {
      v3 = v11;
      v12 = "cam_actuator_init_subdev";
      v13 = "Fail with cam_register_subdev rc: %d";
      v14 = 177;
LABEL_19:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        0x2000,
        1,
        v12,
        v14,
        v13,
        v3);
      goto LABEL_20;
    }
    if ( *(_WORD *)v8 )
      *(_WORD *)(**(_QWORD **)(v4 + 40) + 2LL) = *(_WORD *)v8;
    if ( mem_trace_en == 1 )
    {
      v15 = cam_mem_trace_alloc(1536, 0xCC0u, 0, "cam_actuator_i2c_component_bind", 0xFCu);
      *(_QWORD *)(v4 + 4448) = v15;
      if ( !v15 )
        goto LABEL_47;
    }
    else
    {
      v16 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v4 + 4448) = v16;
      if ( !v16 )
      {
LABEL_47:
        v3 = -12;
LABEL_48:
        cam_unregister_subdev(v4 + 3736);
LABEL_20:
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v8, 0);
        else
          kvfree(v8);
        goto LABEL_40;
      }
    }
    ((void (__fastcall *)(__int64, _QWORD))cam_sensor_module_add_i2c_device)(v4, 0);
    v17 = 0;
    *(_QWORD *)(v4 + 4208) = v4 + 4208;
    *(_QWORD *)(v4 + 4216) = v4 + 4208;
    *(_QWORD *)(v4 + 4256) = v4 + 4256;
    *(_QWORD *)(v4 + 4264) = v4 + 4256;
    do
    {
      v18 = (_QWORD *)(*(_QWORD *)(v4 + 4448) + v17);
      v17 += 48;
      *v18 = v18;
      v18[1] = v18;
    }
    while ( v17 != 1536 );
    _mutex_init(v4 + 4680, "&a_ctrl->actuator_park_mutex", &cam_actuator_i2c_component_bind___key);
    *(_DWORD *)(v4 + 4736) = 0;
    _init_swait_queue_head(v4 + 4744, "&x->wait", &init_completion___key_17);
    v3 = cam_req_mgr_workq_create(
           "cam_actuator_worker",
           1u,
           (__int64 *)(v4 + 4672),
           0,
           0,
           (__int64)cam_actuator_process_workq);
    if ( (v3 & 0x80000000) == 0 )
    {
      *(_DWORD *)(v4 + 4664) = 0;
      *(_DWORD *)(v4 + 4584) = -1;
      *(_DWORD *)(v4 + 4592) = -1;
      *(_QWORD *)(v4 + 4600) = cam_actuator_publish_dev_info;
      *(_QWORD *)(v4 + 4608) = cam_actuator_establish_link;
      *(_QWORD *)(v4 + 4616) = cam_actuator_apply_request;
      *(_DWORD *)(v4 + 3728) = 0;
      ktime_get_real_ts64(v22);
      cam_record_bind_latency();
      goto LABEL_46;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_i2c_component_bind",
      273,
      "Unable to create worker");
    v19 = *(_QWORD **)(v4 + 4448);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v19, 0);
    else
      kvfree(v19);
    *(_QWORD *)(v4 + 4448) = 0;
    goto LABEL_48;
  }
  v6 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v4 + 40) = v6;
  if ( v6 )
    goto LABEL_11;
LABEL_38:
  v3 = -12;
LABEL_43:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v4, 0);
  else
    kvfree(v4);
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return v3;
}
