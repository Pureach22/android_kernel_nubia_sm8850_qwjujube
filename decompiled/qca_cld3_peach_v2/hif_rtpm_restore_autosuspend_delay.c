__int64 hif_rtpm_restore_autosuspend_delay()
{
  int v0; // w4
  __int64 v1; // x1
  __int64 v2; // x20
  int v4; // w4
  __int64 v5; // x20

  v0 = *(_DWORD *)(gp_hif_rtpm_ctx + 316);
  v1 = *(unsigned int *)(gp_hif_rtpm_ctx + 312);
  if ( v0 == (_DWORD)v1 )
  {
    v2 = jiffies;
    if ( hif_rtpm_restore_autosuspend_delay___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(61, 4, "%s: RTPM delay already default: %d", "hif_rtpm_restore_autosuspend_delay", v0);
      hif_rtpm_restore_autosuspend_delay___last_ticks = v2;
    }
    return 6;
  }
  else
  {
    pm_runtime_set_autosuspend_delay(*(_QWORD *)(gp_hif_rtpm_ctx + 8), v1);
    v4 = *(_DWORD *)(gp_hif_rtpm_ctx + 312);
    *(_DWORD *)(gp_hif_rtpm_ctx + 316) = v4;
    v5 = jiffies;
    if ( hif_rtpm_restore_autosuspend_delay___last_ticks_49 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(61, 4, "%s: RTPM delay set: %d ms", "hif_rtpm_restore_autosuspend_delay", v4);
      hif_rtpm_restore_autosuspend_delay___last_ticks_49 = v5;
      return 0;
    }
    else
    {
      return 0;
    }
  }
}
