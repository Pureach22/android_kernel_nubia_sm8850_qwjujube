__int64 __fastcall cam_ois_component_bind(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  int v4; // w8
  __int64 v5; // x9
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x21
  unsigned int v10; // w0
  unsigned int v11; // w22
  unsigned int v12; // w0
  __int64 v13; // x8
  unsigned int v14; // w9
  unsigned int v15; // w8
  unsigned int v16; // w9
  char *v17; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v19; // x22
  _QWORD *v20; // x0
  _QWORD v22[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v23[3]; // [xsp+18h] [xbp-18h] BYREF

  v23[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  v23[1] = 0;
  v22[0] = 0;
  v22[1] = 0;
  ktime_get_real_ts64(v23);
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(4736, 0xCC0u, 0, "cam_ois_component_bind", 0x18Fu);
  else
    v2 = _kvmalloc_node_noprof(4736, 0, 3520, 0xFFFFFFFFLL);
  v3 = v2;
  if ( !v2 )
  {
LABEL_30:
    v11 = -12;
    goto LABEL_39;
  }
  while ( 1 )
  {
    v4 = (unsigned __int8)mem_trace_en;
    *(_QWORD *)(v3 + 24) = a1 - 16;
    *(_QWORD *)(v3 + 80) = a1 - 16;
    *(_QWORD *)(v3 + 88) = a1;
    v5 = *(_QWORD *)(a1 - 16);
    *(_DWORD *)(v3 + 3656) = 1;
    *(_QWORD *)(v3 + 104) = v5;
    if ( v4 == 1 )
    {
      v6 = cam_mem_trace_alloc(40, 0xCC0u, 0, "cam_ois_component_bind", 0x19Au);
      *(_QWORD *)(v3 + 3672) = v6;
      if ( !v6 )
        goto LABEL_31;
    }
    else
    {
      v7 = _kvmalloc_node_noprof(40, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v3 + 3672) = v7;
      if ( !v7 )
      {
LABEL_31:
        v11 = 0;
        goto LABEL_36;
      }
    }
    if ( mem_trace_en == 1 )
      v8 = cam_mem_trace_alloc(104, 0xCC0u, 0, "cam_ois_component_bind", 0x19Fu);
    else
      v8 = _kvmalloc_node_noprof(104, 0, 3520, 0xFFFFFFFFLL);
    v9 = v8;
    if ( !v8 )
    {
      v11 = -12;
      goto LABEL_33;
    }
    *(_QWORD *)(v3 + 3376) = v8;
    *(_QWORD *)(v8 + 16) = a1;
    _mutex_init(v3 + 32, "&(o_ctrl->ois_mutex)", &cam_ois_component_bind___key);
    v10 = cam_ois_driver_soc_init(v3);
    if ( v10 )
    {
      v11 = v10;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_component_bind",
        425,
        "failed: soc init rc %d",
        v10);
      goto LABEL_17;
    }
    *(_QWORD *)(v3 + 4120) = &cam_ois_internal_ops;
    *(_QWORD *)(v3 + 4112) = &cam_ois_subdev_ops;
    *(_QWORD *)(v3 + 4128) = v3;
    *(_QWORD *)(v3 + 4144) = v3;
    *(_QWORD *)v3 = 0x73696F2D6D6163LL;
    *(_DWORD *)(v3 + 4136) = 12;
    *(_DWORD *)(v3 + 4152) = 65549;
    *(_DWORD *)(v3 + 4184) = 1;
    *(_QWORD *)(v3 + 4648) = cam_ois_read_firmware_ver;
    *(_QWORD *)(v3 + 4656) = cam_ois_dw978x_firmware_download;
    *(_BYTE *)(v3 + 4728) = 0;
    v12 = cam_register_subdev(v3 + 3720);
    if ( v12 )
    {
      v11 = v12;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_init_subdev_param",
        188,
        "fail to create subdev");
      goto LABEL_17;
    }
    if ( *(_DWORD *)(v3 + 3656) == 1 )
    {
      v13 = *(_QWORD *)(v3 + 3672);
      if ( v13 )
      {
        v14 = *(unsigned __int16 *)(v9 + 8);
        *(_DWORD *)(v13 + 28) = 3;
        *(_WORD *)(v13 + 20) = v14 >> 1;
        *(_DWORD *)(v13 + 12) = *(unsigned __int8 *)(v9 + 10);
        goto LABEL_23;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_update_i2c_info",
        97,
        "failed: cci_client %pK",
        nullptr);
      v11 = -22;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_component_bind",
        435,
        "failed: to update i2c info rc %d",
        -22);
      cam_unregister_subdev(v3 + 3720);
LABEL_17:
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)v9, 0);
      else
        kvfree(v9);
LABEL_33:
      v20 = *(_QWORD **)(v3 + 3672);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v20, 0);
      else
        kvfree(v20);
LABEL_36:
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)v3, 0);
      else
        kvfree(v3);
      goto LABEL_39;
    }
LABEL_23:
    *(_DWORD *)(v3 + 4192) = -1;
    ((void (__fastcall *)(__int64, __int64))cam_sensor_module_add_i2c_device)(v3, 3);
    *(_QWORD *)(a1 + 152) = v3;
    v15 = *(_DWORD *)(v3 + 100);
    *(_DWORD *)(v3 + 4512) = 0;
    if ( v15 < 0x10 )
    {
      g_i3c_ois_data[5 * v15] = v3;
      v16 = *(_DWORD *)(v3 + 100);
      if ( v16 <= 0xF )
        break;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v19 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_ois_component_bind__alloc_tag;
    v3 = _kvmalloc_node_noprof(4736, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v19;
    if ( !v3 )
      goto LABEL_30;
  }
  v17 = (char *)&g_i3c_ois_data[5 * v16];
  *((_DWORD *)v17 + 2) = 0;
  _init_swait_queue_head(v17 + 16, "&x->wait", &init_completion___key_21);
  ktime_get_real_ts64(v22);
  cam_record_bind_latency();
  v11 = 0;
  if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x100000,
      4,
      "cam_ois_component_bind",
      451,
      "Component bound successfully");
    v11 = 0;
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return v11;
}
