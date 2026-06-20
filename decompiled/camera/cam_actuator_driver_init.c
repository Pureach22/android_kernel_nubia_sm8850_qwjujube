__int64 cam_actuator_driver_init()
{
  int v0; // w0
  int v1; // w0
  unsigned int v2; // w19
  __int64 node_opts_by_path; // x0
  __int64 v5; // x19
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v0 = _platform_driver_register(cam_actuator_platform_driver, &_this_module);
  if ( v0 < 0 )
  {
    v2 = v0;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_driver_init",
      806,
      "platform_driver_register failed rc = %d",
      v0);
    goto LABEL_6;
  }
  v1 = i2c_register_driver(&_this_module, &cam_actuator_i2c_driver);
  if ( v1 )
  {
    v2 = v1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_driver_init",
      812,
      "i2c_add_driver failed rc = %d",
      v1);
LABEL_4:
    platform_driver_unregister(cam_actuator_platform_driver);
    goto LABEL_6;
  }
  memset(&actuator_i3c_id, 0, 0x210u);
  node_opts_by_path = of_find_node_opts_by_path("/soc/qcom,cam-i3c-id-table", 0);
  if ( node_opts_by_path )
  {
    v5 = node_opts_by_path;
    if ( (unsigned int)cam_sensor_count_elems_i3c_device_id(node_opts_by_path, &v6, "i3c-actuator-id-table") )
    {
      v2 = 0;
      goto LABEL_6;
    }
    v2 = cam_sensor_fill_i3c_device_id(v5, v6, "i3c-actuator-id-table", &actuator_i3c_id);
    if ( !v2 )
    {
      v2 = i3c_driver_register_with_owner(&cam_actuator_i3c_driver, &_this_module);
      if ( !v2 )
        goto LABEL_6;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000,
        1,
        "cam_actuator_driver_init",
        836,
        "i3c_driver registration failed, rc: %d",
        v2);
    }
    i2c_del_driver(&cam_actuator_i2c_driver);
    goto LABEL_4;
  }
  v2 = 0;
  if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x2000,
      4,
      "cam_actuator_driver_init",
      820,
      "Couldnt Find the i3c-id-table dev node");
    v2 = 0;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return v2;
}
