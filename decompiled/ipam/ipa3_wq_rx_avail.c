__int64 __fastcall ipa3_wq_rx_avail(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x8
  __int64 v3; // x0

  if ( a1 == 48 )
  {
    _warn_printk("rx pkt is null");
    __break(0x800u);
  }
  result = __ratelimit(&ipa3_wq_rx_common__rs, "ipa3_wq_rx_common");
  if ( (_DWORD)result )
    result = printk(&unk_3C6D67, "ipa3_wq_rx_common");
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d gsi_chan_xfer_notify is null\n", "ipa3_wq_rx_common", 5593);
      v2 = ipa3_ctx;
    }
    result = *(_QWORD *)(v2 + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d gsi_chan_xfer_notify is null\n", "ipa3_wq_rx_common", 5593);
  }
  return result;
}
