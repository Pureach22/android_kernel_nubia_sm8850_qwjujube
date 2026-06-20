__int64 *__fastcall _cam_req_mgr_tbl_set_all_skip_cnt(__int64 *result)
{
  __int64 v1; // x21
  int v2; // w23
  char v3; // w8
  int v4; // w9
  int v5; // w7

  v1 = *result;
  if ( *result )
  {
    v2 = *(_DWORD *)(v1 + 4);
    v3 = debug_mdl;
    v4 = debug_priority;
    do
    {
      v5 = *(_DWORD *)(v1 + 4);
      *(_DWORD *)(v1 + 16) = v2 - v5;
      if ( (v3 & 0x10) != 0 && !v4 )
      {
        result = (__int64 *)((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                              3,
                              v3 & 0x10,
                              4,
                              "__cam_req_mgr_tbl_set_all_skip_cnt",
                              803,
                              "%d: pd %d skip_traverse %d delta %d",
                              *(_DWORD *)v1,
                              v5,
                              v2 - v5,
                              *(_DWORD *)(v1 + 32));
        v3 = debug_mdl;
        v4 = debug_priority;
      }
      v1 = *(_QWORD *)(v1 + 24);
    }
    while ( v1 );
  }
  return result;
}
