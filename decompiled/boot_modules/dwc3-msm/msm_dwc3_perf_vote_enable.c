__int64 __fastcall msm_dwc3_perf_vote_enable(__int64 a1, char a2)
{
  __int64 result; // x0
  int v5; // w8

  result = irq_to_desc(*(unsigned int *)(a1 + 556));
  if ( (*(_BYTE *)(a1 + 2804) & 1) == 0 && result )
  {
    if ( (a2 & 1) != 0 )
    {
      v5 = *(_DWORD *)(result + 144);
      *(_BYTE *)(a1 + 744) = 0;
      *(_DWORD *)(a1 + 560) = v5;
      cpu_latency_qos_add_request(a1 + 880, 0xFFFFFFFFLL);
      return queue_delayed_work_on(32, system_wq, a1 + 928, 25);
    }
    else
    {
      cancel_delayed_work_sync(a1 + 928);
      if ( *(_BYTE *)(a1 + 744) )
      {
        if ( *(_DWORD *)(a1 + 872) )
        {
          cpu_latency_qos_update_request(a1 + 880, 0xFFFFFFFFLL);
          *(_BYTE *)(a1 + 744) = 0;
        }
      }
      return cpu_latency_qos_remove_request(a1 + 880);
    }
  }
  return result;
}
