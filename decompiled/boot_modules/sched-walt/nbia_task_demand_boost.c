__int64 __fastcall nbia_task_demand_boost(__int64 a1, unsigned int a2)
{
  int v3; // w8
  unsigned int v4; // w10
  int v5; // w8
  __int64 v7; // x20

  if ( (walt_disabled & 1) == 0 && sysctl_sched_nbia_dp )
  {
    if ( sched_nbia_debug )
    {
      v7 = a1;
      printk(&unk_61543);
      a1 = v7;
    }
    if ( sysctl_sched_nbia_dp_array[0] && sysctl_sched_nbia_dp_array[0] == *(_DWORD *)(a1 + 1800) )
    {
      v3 = 0;
    }
    else if ( dword_6A5FC && dword_6A5FC == *(_DWORD *)(a1 + 1800) )
    {
      v3 = 3;
    }
    else if ( dword_6A608 && dword_6A608 == *(_DWORD *)(a1 + 1800) )
    {
      v3 = 6;
    }
    else
    {
      if ( !dword_6A614 || dword_6A614 != *(_DWORD *)(a1 + 1800) )
        return a2;
      v3 = 9;
    }
    v4 = sysctl_sched_nbia_dp_array[v3 + 1];
    if ( v4 )
    {
      if ( v4 <= a2 )
      {
        v5 = sysctl_sched_nbia_dp_array[v3 + 2];
        if ( (unsigned int)(v5 - 7) >= 0xFFFFFFFA )
          a2 += a2 >> v5;
      }
    }
  }
  return a2;
}
