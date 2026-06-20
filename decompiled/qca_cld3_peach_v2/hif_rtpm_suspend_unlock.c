__int64 hif_rtpm_suspend_unlock()
{
  return raw_spin_unlock_irqrestore(gp_hif_rtpm_ctx + 32, *(_QWORD *)(gp_hif_rtpm_ctx + 40));
}
