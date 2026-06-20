__int64 __fastcall cam_req_mgr_issue_resume(
        const void *a1,
        const void *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  if ( a1 && a2 )
    return _cam_req_mgr_send_evt(0, 3, 8, a1, a5, a6, a2);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    16,
    1,
    "cam_req_mgr_issue_resume",
    3714,
    "input args NULL %pK %pK",
    a2,
    a1);
  return 4294967274LL;
}
