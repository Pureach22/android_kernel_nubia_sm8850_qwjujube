__int64 __fastcall cam_flash_i2c_component_bind(const char *a1)
{
  const char *v2; // x21
  __int64 v3; // x0
  unsigned int v4; // w21
  __int64 v5; // x19
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x9
  __int64 v9; // x8
  unsigned int dt_data; // w0
  const char *v11; // x5
  __int64 v12; // x4
  unsigned int inited; // w0
  _QWORD *v14; // x0
  __int64 v15; // x24
  __int64 v16; // x27
  unsigned __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  _QWORD *v22; // x9
  unsigned __int64 StatusReg; // x22
  __int64 v24; // x24
  _QWORD v26[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v27[3]; // [xsp+18h] [xbp-18h] BYREF

  v27[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  v27[1] = 0;
  v26[0] = 0;
  v26[1] = 0;
  ktime_get_real_ts64(v27);
  v2 = a1 - 32;
  if ( a1 == (const char *)&dword_20 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_i2c_component_bind",
      723,
      "Invalid Args client: %pK",
      nullptr);
    v4 = -22;
    goto LABEL_60;
  }
  if ( mem_trace_en == 1 )
    v3 = cam_mem_trace_alloc(6912, 0xCC0u, 0, "cam_flash_i2c_component_bind", 0x2D8u);
  else
    v3 = _kvmalloc_node_noprof(6912, 0, 3520, 0xFFFFFFFFLL);
  v5 = v3;
  if ( !v3 )
  {
LABEL_55:
    v4 = -12;
    goto LABEL_60;
  }
  while ( 2 )
  {
    if ( mem_trace_en == 1 )
    {
      v6 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_flash_i2c_component_bind", 0x2DDu);
      *(_QWORD *)(v5 + 6288) = v6;
      if ( !v6 )
        goto LABEL_56;
    }
    else
    {
      v7 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v5 + 6288) = v7;
      if ( !v7 )
      {
LABEL_56:
        v4 = -12;
LABEL_57:
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v5, 0);
        else
          kvfree(v5);
        goto LABEL_60;
      }
    }
    *((_QWORD *)a1 + 19) = v5;
    **(_QWORD **)(v5 + 6288) = v2;
    v8 = *((_QWORD *)a1 + 93);
    *(_QWORD *)(v5 + 48) = a1 - 28;
    *(_QWORD *)(v5 + 32) = a1;
    *(_QWORD *)(v5 + 5544) = v8;
    *(_DWORD *)(v5 + 6280) = 2;
    v9 = *((_QWORD *)a1 + 93);
    if ( v9 )
      a1 = *(const char **)(v9 + 16);
    else
      a1 = "<no-node>";
    dt_data = cam_flash_get_dt_data(v5, v5 + 24);
    if ( dt_data )
    {
      v4 = dt_data;
      v11 = "failed: cam_flash_get_dt_data rc %d";
      v12 = 750;
LABEL_18:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_i2c_component_bind",
        v12,
        v11,
        v4);
      goto LABEL_19;
    }
    inited = cam_flash_init_default_params(v5);
    if ( inited )
    {
      v4 = inited;
      v11 = "failed: cam_flash_init_default_params rc %d";
      v12 = 758;
      goto LABEL_18;
    }
    if ( *(_DWORD *)(v5 + 512) )
    {
      v15 = 0;
      v2 = "cam_flash_i2c_component_bind";
      while ( v15 != 10 )
      {
        v16 = v5 + 8 * v15;
        v17 = devm_regulator_get(*(_QWORD *)(v5 + 32), *(_QWORD *)(v16 + 520));
        *(_QWORD *)(v16 + 768) = v17;
        if ( !v17 || v17 >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( (_DWORD)v17 )
            v4 = v17;
          else
            v4 = -22;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4096,
            1,
            "cam_flash_i2c_component_bind",
            772,
            "get failed for regulator %s %d",
            *(const char **)(v16 + 520),
            v4);
          goto LABEL_19;
        }
        if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1000,
            4,
            "cam_flash_i2c_component_bind",
            776,
            "get for regulator %s",
            *(const char **)(v16 + 520));
        if ( ++v15 >= (unsigned __int64)*(unsigned int *)(v5 + 512) )
          goto LABEL_31;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v24 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_flash_i2c_component_bind__alloc_tag;
      v5 = _kvmalloc_node_noprof(6912, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v24;
      if ( v5 )
        continue;
      goto LABEL_55;
    }
    break;
  }
