__int64 __fastcall hif_rtpm_set_monitor_wake_intr(__int64 result)
{
  *(_DWORD *)(gp_hif_rtpm_ctx + 200) = result;
  return result;
}
