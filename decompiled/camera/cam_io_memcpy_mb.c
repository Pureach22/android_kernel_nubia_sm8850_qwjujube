__int64 __fastcall cam_io_memcpy_mb(unsigned int *a1, unsigned int *a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int v6; // w25
  unsigned int v7; // t1
  unsigned int *v8; // x22
  unsigned int *v9; // x22
  unsigned int *v10; // x20
  unsigned int v11; // w21

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    if ( (debug_mdl & 0x20000000) != 0 && !debug_priority )
    {
      v10 = a1;
      v11 = a3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000000,
        4,
        "cam_io_memcpy_mb",
        97,
        "%pK %pK %d",
        a1,
        a2,
        a3);
      a3 = v11;
      a1 = v10;
    }
    __dsb(0xEu);
    if ( a3 >= 4 )
    {
      v6 = a3 >> 2;
      do
      {
        if ( (debug_mdl & 0x20000000) != 0 && !debug_priority )
        {
          v9 = a1;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20000000,
            4,
            "cam_io_memcpy_mb",
            105,
            "0x%pK %08x",
            a1,
            *a2);
          a1 = v9;
        }
        v7 = *a2++;
        v8 = a1 + 1;
        writel_relaxed(v7, a1);
        --v6;
        a1 = v8;
      }
      while ( v6 );
    }
    __dsb(0xEu);
    return 0;
  }
  return result;
}
