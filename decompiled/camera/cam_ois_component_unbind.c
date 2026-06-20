_QWORD *__fastcall cam_ois_component_unbind(__int64 a1)
{
  _QWORD *v1; // x19
  int v3; // w8

  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       0x100000,
                       1,
                       "cam_ois_component_unbind",
                       473,
                       "ois device is NULL");
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x100000,
    3,
    "cam_ois_component_unbind",
    477,
    "platform driver remove invoked");
  mutex_lock(v1 + 4);
  cam_ois_shutdown(v1);
  mutex_unlock(v1 + 4);
  cam_unregister_subdev((__int64)(v1 + 465));
  cam_sensor_util_release_resources(v1 + 457, v1 + 10);
  *(_QWORD *)(a1 + 152) = 0;
  v3 = (unsigned __int8)mem_trace_en;
  v1[496] = 0;
  if ( v3 == 1 )
    return cam_mem_trace_free(v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
