__int64 __fastcall wcd938x_codec_enable_hphr_pa(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x19
  __int64 v7; // x22
  unsigned int v8; // w20
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x1
  void (__fastcall *v13)(__int64, __int64, __int64); // x8
  __int64 v14; // x0
  unsigned int v15; // w21
  void (__fastcall *v16)(__int64, __int64, __int64); // x8
  __int64 v17; // x0
  void (__fastcall *v18)(__int64, __int64, __int64); // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x1
  void (__fastcall *v22)(__int64, __int64, __int64); // x8
  __int64 v23; // x0
  unsigned __int64 v30; // x9
  unsigned __int64 v33; // x9
  unsigned __int64 v36; // x10
  unsigned __int64 v39; // x10

  result = 0;
  v5 = *(_QWORD *)(a1 + 40);
  v6 = v5 - 208;
  v7 = *(_QWORD *)(*(_QWORD *)(v5 - 184) + 152LL);
  v8 = *(_DWORD *)(v7 + 264);
  if ( a3 > 3 )
  {
    if ( a3 == 4 )
    {
      v16 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3128);
      if ( v16 )
      {
        v17 = *(_QWORD *)(v7 + 3120);
        if ( *((_DWORD *)v16 - 1) != -17866579 )
          __break(0x8228u);
        v16(v17, 1, 65537);
      }
      wcd_disable_irq(v7 + 304, 14);
      v18 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3128);
      if ( v18 && *(_BYTE *)(v7 + 289) == 1 )
      {
        v19 = *(_QWORD *)(v7 + 3120);
        if ( *((_DWORD *)v18 - 1) != -17866579 )
          __break(0x8228u);
        v18(v19, 4, 0x10000);
      }
      if ( (*(_BYTE *)(v7 + 289) & 1) != 0 )
      {
        v20 = 7000;
        v21 = 7100;
      }
      else
      {
        v20 = 20000;
        v21 = 20100;
      }
      usleep_range_state(v20, v21, 2);
      snd_soc_component_update_bits(v6, 12297, 64, 0);
      blocking_notifier_call_chain(*(_QWORD *)(v7 + 256) + 976LL, 14);
      _X8 = (unsigned __int64 *)(v7 + 352);
      __asm { PRFM            #0x11, [X8] }
      do
        v33 = __ldxr(_X8);
      while ( __stxr(v33 | 0x40, _X8) );
    }
    else
    {
      if ( a3 != 8 )
        return result;
      if ( (*(_QWORD *)(v7 + 352) & 0x40) != 0 )
      {
        if ( (*(_BYTE *)(v7 + 289) & 1) != 0 )
        {
          v11 = 7000;
          v12 = 7100;
        }
        else
        {
          v11 = 20000;
          v12 = 20100;
        }
        usleep_range_state(v11, v12, 2);
        _X8 = (unsigned __int64 *)(v7 + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v39 = __ldxr(_X8);
        while ( __stxr(v39 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
      }
      blocking_notifier_call_chain(*(_QWORD *)(v7 + 256) + 976LL, 12);
      snd_soc_component_update_bits(v6, 12297, 16, 0);
      snd_soc_component_update_bits(v6, 13414, 7, 0);
      wcd_cls_h_fsm(v6, v7 + 224, 2, 4, v8);
      result = 0;
      if ( *(_BYTE *)(v7 + 290) != 1 )
        return result;
      snd_soc_component_update_bits(v6, 12391, 128, 0);
    }
    return 0;
  }
  if ( a3 != 1 )
  {
    if ( a3 != 2 )
      return result;
    if ( (*(_QWORD *)(v7 + 352) & 0x40) != 0 )
    {
      if ( (*(_BYTE *)(v7 + 289) & 1) != 0 )
      {
        v9 = 7000;
        v10 = 7100;
      }
      else
      {
        v9 = 20000;
        v10 = 20100;
      }
      usleep_range_state(v9, v10, 2);
      if ( v8 <= 5 && ((1 << v8) & 0x34) != 0 )
        snd_soc_component_update_bits(v6, 12510, 1, 0);
      _X8 = (unsigned __int64 *)(v7 + 352);
      __asm { PRFM            #0x11, [X8] }
      do
        v36 = __ldxr(_X8);
      while ( __stxr(v36 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
    }
    snd_soc_component_update_bits(v6, 12602, 2, 2);
    if ( v8 <= 8 && ((1 << v8) & 0x1C8) != 0 )
      snd_soc_component_update_bits(v6, 12296, 2, 2);
    v22 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3128);
    if ( v22 )
    {
      v23 = *(_QWORD *)(v7 + 3120);
      if ( *((_DWORD *)v22 - 1) != -17866579 )
        __break(0x8228u);
      v22(v23, 1, 0x10000);
    }
    wcd_enable_irq(v7 + 304, 14);
    return 0;
  }
  if ( *(_BYTE *)(v7 + 290) == 1 )
    snd_soc_component_update_bits(v6, 12391, 128, 128);
  v13 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3128);
  if ( v13 )
  {
    v14 = *(_QWORD *)(v7 + 3120);
    if ( *((_DWORD *)v13 - 1) != -17866579 )
      __break(0x8228u);
    v13(v14, 1, 65537);
  }
  v15 = swr_slvdev_datapath_control(*(_QWORD *)(v7 + 40), *(unsigned __int8 *)(*(_QWORD *)(v7 + 40) + 64LL), 1);
  wcd_cls_h_fsm(v6, v7 + 224, 1, 4, v8);
  wcd_clsh_set_hph_mode(v6, 1);
  if ( v8 <= 5 && ((1 << v8) & 0x34) != 0 )
    snd_soc_component_update_bits(v6, 12510, 1, 1);
  snd_soc_component_update_bits(v6, 12297, 16, 16);
  wcd_clsh_set_hph_mode(v6, v8);
  usleep_range_state(100, 110, 2);
  _X8 = (unsigned __int64 *)(v7 + 352);
  __asm { PRFM            #0x11, [X8] }
  do
    v30 = __ldxr(_X8);
  while ( __stxr(v30 | 0x40, _X8) );
  snd_soc_component_update_bits(v6, 13414, 7, 3);
  return v15;
}
