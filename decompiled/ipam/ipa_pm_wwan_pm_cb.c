__int64 __fastcall ipa_pm_wwan_pm_cb(__int64 a1, int a2)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d event %d\n", "ipa_pm_wwan_pm_cb", 3597, a2);
  }
  if ( a2 )
    return printk(&unk_3F957C, "ipa_pm_wwan_pm_cb");
  if ( !*(_DWORD *)(a1 + 2928) )
    return complete_all(a1 + 2896);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v5 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v5, "ipa-wan %s:%d Resource Granted - starting queue\n", "ipa3_pm_resource_granted", 3510);
  }
  return queue_work_on(32, system_wq, &ipa3_tx_wakequeue_work);
}
