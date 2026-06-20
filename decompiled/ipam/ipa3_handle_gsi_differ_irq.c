__int64 ipa3_handle_gsi_differ_irq()
{
  return queue_work_on(32, *(_QWORD *)(ipa3_ctx + 31944), &ipa_inc_clients_enable_clks_on_wq_work);
}
