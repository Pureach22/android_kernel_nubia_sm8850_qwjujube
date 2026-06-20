__int64 __fastcall ipa3_handle_mhi_alloc_channel_req(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 v2; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x0

  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v2 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v2,
                   "ipa-wan %s:%d Received QMI_IPA_MHI_ALLOC_CHANNEL_REQ_V01\n",
                   "ipa3_handle_mhi_alloc_channel_req",
                   322);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v4 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(
      v4,
      "ipa-wan %s:%d Received QMI_IPA_MHI_ALLOC_CHANNEL_REQ_V01\n",
      "ipa3_handle_mhi_alloc_channel_req",
      322);
  }
  v5 = printk(&unk_3E14DE, "ipa3_handle_mhi_alloc_channel_req");
  v6 = ipa3_get_ipc_logbuf(v5);
  if ( v6 )
  {
    v7 = ipa3_get_ipc_logbuf(v6);
    v6 = ipc_log_string(
           v7,
           "ipa-wan %s:%d imp handle allocate channel req fails\n",
           "ipa3_handle_mhi_alloc_channel_req",
           327);
  }
  result = ipa3_get_ipc_logbuf_low(v6);
  if ( result )
  {
    v9 = ipa3_get_ipc_logbuf_low(result);
    return ipc_log_string(
             v9,
             "ipa-wan %s:%d imp handle allocate channel req fails\n",
             "ipa3_handle_mhi_alloc_channel_req",
             327);
  }
  return result;
}
