__int64 __fastcall ipa3_q6_clnt_svc_event_notify_svc_new(__int64 a1, _DWORD *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 v4; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x0
  __int64 v7; // x8

  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v4 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v4,
                   "ipa-wan %s:%d QMI svc:%d vers:%d ins:%d node:%d port:%d\n",
                   "ipa3_q6_clnt_svc_event_notify_svc_new",
                   2182,
                   *a2,
                   a2[1],
                   a2[2],
                   a2[3],
                   a2[4]);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v6 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(
      v6,
      "ipa-wan %s:%d QMI svc:%d vers:%d ins:%d node:%d port:%d\n",
      "ipa3_q6_clnt_svc_event_notify_svc_new",
      2182,
      *a2,
      a2[1],
      a2[2],
      a2[3],
      a2[4]);
  }
  if ( ipa3_qmi_ctx )
  {
    v7 = ipa3_qmi_ctx + 28672;
    *(_WORD *)(ipa3_qmi_ctx + 28876) = 42;
    *(_DWORD *)(v7 + 208) = a2[3];
    *(_DWORD *)(v7 + 212) = a2[4];
  }
  if ( (workqueues_stopped & 1) == 0 )
    queue_delayed_work_on(32, ipa_clnt_req_workqueue, &ipa3_work_svc_arrive, 0);
  return 0;
}
