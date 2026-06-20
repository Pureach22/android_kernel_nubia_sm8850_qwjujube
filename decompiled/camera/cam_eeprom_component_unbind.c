_QWORD *__fastcall cam_eeprom_component_unbind(__int64 a1)
{
  _QWORD *v1; // x19
  int v3; // w8

  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       0x10000,
                       1,
                       "cam_eeprom_component_unbind",
                       607,
                       "eeprom device is NULL");
  if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10000,
      4,
      "cam_eeprom_component_unbind",
      611,
      "Component unbind called for: %s",
      *(const char **)(a1 - 16));
  mutex_lock(v1 + 5);
  cam_eeprom_shutdown(v1);
  mutex_unlock(v1 + 5);
  cam_unregister_subdev((__int64)(v1 + 467));
  cam_sensor_util_release_resources(v1 + 458, v1 + 11);
  *(_QWORD *)(a1 + 152) = 0;
  v3 = (unsigned __int8)mem_trace_en;
  v1[498] = 0;
  if ( v3 == 1 )
    return cam_mem_trace_free(v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
