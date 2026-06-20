__int64 __fastcall rmnet_ipa3_send_lan_client_msg(__int64 *a1)
{
  __int64 v2; // x19
  int v3; // w3
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x10
  unsigned int v9; // w8
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w20
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = _kmalloc_cache_noprof(ipc_log_string, 3520, 38);
  if ( v2 )
  {
    v3 = *((_DWORD *)a1 + 10);
    if ( (v3 & 0xFFFFFFFE) == 0x1E )
    {
      v5 = *a1;
      v4 = a1[1];
      *((_BYTE *)a1 + 31) = 0;
      v18 = 2490368;
      *(_QWORD *)v2 = v5;
      *(_QWORD *)(v2 + 8) = v4;
      v6 = a1[2];
      v7 = a1[3];
      v8 = *(__int64 *)((char *)a1 + 30);
      LOBYTE(v18) = v3;
      *(_QWORD *)(v2 + 16) = v6;
      *(_QWORD *)(v2 + 24) = v7;
      *(_QWORD *)(v2 + 30) = v8;
      v9 = ipa_send_msg((unsigned __int8 *)&v18, (_WORD *)v2, rmnet_ipa_free_msg);
      result = 0;
      if ( v9 )
      {
        v13 = v9;
        printk(&unk_3EA6F6, "rmnet_ipa3_send_lan_client_msg");
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(
            ipc_logbuf,
            "ipa-wan %s:%d ipa_send_msg failed: %d\n",
            "rmnet_ipa3_send_lan_client_msg",
            6197,
            v13);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipa-wan %s:%d ipa_send_msg failed: %d\n",
            "rmnet_ipa3_send_lan_client_msg",
            6197,
            v13);
        }
        kfree(v2);
        result = v13;
      }
    }
    else
    {
      printk(&unk_3EA6C7, "rmnet_ipa3_send_lan_client_msg");
      if ( ipa3_get_ipc_logbuf() )
      {
        v11 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v11,
          "ipa-wan %s:%d Wrong event given. Event:- %d\n",
          "rmnet_ipa3_send_lan_client_msg",
          6184,
          *((_DWORD *)a1 + 10));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v12 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v12,
          "ipa-wan %s:%d Wrong event given. Event:- %d\n",
          "rmnet_ipa3_send_lan_client_msg",
          6184,
          *((_DWORD *)a1 + 10));
      }
      kfree(v2);
      result = 4294967274LL;
    }
  }
  else
  {
    printk(&unk_3FF0D2, "rmnet_ipa3_send_lan_client_msg");
    if ( ipa3_get_ipc_logbuf() )
    {
      v16 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v16,
        "ipa-wan %s:%d Can't allocate memory for tether_info\n",
        "rmnet_ipa3_send_lan_client_msg",
        6177);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v17,
        "ipa-wan %s:%d Can't allocate memory for tether_info\n",
        "rmnet_ipa3_send_lan_client_msg",
        6177);
    }
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
