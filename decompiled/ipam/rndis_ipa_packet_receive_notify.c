__int64 __fastcall rndis_ipa_packet_receive_notify(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v7; // x0
  __int16 v8; // w0
  __int64 v9; // x8
  __int64 result; // x0
  __int64 (__fastcall *v11)(_QWORD); // x8

  v3 = *(unsigned int *)(a3 + 112);
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d packet Rx, len=%d\n", "rndis_ipa_packet_receive_notify", 1258, v3);
  if ( !a1 )
  {
    if ( ipa_rndis_logbuf )
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d Private context is NULL. Drop SKB.\n",
        "rndis_ipa_packet_receive_notify",
        1261);
    return dev_kfree_skb_any_reason(a3, 2);
  }
  if ( *(_BYTE *)(a1 + 24) == 1 )
    rndis_ipa_dump_skb(a3);
  if ( *(_DWORD *)(a1 + 72) != 4 )
  {
    if ( ipa_rndis_logbuf )
    {
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d use connect()/up() before receive()\n",
        "rndis_ipa_packet_receive_notify",
        1270);
      if ( ipa_rndis_logbuf )
        ipc_log_string(
          ipa_rndis_logbuf,
          "RNDIS_IPA %s:%d packet dropped (length=%d)\n",
          "rndis_ipa_packet_receive_notify",
          1272,
          *(_DWORD *)(a3 + 112));
    }
    goto LABEL_16;
  }
  if ( a2 )
  {
    if ( (unsigned int)__ratelimit(&rndis_ipa_packet_receive_notify__rs, "rndis_ipa_packet_receive_notify") )
    {
      _ReadStatusReg(SP_EL0);
      printk(&unk_3E0216, "rndis_ipa_packet_receive_notify");
      v7 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
        goto LABEL_16;
    }
    else
    {
      v7 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
      {
LABEL_16:
        ++*(_DWORD *)(a1 + 20);
        return dev_kfree_skb_any_reason(a3, 2);
      }
    }
    ipc_log_string(
      v7,
      "RNDIS_IPA %s:%d a none IPA_RECEIVE event in driver RX\n",
      "rndis_ipa_packet_receive_notify",
      1279);
    goto LABEL_16;
  }
  if ( (*(_BYTE *)(a1 + 26) & 1) == 0 )
    skb_pull(a3, 44);
  *(_QWORD *)(a3 + 16) = *(_QWORD *)a1;
  v8 = eth_type_trans(a3);
  v9 = *(_QWORD *)(a3 + 16);
  *(_WORD *)(a3 + 180) = v8;
  if ( *(_BYTE *)(v9 + 2705) == 1 )
  {
    if ( ipa_rndis_logbuf )
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d packet got filtered out on RX path\n",
        "rndis_ipa_packet_receive_notify",
        1292);
    goto LABEL_16;
  }
  v11 = *(__int64 (__fastcall **)(_QWORD))(a1 + 216);
  if ( *((_DWORD *)v11 - 1) != -1282094308 )
    __break(0x8228u);
  result = v11(a3);
  ++*(_QWORD *)(*(_QWORD *)a1 + 552LL);
  *(_QWORD *)(*(_QWORD *)a1 + 568LL) += v3;
  return result;
}
