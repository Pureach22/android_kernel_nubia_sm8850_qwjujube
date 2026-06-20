__int64 __fastcall msm_vidc_schedule_core_deinit(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0

  if ( *(_QWORD *)(result + 4320) )
  {
    v1 = result;
    cancel_delayed_work(result + 6232);
    v2 = _msecs_to_jiffies(*(unsigned int *)(v1 + 4336));
    result = queue_delayed_work_on(32, system_wq, v1 + 6232, v2);
    if ( (msm_vidc_debug & 2) != 0 )
      return printk(&unk_97A63, "high", 0xFFFFFFFFLL, "codec", *(_QWORD *)(v1 + 4336));
  }
  return result;
}
