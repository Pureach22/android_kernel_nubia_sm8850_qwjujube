__int64 __fastcall walt_get_mvp_task_prio(__int64 a1, __int64 a2)
{
  _BYTE *v2; // x19
  __int64 v4; // x21
  unsigned __int64 v5; // x8

  if ( (_UNKNOWN *)a1 == &init_task )
    v2 = &vendor_data_pad;
  else
    v2 = (_BYTE *)(a1 + 5184);
  if ( (v2[191] & 0xC) != 0 )
    return 4;
  if ( (v2[191] & 1) != 0 && sysctl_walt_low_latency_task_threshold > (unsigned int)*((unsigned __int16 *)v2 + 79) )
    return 3;
  if ( *((_QWORD *)v2 + 24) )
  {
    v4 = a1;
    v5 = walt_sched_clock(a1, a2);
    a1 = v4;
    if ( v5 > *((_QWORD *)v2 + 25) )
    {
      *((_DWORD *)v2 + 46) = 0;
      *((_QWORD *)v2 + 24) = 0;
      *((_QWORD *)v2 + 25) = 0;
    }
  }
  if ( *((_DWORD *)v2 + 46) == 3 )
    return 2;
  if ( (v2[191] & 2) != 0 && sysctl_walt_low_latency_task_threshold > (unsigned int)*((unsigned __int16 *)v2 + 79) )
    return 1;
  if ( *((_QWORD *)v2 + 30) )
    return (unsigned int)(*(_DWORD *)(a1 + 148) <= (unsigned int)sysctl_walt_rtg_cfs_boost_prio) - 1;
  return 0xFFFFFFFFLL;
}
