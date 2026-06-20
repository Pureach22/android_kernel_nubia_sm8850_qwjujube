__int64 __fastcall hif_system_pm_state_check(__int64 a1)
{
  __int64 v1; // x0

  if ( a1 )
  {
    if ( (*(_DWORD *)(a1 + 4008) & 0xFFFFFFFE) == 2 )
    {
      v1 = qdf_trace_msg(61, 5, "%s: Triggering system wakeup", "hif_system_pm_state_check");
      qdf_pm_system_wakeup(v1);
      return 4294967285LL;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(61, 2, "%s: hif context is null", "hif_system_pm_state_check");
    return 4294967282LL;
  }
}
