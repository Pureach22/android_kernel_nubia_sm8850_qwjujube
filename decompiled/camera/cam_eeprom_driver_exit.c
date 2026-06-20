__int64 cam_eeprom_driver_exit()
{
  __int64 result; // x0

  platform_driver_unregister(cam_eeprom_platform_driver);
  driver_unregister(&off_BBCB0);
  i2c_del_driver(&cam_eeprom_i2c_driver);
  result = of_find_node_opts_by_path("/soc/qcom,cam-i3c-id-table", 0);
  if ( result )
    return i3c_driver_unregister(&cam_eeprom_i3c_driver);
  if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             debug_mdl & 0x10000,
             4,
             "cam_eeprom_driver_exit",
             930,
             "Couldnt Find the i3c-id-table dev node");
  return result;
}
