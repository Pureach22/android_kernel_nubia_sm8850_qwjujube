__int64 __fastcall thermal_pause_set_cur_state(__int64 a1, unsigned __int64 a2)
{
  __int64 v3; // x21
  int v4; // w19
  __int64 v5; // x1

  if ( a2 > 1 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 944);
  v4 = a2;
  mutex_lock(&cpus_pause_lock);
  v5 = system_highpri_wq;
  *(_DWORD *)(v3 + 28) = v4;
  queue_work_on(32, v5, v3 + 104);
  mutex_unlock(&cpus_pause_lock);
  return 0;
}
