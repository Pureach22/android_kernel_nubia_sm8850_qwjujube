bool __fastcall walt_can_migrate_task(__int64 a1, __int64 a2, char a3, char a4, char a5)
{
  __int64 v5; // x8
  _BYTE *v6; // x19
  int *v8; // x20
  unsigned int v9; // w22
  __int64 v10; // x21
  char v11; // w23
  unsigned __int64 v12; // x8
  __int64 v13; // x20
  unsigned int v14; // w21
  __int64 lock; // x0
  __int64 v16; // x8
  char v17; // w19
  int v18; // w19
  char v19; // w0
  int v20; // w19
  char v21; // w0

  v5 = *(unsigned int *)(a1 + 40);
  if ( (unsigned int)v5 >= 0x20 )
  {
    __break(0x5512u);
    JUMPOUT(0x4CCDC);
  }
  if ( (_UNKNOWN *)a1 == &init_task )
    v6 = &vendor_data_pad;
  else
    v6 = (_BYTE *)(a1 + 5184);
  if ( *(_BYTE *)(a1 + 273) )
    return 0;
  v8 = (int *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v5)];
  if ( *(_QWORD *)v8 == a1 )
    return 0;
  if ( !sched_boost_type
    && (pipeline_nr || sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres && have_heavy_list)
    && (v6[191] & 0xC) != 0 )
  {
    return 0;
  }
  if ( (a3 & 1) != 0 )
  {
    if ( v6[272] == 1 && *((unsigned __int16 *)v6 + 79) < 0x28Au )
      return 0;
    if ( *((_QWORD *)v6 + 24) )
    {
      v9 = a2;
      v10 = a1;
      v11 = a5;
      v12 = walt_sched_clock(a1, a2);
      a5 = v11;
      a2 = v9;
      a1 = v10;
      if ( v12 > *((_QWORD *)v6 + 25) )
      {
        *((_DWORD *)v6 + 46) = 0;
        *((_QWORD *)v6 + 24) = 0;
        *((_QWORD *)v6 + 25) = 0;
      }
    }
    if ( *((_DWORD *)v6 + 46) == 3 && *((_QWORD *)v6 + 30) )
      return 0;
    if ( (a5 & 1) != 0 )
      return ((*(unsigned __int64 *)((char *)_cpu_halt_mask + (((unsigned __int64)(unsigned int)a2 >> 3) & 0x1FFFFFF8)) >> a2)
            & 1) == 0;
    if ( (soc_flags & 0x80) != 0 )
    {
      v13 = a1;
      v14 = a2;
      lock = _rcu_read_lock(a1);
      v16 = *((_QWORD *)v6 + 30);
      if ( v16 )
      {
        v17 = *(_BYTE *)(v16 + 40);
        _rcu_read_unlock(lock);
        a2 = v14;
        a1 = v13;
        if ( (v17 & 1) != 0 )
          return 0;
      }
      else
      {
        _rcu_read_unlock(lock);
        a2 = v14;
        a1 = v13;
      }
    }
    v20 = a2;
    v21 = task_fits_max_0((char *)a1, a2);
    LODWORD(a2) = v20;
    if ( (v21 & 1) != 0 )
      return ((*(unsigned __int64 *)((char *)_cpu_halt_mask + (((unsigned __int64)(unsigned int)a2 >> 3) & 0x1FFFFFF8)) >> a2)
            & 1) == 0;
  }
  else
  {
    if ( (a4 & 1) != 0 )
      return ((*(unsigned __int64 *)((char *)_cpu_halt_mask + (((unsigned __int64)(unsigned int)a2 >> 3) & 0x1FFFFFF8)) >> a2)
            & 1) == 0;
    v18 = a2;
    v19 = task_fits_max_0((char *)a1, a2);
    LODWORD(a2) = v18;
    if ( (v19 & 1) != 0 || v8[6] >= 2 )
      return ((*(unsigned __int64 *)((char *)_cpu_halt_mask + (((unsigned __int64)(unsigned int)a2 >> 3) & 0x1FFFFFF8)) >> a2)
            & 1) == 0;
  }
  return 0;
}
