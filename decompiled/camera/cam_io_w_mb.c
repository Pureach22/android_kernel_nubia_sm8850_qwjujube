__int64 __fastcall cam_io_w_mb(int a1, const void *a2)
{
  if ( !a2 )
    return 4294967274LL;
  if ( (debug_mdl & 0x20000000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000000,
      4,
      "cam_io_w_mb",
      31,
      "0x%pK %08x",
      a2,
      a1);
  writel();
  return 0;
}
