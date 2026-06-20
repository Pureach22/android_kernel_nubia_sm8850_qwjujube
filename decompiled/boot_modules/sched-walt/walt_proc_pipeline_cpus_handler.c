__int64 __fastcall walt_proc_pipeline_cpus_handler(_QWORD *a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x10
  int v13; // w24
  unsigned int v14; // w19
  _QWORD v16[8]; // [xsp+0h] [xbp-40h] BYREF

  v16[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[4];
  v10 = a1[5];
  v16[6] = a1[6];
  v16[4] = v9;
  v16[5] = v10;
  v11 = a1[1];
  v16[0] = *a1;
  v16[1] = v11;
  v12 = a1[3];
  v16[2] = a1[2];
  v16[3] = v12;
  mutex_lock(&walt_proc_pipeline_cpus_handler_mutex);
  v13 = sysctl_sched_pipeline_cpus;
  v14 = proc_dointvec_minmax(v16, a2, a3, a4, a5);
  if ( a2 && !v14 && v13 != sysctl_sched_pipeline_cpus )
  {
    if ( walt_proc_pipeline_cpus_handler_written_once == 1 )
    {
      sysctl_sched_pipeline_cpus = v13;
    }
    else
    {
      sysctl_bitmap = (unsigned int)sysctl_sched_pipeline_cpus;
      cpus_for_pipeline = (unsigned int)sysctl_sched_pipeline_cpus;
      walt_proc_pipeline_cpus_handler_written_once = 1;
    }
  }
  mutex_unlock(&walt_proc_pipeline_cpus_handler_mutex);
  _ReadStatusReg(SP_EL0);
  return v14;
}
