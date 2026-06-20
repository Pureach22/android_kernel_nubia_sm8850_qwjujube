__int64 __fastcall rmnet_ipa3_set_lan_client_info(unsigned int *a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v4; // w3
  unsigned __int64 v5; // x4
  __int64 v6; // x0
  __int64 v7; // x0
  unsigned __int64 v9; // x22
  __int16 v10; // w9
  __int64 v11; // x23
  unsigned __int64 v12; // x21
  unsigned __int64 v13; // x21
  int ep_mapping; // w0
  __int64 v15; // x8
  __int64 v16; // x9
  unsigned __int64 v17; // x8
  _BYTE *v18; // x9
  int v19; // t1
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d Client MAC %02x:%02x:%02x:%02x:%02x:%02x\n",
      "rmnet_ipa3_set_lan_client_info",
      6022,
      *((unsigned __int8 *)a1 + 4),
      *((unsigned __int8 *)a1 + 5),
      *((unsigned __int8 *)a1 + 6),
      *((unsigned __int8 *)a1 + 7),
      *((unsigned __int8 *)a1 + 8),
      *((unsigned __int8 *)a1 + 9));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa-wan %s:%d Client MAC %02x:%02x:%02x:%02x:%02x:%02x\n",
      "rmnet_ipa3_set_lan_client_info",
      6022,
      *((unsigned __int8 *)a1 + 4),
      *((unsigned __int8 *)a1 + 5),
      *((unsigned __int8 *)a1 + 6),
      *((unsigned __int8 *)a1 + 7),
      *((unsigned __int8 *)a1 + 8),
      *((unsigned __int8 *)a1 + 9));
  }
  if ( *a1 >= 4 )
  {
    printk(&unk_3D6BB8, "rmnet_ipa3_set_lan_client_info");
    if ( ipa3_get_ipc_logbuf() )
    {
      v24 = ipa3_get_ipc_logbuf();
      ipc_log_string(v24, "ipa-wan %s:%d Invalid Device type: %d\n", "rmnet_ipa3_set_lan_client_info", 6027, *a1);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      return 4294967274LL;
    v25 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v25, "ipa-wan %s:%d Invalid Device type: %d\n", "rmnet_ipa3_set_lan_client_info", 6027, *a1);
    return 4294967274LL;
  }
  if ( (unsigned int)*((char *)a1 + 11) >= 0x10 )
  {
    printk(&unk_3B619F, "rmnet_ipa3_set_lan_client_info");
    if ( ipa3_get_ipc_logbuf() )
    {
      v26 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v26,
        "ipa-wan %s:%d Invalid Client Index: %d\n",
        "rmnet_ipa3_set_lan_client_info",
        6034,
        *((char *)a1 + 11));
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      return 4294967274LL;
    v27 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v27,
      "ipa-wan %s:%d Invalid Client Index: %d\n",
      "rmnet_ipa3_set_lan_client_info",
      6034,
      (unsigned int)*((char *)a1 + 11));
    return 4294967274LL;
  }
  if ( !*((_BYTE *)a1 + 20) || *((unsigned __int8 *)a1 + 20) + 1 != *((unsigned __int8 *)a1 + 21) )
  {
    printk(&unk_3C204C, "rmnet_ipa3_set_lan_client_info");
    if ( ipa3_get_ipc_logbuf() )
    {
      v28 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v28,
        "ipa-wan %s:%d Invalid counter indices %u, %u\n",
        "rmnet_ipa3_set_lan_client_info",
        6042,
        *((unsigned __int8 *)a1 + 20),
        *((unsigned __int8 *)a1 + 21));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v29 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v29,
        "ipa-wan %s:%d Invalid counter indices %u, %u\n",
        "rmnet_ipa3_set_lan_client_info",
        6042,
        *((unsigned __int8 *)a1 + 20),
        *((unsigned __int8 *)a1 + 21));
    }
    return 4294967274LL;
  }
  mutex_lock(rmnet_ipa3_ctx + 1200);
  v4 = *a1;
  if ( !*((_BYTE *)a1 + 10) )
  {
    if ( v4 > 4 )
      goto LABEL_51;
    goto LABEL_19;
  }
  if ( v4 > 3 )
    goto LABEL_51;
  v5 = *((unsigned __int8 *)a1 + 11);
  if ( v5 > 0xF )
    goto LABEL_51;
  if ( !*(_BYTE *)(rmnet_ipa3_ctx + 172LL * v4 + 8 * v5 + 1267) )
  {
LABEL_19:
    v9 = *((unsigned __int8 *)a1 + 11);
    if ( v9 <= 0x10 )
    {
      v10 = *((_WORD *)a1 + 4);
      v11 = rmnet_ipa3_ctx + 172LL * v4 + 1248;
      v12 = v11 + 8 * v9;
      *(_DWORD *)(v12 + 12) = a1[1];
      v13 = v12 + 12;
      *(_WORD *)(v13 + 4) = v10;
      *(_BYTE *)(v13 + 6) = *((_BYTE *)a1 + 11);
      ep_mapping = ipa_get_ep_mapping(a1[4]);
      if ( *a1 <= 3 )
      {
        v15 = rmnet_ipa3_ctx + 1248;
        *(_DWORD *)(rmnet_ipa3_ctx + 1248 + 172LL * *a1) = ep_mapping;
        if ( *a1 <= 3 )
        {
          v16 = v15 + 172LL * *a1;
          v17 = v11 + 2 * v9;
          v19 = *(unsigned __int8 *)(v16 + 4);
          v18 = (_BYTE *)(v16 + 4);
          if ( !v19 )
            *v18 = *((_BYTE *)a1 + 12);
          *(_BYTE *)(v17 + 140) = *((_BYTE *)a1 + 20);
          *(_BYTE *)(v17 + 141) = *((_BYTE *)a1 + 21);
          if ( ipa3_get_ipc_logbuf() )
          {
            v20 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v20,
              "ipa-wan %s:%d Device type %d, ul/dl = %d/%d\n",
              "rmnet_ipa3_set_lan_client_info",
              6080,
              *a1,
              *((unsigned __int8 *)a1 + 20),
              *((unsigned __int8 *)a1 + 21));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v21 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v21,
              "ipa-wan %s:%d Device type %d, ul/dl = %d/%d\n",
              "rmnet_ipa3_set_lan_client_info",
              6080,
              *a1,
              *((unsigned __int8 *)a1 + 20),
              *((unsigned __int8 *)a1 + 21));
          }
          *(_BYTE *)(v13 + 7) = 1;
          if ( *a1 <= 3 )
          {
            ++*(_DWORD *)(rmnet_ipa3_ctx + 172LL * *a1 + 1256);
            if ( ipa3_get_ipc_logbuf() )
            {
              v22 = ipa3_get_ipc_logbuf();
              if ( *a1 > 3 )
                goto LABEL_51;
              ipc_log_string(
                v22,
                "ipa-wan %s:%d Set the lan client info: %d, %d, %d\n",
                "rmnet_ipa3_set_lan_client_info",
                6089,
                *(char *)(v13 + 6),
                *(_DWORD *)(rmnet_ipa3_ctx + 172LL * *a1 + 1248),
                *(_DWORD *)(rmnet_ipa3_ctx + 172LL * *a1 + 1256));
            }
            if ( !ipa3_get_ipc_logbuf_low() )
            {
LABEL_35:
              mutex_unlock(rmnet_ipa3_ctx + 1200);
              return 0;
            }
            v23 = ipa3_get_ipc_logbuf_low();
            if ( *a1 <= 3 )
            {
              ipc_log_string(
                v23,
                "ipa-wan %s:%d Set the lan client info: %d, %d, %d\n",
                "rmnet_ipa3_set_lan_client_info",
                6089,
                *(char *)(v13 + 6),
                *(_DWORD *)(rmnet_ipa3_ctx + 172LL * *a1 + 1248),
                *(_DWORD *)(rmnet_ipa3_ctx + 172LL * *a1 + 1256));
              goto LABEL_35;
            }
          }
        }
      }
    }
LABEL_51:
    __break(0x5512u);
    JUMPOUT(0x14905C);
  }
  printk(&unk_3E1F0F, "rmnet_ipa3_set_lan_client_info");
  if ( ipa3_get_ipc_logbuf() )
  {
    v6 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v6,
      "ipa-wan %s:%d Client already inited: %d:%d\n",
      "rmnet_ipa3_set_lan_client_info",
      6052,
      *a1,
      *((char *)a1 + 11));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v7 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v7,
      "ipa-wan %s:%d Client already inited: %d:%d\n",
      "rmnet_ipa3_set_lan_client_info",
      6052,
      *a1,
      *((char *)a1 + 11));
  }
  mutex_unlock(rmnet_ipa3_ctx + 1200);
  return 4294967274LL;
}
