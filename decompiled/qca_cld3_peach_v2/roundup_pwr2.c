__int64 __fastcall roundup_pwr2(__int64 result)
{
  if ( ((unsigned int)result & ((_DWORD)result - 1)) != 0 )
  {
    if ( (unsigned int)result >= 4 )
    {
      if ( (unsigned int)result >= 8 )
      {
        if ( (unsigned int)result >= 0x10 )
        {
          if ( (unsigned int)result >= 0x20 )
          {
            if ( (unsigned int)result >= 0x40 )
            {
              if ( (unsigned int)result >= 0x80 )
              {
                if ( (unsigned int)result >= 0x100 )
                {
                  if ( (unsigned int)result >= 0x200 )
                  {
                    if ( (unsigned int)result >= 0x400 )
                    {
                      if ( (unsigned int)result >= 0x800 )
                      {
                        if ( (unsigned int)result >= 0x1000 )
                        {
                          if ( (unsigned int)result >= 0x2000 )
                          {
                            if ( (unsigned int)result >= 0x4000 )
                            {
                              if ( (unsigned int)result >= 0x8000 )
                              {
                                if ( (unsigned int)result >= 0x10000 )
                                {
                                  if ( (unsigned int)result >= 0x20000 )
                                  {
                                    if ( (unsigned int)result >= 0x40000 )
                                    {
                                      if ( (unsigned int)result >= 0x80000 )
                                      {
                                        if ( (unsigned int)result >= 0x100000 )
                                        {
                                          if ( (unsigned int)result >= 0x200000 )
                                          {
                                            if ( (unsigned int)result >= 0x400000 )
                                            {
                                              if ( (unsigned int)result >= 0x800000 )
                                              {
                                                if ( BYTE3(result) )
                                                {
                                                  if ( (unsigned int)result >> 25 )
                                                  {
                                                    if ( (unsigned int)result >> 26 )
                                                    {
                                                      if ( (unsigned int)result >> 27 )
                                                      {
                                                        if ( (unsigned int)result >> 28 )
                                                        {
                                                          if ( (unsigned int)result >> 29 )
                                                            return (unsigned __int8)((unsigned int)result >> 30 == 0) << 30;
                                                          else
                                                            return 0x20000000;
                                                        }
                                                        else
                                                        {
                                                          return 0x10000000;
                                                        }
                                                      }
                                                      else
                                                      {
                                                        return 0x8000000;
                                                      }
                                                    }
                                                    else
                                                    {
                                                      return 0x4000000;
                                                    }
                                                  }
                                                  else
                                                  {
                                                    return 0x2000000;
                                                  }
                                                }
                                                else
                                                {
                                                  return 0x1000000;
                                                }
                                              }
                                              else
                                              {
                                                return 0x800000;
                                              }
                                            }
                                            else
                                            {
                                              return 0x400000;
                                            }
                                          }
                                          else
                                          {
                                            return 0x200000;
                                          }
                                        }
                                        else
                                        {
                                          return 0x100000;
                                        }
                                      }
                                      else
                                      {
                                        return 0x80000;
                                      }
                                    }
                                    else
                                    {
                                      return 0x40000;
                                    }
                                  }
                                  else
                                  {
                                    return 0x20000;
                                  }
                                }
                                else
                                {
                                  return 0x10000;
                                }
                              }
                              else
                              {
                                return 0x8000;
                              }
                            }
                            else
                            {
                              return 0x4000;
                            }
                          }
                          else
                          {
                            return 0x2000;
                          }
                        }
                        else
                        {
                          return 4096;
                        }
                      }
                      else
                      {
                        return 2048;
                      }
                    }
                    else
                    {
                      return 1024;
                    }
                  }
                  else
                  {
                    return 512;
                  }
                }
                else
                {
                  return 256;
                }
              }
              else
              {
                return 128;
              }
            }
            else
            {
              return 64;
            }
          }
          else
          {
            return 32;
          }
        }
        else
        {
          return 16;
        }
      }
      else
      {
        return 8;
      }
    }
    else
    {
      return 4;
    }
  }
  return result;
}
