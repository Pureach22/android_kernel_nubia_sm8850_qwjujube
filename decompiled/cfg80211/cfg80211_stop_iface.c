__int64 __fastcall cfg80211_stop_iface(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x29
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 result; // x0
  _QWORD *v9; // x21
  __int64 v10; // x0
  __int64 v11; // x2
  _QWORD *v12; // x1
  __int64 v13; // x9
  unsigned __int64 StatusReg; // x21
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x8

  if ( a1 )
  {
    v3 = a1;
    v4 = a2;
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      *(_DWORD *)(v5 + 28) = a3;
      v15 = _traceiter_cfg80211_stop_iface(0, v3, v4);
      a3 = *(unsigned int *)(v5 + 28);
      v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v17;
      if ( !v17 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v15, v16, a3);
        LODWORD(a3) = *(_DWORD *)(v5 + 28);
      }
    }
  }
  v6 = 1;
  if ( (a3 & 0x10) == 0 )
    v6 = 2;
  if ( (a3 & 0x400010) != 0 )
    v7 = v6;
  else
    v7 = 0;
  result = _kmalloc_cache_noprof(kmalloc_caches[14 * v7 + 10], (unsigned int)a3 | 0x100, 616);
  v9 = (_QWORD *)result;
  if ( result )
  {
    *(_DWORD *)(result + 16) = 4;
    v10 = raw_spin_lock_irqsave(v4 + 160);
    v11 = v4 + 144;
    v12 = *(_QWORD **)(v4 + 152);
    v13 = v10;
    if ( v9 == (_QWORD *)(v4 + 144) || v12 == v9 || *v12 != v11 )
    {
      _list_add_valid_or_report(v9, v12);
    }
    else
    {
      *(_QWORD *)(v4 + 152) = v9;
      *v9 = v11;
      v9[1] = v12;
      *v12 = v9;
    }
    raw_spin_unlock_irqrestore(v4 + 160, v13);
    return queue_work_on(32, cfg80211_wq, v3 - 656);
  }
  return result;
}
