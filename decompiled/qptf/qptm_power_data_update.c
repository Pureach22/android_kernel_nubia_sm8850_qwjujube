__int64 qptm_power_data_update()
{
  return blocking_notifier_call_chain(&qptm_update_notifier, 0, 0);
}
