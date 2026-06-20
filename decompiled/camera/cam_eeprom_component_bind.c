__int64 __fastcall cam_eeprom_component_bind(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  int v4; // w10
  __int64 v5; // x9
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x22
  unsigned int v10; // w0
  unsigned int v11; // w21
  const char *v12; // x5
  __int64 v13; // x4
  unsigned int updated; // w0
  unsigned int v15; // w0
  int v16; // w8
  unsigned int v17; // w8
  unsigned int v18; // w9
  char *v19; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v21; // x22
  _QWORD *v22; // x0
  _QWORD v24[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v25[3]; // [xsp+18h] [xbp-18h] BYREF

  v25[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  v25[1] = 0;
  v24[0] = 0;
  v24[1] = 0;
  ktime_get_real_ts64(v25);
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(4408, 0xCC0u, 0, "cam_eeprom_component_bind", 0x20Cu);
  else
    v2 = _kvmalloc_node_noprof(4408, 0, 3520, 0xFFFFFFFFLL);
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
    *(_QWORD *)(v3 + 88) = a1 - 16;
    *(_QWORD *)(v3 + 96) = a1;
    v5 = *(_QWORD *)(a1 - 16);
    *(_DWORD *)(v3 + 4288) = 1;
    *(_QWORD *)(v3 + 4320) = 0;
    *(_QWORD *)(v3 + 112) = v5;
    *(_QWORD *)(v3 + 4304) = 0;
    *(_BYTE *)(v3 + 4296) = 0;
    *(_DWORD *)(v3 + 3664) = 1;
    if ( v4 == 1 )
    {
      v6 = cam_mem_trace_alloc(40, 0xCC0u, 0, "cam_eeprom_component_bind", 0x21Au);
      *(_QWORD *)(v3 + 3680) = v6;
      if ( !v6 )
        goto LABEL_31;
    }
    else
    {
      v7 = _kvmalloc_node_noprof(40, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v3 + 3680) = v7;
      if ( !v7 )
      {
LABEL_31:
        v11 = -12;
        goto LABEL_36;
      }
    }
    if ( mem_trace_en == 1 )
      v8 = cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_eeprom_component_bind", 0x221u);
    else
      v8 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
    v9 = v8;
    if ( !v8 )
    {
      v11 = -12;
      goto LABEL_33;
    }
    *(_QWORD *)(v3 + 3384) = v8;
    *(_QWORD *)(v8 + 16) = a1;
    _mutex_init(v3 + 40, "&(e_ctrl->eeprom_mutex)", &cam_eeprom_component_bind___key);
    v10 = cam_eeprom_parse_dt(v3);
    if ( v10 )
    {
      v11 = v10;
      v12 = "failed: soc init rc %d";
      v13 = 557;
LABEL_17:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_eeprom_component_bind",
        v13,
        v12,
        v11);
      goto LABEL_18;
    }
    updated = cam_eeprom_update_i2c_info(v3, (unsigned __int16 *)(v9 + 8));
    if ( updated )
    {
      v11 = updated;
      v12 = "failed: to update i2c info rc %d";
      v13 = 562;
      goto LABEL_17;
    }
    *(_QWORD *)(v3 + 4344) = v3 + 4344;
    *(_QWORD *)(v3 + 4352) = v3 + 4344;
    *(_QWORD *)(v3 + 4128) = &cam_eeprom_subdev_ops;
    *(_QWORD *)(v3 + 4136) = &cam_eeprom_internal_ops;
    *(_DWORD *)(v3 + 4152) = 12;
    *(_QWORD *)(v3 + 4144) = v3;
    *(_DWORD *)(v3 + 4168) = 65548;
    strcpy((char *)v3, "cam-eeprom");
    *(_QWORD *)(v3 + 4160) = v3;
    *(_DWORD *)(v3 + 4200) = 1;
    v15 = cam_register_subdev(v3 + 3736);
    if ( v15 )
      break;
    ((void (__fastcall *)(__int64, __int64))cam_sensor_module_add_i2c_device)(v3, 1);
    *(_QWORD *)(v3 + 4224) = 0;
    *(_DWORD *)(v3 + 4208) = -1;
    *(_QWORD *)(v3 + 4232) = 0;
    *(_QWORD *)(v3 + 4240) = 0;
    *(_QWORD *)(a1 + 152) = v3;
    v16 = debug_mdl;
    *(_DWORD *)(v3 + 4292) = 0;
    if ( (v16 & 0x10000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        *(_QWORD *)&v16 & 0x10000LL,
        4,
        "cam_eeprom_component_bind",
        579,
        "Component bound successfully");
    v17 = *(_DWORD *)(v3 + 108);
    if ( v17 < 0x10 )
    {
      g_i3c_eeprom_data[5 * v17] = v3;
      v18 = *(_DWORD *)(v3 + 108);
      if ( v18 <= 0xF )
      {
        v19 = (char *)&g_i3c_eeprom_data[5 * v18];
        *((_DWORD *)v19 + 2) = 0;
        _init_swait_queue_head(v19 + 16, "&x->wait", &init_completion___key_20);
        ktime_get_real_ts64(v24);
        cam_record_bind_latency();
        v11 = 0;
        goto LABEL_39;
      }
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v21 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_eeprom_component_bind__alloc_tag;
    v3 = _kvmalloc_node_noprof(4408, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v21;
    if ( !v3 )
      goto LABEL_30;
  }
  v11 = v15;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    32,
    1,
    "cam_eeprom_init_subdev",
    193,
    "Fail with cam_register_subdev");
LABEL_18:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v9, 0);
  else
    kvfree(v9);
LABEL_33:
  v22 = *(_QWORD **)(v3 + 3680);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v22, 0);
  else
    kvfree(v22);
LABEL_36:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v3, 0);
  else
    kvfree(v3);
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return v11;
}
