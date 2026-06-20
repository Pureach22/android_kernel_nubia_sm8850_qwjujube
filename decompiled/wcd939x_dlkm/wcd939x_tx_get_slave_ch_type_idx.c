__int64 __fastcall wcd939x_tx_get_slave_ch_type_idx(__int64 a1, int *a2)
{
  __int64 result; // x0
  int v5; // w8

  result = strnstr(a1, "ADC1", 5);
  if ( result )
  {
    v5 = 0;
  }
  else
  {
    result = strnstr(a1, "ADC2", 5);
    if ( result )
    {
      v5 = 1;
    }
    else
    {
      result = strnstr(a1, "ADC3", 5);
      if ( result )
      {
        v5 = 2;
      }
      else
      {
        result = strnstr(a1, "ADC4", 5);
        if ( result )
        {
          v5 = 3;
        }
        else
        {
          result = strnstr(a1, "DMIC0", 6);
          if ( result )
          {
            v5 = 4;
          }
          else
          {
            result = strnstr(a1, "DMIC1", 6);
            if ( result )
            {
              v5 = 5;
            }
            else
            {
              result = strnstr(a1, "MBHC", 5);
              if ( result )
              {
                v5 = 6;
              }
              else
              {
                result = strnstr(a1, "DMIC2", 6);
                if ( result )
                {
                  v5 = 6;
                }
                else
                {
                  result = strnstr(a1, "DMIC3", 6);
                  if ( result )
                  {
                    v5 = (unsigned __int8)asc_1DE78[1];
                  }
                  else
                  {
                    result = strnstr(a1, "DMIC4", 6);
                    if ( result )
                    {
                      v5 = (unsigned __int8)asc_1DE78[3];
                    }
                    else
                    {
                      result = strnstr(a1, "DMIC5", 6);
                      if ( result )
                      {
                        v5 = (unsigned __int8)asc_1DE78[5];
                      }
                      else
                      {
                        result = strnstr(a1, "DMIC6", 6);
                        if ( result )
                        {
                          v5 = (unsigned __int8)asc_1DE78[7];
                        }
                        else
                        {
                          result = strnstr(a1, "DMIC7", 6);
                          if ( result )
                          {
                            v5 = (unsigned __int8)asc_1DE78[9];
                          }
                          else
                          {
                            result = __ratelimit(
                                       &wcd939x_tx_get_slave_ch_type_idx__rs,
                                       "wcd939x_tx_get_slave_ch_type_idx");
                            if ( (_DWORD)result )
                              result = printk(&unk_18B55, "wcd939x_tx_get_slave_ch_type_idx");
                            v5 = -22;
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
  *a2 = v5;
  return result;
}
