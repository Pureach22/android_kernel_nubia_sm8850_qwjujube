long double __fastcall apps_ipa_packet_receive_notify(_QWORD *a1, int a2, __int64 a3)
{
  __int64 v3; // x21
  long double result; // q0
  __int64 ipc_logbuf_low; // x0
  _QWORD *v8; // x8
  int v9; // w9
  int v10; // w10
  __int16 v11; // w8
  int v12; // w10
  __int64 v13; // x9
  __int64 ipc_logbuf; // x0
  __int64 v16; // x0

  if ( !a2 )
  {
    v3 = *(unsigned int *)(a3 + 112);
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      result = ipc_log_string(
                 ipc_logbuf_low,
                 "ipa-wan %s:%d Rx packet was received",
                 "apps_ipa_packet_receive_notify",
                 1416);
    }
    v8 = (_QWORD *)rmnet_ipa3_ctx;
    if ( rmnet_ipa3_ctx )
    {
      v8 = *(_QWORD **)rmnet_ipa3_ctx;
      if ( *(_QWORD *)rmnet_ipa3_ctx )
        v8 = (_QWORD *)*v8;
    }
    v9 = *(_DWORD *)(a3 + 224);
    v10 = *(_DWORD *)(a3 + 216);
    *(_QWORD *)(a3 + 16) = v8;
    *(_WORD *)(a3 + 180) = -1792;
    v11 = v9 - v10;
    v12 = (unsigned __int8)byte_2018C2;
    *(_WORD *)(a3 + 186) = v11;
    *(_WORD *)(a3 + 124) = 1;
    if ( v12 == 1 )
    {
      if ( !(unsigned int)netif_receive_skb(a3, result) )
      {
LABEL_15:
        v13 = a1[71] + v3;
        ++a1[69];
        a1[71] = v13;
        return result;
      }
    }
    else if ( (a1[69] & 0xFLL) != 0 || !(unsigned int)netif_rx(a3, result) )
    {
      goto LABEL_15;
    }
    if ( (unsigned int)__ratelimit(&apps_ipa_packet_receive_notify__rs, "apps_ipa_packet_receive_notify") )
      printk(&unk_3FF336, "apps_ipa_packet_receive_notify");
    ++a1[75];
    goto LABEL_15;
  }
  printk(&unk_3CDE38, "apps_ipa_packet_receive_notify");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d Invalid evt %d received in wan_ipa_receive\n",
      "apps_ipa_packet_receive_notify",
      1447,
      a2);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v16 = ipa3_get_ipc_logbuf_low();
    return ipc_log_string(
             v16,
             "ipa-wan %s:%d Invalid evt %d received in wan_ipa_receive\n",
             "apps_ipa_packet_receive_notify",
             1447,
             a2);
  }
  return result;
}
