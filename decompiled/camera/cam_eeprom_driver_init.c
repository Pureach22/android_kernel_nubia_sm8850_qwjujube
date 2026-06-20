__int64 cam_eeprom_driver_init()
{
  int v0; // w0
  int v1; // w0
  int v2; // w0
  __int64 node_opts_by_path; // x0
  __int64 v4; // x19
  unsigned int v5; // w19
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  v0 = _platform_driver_register(cam_eeprom_platform_driver, &_this_module);
  if ( v0 < 0 )
  {
    v5 = v0;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_driver_init",
      869,
      "platform_driver_register failed rc = %d",
      v0);
    goto LABEL_19;
  }
  v1 = _spi_register_driver(&_this_module, &cam_eeprom_spi_driver);
  if ( v1 < 0 )
  {
    v5 = v1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_driver_init",
      875,
      "spi_register_driver failed rc = %d",
      v1);
LABEL_18:
    platform_driver_unregister(cam_eeprom_platform_driver);
    goto LABEL_19;
  }
  v2 = i2c_register_driver(&_this_module, &cam_eeprom_i2c_driver);
  if ( v2 < 0 )
  {
    v5 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_driver_init",
      881,
      "i2c_add_driver failed rc = %d",
      v2);
LABEL_17:
    driver_unregister(&off_BBCB0);
    goto LABEL_18;
  }
  memset(&eeprom_i3c_id, 0, 0x210u);
  node_opts_by_path = of_find_node_opts_by_path("/soc/qcom,cam-i3c-id-table", 0);
  if ( node_opts_by_path )
  {
    v4 = node_opts_by_path;
    if ( (unsigned int)cam_sensor_count_elems_i3c_device_id(node_opts_by_path, &v7, "i3c-eeprom-id-table") )
    {
      v5 = 0;
      goto LABEL_19;
    }
    v5 = cam_sensor_fill_i3c_device_id(v4, v7, "i3c-eeprom-id-table", &eeprom_i3c_id);
    if ( !v5 )
    {
      v5 = i3c_driver_register_with_owner(&cam_eeprom_i3c_driver, &_this_module);
      if ( !v5 )
        goto LABEL_19;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_eeprom_driver_init",
        905,
        "i3c_driver registration failed, rc: %d",
        v5);
    }
    i2c_del_driver(&cam_eeprom_i2c_driver);
    goto LABEL_17;
  }
  v5 = 0;
  if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x10000,
      4,
      "cam_eeprom_driver_init",
      889,
      "Couldnt Find the i3c-id-table dev node");
    v5 = 0;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v5;
}
