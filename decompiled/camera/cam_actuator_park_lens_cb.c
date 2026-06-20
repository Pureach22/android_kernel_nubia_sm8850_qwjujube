__int64 __fastcall cam_actuator_park_lens_cb(__int64 a1)
{
  __int64 v2; // x22
  unsigned int v3; // w6
  unsigned int v4; // w20
  __int64 v5; // x8
  int v6; // w0
  int v7; // w20
  _QWORD *v8; // x0
  _QWORD *v9; // x0
  __int16 v10; // w8

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_park_lens_cb",
      447,
      "Invalid Args");
    return (unsigned int)-22;
  }
  v2 = *(_QWORD *)(a1 + 3392);
  mutex_lock(a1 + 4680);
  if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000,
      4,
      "cam_actuator_park_lens_cb",
      457,
      "Actuator park start in state: %d",
      *(_DWORD *)(a1 + 3728));
  v3 = *(_DWORD *)(a1 + 3728);
  if ( v3 > 1 )
  {
    if ( (cam_actuator_apply_settings(a1, a1 + 4256) & 0x80000000) != 0 )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x2000,
        1,
        "cam_actuator_park_lens_cb",
        468,
        "Apply park lens settings failed");
    v5 = *(_QWORD *)(a1 + 3392);
    if ( v5 != -8 )
    {
      v6 = cam_sensor_util_power_down(v5 + 8, a1 + 96);
      if ( v6 )
      {
        v7 = v6;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000,
          1,
          "cam_actuator_power_down",
          150,
          "power down the core is failed:%d",
          v6);
        if ( v7 < 0 )
          goto LABEL_15;
      }
      else
      {
        camera_io_release(a1 + 32);
      }
      *(_DWORD *)(a1 + 3728) = 0;
      *(_BYTE *)(a1 + 4728) = 0;
LABEL_18:
      v4 = delete_request(a1 + 4256);
      if ( (v4 & 0x80000000) != 0 )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x2000,
          1,
          "cam_actuator_park_lens_cb",
          483,
          "Fail in deleting the config settings");
      goto LABEL_20;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_power_down",
      145,
      "failed: power_info %pK",
      nullptr);
LABEL_15:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_park_lens_cb",
      472,
      "Actuator power down failed");
    goto LABEL_18;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x2000,
    1,
    "cam_actuator_park_lens_cb",
    460,
    "Actuator park in invalid state: %d",
    v3);
  v4 = -22;
LABEL_20:
  v8 = *(_QWORD **)(v2 + 16);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v8, 0);
  else
    kvfree(v8);
  v9 = *(_QWORD **)(v2 + 32);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v9, 0);
  else
    kvfree(v9);
  v10 = debug_mdl;
  *(_QWORD *)(v2 + 16) = 0;
  *(_QWORD *)(v2 + 32) = 0;
  *(_WORD *)(v2 + 40) = 0;
  *(_WORD *)(v2 + 24) = 0;
  if ( (v10 & 0x2000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v10 & 0x2000,
      4,
      "cam_actuator_park_lens_cb",
      492,
      "Actuator park end");
  mutex_unlock(a1 + 4680);
  complete_all(a1 + 4736);
  return v4;
}
