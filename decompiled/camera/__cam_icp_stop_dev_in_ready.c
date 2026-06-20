__int64 __fastcall _cam_icp_stop_dev_in_ready(__int64 a1)
{
  unsigned int v2; // w20

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
  trace_cam_context_state_0(a1, a1);
  return v2;
}
