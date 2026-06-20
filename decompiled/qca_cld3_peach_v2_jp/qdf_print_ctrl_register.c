__int64 __fastcall qdf_print_ctrl_register(__int64 a1, __int64 a2, __int64 a3, char *string)
{
  unsigned int v8; // w23
  char *v9; // x24
  size_t v10; // x0
  unsigned __int64 v11; // x1
  unsigned __int64 v12; // x2
  __int64 i; // x8
  unsigned int v14; // w11
  __int16 v15; // w12
  __int16 v16; // w11

  if ( byte_76A2E0 == 1 )
  {
    if ( byte_76A468 == 1 )
    {
      if ( byte_76A5F0 == 1 )
      {
        if ( byte_76A778 == 1 )
        {
          if ( byte_76A900 == 1 )
          {
            if ( byte_76AA88 == 1 )
            {
              if ( byte_76AC10 == 1 )
              {
                if ( byte_76AD98 == 1 )
                {
                  if ( byte_76AF20 == 1 )
                  {
                    if ( byte_76B0A8 == 1 )
                    {
                      if ( byte_76B230 == 1 )
                      {
                        if ( byte_76B3B8 == 1 )
                        {
                          if ( byte_76B540 == 1 )
                          {
                            if ( byte_76B6C8 == 1 )
                            {
                              if ( byte_76B850 == 1 )
                              {
                                if ( byte_76B9D8 == 1 )
                                {
                                  if ( byte_76BB60 == 1 )
                                  {
                                    if ( byte_76BCE8 == 1 )
                                    {
                                      if ( byte_76BE70 == 1 )
                                      {
                                        if ( byte_76BFF8 == 1 )
                                        {
                                          if ( byte_76C180 == 1 )
                                          {
                                            if ( byte_76C308 == 1 )
                                            {
                                              if ( byte_76C490 == 1 )
                                              {
                                                if ( byte_76C618 == 1 )
                                                {
                                                  if ( byte_76C7A0 == 1 )
                                                  {
                                                    if ( byte_76C928 == 1 )
                                                    {
                                                      if ( byte_76CAB0 == 1 )
                                                      {
                                                        if ( byte_76CC38 == 1 )
                                                        {
                                                          if ( byte_76CDC0 == 1 )
                                                          {
                                                            if ( byte_76CF48 == 1 )
                                                            {
                                                              if ( byte_76D0D0 == 1 )
                                                              {
                                                                if ( byte_76D258 == 1 )
                                                                  goto LABEL_88;
                                                                v8 = 31;
                                                              }
                                                              else
                                                              {
                                                                v8 = 30;
                                                              }
                                                            }
                                                            else
                                                            {
                                                              v8 = 29;
                                                            }
                                                          }
                                                          else
                                                          {
                                                            v8 = 28;
                                                          }
                                                        }
                                                        else
                                                        {
                                                          v8 = 27;
                                                        }
                                                      }
                                                      else
                                                      {
                                                        v8 = 26;
                                                      }
                                                    }
                                                    else
                                                    {
                                                      v8 = 25;
                                                    }
                                                  }
                                                  else
                                                  {
                                                    v8 = 24;
                                                  }
                                                }
                                                else
                                                {
                                                  v8 = 23;
                                                }
                                              }
                                              else
                                              {
                                                v8 = 22;
                                              }
                                            }
                                            else
                                            {
                                              v8 = 21;
                                            }
                                          }
                                          else
                                          {
                                            v8 = 20;
                                          }
                                        }
                                        else
                                        {
                                          v8 = 19;
                                        }
                                      }
                                      else
                                      {
                                        v8 = 18;
                                      }
                                    }
                                    else
                                    {
                                      v8 = 17;
                                    }
                                  }
                                  else
                                  {
                                    v8 = 16;
                                  }
                                }
                                else
                                {
                                  v8 = 15;
                                }
                              }
                              else
                              {
                                v8 = 14;
                              }
                            }
                            else
                            {
                              v8 = 13;
                            }
                          }
                          else
                          {
                            v8 = 12;
                          }
                        }
                        else
                        {
                          v8 = 11;
                        }
                      }
                      else
                      {
                        v8 = 10;
                      }
                    }
                    else
                    {
                      v8 = 9;
                    }
                  }
                  else
                  {
                    v8 = 8;
                  }
                }
                else
                {
                  v8 = 7;
                }
              }
              else
              {
                v8 = 6;
              }
            }
            else
            {
              v8 = 5;
            }
          }
          else
          {
            v8 = 4;
          }
        }
        else
        {
          v8 = 3;
        }
      }
      else
      {
        v8 = 2;
      }
    }
    else
    {
      v8 = 1;
    }
  }
  else
  {
    v8 = 0;
  }
  v9 = (char *)&print_ctrl_obj + 392 * v8;
  v9[384] = 1;
  if ( string )
  {
    v10 = strnlen(string, 0x20u);
    if ( v10 == -1 )
    {
      _fortify_panic(2, -1, 0);
    }
    else
    {
      v11 = -392LL * (int)v8 + 12544;
      if ( v10 == 32 )
        v12 = 32;
      else
        v12 = v10 + 1;
      if ( v12 <= v11 )
      {
        sized_strscpy((char *)&print_ctrl_obj + 392 * v8, string, v12);
        goto LABEL_72;
      }
    }
    _fortify_panic(7, v11, v12);
LABEL_88:
    printk(&unk_9838D0, "qdf_print_ctrl_register", a3, string);
    return (unsigned int)-1;
  }
LABEL_72:
  if ( a2 )
    *((_QWORD *)v9 + 46) = a2;
  if ( a3 )
    *((_QWORD *)v9 + 47) = a3;
  if ( a1 )
  {
    for ( i = 0; i != 334; i += 2 )
    {
      v14 = *(unsigned __int16 *)(a1 + i);
      if ( v14 == 10 )
        v15 = -1;
      else
        v15 = *(_WORD *)(a1 + i);
      if ( v14 >= 2 )
        v16 = v15;
      else
        v16 = 0;
      *(_WORD *)&v9[i + 32] = v16;
    }
  }
  return v8;
}
