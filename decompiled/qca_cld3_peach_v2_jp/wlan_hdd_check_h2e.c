unsigned __int8 *__fastcall wlan_hdd_check_h2e(unsigned __int8 *result, _BYTE *a2)
{
  unsigned int v2; // w8

  if ( result )
  {
    if ( a2 )
    {
      v2 = *result;
      if ( *result )
      {
        if ( result[1] == 251 )
        {
          *a2 = 1;
          v2 = *result;
        }
        if ( v2 >= 2 )
        {
          if ( result[2] == 251 )
          {
            *a2 = 1;
            v2 = *result;
          }
          if ( v2 >= 3 )
          {
            if ( result[3] == 251 )
            {
              *a2 = 1;
              v2 = *result;
            }
            if ( v2 >= 4 )
            {
              if ( result[4] == 251 )
              {
                *a2 = 1;
                v2 = *result;
              }
              if ( v2 >= 5 )
              {
                if ( result[5] == 251 )
                {
                  *a2 = 1;
                  v2 = *result;
                }
                if ( v2 >= 6 )
                {
                  if ( result[6] == 251 )
                  {
                    *a2 = 1;
                    v2 = *result;
                  }
                  if ( v2 >= 7 )
                  {
                    if ( result[7] == 251 )
                    {
                      *a2 = 1;
                      v2 = *result;
                    }
                    if ( v2 >= 8 )
                    {
                      if ( result[8] == 251 )
                      {
                        *a2 = 1;
                        v2 = *result;
                      }
                      if ( v2 >= 9 )
                      {
                        if ( result[9] == 251 )
                        {
                          *a2 = 1;
                          v2 = *result;
                        }
                        if ( v2 >= 0xA )
                        {
                          if ( result[10] == 251 )
                          {
                            *a2 = 1;
                            v2 = *result;
                          }
                          if ( v2 >= 0xB )
                          {
                            if ( result[11] == 251 )
                            {
                              *a2 = 1;
                              v2 = *result;
                            }
                            if ( v2 >= 0xC )
                            {
                              if ( result[12] == 251 )
                              {
                                *a2 = 1;
                                v2 = *result;
                              }
                              if ( v2 > 0xC )
                              {
                                __break(0x5512u);
                                return (unsigned __int8 *)wlan_hdd_set_sap_hwmode(result);
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
