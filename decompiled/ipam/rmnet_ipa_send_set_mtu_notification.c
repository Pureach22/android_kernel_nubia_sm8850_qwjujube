__int64 __fastcall rmnet_ipa_send_set_mtu_notification(
        const char *a1,
        unsigned __int16 a2,
        unsigned __int16 a3,
        int a4)
{
  __int64 v8; // x23
  size_t v9; // x0
  unsigned __int64 v10; // x2
  int v11; // w0
  __int64 v12; // x0
  __int64 result; // x0
  __int64 v14; // x0
  int v15; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v19; // x25
  long double (*v20)(_QWORD, const char *, ...); // x0
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 2621479;
  v8 = _kmalloc_cache_noprof(ipc_log_string, 3520, 40);
  if ( !v8 )
  {
LABEL_19:
    result = 4294967284LL;
    goto LABEL_20;
  }
  while ( 1 )
  {
    v9 = strnlen(a1, 0x20u);
    if ( v9 != -1 )
      break;
    _fortify_panic(2, -1, 0);
LABEL_18:
    _fortify_panic(7, 32, v10);
    StatusReg = _ReadStatusReg(SP_EL0);
    v19 = *(_QWORD *)(StatusReg + 80);
    v20 = ipc_log_string;
    *(_QWORD *)(StatusReg + 80) = &rmnet_ipa_send_set_mtu_notification__alloc_tag;
    v8 = _kmalloc_cache_noprof(v20, 3520, 40);
    *(_QWORD *)(StatusReg + 80) = v19;
    if ( !v8 )
      goto LABEL_19;
  }
  if ( v9 == 32 )
    v10 = 32;
  else
    v10 = v9 + 1;
  if ( v10 >= 0x21 )
    goto LABEL_18;
  sized_strscpy(v8, a1);
  *(_WORD *)(v8 + 36) = a2;
  *(_WORD *)(v8 + 38) = a3;
  *(_DWORD *)(v8 + 32) = a4;
  v11 = ipa_send_msg((unsigned __int8 *)&v21, (_WORD *)v8, ipa3_wwan_msg_free_cb);
  if ( v11 )
  {
    v15 = v11;
    printk(&unk_3EA6F6, "rmnet_ipa_send_set_mtu_notification");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa-wan %s:%d ipa_send_msg failed: %d\n",
        "rmnet_ipa_send_set_mtu_notification",
        3368,
        v15);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa-wan %s:%d ipa_send_msg failed: %d\n",
        "rmnet_ipa_send_set_mtu_notification",
        3368,
        v15);
    }
    result = 4294967282LL;
  }
  else
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v12 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v12,
        "ipa-wan %s:%d sent new mtu_v4(%d)/mtu_v6(%d) with iptype(%d) for iface(%s) to IPACM",
        "rmnet_ipa_send_set_mtu_notification",
        3373,
        a2,
        a3,
        a4,
        a1);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v14,
        "ipa-wan %s:%d sent new mtu_v4(%d)/mtu_v6(%d) with iptype(%d) for iface(%s) to IPACM",
        "rmnet_ipa_send_set_mtu_notification",
        3373,
        a2,
        a3,
        a4,
        a1);
      result = 0;
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
