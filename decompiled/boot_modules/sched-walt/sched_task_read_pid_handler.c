__int64 __fastcall sched_task_read_pid_handler(_QWORD *a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x10
  _QWORD v14[8]; // [xsp+0h] [xbp-40h] BYREF

  v14[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[4];
  v10 = a1[5];
  v14[6] = a1[6];
  v14[4] = v9;
  v14[5] = v10;
  v11 = a1[1];
  v14[0] = *a1;
  v14[1] = v11;
  v12 = a1[3];
  v14[2] = a1[2];
  v14[3] = v12;
  mutex_lock(&sysctl_pid_mutex);
  LODWORD(a5) = proc_dointvec_minmax(v14, a2, a3, a4, a5);
  mutex_unlock(&sysctl_pid_mutex);
  _ReadStatusReg(SP_EL0);
  return (unsigned int)a5;
}
