__int64 __fastcall wcd939x_codec_enable_hphr_pa(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x20
  __int64 v7; // x19
  unsigned int v8; // w21
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x1
  void (__fastcall *v13)(__int64, __int64, __int64); // x8
  __int64 v14; // x0
  unsigned int v15; // w22
  __int64 v17; // x2
  void (__fastcall *v18)(__int64, __int64, __int64); // x8
  __int64 v19; // x0
  void (__fastcall *v20)(__int64, __int64, __int64); // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x1
  void (__fastcall *v24)(__int64, __int64, __int64); // x8
  __int64 v25; // x0
  unsigned __int64 v31; // x9
  unsigned __int64 v34; // x9
  unsigned __int64 v37; // x10
  unsigned __int64 v40; // x10

  result = 0;
  v5 = *(_QWORD *)(a1 + 40);
  v6 = v5 - 208;
  v7 = *(_QWORD *)(*(_QWORD *)(v5 - 184) + 152LL);
  v8 = *(_DWORD *)(v7 + 284);
  if ( a3 > 3 )
  {
    if ( a3 == 4 )
    {
      v18 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3152);
      if ( v18 )
      {
        v19 = *(_QWORD *)(v7 + 3144);
        if ( *((_DWORD *)v18 - 1) != -17866579 )
          __break(0x8228u);
        v18(v19, 1, 65537);
      }
      wcd_disable_irq(v7 + 328, 12);
      v20 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3152);
      if ( v20 && *(_BYTE *)(v7 + 309) == 1 )
      {
        v21 = *(_QWORD *)(v7 + 3144);
        if ( *((_DWORD *)v20 - 1) != -17866579 )
          __break(0x8228u);
        v20(v21, 4, 0x10000);
      }
      if ( (*(_BYTE *)(v7 + 309) & 1) != 0 )
      {
        v22 = 7000;
        v23 = 7100;
      }
      else
      {
        v22 = 20000;
        v23 = 20100;
      }
      usleep_range_state(v22, v23, 2);
      snd_soc_component_update_bits(v6, 12297, 64, 0);
      blocking_notifier_call_chain(*(_QWORD *)(v7 + 256) + 976LL, 14);
      _X8 = (unsigned __int64 *)(v7 + 376);
      __asm { PRFM            #0x11, [X8] }
      do
        v34 = __ldxr(_X8);
      while ( __stxr(v34 | 0x40, _X8) );
    }
    else
    {
      if ( a3 != 8 )
        return result;
      if ( (*(_QWORD *)(v7 + 376) & 0x40) != 0 )
      {
        if ( (*(_BYTE *)(v7 + 309) & 1) != 0 )
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
        _X8 = (unsigned __int64 *)(v7 + 376);
        __asm { PRFM            #0x11, [X8] }
        do
          v40 = __ldxr(_X8);
        while ( __stxr(v40 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
      }
      blocking_notifier_call_chain(*(_QWORD *)(v7 + 256) + 976LL, 12);
      snd_soc_component_update_bits(v6, 12297, 16, 0);
      snd_soc_component_update_bits(v6, 13414, 7, 0);
      if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 256) + 112LL) + 88LL)
        && (snd_soc_component_read(v6, 12297) & 0xC0) == 0
        && !*(_DWORD *)(v7 + 304) )
      {
        wcd_usbss_audio_config(0, 0, 1);
      }
      wcd_cls_h_fsm(v6, v7 + 224, 2, 4, v8);
      if ( *(_BYTE *)(v7 + 310) == 1 )
        snd_soc_component_update_bits(v6, 12391, 128, 0);
    }
    return 0;
  }
  if ( a3 != 1 )
  {
    if ( a3 != 2 )
      return result;
    if ( (*(_QWORD *)(v7 + 376) & 0x40) != 0 )
    {
      if ( (*(_BYTE *)(v7 + 309) & 1) != 0 )
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
      if ( v8 <= 5 && ((1 << v8) & 0x34) != 0 && !*(_BYTE *)(v7 + 280) )
        snd_soc_component_update_bits(v6, 12510, 1, 0);
      _X8 = (unsigned __int64 *)(v7 + 376);
      __asm { PRFM            #0x11, [X8] }
      do
        v37 = __ldxr(_X8);
      while ( __stxr(v37 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
    }
    snd_soc_component_update_bits(v6, 12602, 2, 2);
    if ( v8 <= 8 && ((1 << v8) & 0x1C8) != 0 )
      snd_soc_component_update_bits(v6, 12296, 2, 2);
    v24 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3152);
    if ( v24 )
    {
      v25 = *(_QWORD *)(v7 + 3144);
      if ( *((_DWORD *)v24 - 1) != -17866579 )
        __break(0x8228u);
      v24(v25, 1, 0x10000);
    }
    if ( !*(_BYTE *)(v7 + 280) )
      wcd_enable_irq(v7 + 328, 12);
    return 0;
  }
  if ( *(_BYTE *)(v7 + 310) == 1 )
    snd_soc_component_update_bits(v6, 12391, 128, 128);
  v13 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3152);
  if ( v13 )
  {
    v14 = *(_QWORD *)(v7 + 3144);
    if ( *((_DWORD *)v13 - 1) != -17866579 )
      __break(0x8228u);
    v13(v14, 1, 65537);
  }
  v15 = swr_slvdev_datapath_control(*(_QWORD *)(v7 + 40), *(unsigned __int8 *)(*(_QWORD *)(v7 + 40) + 64LL), 1);
  wcd_cls_h_fsm(v6, v7 + 224, 1, 4, v8);
  wcd939x_config_2Vpk_mode(v6, v7, 1);
  if ( v8 <= 5 && ((1 << v8) & 0x34) != 0 )
  {
    if ( !*(_BYTE *)(v7 + 280) )
      snd_soc_component_update_bits(v6, 12510, 1, 1);
    if ( v8 == 4 )
      snd_soc_component_update_bits(v6, 12297, 12, 0);
  }
  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 256) + 112LL) + 88LL) )
  {
    if ( v8 == 4 || v8 == 1 )
      v17 = 4;
    else
      v17 = 2;
    wcd_usbss_audio_config(0, 0, v17);
  }
  snd_soc_component_update_bits(v6, 12456, 240, 208);
  snd_soc_component_update_bits(v6, 12297, 16, 16);
  if ( (~(unsigned int)snd_soc_component_read(v6, 12297) & 0x30) == 0 )
    usleep_range_state(2500, 2600, 2);
  _X8 = (unsigned __int64 *)(v7 + 376);
  __asm { PRFM            #0x11, [X8] }
  do
    v31 = __ldxr(_X8);
  while ( __stxr(v31 | 0x40, _X8) );
  result = v15;
  if ( !*(_BYTE *)(v7 + 280) )
  {
    snd_soc_component_update_bits(v6, 13414, 7, 3);
    return v15;
  }
  return result;
}
