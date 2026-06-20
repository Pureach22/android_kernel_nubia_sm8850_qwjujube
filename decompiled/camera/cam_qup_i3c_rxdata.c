__int64 __fastcall cam_qup_i3c_rxdata(__int64 a1, __int64 a2, __int16 a3, __int16 a4)
{
  unsigned int v5; // w20
  int v6; // w21
  _QWORD v8[3]; // [xsp+8h] [xbp-38h] BYREF
  __int16 v9; // [xsp+20h] [xbp-20h]
  __int16 v10; // [xsp+22h] [xbp-1Eh]
  int v11; // [xsp+24h] [xbp-1Ch]
  __int64 v12; // [xsp+28h] [xbp-18h]
  __int64 v13; // [xsp+30h] [xbp-10h]
  __int64 v14; // [xsp+38h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v8[1] = a2;
  WORD1(v8[0]) = a3;
  v12 = a2;
  v13 = 0;
  v8[2] = 0;
  v9 = 1;
  v10 = a4;
  v11 = 0;
  v5 = i3c_device_do_priv_xfers(a1, v8, 2);
  if ( v5 )
  {
    if ( v5 != -107 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_qup_i3c_rxdata",
        48,
        "Failed with i3c_read: rc = %d",
        v5);
      goto LABEL_27;
    }
    usleep_range_state(1000, 1005, 2);
    v5 = i3c_device_do_priv_xfers(a1, v8, 2);
    if ( v5 )
    {
      if ( v5 == -107 )
      {
        v6 = 1000;
        usleep_range_state(1000, 1005, 2);
        v5 = i3c_device_do_priv_xfers(a1, v8, 2);
        if ( !v5 )
          goto LABEL_27;
        if ( v5 == -107 )
        {
          usleep_range_state(1000, 1005, 2);
          v5 = i3c_device_do_priv_xfers(a1, v8, 2);
          if ( !v5 )
            goto LABEL_27;
          if ( v5 == -107 )
          {
            usleep_range_state(1000, 1005, 2);
            v5 = i3c_device_do_priv_xfers(a1, v8, 2);
            if ( !v5 )
              goto LABEL_27;
            if ( v5 == -107 )
            {
              usleep_range_state(1000, 1005, 2);
              v5 = i3c_device_do_priv_xfers(a1, v8, 2);
              if ( !v5 )
                goto LABEL_27;
              if ( v5 == -107 )
              {
                usleep_range_state(1000, 1005, 2);
                v5 = i3c_device_do_priv_xfers(a1, v8, 2);
                if ( !v5 )
                  goto LABEL_27;
                if ( v5 == -107 )
                {
                  usleep_range_state(1000, 1005, 2);
                  v5 = i3c_device_do_priv_xfers(a1, v8, 2);
                  if ( !v5 )
                    goto LABEL_27;
                  if ( v5 == -107 )
                  {
                    usleep_range_state(1000, 1005, 2);
                    v5 = i3c_device_do_priv_xfers(a1, v8, 2);
                    if ( !v5 )
                      goto LABEL_27;
                    if ( v5 == -107 )
                    {
                      usleep_range_state(1000, 1005, 2);
                      v5 = i3c_device_do_priv_xfers(a1, v8, 2);
                      if ( !v5 )
                        goto LABEL_27;
                      if ( v5 == -107 )
                      {
                        usleep_range_state(1000, 1005, 2);
                        v5 = i3c_device_do_priv_xfers(a1, v8, 2);
                        if ( v5 )
                        {
                          if ( v5 == -107 )
                            v6 = 10000;
                          else
                            v6 = 9000;
                          goto LABEL_26;
                        }
                        goto LABEL_27;
                      }
                      v6 = 8000;
                    }
                    else
                    {
                      v6 = 7000;
                    }
                  }
                  else
                  {
                    v6 = 6000;
                  }
                }
                else
                {
                  v6 = 5000;
                }
              }
              else
              {
                v6 = 4000;
              }
            }
            else
            {
              v6 = 3000;
            }
          }
          else
          {
            v6 = 2000;
          }
        }
      }
      else
      {
        v6 = 0;
      }
LABEL_26:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_qup_i3c_rxdata",
        46,
        "Retry Failed i3c_read: rc = %d, us = %d",
        v5,
        v6);
    }
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v5;
}
