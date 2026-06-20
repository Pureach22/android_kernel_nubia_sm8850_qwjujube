__int64 __fastcall cam_sensor_notify_frame_skip(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  unsigned int v4; // w21

  if ( !a1 )
    return 4294967274LL;
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
  if ( !device_priv )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_notify_frame_skip",
      2401,
      "Device data is NULL");
    return 4294967274LL;
  }
  v3 = device_priv;
  if ( (debug_mdl & 0x1000020) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000020,
      4,
      "cam_sensor_notify_frame_skip",
      2406,
      "Sensor[%d] handle frame skip for req id: %lld",
      *(_DWORD *)(device_priv + 52),
      *(_QWORD *)(a1 + 8));
  mutex_lock(v3 + 3608);
  v4 = cam_sensor_apply_settings(v3, *(_QWORD *)(a1 + 8), 7u);
  if ( *(_WORD *)(v3 + 7558) == 1 && *(_BYTE *)(a1 + 42) == 1 )
  {
    cam_sensor_apply_settings(v3, *(_QWORD *)(a1 + 8), 0xCu);
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_notify_frame_skip",
        2418,
        "Sensor[%d] applying deferred settings from req id: %lld",
        *(_DWORD *)(v3 + 52),
        *(_QWORD *)(a1 + 8));
  }
  mutex_unlock(v3 + 3608);
  return v4;
}
