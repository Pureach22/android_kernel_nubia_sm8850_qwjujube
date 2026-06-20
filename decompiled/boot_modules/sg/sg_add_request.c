_QWORD *__fastcall sg_add_request(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  _QWORD *v4; // x22
  __int64 v5; // x8
  _QWORD *v6; // x1

  v2 = raw_write_lock_irqsave(a1 + 48);
  v3 = a1 + 144;
  v4 = (_QWORD *)(a1 + 168);
  if ( *(_QWORD *)(a1 + 144) != a1 + 144 )
  {
    if ( !*(_BYTE *)(a1 + 4905) )
    {
LABEL_19:
      v4 = nullptr;
      goto LABEL_39;
    }
    if ( *(_QWORD *)(a1 + 184) )
    {
      if ( *(_QWORD *)(a1 + 480) )
      {
        if ( *(_QWORD *)(a1 + 776) )
        {
          if ( *(_QWORD *)(a1 + 1072) )
          {
            if ( *(_QWORD *)(a1 + 1368) )
            {
              if ( *(_QWORD *)(a1 + 1664) )
              {
                if ( *(_QWORD *)(a1 + 1960) )
                {
                  if ( *(_QWORD *)(a1 + 2256) )
                  {
                    if ( *(_QWORD *)(a1 + 2552) )
                    {
                      if ( *(_QWORD *)(a1 + 2848) )
                      {
                        if ( *(_QWORD *)(a1 + 3144) )
                        {
                          if ( *(_QWORD *)(a1 + 3440) )
                          {
                            if ( *(_QWORD *)(a1 + 3736) )
                            {
                              if ( *(_QWORD *)(a1 + 4032) )
                              {
                                if ( *(_QWORD *)(a1 + 4328) )
                                {
                                  if ( *(_QWORD *)(a1 + 4624) )
                                    goto LABEL_19;
                                  v5 = 4608;
                                }
                                else
                                {
                                  v5 = 4312;
                                }
                                v4 = (_QWORD *)(a1 + v5);
                              }
                              else
                              {
                                v4 = (_QWORD *)(a1 + 4016);
                              }
                            }
                            else
                            {
                              v4 = (_QWORD *)(a1 + 3720);
                            }
                          }
                          else
                          {
                            v4 = (_QWORD *)(a1 + 3424);
                          }
                        }
                        else
                        {
                          v4 = (_QWORD *)(a1 + 3128);
                        }
                      }
                      else
                      {
                        v4 = (_QWORD *)(a1 + 2832);
                      }
                    }
                    else
                    {
                      v4 = (_QWORD *)(a1 + 2536);
                    }
                  }
                  else
                  {
                    v4 = (_QWORD *)(a1 + 2240);
                  }
                }
                else
                {
                  v4 = (_QWORD *)(a1 + 1944);
                }
              }
              else
              {
                v4 = (_QWORD *)(a1 + 1648);
              }
            }
            else
            {
              v4 = (_QWORD *)(a1 + 1352);
            }
          }
          else
          {
            v4 = (_QWORD *)(a1 + 1056);
          }
        }
        else
        {
          v4 = (_QWORD *)(a1 + 760);
        }
      }
      else
      {
        v4 = (_QWORD *)(a1 + 464);
      }
    }
  }
  memset(v4, 0, 0x128u);
  v4[2] = a1;
  *((_DWORD *)v4 + 33) = jiffies_to_msecs(jiffies);
  v6 = *(_QWORD **)(a1 + 152);
  if ( v6 == v4 || *v6 != v3 )
  {
    _list_add_valid_or_report(v4);
  }
  else
  {
    *(_QWORD *)(a1 + 152) = v4;
    *v4 = v3;
    v4[1] = v6;
    *v6 = v4;
  }
LABEL_39:
  raw_write_unlock_irqrestore(a1 + 48, v2);
  return v4;
}
