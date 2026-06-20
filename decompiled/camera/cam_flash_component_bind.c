__int64 __fastcall cam_flash_component_bind(__int64 a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x19
  __int64 v4; // x8
  int dt_data; // w0
  __int64 result; // x0
  int inited; // w0
  unsigned int v8; // w19
  __int64 (__fastcall *v9)(); // x9
  __int64 (__fastcall *v10)(); // x8
  __int64 (__fastcall *v11)(); // x10
  __int64 (__fastcall *v12)(); // x12
  __int64 parent; // x0
  int v14; // w9
  __int16 v15; // w8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x11
  _QWORD *v19; // x13
  int v20; // w0
  __int16 v21; // w8
  int v22; // w21
  _QWORD *v23; // x0
  unsigned int v24; // w21
  _QWORD *v25; // x0
  _QWORD *v26; // x0
  int v27; // w8
  _QWORD v28[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v29[3]; // [xsp+18h] [xbp-18h] BYREF

  v29[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = 0;
  v29[1] = 0;
  v28[0] = 0;
  v28[1] = 0;
  ktime_get_real_ts64(v29);
  if ( (debug_mdl & 0x1000) == 0 || debug_priority )
  {
    if ( *(_QWORD *)(a1 + 744) )
      goto LABEL_4;
LABEL_42:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_component_bind",
      527,
      "of_node NULL");
    result = 4294967274LL;
    goto LABEL_59;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    debug_mdl & 0x1000,
    4,
    "cam_flash_component_bind",
    525,
    "Binding flash component");
  if ( !*(_QWORD *)(a1 + 744) )
    goto LABEL_42;
LABEL_4:
  if ( mem_trace_en == 1 )
    v2 = (_QWORD *)cam_mem_trace_alloc(6912, 0xCC0u, 0, "cam_flash_component_bind", 0x213u);
  else
    v2 = (_QWORD *)_kvmalloc_node_noprof(6912, 0, 3520, 0xFFFFFFFFLL);
  v3 = (__int64)v2;
  if ( !v2 )
  {
    result = 4294967284LL;
    goto LABEL_59;
  }
  v2[450] = a1 - 16;
  v4 = *(_QWORD *)(a1 + 744);
  v2[3] = a1 - 16;
  v2[4] = a1;
  v2[693] = v4;
  v2[6] = *(_QWORD *)(a1 - 16);
  *(_QWORD *)(a1 + 152) = v2;
  dt_data = cam_flash_get_dt_data(v2, v2 + 3);
  if ( dt_data )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_component_bind",
      545,
      "cam_flash_get_dt_data failed with %d",
      dt_data);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v3, 0);
    else
      kvfree(v3);
    result = 4294967274LL;
    goto LABEL_59;
  }
  if ( of_find_property(*(_QWORD *)(a1 + 744), "cci-master", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "cci-master", v3 + 6272, 1, 0) & 0x80000000) != 0 )
      *(_DWORD *)(v3 + 6272) = 0;
    if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000,
        4,
        "cam_flash_component_bind",
        559,
        "cci-master %d",
        *(_DWORD *)(v3 + 6272));
    *(_DWORD *)(v3 + 6280) = 1;
    inited = cam_flash_init_default_params(v3);
    if ( inited )
    {
      v8 = inited;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_component_bind",
        566,
        "failed: cam_flash_init_default_params rc %d",
        inited);
      result = v8;
      goto LABEL_59;
    }
    parent = of_get_parent(*(_QWORD *)(a1 + 744));
    if ( (of_property_read_variable_u32_array(parent, "cell-index", v3 + 6276, 1, 0) & 0x80000000) != 0 )
    {
      LOWORD(v14) = 0;
      *(_DWORD *)(v3 + 6276) = 0;
    }
    else
    {
      v14 = *(_DWORD *)(v3 + 6276);
    }
    v15 = debug_mdl;
    *(_WORD *)(*(_QWORD *)(v3 + 6296) + 32LL) = v14;
    if ( (v15 & 0x1000) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v15 & 0x1000,
        4,
        "cam_flash_component_bind",
        577,
        "cci-index %d",
        *(_DWORD *)(v3 + 6276));
    if ( mem_trace_en == 1 )
    {
      v16 = cam_mem_trace_alloc(1536, 0xCC0u, 0, "cam_flash_component_bind", 0x245u);
      *(_QWORD *)(v3 + 6584) = v16;
      if ( !v16 )
        goto LABEL_44;
    }
    else
    {
      v17 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v3 + 6584) = v17;
      if ( !v17 )
      {
LABEL_44:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          4096,
          1,
          "cam_flash_component_bind",
          583,
          "No Memory");
        v20 = -12;
        goto LABEL_45;
      }
    }
    v18 = 0;
    v10 = cam_flash_i2c_flush_request;
    *(_QWORD *)(v3 + 6344) = v3 + 6344;
    v11 = cam_flash_i2c_apply_setting;
    *(_QWORD *)(v3 + 6352) = v3 + 6344;
    v9 = cam_flash_i2c_power_ops;
    *(_QWORD *)(v3 + 6392) = v3 + 6392;
    *(_QWORD *)(v3 + 6400) = v3 + 6392;
    v12 = cam_flash_i2c_pkt_parser;
    do
    {
      v19 = (_QWORD *)(*(_QWORD *)(v3 + 6584) + v18);
      v18 += 48;
      *v19 = v19;
      v19[1] = v19;
    }
    while ( v18 != 1536 );
  }
  else
  {
    v9 = nullptr;
    v10 = cam_flash_pmic_flush_request;
    v11 = cam_flash_pmic_apply_setting;
    v12 = cam_flash_pmic_pkt_parser;
  }
  *(_QWORD *)(v3 + 6208) = v12;
  *(_QWORD *)(v3 + 6216) = v11;
  *(_QWORD *)(v3 + 6224) = v9;
  *(_QWORD *)(v3 + 6232) = v10;
  v20 = cam_flash_init_subdev(v3);
  if ( v20 )
  {
    if ( !*(_QWORD *)(v3 + 6296) )
    {
LABEL_49:
      v24 = v20;
      v25 = *(_QWORD **)(v3 + 6584);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v25, 0);
      else
        kvfree(v25);
      v26 = *(_QWORD **)(v3 + 3320);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v26, 0);
      else
        kvfree(v26);
      cam_soc_util_release_platform_resource(v3 + 24);
      v27 = (unsigned __int8)mem_trace_en;
      *(_QWORD *)(v3 + 6584) = 0;
      *(_QWORD *)(v3 + 3320) = 0;
      if ( v27 == 1 )
        cam_mem_trace_free((_QWORD *)v3, 0);
      else
        kvfree(v3);
      result = v24;
      goto LABEL_59;
    }
