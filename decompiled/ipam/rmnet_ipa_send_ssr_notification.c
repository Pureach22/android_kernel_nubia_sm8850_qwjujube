void __fastcall rmnet_ipa_send_ssr_notification(char a1)
{
  unsigned __int8 v1; // w8
  int v2; // w0
  int v3; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a1 & 1) != 0 )
    v1 = 25;
  else
    v1 = 24;
  v6 = v1;
  v2 = ipa_send_msg((unsigned __int8 *)&v6, nullptr, nullptr);
  if ( v2 )
  {
    v3 = v2;
    printk(&unk_3EA6F6, "rmnet_ipa_send_ssr_notification");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa-wan %s:%d ipa_send_msg failed: %d\n", "rmnet_ipa_send_ssr_notification", 4041, v3);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa-wan %s:%d ipa_send_msg failed: %d\n",
        "rmnet_ipa_send_ssr_notification",
        4041,
        v3);
    }
  }
  _ReadStatusReg(SP_EL0);
}
