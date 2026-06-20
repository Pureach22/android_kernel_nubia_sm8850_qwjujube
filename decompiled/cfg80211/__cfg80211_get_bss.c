__int64 *__fastcall _cfg80211_get_bss(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        void *a4,
        size_t a5,
        unsigned int a6,
        unsigned int a7,
        int a8)
{
  int v8; // w19
  unsigned int v9; // w20
  unsigned int v10; // w21
  __int64 v11; // x25
  _DWORD *v12; // x26
  __int64 v13; // x28
  __int64 v14; // x27
  __int64 *v15; // x23
  __int64 *v16; // x25
  _DWORD *v17; // x8
  __int64 *v18; // x22
  unsigned int v19; // w9
  int v20; // w10
  int v21; // w10
  int v22; // w9
  bool v23; // zf
  int v24; // w8
  int v25; // w8
  __int64 v27; // x8
  __int64 v28; // x8
  unsigned __int64 StatusReg; // x22
  __int64 bss; // x0
  __int64 v31; // x1
  __int64 v32; // x2
  __int64 v33; // x8
  int v34; // [xsp+8h] [xbp-18h]

  v34 = a3;
  if ( a1 )
  {
    v8 = a8;
    v9 = a7;
    v13 = jiffies;
    v10 = a6;
    v11 = a1;
    v12 = a2;
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
      bss = _traceiter_cfg80211_get_bss(0, v11, v12, a3, a4, a5, v10, v9);
      v33 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v33;
      if ( !v33 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(bss, v31, v32);
    }
  }
  v14 = v11 - 808;
  raw_spin_lock_bh(v11 - 808);
  v15 = (__int64 *)(v11 - 800);
  v16 = *(__int64 **)(v11 - 800);
  if ( v16 == v15 )
  {
LABEL_35:
    raw_spin_unlock_bh(v14);
    return nullptr;
  }
  while ( 1 )
  {
    v18 = v16 + 14;
    v17 = (_DWORD *)v16[14];
    v19 = *((unsigned __int16 *)v16 + 91);
    if ( v10 == 4 )
      break;
    if ( *v17 == 2 )
    {
      v20 = 3 - v10;
      if ( v10 >= 3 )
        goto LABEL_6;
    }
    else if ( v10 )
    {
      if ( v10 == 3 )
      {
        v20 = 0;
      }
      else
      {
        if ( v10 != 2 )
          goto LABEL_6;
        v20 = 2;
      }
    }
    else
    {
      v20 = 1;
    }
    if ( v20 == (v19 & 3) )
      break;
LABEL_6:
    v16 = (__int64 *)*v16;
    if ( v16 == v15 )
      goto LABEL_35;
  }
  v21 = (v19 >> 4) & 1;
  v22 = v9 | v19 & 0x10;
  if ( v9 != 1 )
    v21 = 0;
  if ( v12 )
    v23 = v17 == v12;
  else
    v23 = 1;
  v24 = v23;
  if ( !v22 )
    goto LABEL_6;
  if ( v21 )
    goto LABEL_6;
  if ( !v24 )
    goto LABEL_6;
  v25 = *((_DWORD *)v16 + 46);
  if ( (v25 & 1) != 0
    || !(v25 | *((unsigned __int16 *)v16 + 94))
    || (v8 & ~*((unsigned __int8 *)v16 + 198)) != 0
    || v16[8] - v13 + 7500 < 0 && !*((_DWORD *)v16 + 20) )
  {
    goto LABEL_6;
  }
  if ( (is_bss((int)v16 + 112, v34, a4, a5) & 1) == 0 )
    goto LABEL_6;
  v27 = v16[18];
  ++v16[9];
  if ( v27 )
    ++*(_QWORD *)(v27 - 40);
  v28 = v16[19];
  if ( v28 )
    ++*(_QWORD *)(v28 - 40);
  raw_spin_unlock_bh(v14);
  if ( !v16 )
    return nullptr;
  return v18;
}
