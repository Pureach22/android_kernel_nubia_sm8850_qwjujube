__int64 __fastcall wsa884x_spkr_event(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  unsigned int v10; // w8
  __int64 v11; // x3
  unsigned __int64 v19; // x10
  unsigned __int64 v22; // x10

  v3 = *(_QWORD *)(a1 + 40);
  v4 = v3 - 208;
  v5 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( a3 == 4 )
  {
    snd_soc_component_update_bits(v3 - 208, 13360, 1, 0);
    snd_soc_component_update_bits(v4, 13451, 1, 0);
    _X8 = (unsigned __int64 *)(v5 + 680);
    __asm { PRFM            #0x11, [X8] }
    do
      v19 = __ldxr(_X8);
    while ( __stxr(v19 & 0xFFFFFFFFFFFFFFFELL, _X8) );
    _X8 = (unsigned __int64 *)(v5 + 680);
    __asm { PRFM            #0x11, [X8] }
    do
      v22 = __ldxr(_X8);
    while ( __stxr(v22 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    *(_DWORD *)(v5 + 208) = 0;
    return 0;
  }
  if ( a3 != 2 )
    return 0;
  swr_slvdev_datapath_control(*(_QWORD *)(v5 + 16), *(unsigned __int8 *)(*(_QWORD *)(v5 + 16) + 64LL), 1);
  wsa884x_set_gain_parameters(v4);
  if ( *(_DWORD *)(v5 + 116) )
  {
    snd_soc_component_update_bits(v4, 13488, 240, 48);
    snd_soc_component_update_bits(v4, 13338, 2, 2);
    v6 = v4;
    v7 = 12362;
    v8 = 8;
    v9 = 8;
  }
  else
  {
    v6 = v4;
    v7 = 13488;
    v8 = 240;
    v9 = 240;
  }
  snd_soc_component_update_bits(v6, v7, v8, v9);
  if ( *(_BYTE *)(v5 + 35) != 1 )
  {
    snd_soc_component_update_bits(v4, 12433, 128, 128);
    if ( *(unsigned __int8 *)(v5 + 236) <= 5u )
      v11 = 36;
    else
      v11 = 84;
    goto LABEL_13;
  }
  snd_soc_component_update_bits(v4, 12433, 128, 0);
  v10 = *(_DWORD *)(v5 + 228) - 1;
  if ( v10 < 3 )
  {
    v11 = 84 - 16 * v10;
LABEL_13:
    snd_soc_component_update_bits(v4, 12433, 124, v11);
  }
  swr_remove_from_group(*(_QWORD *)(v5 + 16), *(unsigned __int8 *)(*(_QWORD *)(v5 + 16) + 64LL));
  if ( (*(_QWORD *)(v5 + 680) & 4) != 0 && !*(_DWORD *)(v5 + 208) )
    snd_soc_component_update_bits(v4, 13360, 1, 1);
  return 0;
}
