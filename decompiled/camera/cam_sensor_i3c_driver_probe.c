__int64 __fastcall cam_sensor_i3c_driver_probe(__int64 a1)
{
  int v2; // w0
  const char *v3; // x7
  __int64 result; // x0
  const char *v5; // x6
  unsigned int v6; // w20
  __int64 v7; // x23
  __int64 v8; // x0
  const char *v9; // x6
  __int64 v10; // x0
  unsigned int v11; // w8
  bool v12; // cc
  const char *v13; // x6
  const char *v14; // x6
  unsigned __int64 StatusReg; // x24
  __int64 v16; // x25
  __int64 v17; // x0
  const char *v18; // x6
  unsigned int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_sensor_i3c_driver_probe",
      175,
      "Invalid input args");
    result = 4294967274LL;
    goto LABEL_34;
  }
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
  {
    v14 = *(const char **)(a1 + 112);
    if ( !v14 )
      v14 = *(const char **)a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_i3c_driver_probe",
      181,
      "Probe for I3C Slave %s",
      v14);
  }
  v2 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "cell-index", &v19, 1, 0);
  if ( v2 < 0 )
  {
    v5 = *(const char **)(a1 + 112);
    v6 = v2 & (v2 >> 31);
    if ( !v5 )
      v5 = *(const char **)a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_sensor_i3c_driver_probe",
      185,
      "device %s failed to read cell-index",
      v5);
    result = v6;
  }
  else
  {
    if ( v19 >= 0x10 )
    {
      v3 = *(const char **)(a1 + 112);
      if ( !v3 )
        v3 = *(const char **)a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_i3c_driver_probe",
        190,
        "Invalid Cell-Index: %u for %s",
        v19,
        v3);
      result = 4294967274LL;
      goto LABEL_34;
    }
    v7 = g_i3c_sensor_data[5 * v19];
    if ( v7 )
    {
      *(_QWORD *)(a1 + 152) = v7;
      if ( mem_trace_en == 1 )
      {
        v8 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_sensor_i3c_driver_probe", 0xCCu);
        *(_QWORD *)(v7 + 6488) = v8;
        if ( v8 )
          goto LABEL_21;
        goto LABEL_31;
      }
      v10 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v7 + 6488) = v10;
      if ( !v10 )
      {
LABEL_31:
        v18 = *(const char **)(a1 + 112);
        if ( !v18 )
          v18 = *(const char **)a1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_i3c_driver_probe",
          207,
          "Unable to allocate memory for QUP handle for %s",
          v18);
        result = 4294967284LL;
        goto LABEL_34;
      }
LABEL_21:
      while ( 1 )
      {
        cam_sensor_utils_parse_pm_ctrl_flag(*(_QWORD *)(v7 + 6560), v7 + 6480);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          3,
          "cam_sensor_i3c_driver_probe",
          215,
          "master: %d (1-CCI, 2-I2C, 3-SPI, 4-I3C) pm_ctrl_client_enable: %d",
          *(_DWORD *)(v7 + 6480),
          *(unsigned __int8 *)(*(_QWORD *)(v7 + 6488) + 16LL));
        *(_QWORD *)(*(_QWORD *)(v7 + 6488) + 8LL) = a1;
        v11 = v19;
        v12 = v19 > 0xF;
        *(_BYTE *)(*(_QWORD *)(v7 + 6488) + 17LL) = 0;
        if ( !v12 )
          break;
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v16 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &cam_sensor_i3c_driver_probe__alloc_tag;
        v17 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
        *(_QWORD *)(StatusReg + 80) = v16;
        *(_QWORD *)(v7 + 6488) = v17;
        if ( !v17 )
          goto LABEL_31;
      }
      complete_all(&g_i3c_sensor_data[5 * v11 + 1]);
      result = 0;
      if ( (debug_mdl & 0x20) != 0 && !debug_priority )
      {
        v13 = *(const char **)(a1 + 112);
        if ( !v13 )
          v13 = *(const char **)a1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20,
          4,
          "cam_sensor_i3c_driver_probe",
          222,
          "I3C Probe Finished for %s",
          v13);
        result = 0;
      }
    }
    else
    {
      v9 = *(const char **)(a1 + 112);
      if ( !v9 )
        v9 = *(const char **)a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_i3c_driver_probe",
        197,
        "S_ctrl is null. I3C Probe before platfom driver probe for %s",
        v9);
      result = 4294967274LL;
    }
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
