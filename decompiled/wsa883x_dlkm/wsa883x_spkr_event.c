__int64 __fastcall wsa883x_spkr_event(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x22
  int v6; // w8
  __int64 v7; // x3
  unsigned int v8; // w21
  unsigned int v9; // w20
  unsigned __int64 v17; // x10
  unsigned __int64 v20; // x10

  v3 = *(_QWORD *)(a1 + 40);
  v4 = v3 - 208;
  v5 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( a3 != 4 )
  {
    if ( a3 != 2 )
      return 0;
    v6 = *(_DWORD *)(v5 + 92);
    if ( v6 == 1 )
    {
      v9 = 0;
      v8 = 8;
      v7 = 2;
    }
    else
    {
      if ( v6 )
        goto LABEL_12;
      v7 = 0;
      v8 = 0;
      v9 = 144;
    }
    snd_soc_component_update_bits(v4, 13320, 2, v7);
    snd_soc_component_update_bits(v4, 12345, 8, v8);
    snd_soc_component_update_bits(v4, 13420, 240, v9);
LABEL_12:
    swr_slvdev_datapath_control(*(_QWORD *)(v5 + 16), *(unsigned __int8 *)(*(_QWORD *)(v5 + 16) + 64LL), 1);
    usleep_range_state(250, 300, 2);
    snd_soc_component_update_bits(v4, 13421, 1, 1);
    usleep_range_state(250, 300, 2);
    swr_remove_from_group(*(_QWORD *)(v5 + 16), *(unsigned __int8 *)(*(_QWORD *)(v5 + 16) + 64LL));
    if ( *(_BYTE *)(v5 + 32) == 1 && (*(_QWORD *)(v5 + 400) & 1) != 0 )
      snd_soc_component_update_bits(v4, 13420, 7, *(unsigned int *)(v5 + 96));
    wcd_enable_irq(v5 + 216, 9);
    wcd_enable_irq(v5 + 216, 8);
    wcd_enable_irq(v5 + 216, 0);
    wcd_enable_irq(v5 + 216, 1);
    wcd_enable_irq(v5 + 216, 2);
    wcd_enable_irq(v5 + 216, 3);
    wcd_enable_irq(v5 + 216, 6);
    snd_soc_component_update_bits(v4, 13350, 14, 6);
    snd_soc_component_update_bits(v4, 13350, 1, 1);
    if ( (*(_QWORD *)(v5 + 376) & 4) != 0 )
      snd_soc_component_update_bits(v4, 13328, 1, 1);
    return 0;
  }
  if ( (*(_QWORD *)(v5 + 376) & 4) == 0 && *(_BYTE *)(v5 + 36) == 1 )
  {
    wcd_disable_irq(v5 + 216, 5);
    *(_BYTE *)(v5 + 36) = 0;
  }
  snd_soc_component_update_bits(v4, 13350, 1, 0);
  snd_soc_component_update_bits(v4, 13350, 14, 0);
  snd_soc_component_update_bits(v4, 13328, 1, 0);
  snd_soc_component_update_bits(v4, 13328, 16, 0);
  snd_soc_component_update_bits(v4, 13328, 16, 16);
  snd_soc_component_update_bits(v4, 13328, 16, 0);
  snd_soc_component_update_bits(v4, 13387, 1, 0);
  wcd_disable_irq(v5 + 216, 6);
  wcd_disable_irq(v5 + 216, 3);
  wcd_disable_irq(v5 + 216, 2);
  wcd_disable_irq(v5 + 216, 1);
  wcd_disable_irq(v5 + 216, 0);
  wcd_disable_irq(v5 + 216, 8);
  wcd_disable_irq(v5 + 216, 9);
  _X8 = (unsigned __int64 *)(v5 + 376);
  __asm { PRFM            #0x11, [X8] }
  do
    v17 = __ldxr(_X8);
  while ( __stxr(v17 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  _X8 = (unsigned __int64 *)(v5 + 376);
  __asm { PRFM            #0x11, [X8] }
  do
    v20 = __ldxr(_X8);
  while ( __stxr(v20 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  return 0;
}
