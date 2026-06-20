__int64 __fastcall sched_ravg_window_handler(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int16 v9; // w9
  unsigned int v10; // w19
  _QWORD v12[2]; // [xsp+8h] [xbp-48h] BYREF
  int v13; // [xsp+18h] [xbp-38h]
  __int16 v14; // [xsp+1Ch] [xbp-34h]
  __int16 v15; // [xsp+1Eh] [xbp-32h]
  __int64 v16; // [xsp+20h] [xbp-30h]
  __int64 v17; // [xsp+28h] [xbp-28h]
  __int64 v18; // [xsp+30h] [xbp-20h]
  __int64 v19; // [xsp+38h] [xbp-18h]
  int v20; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+48h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_WORD *)(a1 + 20);
  v12[1] = &v20;
  v15 = 0;
  v20 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v12[0] = 0;
  v13 = 4;
  v14 = v9;
  mutex_lock(&sched_ravg_window_handler_mutex);
  v20 = sysctl_sched_ravg_window_nr_ticks;
  v10 = proc_dointvec(v12, a2, a3, a4, a5);
  if ( a2 && !v10 )
  {
    if ( v20 != sysctl_sched_ravg_window_nr_ticks )
    {
      if ( (unsigned int)(v20 - 2) >= 4 && v20 != 8 )
      {
        v10 = -22;
        goto LABEL_8;
      }
      sysctl_sched_ravg_window_nr_ticks = v20;
      sched_window_nr_ticks_change();
    }
    v10 = 0;
  }
LABEL_8:
  mutex_unlock(&sched_ravg_window_handler_mutex);
  _ReadStatusReg(SP_EL0);
  return v10;
}
