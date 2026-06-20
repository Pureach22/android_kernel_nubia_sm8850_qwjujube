__int64 __fastcall replicator_online_cpu(unsigned int a1)
{
  __int64 v1; // x23
  _UNKNOWN ***v2; // x22
  __int64 v3; // x27
  unsigned __int64 v6; // x9
  _UNKNOWN **v7; // x28
  unsigned __int64 v14; // x9
  _QWORD *v15; // x21
  unsigned __int64 v16; // x26
  __int64 v17; // x27
  _UNKNOWN **v18; // x28
  __int64 v19; // x24
  _QWORD *v20; // x8
  _UNKNOWN **v21; // x9
  __int64 v22; // x22
  __int64 result; // x0
  void *v24; // x2
  _UNKNOWN **v25; // x0
  unsigned __int64 v28; // x9
  unsigned __int64 v31; // x9
  unsigned int v32; // w8
  unsigned int v35; // w10
  __int64 v37; // [xsp+8h] [xbp-8h]

  v1 = a1 >> 6;
  v2 = (_UNKNOWN ***)cpu_pm_list;
  if ( cpu_pm_list != (_UNKNOWN *)&cpu_pm_list )
  {
    v3 = 1LL << a1;
    do
    {
      v7 = *v2;
      if ( ((unsigned __int64)(*(v2 - 5))[(unsigned __int64)a1 >> 6] & (1LL << a1)) != 0 )
      {
        raw_spin_lock_irqsave(v2 - 8);
        _X8 = (unsigned __int64 *)&v2[v1 - 6];
        __asm { PRFM            #0x11, [X8] }
        do
          v14 = __ldxr(_X8);
        while ( __stxr(v14 | v3, _X8) );
        _X8 = (unsigned __int64 *)&v2[v1 - 4];
        __asm { PRFM            #0x11, [X8] }
        do
          v6 = __ldxr(_X8);
        while ( __stxr(v6 | v3, _X8) );
        *((_BYTE *)v2 - 8) = 1;
        raw_spin_unlock_irqrestore(v2 - 8);
      }
      v2 = (_UNKNOWN ***)v7;
    }
    while ( v7 != &cpu_pm_list );
  }
  v15 = delay_probe_list;
  if ( delay_probe_list == (_UNKNOWN *)&delay_probe_list )
    return 0;
  v16 = (unsigned __int64)a1 >> 6;
  v17 = 1LL << a1;
  v37 = 1LL << a1;
  while ( 1 )
  {
    v18 = (_UNKNOWN **)*v15;
    if ( (*(_QWORD *)(*(v15 - 1) + 8 * v16) & v17) != 0 )
      break;
LABEL_13:
    v15 = v18;
    if ( v18 == &delay_probe_list )
      return 0;
  }
  v19 = *(_QWORD *)(*(v15 - 2) + 152LL);
  raw_spin_lock(&delay_lock);
  *(_QWORD *)(v19 + 40) = 0;
  v20 = (_QWORD *)v15[1];
  if ( (_QWORD *)*v20 == v15 && (v21 = (_UNKNOWN **)*v15, *(_QWORD **)(*v15 + 8LL) == v15) )
  {
    v21[1] = v20;
    *v20 = v21;
  }
  else
  {
    _list_del_entry_valid_or_report(v15);
  }
  *v15 = 0xDEAD000000000100LL;
  v15[1] = 0xDEAD000000000122LL;
  raw_spin_unlock(&delay_lock);
  v22 = *(v15 - 2);
  result = _pm_runtime_resume(v22, 4);
  if ( (result & 0x80000000) == 0 )
  {
    if ( (unsigned int)replicator_add_coresight_dev(*(v15 - 2), *(v15 - 2) + 912LL) )
    {
      _pm_runtime_idle(*(v15 - 2), 4);
    }
    else
    {
      *(_QWORD *)(v19 + 56) = *(v15 - 1);
      _X8 = (unsigned __int64 *)(v19 + 48 + 8 * v1);
      __asm { PRFM            #0x11, [X8] }
      do
        v28 = __ldxr(_X8);
      while ( __stxr(v28 | v37, _X8) );
      _X8 = (unsigned __int64 *)(v19 + 64 + 8 * v1);
      __asm { PRFM            #0x11, [X8] }
      do
        v31 = __ldxr(_X8);
      while ( __stxr(v31 | v37, _X8) );
      *(_BYTE *)(v19 + 89) = 1;
      raw_spin_lock(&delay_lock);
      v24 = cpu_pm_list;
      v25 = (_UNKNOWN **)(v19 + 96);
      if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)cpu_pm_list) != &cpu_pm_list
        || v25 == &cpu_pm_list
        || cpu_pm_list == (_UNKNOWN *)v25 )
      {
        _list_add_valid_or_report(v25, &cpu_pm_list);
      }
      else
      {
        *(_QWORD *)((char *)&unk_8 + (_QWORD)cpu_pm_list) = v25;
        *(_QWORD *)(v19 + 96) = v24;
        *(_QWORD *)(v19 + 104) = &cpu_pm_list;
        cpu_pm_list = (_UNKNOWN *)(v19 + 96);
      }
      raw_spin_unlock(&delay_lock);
    }
    goto LABEL_13;
  }
  v32 = *(_DWORD *)(v22 + 480);
  do
  {
    if ( !v32 )
      break;
    _X12 = (unsigned int *)(v22 + 480);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v35 = __ldxr(_X12);
      if ( v35 != v32 )
        break;
      if ( !__stlxr(v32 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v35 == v32;
    v32 = v35;
  }
  while ( !_ZF );
  return result;
}