LABEL_31:
  v18 = *(_QWORD *)(v5 + 3232);
  if ( v18 )
  {
    if ( !*(_BYTE *)(v18 + 8) )
    {
      v4 = -22;
      if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x1000,
          4,
          "cam_flash_i2c_component_bind",
          783,
          "No GPIO found");
      goto LABEL_19;
    }
    if ( (cam_sensor_util_init_gpio_pin_tbl(v5 + 24, (__int64 *)(v5 + 3648)) & 0x80000000) != 0
      || !*(_QWORD *)(v5 + 3648) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_i2c_component_bind",
        791,
        "No/Error Flash GPIOs");
      v4 = -22;
      goto LABEL_19;
    }
  }
  else if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x1000,
      4,
      "cam_flash_i2c_component_bind",
      780,
      "No GPIO found");
  }
  v4 = cam_flash_init_subdev(v5);
  if ( v4 )
  {
LABEL_19:
    v14 = *(_QWORD **)(v5 + 6288);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v14, 0);
    else
      kvfree(v14);
    goto LABEL_57;
  }
  if ( mem_trace_en == 1 )
  {
    v19 = cam_mem_trace_alloc(1536, 0xCC0u, 0, "cam_flash_i2c_component_bind", 0x323u);
    *(_QWORD *)(v5 + 6584) = v19;
    if ( !v19 )
      goto LABEL_61;
  }
  else
  {
    v20 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v5 + 6584) = v20;
    if ( !v20 )
    {
LABEL_61:
      cam_unregister_subdev(v5 + 5552);
      v4 = -12;
      goto LABEL_19;
    }
  }
  ((void (__fastcall *)(__int64, __int64))cam_sensor_module_add_i2c_device)(v5, 2);
  v21 = 0;
  *(_QWORD *)(v5 + 6344) = v5 + 6344;
  *(_QWORD *)(v5 + 6352) = v5 + 6344;
  *(_QWORD *)(v5 + 6392) = v5 + 6392;
  *(_QWORD *)(v5 + 6400) = v5 + 6392;
  do
  {
    v22 = (_QWORD *)(*(_QWORD *)(v5 + 6584) + v21);
    v21 += 48;
    *v22 = v22;
    v22[1] = v22;
  }
  while ( v21 != 1536 );
  *(_QWORD *)(v5 + 6208) = cam_flash_i2c_pkt_parser;
  *(_QWORD *)(v5 + 6216) = cam_flash_i2c_apply_setting;
  *(_QWORD *)(v5 + 6224) = cam_flash_i2c_power_ops;
  *(_QWORD *)(v5 + 6232) = cam_flash_i2c_flush_request;
  *(_DWORD *)(v5 + 6024) = -1;
  *(_DWORD *)(v5 + 6032) = -1;
  *(_QWORD *)(v5 + 6040) = cam_flash_publish_dev_info;
  *(_QWORD *)(v5 + 6048) = cam_flash_establish_link;
  *(_QWORD *)(v5 + 6056) = cam_flash_apply_request;
  *(_QWORD *)(v5 + 6072) = cam_flash_flush_request;
  *(_DWORD *)(v5 + 6712) = 0;
  _mutex_init(v5 + 6152, "&(fctrl->flash_mutex)", &cam_flash_i2c_component_bind___key);
  *(_DWORD *)(v5 + 6200) = 0;
  ktime_get_real_ts64(v26);
  cam_record_bind_latency();
  v4 = 0;
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return v4;
}
