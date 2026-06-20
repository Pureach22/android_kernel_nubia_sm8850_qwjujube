__int64 __fastcall wcd9378_codec_hphl_dac_event(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x2
  unsigned __int64 v14; // x9
  unsigned __int64 v17; // x10

  v3 = *(_QWORD *)(a1 + 40);
  v4 = v3 - 208;
  v5 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( (_DWORD)a3 == 8 )
  {
    snd_soc_component_update_bits(v3 - 208, 1075314894, 16, 0);
    snd_soc_component_update_bits(v4, 1075314894, 2, 0);
    if ( (*(_QWORD *)(v5 + 16) & 0x800) == 0 )
    {
      snd_soc_component_update_bits(v4, 1075315790, 4, 0);
      if ( (*(_QWORD *)(v5 + 456) & 0x2000) != 0 )
      {
        wcd9378_rx_connect_port(v4, 14, 0);
        _X8 = (unsigned __int64 *)(v5 + 456);
        __asm { PRFM            #0x11, [X8] }
        do
          v17 = __ldxr(_X8);
        while ( __stxr(v17 & 0xFFFFFFFFFFFFDFFFLL, _X8) );
      }
    }
    if ( *(_BYTE *)(v5 + 392) == 1 )
    {
      v6 = 0;
      goto LABEL_12;
    }
  }
  else if ( (_DWORD)a3 == 1 )
  {
    wcd9378_sys_usage_auto_udpate(v3 - 208, 12, a3);
    snd_soc_component_update_bits(v4, 1075314894, 16, 16);
    snd_soc_component_update_bits(v4, 1075314894, 2, 2);
    snd_soc_component_update_bits(v4, 1075315790, 4, 4);
    snd_soc_component_update_bits(v4, 1075314905, 128, 0);
    if ( (*(_QWORD *)(v5 + 456) & 0x2000) == 0 )
    {
      wcd9378_rx_connect_port(v4, 14, 1);
      _X8 = (unsigned __int64 *)(v5 + 456);
      __asm { PRFM            #0x11, [X8] }
      do
        v14 = __ldxr(_X8);
      while ( __stxr(v14 | 0x2000, _X8) );
    }
    if ( *(_BYTE *)(v5 + 392) == 1 )
    {
      snd_soc_component_update_bits(v4, 1075315732, 2, 2);
      v6 = 1;
LABEL_12:
      wcd9378_rx_connect_port(v4, 16, v6);
    }
  }
  return 0;
}
