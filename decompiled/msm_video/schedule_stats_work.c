__int64 __fastcall schedule_stats_work(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x8
  __int64 v7; // x19
  __int64 v9; // x0

  if ( a1 && (v5 = a1[40]) != 0 )
  {
    if ( (msm_vidc_debug & 0x40) != 0 )
    {
      if ( a1[46] )
      {
        v7 = a1[496];
        v9 = _msecs_to_jiffies(*(unsigned int *)(v5 + 4512));
        mod_delayed_work_on(32, v7, a1 + 477, v9);
      }
      else if ( (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_8A6EC, "err ", (char *)a1 + 340, a4, a5);
      }
    }
    else if ( (msm_vidc_debug & 2) != 0 )
    {
      printk(&unk_97971, "high", (char *)a1 + 340, "schedule_stats_work", a5);
    }
    return 0;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "schedule_stats_work");
    return 4294967274LL;
  }
}
