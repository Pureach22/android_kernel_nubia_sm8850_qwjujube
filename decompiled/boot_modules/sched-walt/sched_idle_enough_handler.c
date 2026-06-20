__int64 __fastcall sched_idle_enough_handler(_QWORD *a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x10
  unsigned int v13; // w19
  _QWORD v15[8]; // [xsp+0h] [xbp-40h] BYREF

  v15[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[4];
  v10 = a1[5];
  v15[6] = a1[6];
  v15[4] = v9;
  v15[5] = v10;
  v11 = a1[1];
  v15[0] = *a1;
  v15[1] = v11;
  v12 = a1[3];
  v15[2] = a1[2];
  v15[3] = v12;
  mutex_lock(&idle_enough_mutex);
  v13 = proc_douintvec_minmax(v15, a2, a3, a4, a5);
  if ( !v13 )
  {
    sysctl_sched_idle_enough_clust = sysctl_sched_idle_enough;
    dword_6853C = sysctl_sched_idle_enough;
    dword_68540 = sysctl_sched_idle_enough;
    dword_68544 = sysctl_sched_idle_enough;
  }
  mutex_unlock(&idle_enough_mutex);
  _ReadStatusReg(SP_EL0);
  return v13;
}
