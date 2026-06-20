__int64 __fastcall cam_io_memcpy(unsigned int *a1, unsigned int *a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int *v5; // x19
  unsigned int v6; // w20
  unsigned int v7; // w25
  unsigned int *v8; // x1
  unsigned int v9; // t1
  unsigned int *v10; // x22
  unsigned int *v11; // x22

  result = 4294967274LL;
  if ( a1 )
  {
    v5 = a2;
    if ( a2 )
    {
      if ( (debug_mdl & 0x20000000) != 0 && !debug_priority )
      {
        v6 = a3;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000000,
          4,
          "cam_io_memcpy",
          77,
          "%pK %pK %d",
          a1,
          a2,
          a3);
        a3 = v6;
        if ( v6 < 4 )
          return 0;
      }
      else if ( a3 < 4 )
      {
        return 0;
      }
      v7 = a3 >> 2;
      v8 = a1;
      do
      {
        if ( (debug_mdl & 0x20000000) != 0 && !debug_priority )
        {
          v11 = v8;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20000000,
            4,
            "cam_io_memcpy",
            80,
            "0x%pK %08x",
            v8,
            *v5);
          v8 = v11;
        }
        v9 = *v5++;
        v10 = v8 + 1;
        writel_relaxed(v9, v8);
        --v7;
        v8 = v10;
      }
      while ( v7 );
      return 0;
    }
  }
  return result;
}
