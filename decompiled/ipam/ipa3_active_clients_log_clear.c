__int64 ipa3_active_clients_log_clear()
{
  __int64 v0; // x1
  __int64 v1; // x0

  v0 = raw_spin_lock_irqsave(ipa3_ctx + 30560);
  v1 = ipa3_ctx + 30560;
  *(_QWORD *)(ipa3_ctx + 31528) = 0x7700000000LL;
  return raw_spin_unlock_irqrestore(v1, v0);
}
