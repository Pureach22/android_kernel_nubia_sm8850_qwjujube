__int64 __fastcall cam_flash_get_dt_data(__int64 a1, __int64 a2)
{
  char *v2; // x23
  __int64 v5; // x0
  unsigned int v6; // w27
  __int64 v7; // x0
  __int64 v8; // x21
  unsigned int dt_properties; // w0
  const char *v10; // x5
  __int64 v11; // x4
  __int64 v12; // x25
  unsigned int v13; // w8
  unsigned int v14; // w6
  bool v15; // cf
  _QWORD *v16; // x0
  __int64 v17; // x24
  unsigned __int64 v18; // x22
  const char *v19; // x28
  __int64 v20; // x26
  __int64 v21; // x8
  unsigned __int64 v22; // x0
  const char *v23; // x21
  __int64 v24; // x28
  __int64 v25; // x25
  unsigned int variable_u32_array; // w0
  unsigned int v27; // w0
  int v28; // w0
  int v29; // w8
  __int64 v30; // x1
  unsigned __int64 StatusReg; // x21
  __int64 v32; // x22
  __int64 v33; // x0
  __int64 v35; // [xsp+8h] [xbp-68h]
  unsigned int v36; // [xsp+14h] [xbp-5Ch] BYREF
  _QWORD v37[11]; // [xsp+18h] [xbp-58h] BYREF

  v37[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_get_dt_data",
      380,
      "NULL flash control structure");
    v6 = -22;
    goto LABEL_56;
  }
  v2 = (char *)&unk_2FD000;
  if ( mem_trace_en == 1 )
  {
    v5 = cam_mem_trace_alloc(88, 0xCC0u, 0, "cam_flash_get_dt_data", 0x181u);
    *(_QWORD *)(a2 + 3296) = v5;
    if ( !v5 )
      goto LABEL_54;
  }
  else
  {
    v7 = _kvmalloc_node_noprof(88, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(a2 + 3296) = v7;
    if ( !v7 )
      goto LABEL_54;
  }
  while ( 2 )
  {
    v8 = *(_QWORD *)(a1 + 5544);
    if ( !v8 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_get_dt_data",
        392,
        "device node is NULL");
      v6 = -22;
LABEL_21:
      v16 = *(_QWORD **)(a2 + 3296);
      if ( v2[2904] == 1 )
        cam_mem_trace_free(v16, 0);
      else
        kvfree(v16);
      *(_QWORD *)(a2 + 3296) = 0;
      goto LABEL_55;
    }
    dt_properties = cam_soc_util_get_dt_properties(a2);
    if ( dt_properties )
    {
      v6 = dt_properties;
      v10 = "Get_dt_properties failed rc %d";
      v11 = 401;
LABEL_20:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_get_dt_data",
        v11,
        v10,
        v6);
      goto LABEL_21;
    }
    v12 = *(_QWORD *)(a2 + 3296);
    v36 = 0;
    *(_DWORD *)(a1 + 6716) = 0;
    *(_QWORD *)(a1 + 6136) = 0;
    *(_QWORD *)(a1 + 6144) = 0;
    *(_QWORD *)(a1 + 6240) = 0;
    *(_QWORD *)(a1 + 6248) = 0;
    *(_QWORD *)(a1 + 6256) = 0;
    *(_QWORD *)(a1 + 6264) = 0;
    if ( !of_get_property(v8, "leds", &v36) )
    {
      v6 = 0;
      goto LABEL_56;
    }
    v13 = v36;
    v14 = v36 >> 2;
    v15 = v36 >= 0xC;
    v36 >>= 2;
    if ( v15 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4096,
        1,
        "cam_get_led_source_node_info",
        305,
        "Invalid LED count: %d",
        v14);
      v6 = -22;
