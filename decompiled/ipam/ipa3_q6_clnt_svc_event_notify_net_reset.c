__int64 ipa3_q6_clnt_svc_event_notify_net_reset()
{
  __int64 result; // x0

  if ( (workqueues_stopped & 1) == 0 )
    return queue_delayed_work_on(32, ipa_clnt_req_workqueue, &ipa3_work_svc_exit, 0);
  return result;
}
