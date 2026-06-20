__int64 __fastcall _cam_icp_release_dev_in_acquired(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20

  cam_common_release_evt_params((_QWORD *)*(unsigned int *)(a1 + 60));
  result = cam_context_release_dev_to_hw(a1);
  if ( (_DWORD)result )
  {
    v3 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "__cam_icp_release_dev_in_acquired",
      125,
      "[%s] ctx[%u]: Unable to release device",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
    result = v3;
  }
  *(_DWORD *)(a1 + 240) = 1;
  return result;
}
