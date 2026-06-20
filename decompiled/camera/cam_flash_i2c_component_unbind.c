_QWORD *__fastcall cam_flash_i2c_component_unbind(__int64 a1)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x0
  int v4; // w8
  _QWORD *v5; // x0

  if ( a1 == 32 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       4096,
                       1,
                       "cam_flash_i2c_component_unbind",
                       857,
                       "Failed to get i2c client");
  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       4096,
                       1,
                       "cam_flash_i2c_component_unbind",
                       864,
                       "Flash device is NULL");
  if ( (unsigned int)precise_flash_timer_deinit(*(_QWORD *)(a1 + 152)) )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      2,
      "cam_flash_i2c_component_unbind",
      869,
      "hrtimer deinit failed");
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    4096,
    3,
    "cam_flash_i2c_component_unbind",
    870,
    "i2c driver remove invoked");
  v2 = (_QWORD *)v1[823];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v2, 0);
  else
    kvfree(v2);
  v4 = (unsigned __int8)mem_trace_en;
  v5 = (_QWORD *)v1[786];
  v1[823] = 0;
  if ( v4 == 1 )
    cam_mem_trace_free(v5, 0);
  else
    kvfree(v5);
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free(v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
