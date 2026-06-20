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
  if ( qword_16A58 == a1 )
  {
    v11 = 0;
  }
  else
  {
    v9 = &dword_16A68;
    if ( qword_16A78 == a1 )
    {
      v11 = 1;
    }
    else
    {
      v9 = &dword_16A88;
      if ( qword_16A98 == a1 )
      {
        v11 = 2;
      }
      else
      {
        v9 = &dword_16AA8;
        if ( qword_16AB8 == a1 )
        {
          v11 = 3;
        }
        else
        {
          v9 = &dword_16AC8;
          if ( qword_16AD8 == a1 )
          {
            v11 = 4;
          }
          else
          {
            v9 = &dword_16AE8;
            if ( qword_16AF8 == a1 )
            {
              v11 = 5;
            }
            else
            {
              v9 = &dword_16B08;
              if ( qword_16B18 == a1 )
              {
                v11 = 6;
              }
              else
              {
                v9 = &dword_16B28;
                if ( qword_16B38 == a1 )
                {
                  v11 = 7;
                }
                else
                {
                  v9 = &dword_16B48;
                  if ( qword_16B58 != a1 )
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
