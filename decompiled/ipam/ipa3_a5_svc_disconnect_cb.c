__int64 __fastcall ipa3_a5_svc_disconnect_cb(__int64 a1)
{
  __int64 result; // x0
  __int64 ipc_logbuf_low; // x0

  result = ipa3_get_ipc_logbuf_low(a1);
  if ( result )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(result);
    return ipc_log_string(
             ipc_logbuf_low,
             "ipa-wan %s:%d Received QMI client disconnect\n",
             "ipa3_a5_svc_disconnect_cb",
             503);
  }
  return result;
}
