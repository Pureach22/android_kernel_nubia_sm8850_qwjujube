__int64 __fastcall rmnet_wlan_fwd_info_notifier(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  unsigned __int64 v5; // x8
  __int64 v6; // x9
  unsigned int *v7; // x9
  unsigned int v8; // w12
  __int64 v9; // x9
  unsigned __int64 StatusReg; // x9
  __int64 v11; // x10
  unsigned int *v12; // x10
  unsigned int v13; // w13
  __int64 v14; // x10
  __int64 v16; // [xsp+0h] [xbp-10h]
  __int64 v17; // [xsp+8h] [xbp-8h]
  __int64 v18; // [xsp+8h] [xbp-8h]

  v3 = *a3;
  if ( *a3
    && *(unsigned __int8 *)(v3 + 296) == *(unsigned __int8 *)(a1 + 24)
    && (!*(_BYTE *)(v3 + 297)
     || *(unsigned __int8 *)(v3 + 297) == *(unsigned __int8 *)(a1 + 25)
     && (!*(_BYTE *)(v3 + 298)
      || *(unsigned __int8 *)(v3 + 298) == *(unsigned __int8 *)(a1 + 26)
      && (!*(_BYTE *)(v3 + 299)
       || *(unsigned __int8 *)(v3 + 299) == *(unsigned __int8 *)(a1 + 27)
       && (!*(_BYTE *)(v3 + 300)
        || *(unsigned __int8 *)(v3 + 300) == *(unsigned __int8 *)(a1 + 28)
        && (!*(_BYTE *)(v3 + 301)
         || *(unsigned __int8 *)(v3 + 301) == *(unsigned __int8 *)(a1 + 29)
         && (!*(_BYTE *)(v3 + 302)
          || *(unsigned __int8 *)(v3 + 302) == *(unsigned __int8 *)(a1 + 30)
          && (!*(_BYTE *)(v3 + 303)
           || *(unsigned __int8 *)(v3 + 303) == *(unsigned __int8 *)(a1 + 31)
           && (!*(_BYTE *)(v3 + 304)
            || *(unsigned __int8 *)(v3 + 304) == *(unsigned __int8 *)(a1 + 32)
            && (!*(_BYTE *)(v3 + 305)
             || *(unsigned __int8 *)(v3 + 305) == *(unsigned __int8 *)(a1 + 33)
             && (!*(_BYTE *)(v3 + 306)
              || *(unsigned __int8 *)(v3 + 306) == *(unsigned __int8 *)(a1 + 34)
              && (!*(_BYTE *)(v3 + 307)
               || *(unsigned __int8 *)(v3 + 307) == *(unsigned __int8 *)(a1 + 35)
               && (!*(_BYTE *)(v3 + 308)
                || *(unsigned __int8 *)(v3 + 308) == *(unsigned __int8 *)(a1 + 36)
                && (!*(_BYTE *)(v3 + 309)
                 || *(unsigned __int8 *)(v3 + 309) == *(unsigned __int8 *)(a1 + 37)
                 && (!*(_BYTE *)(v3 + 310)
                  || *(unsigned __int8 *)(v3 + 310) == *(unsigned __int8 *)(a1 + 38)
                  && (!*(_BYTE *)(v3 + 311) || *(unsigned __int8 *)(v3 + 311) == *(unsigned __int8 *)(a1 + 39)))))))))))))))) )
  {
    if ( a2 == 1 )
    {
      if ( !*(_QWORD *)(a1 + 40) )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(StatusReg + 16);
        v11 = *(_QWORD *)(v3 + 1320);
        v12 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v11);
        do
          v13 = __ldxr(v12);
        while ( __stxr(v13 + 1, v12) );
        v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v14;
        if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
        {
          v16 = v3;
          v18 = a1;
          preempt_schedule_notrace();
          v3 = v16;
          a1 = v18;
        }
        *(_QWORD *)(a1 + 40) = v3;
      }
    }
    else if ( a2 == 10 )
    {
      v4 = *(_QWORD *)(a1 + 40);
      if ( v4 )
      {
        v5 = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(v5 + 16);
        v6 = *(_QWORD *)(v4 + 1320);
        v7 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v6);
        do
          v8 = __ldxr(v7);
        while ( __stxr(v8 - 1, v7) );
        v9 = *(_QWORD *)(v5 + 16) - 1LL;
        *(_DWORD *)(v5 + 16) = v9;
        if ( !v9 || !*(_QWORD *)(v5 + 16) )
        {
          v17 = a1;
          preempt_schedule_notrace();
          a1 = v17;
        }
        *(_QWORD *)(a1 + 40) = 0;
      }
    }
  }
  return 0;
}
