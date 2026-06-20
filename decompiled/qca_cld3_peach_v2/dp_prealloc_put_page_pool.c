__int64 __fastcall dp_prealloc_put_page_pool(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int *v10; // x8
  __int64 v11; // x4

  v10 = &g_dp_page_pool_allocs;
  if ( g_dp_page_pool_allocs == a2 && qword_16500 == a1 )
  {
    v11 = 0;
  }
  else
  {
    v10 = &dword_16528;
    if ( dword_16528 == a2 && qword_16530 == a1 )
    {
      v11 = 1;
    }
    else
    {
      v10 = &dword_16558;
      if ( dword_16558 == a2 && qword_16560 == a1 )
      {
        v11 = 2;
      }
      else
      {
        v10 = &dword_16588;
        if ( dword_16588 == a2 && qword_16590 == a1 )
        {
          v11 = 3;
        }
        else
        {
          v10 = &dword_165B8;
          if ( dword_165B8 != a2 || qword_165C0 != a1 )
            return qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: put page pool type %d failed",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "dp_prealloc_put_page_pool",
                     a2);
          v11 = 4;
        }
      }
    }
  }
  *((_BYTE *)v10 + 40) = 0;
  return qdf_trace_msg(
           0x45u,
           5u,
           "%s: put page pool:%d type %d to pre-alloc success",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "dp_prealloc_put_page_pool",
           v11,
           a2);
}
