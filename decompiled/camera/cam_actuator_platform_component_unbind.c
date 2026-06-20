__int64 __fastcall cam_actuator_platform_component_unbind(__int64 a1)
{
  _QWORD *v1; // x20
  _QWORD *v3; // x0
  const char *v4; // x5
  __int64 v5; // x2
  __int64 v6; // x4

  v1 = *(_QWORD **)(a1 + 152);
  if ( v1 )
  {
    mutex_lock(v1 + 459);
    cam_actuator_shutdown(v1);
    mutex_unlock(v1 + 459);
    cam_unregister_subdev((__int64)(v1 + 467));
    cam_req_mgr_workq_destroy(v1 + 584);
    cam_sensor_util_release_resources(v1 + 4, v1 + 12);
    v3 = (_QWORD *)v1[556];
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v3, 0);
    else
      kvfree(v3);
    v1[556] = 0;
    v1[498] = 0;
    *(_QWORD *)(a1 + 152) = 0;
    devm_kfree(a1);
    v4 = "Actuator component unbinded";
    v5 = 3;
    v6 = 568;
  }
  else
  {
    v4 = "Actuator device is NULL";
    v5 = 1;
    v6 = 552;
  }
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
           3,
           0x2000,
           v5,
           "cam_actuator_platform_component_unbind",
           v6,
           v4);
}
