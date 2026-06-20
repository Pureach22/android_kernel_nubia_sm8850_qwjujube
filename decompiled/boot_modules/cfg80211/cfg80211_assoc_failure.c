__int64 __usercall cfg80211_assoc_failure@<X0>(__int64 a1@<X0>, __int64 a2@<X1>, __int64 a3@<X2>, __int64 a4@<X8>)
{
  __int64 v4; // x20
  __int64 *v5; // x21
  __int64 v6; // x19
  __int64 result; // x0
  __int64 i; // x21
  __int64 v9; // x1
  __int64 v10; // x8
  unsigned int v17; // w8
  unsigned int v18; // w8
  unsigned int v21; // w8
  unsigned int v22; // w8
  unsigned __int64 StatusReg; // x22
  __int64 v24; // x23
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 v27; // x9

  v5 = *(__int64 **)(a1 + 992);
  v6 = *v5;
  if ( *v5 )
  {
    a4 = a1;
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
      v24 = a4;
      ++*(_DWORD *)(StatusReg + 16);
      v25 = _traceiter_cfg80211_send_assoc_failure(0, a4, v4);
      v27 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v27;
      if ( !v27 || (a4 = v24, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(v25, v26, a3);
        a4 = v24;
      }
    }
  }
  if ( *(_BYTE *)(v4 + 128) == 1 )
  {
    nl80211_send_assoc_timeout(v6 - 992, a4);
    result = ((__int64 (__fastcall *)(__int64 *))cfg80211_sme_assoc_timeout)(v5);
  }
  else
  {
    result = cfg80211_sme_abandon_assoc(v5);
  }
  for ( i = 8; i != 128; i += 8 )
  {
    v9 = *(_QWORD *)(v4 + i);
    if ( v9 )
    {
      _X9 = (unsigned int *)(v9 - 32);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v17 = __ldxr(_X9);
        v18 = v17 - 1;
      }
      while ( __stlxr(v18, _X9) );
      __dmb(0xBu);
      if ( (v18 & 0x80000000) != 0 )
      {
        __break(0x800u);
        v10 = *(_QWORD *)(v9 + 40);
        if ( !v10 )
          goto LABEL_7;
      }
      else
      {
        v10 = *(_QWORD *)(v9 + 40);
        if ( !v10 )
        {
LABEL_7:
          result = cfg80211_put_bss(v6, v9);
          continue;
        }
      }
      _X9 = (unsigned int *)(v10 - 32);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v21 = __ldxr(_X9);
        v22 = v21 - 1;
      }
      while ( __stlxr(v22, _X9) );
      __dmb(0xBu);
      if ( (v22 & 0x80000000) != 0 )
        __break(0x800u);
      goto LABEL_7;
    }
  }
  return result;
}
