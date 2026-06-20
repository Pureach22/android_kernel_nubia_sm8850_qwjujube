__int64 __fastcall cam_icp_ctx_timer_start(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8

  result = crm_timer_init((const void **)(a1 + 29800), 200, a1, (__int64 (__fastcall *)(__int64))cam_icp_ctx_timer_cb);
  if ( (_DWORD)result )
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               256,
               1,
               "cam_icp_ctx_timer_start",
               979,
               "%s: Failed to start timer",
               (const char *)(a1 + 29824));
  v3 = debug_mdl;
  *(_DWORD *)(a1 + 29808) = 0;
  if ( (v3 & 0x2000100) != 0 && !debug_priority )
    return ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             v3 & 0x2000100,
             4,
             "cam_icp_ctx_timer_start",
             983,
             "%s: start timer",
             (const char *)(a1 + 29824));
  return result;
}
