__int64 __fastcall wcd939x_tx_swr_ctrl(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x25
  __int64 v6; // x23
  int v7; // w0
  _BOOL4 v8; // w24
  unsigned __int64 v9; // x8
  unsigned int v10; // w8
  int v11; // w21
  __int64 v12; // x0
  int v13; // w8
  __int64 v14; // x22
  __int64 v15; // x0
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x9
  __int64 v18; // x8
  __int64 result; // x0
  __int64 v20; // x1
  __int64 v21; // x0
  __int64 v22; // x2
  int v23; // w8
  __int64 v24; // x8
  __int64 v25; // x10
  __int64 v26; // x10
  __int64 v27; // x10
  int v28; // w10
  int v29; // w8
  __int64 v30; // x3
  int v31; // w9
  unsigned int v33; // w8
  unsigned int v34; // w9
  __int64 v35; // x2
  unsigned int v36; // w0
  __int64 v37; // x8
  unsigned int v38; // w20
  __int64 v39; // x3
  bool v40; // zf
  unsigned int v41; // w8
  unsigned int v42; // w9
  __int64 v43; // x2
  unsigned __int64 v46; // x10
  unsigned __int64 v49; // x10
  unsigned __int64 v52; // x10
  unsigned __int64 v55; // x10
  unsigned __int64 v58; // x10
  unsigned __int64 v64; // x9
  unsigned __int64 v67; // x10
  unsigned __int64 v70; // x10
  unsigned __int64 v73; // x10
  unsigned __int64 v76; // x10
  int v77; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v78[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v79[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v80[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v81[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v82; // [xsp+18h] [xbp-8h]

  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 40);
  v77 = 0;
  v6 = *(_QWORD *)(*(_QWORD *)(v5 - 184) + 152LL);
  v7 = swr_read(*(_QWORD *)(v6 + 48), *(unsigned __int8 *)(*(_QWORD *)(v6 + 48) + 64LL), 68, &v77, 1);
  v8 = (v7 | v77 & 0x40) != 0;
  if ( strnstr(*(_QWORD *)(a1 + 8), "ADC", 4) )
  {
    v9 = *(unsigned __int8 *)(a1 + 76);
    if ( v9 >= 4 )
      goto LABEL_100;
    v10 = *(_DWORD *)(v6 + 4 * v9 + 288) - 4;
    if ( v10 > 2 )
      v11 = 9600000;
    else
      v11 = dword_26834[v10];
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
        _X8 = (unsigned __int64 *)(v6 + 376);
        __asm { PRFM            #0x11, [X8] }
        do
          v49 = __ldxr(_X8);
        while ( __stxr(v49 & 0xFFFFFFFFFFFFFFFELL, _X8) );
        _X8 = (unsigned __int64 *)(v6 + 376);
        __asm { PRFM            #0x11, [X8] }
        do
          v52 = __ldxr(_X8);
        while ( __stxr(v52 & 0xFFFFFFFFFFFFFDFFLL, _X8) );
      }
      else if ( strnstr(*(_QWORD *)(a1 + 8), "ADC2", 5) )
      {
        _X8 = (unsigned __int64 *)(v6 + 376);
        __asm { PRFM            #0x11, [X8] }
        do
          v55 = __ldxr(_X8);
        while ( __stxr(v55 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
        _X8 = (unsigned __int64 *)(v6 + 376);
        __asm { PRFM            #0x11, [X8] }
        do
          v58 = __ldxr(_X8);
        while ( __stxr(v58 & 0xFFFFFFFFFFFFFBFFLL, _X8) );
      }
      else if ( strnstr(*(_QWORD *)(a1 + 8), "ADC3", 5) )
      {
        _X8 = (unsigned __int64 *)(v6 + 376);
        __asm { PRFM            #0x11, [X8] }
        do
          v67 = __ldxr(_X8);
        while ( __stxr(v67 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
        _X8 = (unsigned __int64 *)(v6 + 376);
        __asm { PRFM            #0x11, [X8] }
        do
          v70 = __ldxr(_X8);
        while ( __stxr(v70 & 0xFFFFFFFFFFFFF7FFLL, _X8) );
      }
      else if ( strnstr(*(_QWORD *)(a1 + 8), "ADC4", 5) )
      {
        _X8 = (unsigned __int64 *)(v6 + 376);
        __asm { PRFM            #0x11, [X8] }
        do
          v73 = __ldxr(_X8);
        while ( __stxr(v73 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
        _X8 = (unsigned __int64 *)(v6 + 376);
        __asm { PRFM            #0x11, [X8] }
        do
          v76 = __ldxr(_X8);
        while ( __stxr(v76 & 0xFFFFFFFFFFFFEFFFLL, _X8) );
      }
    }
    if ( !strnstr(*(_QWORD *)(a1 + 8), "ADC", 4) )
    {
LABEL_79:
      v36 = swr_slvdev_datapath_control(*(_QWORD *)(v6 + 48), *(unsigned __int8 *)(*(_QWORD *)(v6 + 48) + 64LL), 0);
      v37 = *(_QWORD *)(a1 + 8);
      v38 = v36;
      if ( !strnstr(v37, "ADC", 4) )
      {
LABEL_98:
        result = v38;
        goto LABEL_99;
      }
      v39 = 0;
      if ( v11 > 2399999 )
      {
        if ( v11 != 2400000 )
        {
          if ( v11 == 4800000 )
          {
            if ( v8 )
              v39 = 16;
            else
              v39 = 1;
          }
          goto LABEL_94;
        }
        v40 = !v8;
        v41 = 3;
        v42 = 48;
      }
      else if ( v11 == 600000 )
      {
        v40 = !v8;
        v41 = 6;
        v42 = 96;
      }
      else
      {
        if ( v11 != 1200000 )
          goto LABEL_94;
        v40 = !v8;
        v41 = 5;
        v42 = 80;
      }
      if ( v40 )
        v39 = v41;
      else
        v39 = v42;
LABEL_94:
      if ( v8 )
        v43 = 240;
      else
        v43 = 15;
      snd_soc_component_update_bits(v5 - 208, 13317, v43, v39);
      goto LABEL_98;
    }
    if ( (*(_QWORD *)(v6 + 376) & 1) != 0 || (*(_QWORD *)(v6 + 376) & 0x200) != 0 )
    {
      v24 = *(unsigned int *)(v6 + 288);
      if ( (unsigned int)v24 > 6 )
        goto LABEL_100;
      v23 = tx_mode_bit[v24];
      if ( (*(_QWORD *)(v6 + 376) & 2) != 0 )
        goto LABEL_37;
    }
    else
    {
      v23 = 0;
      if ( (*(_QWORD *)(v6 + 376) & 2) != 0 )
      {
LABEL_37:
        v25 = *(unsigned int *)(v6 + 292);
        if ( (unsigned int)v25 > 6 )
          goto LABEL_100;
        v23 |= tx_mode_bit[v25];
LABEL_39:
        if ( (*(_QWORD *)(v6 + 376) & 4) != 0 || (*(_QWORD *)(v6 + 376) & 0x800) != 0 )
        {
          v26 = *(unsigned int *)(v6 + 296);
          if ( (unsigned int)v26 > 6 )
            goto LABEL_100;
          v23 |= tx_mode_bit[v26];
        }
        if ( (*(_QWORD *)(v6 + 376) & 8) == 0 && (*(_QWORD *)(v6 + 376) & 0x1000) == 0 )
        {
LABEL_47:
          if ( v23 )
          {
            v28 = 9600000;
            if ( (v23 & 7) == 0 )
            {
              if ( (v23 & 8) != 0 )
              {
                v28 = 4800000;
              }
              else if ( (v23 & 0x10) != 0 )
              {
                v28 = 1200000;
              }
              else
              {
                v28 = 600000;
              }
            }
          }
          else
          {
            v28 = 9600000;
          }
          v29 = *(_DWORD *)(v6 + 304);
          v30 = 0;
          if ( v29 * v28 >= 9600000 )
            v31 = 9600000;
          else
            v31 = v29 * v28;
          if ( v29 )
            v11 = v31;
          else
            v11 = v28;
          if ( v11 > 2399999 )
          {
            if ( v11 != 2400000 )
            {
              if ( v11 == 4800000 )
              {
                if ( v8 )
                  v30 = 1;
                else
                  v30 = 16;
              }
              goto LABEL_75;
            }
            _ZF = !v8;
            v33 = 48;
            v34 = 3;
          }
          else if ( v11 == 600000 )
          {
            _ZF = !v8;
            v33 = 96;
            v34 = 6;
          }
          else
          {
            if ( v11 != 1200000 )
              goto LABEL_75;
            _ZF = !v8;
            v33 = 80;
            v34 = 5;
          }
          if ( _ZF )
            v30 = v33;
          else
            v30 = v34;
LABEL_75:
          if ( v8 )
            v35 = 15;
          else
            v35 = 240;
          snd_soc_component_update_bits(v5 - 208, 13317, v35, v30);
          goto LABEL_79;
        }
        v27 = *(unsigned int *)(v6 + 300);
        if ( (unsigned int)v27 <= 6 )
        {
          v23 |= tx_mode_bit[v27];
          goto LABEL_47;
        }
LABEL_100:
        __break(0x5512u);
      }
    }
    if ( (*(_QWORD *)(v6 + 376) & 0x400) == 0 )
      goto LABEL_39;
    goto LABEL_37;
  }
  if ( a3 == 1 )
  {
    v12 = strnstr(*(_QWORD *)(a1 + 8), "ADC", 4);
    v13 = *(unsigned __int8 *)(a1 + 76);
    if ( v12 )
    {
      if ( v13 == 1 && (snd_soc_component_read(v5 - 208, 12583) & 0x38) == 0x10 && (*(_BYTE *)(v6 + 311) & 1) == 0 )
      {
        v14 = *(_QWORD *)(*(_QWORD *)(v5 - 184) + 152LL);
        v81[0] = 0;
        v80[0] = 0;
        v79[0] = 0;
        if ( !(unsigned int)wcd939x_set_port_params(v5 - 208, 29, v81, v80, v79, &v77, v78, 0) )
        {
          v15 = *(_QWORD *)(v14 + 48);
          v77 = 4800000;
          v78[0] = *(_BYTE *)(v14 + 3223);
          swr_connect_port(v15, v81, 1, v79, &v77, v80, v78);
        }
        _X8 = (unsigned __int64 *)(v6 + 376);
        __asm { PRFM            #0x11, [X8] }
        do
          v64 = __ldxr(_X8);
        while ( __stxr(v64 | 0x80, _X8) );
      }
      v16 = *(unsigned __int8 *)(a1 + 76);
      v17 = v16 >> 6;
      v18 = 1LL << v16;
      _X9 = (unsigned __int64 *)(v6 + 376 + 8 * v17);
      __asm { PRFM            #0x11, [X9] }
      do
        v46 = __ldxr(_X9);
      while ( __stxr(v46 | v18, _X9) );
      v21 = v5 - 208;
      v22 = (unsigned int)v11;
      v20 = (unsigned int)*(unsigned __int8 *)(a1 + 76) + 30;
    }
    else
    {
      v20 = (unsigned int)(v13 + 34);
      v21 = v5 - 208;
      v22 = 2400000;
    }
    wcd939x_tx_connect_port(v21, v20, v22, 1);
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
