__int64 __fastcall sta_apply_parameters(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x24
  int v5; // w9
  _BOOL4 v8; // w10
  unsigned int v9; // w22
  unsigned int v10; // w21
  __int64 result; // x0
  int v12; // w8
  int v13; // w8
  unsigned __int64 v16; // x10
  unsigned __int64 v23; // x9
  unsigned __int64 v26; // x10
  unsigned __int64 v29; // x9
  unsigned __int64 v32; // x10
  unsigned __int64 v35; // x9
  unsigned __int64 v38; // x9
  unsigned __int64 v41; // x9

  v3 = *(_QWORD *)(a2 + 80);
  v5 = *(_DWORD *)(a3 + 12);
  v8 = (*(_QWORD *)(a2 + 216) & 0x800LL) == 0;
  if ( (v5 & 2) == 0 )
    v8 = 1;
  if ( v8 )
    v9 = *(_DWORD *)(a3 + 8);
  else
    v9 = *(_DWORD *)(a3 + 8) | 0xA0;
  if ( v8 )
    v10 = *(_DWORD *)(a3 + 12);
  else
    v10 = v5 | 0xA0;
  if ( (v9 & 8) != 0 && *(unsigned __int16 *)(a1 + 128) >= 4u )
    *(_BYTE *)(a2 + 2698) = (v10 & 8) != 0;
  if ( (*(_QWORD *)(a2 + 216) & 0x800) != 0
    || (v9 & 0x80) != 0 && (v10 & 0x80) != 0
    || (result = sta_apply_auth_flags(a2, v9, v10), !(_DWORD)result) )
  {
    if ( (v9 & 4) == 0 )
    {
      if ( (v9 & 0x10) == 0 )
        goto LABEL_18;
LABEL_24:
      *(_BYTE *)(a2 + 2714) = (v10 & 0x10) != 0;
      if ( (v10 & 0x10) != 0 )
      {
        _X8 = (unsigned __int64 *)(a2 + 216);
        __asm { PRFM            #0x11, [X8] }
        do
          v29 = __ldxr(_X8);
        while ( __stxr(v29 | 0x80, _X8) );
        if ( (v9 & 0x40) != 0 )
          goto LABEL_26;
      }
      else
      {
        _X8 = (unsigned __int64 *)(a2 + 216);
        __asm { PRFM            #0x11, [X8] }
        do
          v26 = __ldxr(_X8);
        while ( __stxr(v26 & 0xFFFFFFFFFFFFFF7FLL, _X8) );
        if ( (v9 & 0x40) != 0 )
          goto LABEL_26;
      }
LABEL_19:
      if ( (v9 & 0x100) == 0 )
        goto LABEL_20;
LABEL_28:
      *(_BYTE *)(a2 + 2716) = BYTE1(v10) & 1;
      if ( (*(_QWORD *)(a2 + 216) & 0x800) == 0 )
        goto LABEL_32;
LABEL_29:
      if ( (*(_BYTE *)(v3 + 4178) & 1) == 0
        && *(unsigned __int8 *)(a3 + 56) >= 4u
        && (*(_BYTE *)(*(_QWORD *)(a3 + 48) + 3LL) & 0x40) != 0 )
      {
        _X8 = (unsigned __int64 *)(a2 + 216);
        __asm { PRFM            #0x11, [X8] }
        do
          v38 = __ldxr(_X8);
        while ( __stxr(v38 | 0x4000, _X8) );
        if ( (*(_QWORD *)(a2 + 216) & 0x800) != 0 )
        {
LABEL_33:
          if ( (*(_BYTE *)(v3 + 2740) & 1) == 0
            && (*(_QWORD *)(a1 + 96) & 0x20000000) != 0
            && *(unsigned __int8 *)(a3 + 56) >= 8u
            && (*(_BYTE *)(*(_QWORD *)(a3 + 48) + 7LL) & 0x20) != 0 )
          {
            _X8 = (unsigned __int64 *)(a2 + 216);
            __asm { PRFM            #0x11, [X8] }
            do
              v41 = __ldxr(_X8);
            while ( __stxr(v41 | 0x10000, _X8) );
          }
        }
LABEL_37:
        if ( (*(_BYTE *)(a3 + 16) & 1) != 0 )
        {
          *(_BYTE *)(a2 + 2699) = *(_BYTE *)(a3 + 32);
          *(_BYTE *)(a2 + 2700) = *(_BYTE *)(a3 + 33);
        }
        ieee80211_sta_set_max_amsdu_subframes(a2, *(_QWORD *)(a3 + 48), *(unsigned __int8 *)(a3 + 56));
        if ( *(_WORD *)(a3 + 24) )
          *(_WORD *)(a2 + 2694) = *(_WORD *)(a3 + 24);
        v12 = *(_DWORD *)(a3 + 20);
        if ( (v12 & 0x80000000) == 0 )
          *(_WORD *)(a2 + 200) = v12;
        result = sta_link_apply_parameters(a1, a2, 1, a3 + 104);
        if ( !(_DWORD)result )
        {
          v13 = *(_DWORD *)(a3 + 92);
          if ( (v13 & 0x80000000) == 0 )
            *(_BYTE *)(a2 + 2728) = v13 != 0;
          if ( *(_WORD *)(a3 + 96) )
            *(_WORD *)(a2 + 688) = *(_WORD *)(a3 + 96);
          if ( (*(_QWORD *)(a2 + 216) & 0x800) == 0 && (v10 & 0x80) == 0
            || (result = sta_apply_auth_flags(a2, v9, v10), !(_DWORD)result) )
          {
            result = 0;
            if ( *(_QWORD *)(a3 + 104) )
              *(_BYTE *)(a2 + 2715) = 1;
          }
        }
        return result;
      }
LABEL_32:
      if ( (*(_QWORD *)(a2 + 216) & 0x800) != 0 )
        goto LABEL_33;
      goto LABEL_37;
    }
    if ( (v10 & 4) != 0 )
    {
      _X8 = (unsigned __int64 *)(a2 + 216);
      __asm { PRFM            #0x11, [X8] }
      do
        v23 = __ldxr(_X8);
      while ( __stxr(v23 | 0x10, _X8) );
      if ( (v9 & 0x10) != 0 )
        goto LABEL_24;
    }
    else
    {
      _X8 = (unsigned __int64 *)(a2 + 216);
      __asm { PRFM            #0x11, [X8] }
      do
        v16 = __ldxr(_X8);
      while ( __stxr(v16 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
      if ( (v9 & 0x10) != 0 )
        goto LABEL_24;
    }
LABEL_18:
    if ( (v9 & 0x40) == 0 )
      goto LABEL_19;
LABEL_26:
    if ( (v10 & 0x40) != 0 )
    {
      _X8 = (unsigned __int64 *)(a2 + 216);
      __asm { PRFM            #0x11, [X8] }
      do
        v35 = __ldxr(_X8);
      while ( __stxr(v35 | 0x800, _X8) );
      if ( (v9 & 0x100) != 0 )
        goto LABEL_28;
    }
    else
    {
      _X8 = (unsigned __int64 *)(a2 + 216);
      __asm { PRFM            #0x11, [X8] }
      do
        v32 = __ldxr(_X8);
      while ( __stxr(v32 & 0xFFFFFFFFFFFFF7FFLL, _X8) );
      if ( (v9 & 0x100) != 0 )
        goto LABEL_28;
    }
LABEL_20:
    if ( (*(_QWORD *)(a2 + 216) & 0x800) == 0 )
      goto LABEL_32;
    goto LABEL_29;
  }
  return result;
}
