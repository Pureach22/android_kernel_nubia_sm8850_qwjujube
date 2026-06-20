__int64 __fastcall cam_eeprom_i2c_component_bind(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w20
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x21
  _QWORD *v9; // x8
  unsigned int v10; // w0
  const char *v11; // x5
  __int64 v12; // x4
  unsigned int updated; // w0
  unsigned int v14; // w0
  _QWORD *v15; // x0
  _QWORD v17[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v18[3]; // [xsp+18h] [xbp-18h] BYREF

  v18[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v18[1] = 0;
  v17[0] = 0;
  v17[1] = 0;
  ktime_get_real_ts64(v18);
  if ( a1 == 32 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_eeprom_i2c_component_bind",
      215,
      "Invalid Args client: %pK",
      nullptr);
    v3 = -22;
    goto LABEL_37;
  }
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(4408, 0xCC0u, 0, "cam_eeprom_i2c_component_bind", 0xDBu);
  else
    v2 = _kvmalloc_node_noprof(4408, 0, 3520, 0xFFFFFFFFLL);
  v4 = v2;
  if ( !v2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_i2c_component_bind",
      221,
      "CAM_MEM_ZALLOC failed");
    v3 = -12;
    goto LABEL_37;
  }
  if ( mem_trace_en == 1 )
  {
    v5 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_eeprom_i2c_component_bind", 0xE3u);
    *(_QWORD *)(v4 + 3672) = v5;
    if ( !v5 )
      goto LABEL_29;
  }
  else
  {
    v6 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v4 + 3672) = v6;
    if ( !v6 )
    {
LABEL_29:
      v3 = -12;
LABEL_34:
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)v4, 0);
      else
        kvfree(v4);
      goto LABEL_37;
    }
  }
  if ( mem_trace_en == 1 )
    v7 = cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_eeprom_i2c_component_bind", 0xE9u);
  else
    v7 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
  v8 = v7;
  if ( !v7 )
  {
    v3 = 0;
LABEL_31:
    v15 = *(_QWORD **)(v4 + 3672);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v15, 0);
    else
      kvfree(v15);
    goto LABEL_34;
  }
  *(_QWORD *)(v4 + 3384) = v7;
  *(_QWORD *)(a1 + 152) = v4;
  _mutex_init(v4 + 40, "&(e_ctrl->eeprom_mutex)", &cam_eeprom_i2c_component_bind___key);
  *(_QWORD *)(v4 + 4344) = v4 + 4344;
  *(_QWORD *)(v4 + 4352) = v4 + 4344;
  *(_QWORD *)(v4 + 112) = a1 - 28;
  *(_DWORD *)(v4 + 3664) = 2;
  v9 = *(_QWORD **)(v4 + 3672);
  *(_QWORD *)(v4 + 96) = a1;
  *v9 = a1 - 32;
  *(_DWORD *)(v4 + 4288) = 0;
  *(_QWORD *)(v4 + 4320) = 0;
  *(_QWORD *)(v4 + 4304) = 0;
  *(_BYTE *)(v4 + 4296) = 0;
  v10 = cam_eeprom_parse_dt(v4);
  if ( v10 )
  {
    v3 = v10;
    v11 = "failed: soc init rc %d";
    v12 = 258;
LABEL_19:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_i2c_component_bind",
      v12,
      v11,
      v3);
    goto LABEL_20;
  }
  updated = cam_eeprom_update_i2c_info(v4, (unsigned __int16 *)(v8 + 8));
  if ( updated )
  {
    v3 = updated;
    v11 = "failed: to update i2c info rc %d";
    v12 = 264;
    goto LABEL_19;
  }
  *(_QWORD *)(v4 + 4136) = &cam_eeprom_internal_ops;
  *(_QWORD *)(v4 + 4128) = &cam_eeprom_subdev_ops;
  *(_QWORD *)(v4 + 4144) = v4;
  *(_DWORD *)(v4 + 4152) = 12;
  strcpy((char *)v4, "cam-eeprom");
  *(_DWORD *)(v4 + 4168) = 65548;
  *(_QWORD *)(v4 + 4160) = v4;
  *(_DWORD *)(v4 + 4200) = 1;
  v14 = cam_register_subdev(v4 + 3736);
  if ( v14 )
  {
    v3 = v14;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_eeprom_init_subdev",
      193,
      "Fail with cam_register_subdev");
LABEL_20:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v8, 0);
    else
      kvfree(v8);
    goto LABEL_31;
  }
  ((void (__fastcall *)(__int64, __int64))cam_sensor_module_add_i2c_device)(v4, 1);
  if ( *(_WORD *)(v8 + 8) )
    *(_WORD *)(**(_QWORD **)(v4 + 3672) + 2LL) = *(_WORD *)(v8 + 8);
  *(_DWORD *)(v4 + 4292) = 0;
  *(_DWORD *)(v4 + 4208) = -1;
  *(_QWORD *)(v4 + 4224) = 0;
  *(_QWORD *)(v4 + 4232) = 0;
  *(_QWORD *)(v4 + 4240) = 0;
  ktime_get_real_ts64(v17);
  cam_record_bind_latency();
  v3 = 0;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return v3;
}
