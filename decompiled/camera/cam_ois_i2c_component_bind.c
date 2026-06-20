__int64 __fastcall cam_ois_i2c_component_bind(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w21
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  _QWORD *v7; // x9
  __int64 v8; // x0
  _QWORD *v9; // x22
  unsigned int v10; // w0
  unsigned int v11; // w0
  _QWORD *v12; // x0
  _QWORD v14[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v15[3]; // [xsp+18h] [xbp-18h] BYREF

  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  v15[1] = 0;
  v14[0] = 0;
  v14[1] = 0;
  ktime_get_real_ts64(v15);
  if ( a1 == 32 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_i2c_component_bind",
      209,
      "Invalid Args client: %pK",
      nullptr);
    v3 = -22;
    goto LABEL_32;
  }
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(4736, 0xCC0u, 0, "cam_ois_i2c_component_bind", 0xD5u);
  else
    v2 = _kvmalloc_node_noprof(4736, 0, 3520, 0xFFFFFFFFLL);
  v4 = v2;
  if ( !v2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_i2c_component_bind",
      215,
      "CAM_MEM_ZALLOC failed");
    v3 = -12;
    goto LABEL_32;
  }
  if ( mem_trace_en == 1 )
  {
    v5 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_ois_i2c_component_bind", 0xDDu);
    *(_QWORD *)(v4 + 3664) = v5;
    if ( !v5 )
      goto LABEL_24;
LABEL_11:
    *(_QWORD *)(a1 + 152) = v4;
    v7 = *(_QWORD **)(v4 + 3664);
    *(_QWORD *)(v4 + 104) = a1 - 28;
    *(_QWORD *)(v4 + 88) = a1;
    *(_DWORD *)(v4 + 3656) = 2;
    *v7 = a1 - 32;
    if ( mem_trace_en == 1 )
      v8 = cam_mem_trace_alloc(104, 0xCC0u, 0, "cam_ois_i2c_component_bind", 0xEEu);
    else
      v8 = _kvmalloc_node_noprof(104, 0, 3520, 0xFFFFFFFFLL);
    v9 = (_QWORD *)v8;
    if ( v8 )
    {
      *(_QWORD *)(v4 + 3376) = v8;
      v10 = cam_ois_driver_soc_init(v4);
      if ( v10 )
      {
        v3 = v10;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x100000,
          1,
          "cam_ois_i2c_component_bind",
          247,
          "failed: cam_ois_driver_soc_init rc %d",
          v10);
      }
      else
      {
        *(_QWORD *)(v4 + 4120) = &cam_ois_internal_ops;
        *(_QWORD *)(v4 + 4112) = &cam_ois_subdev_ops;
        *(_QWORD *)(v4 + 4128) = v4;
        *(_QWORD *)(v4 + 4144) = v4;
        *(_QWORD *)v4 = 0x73696F2D6D6163LL;
        *(_DWORD *)(v4 + 4136) = 12;
        *(_DWORD *)(v4 + 4152) = 65549;
        *(_DWORD *)(v4 + 4184) = 1;
        *(_QWORD *)(v4 + 4648) = cam_ois_read_firmware_ver;
        *(_QWORD *)(v4 + 4656) = cam_ois_dw978x_firmware_download;
        *(_BYTE *)(v4 + 4728) = 0;
        v11 = cam_register_subdev(v4 + 3720);
        if ( !v11 )
        {
          ((void (__fastcall *)(__int64, __int64))cam_sensor_module_add_i2c_device)(v4, 3);
          *(_DWORD *)(v4 + 4192) = -1;
          _mutex_init(v4 + 32, "&(o_ctrl->ois_mutex)", &cam_ois_i2c_component_bind___key);
          *(_DWORD *)(v4 + 4512) = 0;
          ktime_get_real_ts64(v14);
          cam_record_bind_latency();
          v3 = 0;
          goto LABEL_32;
        }
        v3 = v11;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x100000,
          1,
          "cam_ois_init_subdev_param",
          188,
          "fail to create subdev");
      }
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v9, 0);
      else
        kvfree(v9);
    }
    else
    {
      v3 = -12;
    }
    v12 = *(_QWORD **)(v4 + 3664);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v12, 0);
    else
      kvfree(v12);
    goto LABEL_29;
  }
  v6 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v4 + 3664) = v6;
  if ( v6 )
    goto LABEL_11;
LABEL_24:
  v3 = -12;
LABEL_29:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v4, 0);
  else
    kvfree(v4);
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return v3;
}
