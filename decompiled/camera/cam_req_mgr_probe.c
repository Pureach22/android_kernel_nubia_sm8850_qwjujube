__int64 __fastcall cam_req_mgr_probe(__int64 a1)
{
  __int64 compatible_node; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x20
  __int64 v11; // x0
  int v12; // w0
  unsigned int v13; // w19
  unsigned int matched; // w0
  const char *v15; // x5
  unsigned int v16; // w19
  __int64 v17; // x4
  unsigned int v18; // w0
  unsigned int v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v19 = 0;
  cam_mem_trace_init();
  compatible_node = of_find_compatible_node(0, 0, (char *)off_9AE30 + 64);
  if ( compatible_node )
  {
    v3 = compatible_node;
    while ( (of_device_is_available(v3) & 1) == 0 || i2c_find_device_by_fwnode(v3 + 24) )
    {
      v3 = of_find_compatible_node(v3, 0, (char *)off_9AE30 + 64);
      if ( !v3 )
        goto LABEL_7;
    }
    goto LABEL_30;
  }
LABEL_7:
  v4 = of_find_compatible_node(0, 0, (char *)off_BCA78 + 64);
  if ( v4 )
  {
    v3 = v4;
    while ( (of_device_is_available(v3) & 1) == 0 || i2c_find_device_by_fwnode(v3 + 24) )
    {
      v3 = of_find_compatible_node(v3, 0, (char *)off_BCA78 + 64);
      if ( !v3 )
        goto LABEL_13;
    }
    goto LABEL_30;
  }
LABEL_13:
  v5 = of_find_compatible_node(0, 0, (char *)off_BBF78 + 64);
  if ( v5 )
  {
    v3 = v5;
    while ( (of_device_is_available(v3) & 1) == 0 || i2c_find_device_by_fwnode(v3 + 24) )
    {
      v3 = of_find_compatible_node(v3, 0, (char *)off_BBF78 + 64);
      if ( !v3 )
        goto LABEL_19;
    }
    goto LABEL_30;
  }
LABEL_19:
  v6 = of_find_compatible_node(0, 0, (char *)off_BBB30 + 64);
  if ( v6 )
  {
    v3 = v6;
    while ( (of_device_is_available(v3) & 1) == 0 || i2c_find_device_by_fwnode(v3 + 24) )
    {
      v3 = of_find_compatible_node(v3, 0, (char *)off_BBB30 + 64);
      if ( !v3 )
        goto LABEL_25;
    }
    goto LABEL_30;
  }
LABEL_25:
  v7 = of_find_compatible_node(0, 0, (char *)off_BC610 + 64);
  if ( v7 )
  {
    v3 = v7;
    while ( (of_device_is_available(v3) & 1) == 0 || i2c_find_device_by_fwnode(v3 + 24) )
    {
      v3 = of_find_compatible_node(v3, 0, (char *)off_BC610 + 64);
      if ( !v3 )
        goto LABEL_35;
    }
LABEL_30:
    if ( (unsigned int)__ratelimit(&cam_req_mgr_probe__rs, "cam_req_mgr_probe") )
      v8 = 3;
    else
      v8 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v8,
      16,
      3,
      "cam_req_mgr_probe",
      1214,
      "I2C device: %s not available, deferring probe",
      *(const char **)(v3 + 16));
    result = 4294966779LL;
    goto LABEL_34;
  }
LABEL_35:
  v10 = 0;
  while ( 1 )
  {
    v11 = of_find_compatible_node(v10, 0, "qcom,geni-i3c");
    if ( !v11 )
      break;
    v10 = v11;
    v12 = of_platform_populate(v11, &cam_sensor_module_dt_match, 0, 0);
    if ( v12 )
    {
      v13 = v12;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        1,
        "cam_req_mgr_probe",
        1227,
        "Failed to populate child nodes as platform devices for parent: %s, rc=%d",
        *(const char **)(v10 + 16),
        v12);
      result = v13;
      goto LABEL_34;
    }
  }
  matched = camera_component_match_add_drivers(a1 + 16, v20);
  if ( matched )
  {
    v15 = "Unable to match components, probe failed rc: %d";
    v16 = matched;
    v17 = 1236;
LABEL_43:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_probe",
      v17,
      v15,
      v16);
    result = v16;
    goto LABEL_34;
  }
  v18 = component_master_add_with_match(a1 + 16, cam_req_mgr_component_master_ops, v20[0]);
  if ( v18 )
  {
    v15 = "Unable to add master, probe failed rc: %d";
    v16 = v18;
    v17 = 1246;
    goto LABEL_43;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "cam-bypass-driver", &v19, 1, 0) & 0x80000000) != 0 )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      3,
      "cam_req_mgr_probe",
      1256,
      "bypass driver parameter not found");
  else
    cam_soc_util_set_bypass_drivers(v19);
  result = 0;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
