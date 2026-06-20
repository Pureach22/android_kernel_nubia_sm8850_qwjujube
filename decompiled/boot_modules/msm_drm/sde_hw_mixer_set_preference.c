__int64 __fastcall sde_hw_mixer_set_preference(__int64 a1, unsigned int a2, int a3)
{
  unsigned int v3; // w8
  __int64 v4; // x9
  unsigned __int64 v5; // x10
  unsigned int v6; // w13
  __int64 v7; // x12
  unsigned __int64 v14; // x17
  unsigned __int64 v17; // x17
  __int64 v18; // x9
  unsigned __int64 v19; // x10
  unsigned int v20; // w11
  unsigned int v21; // w17
  __int64 v22; // x13
  unsigned int v23; // w2
  unsigned __int64 v26; // x3
  unsigned __int64 v29; // x3
  unsigned __int64 v32; // x3
  unsigned __int64 v35; // x3

  if ( a3 == 1 )
  {
    v3 = *(_DWORD *)(a1 + 6952);
    if ( !v3 )
      return v3;
    v18 = 0;
    v19 = 0;
    v3 = 0;
    v20 = 0;
    v21 = 0;
    v22 = a1 + 6992;
    while ( 1 )
    {
      if ( v18 == 1152 )
        goto LABEL_48;
      if ( (*(_BYTE *)(a1 + v18 + 6992) & 0x40) != 0 )
      {
        _X2 = (unsigned __int64 *)(v22 + v18);
        __asm { PRFM            #0x11, [X2] }
        do
          v29 = __ldxr(_X2);
        while ( __stxr(v29 & 0xFFFFFFFFFFFFFFBFLL, _X2) );
        ++v20;
      }
      _X2 = (unsigned __int64 *)(v22 + v18);
      __asm { PRFM            #0x11, [X2] }
      do
        v26 = __ldxr(_X2);
      while ( __stxr(v26 & 0xFFFFFFFFFFFFFFDFLL, _X2) );
      if ( v21 < a2 )
      {
        _X2 = (unsigned __int64 *)(v22 + v18);
        __asm { PRFM            #0x11, [X2] }
        do
          v32 = __ldxr(_X2);
        while ( __stxr(v32 | 0x20, _X2) );
        ++v21;
        v3 |= 1LL << ((unsigned __int8)*(_DWORD *)(a1 + v18 + 6976) - 1);
      }
      if ( v21 != a2 || v20 < 2 )
        break;
      if ( v18 == 1056 )
        goto LABEL_48;
      v23 = a2;
      if ( ((*(_QWORD *)(a1 + v18 + (((unsigned __int64)*(unsigned int *)(a1 + v18 + 7072) >> 3) & 0x1FFFFFF8) + 7040) >> *(_DWORD *)(a1 + v18 + 7072))
          & 1) != 0 )
        goto LABEL_35;
LABEL_23:
      ++v19;
      v18 += 96;
      v21 = v23;
      if ( v19 >= *(unsigned int *)(a1 + 6952) )
        return v3;
    }
    if ( v21 >= a2 )
    {
LABEL_35:
      if ( v21 < v20 + a2 )
      {
        _X2 = (unsigned __int64 *)(v22 + v18);
        __asm { PRFM            #0x11, [X2] }
        do
          v35 = __ldxr(_X2);
        while ( __stxr(v35 | 0x40, _X2) );
        v23 = v21 + 1;
        goto LABEL_23;
      }
    }
    v23 = v21;
    goto LABEL_23;
  }
  if ( a3 == 2 )
  {
    v3 = *(_DWORD *)(a1 + 6952);
    if ( v3 )
    {
      v4 = 0;
      v5 = 0;
      v3 = 0;
      v6 = 0;
      v7 = a1 + 6992;
      while ( v4 != 1152 )
      {
        _X16 = (unsigned __int64 *)(v7 + v4);
        __asm { PRFM            #0x11, [X16] }
        do
          v14 = __ldxr(_X16);
        while ( __stxr(v14 & 0xFFFFFFFFFFFFFFBFLL, _X16) );
        if ( a2 < 2 || v6 )
          goto LABEL_13;
        if ( v4 == 1056 )
          break;
        if ( ((*(_QWORD *)(a1 + v4 + (((unsigned __int64)*(unsigned int *)(a1 + v4 + 7072) >> 3) & 0x1FFFFFF8) + 7040) >> *(_DWORD *)(a1 + v4 + 7072))
            & 1) != 0 )
        {
LABEL_13:
          if ( v6 < a2 && (*(_BYTE *)(a1 + v4 + 6992) & 0x20) == 0 )
          {
            _X16 = (unsigned __int64 *)(v7 + v4);
            __asm { PRFM            #0x11, [X16] }
            do
              v17 = __ldxr(_X16);
            while ( __stxr(v17 | 0x40, _X16) );
            ++v6;
            v3 |= 1LL << ((unsigned __int8)*(_DWORD *)(a1 + v4 + 6976) - 1);
          }
        }
        else
        {
          v6 = 0;
        }
        ++v5;
        v4 += 96;
        if ( v5 >= *(unsigned int *)(a1 + 6952) )
          return v3;
      }
LABEL_48:
      __break(0x5512u);
      JUMPOUT(0x168C8C);
    }
    return v3;
  }
  return 0;
}
