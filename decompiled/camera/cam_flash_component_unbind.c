__int64 __fastcall cam_flash_component_unbind(__int64 a1)
{
  _QWORD *v1; // x19
  int v3; // w8
  const char *v4; // x5
  __int64 v5; // x2
  __int64 v6; // x4

  v1 = *(_QWORD **)(a1 + 152);
  if ( v1 )
  {
    mutex_lock(v1 + 769);
    if ( (unsigned int)precise_flash_timer_deinit((__int64)v1) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4096,
        2,
        "cam_flash_component_unbind",
        661,
        "hrtimer deinit failed");
    cam_flash_shutdown(v1);
    mutex_unlock(v1 + 769);
    cam_unregister_subdev((__int64)(v1 + 694));
    cam_flash_put_source_node_data(v1);
    *(_QWORD *)(a1 + 152) = 0;
    v3 = (unsigned __int8)mem_trace_en;
    v1[725] = 0;
    if ( v3 == 1 )
      cam_mem_trace_free(v1, 0);
    else
      kvfree(v1);
    v4 = "Flash Sensor component unbind";
    v5 = 3;
    v6 = 669;
  }
  else
  {
    v4 = "Flash device is NULL";
    v5 = 1;
    v6 = 655;
  }
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
           3,
           4096,
           v5,
           "cam_flash_component_unbind",
           v6,
           v4);
}
