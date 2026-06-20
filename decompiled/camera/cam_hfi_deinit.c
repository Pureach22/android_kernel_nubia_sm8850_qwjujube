void *__fastcall cam_hfi_deinit(__int64 a1)
{
  unsigned int v1; // w19
  __int64 v2; // x20
  void *result; // x0
  int v4; // w6

  v1 = a1;
  if ( (unsigned int)a1 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      82,
      "Invalid HFI index: %u from hdl:%d",
      a1,
      a1);
    v4 = -22;
    return (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     0x40000,
                     1,
                     "cam_hfi_deinit",
                     1330,
                     "Failed to get hfi info rc: %d for hdl: %d",
                     v4,
                     v1);
  }
  v2 = *(_QWORD *)&g_hfi[2 * (unsigned int)a1 + 2];
  if ( !v2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      89,
      "[%s] HFI interface not setup for client hdl: %d",
      byte_3EC,
      a1);
    v4 = -19;
    return (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     0x40000,
                     1,
                     "cam_hfi_deinit",
                     1330,
                     "Failed to get hfi info rc: %d for hdl: %d",
                     v4,
                     v1);
  }
  if ( (cam_presil_mode_enabled(a1) & 1) != 0 )
  {
    if ( (debug_mdl & 0x40000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000,
        4,
        "cam_hfi_deinit",
        1337,
        "[%s] HFI hdl: %d SYS_RESET Needed in presil for back to back hfi_init success",
        (const char *)(v2 + 1004),
        v1);
    hfi_send_system_cmd(v1, 65542, 0);
  }
  mutex_lock(v2 + 832);
  mutex_lock(v2 + 880);
  mutex_lock(v2 + 928);
  *(_BYTE *)(v2 + 976) = 0;
  *(_WORD *)(v2 + 1036) = 0;
  *(_BYTE *)(v2 + 1038) = 0;
  mutex_unlock(v2 + 928);
  mutex_unlock(v2 + 832);
  mutex_unlock(v2 + 880);
  result = memset((void *)v2, 0, 0x120u);
  *(_QWORD *)(v2 + 288) = 0;
  *(_QWORD *)(v2 + 296) = 0;
  *(_QWORD *)(v2 + 304) = 0;
  *(_QWORD *)(v2 + 312) = 0;
  *(_DWORD *)(v2 + 320) = 0;
  *(_QWORD *)(v2 + 984) = 0;
  *(_QWORD *)(v2 + 992) = 0;
  return result;
}
