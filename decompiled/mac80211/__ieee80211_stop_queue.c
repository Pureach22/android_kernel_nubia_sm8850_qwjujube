__int64 __fastcall _ieee80211_stop_queue(__int64 result, unsigned int a2, unsigned int a3, int a4)
{
  __int64 v4; // x10
  int v5; // w11
  unsigned __int64 StatusReg; // x19
  __int64 v7; // x8
  unsigned __int64 v14; // x10
  int v15; // [xsp+4h] [xbp-Ch]
  unsigned int v16; // [xsp+8h] [xbp-8h]
  unsigned int v17; // [xsp+Ch] [xbp-4h]
  __int64 v18; // [xsp+28h] [xbp+18h]

  while ( 1 )
  {
    if ( *(unsigned __int16 *)(result + 128) <= (int)a2 )
    {
      __break(0x800u);
      return result;
    }
    if ( (a4 & 1) == 0 )
      break;
    if ( a2 <= 0xF && a3 <= 0xB )
    {
      v4 = result + 44LL * a2 + 4LL * a3;
      v5 = *(_DWORD *)(v4 + 608) + 1;
      goto LABEL_9;
    }
LABEL_11:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v18 = result;
      v17 = a2;
      v16 = a3;
      v15 = a4;
      _traceiter_stop_queue(0, result, a2, a3);
      a4 = v15;
      a3 = v16;
      a2 = v17;
      result = v18;
      v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v7;
      if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v18);
        a4 = v15;
        a3 = v16;
        a2 = v17;
        result = v18;
      }
    }
  }
  if ( a2 > 0xF || a3 >= 0xB )
    goto LABEL_11;
  v5 = 1;
  v4 = result + 44LL * a2 + 4LL * a3;
LABEL_9:
  *(_DWORD *)(v4 + 608) = v5;
  _X9 = (unsigned __int64 *)(result + 8LL * a2 + 480 + 8LL * (a3 >> 6));
  __asm { PRFM            #0x11, [X9] }
  do
    v14 = __ldxr(_X9);
  while ( __stxr(v14 | (1LL << a3), _X9) );
  return result;
}
