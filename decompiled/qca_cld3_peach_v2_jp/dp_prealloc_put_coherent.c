void *__fastcall dp_prealloc_put_coherent(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  _QWORD *v10; // x19
  __int64 v12; // x4
  void *v13; // x0
  size_t v14; // x1

  v10 = &g_dp_consistent_allocs;
  if ( qword_15CD8 == a10 )
  {
    v12 = 0;
  }
  else
  {
    v10 = &unk_15CF8;
    if ( qword_15D08 == a10 )
    {
      v12 = 1;
    }
    else
    {
      v10 = &unk_15D28;
      if ( qword_15D38 == a10 )
      {
        v12 = 2;
      }
      else
      {
        v10 = &unk_15D58;
        if ( qword_15D68 == a10 )
        {
          v12 = 3;
        }
        else
        {
          v10 = &unk_15D88;
          if ( qword_15D98 == a10 )
          {
            v12 = 4;
          }
          else
          {
            v10 = &unk_15DB8;
            if ( qword_15DC8 == a10 )
            {
              v12 = 5;
            }
            else
            {
              v10 = &unk_15DE8;
              if ( qword_15DF8 == a10 )
              {
                v12 = 6;
              }
              else
              {
                v10 = &unk_15E18;
                if ( qword_15E28 == a10 )
                {
                  v12 = 7;
                }
                else
                {
                  v10 = &unk_15E48;
                  if ( qword_15E58 == a10 )
                  {
                    v12 = 8;
                  }
                  else
                  {
                    v10 = &unk_15E78;
                    if ( qword_15E88 == a10 )
                    {
                      v12 = 9;
                    }
                    else
                    {
                      v10 = &unk_15EA8;
                      if ( qword_15EB8 == a10 )
                      {
                        v12 = 10;
                      }
                      else
                      {
                        v10 = &unk_15ED8;
                        if ( qword_15EE8 == a10 )
                        {
                          v12 = 11;
                        }
                        else
                        {
                          v10 = &unk_15F08;
                          if ( qword_15F18 == a10 )
                          {
                            v12 = 12;
                          }
                          else
                          {
                            v10 = &unk_15F38;
                            if ( qword_15F48 == a10 )
                            {
                              v12 = 13;
                            }
                            else
                            {
                              v10 = &unk_15F68;
                              if ( qword_15F78 == a10 )
                              {
                                v12 = 14;
                              }
                              else
                              {
                                v10 = &unk_15F98;
                                if ( qword_15FA8 == a10 )
                                {
                                  v12 = 15;
                                }
                                else
                                {
                                  v10 = &unk_15FC8;
                                  if ( qword_15FD8 == a10 )
                                  {
                                    v12 = 16;
                                  }
                                  else
                                  {
                                    v10 = &unk_15FF8;
                                    if ( qword_16008 == a10 )
                                    {
                                      v12 = 17;
                                    }
                                    else
                                    {
                                      v10 = &unk_16028;
                                      if ( qword_16038 == a10 )
                                      {
                                        v12 = 18;
                                      }
                                      else
                                      {
                                        v10 = &unk_16058;
                                        if ( qword_16068 == a10 )
                                        {
                                          v12 = 19;
                                        }
                                        else
                                        {
                                          v10 = &unk_16088;
                                          if ( qword_16098 == a10 )
                                          {
                                            v12 = 20;
                                          }
                                          else
                                          {
                                            v10 = &unk_160B8;
                                            if ( qword_160C8 == a10 )
                                            {
                                              v12 = 21;
                                            }
                                            else
                                            {
                                              v10 = &unk_160E8;
                                              if ( qword_160F8 == a10 )
                                              {
                                                v12 = 22;
                                              }
                                              else
                                              {
                                                v10 = &unk_16118;
                                                if ( qword_16128 == a10 )
                                                {
                                                  v12 = 23;
                                                }
                                                else
                                                {
                                                  v10 = &unk_16148;
                                                  if ( qword_16158 == a10 )
                                                  {
                                                    v12 = 24;
                                                  }
                                                  else
                                                  {
                                                    v10 = &unk_16178;
                                                    if ( qword_16188 == a10 )
                                                    {
                                                      v12 = 25;
                                                    }
                                                    else
                                                    {
                                                      v10 = &unk_161A8;
                                                      if ( qword_161B8 == a10 )
                                                      {
                                                        v12 = 26;
                                                      }
                                                      else
                                                      {
                                                        v10 = &unk_161D8;
                                                        if ( qword_161E8 != a10 )
                                                          return (void *)qdf_trace_msg(
                                                                           0x45u,
                                                                           2u,
                                                                           "%s: unable to find vaddr %pK",
                                                                           a1,
                                                                           a2,
                                                                           a3,
                                                                           a4,
                                                                           a5,
                                                                           a6,
                                                                           a7,
                                                                           a8,
                                                                           "dp_prealloc_put_coherent",
                                                                           a10);
                                                        v12 = 27;
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  qdf_trace_msg(0x45u, 8u, "%s: index %d, returned", a1, a2, a3, a4, a5, a6, a7, a8, "dp_prealloc_put_coherent", v12);
  v13 = (void *)v10[2];
  v14 = *((unsigned int *)v10 + 1);
  *((_BYTE *)v10 + 8) = 0;
  return qdf_mem_set(v13, v14, 0);
}
