__int64 __fastcall android_rvh_get_nohz_timer_target(__int64 a1, int *a2, _BYTE *a3)
{
  char *v3; // x21
  unsigned __int64 v5; // x20
  int v6; // w24
  int v7; // w23
  __int64 result; // x0
  _QWORD *lock; // x0
  __int64 v10; // x8
  __int64 **i; // x24
  char v12; // w26
  unsigned __int64 v13; // x21
  int v14; // w9
  __int64 v15; // x21
  char v16; // w21
  unsigned __int64 v17; // x22
  char v18; // w9
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x25
  int v21; // w8
  __int64 v22; // [xsp+8h] [xbp-18h] BYREF
  __int64 v23; // [xsp+10h] [xbp-10h] BYREF
  __int64 v24; // [xsp+18h] [xbp-8h] BYREF

  v3 = "n";
  *a3 = 1;
  LODWORD(v5) = _cpu_active_mask;
  v6 = _cpu_halt_mask;
  while ( 1 )
  {
    if ( ((*(unsigned __int64 *)((char *)&_cpu_halt_mask + (((unsigned __int64)(unsigned int)*a2 >> 3) & 0x1FFFFFF8)) >> *a2)
        & 1) != 0 )
    {
LABEL_3:
      v7 = -1;
      goto LABEL_6;
    }
    result = ((__int64 (*)(void))available_idle_cpu)();
    if ( !(_DWORD)result )
      return result;
    v7 = *a2;
LABEL_6:
    v5 = (unsigned int)v5 & ~v6;
    result = _sw_hweight64(v5);
    if ( !(_DWORD)result )
    {
      v14 = *((_DWORD *)v3 + 818);
      v15 = (unsigned int)cpus_paused_by_us & v14;
      v24 = v15;
      v22 = v14 & (unsigned int)_cpu_halt_mask;
      v23 = (unsigned int)cpus_part_paused_by_us & v14;
      result = _sw_hweight64(v23);
      if ( (_DWORD)result )
      {
        v3 = (char *)&v23;
      }
      else
      {
        result = _sw_hweight64(v15);
        if ( (_DWORD)result )
          v3 = (char *)&v24;
        else
          v3 = (char *)&v22;
      }
      v18 = 0;
      v6 = -1;
      do
      {
        v19 = (unsigned int)(-1LL << v18) & (unsigned int)*(_QWORD *)v3;
        if ( !(_DWORD)v19 )
          break;
        v20 = __clz(__rbit64(v19));
        if ( *a2 != (_DWORD)v20 || (result = _sw_hweight64((unsigned int)*(_QWORD *)v3), (result & 0xFFFFFFFE) == 0) )
        {
          *a2 = v20;
          return result;
        }
        v18 = v20 + 1;
      }
      while ( v20 <= 0x1E );
    }
    lock = (_QWORD *)_rcu_read_lock(result);
    v10 = (unsigned int)*a2;
    if ( (unsigned int)v10 < 0x20 )
      break;
    __break(0x5512u);
    if ( (housekeeping_test_cpu(lock, 0) & 1) == 0 )
      goto LABEL_3;
  }
  for ( i = *(__int64 ***)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v10) + 3536); i; i = (__int64 **)*i )
  {
    lock = (_QWORD *)housekeeping_cpumask(0);
    v12 = 0;
    do
    {
      if ( ((unsigned int)(-1LL << v12) & (_DWORD)i[38] & *lock) == 0 )
        break;
      v13 = __clz(__rbit64((unsigned int)(-1LL << v12) & (_DWORD)i[38] & *lock));
      if ( *a2 != (_DWORD)v13 )
      {
        lock = (_QWORD *)available_idle_cpu((unsigned int)v13);
        if ( !(_DWORD)lock && (((unsigned __int64)_cpu_halt_mask >> v13) & 1) == 0 )
          goto LABEL_41;
      }
      v12 = v13 + 1;
      lock = (_QWORD *)housekeeping_cpumask(0);
    }
    while ( v13 < 0x1F );
  }
  LODWORD(v13) = v7;
  if ( v7 != -1 )
    goto LABEL_41;
  lock = (_QWORD *)housekeeping_cpumask(0);
  v16 = 0;
  do
  {
    if ( ((unsigned int)(-1LL << v16) & *(_DWORD *)lock & (unsigned int)v5) == 0 )
      break;
    v17 = __clz(__rbit64((unsigned int)(-1LL << v16) & *(_DWORD *)lock & (unsigned int)v5));
    if ( *a2 != (_DWORD)v17 )
    {
      lock = (_QWORD *)available_idle_cpu((unsigned int)v17);
      LODWORD(v13) = v17;
      if ( !(_DWORD)lock )
        goto LABEL_41;
    }
    v16 = v17 + 1;
    lock = (_QWORD *)housekeeping_cpumask(0);
  }
  while ( v17 < 0x1F );
  v21 = __clz(__rbit64(v5));
  LODWORD(v13) = v5 ? v21 : 32;
  if ( (unsigned int)v13 < nr_cpu_ids )
LABEL_41:
    *a2 = v13;
  return _rcu_read_unlock(lock);
}
