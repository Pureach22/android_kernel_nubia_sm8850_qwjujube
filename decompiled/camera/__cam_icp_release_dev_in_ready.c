__int64 __fastcall _cam_icp_release_dev_in_ready(__int64 a1)
{
  int v2; // w21
  __int64 result; // x0
  unsigned int v4; // w19

  v2 = cam_context_stop_dev_to_hw(a1);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "__cam_icp_stop_dev_in_ready",
      243,
      "[%s] ctx[%u]: Failed to stop device",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
  *(_DWORD *)(a1 + 240) = 2;
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "__cam_icp_release_dev_in_ready",
      258,
      "[%s] ctx[%u]: Failed to stop device",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
  result = _cam_icp_release_dev_in_acquired(a1);
  if ( (_DWORD)result )
  {
    v4 = result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "__cam_icp_release_dev_in_ready",
      262,
      "Failed to release device");
    return v4;
  }
  return result;
}
