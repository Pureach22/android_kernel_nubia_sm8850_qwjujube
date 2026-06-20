__int64 __fastcall update_xtalk_scale_and_alpha(__int64 result)
{
  __int64 v1; // x21
  __int64 v2; // x19
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x10
  int v6; // w22
  int v7; // w23
  __int64 v8; // x19
  unsigned __int64 v9; // x8
  unsigned int v10; // w20
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x10
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x9

  v1 = *(_QWORD *)(*(_QWORD *)result + 144LL);
  if ( v1 && *(_DWORD *)(v1 + 260) )
  {
    v2 = result;
    *(_DWORD *)(v1 + 256) = 2031647;
    result = wcd_usbss_get_sbu_switch_orientation(result);
    if ( (_DWORD)result == 2 )
    {
      v3 = 168;
      v4 = 180;
      v5 = 164;
    }
    else
    {
      result = wcd_usbss_get_sbu_switch_orientation(result);
      if ( (_DWORD)result != 1 )
        return result;
      v3 = 132;
      v4 = 144;
      v5 = 128;
    }
    v6 = *(_DWORD *)(v1 + v3);
    v7 = *(_DWORD *)(v1 + v5);
    if ( *(_DWORD *)(v1 + 260) == 2 )
    {
      v8 = *(_QWORD *)(v2 + 32);
      if ( v8 )
      {
        v9 = (((unsigned __int64)((*(_DWORD *)(v1 + v4)
                                 + ((unsigned int)(*(_DWORD *)(v1 + 96) + *(_DWORD *)(v1 + 68)) >> 1)) >> 1) << 16)
            + 4201025LL * *(unsigned int *)(v1 + v4))
           / ((unsigned __int64)(*(_DWORD *)(v1 + v4)
                               + ((unsigned int)(*(_DWORD *)(v1 + 96) + *(_DWORD *)(v1 + 68)) >> 1)) << 16);
        if ( v9 <= 0x1C )
          v10 = 29 - v9;
        else
          v10 = 0;
        regmap_update_bits_base(v8, 12608, 31, v10, 0, 0, 0);
        result = regmap_update_bits_base(v8, 12609, 31, v10, 0, 0, 0);
      }
    }
    v11 = (unsigned int)(*(_DWORD *)(v1 + 80) - (v7 + v6) + *(_DWORD *)(v1 + 72));
    if ( (_DWORD)v11 )
    {
      v12 = ((unsigned __int64)*(unsigned int *)(v1 + 244) << 16) / v11;
      if ( (_DWORD)v12 )
      {
        v13 = 0x10000uLL / (int)v12;
        if ( (_DWORD)v13 )
        {
          if ( (_DWORD)v13 == 1 )
          {
            LOBYTE(v13) = 1;
          }
          else if ( (unsigned int)v13 >= 4 )
          {
            if ( (unsigned int)v13 >= 8 )
            {
              if ( (unsigned int)v13 >= 0x10 )
              {
                if ( (unsigned int)v13 >= 0x20 )
                {
                  if ( (unsigned int)v13 >= 0x40 )
                  {
                    if ( (unsigned int)v13 >= 0x80 )
                    {
                      if ( (unsigned int)v13 >= 0x100 )
                      {
                        if ( (unsigned int)v13 >= 0x200 )
                        {
                          if ( (unsigned int)v13 >= 0x400 )
                          {
                            if ( (unsigned int)v13 >= 0x800 )
                            {
                              if ( (unsigned int)v13 >= 0x1000 )
                              {
                                if ( (unsigned int)v13 >= 0x2000 )
                                {
                                  if ( (unsigned int)v13 >= 0x4000 )
                                  {
                                    if ( (unsigned int)v13 >= 0x8000 )
                                    {
                                      if ( (unsigned int)v13 < 0x10000 )
                                        LOBYTE(v13) = 16;
                                      else
                                        LOBYTE(v13) = 17;
                                    }
                                    else
                                    {
                                      LOBYTE(v13) = 15;
                                    }
                                  }
                                  else
                                  {
                                    LOBYTE(v13) = 14;
                                  }
                                }
                                else
                                {
                                  LOBYTE(v13) = 13;
                                }
                              }
                              else
                              {
                                LOBYTE(v13) = 12;
                              }
                            }
                            else
                            {
                              LOBYTE(v13) = 11;
                            }
                          }
                          else
                          {
                            LOBYTE(v13) = 10;
                          }
                        }
                        else
                        {
                          LOBYTE(v13) = 9;
                        }
                      }
                      else
                      {
                        LOBYTE(v13) = 8;
                      }
                    }
                    else
                    {
                      LOBYTE(v13) = 7;
                    }
                  }
                  else
                  {
                    LOBYTE(v13) = 6;
                  }
                }
                else
                {
                  LOBYTE(v13) = 5;
                }
              }
              else
              {
                LOBYTE(v13) = 4;
              }
            }
            else
            {
              LOBYTE(v13) = 3;
            }
          }
          else
          {
            LOBYTE(v13) = 2;
          }
        }
        *(_BYTE *)(v1 + 256) = v13;
        v12 = 255LL * (unsigned int)((_DWORD)v12 << v13) + 0xFFFFFF018000LL;
        if ( (v12 & 0xFFFFFF000000LL) != 0 )
          LOBYTE(v12) = -1;
        else
          LOBYTE(v12) = BYTE2(v12);
      }
      else
      {
        *(_BYTE *)(v1 + 256) = 31;
      }
      *(_BYTE *)(v1 + 257) = v12;
    }
    v14 = (unsigned int)(*(_DWORD *)(v1 + 108) - (v7 + v6) + *(_DWORD *)(v1 + 100));
    if ( (_DWORD)v14 )
    {
      v15 = ((unsigned __int64)*(unsigned int *)(v1 + 244) << 16) / v14;
      if ( (_DWORD)v15 )
      {
        v16 = 0x10000uLL / (int)v15;
        if ( (_DWORD)v16 )
        {
          if ( (_DWORD)v16 == 1 )
          {
            LOBYTE(v16) = 1;
          }
          else if ( (unsigned int)v16 >= 4 )
          {
            if ( (unsigned int)v16 >= 8 )
            {
              if ( (unsigned int)v16 >= 0x10 )
              {
                if ( (unsigned int)v16 >= 0x20 )
                {
                  if ( (unsigned int)v16 >= 0x40 )
                  {
                    if ( (unsigned int)v16 >= 0x80 )
                    {
                      if ( (unsigned int)v16 >= 0x100 )
                      {
                        if ( (unsigned int)v16 >= 0x200 )
                        {
                          if ( (unsigned int)v16 >= 0x400 )
                          {
                            if ( (unsigned int)v16 >= 0x800 )
                            {
                              if ( (unsigned int)v16 >= 0x1000 )
                              {
                                if ( (unsigned int)v16 >= 0x2000 )
                                {
                                  if ( (unsigned int)v16 >= 0x4000 )
                                  {
                                    if ( (unsigned int)v16 >= 0x8000 )
                                    {
                                      if ( (unsigned int)v16 < 0x10000 )
                                        LOBYTE(v16) = 16;
                                      else
                                        LOBYTE(v16) = 17;
                                    }
                                    else
                                    {
                                      LOBYTE(v16) = 15;
                                    }
                                  }
                                  else
                                  {
                                    LOBYTE(v16) = 14;
                                  }
                                }
                                else
                                {
                                  LOBYTE(v16) = 13;
                                }
                              }
                              else
                              {
                                LOBYTE(v16) = 12;
                              }
                            }
                            else
                            {
                              LOBYTE(v16) = 11;
                            }
                          }
                          else
                          {
                            LOBYTE(v16) = 10;
                          }
                        }
                        else
                        {
                          LOBYTE(v16) = 9;
                        }
                      }
                      else
                      {
                        LOBYTE(v16) = 8;
                      }
                    }
                    else
                    {
                      LOBYTE(v16) = 7;
                    }
                  }
                  else
                  {
                    LOBYTE(v16) = 6;
                  }
                }
                else
                {
                  LOBYTE(v16) = 5;
                }
              }
              else
              {
                LOBYTE(v16) = 4;
              }
            }
            else
            {
              LOBYTE(v16) = 3;
            }
          }
          else
          {
            LOBYTE(v16) = 2;
          }
        }
        *(_BYTE *)(v1 + 258) = v16;
        v15 = 255LL * (unsigned int)((_DWORD)v15 << v16) + 0xFFFFFF018000LL;
        if ( (v15 & 0xFFFFFF000000LL) != 0 )
          LOBYTE(v15) = -1;
        else
          LOBYTE(v15) = BYTE2(v15);
      }
      else
      {
        *(_BYTE *)(v1 + 258) = 31;
      }
      *(_BYTE *)(v1 + 259) = v15;
    }
  }
  return result;
}
