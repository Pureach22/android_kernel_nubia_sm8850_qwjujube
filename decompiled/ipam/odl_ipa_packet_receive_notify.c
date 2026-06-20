__int64 __fastcall odl_ipa_packet_receive_notify(__int64 a1, int a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x0

  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d Rx packet was received\n", "odl_ipa_packet_receive_notify", 273);
  }
  if ( !a2 )
    return ipa3_send_adpl_msg(a3);
  result = printk(&unk_3E69B2, "odl_ipa_packet_receive_notify");
  v7 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(
        v8,
        "ipa %s:%d Invalid evt %d received in wan_ipa_receive\n",
        "odl_ipa_packet_receive_notify",
        277,
        a2);
      v7 = ipa3_ctx;
    }
    result = *(_QWORD *)(v7 + 34160);
    if ( result )
      return ipc_log_string(
               result,
               "ipa %s:%d Invalid evt %d received in wan_ipa_receive\n",
               "odl_ipa_packet_receive_notify",
               277,
               a2);
  }
  return result;
}
