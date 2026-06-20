__int64 __fastcall cam_io_poll_value(unsigned int *a1, int a2, unsigned int a3, __int64 a4, __int64 a5)
{
  unsigned int v10; // w24
  bool v11; // zf
  _BOOL4 v12; // w25
  __int64 result; // x0

  if ( !a1 )
    return 4294967274LL;
  if ( (unsigned int)readl_relaxed(a1) == a2 )
    return 0;
  v10 = 0;
  v11 = !a4 || a5 == 0;
  v12 = !v11;
  while ( a3 != v10 )
  {
    if ( v12 )
      usleep_range_state(a4, a5, 2);
    ++v10;
    if ( (unsigned int)readl_relaxed(a1) == a2 )
      goto LABEL_15;
  }
  v10 = a3 + 1;
LABEL_15:
  if ( v10 <= a3 )
    return 0;
  result = 4294967274LL;
  if ( (debug_mdl & 0x20000000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x20000000,
      4,
      "cam_io_poll_value",
      131,
      "Poll failed by value");
    return 4294967274LL;
  }
  return result;
}
