__int64 __fastcall ipa_pm_set_clock_index(__int64 a1)
{
  int v1; // w19
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 result; // x0
  __int64 ipc_logbuf_low; // x0

  v1 = a1;
  if ( (a1 & 0x80000000) == 0 && ipa_pm_ctx )
    *(_DWORD *)(ipa_pm_ctx + 1120) = a1;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(v3, "ipa_pm %s:%d Setting pm clock vote to %d\n", "ipa_pm_set_clock_index", 1360, v1);
  }
  result = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( result )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(result);
    return ipc_log_string(
             ipc_logbuf_low,
             "ipa_pm %s:%d Setting pm clock vote to %d\n",
             "ipa_pm_set_clock_index",
             1360,
             v1);
  }
  return result;
}
