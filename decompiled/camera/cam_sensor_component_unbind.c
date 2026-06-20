__int64 __fastcall cam_sensor_component_unbind(__int64 a1)
{
  _QWORD *v1; // x20
  _QWORD *v3; // x0
  _QWORD *v5; // x0
  _QWORD *v6; // x0
  _QWORD *v7; // x0

  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             32,
             1,
             "cam_sensor_component_unbind",
             704,
             "sensor device is NULL");
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_component_unbind",
      708,
      "Component unbind called for: %s",
      *(const char **)(a1 - 16));
  mutex_lock(v1 + 451);
  cam_sensor_shutdown(v1);
  mutex_unlock(v1 + 451);
  cam_unregister_subdev((__int64)(v1 + 821));
  cam_sensor_util_release_resources(v1 + 810, v1 + 4);
  v3 = (_QWORD *)v1[912];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v3, 0);
  else
    kvfree(v3);
  v5 = (_QWORD *)v1[911];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v5, 0);
  else
    kvfree(v5);
  v6 = (_QWORD *)v1[913];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v6, 0);
  else
    kvfree(v6);
  v7 = (_QWORD *)v1[914];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v7, 0);
  else
    kvfree(v7);
  *(_QWORD *)(a1 + 152) = 0;
  v1[852] = 0;
  return devm_kfree(a1);
}
