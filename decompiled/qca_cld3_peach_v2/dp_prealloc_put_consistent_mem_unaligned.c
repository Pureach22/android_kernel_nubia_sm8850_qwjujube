void *__fastcall dp_prealloc_put_consistent_mem_unaligned(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int *v9; // x19
  __int64 v11; // x4
  void *v12; // x0
  size_t v13; // x1

  v9 = g_dp_consistent_unaligned_allocs;
  if ( qword_17378 == a1 )
  {
    v11 = 0;
  }
  else
  {
    v9 = &dword_17388;
    if ( qword_17398 == a1 )
    {
      v11 = 1;
    }
    else
    {
      v9 = &dword_173A8;
      if ( qword_173B8 == a1 )
      {
        v11 = 2;
      }
      else
      {
        v9 = &dword_173C8;
        if ( qword_173D8 == a1 )
        {
          v11 = 3;
        }
        else
        {
          v9 = &dword_173E8;
          if ( qword_173F8 == a1 )
          {
            v11 = 4;
          }
          else
          {
            v9 = &dword_17408;
            if ( qword_17418 == a1 )
            {
              v11 = 5;
            }
            else
            {
              v9 = &dword_17428;
              if ( qword_17438 == a1 )
              {
                v11 = 6;
              }
              else
              {
                v9 = &dword_17448;
                if ( qword_17458 == a1 )
                {
                  v11 = 7;
                }
                else
                {
                  v9 = &dword_17468;
                  if ( qword_17478 != a1 )
                    return (void *)qdf_trace_msg(
                                     0x45u,
                                     2u,
                                     "%s: unable to find vaddr %pK",
                                     a2,
                                     a3,
                                     a4,
                                     a5,
                                     a6,
                                     a7,
                                     a8,
                                     a9,
                                     "dp_prealloc_put_consistent_mem_unaligned",
                                     a1);
                  v11 = 8;
                }
              }
            }
          }
        }
      }
    }
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: index %d, returned",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_prealloc_put_consistent_mem_unaligned",
    v11);
  v12 = *((void **)v9 + 2);
  v13 = (unsigned int)v9[1];
  *((_BYTE *)v9 + 8) = 0;
  return qdf_mem_set(v12, v13, 0);
}
