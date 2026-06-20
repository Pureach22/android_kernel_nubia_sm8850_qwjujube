_QWORD *__fastcall cam_actuator_i2c_component_unbind(__int64 a1)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x0
  int v4; // w8

  if ( a1 == 32 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       0x2000,
                       1,
                       "cam_actuator_i2c_component_unbind",
                       317,
                       "Failed to get i2c client");
  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       0x2000,
                       1,
                       "cam_actuator_i2c_component_unbind",
                       324,
                       "Actuator device is NULL");
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x2000,
    3,
    "cam_actuator_i2c_component_unbind",
    328,
    "i2c remove invoked");
  mutex_lock(v1 + 459);
  cam_actuator_shutdown(v1);
  mutex_unlock(v1 + 459);
  cam_unregister_subdev((__int64)(v1 + 467));
  cam_req_mgr_workq_destroy(v1 + 584);
  cam_sensor_util_release_resources(v1 + 4, v1 + 12);
  v2 = (_QWORD *)v1[556];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v2, 0);
  else
    kvfree(v2);
  v4 = (unsigned __int8)mem_trace_en;
  v1[556] = 0;
  v1[498] = 0;
  if ( v4 == 1 )
    return cam_mem_trace_free(v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
