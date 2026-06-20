__int64 __fastcall walt_proc_group_thresholds_handler(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int *v5; // x25
  __int64 v6; // x24
  unsigned __int16 v7; // w8
  unsigned int v13; // w19
  bool v14; // zf
  __int64 v15; // x19
  _QWORD v17[2]; // [xsp+8h] [xbp-48h] BYREF
  int v18; // [xsp+18h] [xbp-38h]
  __int64 v19; // [xsp+1Ch] [xbp-34h]
  int v20; // [xsp+24h] [xbp-2Ch]
  __int64 v21; // [xsp+28h] [xbp-28h]
  __int64 v22; // [xsp+30h] [xbp-20h]
  __int64 v23; // [xsp+38h] [xbp-18h]
  unsigned int v24; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+48h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !_cpu_possible_mask )
    __break(0x5512u);
  v17[0] = 0;
  v17[1] = &v24;
  v5 = *(int **)(a1 + 8);
  v6 = *((_QWORD *)&_per_cpu_offset + __clz(__rbit64(_cpu_possible_mask)));
  v7 = *(_WORD *)(a1 + 20);
  v24 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 4;
  v19 = v7;
  if ( num_sched_clusters < 1 )
  {
    v13 = -1;
    goto LABEL_19;
  }
  mutex_lock(&walt_proc_group_thresholds_handler_mutex);
  if ( a2 )
  {
    v13 = proc_dointvec(v17, a2, a3, a4, a5);
    if ( !v13 )
    {
      if ( v5 == &sysctl_sched_group_upmigrate_pct )
      {
        if ( (v24 & 0x80000000) != 0 )
        {
          v13 = -22;
          goto LABEL_18;
        }
        v13 = -22;
        if ( sysctl_sched_group_downmigrate_pct )
          v14 = v24 == 0;
        else
          v14 = 0;
        if ( v14 || v24 - 1 < sysctl_sched_group_downmigrate_pct )
          goto LABEL_18;
      }
      else
      {
        v13 = -22;
        if ( (v24 & 0x80000000) != 0 || v24 >= sysctl_sched_group_upmigrate_pct )
          goto LABEL_18;
      }
      *v5 = v24;
      v15 = raw_spin_lock_irqsave((char *)&runqueues + v6);
      ((void (*)(void))walt_update_group_thresholds)();
      raw_spin_unlock_irqrestore((char *)&runqueues + v6, v15);
      v13 = 0;
    }
  }
  else
  {
    v13 = proc_dointvec(a1, 0, a3, a4, a5);
  }
LABEL_18:
  mutex_unlock(&walt_proc_group_thresholds_handler_mutex);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v13;
}
