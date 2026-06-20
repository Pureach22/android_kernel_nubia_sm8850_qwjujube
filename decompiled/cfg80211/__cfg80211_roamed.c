__int64 __fastcall _cfg80211_roamed(__int64 result, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x20
  __int16 v5; // w8
  unsigned int v6; // w8
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x21
  __int64 v10; // x23
  unsigned __int64 v11; // x25
  __int64 v12; // x9
  __int64 v13; // x8
  unsigned int v16; // w8
  unsigned int v17; // w8
  unsigned int v20; // w8
  unsigned int v21; // w8
  unsigned int v22; // w9
  int **v23; // x22
  __int64 v24; // x10
  unsigned int v25; // w12
  unsigned int v26; // w8
  __int64 v27; // x9
  __int64 v28; // x10
  bool v29; // w13
  __int64 v30; // x12
  unsigned int v33; // w14
  __int64 v34; // x12
  unsigned int v37; // w13
  unsigned int *v38; // x8
  unsigned int v39; // w8
  unsigned int v40; // w21
  _QWORD **v41; // x22
  bool v42; // w9
  unsigned int v43; // w8
  bool v44; // w10
  int v45; // w8
  __int64 v46; // x8
  unsigned int v49; // w8
  unsigned int v50; // w8
  unsigned int v57; // w8
  unsigned int v58; // w8

  v2 = *(_DWORD *)(result + 8);
  v3 = result;
  if ( v2 != 2 && v2 != 8 )
    goto LABEL_86;
  if ( (*(_BYTE *)(result + 164) & 1) == 0 )
    goto LABEL_86;
  v5 = *(_WORD *)(a2 + 88);
  if ( v5 )
  {
    if ( !*(_QWORD *)(a2 + 80)
      || (v5 & 1) != 0 && !*(_QWORD *)(a2 + 96)
      || (v5 & 2) != 0 && !*(_QWORD *)(a2 + 128)
      || (v5 & 4) != 0 && !*(_QWORD *)(a2 + 160)
      || (v5 & 8) != 0 && !*(_QWORD *)(a2 + 192)
      || (v5 & 0x10) != 0 && !*(_QWORD *)(a2 + 224)
      || (v5 & 0x20) != 0 && !*(_QWORD *)(a2 + 256)
      || (v5 & 0x40) != 0 && !*(_QWORD *)(a2 + 288)
      || (v5 & 0x80) != 0 && !*(_QWORD *)(a2 + 320)
      || (*(_WORD *)(a2 + 88) & 0x100) != 0 && !*(_QWORD *)(a2 + 352)
      || (*(_WORD *)(a2 + 88) & 0x200) != 0 && !*(_QWORD *)(a2 + 384)
      || (*(_WORD *)(a2 + 88) & 0x400) != 0 && !*(_QWORD *)(a2 + 416)
      || (*(_WORD *)(a2 + 88) & 0x800) != 0 && !*(_QWORD *)(a2 + 448)
      || (*(_WORD *)(a2 + 88) & 0x1000) != 0 && !*(_QWORD *)(a2 + 480)
      || (*(_WORD *)(a2 + 88) & 0x2000) != 0 && !*(_QWORD *)(a2 + 512)
      || (*(_WORD *)(a2 + 88) & 0x4000) != 0 && !*(_QWORD *)(a2 + 544) )
    {
      goto LABEL_86;
    }
  }
  v6 = *(unsigned __int16 *)(result + 1472);
  if ( !*(_WORD *)(result + 1472) || (v6 & 1) != 0 )
  {
    v7 = *(_QWORD *)(result + 400);
    if ( v7 )
    {
LABEL_111:
      _X10 = (unsigned int *)(v7 + 80);
      __asm { PRFM            #0x11, [X10] }
      do
      {
        v49 = __ldxr(_X10);
        v50 = v49 - 1;
      }
      while ( __stlxr(v50, _X10) );
      __dmb(0xBu);
      if ( (v50 & 0x80000000) != 0 )
      {
        __break(0x800u);
        v8 = *(_QWORD *)(v7 + 152);
        if ( !v8 )
          goto LABEL_42;
      }
      else
      {
        v8 = *(_QWORD *)(v7 + 152);
        if ( !v8 )
        {
LABEL_42:
          result = cfg80211_put_bss(*(_QWORD *)v3, (_QWORD *)(*(_QWORD *)(v3 + 400) + 112LL));
          v6 = *(unsigned __int16 *)(v3 + 1472);
          *(_QWORD *)(v3 + 400) = 0;
          goto LABEL_43;
        }
      }
      _X9 = (unsigned int *)(v8 - 32);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v57 = __ldxr(_X9);
        v58 = v57 - 1;
      }
      while ( __stlxr(v58, _X9) );
      __dmb(0xBu);
      if ( (v58 & 0x80000000) != 0 )
        __break(0x800u);
      goto LABEL_42;
    }
  }
LABEL_43:
  v9 = v3 + 392;
  if ( v6 )
  {
    v10 = 472;
    v11 = 1;
    while ( 1 )
    {
      if ( ((v6 >> v11) & 1) == 0 )
        goto LABEL_51;
      v12 = *(_QWORD *)(v3 + v10);
      if ( !v12 )
        goto LABEL_51;
      _X10 = (unsigned int *)(v12 + 80);
      __asm { PRFM            #0x11, [X10] }
      do
      {
        v16 = __ldxr(_X10);
        v17 = v16 - 1;
      }
      while ( __stlxr(v17, _X10) );
      __dmb(0xBu);
      if ( (v17 & 0x80000000) != 0 )
      {
        __break(0x800u);
        v13 = *(_QWORD *)(v12 + 152);
        if ( v13 )
        {
LABEL_49:
          _X9 = (unsigned int *)(v13 - 32);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v20 = __ldxr(_X9);
            v21 = v20 - 1;
          }
          while ( __stlxr(v21, _X9) );
          __dmb(0xBu);
          if ( (v21 & 0x80000000) != 0 )
            __break(0x800u);
        }
      }
      else
      {
        v13 = *(_QWORD *)(v12 + 152);
        if ( v13 )
          goto LABEL_49;
      }
      result = cfg80211_put_bss(*(_QWORD *)v3, (_QWORD *)(*(_QWORD *)(v3 + v10) + 112LL));
      *(_QWORD *)(v3 + v10) = 0;
      v6 = *(unsigned __int16 *)(v3 + 1472);
LABEL_51:
      if ( v6 )
      {
        _CF = v11++ >= 0xE;
        v10 += 72;
        if ( !_CF )
          continue;
      }
      break;
    }
  }
  v22 = 0;
  v23 = (int **)(a2 + 96);
  v24 = 120;
  while ( *(_WORD *)(a2 + 88) && (((unsigned __int64)*(unsigned __int16 *)(a2 + 88) >> v22) & 1) == 0
       || *(_QWORD *)(a2 + v24) )
  {
    if ( *(_WORD *)(a2 + 88) )
    {
      _CF = v22++ >= 0xE;
      v24 += 32;
      if ( !_CF )
        continue;
    }
    memset((void *)(v3 + 392), 0, 0x438u);
    v25 = *(unsigned __int16 *)(a2 + 88);
    v26 = 0;
    v27 = 120;
    v28 = 400;
    *(_WORD *)(v3 + 1472) = v25;
    v29 = v25 == 0;
    do
    {
      if ( v29 || (((unsigned __int64)v25 >> v26) & 1) != 0 )
      {
        v30 = *(_QWORD *)(a2 + v27);
        _X13 = (unsigned int *)(v30 - 32);
        __asm { PRFM            #0x11, [X13] }
        do
          v33 = __ldxr(_X13);
        while ( __stxr(v33 + 1, _X13) );
        v34 = *(_QWORD *)(v30 + 40);
        if ( v34 )
        {
          _X12 = (unsigned int *)(v34 - 32);
          __asm { PRFM            #0x11, [X12] }
          do
            v37 = __ldxr(_X12);
          while ( __stxr(v37 + 1, _X12) );
        }
        *(_QWORD *)(v3 + v28) = *(_QWORD *)(a2 + v27) - 112LL;
        v25 = *(unsigned __int16 *)(a2 + 88);
      }
      v29 = v25 == 0;
      if ( !v25 )
        break;
      _CF = v26++ >= 0xE;
      v27 += 32;
      v28 += 72;
    }
    while ( !_CF );
    if ( v25 )
      v38 = *(unsigned int **)(a2 + 80);
    else
      v38 = (unsigned int *)(*(_QWORD *)(a2 + 120) + 72LL);
    v7 = *v38;
    *(_DWORD *)(v3 + 280) = v7;
    *(_WORD *)(v3 + 284) = *((_WORD *)v38 + 2);
    v43 = *(unsigned __int16 *)(a2 + 88);
    if ( *(_WORD *)(a2 + 88) )
    {
      v7 = 0;
      v44 = 0;
      do
      {
        if ( v44 || (((unsigned __int64)v43 >> v7) & 1) != 0 )
        {
          v45 = **v23;
          *(_WORD *)(v9 + 4) = *((_WORD *)*v23 + 2);
          *(_DWORD *)v9 = v45;
          v43 = *(unsigned __int16 *)(a2 + 88);
        }
        v44 = v43 == 0;
        if ( !v43 )
          break;
        _CF = (unsigned int)v7++ >= 0xE;
        v23 += 4;
        v9 += 72;
      }
      while ( !_CF );
    }
    v46 = *(_QWORD *)v3;
    *(_QWORD *)(v3 + 272) = 0;
    if ( v46 )
      return nl80211_send_roamed(v46 - 992, *(_QWORD *)(v3 + 32), a2, 0xCC0u);
    __break(0x800u);
    goto LABEL_111;
  }
LABEL_86:
  __break(0x800u);
  v39 = *(unsigned __int16 *)(a2 + 88);
  v40 = 0;
  v41 = (_QWORD **)(a2 + 120);
  v42 = *(_WORD *)(a2 + 88) == 0;
  do
  {
    if ( v42 || (((unsigned __int64)v39 >> v40) & 1) != 0 )
    {
      result = cfg80211_put_bss(*(_QWORD *)v3, *v41);
      v39 = *(unsigned __int16 *)(a2 + 88);
    }
    v42 = v39 == 0;
    if ( !v39 )
      break;
    _CF = v40++ >= 0xE;
    v41 += 4;
  }
  while ( !_CF );
  return result;
}
