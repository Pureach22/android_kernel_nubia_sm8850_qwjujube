__int64 __fastcall wcd938x_codec_enable_adc(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x24
  __int64 v6; // x22
  int v7; // w0
  _BOOL4 v8; // w23
  __int64 result; // x0
  int v10; // w8
  int v11; // w9
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 v14; // x9
  __int64 v15; // x11
  __int64 v16; // x11
  __int64 v17; // x11
  int v18; // w11
  int v19; // w8
  unsigned int v21; // w8
  unsigned int v22; // w9
  __int64 v23; // x3
  __int64 v24; // x0
  __int64 v25; // x2
  unsigned int v26; // w20
  __int64 v27; // x2
  unsigned int v28; // w21
  __int64 v29; // x2
  unsigned __int64 v35; // x10
  int v36; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v37[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v38[3]; // [xsp+10h] [xbp-10h] BYREF
  char v39; // [xsp+13h] [xbp-Dh] BYREF
  _BYTE v40[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+18h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 40);
  v36 = 0;
  v6 = *(_QWORD *)(*(_QWORD *)(v5 - 184) + 152LL);
  v7 = swr_read(*(_QWORD *)(v6 + 48), *(unsigned __int8 *)(*(_QWORD *)(v6 + 48) + 64LL), 68, &v36, 1);
  v8 = (v7 | v36 & 0x40) != 0;
  if ( a3 == 8 )
  {
    *(_DWORD *)(v6 + 284) = (*(_DWORD *)(v6 + 284) - 1) & ~((*(_DWORD *)(v6 + 284) - 1) >> 31);
    wcd938x_tx_connect_port(v5 - 208, (unsigned int)*(unsigned __int8 *)(a1 + 76) + 30, 0, 0);
    result = 0;
    if ( *(_BYTE *)(a1 + 76) != 1 )
      goto LABEL_71;
    if ( (*(_QWORD *)(v6 + 352) & 0x80) == 0 )
    {
LABEL_12:
      result = 0;
      goto LABEL_71;
    }
    v12 = *(_QWORD *)(*(_QWORD *)(v5 - 184) + 152LL);
    v40[0] = 0;
    v38[0] = 0;
    if ( !(unsigned int)wcd938x_set_port_params(v5 - 208, 29, v40, &v39, v38, &v36, v37, 0) )
    {
      v13 = *(_QWORD *)(v12 + 48);
      v37[0] = *(_BYTE *)(v12 + 3199);
      swr_disconnect_port(v13, v40, 1, v38, v37);
    }
LABEL_73:
    _X8 = (unsigned __int64 *)(v6 + 352);
    __asm { PRFM            #0x11, [X8] }
    do
      v35 = __ldxr(_X8);
    while ( __stxr(v35 & 0xFFFFFFFFFFFFFF7FLL, _X8) );
    goto LABEL_12;
  }
  result = 0;
  if ( a3 != 1 )
    goto LABEL_71;
  v10 = *(_DWORD *)(v6 + 284) + 1;
  *(_DWORD *)(v6 + 284) = v10;
  if ( (*(_QWORD *)(v6 + 352) & 1) != 0 || (*(_QWORD *)(v6 + 352) & 0x200) != 0 )
  {
    v14 = *(unsigned int *)(v6 + 268);
    if ( (unsigned int)v14 >= 7 )
      goto LABEL_72;
    v11 = tx_mode_bit[v14];
    if ( (*(_QWORD *)(v6 + 352) & 2) != 0 )
      goto LABEL_16;
LABEL_15:
    if ( (*(_QWORD *)(v6 + 352) & 0x400) == 0 )
      goto LABEL_18;
    goto LABEL_16;
  }
  v11 = 0;
  if ( (*(_QWORD *)(v6 + 352) & 2) == 0 )
    goto LABEL_15;
LABEL_16:
  v15 = *(unsigned int *)(v6 + 272);
  if ( (unsigned int)v15 > 6 )
    goto LABEL_72;
  v11 |= tx_mode_bit[v15];
LABEL_18:
  if ( (*(_QWORD *)(v6 + 352) & 4) != 0 || (*(_QWORD *)(v6 + 352) & 0x800) != 0 )
  {
    v16 = *(unsigned int *)(v6 + 276);
    if ( (unsigned int)v16 <= 6 )
    {
      v11 |= tx_mode_bit[v16];
      goto LABEL_22;
    }
LABEL_72:
    __break(0x5512u);
    goto LABEL_73;
  }
LABEL_22:
  if ( (*(_QWORD *)(v6 + 352) & 8) != 0 || (*(_QWORD *)(v6 + 352) & 0x1000) != 0 )
  {
    v17 = *(unsigned int *)(v6 + 280);
    if ( (unsigned int)v17 <= 6 )
    {
      v11 |= tx_mode_bit[v17];
      goto LABEL_26;
    }
    goto LABEL_72;
  }
LABEL_26:
  if ( v11 )
  {
    v18 = 9600000;
    if ( (v11 & 7) == 0 )
    {
      if ( (v11 & 8) != 0 )
      {
        v18 = 4800000;
      }
      else if ( (v11 & 0x10) != 0 )
      {
        v18 = 1200000;
      }
      else
      {
        v18 = 600000;
      }
    }
  }
  else
  {
    v18 = 9600000;
  }
  v19 = v18 * v10;
  if ( v19 >= 9600000 )
    v19 = 9600000;
  if ( v19 > 2399999 )
  {
    if ( v19 == 2400000 )
    {
      _ZF = !v8;
      v21 = 48;
      v22 = 3;
      goto LABEL_57;
    }
    if ( v19 == 4800000 )
    {
      if ( v8 )
        v23 = 1;
      else
        v23 = 16;
      v24 = v5 - 208;
      if ( v8 )
        v25 = 15;
      else
        v25 = 240;
      if ( v8 )
        v26 = 16;
      else
        v26 = 1;
      goto LABEL_66;
    }
    goto LABEL_51;
  }
  if ( v19 == 600000 )
  {
    _ZF = !v8;
    v21 = 96;
    v22 = 6;
    goto LABEL_57;
  }
  if ( v19 != 1200000 )
  {
LABEL_51:
    if ( v8 )
      v27 = 15;
    else
      v27 = 240;
    snd_soc_component_update_bits(v5 - 208, 13317, v27, 0);
    v28 = swr_slvdev_datapath_control(*(_QWORD *)(v6 + 48), *(unsigned __int8 *)(*(_QWORD *)(v6 + 48) + 64LL), 1);
    v26 = 0;
    goto LABEL_67;
  }
  _ZF = !v8;
  v21 = 80;
  v22 = 5;
LABEL_57:
  if ( _ZF )
    v23 = v21;
  else
    v23 = v22;
  if ( _ZF )
    v25 = 240;
  else
    v25 = 15;
  v24 = v5 - 208;
  if ( _ZF )
    v26 = v22;
  else
    v26 = v21;
LABEL_66:
  snd_soc_component_update_bits(v24, 13317, v25, v23);
  v28 = swr_slvdev_datapath_control(*(_QWORD *)(v6 + 48), *(unsigned __int8 *)(*(_QWORD *)(v6 + 48) + 64LL), 1);
LABEL_67:
  if ( v8 )
    v29 = 240;
  else
    v29 = 15;
  snd_soc_component_update_bits(v5 - 208, 13317, v29, v26);
  result = v28;
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
