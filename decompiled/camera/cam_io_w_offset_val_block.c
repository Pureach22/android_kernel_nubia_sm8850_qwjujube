__int64 __fastcall cam_io_w_offset_val_block(__int64 a1, char *a2, int a3)
{
  __int64 result; // x0
  int v7; // w8
  int v8; // w24
  unsigned int *v9; // x27

  result = 4294967274LL;
  if ( a2 && a1 && a3 )
  {
    v7 = 0;
    do
    {
      v8 = v7;
      v9 = (unsigned int *)(a1 + 8LL * v7);
      if ( (debug_mdl & 0x20000000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000000,
          4,
          "cam_io_w_offset_val_block",
          212,
          "i= %d len =%d val=%x addr_base =%pK reg=%x",
          v7,
          a3,
          v9[1],
          a2,
          *v9);
      writel_relaxed(v9[1], (unsigned int *)&a2[*v9]);
      v7 = v8 + 1;
    }
    while ( a3 != v8 + 1 );
    return 0;
  }
  return result;
}
