__int64 __fastcall cam_icp_context_mini_dump(unsigned __int64 a1, __int64 *a2)
{
  unsigned int v3; // w20

  if ( a1 && a2 )
  {
    v3 = cam_context_mini_dump(a1, a2);
    if ( v3 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_context_mini_dump",
        96,
        "[%s] ctx[%u]: Mini Dump failed rc %d",
        (const char *)a1,
        *(_DWORD *)(a1 + 32),
        v3);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_context_mini_dump",
      88,
      "Invalid priv %pK args %pK",
      (const void *)a1,
      a2);
    return (unsigned int)-22;
  }
  return v3;
}
