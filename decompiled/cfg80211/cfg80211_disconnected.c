__int64 __fastcall cfg80211_disconnected(__int64 a1, __int16 a2, const void *a3, size_t a4, char a5, int a6)
{
  char v6; // w21
  __int16 v7; // w22
  size_t v8; // x23
  const void *v9; // x24
  __int64 *v10; // x26
  __int64 v11; // x25
  unsigned __int64 v12; // x19
  __int64 result; // x0
  __int64 *v14; // x1
  __int64 v15; // x20
  __int64 v16; // x0
  _QWORD *v17; // x2
  __int64 v18; // x9
  unsigned __int64 StatusReg; // x27
  __int64 v20; // x28

  v10 = *(__int64 **)(a1 + 992);
  v11 = *v10;
  if ( *v10 )
  {
    v6 = a5;
    v8 = a4;
    v9 = a3;
    v7 = a2;
    v12 = a4 + 616;
    result = _kmalloc_noprof(a4 + 616, a6 | 0x100u);
    v15 = result;
    if ( !result )
      return result;
  }
  else
  {
    __break(0x800u);
    v12 = v8 + 616;
    StatusReg = _ReadStatusReg(SP_EL0);
    v20 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cfg80211_disconnected__alloc_tag;
    result = _kmalloc_noprof(v8 + 616, a6 | 0x100u);
    v15 = result;
    *(_QWORD *)(StatusReg + 80) = v20;
    if ( !result )
      return result;
  }
  if ( v12 < 0x10 )
    goto LABEL_24;
  if ( (v12 & 0xFFFFFFFFFFFFFFFCLL) == 0x10 )
    goto LABEL_24;
  *(_DWORD *)(v15 + 16) = 2;
  if ( v12 < 0x18 )
    goto LABEL_24;
  if ( (v12 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
    goto LABEL_24;
  *(_QWORD *)(v15 + 24) = v15 + 616;
  if ( v12 < 0x20 || (v12 & 0xFFFFFFFFFFFFFFF8LL) == 0x20 )
    goto LABEL_24;
  *(_QWORD *)(v15 + 32) = v8;
  if ( v12 >= 0x268 )
    v14 = (__int64 *)(v12 - 616);
  else
    v14 = nullptr;
  if ( (unsigned __int64)v14 < v8 )
    goto LABEL_25;
  if ( (v12 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
    goto LABEL_24;
  memcpy(*(void **)(v15 + 24), v9, v8);
  if ( v12 < 0x28 )
    goto LABEL_24;
  if ( (v12 & 0xFFFFFFFFFFFFFFFELL) == 0x28 )
    goto LABEL_24;
  *(_WORD *)(v15 + 40) = v7;
  if ( v12 < 0x2B )
    goto LABEL_24;
  *(_BYTE *)(v15 + 42) = v6 & 1;
  v16 = raw_spin_lock_irqsave(v10 + 20);
  v17 = v10 + 18;
  v14 = (__int64 *)v10[19];
  v18 = v16;
  if ( (__int64 *)v15 == v10 + 18 || v14 == (__int64 *)v15 || (_QWORD *)*v14 != v17 )
    goto LABEL_26;
  v10[19] = v15;
  *(_QWORD *)v15 = v17;
  if ( (v12 & 0xFFFFFFFFFFFFFFF8LL) == 8 )
  {
LABEL_24:
    __break(1u);
LABEL_25:
    _fortify_panic(17, v14);
LABEL_26:
    _list_add_valid_or_report(v15, v14);
    goto LABEL_22;
  }
  *(_QWORD *)(v15 + 8) = v14;
  *v14 = v15;
LABEL_22:
  raw_spin_unlock_irqrestore(v10 + 20, v18);
  return queue_work_on(32, cfg80211_wq, v11 - 656);
}
