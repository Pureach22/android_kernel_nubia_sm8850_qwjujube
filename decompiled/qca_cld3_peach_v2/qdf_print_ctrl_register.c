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

  if ( byte_822D10 == 1 )
  {
    if ( byte_822E98 == 1 )
    {
      if ( byte_823020 == 1 )
      {
        if ( byte_8231A8 == 1 )
        {
          if ( byte_823330 == 1 )
          {
            if ( byte_8234B8 == 1 )
            {
              if ( byte_823640 == 1 )
              {
                if ( byte_8237C8 == 1 )
                {
                  if ( byte_823950 == 1 )
                  {
                    if ( byte_823AD8 == 1 )
                    {
                      if ( byte_823C60 == 1 )
                      {
                        if ( byte_823DE8 == 1 )
                        {
                          if ( byte_823F70 == 1 )
                          {
                            if ( byte_8240F8 == 1 )
                            {
                              if ( byte_824280 == 1 )
                              {
                                if ( byte_824408 == 1 )
                                {
                                  if ( byte_824590 == 1 )
                                  {
                                    if ( byte_824718 == 1 )
                                    {
                                      if ( byte_8248A0 == 1 )
                                      {
                                        if ( byte_824A28 == 1 )
                                        {
                                          if ( byte_824BB0 == 1 )
                                          {
                                            if ( byte_824D38 == 1 )
                                            {
                                              if ( byte_824EC0 == 1 )
                                              {
                                                if ( byte_825048 == 1 )
                                                {
                                                  if ( byte_8251D0 == 1 )
                                                  {
                                                    if ( byte_825358 == 1 )
                                                    {
                                                      if ( byte_8254E0 == 1 )
                                                      {
                                                        if ( byte_825668 == 1 )
                                                        {
                                                          if ( byte_8257F0 == 1 )
                                                          {
                                                            if ( byte_825978 == 1 )
                                                            {
                                                              if ( byte_825B00 == 1 )
                                                              {
                                                                if ( byte_825C88 == 1 )
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
    printk(&unk_A6C7BC, "qdf_print_ctrl_register", a3, string);
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
