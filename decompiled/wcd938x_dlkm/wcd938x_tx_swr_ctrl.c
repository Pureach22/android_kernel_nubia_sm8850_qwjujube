__int64 __fastcall wcd938x_tx_swr_ctrl(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x25
  __int64 v6; // x23
  int v7; // w0
  _BOOL4 v8; // w24
  unsigned __int64 v9; // x8
  unsigned int v10; // w8
  int v11; // w21
  __int64 v12; // x22
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 result; // x0
  __int64 v17; // x0
  __int64 v18; // x2
  int v19; // w8
  __int64 v20; // x8
  __int64 v21; // x10
  __int64 v22; // x10
  __int64 v23; // x10
  int v24; // w10
  int v25; // w8
  __int64 v26; // x3
  int v27; // w9
  unsigned int v29; // w8
  unsigned int v30; // w9
  __int64 v31; // x2
  unsigned int v32; // w0
  __int64 v33; // x8
  unsigned int v34; // w20
  __int64 v35; // x3
  bool v36; // zf
  unsigned int v37; // w8
  unsigned int v38; // w9
  __int64 v39; // x2
  unsigned __int64 v42; // x10
  unsigned __int64 v45; // x10
  unsigned __int64 v48; // x10
  unsigned __int64 v51; // x10
  unsigned __int64 v54; // x10
  unsigned __int64 v60; // x9
  unsigned __int64 v63; // x10
  unsigned __int64 v66; // x10
  unsigned __int64 v69; // x10
  unsigned __int64 v72; // x10
  int v73; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v74[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v75[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v76[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v77[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v78; // [xsp+18h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 40);
  v73 = 0;
  v6 = *(_QWORD *)(*(_QWORD *)(v5 - 184) + 152LL);
  v7 = swr_read(*(_QWORD *)(v6 + 48), *(unsigned __int8 *)(*(_QWORD *)(v6 + 48) + 64LL), 68, &v73, 1);
  v8 = (v7 | v73 & 0x40) != 0;
  if ( strnstr(*(_QWORD *)(a1 + 8), "ADC", 4) )
  {
    v9 = *(unsigned __int8 *)(a1 + 76) - 30LL;
    if ( v9 >= 4 )
      goto LABEL_100;
    v10 = *(_DWORD *)(v6 + 4 * v9 + 268) - 4;
    if ( v10 > 2 )
      v11 = 9600000;
    else
      v11 = dword_205F4[v10];
  }
  else
  {
    v11 = 0;
  }
  if ( a3 == 8 )
  {
    if ( strnstr(*(_QWORD *)(a1 + 8), "ADC", 4) )
    {
      if ( strnstr(*(_QWORD *)(a1 + 8), "ADC1", 5) )
      {
        _X8 = (unsigned __int64 *)(v6 + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v45 = __ldxr(_X8);
        while ( __stxr(v45 & 0xFFFFFFFFFFFFFFFELL, _X8) );
        _X8 = (unsigned __int64 *)(v6 + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v48 = __ldxr(_X8);
        while ( __stxr(v48 & 0xFFFFFFFFFFFFFDFFLL, _X8) );
      }
      else if ( strnstr(*(_QWORD *)(a1 + 8), "ADC2", 5) )
      {
        _X8 = (unsigned __int64 *)(v6 + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v51 = __ldxr(_X8);
        while ( __stxr(v51 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
        _X8 = (unsigned __int64 *)(v6 + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v54 = __ldxr(_X8);
        while ( __stxr(v54 & 0xFFFFFFFFFFFFFBFFLL, _X8) );
      }
      else if ( strnstr(*(_QWORD *)(a1 + 8), "ADC3", 5) )
      {
        _X8 = (unsigned __int64 *)(v6 + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v63 = __ldxr(_X8);
        while ( __stxr(v63 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
        _X8 = (unsigned __int64 *)(v6 + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v66 = __ldxr(_X8);
        while ( __stxr(v66 & 0xFFFFFFFFFFFFF7FFLL, _X8) );
      }
      else if ( strnstr(*(_QWORD *)(a1 + 8), "ADC4", 5) )
      {
        _X8 = (unsigned __int64 *)(v6 + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v69 = __ldxr(_X8);
        while ( __stxr(v69 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
        _X8 = (unsigned __int64 *)(v6 + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v72 = __ldxr(_X8);
        while ( __stxr(v72 & 0xFFFFFFFFFFFFEFFFLL, _X8) );
      }
    }
    if ( !strnstr(*(_QWORD *)(a1 + 8), "ADC", 4) )
    {
LABEL_79:
      v32 = swr_slvdev_datapath_control(*(_QWORD *)(v6 + 48), *(unsigned __int8 *)(*(_QWORD *)(v6 + 48) + 64LL), 0);
      v33 = *(_QWORD *)(a1 + 8);
      v34 = v32;
      if ( !strnstr(v33, "ADC", 4) )
      {
LABEL_98:
        result = v34;
        goto LABEL_99;
      }
      v35 = 0;
      if ( v11 > 2399999 )
      {
        if ( v11 != 2400000 )
        {
          if ( v11 == 4800000 )
          {
            if ( v8 )
              v35 = 16;
            else
              v35 = 1;
          }
          goto LABEL_94;
        }
        v36 = !v8;
        v37 = 3;
        v38 = 48;
      }
      else if ( v11 == 600000 )
      {
        v36 = !v8;
        v37 = 6;
        v38 = 96;
      }
      else
      {
        if ( v11 != 1200000 )
          goto LABEL_94;
        v36 = !v8;
        v37 = 5;
        v38 = 80;
      }
      if ( v36 )
        v35 = v37;
      else
        v35 = v38;
LABEL_94:
      if ( v8 )
        v39 = 240;
      else
        v39 = 15;
      snd_soc_component_update_bits(v5 - 208, 13317, v39, v35);
      goto LABEL_98;
    }
    if ( (*(_QWORD *)(v6 + 352) & 1) != 0 || (*(_QWORD *)(v6 + 352) & 0x200) != 0 )
    {
      v20 = *(unsigned int *)(v6 + 268);
      if ( (unsigned int)v20 > 6 )
        goto LABEL_100;
      v19 = tx_mode_bit[v20];
      if ( (*(_QWORD *)(v6 + 352) & 2) != 0 )
        goto LABEL_37;
    }
    else
    {
      v19 = 0;
      if ( (*(_QWORD *)(v6 + 352) & 2) != 0 )
      {
LABEL_37:
        v21 = *(unsigned int *)(v6 + 272);
        if ( (unsigned int)v21 > 6 )
          goto LABEL_100;
        v19 |= tx_mode_bit[v21];
LABEL_39:
        if ( (*(_QWORD *)(v6 + 352) & 4) != 0 || (*(_QWORD *)(v6 + 352) & 0x800) != 0 )
        {
          v22 = *(unsigned int *)(v6 + 276);
          if ( (unsigned int)v22 > 6 )
            goto LABEL_100;
          v19 |= tx_mode_bit[v22];
        }
        if ( (*(_QWORD *)(v6 + 352) & 8) == 0 && (*(_QWORD *)(v6 + 352) & 0x1000) == 0 )
        {
LABEL_47:
          if ( v19 )
          {
            v24 = 9600000;
            if ( (v19 & 7) == 0 )
            {
              if ( (v19 & 8) != 0 )
              {
                v24 = 4800000;
              }
              else if ( (v19 & 0x10) != 0 )
              {
                v24 = 1200000;
              }
              else
              {
                v24 = 600000;
              }
            }
          }
          else
          {
            v24 = 9600000;
          }
          v25 = *(_DWORD *)(v6 + 284);
          v26 = 0;
          if ( v25 * v24 >= 9600000 )
            v27 = 9600000;
          else
            v27 = v25 * v24;
          if ( v25 )
            v11 = v27;
          else
            v11 = v24;
          if ( v11 > 2399999 )
          {
            if ( v11 != 2400000 )
            {
              if ( v11 == 4800000 )
              {
                if ( v8 )
                  v26 = 1;
                else
                  v26 = 16;
              }
              goto LABEL_75;
            }
            _ZF = !v8;
            v29 = 48;
            v30 = 3;
          }
          else if ( v11 == 600000 )
          {
            _ZF = !v8;
            v29 = 96;
            v30 = 6;
          }
          else
          {
            if ( v11 != 1200000 )
              goto LABEL_75;
            _ZF = !v8;
            v29 = 80;
            v30 = 5;
          }
          if ( _ZF )
            v26 = v29;
          else
            v26 = v30;
LABEL_75:
          if ( v8 )
            v31 = 15;
          else
            v31 = 240;
          snd_soc_component_update_bits(v5 - 208, 13317, v31, v26);
          goto LABEL_79;
        }
        v23 = *(unsigned int *)(v6 + 280);
        if ( (unsigned int)v23 <= 6 )
        {
          v19 |= tx_mode_bit[v23];
          goto LABEL_47;
        }
LABEL_100:
        __break(0x5512u);
      }
    }
    if ( (*(_QWORD *)(v6 + 352) & 0x400) == 0 )
      goto LABEL_39;
    goto LABEL_37;
  }
  if ( a3 == 1 )
  {
    if ( *(_BYTE *)(a1 + 76) == 31
      && (snd_soc_component_read(v5 - 208, 12583) & 0x80) == 0
      && (*(_BYTE *)(v6 + 291) & 1) == 0 )
    {
      v12 = *(_QWORD *)(*(_QWORD *)(v5 - 184) + 152LL);
      v77[0] = 0;
      v76[0] = 0;
      v75[0] = 0;
      if ( !(unsigned int)wcd938x_set_port_params(v5 - 208, 29, v77, v76, v75, &v73, v74, 0) )
      {
        v13 = *(_QWORD *)(v12 + 48);
        v73 = 4800000;
        v74[0] = *(_BYTE *)(v12 + 3199);
        swr_connect_port(v13, v77, 1, v75, &v73, v76, v74);
      }
      _X8 = (unsigned __int64 *)(v6 + 352);
      __asm { PRFM            #0x11, [X8] }
      do
        v60 = __ldxr(_X8);
      while ( __stxr(v60 | 0x80, _X8) );
    }
    v14 = strnstr(*(_QWORD *)(a1 + 8), "ADC", 4);
    v15 = *(unsigned __int8 *)(a1 + 76);
    if ( v14 )
    {
      _X9 = (unsigned __int64 *)(v6 + 352 + 8LL * ((unsigned int)(v15 - 30) >> 6));
      __asm { PRFM            #0x11, [X9] }
      do
        v42 = __ldxr(_X9);
      while ( __stxr(v42 | (1LL << ((unsigned __int8)v15 - 30)), _X9) );
      v15 = *(unsigned __int8 *)(a1 + 76);
      v17 = v5 - 208;
      v18 = (unsigned int)v11;
    }
    else
    {
      v17 = v5 - 208;
      v18 = 2400000;
    }
    wcd938x_tx_connect_port(v17, v15, v18, 1);
    result = 0;
  }
  else
  {
    result = 0;
  }
LABEL_99:
  _ReadStatusReg(SP_EL0);
  return result;
}
