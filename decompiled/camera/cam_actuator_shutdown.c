__int64 __fastcall cam_actuator_shutdown(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  int v3; // w8
  int v4; // w9
  _QWORD *v5; // x0
  _QWORD *v6; // x0

  v1 = *(_QWORD *)(result + 3392);
  v2 = result;
  if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 0x2000,
               4,
               "cam_actuator_shutdown",
               995,
               "Actuator shutdown in state: %d is_deferred_park_lens: %d",
               *(_DWORD *)(result + 3728),
               *(unsigned __int8 *)(result + 4728));
  if ( *(_BYTE *)(v2 + 4728) == 1 )
  {
    result = cam_common_wait_for_completion_timeout(v2 + 4736);
    if ( !result )
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                 3,
                 0x2000,
                 1,
                 "cam_actuator_wait_for_park_done",
                 532,
                 "Async park done completion timeout");
  }
  v3 = *(_DWORD *)(v2 + 3728);
  *(_BYTE *)(v2 + 4728) = 0;
  if ( v3 )
  {
    if ( v3 != 1 )
    {
      if ( (cam_actuator_power_down(v2) & 0x80000000) != 0 )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x2000,
          1,
          "cam_actuator_shutdown",
          1008,
          "Actuator Power down failed");
      *(_DWORD *)(v2 + 3728) = 1;
    }
    if ( (cam_destroy_device_hdl(*(unsigned int *)(v2 + 4584)) & 0x80000000) != 0 )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x2000,
        1,
        "cam_actuator_shutdown",
        1015,
        "destroying  dhdl failed");
    *(_QWORD *)(v2 + 4584) = -1;
    v4 = (unsigned __int8)mem_trace_en;
    *(_DWORD *)(v2 + 4592) = -1;
    v5 = *(_QWORD **)(v1 + 16);
    if ( v4 == 1 )
      cam_mem_trace_free(v5, 0);
    else
      kvfree(v5);
    v6 = *(_QWORD **)(v1 + 32);
    if ( mem_trace_en == 1 )
      result = (__int64)cam_mem_trace_free(v6, 0);
    else
      result = kvfree(v6);
    *(_QWORD *)(v1 + 16) = 0;
    *(_QWORD *)(v1 + 32) = 0;
    *(_WORD *)(v1 + 24) = 0;
    *(_WORD *)(v1 + 40) = 0;
    *(_DWORD *)(v2 + 4664) = 0;
    *(_DWORD *)(v2 + 3728) = 0;
  }
  return result;
}
