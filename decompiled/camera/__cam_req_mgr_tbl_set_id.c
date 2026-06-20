__int64 __fastcall _cam_req_mgr_tbl_set_id(__int64 result, __int64 a2)
{
  int v2; // w6
  __int64 v3; // x23
  __int64 v4; // x24

  for ( ; result; result = *(_QWORD *)(result + 24) )
  {
    v2 = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(a2 + 16) = v2 + 1;
    *(_DWORD *)result = v2;
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    {
      v3 = a2;
      v4 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "__cam_req_mgr_tbl_set_id",
        774,
        "%d: pd %d skip_traverse %d delta %d",
        v2,
        *(_DWORD *)(result + 4),
        *(_DWORD *)(result + 16),
        *(_DWORD *)(result + 32));
      a2 = v3;
      result = v4;
    }
  }
  return result;
}
