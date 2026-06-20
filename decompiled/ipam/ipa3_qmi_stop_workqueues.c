__int64 __fastcall ipa3_qmi_stop_workqueues(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 v2; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0

  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v2 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(v2, "ipa-wan %s:%d Stopping all QMI workqueues\n", "ipa3_qmi_stop_workqueues", 2541);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v4 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v4, "ipa-wan %s:%d Stopping all QMI workqueues\n", "ipa3_qmi_stop_workqueues", 2541);
  }
  workqueues_stopped = 1;
  cancel_delayed_work(&ipa3_work_svc_arrive);
  return cancel_delayed_work(&ipa3_work_svc_exit);
}
