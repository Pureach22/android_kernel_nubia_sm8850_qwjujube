__int64 __fastcall cam_io_poll_value_wmask(unsigned int *a1, int a2, int a3, unsigned int a4, __int64 a5, __int64 a6)
{
  unsigned int v12; // w25
  bool v13; // zf
  _BOOL4 v14; // w26
  __int64 result; // x0

  if ( !a1 )
    return 4294967274LL;
  if ( ((unsigned int)readl_relaxed(a1) & a3) == a2 )
    return 0;
  v12 = 0;
  v13 = !a5 || a6 == 0;
  v14 = !v13;
  while ( a4 != v12 )
  {
    if ( v14 )
      usleep_range_state(a5, a6, 2);
    ++v12;
    if ( ((unsigned int)readl_relaxed(a1) & a3) == a2 )
      goto LABEL_15;
  }
  v12 = a4 + 1;
LABEL_15:
  if ( v12 <= a4 )
    return 0;
  result = 4294967274LL;
  if ( (debug_mdl & 0x20000000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x20000000,
      4,
      "cam_io_poll_value_wmask",
      156,
      "Poll failed with mask");
    return 4294967274LL;
  }
  return result;
}
