_QWORD *__fastcall cam_ois_i2c_component_unbind(__int64 a1)
{
  _QWORD *v1; // x19

  if ( a1 == 32 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       0x100000,
                       1,
                       "cam_ois_i2c_component_unbind",
                       288,
                       "Failed to get i2c client");
  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       0x100000,
                       1,
                       "cam_ois_i2c_component_unbind",
                       294,
                       "ois device is NULL");
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x100000,
    3,
    "cam_ois_i2c_component_unbind",
    298,
    "i2c driver remove invoked");
  mutex_lock(v1 + 4);
  cam_ois_shutdown(v1);
  mutex_unlock(v1 + 4);
  cam_unregister_subdev((__int64)(v1 + 465));
  cam_sensor_util_release_resources(v1 + 457, v1 + 10);
  v1[496] = 0;
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free(v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
