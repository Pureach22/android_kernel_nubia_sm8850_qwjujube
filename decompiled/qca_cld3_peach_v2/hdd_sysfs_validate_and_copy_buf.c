__int64 __fastcall hdd_sysfs_validate_and_copy_buf(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x20
  __int64 result; // x0

  if ( a2 - 1 >= a4 )
  {
    sized_strscpy(a1, a3, a2);
    result = 0;
    if ( *(_BYTE *)(a1 + a4 - 1) == 10 )
      *(_BYTE *)(a1 + a4 - 1) = 0;
  }
  else
  {
    v12 = jiffies;
    if ( hdd_sysfs_validate_and_copy_buf___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command length is larger than %zu bytes",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "hdd_sysfs_validate_and_copy_buf",
        a2);
      hdd_sysfs_validate_and_copy_buf___last_ticks = v12;
    }
    return 4294967274LL;
  }
  return result;
}
