void __fastcall android_rvh_show_max_freq(__int64 a1, __int64 a2, _DWORD *a3)
{
  if ( cpuinfo_max_freq_cached
    && (((unsigned __int64)(unsigned int)sched_lib_mask_force >> *(_DWORD *)(a2 + 28)) & 1) != 0
    && ((is_sched_lib_based_app(*(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800)) & 1) != 0
     || (is_sched_lib_task() & 1) != 0) )
  {
    *a3 = 2 * cpuinfo_max_freq_cached;
  }
}
