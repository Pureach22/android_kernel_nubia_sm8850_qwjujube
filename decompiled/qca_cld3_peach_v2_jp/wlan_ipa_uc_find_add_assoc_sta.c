__int64 __fastcall wlan_ipa_uc_find_add_assoc_sta(
        _BYTE *a1,
        char a2,
        unsigned __int8 *a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  _BYTE *v14; // x20
  _BYTE *v15; // x9
  int v16; // w10
  int v17; // w9
  bool v18; // zf
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  __int64 v28; // x8
  _BYTE *v29; // x9
  int v30; // w10
  int v31; // w9
  _BYTE *v33; // x20

  v12 = 0;
  v14 = a1 + 3723;
  do
  {
    v15 = &a1[v12];
    if ( a1[v12 + 3723] == 1 )
    {
      v16 = *((_DWORD *)v15 + 931);
      v17 = *((unsigned __int16 *)v15 + 1864);
      v18 = v16 == *(_DWORD *)a3 && v17 == *((unsigned __int16 *)a3 + 2);
      if ( v18 && a1[v12 + 3731] == a4 )
      {
        if ( (a2 & 1) != 0 )
        {
          if ( a3 )
          {
            v19 = *a3;
            v20 = a3[1];
            v21 = a3[2];
            v22 = a3[5];
          }
          else
          {
            v21 = 0;
            v19 = 0;
            v20 = 0;
            v22 = 0;
          }
          qdf_trace_msg(
            0x61u,
            2u,
            "%s: STA already exist, cannot add: %02x:%02x:%02x:**:**:%02x",
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            "wlan_ipa_uc_find_add_assoc_sta",
            v19,
            v20,
            v21,
            v22);
        }
        else
        {
          v28 = 0;
          while ( 1 )
          {
            v29 = &a1[v28];
            if ( a1[v28 + 3723] == 1 )
            {
              v30 = *((_DWORD *)v29 + 931);
              v31 = *((unsigned __int16 *)v29 + 1864);
              if ( v30 == *(_DWORD *)a3 && v31 == *((unsigned __int16 *)a3 + 2) )
              {
                v33 = &a1[v28];
                if ( a1[v28 + 3731] == a4 )
                  break;
              }
            }
            v28 += 9;
            if ( v28 == 288 )
              return 1;
          }
          v33[3723] = 0;
          qdf_mem_set(v33 + 3724, 6u, 0);
          v33[3731] = 5;
        }
        return 1;
      }
    }
    v12 += 9;
  }
  while ( v12 != 288 );
  if ( (a2 & 1) != 0 )
  {
    if ( *v14 == 1 )
    {
      if ( a1[3732] == 1 )
      {
        if ( a1[3741] == 1 )
        {
          if ( a1[3750] == 1 )
          {
            if ( a1[3759] == 1 )
            {
              if ( a1[3768] == 1 )
              {
                if ( a1[3777] == 1 )
                {
                  if ( a1[3786] == 1 )
                  {
                    if ( a1[3795] == 1 )
                    {
                      if ( a1[3804] == 1 )
                      {
                        if ( a1[3813] == 1 )
                        {
                          if ( a1[3822] == 1 )
                          {
                            if ( a1[3831] == 1 )
                            {
                              if ( a1[3840] == 1 )
                              {
                                if ( a1[3849] == 1 )
                                {
                                  if ( a1[3858] == 1 )
                                  {
                                    if ( a1[3867] == 1 )
                                    {
                                      if ( a1[3876] == 1 )
                                      {
                                        if ( a1[3885] == 1 )
                                        {
                                          if ( a1[3894] == 1 )
                                          {
                                            if ( a1[3903] == 1 )
                                            {
                                              if ( a1[3912] == 1 )
                                              {
                                                if ( a1[3921] == 1 )
                                                {
                                                  if ( a1[3930] == 1 )
                                                  {
                                                    if ( a1[3939] == 1 )
                                                    {
                                                      if ( a1[3948] == 1 )
                                                      {
                                                        if ( a1[3957] == 1 )
                                                        {
                                                          if ( a1[3966] == 1 )
                                                          {
                                                            if ( a1[3975] == 1 )
                                                            {
                                                              if ( a1[3984] == 1 )
                                                              {
                                                                if ( a1[3993] == 1 )
                                                                {
                                                                  if ( (a1[4002] & 1) != 0 )
                                                                    return 0;
                                                                  v14 = a1 + 4002;
                                                                }
                                                                else
                                                                {
                                                                  v14 = a1 + 3993;
                                                                }
                                                              }
                                                              else
                                                              {
                                                                v14 = a1 + 3984;
                                                              }
                                                            }
                                                            else
                                                            {
                                                              v14 = a1 + 3975;
                                                            }
                                                          }
                                                          else
                                                          {
                                                            v14 = a1 + 3966;
                                                          }
                                                        }
                                                        else
                                                        {
                                                          v14 = a1 + 3957;
                                                        }
                                                      }
                                                      else
                                                      {
                                                        v14 = a1 + 3948;
                                                      }
                                                    }
                                                    else
                                                    {
                                                      v14 = a1 + 3939;
                                                    }
                                                  }
                                                  else
                                                  {
                                                    v14 = a1 + 3930;
                                                  }
                                                }
                                                else
                                                {
                                                  v14 = a1 + 3921;
                                                }
                                              }
                                              else
                                              {
                                                v14 = a1 + 3912;
                                              }
                                            }
                                            else
                                            {
                                              v14 = a1 + 3903;
                                            }
                                          }
                                          else
                                          {
                                            v14 = a1 + 3894;
                                          }
                                        }
                                        else
                                        {
                                          v14 = a1 + 3885;
                                        }
                                      }
                                      else
                                      {
                                        v14 = a1 + 3876;
                                      }
                                    }
                                    else
                                    {
                                      v14 = a1 + 3867;
                                    }
                                  }
                                  else
                                  {
                                    v14 = a1 + 3858;
                                  }
                                }
                                else
                                {
                                  v14 = a1 + 3849;
                                }
                              }
                              else
                              {
                                v14 = a1 + 3840;
                              }
                            }
                            else
                            {
                              v14 = a1 + 3831;
                            }
                          }
                          else
                          {
                            v14 = a1 + 3822;
                          }
                        }
                        else
                        {
                          v14 = a1 + 3813;
                        }
                      }
                      else
                      {
                        v14 = a1 + 3804;
                      }
                    }
                    else
                    {
                      v14 = a1 + 3795;
                    }
                  }
                  else
                  {
                    v14 = a1 + 3786;
                  }
                }
                else
                {
                  v14 = a1 + 3777;
                }
              }
              else
              {
                v14 = a1 + 3768;
              }
            }
            else
            {
              v14 = a1 + 3759;
            }
          }
          else
          {
            v14 = a1 + 3750;
          }
        }
        else
        {
          v14 = a1 + 3741;
        }
      }
      else
      {
        v14 = a1 + 3732;
      }
    }
    *v14 = 1;
    qdf_mem_copy(v14 + 1, a3, 6u);
    v14[8] = a4;
    return 0;
  }
  else
  {
    if ( a3 )
    {
      v24 = *a3;
      v25 = a3[1];
      v26 = a3[2];
      v27 = a3[5];
    }
    else
    {
      v26 = 0;
      v24 = 0;
      v25 = 0;
      v27 = 0;
    }
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: STA does not exist, cannot delete: %02x:%02x:%02x:**:**:%02x",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_ipa_uc_find_add_assoc_sta",
      v24,
      v25,
      v26,
      v27);
    return 0;
  }
}
