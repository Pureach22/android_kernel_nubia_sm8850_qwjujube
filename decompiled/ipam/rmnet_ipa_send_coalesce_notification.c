__int64 __fastcall rmnet_ipa_send_coalesce_notification(unsigned __int8 a1, char a2, char a3, char a4)
{
  __int64 v8; // x0
  char v9; // w8
  int v10; // w0
  int v11; // w23
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 result; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 196608;
  v8 = _kmalloc_cache_noprof(sg_next, 3520, 3);
  if ( !v8 )
  {
    result = 4294967284LL;
    goto LABEL_20;
  }
  *(_BYTE *)(v8 + 1) = a3 & 1;
  if ( (a2 & 1) != 0 )
    v9 = 37;
  else
    v9 = 38;
  *(_BYTE *)v8 = a1;
  *(_BYTE *)(v8 + 2) = a4 & 1;
  LOBYTE(v17) = v9;
  v10 = ipa_send_msg((unsigned __int8 *)&v17, (_WORD *)v8, ipa3_wwan_msg_free_cb);
  if ( v10 )
  {
    v11 = v10;
    if ( (unsigned int)__ratelimit(&rmnet_ipa_send_coalesce_notification__rs, "rmnet_ipa_send_coalesce_notification") )
    {
      printk(&unk_3EA6F6, "rmnet_ipa_send_coalesce_notification");
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_9;
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
LABEL_9:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa-wan %s:%d ipa_send_msg failed: %d\n",
          "rmnet_ipa_send_coalesce_notification",
          3339,
          v11);
      }
      result = 4294967282LL;
      goto LABEL_20;
    }
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d ipa_send_msg failed: %d\n",
      "rmnet_ipa_send_coalesce_notification",
      3339,
      v11);
    goto LABEL_9;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v15 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v15,
      "ipa-wan %s:%d qmap-id(%d),enable(%d),tcp(%d),udp(%d)\n",
      "rmnet_ipa_send_coalesce_notification",
      3343,
      a1,
      a2 & 1,
      a3 & 1,
      a4 & 1);
  }
  result = ipa3_get_ipc_logbuf_low();
  if ( result )
  {
    v16 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v16,
      "ipa-wan %s:%d qmap-id(%d),enable(%d),tcp(%d),udp(%d)\n",
      "rmnet_ipa_send_coalesce_notification",
      3343,
      a1,
      a2 & 1,
      a3 & 1,
      a4 & 1);
    result = 0;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
