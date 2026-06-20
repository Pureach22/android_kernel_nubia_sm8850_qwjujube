__int64 __fastcall cam_io_w_same_offset_block(__int64 a1, unsigned int *a2, int a3)
{
  __int64 result; // x0
  int v7; // w9
  __int64 v8; // x24

  result = 4294967274LL;
  if ( a2 && a1 && a3 )
  {
    v7 = 0;
    do
    {
      v8 = v7;
      if ( (debug_mdl & 0x20000000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000000,
          4,
          "cam_io_w_same_offset_block",
          173,
          "i= %d len =%d val=%x addr =%pK",
          v7,
          a3,
          *(_DWORD *)(a1 + 4LL * v7),
          a2);
      writel_relaxed(*(_DWORD *)(a1 + 4 * v8), a2);
      v7 = v8 + 1;
    }
    while ( a3 != (_DWORD)v8 + 1 );
    return 0;
  }
  return result;
}
