__int64 __fastcall _cam_icp_dump_dev_in_ready(__int64 a1, __int64 *a2)
{
  __int64 result; // x0
  unsigned int v4; // w20

  result = cam_context_dump_dev_to_hw(a1, a2);
  if ( (_DWORD)result )
  {
    v4 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "__cam_icp_dump_dev_in_ready",
      155,
      "[%s] ctx[%u]: Failed to dump device",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
    return v4;
  }
  return result;
}
