__int64 __fastcall tmc_probe(__int64 *a1)
{
  __int64 v2; // x0
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x4
  __int64 v6; // x5
  __int64 v7; // x8
  __int64 v8; // x21
  _DWORD *v9; // x22
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  char v14; // w10
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x10
  bool v17; // cc
  __int64 v18; // x0
  _QWORD *v19; // x20
  void *v20; // x2
  void *v21; // x0
  __int64 v22; // x0
  __int64 v24; // x0
  unsigned int v25; // w19
  __int64 v26; // x8
  void *v27; // x0
  void *v28; // x2

  v2 = devm_kmalloc(a1, 432, 3520);
  if ( !v2 )
    return 4294967284LL;
  v7 = a1[74];
  a1[19] = v2;
  if ( !v7 || !*(_DWORD *)(v7 + 416) )
    return tmc_add_coresight_dev(a1, (__int64)(a1 + 114), v3, v4, v5, v6);
  v8 = v2;
  v9 = (_DWORD *)(v7 + 416);
  cpus_read_lock();
  v14 = 0;
  do
  {
    v15 = (unsigned int)(-1LL << v14) & _cpu_online_mask;
    if ( !(_DWORD)v15 )
      break;
    v16 = __clz(__rbit64(v15));
    if ( ((*(_QWORD *)v9 >> v16) & 1) != 0 )
    {
      v24 = tmc_add_coresight_dev(a1, (__int64)(a1 + 114), v10, v11, v12, v13);
      v25 = v24;
      if ( !(_DWORD)v24 )
      {
        *(_QWORD *)(v8 + 376) = v9;
        v26 = (unsigned int)(*v9 & _cpu_online_mask);
        *(_QWORD *)(v8 + 368) = v26;
        *(_QWORD *)(v8 + 384) = v26;
        *(_BYTE *)(v8 + 409) = 1;
        raw_spin_lock(&delay_lock);
        v27 = (void *)(v8 + 416);
        v28 = cpu_pm_list;
        if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)cpu_pm_list) != &cpu_pm_list || cpu_pm_list == v27 )
        {
          _list_add_valid_or_report(v27, &cpu_pm_list);
        }
        else
        {
          *(_QWORD *)((char *)&unk_8 + (_QWORD)cpu_pm_list) = v27;
          *(_QWORD *)(v8 + 416) = v28;
          *(_QWORD *)(v8 + 424) = &cpu_pm_list;
          cpu_pm_list = (_UNKNOWN *)(v8 + 416);
        }
        v24 = raw_spin_unlock(&delay_lock);
      }
      cpus_read_unlock(v24);
      return v25;
    }
    v17 = v16 > 0x1E;
    v14 = v16 + 1;
  }
  while ( !v17 );
  v18 = devm_kmalloc(a1, 40, 3520);
  if ( !v18 )
  {
    cpus_read_unlock(0);
    return 4294967284LL;
  }
  v19 = (_QWORD *)v18;
  raw_spin_lock(&delay_lock);
  *v19 = a1;
  v19[1] = v9;
  v20 = delay_probe_list;
  v21 = v19 + 2;
  if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)delay_probe_list) != &delay_probe_list || delay_probe_list == v21 )
  {
    _list_add_valid_or_report(v21, &delay_probe_list);
  }
  else
  {
    *(_QWORD *)((char *)&unk_8 + (_QWORD)delay_probe_list) = v21;
    v19[2] = v20;
    v19[3] = &delay_probe_list;
    delay_probe_list = v19 + 2;
  }
  *(_QWORD *)(v8 + 352) = v19;
  v22 = raw_spin_unlock(&delay_lock);
  cpus_read_unlock(v22);
  _pm_runtime_idle(a1, 4);
  return 0;
}
