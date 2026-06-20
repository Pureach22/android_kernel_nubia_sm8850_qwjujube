__int64 __fastcall nl80211_add_link(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x21
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x19
  __int64 v6; // x9
  int v7; // w10
  __int64 v8; // x22
  __int64 v9; // x20
  __int64 v10; // x9
  _DWORD *v11; // x9
  __int64 result; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x9
  int v18; // [xsp+18h] [xbp+18h]

  v3 = a2[4];
  v4 = *(_QWORD *)(v3 + 2504);
  if ( v4 )
    v4 = *(unsigned __int8 *)(v4 + 4);
  v5 = *(_QWORD *)(a2[7] + 992LL);
  if ( (*(_BYTE *)(*(_QWORD *)v5 + 100LL) & 2) == 0 )
    return 4294967274LL;
  if ( *(_DWORD *)(v5 + 8) != 3 )
    return 4294967274LL;
  v6 = *(_QWORD *)(v3 + 48);
  if ( !v6 )
    return 4294967274LL;
  v7 = *(_DWORD *)(v6 + 4);
  if ( (v7 & 1) != 0 || !(v7 | *(unsigned __int16 *)(v6 + 8)) )
    return 4294967274LL;
  v8 = a2[6];
  v9 = 1LL << v4;
  *(_WORD *)(v5 + 1472) |= 1LL << v4;
  if ( (unsigned int)v4 > 0xE )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v18 = v4;
      v14 = _traceiter_rdev_add_intf_link(0, v8 + 992, v5, v4);
      LODWORD(v4) = v18;
      v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v17;
      if ( !v17 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v14, v15, v16);
        LODWORD(v4) = v18;
      }
    }
  }
  else
  {
    v2 = v5 + 72LL * (unsigned int)v4;
    v10 = *(_QWORD *)(a2[4] + 48LL);
    *(_DWORD *)(v2 + 392) = *(_DWORD *)(v10 + 4);
    *(_WORD *)(v2 + 396) = *(_WORD *)(v10 + 8);
  }
  v11 = *(_DWORD **)(*(_QWORD *)v8 + 48LL);
  if ( v11 )
  {
    if ( *(v11 - 1) != 319002951 )
      __break(0x8229u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v11)(v8 + 992, v5, (unsigned int)v4);
  }
  else
  {
    result = 0;
  }
  if ( (_DWORD)result )
  {
    *(_WORD *)(v5 + 1472) &= ~(_WORD)v9;
    *(_WORD *)(v2 + 396) = 0;
    *(_DWORD *)(v2 + 392) = 0;
  }
  return result;
}
