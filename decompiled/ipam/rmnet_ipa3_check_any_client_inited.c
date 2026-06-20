__int64 __fastcall rmnet_ipa3_check_any_client_inited(unsigned int a1)
{
  __int64 v1; // x9
  __int64 v2; // x10
  __int64 v3; // x10
  __int64 v4; // x10
  __int64 v5; // x10
  __int64 v6; // x10
  __int64 v7; // x10
  __int64 v8; // x10
  __int64 v9; // x10
  __int64 v10; // x10
  __int64 v11; // x10
  __int64 v12; // x10
  __int64 v13; // x10
  __int64 v14; // x10
  __int64 v15; // x10
  __int64 v16; // x10
  __int64 v17; // x8
  int v19; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 > 4 )
  {
    __break(0x5512u);
    JUMPOUT(0x14AB40);
  }
  v1 = rmnet_ipa3_ctx + 1248;
  v2 = rmnet_ipa3_ctx + 1248 + 172LL * a1;
  if ( *(unsigned __int8 *)(v2 + 18) != 255 && *(_BYTE *)(v2 + 19) )
  {
    v19 = 0;
  }
  else
  {
    v3 = v1 + 172LL * a1;
    if ( *(unsigned __int8 *)(v3 + 26) != 255 && *(_BYTE *)(v3 + 27) )
    {
      v19 = 1;
    }
    else
    {
      v4 = v1 + 172LL * a1;
      if ( *(unsigned __int8 *)(v4 + 34) != 255 && *(_BYTE *)(v4 + 35) )
      {
        v19 = 2;
      }
      else
      {
        v5 = v1 + 172LL * a1;
        if ( *(unsigned __int8 *)(v5 + 42) != 255 && *(_BYTE *)(v5 + 43) )
        {
          v19 = 3;
        }
        else
        {
          v6 = v1 + 172LL * a1;
          if ( *(unsigned __int8 *)(v6 + 50) != 255 && *(_BYTE *)(v6 + 51) )
          {
            v19 = 4;
          }
          else
          {
            v7 = v1 + 172LL * a1;
            if ( *(unsigned __int8 *)(v7 + 58) != 255 && *(_BYTE *)(v7 + 59) )
            {
              v19 = 5;
            }
            else
            {
              v8 = v1 + 172LL * a1;
              if ( *(unsigned __int8 *)(v8 + 66) != 255 && *(_BYTE *)(v8 + 67) )
              {
                v19 = 6;
              }
              else
              {
                v9 = v1 + 172LL * a1;
                if ( *(unsigned __int8 *)(v9 + 74) != 255 && *(_BYTE *)(v9 + 75) )
                {
                  v19 = 7;
                }
                else
                {
                  v10 = v1 + 172LL * a1;
                  if ( *(unsigned __int8 *)(v10 + 82) != 255 && *(_BYTE *)(v10 + 83) )
                  {
                    v19 = 8;
                  }
                  else
                  {
                    v11 = v1 + 172LL * a1;
                    if ( *(unsigned __int8 *)(v11 + 90) != 255 && *(_BYTE *)(v11 + 91) )
                    {
                      v19 = 9;
                    }
                    else
                    {
                      v12 = v1 + 172LL * a1;
                      if ( *(unsigned __int8 *)(v12 + 98) != 255 && *(_BYTE *)(v12 + 99) )
                      {
                        v19 = 10;
                      }
                      else
                      {
                        v13 = v1 + 172LL * a1;
                        if ( *(unsigned __int8 *)(v13 + 106) != 255 && *(_BYTE *)(v13 + 107) )
                        {
                          v19 = 11;
                        }
                        else
                        {
                          v14 = v1 + 172LL * a1;
                          if ( *(unsigned __int8 *)(v14 + 114) != 255 && *(_BYTE *)(v14 + 115) )
                          {
                            v19 = 12;
                          }
                          else
                          {
                            v15 = v1 + 172LL * a1;
                            if ( *(unsigned __int8 *)(v15 + 122) != 255 && *(_BYTE *)(v15 + 123) )
                            {
                              v19 = 13;
                            }
                            else
                            {
                              v16 = v1 + 172LL * a1;
                              if ( *(unsigned __int8 *)(v16 + 130) != 255 && *(_BYTE *)(v16 + 131) )
                              {
                                v19 = 14;
                              }
                              else
                              {
                                v17 = v1 + 172LL * a1;
                                if ( *(unsigned __int8 *)(v17 + 138) == 255 || !*(_BYTE *)(v17 + 139) )
                                  return 0;
                                v19 = 15;
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
  printk(&unk_3DF430, "rmnet_ipa3_check_any_client_inited");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d Found client index: %d which is inited\n",
      "rmnet_ipa3_check_any_client_inited",
      5872,
      v19);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa-wan %s:%d Found client index: %d which is inited\n",
      "rmnet_ipa3_check_any_client_inited",
      5872,
      v19);
  }
  return 1;
}
