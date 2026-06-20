__int64 hif_rtpm_get_monitor_wake_intr()
{
  return *(unsigned int *)(gp_hif_rtpm_ctx + 200);
}
