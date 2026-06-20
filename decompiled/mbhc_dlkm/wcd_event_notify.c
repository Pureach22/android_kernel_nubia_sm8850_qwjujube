__int64 __fastcall wcd_event_notify(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 (__fastcall *v6)(__int64, __int64); // x8
  char v7; // w22
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  char v9; // w21
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x2
  _QWORD *v13; // x8
  _DWORD *v14; // x9
  void (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x1
  __int64 v17; // x8
  char v18; // w0
  __int64 v19; // x1
  __int64 v20; // x0
  void (__fastcall *v21)(__int64, __int64, __int64); // x8
  __int64 v22; // x1
  _QWORD *v23; // x8
  _DWORD *v24; // x9
  void (__fastcall *v25)(__int64, __int64, __int64); // x8
  void (__fastcall *v26)(__int64, __int64); // x9
  _DWORD *v27; // x9
  __int64 v28; // x8
  char v29; // w0
  __int64 v30; // x1
  _QWORD *v31; // x0
  int v32; // w1
  unsigned __int64 v39; // x9
  unsigned __int64 v43; // x10
  unsigned __int64 v46; // x10
  unsigned __int64 v49; // x10
  unsigned __int64 v52; // x9
  unsigned __int64 v55; // x10
  unsigned __int64 v58; // x10
  unsigned __int64 v61; // x10

  v3 = *(_QWORD *)(a3 + 216);
  v6 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a3 + 120) + 152LL);
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != -1840370871 )
      __break(0x8228u);
    v7 = v6(a3, 2);
    v8 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a3 + 120) + 152LL);
    if ( *((_DWORD *)v8 - 1) != -1840370871 )
      __break(0x8228u);
    v9 = v8(a3, 1);
    if ( a2 > 8 )
      goto LABEL_7;
  }
  else
  {
    v7 = 0;
    v9 = 0;
    if ( a2 > 8 )
    {
LABEL_7:
      if ( a2 <= 11 )
      {
        switch ( a2 )
        {
          case 9:
            _X8 = (unsigned __int64 *)(a3 + 360);
            __asm { PRFM            #0x11, [X8] }
            do
              v52 = __ldxr(_X8);
            while ( __stxr(v52 | 1, _X8) );
            if ( (v7 & 1) == 0 )
              goto LABEL_85;
            goto LABEL_71;
          case 10:
            mutex_lock(&hphl_pa_lock);
            _X8 = (unsigned __int64 *)(a3 + 344);
            __asm { PRFM            #0x11, [X8] }
            do
              v43 = __ldxr(_X8);
            while ( __stxr(v43 & 0xFFFFFFFFFFFFFFFELL, _X8) );
            _X8 = (unsigned __int64 *)(a3 + 360);
            __asm { PRFM            #0x11, [X8] }
            do
              v46 = __ldxr(_X8);
            while ( __stxr(v46 & 0xFFFFFFFFFFFFFFFELL, _X8) );
            wcd_enable_curr_micbias((_QWORD *)a3, v7 & 1);
            mutex_unlock(&hphl_pa_lock);
            _X8 = (unsigned __int64 *)(a3 + 352);
            __asm { PRFM            #0x11, [X8] }
            do
              v49 = __ldxr(_X8);
            while ( __stxr(v49 & 0xFFFFFFFFFFFFFFFELL, _X8) );
            break;
          case 11:
            _X8 = (unsigned __int64 *)(a3 + 360);
            __asm { PRFM            #0x11, [X8] }
            do
              v39 = __ldxr(_X8);
            while ( __stxr(v39 | 2, _X8) );
            if ( (v7 & 1) == 0 )
            {
LABEL_85:
              v31 = (_QWORD *)a3;
              v32 = 2;
              goto LABEL_86;
            }
LABEL_71:
            v31 = (_QWORD *)a3;
            v32 = 1;
LABEL_86:
            wcd_enable_curr_micbias(v31, v32);
            return 0;
        }
        return 0;
      }
      switch ( a2 )
      {
        case 12:
          mutex_lock(&hphr_pa_lock);
          _X8 = (unsigned __int64 *)(a3 + 344);
          __asm { PRFM            #0x11, [X8] }
          do
            v55 = __ldxr(_X8);
          while ( __stxr(v55 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
          _X8 = (unsigned __int64 *)(a3 + 360);
          __asm { PRFM            #0x11, [X8] }
          do
            v58 = __ldxr(_X8);
          while ( __stxr(v58 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
          wcd_enable_curr_micbias((_QWORD *)a3, v7 & 1);
          mutex_unlock(&hphr_pa_lock);
          _X8 = (unsigned __int64 *)(a3 + 352);
          __asm { PRFM            #0x11, [X8] }
          do
            v61 = __ldxr(_X8);
          while ( __stxr(v61 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
          return 0;
        case 15:
          v10 = *(_QWORD *)(a3 + 120);
          v11 = *(_QWORD *)(a3 + 792);
          v12 = 0;
          break;
        case 16:
          v10 = *(_QWORD *)(a3 + 120);
          v11 = *(_QWORD *)(a3 + 792);
          v12 = 1;
          break;
        default:
          return 0;
      }
      v20 = *(_QWORD *)(a3 + 216);
      v21 = *(void (__fastcall **)(__int64, __int64, __int64))(v10 + 112);
      v22 = *(unsigned int *)(v11 + 20);
      if ( *((_DWORD *)v21 - 1) != 542830841 )
        __break(0x8228u);
LABEL_82:
      v21(v20, v22, v12);
      return 0;
    }
  }
  if ( a2 <= 3 )
  {
    if ( a2 == 1 )
    {
      if ( *(_QWORD *)(*(_QWORD *)(a3 + 120) + 208LL) )
      {
        if ( (*(_BYTE *)(a3 + 207) & 1) == 0 )
        {
          v17 = *(_QWORD *)(a3 + 856);
          if ( !*(_DWORD *)(v17 + 184)
            || (v18 = snd_soc_component_read(*(_QWORD *)(a3 + 216)),
                v17 = *(_QWORD *)(a3 + 856),
                (unsigned __int8)(v18 & *(_BYTE *)(v17 + 188)) >> *(_BYTE *)(v17 + 189)) )
          {
            v19 = *(unsigned int *)(v17 + 360);
            if ( (_DWORD)v19 )
              snd_soc_component_update_bits(
                *(_QWORD *)(a3 + 216),
                v19,
                *(unsigned __int8 *)(v17 + 364),
                (unsigned int)(3 << *(_BYTE *)(v17 + 365)));
          }
        }
      }
      return 0;
    }
    if ( a2 == 2 )
    {
      v13 = *(_QWORD **)(a3 + 120);
      if ( !v13[26] )
        *(_BYTE *)(a3 + 209) = 0;
      if ( *(_BYTE *)(a3 + 207) == 1 )
        goto LABEL_71;
      v14 = (_DWORD *)v13[9];
      if ( v14 )
      {
        if ( *(v14 - 1) != -1918869124 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v14)(v3, 0);
        v13 = *(_QWORD **)(a3 + 120);
      }
      v15 = (void (__fastcall *)(_QWORD))v13[8];
      if ( v15 && (*(_BYTE *)(a3 + 207) & 1) == 0 )
      {
        if ( *((_DWORD *)v15 - 1) != 933030000 )
          __break(0x8228u);
        v15(v3);
      }
      if ( (*(_QWORD *)(a3 + 360) & 1) != 0 )
        LODWORD(v16) = 2;
      else
        v16 = *(_QWORD *)(a3 + 360) & 2LL;
      wcd_enable_curr_micbias((_QWORD *)a3, v16);
      v21 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a3 + 120) + 88LL);
      if ( v21 )
      {
        v22 = v9 & 1;
        v20 = v3;
        v12 = 0;
        if ( *((_DWORD *)v21 - 1) != -888789118 )
          __break(0x8228u);
        goto LABEL_82;
      }
    }
  }
  else
  {
    if ( a2 != 4 )
    {
      if ( a2 == 6 )
      {
        *(_BYTE *)(a3 + 209) = 0;
      }
      else if ( a2 == 8 )
      {
        *(_BYTE *)(a3 + 209) = 1;
      }
      return 0;
    }
    v23 = *(_QWORD **)(a3 + 120);
    if ( *(_BYTE *)(a3 + 207) == 1 )
    {
      v24 = (_DWORD *)v23[21];
      if ( v24 )
      {
        if ( *(v24 - 1) != 542830841 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD, __int64))v24)(v3, 0, 1);
        v25 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a3 + 120) + 168LL);
        if ( *((_DWORD *)v25 - 1) != 542830841 )
          __break(0x8228u);
        v25(v3, 1, 1);
        msleep(50);
        v23 = *(_QWORD **)(a3 + 120);
      }
      v26 = (void (__fastcall *)(__int64, __int64))v23[9];
      if ( v26 )
      {
        if ( *((_DWORD *)v26 - 1) != -1918869124 )
          __break(0x8229u);
        v26(v3, 1);
        v23 = *(_QWORD **)(a3 + 120);
      }
      v27 = (_DWORD *)v23[21];
      if ( v27 )
      {
        if ( *(v27 - 1) != 542830841 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD))v27)(v3, 0, 0);
        v23 = *(_QWORD **)(a3 + 120);
      }
    }
    if ( v23[26] )
    {
      v28 = *(_QWORD *)(a3 + 856);
      if ( !*(_DWORD *)(v28 + 184)
        || (v29 = snd_soc_component_read(*(_QWORD *)(a3 + 216)),
            v28 = *(_QWORD *)(a3 + 856),
            (unsigned __int8)(v29 & *(_BYTE *)(v28 + 188)) >> *(_BYTE *)(v28 + 189)) )
      {
        v30 = *(unsigned int *)(v28 + 360);
        if ( (_DWORD)v30 )
          snd_soc_component_update_bits(*(_QWORD *)(a3 + 216), v30, *(unsigned __int8 *)(v28 + 364), 0);
      }
    }
    else
    {
      *(_BYTE *)(a3 + 209) = 1;
      wcd_enable_curr_micbias((_QWORD *)a3, 1);
    }
    v21 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a3 + 120) + 88LL);
    if ( v21 )
    {
      v22 = v9 & 1;
      v20 = v3;
      v12 = 1;
      if ( *((_DWORD *)v21 - 1) != -888789118 )
        __break(0x8228u);
      goto LABEL_82;
    }
  }
  return 0;
}
