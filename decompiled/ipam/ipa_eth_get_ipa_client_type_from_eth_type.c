__int64 __fastcall ipa_eth_get_ipa_client_type_from_eth_type(unsigned int a1, int a2)
{
  int v2; // w8
  unsigned int v3; // w9
  unsigned int v4; // w10
  int v5; // w11
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 > 5 )
  {
    printk(&unk_3D0FA3, "ipa_eth_get_ipa_client_type_from_eth_type");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_eth %s:%d invalid client type%d\n",
        "ipa_eth_get_ipa_client_type_from_eth_type",
        1250,
        a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_eth %s:%d invalid client type%d\n",
        "ipa_eth_get_ipa_client_type_from_eth_type",
        1250,
        a1);
    }
    return 134;
  }
  else
  {
    v2 = 1 << a1;
    if ( a2 )
      v3 = 102;
    else
      v3 = 103;
    if ( a2 )
      v4 = 108;
    else
      v4 = 109;
    if ( a2 )
      v5 = 48;
    else
      v5 = 49;
    if ( (v2 & 0xC) == 0 )
      v4 = v5;
    if ( (v2 & 3) != 0 )
      return v3;
    else
      return v4;
  }
}
