__int64 __fastcall wcd_measure_adc_once(_QWORD *a1, int a2)
{
  __int64 v4; // x9
  unsigned int v5; // w8
  char v6; // w0
  __int64 v7; // x1
  int v8; // w23
  __int64 v9; // x1
  __int64 v10; // x1
  __int64 v11; // x1
  __int64 v12; // x1
  int v13; // w22
  __int64 v14; // x8
  char v15; // w0
  char v16; // w0
  unsigned int v17; // w22
  _BOOL4 v18; // w24
  __int64 v19; // x1
  char v21; // w0
  int v22; // w24
  __int64 v23; // x9
  _DWORD *v24; // x9
  int v25; // w9
  char v26; // w0
  int v27; // w9
  int v28; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[107];
  v5 = *(_DWORD *)(v4 + 744);
  if ( v5 )
  {
    snd_soc_component_update_bits(a1[27], v5, *(unsigned __int8 *)(v4 + 748), 0);
    v4 = a1[107];
  }
  if ( *(_DWORD *)(v4 + 664) )
  {
    v6 = snd_soc_component_read(a1[27]);
    v4 = a1[107];
    v7 = *(unsigned int *)(v4 + 664);
    v8 = (unsigned __int8)(v6 & *(_BYTE *)(v4 + 668)) >> *(_BYTE *)(v4 + 669);
    if ( (_DWORD)v7 )
    {
      snd_soc_component_update_bits(a1[27], v7, *(unsigned __int8 *)(v4 + 668), 0);
      v4 = a1[107];
    }
    v9 = *(unsigned int *)(v4 + 184);
    if ( !(_DWORD)v9 )
      goto LABEL_8;
  }
  else
  {
    v8 = 234;
    v9 = *(unsigned int *)(v4 + 184);
    if ( !(_DWORD)v9 )
      goto LABEL_8;
  }
  snd_soc_component_update_bits(a1[27], v9, *(unsigned __int8 *)(v4 + 188), 0);
  v4 = a1[107];
LABEL_8:
  v10 = *(unsigned int *)(v4 + 536);
  if ( (_DWORD)v10 )
  {
    snd_soc_component_update_bits(
      a1[27],
      v10,
      *(unsigned __int8 *)(v4 + 540),
      (unsigned int)(a2 << *(_BYTE *)(v4 + 541)));
    v4 = a1[107];
  }
  v11 = *(unsigned int *)(v4 + 184);
  if ( (_DWORD)v11 )
  {
    snd_soc_component_update_bits(
      a1[27],
      v11,
      *(unsigned __int8 *)(v4 + 188),
      (unsigned int)(1 << *(_BYTE *)(v4 + 189)));
    v4 = a1[107];
  }
  v12 = *(unsigned int *)(v4 + 664);
  if ( (_DWORD)v12 )
    snd_soc_component_update_bits(
      a1[27],
      v12,
      *(unsigned __int8 *)(v4 + 668),
      (unsigned int)(1 << *(_BYTE *)(v4 + 669)));
  v13 = 5;
  while ( 1 )
  {
    usleep_range_state(600, 610, 2);
    v14 = a1[107];
    if ( *(_DWORD *)(v14 + 696) )
    {
      v15 = snd_soc_component_read(a1[27]);
      v14 = a1[107];
      if ( !((unsigned __int8)(v15 & *(_BYTE *)(v14 + 700)) >> *(_BYTE *)(v14 + 701)) )
      {
        if ( !*(_DWORD *)(v14 + 680) )
          break;
        v16 = snd_soc_component_read(a1[27]);
        v14 = a1[107];
        if ( (unsigned __int8)(v16 & *(_BYTE *)(v14 + 684)) >> *(_BYTE *)(v14 + 685) )
          break;
      }
    }
    if ( --v13 == -1 )
    {
      v17 = 0;
      v18 = 1;
      v19 = *(unsigned int *)(v14 + 664);
      if ( !(_DWORD)v19 )
        goto LABEL_23;
      goto LABEL_22;
    }
  }
  if ( *(_DWORD *)(v14 + 712) )
  {
    v21 = snd_soc_component_read(a1[27]);
    v14 = a1[107];
    v22 = 125 * ((unsigned __int8)(v21 & *(_BYTE *)(v14 + 716)) >> *(_BYTE *)(v14 + 717));
  }
  else
  {
    v22 = 29250;
  }
  v23 = a1[15];
  v28 = 0;
  v24 = *(_DWORD **)(v23 + 24);
  if ( v24 )
  {
    if ( *(v24 - 1) != -2034283555 )
      __break(0x8229u);
    ((void (__fastcall *)(_QWORD *, int *))v24)(a1, &v28);
    v25 = v28;
    v14 = a1[107];
  }
  else if ( *(_DWORD *)(v14 + 728) )
  {
    v26 = snd_soc_component_read(a1[27]);
    v14 = a1[107];
    v25 = 50 * ((unsigned __int8)(v26 & *(_BYTE *)(v14 + 732)) >> *(_BYTE *)(v14 + 733)) + 1000;
  }
  else
  {
    v25 = 12700;
  }
  v27 = v25 * v22;
  v18 = v13 < 1;
  v17 = v27 / 18000;
  v19 = *(unsigned int *)(v14 + 664);
  if ( (_DWORD)v19 )
LABEL_22:
    snd_soc_component_update_bits(
      a1[27],
      v19,
      *(unsigned __int8 *)(v14 + 668),
      (unsigned int)(v8 << *(_BYTE *)(v14 + 669)));
LABEL_23:
  if ( v18 )
  {
    printk(&unk_E636, "wcd_measure_adc_once");
    v17 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
