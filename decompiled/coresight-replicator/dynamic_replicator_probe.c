__int64 __fastcall dynamic_replicator_probe(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x21
  _DWORD *v5; // x22
  char v6; // w10
  unsigned __int64 v7; // x10
  unsigned __int64 v8; // x10
  bool v9; // cc
  __int64 v10; // x0
  _QWORD *v11; // x20
  void *v12; // x2
  void *v13; // x0
  __int64 v14; // x0
  __int64 v16; // x0
  unsigned int v17; // w19
  __int64 v18; // x8
  void *v19; // x0
  void *v20; // x2

  v2 = devm_kmalloc(a1, 112, 3520);
  if ( !v2 )
    return 4294967284LL;
  v3 = a1[74];
  a1[19] = v2;
  if ( !v3 || !*(_DWORD *)(v3 + 416) )
    return replicator_add_coresight_dev(a1, (unsigned __int64)(a1 + 114));
  v4 = v2;
  v5 = (_DWORD *)(v3 + 416);
  cpus_read_lock();
  v6 = 0;
  do
  {
    v7 = (unsigned int)(-1LL << v6) & _cpu_online_mask;
    if ( !(_DWORD)v7 )
      break;
    v8 = __clz(__rbit64(v7));
    if ( ((*(_QWORD *)v5 >> v8) & 1) != 0 )
    {
      v16 = replicator_add_coresight_dev(a1, (unsigned __int64)(a1 + 114));
      v17 = v16;
      if ( !(_DWORD)v16 )
      {
        *(_QWORD *)(v4 + 56) = v5;
        v18 = (unsigned int)(*v5 & _cpu_online_mask);
        *(_QWORD *)(v4 + 48) = v18;
        *(_QWORD *)(v4 + 64) = v18;
        *(_BYTE *)(v4 + 89) = 1;
        raw_spin_lock(&delay_lock);
        v19 = (void *)(v4 + 96);
        v20 = cpu_pm_list;
        if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)cpu_pm_list) != &cpu_pm_list || cpu_pm_list == v19 )
        {
          _list_add_valid_or_report(v19, &cpu_pm_list);
        }
        else
        {
          *(_QWORD *)((char *)&unk_8 + (_QWORD)cpu_pm_list) = v19;
          *(_QWORD *)(v4 + 96) = v20;
          *(_QWORD *)(v4 + 104) = &cpu_pm_list;
          cpu_pm_list = (_UNKNOWN *)(v4 + 96);
        }
        v16 = raw_spin_unlock(&delay_lock);
      }
      cpus_read_unlock(v16);
      return v17;
    }
    v9 = v8 > 0x1E;
    v6 = v8 + 1;
  }
  while ( !v9 );
  v10 = devm_kmalloc(a1, 40, 3520);
  if ( !v10 )
  {
    cpus_read_unlock(0);
    return 4294967284LL;
  }
  v11 = (_QWORD *)v10;
  raw_spin_lock(&delay_lock);
  *v11 = a1;
  v11[1] = v5;
  v12 = delay_probe_list;
  v13 = v11 + 2;
  if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)delay_probe_list) != &delay_probe_list || delay_probe_list == v13 )
  {
    _list_add_valid_or_report(v13, &delay_probe_list);
  }
  else
  {
    *(_QWORD *)((char *)&unk_8 + (_QWORD)delay_probe_list) = v13;
    v11[2] = v12;
    v11[3] = &delay_probe_list;
    delay_probe_list = v11 + 2;
  }
  *(_QWORD *)(v4 + 40) = v11;
  raw_spin_unlock(&delay_lock);
  v14 = _pm_runtime_idle(a1, 4);
  cpus_read_unlock(v14);
  return 0;
}
