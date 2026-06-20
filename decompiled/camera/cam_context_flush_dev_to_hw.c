__int64 __fastcall cam_context_flush_dev_to_hw(__int64 a1, __int64 *a2)
{
  int v2; // w8

  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_flush_dev_to_hw",
      1219,
      "Invalid input params %pK %pK",
      (const void *)a1,
      a2);
    return 4294967274LL;
  }
  if ( *(_QWORD *)(a1 + 208) )
  {
    v2 = *(_DWORD *)(*a2 + 16);
    if ( v2 )
    {
      if ( v2 == 1 )
      {
        *(_DWORD *)(a1 + 464) = *(_QWORD *)(*a2 + 24);
        return cam_context_flush_ctx_to_hw(a1);
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        2,
        1,
        "cam_context_flush_dev_to_hw",
        1239,
        "[%s][%d] Invalid flush type %d",
        (const char *)a1,
        *(_DWORD *)(a1 + 32),
        v2);
      return 4294967274LL;
    }
    return cam_context_flush_req_to_hw(a1, a2);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_flush_dev_to_hw",
      1226,
      "[%s][%d] HW interface is not ready",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
    return 4294967282LL;
  }
}
