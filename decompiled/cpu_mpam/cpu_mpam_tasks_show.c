__int64 __fastcall cpu_mpam_tasks_show(__int64 a1, __int64 a2)
{
  int v2; // w22
  __int64 lock; // x0
  _QWORD *v5; // x24
  __int64 v6; // x21
  __int64 v7; // x8
  _QWORD *v8; // x9
  _QWORD *v9; // x27
  unsigned __int8 *v10; // x9

  v2 = *(_DWORD *)(a1 + 136);
  lock = _rcu_read_lock();
  v5 = (_QWORD *)init_task[199];
  if ( v5 - 199 == init_task )
  {
    v6 = 0;
  }
  else
  {
    v6 = 0;
    do
    {
      v7 = v5[100];
      v8 = (_QWORD *)(v7 + 16);
      v9 = *(_QWORD **)(v7 + 16);
      while ( v9 != v8 )
      {
        if ( v9 - 247 == init_task )
          v10 = (unsigned __int8 *)&vendor_data_pad;
        else
          v10 = (unsigned __int8 *)(v9 + 401);
        if ( v2 == v10[385] )
        {
          lock = scnprintf(a2 + v6, 4096 - v6, "%d ", *((_DWORD *)v9 - 44));
          v7 = v5[100];
          v6 += (int)lock;
        }
        v9 = (_QWORD *)*v9;
        v8 = (_QWORD *)(v7 + 16);
      }
      v5 = (_QWORD *)*v5;
    }
    while ( v5 - 199 != init_task );
  }
  _rcu_read_unlock(lock);
  return v6 + (int)scnprintf(a2 + v6, 4096 - v6, "\n");
}
