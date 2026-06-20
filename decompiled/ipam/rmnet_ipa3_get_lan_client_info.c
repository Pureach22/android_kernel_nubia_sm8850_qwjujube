__int64 __fastcall rmnet_ipa3_get_lan_client_info(unsigned int a1, unsigned __int8 *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x0
  __int64 v7; // x10
  int v8; // w11
  int v9; // w10
  __int64 v11; // x10
  int v12; // w11
  int v13; // w10
  __int64 v15; // x10
  int v16; // w11
  int v17; // w10
  __int64 v19; // x10
  int v20; // w11
  int v21; // w10
  __int64 v23; // x10
  int v24; // w11
  int v25; // w10
  __int64 v27; // x10
  int v28; // w11
  int v29; // w10
  __int64 v31; // x10
  int v32; // w11
  int v33; // w10
  __int64 v35; // x10
  int v36; // w11
  int v37; // w10
  __int64 v39; // x10
  int v40; // w11
  int v41; // w10
  __int64 v43; // x10
  int v44; // w11
  int v45; // w10
  __int64 v47; // x10
  int v48; // w11
  int v49; // w10
  __int64 v51; // x10
  int v52; // w11
  int v53; // w10
  __int64 v55; // x10
  int v56; // w11
  int v57; // w10
  __int64 v59; // x10
  int v60; // w11
  int v61; // w10
  __int64 v63; // x10
  int v64; // w11
  int v65; // w10
  __int64 v67; // x8
  int v68; // w9
  int v69; // w8
  unsigned int v71; // w19
  __int64 v72; // x0
  __int64 v73; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d Client MAC %02x:%02x:%02x:%02x:%02x:%02x\n",
      "rmnet_ipa3_get_lan_client_info",
      5891,
      *a2,
      a2[1],
      a2[2],
      a2[3],
      a2[4],
      a2[5]);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
  if ( ipc_logbuf_low )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v6,
      "ipa-wan %s:%d Client MAC %02x:%02x:%02x:%02x:%02x:%02x\n",
      "rmnet_ipa3_get_lan_client_info",
      5891,
      *a2,
      a2[1],
      a2[2],
      a2[3],
      a2[4],
      a2[5]);
  }
  if ( a1 <= 4 )
  {
    v7 = rmnet_ipa3_ctx + 172LL * a1;
    v8 = *(_DWORD *)(v7 + 1260);
    v9 = *(unsigned __int16 *)(v7 + 1264);
    if ( v8 == *(_DWORD *)a2 && v9 == *((unsigned __int16 *)a2 + 2) )
    {
      v71 = 0;
    }
    else
    {
      v11 = rmnet_ipa3_ctx + 172LL * a1;
      v12 = *(_DWORD *)(v11 + 1268);
      v13 = *(unsigned __int16 *)(v11 + 1272);
      if ( v12 == *(_DWORD *)a2 && v13 == *((unsigned __int16 *)a2 + 2) )
      {
        v71 = 1;
      }
      else
      {
        v15 = rmnet_ipa3_ctx + 172LL * a1;
        v16 = *(_DWORD *)(v15 + 1276);
        v17 = *(unsigned __int16 *)(v15 + 1280);
        if ( v16 == *(_DWORD *)a2 && v17 == *((unsigned __int16 *)a2 + 2) )
        {
          v71 = 2;
        }
        else
        {
          v19 = rmnet_ipa3_ctx + 172LL * a1;
          v20 = *(_DWORD *)(v19 + 1284);
          v21 = *(unsigned __int16 *)(v19 + 1288);
          if ( v20 == *(_DWORD *)a2 && v21 == *((unsigned __int16 *)a2 + 2) )
          {
            v71 = 3;
          }
          else
          {
            v23 = rmnet_ipa3_ctx + 172LL * a1;
            v24 = *(_DWORD *)(v23 + 1292);
            v25 = *(unsigned __int16 *)(v23 + 1296);
            if ( v24 == *(_DWORD *)a2 && v25 == *((unsigned __int16 *)a2 + 2) )
            {
              v71 = 4;
            }
            else
            {
              v27 = rmnet_ipa3_ctx + 172LL * a1;
              v28 = *(_DWORD *)(v27 + 1300);
              v29 = *(unsigned __int16 *)(v27 + 1304);
              if ( v28 == *(_DWORD *)a2 && v29 == *((unsigned __int16 *)a2 + 2) )
              {
                v71 = 5;
              }
              else
              {
                v31 = rmnet_ipa3_ctx + 172LL * a1;
                v32 = *(_DWORD *)(v31 + 1308);
                v33 = *(unsigned __int16 *)(v31 + 1312);
                if ( v32 == *(_DWORD *)a2 && v33 == *((unsigned __int16 *)a2 + 2) )
                {
                  v71 = 6;
                }
                else
                {
                  v35 = rmnet_ipa3_ctx + 172LL * a1;
                  v36 = *(_DWORD *)(v35 + 1316);
                  v37 = *(unsigned __int16 *)(v35 + 1320);
                  if ( v36 == *(_DWORD *)a2 && v37 == *((unsigned __int16 *)a2 + 2) )
                  {
                    v71 = 7;
                  }
                  else
                  {
                    v39 = rmnet_ipa3_ctx + 172LL * a1;
                    v40 = *(_DWORD *)(v39 + 1324);
                    v41 = *(unsigned __int16 *)(v39 + 1328);
                    if ( v40 == *(_DWORD *)a2 && v41 == *((unsigned __int16 *)a2 + 2) )
                    {
                      v71 = 8;
                    }
                    else
                    {
                      v43 = rmnet_ipa3_ctx + 172LL * a1;
                      v44 = *(_DWORD *)(v43 + 1332);
                      v45 = *(unsigned __int16 *)(v43 + 1336);
                      if ( v44 == *(_DWORD *)a2 && v45 == *((unsigned __int16 *)a2 + 2) )
                      {
                        v71 = 9;
                      }
                      else
                      {
                        v47 = rmnet_ipa3_ctx + 172LL * a1;
                        v48 = *(_DWORD *)(v47 + 1340);
                        v49 = *(unsigned __int16 *)(v47 + 1344);
                        if ( v48 == *(_DWORD *)a2 && v49 == *((unsigned __int16 *)a2 + 2) )
                        {
                          v71 = 10;
                        }
                        else
                        {
                          v51 = rmnet_ipa3_ctx + 172LL * a1;
                          v52 = *(_DWORD *)(v51 + 1348);
                          v53 = *(unsigned __int16 *)(v51 + 1352);
                          if ( v52 == *(_DWORD *)a2 && v53 == *((unsigned __int16 *)a2 + 2) )
                          {
                            v71 = 11;
                          }
                          else
                          {
                            v55 = rmnet_ipa3_ctx + 172LL * a1;
                            v56 = *(_DWORD *)(v55 + 1356);
                            v57 = *(unsigned __int16 *)(v55 + 1360);
                            if ( v56 == *(_DWORD *)a2 && v57 == *((unsigned __int16 *)a2 + 2) )
                            {
                              v71 = 12;
                            }
                            else
                            {
                              v59 = rmnet_ipa3_ctx + 172LL * a1;
                              v60 = *(_DWORD *)(v59 + 1364);
                              v61 = *(unsigned __int16 *)(v59 + 1368);
                              if ( v60 == *(_DWORD *)a2 && v61 == *((unsigned __int16 *)a2 + 2) )
                              {
                                v71 = 13;
                              }
                              else
                              {
                                v63 = rmnet_ipa3_ctx + 172LL * a1;
                                v64 = *(_DWORD *)(v63 + 1372);
                                v65 = *(unsigned __int16 *)(v63 + 1376);
                                if ( v64 == *(_DWORD *)a2 && v65 == *((unsigned __int16 *)a2 + 2) )
                                {
                                  v71 = 14;
                                }
                                else
                                {
                                  v67 = rmnet_ipa3_ctx + 172LL * a1;
                                  v68 = *(_DWORD *)(v67 + 1380);
                                  v69 = *(unsigned __int16 *)(v67 + 1384);
                                  if ( v68 != *(_DWORD *)a2 || v69 != *((unsigned __int16 *)a2 + 2) )
                                    return (unsigned int)-22;
                                  v71 = 15;
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
    if ( ipa3_get_ipc_logbuf() )
    {
      v72 = ipa3_get_ipc_logbuf();
      ipc_log_string(v72, "ipa-wan %s:%d Matched client index: %d\n", "rmnet_ipa3_get_lan_client_info", 5900, v71);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v73 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v73, "ipa-wan %s:%d Matched client index: %d\n", "rmnet_ipa3_get_lan_client_info", 5900, v71);
    }
    return v71;
  }
  __break(0x5512u);
  return rmnet_ipa3_check_any_client_inited(ipc_logbuf_low);
}
