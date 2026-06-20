_QWORD *__fastcall cam_eeprom_i2c_component_unbind(__int64 a1)
{
  _QWORD *v1; // x19

  if ( a1 == 32 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       0x10000,
                       1,
                       "cam_eeprom_i2c_component_unbind",
                       310,
                       "Failed to get i2c client");
  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       0x10000,
                       1,
                       "cam_eeprom_i2c_component_unbind",
                       316,
                       "eeprom device is NULL");
  if ( !v1[423] )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       0x10000,
                       1,
                       "cam_eeprom_i2c_component_unbind",
                       323,
                       "soc_info.soc_private is NULL");
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x10000,
    3,
    "cam_eeprom_i2c_component_unbind",
    327,
    "i2c driver remove invoked");
  mutex_lock(v1 + 5);
  cam_eeprom_shutdown(v1);
  mutex_unlock(v1 + 5);
  cam_unregister_subdev((__int64)(v1 + 467));
  cam_sensor_util_release_resources(v1 + 458, v1 + 11);
  v1[498] = 0;
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free(v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
