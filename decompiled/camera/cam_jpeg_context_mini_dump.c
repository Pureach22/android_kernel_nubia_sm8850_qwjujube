__int64 __fastcall cam_jpeg_context_mini_dump(const void *a1, const void *a2)
{
  unsigned int v2; // w19

  if ( !a1 || a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_jpeg_context_mini_dump",
      68,
      "Invalid param priv %pK args %pK",
      a1,
      a2);
    return (unsigned int)-22;
  }
  else
  {
    v2 = cam_context_mini_dump((unsigned __int64)a1, nullptr);
    if ( v2 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_context_mini_dump",
        75,
        "Mini Dump failed %d",
        v2);
  }
  return v2;
}
