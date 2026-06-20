__int64 __fastcall cam_icp_device_timer_start(__int64 result)
{
  int v1; // w8
  int i; // w11
  __int64 v3; // x19
  int v4; // w20
  __int64 v5; // x21

  v1 = *(_DWORD *)(result + 64);
  if ( v1 )
  {
    for ( i = 0; ; ++i )
    {
      v3 = *(_QWORD *)(result + 56) + 584LL * i;
      v4 = i;
      if ( *(_DWORD *)(v3 + 576) == 1 && !*(_QWORD *)(v3 + 552) )
        break;
      if ( v1 == v4 + 1 )
        return result;
    }
    *(_QWORD *)(v3 + 568) = result;
    v5 = result;
    result = crm_timer_init(
               (const void **)(v3 + 552),
               400,
               *(_QWORD *)(result + 56) + 584LL * i,
               (__int64 (__fastcall *)(__int64))cam_icp_device_timer_cb);
    if ( (_DWORD)result )
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 256,
                 1,
                 "cam_icp_device_timer_start",
                 1001,
                 "[%s] Failed to start %s timer",
                 (const char *)(v5 + 112),
                 *(const char **)(*(_QWORD *)(v5 + 56) + 584LL * v4));
    *(_DWORD *)(v3 + 560) = 0;
  }
  return result;
}
