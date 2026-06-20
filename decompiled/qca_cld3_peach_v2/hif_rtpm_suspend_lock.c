__int64 hif_rtpm_suspend_lock()
{
  __int64 v0; // x19
  __int64 result; // x0

  v0 = gp_hif_rtpm_ctx;
  result = raw_spin_lock_irqsave(gp_hif_rtpm_ctx + 32);
  *(_QWORD *)(v0 + 40) = result;
  return result;
}
