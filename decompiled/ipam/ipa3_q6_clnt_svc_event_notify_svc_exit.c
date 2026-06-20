__int64 __fastcall ipa3_q6_clnt_svc_event_notify_svc_exit(__int64 a1, _DWORD *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 ipc_logbuf_low; // x0

  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v4 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v4,
                   "ipa-wan %s:%d QMI svc:%d vers:%d ins:%d node:%d port:%d\n",
                   "ipa3_q6_clnt_svc_event_notify_svc_exit",
                   2207,
                   *a2,
                   a2[1],
                   a2[2],
                   a2[3],
                   a2[4]);
  }
  result = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( result )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(result);
    result = ipc_log_string(
               ipc_logbuf_low,
               "ipa-wan %s:%d QMI svc:%d vers:%d ins:%d node:%d port:%d\n",
               "ipa3_q6_clnt_svc_event_notify_svc_exit",
               2207,
               *a2,
               a2[1],
               a2[2],
               a2[3],
               a2[4]);
  }
  if ( (workqueues_stopped & 1) == 0 )
    return queue_delayed_work_on(32, ipa_clnt_req_workqueue, &ipa3_work_svc_exit, 0);
  return result;
}