LABEL_19:
      v10 = "cam_flash_get_pmic_source_info failed rc %d";
      v11 = 417;
      goto LABEL_20;
    }
    *(_DWORD *)(a1 + 6144) = v14;
    if ( v13 < 4 )
    {
      v6 = 0;
LABEL_18:
      *(_DWORD *)(a1 + 6716) = 1;
      v2 = (char *)&unk_2FD000;
      if ( !v6 )
        goto LABEL_56;
      goto LABEL_19;
    }
    v17 = 0;
    v18 = 0;
    v6 = 0;
    v19 = "leds";
    v2 = (char *)(a1 + 6720);
    v35 = v8;
    while ( 1 )
    {
      memset(v37, 0, 80);
      if ( (unsigned int)_of_parse_phandle_with_args(v8, v19, 0, 0, (unsigned int)v18, v37) || (v20 = v37[0]) == 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          4096,
          2,
          "cam_get_led_source_node_info",
          315,
          "flash_src_node NULL");
        goto LABEL_27;
      }
      v21 = *(_QWORD *)(a1 + 3600);
      if ( v21 )
      {
        v22 = devm_of_led_get(v21 + 16, (unsigned int)v18);
        if ( v18 > 1 )
          goto LABEL_53;
        *(_QWORD *)v2 = v22;
        if ( v22 >= 0xFFFFFFFFFFFFF001LL )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4096,
            1,
            "cam_get_led_source_node_info",
            323,
            "failed to get led_classdev, rc=%d",
            v22);
          v6 = *(_DWORD *)v2;
          v2 = (char *)&unk_2FD000;
          if ( v6 )
            goto LABEL_19;
          goto LABEL_56;
        }
        v23 = v19;
        v24 = v12;
        v25 = v12 + v17;
        *((_QWORD *)v2 + 2) = v22;
        variable_u32_array = of_property_read_variable_u32_array(v20, "flash-max-microamp", v25 + 32, 1, 0);
        if ( (variable_u32_array & 0x80000000) != 0 )
        {
          v6 = variable_u32_array;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4096,
            2,
            "cam_get_led_source_node_info",
            334,
            "LED FLASH flash-max-microamp read fail: %d",
            variable_u32_array);
          v12 = v24;
          v19 = v23;
          v8 = v35;
          goto LABEL_27;
        }
        v27 = of_property_read_variable_u32_array(v20, "led-max-microamp", v25 + 72, 1, 0);
        v12 = v24;
        v19 = v23;
        v8 = v35;
        if ( (v27 & 0x80000000) != 0 )
        {
          v6 = v27;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4096,
            2,
            "cam_get_led_source_node_info",
            344,
            "LED-TORCH max-current read failed: %d",
            v27);
          goto LABEL_27;
        }
      }
      else if ( v18 > 2 )
      {
        goto LABEL_53;
      }
      v28 = of_property_read_variable_u32_array(v20, "flash-max-timeout-us", v12 + v17 + 40, 1, 0);
      v29 = debug_priority;
      if ( v28 < 0 && (debug_mdl & 0x1000) != 0 && !debug_priority )
        break;
      v30 = debug_mdl & 0x1000;
      if ( (debug_mdl & 0x1000) != 0 )
        goto LABEL_41;
LABEL_42:
      v6 = 0;
      if ( v30 && !v29 )
      {
        if ( v17 == 8 )
          goto LABEL_53;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v30,
          4,
          "cam_get_led_source_node_info",
          364,
          "MainFlashMaxCurrent[%d]: %d uA",
          v18,
          *(_DWORD *)(v12 + v17 + 32));
        v6 = 0;
      }
LABEL_27:
      ++v18;
      v17 += 4;
      v2 += 8;
      if ( v18 >= v36 )
        goto LABEL_18;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000,
      4,
      "cam_get_led_source_node_info",
      356,
      "max-duration prop unavailable: %d",
      v28 & (v28 >> 31));
    v29 = debug_priority;
    v30 = debug_mdl & 0x1000;
    if ( (debug_mdl & 0x1000) == 0 )
      goto LABEL_42;
LABEL_41:
    if ( v29 )
      goto LABEL_42;
    if ( v17 != 8 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v30,
        4,
        "cam_get_led_source_node_info",
        362,
        "TorchMaxCurrent[%d]: %d uA",
        v18,
        *(_DWORD *)(v12 + v17 + 72));
      v29 = debug_priority;
      v30 = debug_mdl & 0x1000;
      goto LABEL_42;
    }
LABEL_53:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v32 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_flash_get_dt_data__alloc_tag;
    v33 = _kvmalloc_node_noprof(88, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v32;
    *(_QWORD *)(a2 + 3296) = v33;
    if ( v33 )
      continue;
    break;
  }
LABEL_54:
  v6 = -12;
LABEL_55:
  cam_soc_util_release_platform_resource(a2);
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return v6;
}
