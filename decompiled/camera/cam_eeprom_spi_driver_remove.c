_QWORD *__fastcall cam_eeprom_spi_driver_remove(__int64 a1)
{
  __int64 v1; // x8
  _QWORD *v2; // x19
  _QWORD *v3; // x0
  _QWORD *v5; // x20
  _QWORD *v6; // x0
  int v7; // w8
  int v8; // w8

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       0x10000,
                       1,
                       "cam_eeprom_spi_driver_remove",
                       834,
                       "Subdevice is NULL");
  v2 = *(_QWORD **)(v1 + 240);
  if ( !v2 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       0x10000,
                       1,
                       "cam_eeprom_spi_driver_remove",
                       840,
                       "eeprom device is NULL");
  mutex_lock(v2 + 5);
  cam_eeprom_shutdown(v2);
  mutex_unlock(v2 + 5);
  cam_unregister_subdev((__int64)(v2 + 467));
  v3 = (_QWORD *)v2[461];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v3, 0);
  else
    kvfree(v3);
  v5 = (_QWORD *)v2[423];
  v2[461] = 0;
  if ( v5 )
  {
    v6 = (_QWORD *)v5[7];
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v6, 0);
    else
      kvfree(v6);
    v7 = (unsigned __int8)mem_trace_en;
    v5[7] = 0;
    if ( v7 == 1 )
      cam_mem_trace_free(v5, 0);
    else
      kvfree(v5);
  }
  v8 = (unsigned __int8)mem_trace_en;
  v2[498] = 0;
  if ( v8 == 1 )
    return cam_mem_trace_free(v2, 0);
  else
    return (_QWORD *)kvfree(v2);
}
