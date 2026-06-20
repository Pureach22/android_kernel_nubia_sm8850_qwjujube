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
  if ( g_dp_page_pool_allocs == a2 && qword_15BE0 == a1 )
  {
    v11 = 0;
  }
  else
  {
    v10 = &dword_15C08;
    if ( dword_15C08 == a2 && qword_15C10 == a1 )
    {
      v11 = 1;
    }
    else
    {
      v10 = &dword_15C38;
      if ( dword_15C38 == a2 && qword_15C40 == a1 )
      {
        v11 = 2;
      }
      else
      {
        v10 = &dword_15C68;
        if ( dword_15C68 == a2 && qword_15C70 == a1 )
        {
          v11 = 3;
        }
        else
        {
          v10 = &dword_15C98;
          if ( dword_15C98 != a2 || qword_15CA0 != a1 )
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
