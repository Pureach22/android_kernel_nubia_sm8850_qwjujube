__int64 __fastcall rmnet_ipa3_get_wan_mtu(__int64 a1)
{
  __int64 v2; // x21
  int v3; // w0
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  v2 = rmnet_ipa3_ctx;
  *(_BYTE *)(a1 + 31) = 0;
  v3 = ((__int64 (*)(void))find_vchannel_name_index)();
  if ( v3 == 15 )
  {
    printk(&unk_3F9288, "rmnet_ipa3_get_wan_mtu");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa-wan %s:%d %s is an invalid iface name\n",
        "rmnet_ipa3_get_wan_mtu",
        6474,
        (const char *)a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa-wan %s:%d %s is an invalid iface name\n",
        "rmnet_ipa3_get_wan_mtu",
        6474,
        (const char *)a1);
    }
    return 4294967277LL;
  }
  else
  {
    LODWORD(v4) = v3;
    v5 = v2 + 556;
    if ( ipa3_get_ipc_logbuf() )
    {
      v6 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v6,
        "ipa-wan %s:%d getting v4 MTU = %d\n",
        "rmnet_ipa3_get_wan_mtu",
        6478,
        *(unsigned __int16 *)(v5 + 32LL * (int)v4 + 28));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v7 = ipa3_get_ipc_logbuf_low();
      v4 = (int)v4;
      ipc_log_string(
        v7,
        "ipa-wan %s:%d getting v4 MTU = %d\n",
        "rmnet_ipa3_get_wan_mtu",
        6478,
        *(unsigned __int16 *)(v5 + 32LL * (int)v4 + 28));
    }
    else
    {
      v4 = (int)v4;
    }
    v8 = v5 + 32 * v4;
    *(_WORD *)(a1 + 36) = *(_WORD *)(v8 + 28);
    if ( ipa3_get_ipc_logbuf() )
    {
      v9 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v9,
        "ipa-wan %s:%d getting v6 MTU = %d\n",
        "rmnet_ipa3_get_wan_mtu",
        6482,
        *(unsigned __int16 *)(v8 + 30));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v10,
        "ipa-wan %s:%d getting v6 MTU = %d\n",
        "rmnet_ipa3_get_wan_mtu",
        6482,
        *(unsigned __int16 *)(v8 + 30));
    }
    result = 0;
    *(_WORD *)(a1 + 38) = *(_WORD *)(v8 + 30);
  }
  return result;
}
