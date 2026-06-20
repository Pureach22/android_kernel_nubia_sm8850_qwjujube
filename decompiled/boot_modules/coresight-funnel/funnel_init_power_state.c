__int64 __fastcall funnel_init_power_state(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  _QWORD *v4; // x20
  char v5; // w10
  unsigned int v6; // w8
  unsigned __int64 v7; // x10
  unsigned __int64 v8; // x10
  bool v9; // cc
  __int64 v10; // x8
  _UNKNOWN **v11; // x0
  void *v12; // x2
  __int64 v13; // x0

  v2 = *(_QWORD *)(result + 592);
  if ( v2 && *(_DWORD *)(v2 + 416) )
  {
    v4 = (_QWORD *)(v2 + 416);
    cpus_read_lock();
    v5 = 0;
    v6 = _cpu_online_mask;
    do
    {
      v7 = (unsigned int)(-1LL << v5) & _cpu_online_mask;
      if ( !(_DWORD)v7 )
        break;
      v8 = __clz(__rbit64(v7));
      if ( ((*v4 >> v8) & 1) != 0 )
      {
        *(_BYTE *)(a2 + 88) = 1;
        break;
      }
      v9 = v8 > 0x1E;
      v5 = v8 + 1;
    }
    while ( !v9 );
    *(_QWORD *)(a2 + 56) = v4;
    v10 = *(_DWORD *)v4 & v6;
    *(_QWORD *)(a2 + 48) = v10;
    *(_QWORD *)(a2 + 64) = v10;
    raw_spin_lock(&delay_lock);
    v11 = (_UNKNOWN **)(a2 + 96);
    v12 = cpu_pm_list;
    if ( cpu_pm_list == (_UNKNOWN *)(a2 + 96)
      || v11 == &cpu_pm_list
      || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)cpu_pm_list) != &cpu_pm_list )
    {
      _list_add_valid_or_report();
    }
    else
    {
      *(_QWORD *)((char *)&unk_8 + (_QWORD)cpu_pm_list) = v11;
      *(_QWORD *)(a2 + 96) = v12;
      *(_QWORD *)(a2 + 104) = &cpu_pm_list;
      cpu_pm_list = (_UNKNOWN *)(a2 + 96);
    }
    v13 = raw_spin_unlock(&delay_lock);
    return cpus_read_unlock(v13);
  }
  else
  {
    *(_BYTE *)(a2 + 88) = 1;
  }
  return result;
}
