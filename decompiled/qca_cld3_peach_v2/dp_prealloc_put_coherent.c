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
  if ( qword_165F8 == a10 )
  {
    v12 = 0;
  }
  else
  {
    v10 = &unk_16618;
    if ( qword_16628 == a10 )
    {
      v12 = 1;
    }
    else
    {
      v10 = &unk_16648;
      if ( qword_16658 == a10 )
      {
        v12 = 2;
      }
      else
      {
        v10 = &unk_16678;
        if ( qword_16688 == a10 )
        {
          v12 = 3;
        }
        else
        {
          v10 = &unk_166A8;
          if ( qword_166B8 == a10 )
          {
            v12 = 4;
          }
          else
          {
            v10 = &unk_166D8;
            if ( qword_166E8 == a10 )
            {
              v12 = 5;
            }
            else
            {
              v10 = &unk_16708;
              if ( qword_16718 == a10 )
              {
                v12 = 6;
              }
              else
              {
                v10 = &unk_16738;
                if ( qword_16748 == a10 )
                {
                  v12 = 7;
                }
                else
                {
                  v10 = &unk_16768;
                  if ( qword_16778 == a10 )
                  {
                    v12 = 8;
                  }
                  else
                  {
                    v10 = &unk_16798;
                    if ( qword_167A8 == a10 )
                    {
                      v12 = 9;
                    }
                    else
                    {
                      v10 = &unk_167C8;
                      if ( qword_167D8 == a10 )
                      {
                        v12 = 10;
                      }
                      else
                      {
                        v10 = &unk_167F8;
                        if ( qword_16808 == a10 )
                        {
                          v12 = 11;
                        }
                        else
                        {
                          v10 = &unk_16828;
                          if ( qword_16838 == a10 )
                          {
                            v12 = 12;
                          }
                          else
                          {
                            v10 = &unk_16858;
                            if ( qword_16868 == a10 )
                            {
                              v12 = 13;
                            }
                            else
                            {
                              v10 = &unk_16888;
                              if ( qword_16898 == a10 )
                              {
                                v12 = 14;
                              }
                              else
                              {
                                v10 = &unk_168B8;
                                if ( qword_168C8 == a10 )
                                {
                                  v12 = 15;
                                }
                                else
                                {
                                  v10 = &unk_168E8;
                                  if ( qword_168F8 == a10 )
                                  {
                                    v12 = 16;
                                  }
                                  else
                                  {
                                    v10 = &unk_16918;
                                    if ( qword_16928 == a10 )
                                    {
                                      v12 = 17;
                                    }
                                    else
                                    {
                                      v10 = &unk_16948;
                                      if ( qword_16958 == a10 )
                                      {
                                        v12 = 18;
                                      }
                                      else
                                      {
                                        v10 = &unk_16978;
                                        if ( qword_16988 == a10 )
                                        {
                                          v12 = 19;
                                        }
                                        else
                                        {
                                          v10 = &unk_169A8;
                                          if ( qword_169B8 == a10 )
                                          {
                                            v12 = 20;
                                          }
                                          else
                                          {
                                            v10 = &unk_169D8;
                                            if ( qword_169E8 == a10 )
                                            {
                                              v12 = 21;
                                            }
                                            else
                                            {
                                              v10 = &unk_16A08;
                                              if ( qword_16A18 == a10 )
                                              {
                                                v12 = 22;
                                              }
                                              else
                                              {
                                                v10 = &unk_16A38;
                                                if ( qword_16A48 == a10 )
                                                {
                                                  v12 = 23;
                                                }
                                                else
                                                {
                                                  v10 = &unk_16A68;
                                                  if ( qword_16A78 == a10 )
                                                  {
                                                    v12 = 24;
                                                  }
                                                  else
                                                  {
                                                    v10 = &unk_16A98;
                                                    if ( qword_16AA8 == a10 )
                                                    {
                                                      v12 = 25;
                                                    }
                                                    else
                                                    {
                                                      v10 = &unk_16AC8;
                                                      if ( qword_16AD8 == a10 )
                                                      {
                                                        v12 = 26;
                                                      }
                                                      else
                                                      {
                                                        v10 = &unk_16AF8;
                                                        if ( qword_16B08 != a10 )
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
