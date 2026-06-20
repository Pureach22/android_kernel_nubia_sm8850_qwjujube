__int64 __fastcall _ieee80211_wake_queue(__int64 result, unsigned int a2, unsigned int a3, int a4, __int64 a5)
{
  __int64 v5; // x10
  int v6; // w11
  __int64 v7; // x9
  _DWORD *v8; // x10
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 v12; // x20
  unsigned int v13; // w21
  unsigned __int64 StatusReg; // x19
  __int64 v15; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v25; // x8
  __int64 v26; // [xsp+8h] [xbp-18h]
  int v27; // [xsp+14h] [xbp-Ch]
  unsigned int v28; // [xsp+18h] [xbp-8h]
  unsigned int v29; // [xsp+1Ch] [xbp-4h]
  __int64 v30; // [xsp+38h] [xbp+18h]

  while ( 1 )
  {
    if ( *(unsigned __int16 *)(result + 128) <= (int)a2 )
    {
      __break(0x800u);
      return result;
    }
    if ( a2 > 0x10 )
      goto LABEL_27;
    if ( ((*(_QWORD *)(result + 8LL * a2 + (((unsigned __int64)a3 >> 3) & 0x1FFFFFF8) + 480) >> a3) & 1) == 0 )
      return result;
    if ( (a4 & 1) != 0 )
      break;
    if ( a2 != 16 && a3 <= 0xA )
    {
      v7 = a2;
      v8 = (_DWORD *)(result + 44LL * a2 + 4LL * a3 + 608);
LABEL_15:
      *v8 = 0;
      goto LABEL_16;
    }
LABEL_27:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v28 = a3;
      v29 = a2;
      v30 = result;
      v27 = a4;
      v26 = a5;
      _traceiter_wake_queue(0, result, a2, a3);
      a4 = v27;
      a3 = v28;
      a2 = v29;
      a5 = v26;
      result = v30;
      v15 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v15;
      if ( !v15 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v30);
        a4 = v27;
        a3 = v28;
        a2 = v29;
        a5 = v26;
        result = v30;
      }
    }
  }
  if ( a2 == 16 )
    goto LABEL_27;
  if ( a3 > 0xB )
    goto LABEL_27;
  v5 = result + 44LL * a2 + 4LL * a3;
  v6 = *(_DWORD *)(v5 + 608) - 1;
  *(_DWORD *)(v5 + 608) = v6;
  if ( a3 == 11 )
    goto LABEL_27;
  v7 = a2;
  if ( v6 < 0 )
  {
    v8 = (_DWORD *)(v5 + 608);
    __break(0x800u);
    goto LABEL_15;
  }
  if ( v6 )
  {
    if ( *(_QWORD *)(result + 8LL * a2 + 480) )
      return result;
    goto LABEL_17;
  }
LABEL_16:
  v9 = result + 8 * v7;
  v10 = *(_QWORD *)(v9 + 480) & ~(1LL << a3);
  *(_QWORD *)(v9 + 480) = v10;
  if ( v10 )
    return result;
LABEL_17:
  if ( *(_QWORD *)(result + 24LL * (unsigned int)v7 + 2000) != result + 24LL * (unsigned int)v7 + 2000 )
  {
    _X9 = (unsigned __int64 *)(result + 2392);
    __asm { PRFM            #0x11, [X9] }
    do
      v22 = __ldxr(_X9);
    while ( __stlxr(v22 | 1, _X9) );
    __dmb(0xBu);
    if ( (v22 & 1) == 0 )
    {
      v11 = result;
      v12 = a5;
      v13 = a3;
      _tasklet_schedule(result + 2384);
      a3 = v13;
      a5 = v12;
      result = v11;
    }
  }
  if ( a3 )
    return ((__int64 (__fastcall *)(__int64, __int64))ieee80211_wake_txqs)(result, a5);
  _X9 = (unsigned __int64 *)(result + 2432);
  __asm { PRFM            #0x11, [X9] }
  do
    v25 = __ldxr(_X9);
  while ( __stlxr(v25 | 1, _X9) );
  __dmb(0xBu);
  if ( (v25 & 1) == 0 )
    return _tasklet_schedule(result + 2424);
  return result;
}
