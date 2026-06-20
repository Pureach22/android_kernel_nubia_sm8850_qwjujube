_QWORD *__fastcall cam_eeprom_shutdown(_QWORD *result)
{
  int v1; // w8
  __int64 v2; // x20
  unsigned int *v3; // x19
  int v4; // w9
  _QWORD *v5; // x0
  _QWORD *v6; // x0

  v1 = *((_DWORD *)result + 1073);
  if ( v1 )
  {
    v2 = result[423];
    v3 = (unsigned int *)result;
    if ( v1 != 1 )
    {
      if ( v1 != 2 )
      {
LABEL_16:
        v3[1073] = 0;
        return result;
      }
      if ( (cam_eeprom_power_down((__int64)result) & 0x80000000) != 0 )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x10000,
          1,
          "cam_eeprom_shutdown",
          1452,
          "EEPROM Power down failed");
      v3[1073] = 1;
    }
    if ( (cam_destroy_device_hdl(v3[1052]) & 0x80000000) != 0 )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_eeprom_shutdown",
        1459,
        "destroying the device hdl");
    *((_QWORD *)v3 + 526) = -1;
    v4 = (unsigned __int8)mem_trace_en;
    v3[1054] = -1;
    v5 = *(_QWORD **)(v2 + 24);
    if ( v4 == 1 )
      cam_mem_trace_free(v5, 0);
    else
      kvfree(v5);
    v6 = *(_QWORD **)(v2 + 40);
    if ( mem_trace_en == 1 )
      result = cam_mem_trace_free(v6, 0);
    else
      result = (_QWORD *)kvfree(v6);
    *(_QWORD *)(v2 + 24) = 0;
    *(_QWORD *)(v2 + 40) = 0;
    *(_WORD *)(v2 + 32) = 0;
    *(_WORD *)(v2 + 48) = 0;
    goto LABEL_16;
  }
  return result;
}
