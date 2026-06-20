__int64 __fastcall spcom_create_channel(char *string, char a2, __int64 a3)
{
  int v5; // w24
  unsigned int v6; // w20
  size_t v7; // x0
  __int64 v8; // x2
  __int64 v9; // x22
  __int64 v10; // x26
  __int64 v11; // x23
  __int64 v12; // x2
  __int64 v14; // x0
  __int64 v15; // x1

  v5 = *(_DWORD *)(spcom_dev + 58428);
  if ( v5 )
  {
    printk(&unk_1146C, "spcom_create_channel", a3);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: module remove in progress\n",
      "spcom_create_channel",
      (const char *)&unk_F80E);
    v6 = -19;
    if ( !string )
      goto LABEL_24;
  }
  else
  {
    v6 = 0;
    if ( !string )
      goto LABEL_24;
  }
  if ( !*string )
    goto LABEL_24;
  v7 = strnlen(string, 0x20u);
  if ( v7 == -1 )
    goto LABEL_34;
  if ( v7 >= 0x20 )
  {
LABEL_24:
    printk(&unk_1128C, "spcom_create_channel", a3);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: invalid channel name\n", "spcom_create_channel", &unk_F80E);
    return (unsigned int)-22;
  }
  v7 = strnlen(string, 0x20u);
  if ( v7 != -1 )
  {
    if ( v7 > 0x1F || strcmp(string, "spcom") )
    {
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: create spcom channel, name[%s], is sharable[%d]\n",
        "spcom_create_channel",
        (const char *)&unk_F80E,
        string,
        a2 & 1);
      v9 = 0;
      v10 = 32;
      v11 = spcom_dev + 1200;
      do
      {
        if ( !strcmp((const char *)v11, string) )
        {
          if ( (a2 & 1) != 0 )
          {
            if ( *(_BYTE *)(v11 + 233) == 1 )
            {
              printk(&unk_10DD1, "spcom_create_channel", v12);
              ipc_log_string(
                spcom_ipc_log_context,
                "%sspcom:%s: already created channel as sharable\n",
                "spcom_create_channel",
                (const char *)&unk_F80E);
              return 0;
            }
            printk(&unk_12CBC, "spcom_create_channel", v12);
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: channel already exist, cannot create sharable channel\n",
              "spcom_create_channel",
              (const char *)&unk_F80E);
            v6 = -22;
          }
          else if ( !v5 )
          {
            goto LABEL_21;
          }
          goto LABEL_32;
        }
        if ( !v9 )
        {
          if ( *(_BYTE *)v11 )
            v9 = 0;
          else
            v9 = v11;
        }
        --v10;
        v11 += 1784;
      }
      while ( v10 );
      if ( !v9 )
      {
        printk(&unk_10B97, "spcom_create_channel", v12);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: no free channel\n",
          "spcom_create_channel",
          (const char *)&unk_F80E);
        return (unsigned int)-19;
      }
      if ( !(unsigned int)spcom_init_channel(v9, a2 & 1, string) )
      {
LABEL_21:
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: create channel [%s] is done\n",
          "spcom_create_channel",
          (const char *)&unk_F80E,
          string);
        return 0;
      }
      v6 = -19;
LABEL_32:
      printk(&unk_113AA, "spcom_create_channel", string);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: create channel [%s] failed, ret[%d]\n",
        "spcom_create_channel",
        (const char *)&unk_F80E,
        string,
        v6);
      return v6;
    }
    printk(&unk_12C91, "spcom_create_channel", v8);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: cannot create control channel\n",
      "spcom_create_channel",
      &unk_F80E);
    return (unsigned int)-22;
  }
LABEL_34:
  v14 = _fortify_panic(2, -1, v7 + 1);
  return spcom_channel_deinit_locked(v14, v15);
}
