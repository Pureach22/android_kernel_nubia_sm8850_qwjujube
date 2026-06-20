__int64 __fastcall rmnet_wlan_device_notifier(__int64 a1, __int64 a2, unsigned __int8 **a3)
{
  unsigned __int8 *v3; // x0
  int v4; // w9
  int v5; // w8
  int v6; // w8
  void *v7; // x0

  v3 = *a3;
  if ( *a3 )
  {
    v4 = v3[296];
    if ( v4 == (unsigned __int8)rmnet_wlan_device )
    {
      v5 = v3[297];
      if ( v3[297] )
      {
        if ( v5 != (unsigned __int8)byte_CECD
          || v3[298]
          && (v3[298] != (unsigned __int8)byte_CECE
           || v3[299]
           && (v3[299] != (unsigned __int8)byte_CECF
            || v3[300]
            && (v3[300] != (unsigned __int8)byte_CED0
             || v3[301]
             && (v3[301] != (unsigned __int8)byte_CED1
              || v3[302]
              && (v3[302] != (unsigned __int8)byte_CED2
               || v3[303]
               && (v3[303] != (unsigned __int8)byte_CED3
                || v3[304]
                && (v3[304] != (unsigned __int8)byte_CED4
                 || v3[305]
                 && (v3[305] != (unsigned __int8)byte_CED5
                  || v3[306]
                  && (v3[306] != (unsigned __int8)byte_CED6
                   || v3[307]
                   && (v3[307] != (unsigned __int8)byte_CED7
                    || v3[308]
                    && (v3[308] != (unsigned __int8)byte_CED8
                     || v3[309]
                     && (v3[309] != (unsigned __int8)byte_CED9
                      || v3[310]
                      && (v3[310] != (unsigned __int8)byte_CEDA || v3[311] && v3[311] != (unsigned __int8)byte_CEDB))))))))))))) )
        {
          return 0;
        }
        if ( v4 == 114 )
        {
          if ( !v3[297] )
            goto LABEL_45;
          if ( v5 == 109 )
          {
            v6 = v3[298];
            if ( v6 == 110 )
            {
              v6 = v3[299];
              if ( v6 == 101 )
              {
                v6 = v3[300];
                if ( v6 == 116 )
                {
                  v6 = v3[301];
                  if ( v6 == 95 )
                  {
                    v6 = v3[302];
                    if ( v6 == 100 )
                    {
                      v6 = v3[303];
                      if ( v6 == 97 )
                      {
                        v6 = v3[304];
                        if ( v6 == 116 )
                        {
                          v6 = v3[305];
                          if ( v6 == 97 )
                            goto LABEL_45;
                        }
                      }
                    }
                  }
                }
              }
            }
            if ( !v6 )
              goto LABEL_45;
          }
        }
      }
      else if ( v4 == 114 )
      {
LABEL_45:
        v7 = &unk_DAC6;
LABEL_53:
        printk(v7, "rmnet_wlan_device_notifier");
        return 0;
      }
      if ( a2 == 5 )
      {
        if ( (unsigned int)netdev_rx_handler_register() )
        {
          v7 = &unk_DB6E;
          goto LABEL_53;
        }
      }
      else if ( a2 == 6 )
      {
        netdev_rx_handler_unregister();
      }
    }
  }
  return 0;
}
