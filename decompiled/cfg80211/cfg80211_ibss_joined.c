__int64 __fastcall cfg80211_ibss_joined(__int64 result, int *a2, __int64 a3, int a4)
{
  __int64 v4; // x19
  int *v5; // x20
  __int64 *v6; // x23
  __int64 v7; // x22
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 *v10; // x21
  int v11; // w9
  __int16 v12; // w10
  __int64 v13; // x0
  _QWORD *v14; // x2
  __int64 *v15; // x1
  __int64 v16; // x9
  unsigned __int64 StatusReg; // x21
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x8
  int v21; // [xsp+1Ch] [xbp+1Ch]

  v6 = *(__int64 **)(result + 992);
  v7 = *v6;
  if ( *v6 )
  {
    v4 = a3;
    v5 = a2;
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
      v21 = a4;
      result = _traceiter_cfg80211_ibss_joined(0, result, v5, v4);
      a4 = v21;
      v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v20;
      if ( !v20 || !*(_QWORD *)(StatusReg + 16) )
      {
        result = preempt_schedule_notrace(result, v18, v19);
        a4 = v21;
      }
    }
  }
  if ( v4 )
  {
    v8 = 1;
    if ( (a4 & 0x10) == 0 )
      v8 = 2;
    if ( (a4 & 0x400010) != 0 )
      v9 = v8;
    else
      v9 = 0;
    result = _kmalloc_cache_noprof(kmalloc_caches[14 * v9 + 10], a4 | 0x100u, 616);
    v10 = (__int64 *)result;
    if ( result )
    {
      v11 = *v5;
      v12 = *((_WORD *)v5 + 2);
      *(_DWORD *)(result + 16) = 3;
      *(_DWORD *)(result + 24) = v11;
      *(_WORD *)(result + 28) = v12;
      *(_QWORD *)(result + 32) = v4;
      v13 = raw_spin_lock_irqsave(v6 + 20);
      v14 = v6 + 18;
      v15 = (__int64 *)v6[19];
      v16 = v13;
      if ( v10 == v6 + 18 || v15 == v10 || (_QWORD *)*v15 != v14 )
      {
        _list_add_valid_or_report(v10, v15);
      }
      else
      {
        v6[19] = (__int64)v10;
        *v10 = (__int64)v14;
        v10[1] = (__int64)v15;
        *v15 = (__int64)v10;
      }
      raw_spin_unlock_irqrestore(v6 + 20, v16);
      return queue_work_on(32, cfg80211_wq, v7 - 656);
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
