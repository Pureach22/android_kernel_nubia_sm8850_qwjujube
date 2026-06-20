__int64 __fastcall cam_req_mgr_workq_flush(__int64 a1)
{
  __int64 result; // x0

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             16,
             1,
             "cam_req_mgr_workq_flush",
             72,
             "workq is null");
  *(_DWORD *)(a1 + 56) = 1;
  result = cancel_work_sync();
  *(_DWORD *)(a1 + 56) = 0;
  return result;
}
