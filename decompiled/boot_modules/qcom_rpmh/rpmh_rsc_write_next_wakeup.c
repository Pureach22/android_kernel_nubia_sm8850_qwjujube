__int64 __fastcall rpmh_rsc_write_next_wakeup(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 v2; // x0
  __int64 next_hrtimer; // x20
  unsigned __int64 v4; // x20
  __int64 (*v5)(void); // x8
  __int64 v6; // x20

  if ( *(_DWORD *)(result + 332) )
  {
    v1 = result;
    if ( *(_QWORD *)(result + 88) )
    {
      if ( system_state == 7 )
      {
        v2 = -1;
      }
      else
      {
        next_hrtimer = dev_pm_genpd_get_next_hrtimer(*(_QWORD *)(result + 1648));
        v4 = 1073750 * loops_per_jiffy * ((next_hrtimer - ktime_get()) / 1000);
        v5 = (__int64 (*)(void))arch_timer_read_counter;
        if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
          __break(0x8228u);
        v2 = v5() + HIDWORD(v4);
      }
      v6 = HIDWORD(v2) & 0xFFFFFF;
      writel_relaxed(v2, *(_QWORD *)(v1 + 24) + 64LL);
      return writel_relaxed((unsigned int)v6 | 0x80000000, *(_QWORD *)(v1 + 24) + 56LL);
    }
  }
  return result;
}
