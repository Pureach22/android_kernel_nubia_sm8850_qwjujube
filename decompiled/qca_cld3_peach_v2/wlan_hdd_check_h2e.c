unsigned __int8 *__fastcall wlan_hdd_check_h2e(unsigned __int8 *result, _BYTE *a2, __int64 a3)
{
  unsigned int v3; // w8

  if ( result )
  {
    if ( a2 )
    {
      v3 = *result;
      if ( *result )
      {
        if ( result[1] == 251 )
        {
          *a2 = 1;
          v3 = *result;
        }
        if ( v3 >= 2 )
        {
          if ( result[2] == 251 )
          {
            *a2 = 1;
            v3 = *result;
          }
          if ( v3 >= 3 )
          {
            if ( result[3] == 251 )
            {
              *a2 = 1;
              v3 = *result;
            }
            if ( v3 >= 4 )
            {
              if ( result[4] == 251 )
              {
                *a2 = 1;
                v3 = *result;
              }
              if ( v3 >= 5 )
              {
                if ( result[5] == 251 )
                {
                  *a2 = 1;
                  v3 = *result;
                }
                if ( v3 >= 6 )
                {
                  if ( result[6] == 251 )
                  {
                    *a2 = 1;
                    v3 = *result;
                  }
                  if ( v3 >= 7 )
                  {
                    if ( result[7] == 251 )
                    {
                      *a2 = 1;
                      v3 = *result;
                    }
                    if ( v3 >= 8 )
                    {
                      if ( result[8] == 251 )
                      {
                        *a2 = 1;
                        v3 = *result;
                      }
                      if ( v3 >= 9 )
                      {
                        if ( result[9] == 251 )
                        {
                          *a2 = 1;
                          v3 = *result;
                        }
                        if ( v3 >= 0xA )
                        {
                          if ( result[10] == 251 )
                          {
                            *a2 = 1;
                            v3 = *result;
                          }
                          if ( v3 >= 0xB )
                          {
                            if ( result[11] == 251 )
                            {
                              *a2 = 1;
                              v3 = *result;
                            }
                            if ( v3 >= 0xC )
                            {
                              if ( result[12] == 251 )
                              {
                                *a2 = 1;
                                v3 = *result;
                              }
                              if ( v3 > 0xC )
                              {
                                __break(0x5512u);
                                return (unsigned __int8 *)wlan_hdd_update_rnrie(result, a2, a3);
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
  return result;
}
