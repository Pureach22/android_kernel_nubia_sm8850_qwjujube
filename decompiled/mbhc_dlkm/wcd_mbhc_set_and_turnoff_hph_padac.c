__int64 __fastcall wcd_mbhc_set_and_turnoff_hph_padac(_QWORD *a1)
{
  __int64 v1; // x8
  char v3; // w0
  __int64 v4; // x8
  unsigned int v5; // w20
  char v6; // w0
  __int64 v7; // x8
  __int64 v8; // x1
  __int64 v9; // x1
  __int64 v10; // x1
  __int64 result; // x0
  __int64 (__fastcall *v12)(_QWORD); // x8
  _DWORD *v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  _DWORD *v16; // x8
  unsigned __int64 v19; // x9
  unsigned __int64 v22; // x9
  unsigned __int64 v29; // x9
  unsigned __int64 v32; // x9

  v1 = a1[107];
  if ( *(_DWORD *)(v1 + 408) )
  {
    v3 = snd_soc_component_read(a1[27]);
    v4 = a1[107];
    v5 = 1000 * (unsigned __int8)(((unsigned __int8)(v3 & *(_BYTE *)(v4 + 412)) >> *(_BYTE *)(v4 + 413)) + 1);
    if ( !*(_DWORD *)(v4 + 456) )
      goto LABEL_25;
LABEL_5:
    v6 = snd_soc_component_read(a1[27]);
    v7 = a1[107];
    if ( !((unsigned __int8)(v6 & *(_BYTE *)(v7 + 460)) >> *(_BYTE *)(v7 + 461)) )
      goto LABEL_11;
    goto LABEL_25;
  }
  v5 = 235000;
  if ( *(_DWORD *)(v1 + 456) )
    goto LABEL_5;
LABEL_25:
  _X8 = a1 + 43;
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 | 1, _X8) );
  _X8 = a1 + 43;
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 | 2, _X8) );
  v7 = a1[107];
  v8 = *(unsigned int *)(v7 + 600);
  if ( (_DWORD)v8 )
  {
    snd_soc_component_update_bits(a1[27], v8, *(unsigned __int8 *)(v7 + 604), 0);
    v7 = a1[107];
  }
  v9 = *(unsigned int *)(v7 + 616);
  if ( (_DWORD)v9 )
  {
    snd_soc_component_update_bits(a1[27], v9, *(unsigned __int8 *)(v7 + 620), 0);
    v7 = a1[107];
  }
LABEL_11:
  v10 = *(unsigned int *)(v7 + 456);
  if ( (_DWORD)v10 )
    snd_soc_component_update_bits(a1[27], v10, *(unsigned __int8 *)(v7 + 460), 0);
  result = usleep_range_state(v5, v5 + 50, 2);
  v12 = *(__int64 (__fastcall **)(_QWORD))(a1[15] + 288LL);
  if ( v12 )
  {
    if ( *((_DWORD *)v12 - 1) != -9629763 )
      __break(0x8228u);
    result = v12(a1);
    if ( (result & 1) != 0 )
    {
      result = usleep_range_state(20000, 20100, 2);
      _X8 = a1 + 44;
      __asm { PRFM            #0x11, [X8] }
      do
        v29 = __ldxr(_X8);
      while ( __stxr(v29 | 1, _X8) );
      _X8 = a1 + 44;
      __asm { PRFM            #0x11, [X8] }
      do
        v32 = __ldxr(_X8);
      while ( __stxr(v32 | 2, _X8) );
      v13 = *(_DWORD **)(a1[15] + 280LL);
      if ( v13 )
      {
        v14 = a1[27];
        if ( *(v13 - 1) != -643174803 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD))v13)(v14, 0, 0);
        v15 = a1[27];
        v16 = *(_DWORD **)(a1[15] + 280LL);
        if ( *(v16 - 1) != -643174803 )
          __break(0x8228u);
        return ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v16)(v15, 0, 1);
      }
    }
  }
  return result;
}
