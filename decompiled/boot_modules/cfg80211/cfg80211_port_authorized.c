__int64 __fastcall cfg80211_port_authorized(__int64 result, int *a2, const void *a3, unsigned __int8 a4, int a5)
{
  const void *v5; // x19
  unsigned __int8 v6; // w21
  int *v7; // x23
  __int64 *v8; // x25
  __int64 v9; // x24
  unsigned __int64 v10; // x22
  __int64 v11; // x20
  int v12; // w9
  __int16 v13; // w10
  __int64 v14; // x0
  _QWORD *v15; // x2
  __int64 *v16; // x1
  __int64 v17; // x9
  unsigned __int64 StatusReg; // x26
  __int64 v19; // x27

  v8 = *(__int64 **)(result + 992);
  v9 = *v8;
  if ( !*v8 )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v19 = *(_QWORD *)(StatusReg + 80);
    v10 = v6;
    *(_QWORD *)(StatusReg + 80) = &cfg80211_port_authorized__alloc_tag;
    result = _kmalloc_noprof(v6 + 616LL, a5 | 0x100u);
    v11 = result;
    *(_QWORD *)(StatusReg + 80) = v19;
    if ( !result )
      return result;
LABEL_4:
    v12 = *v7;
    v13 = *((_WORD *)v7 + 2);
    *(_DWORD *)(v11 + 16) = 5;
    *(_DWORD *)(v11 + 24) = v12;
    *(_WORD *)(v11 + 28) = v13;
    *(_QWORD *)(v11 + 32) = v11 + 616;
    *(_BYTE *)(v11 + 40) = v6;
    if ( v10 < v6 )
    {
      _fortify_panic(17, v10);
    }
    else
    {
      memcpy(*(void **)(v11 + 32), v5, v6);
      v14 = raw_spin_lock_irqsave(v8 + 20);
      v15 = v8 + 18;
      v16 = (__int64 *)v8[19];
      v17 = v14;
      if ( (__int64 *)v11 != v8 + 18 && v16 != (__int64 *)v11 && (_QWORD *)*v16 == v15 )
      {
        v8[19] = v11;
        *(_QWORD *)v11 = v15;
        *(_QWORD *)(v11 + 8) = v16;
        *v16 = v11;
LABEL_9:
        raw_spin_unlock_irqrestore(v8 + 20, v17);
        return queue_work_on(32, cfg80211_wq, v9 - 656);
      }
    }
    _list_add_valid_or_report(v11, v16);
    goto LABEL_9;
  }
  v7 = a2;
  if ( !a2 )
  {
    __break(0x800u);
    return result;
  }
  v6 = a4;
  v5 = a3;
  v10 = a4;
  result = _kmalloc_noprof(a4 + 616LL, a5 | 0x100u);
  v11 = result;
  if ( result )
    goto LABEL_4;
  return result;
}
