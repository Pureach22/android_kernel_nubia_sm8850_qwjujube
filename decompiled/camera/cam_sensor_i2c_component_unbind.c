_QWORD *__fastcall cam_sensor_i2c_component_unbind(__int64 a1)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x0
  _QWORD *v4; // x0
  _QWORD *v5; // x0
  _QWORD *v6; // x0
  int v7; // w8

  if ( a1 == 32 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       32,
                       1,
                       "cam_sensor_i2c_component_unbind",
                       461,
                       "Failed to get i2c client");
  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       32,
                       1,
                       "cam_sensor_i2c_component_unbind",
                       467,
                       "sensor device is NULL");
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_i2c_component_unbind",
      471,
      "i2c remove invoked");
  mutex_lock(v1 + 451);
  cam_sensor_shutdown(v1);
  mutex_unlock(v1 + 451);
  cam_unregister_subdev((__int64)(v1 + 821));
  cam_sensor_util_release_resources(v1 + 810, v1 + 4);
  v2 = (_QWORD *)v1[912];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v2, 0);
  else
    kvfree(v2);
  v4 = (_QWORD *)v1[911];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v4, 0);
  else
    kvfree(v4);
  v5 = (_QWORD *)v1[913];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v5, 0);
  else
    kvfree(v5);
  v6 = (_QWORD *)v1[914];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v6, 0);
  else
    kvfree(v6);
  v7 = (unsigned __int8)mem_trace_en;
  v1[852] = 0;
  if ( v7 == 1 )
    return cam_mem_trace_free(v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