LABEL_45:
    v22 = v20;
    v23 = *(_QWORD **)(v3 + 6296);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v23, 0);
    else
      kvfree(v23);
    v20 = v22;
    *(_QWORD *)(v3 + 6296) = 0;
    goto LABEL_49;
  }
  ((void (__fastcall *)(__int64, __int64))cam_sensor_module_add_i2c_device)(v3, 2);
  *(_DWORD *)(v3 + 6024) = -1;
  *(_DWORD *)(v3 + 6032) = -1;
  *(_QWORD *)(v3 + 6040) = cam_flash_publish_dev_info;
  *(_QWORD *)(v3 + 6048) = cam_flash_establish_link;
  *(_QWORD *)(v3 + 6056) = cam_flash_apply_request;
  *(_QWORD *)(v3 + 6072) = cam_flash_flush_request;
  *(_DWORD *)(v3 + 6712) = 0;
  _mutex_init(v3 + 6152, "&(fctrl->flash_mutex)", &cam_flash_component_bind___key);
  v21 = debug_mdl;
  *(_DWORD *)(v3 + 6200) = 0;
  if ( (v21 & 0x1000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v21 & 0x1000,
      4,
      "cam_flash_component_bind",
      627,
      "Component bound successfully");
  ktime_get_real_ts64(v28);
  cam_record_bind_latency();
  result = 0;
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return result;
}
