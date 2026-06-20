__int64 __fastcall wcd9378_codec_ear_dac_event(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v5; // x19
  __int64 v6; // x21
  char v7; // w0
  char v8; // w20
  unsigned __int64 v12; // x10
  unsigned __int64 v19; // x9
  unsigned __int64 v22; // x10

  v3 = *(_QWORD *)(a1 + 40);
  v5 = v3 - 208;
  v6 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  v7 = snd_soc_component_read(v3 - 208, 1075315791);
  if ( a3 == 8 )
  {
    snd_soc_component_update_bits(v5, 1075314698, 64, 0);
    if ( (*(_QWORD *)(v6 + 456) & 0x1000) == 0 )
    {
      wcd9378_rx_connect_port(v5, 19, 0);
      return swr_slvdev_datapath_control(*(_QWORD *)(v6 + 56), *(unsigned __int8 *)(*(_QWORD *)(v6 + 56) + 64LL), 0);
    }
    if ( (*(_QWORD *)(v6 + 16) & 0x1000) == 0 )
    {
      snd_soc_component_update_bits(v5, 1075315790, 4, 0);
      if ( (*(_QWORD *)(v6 + 456) & 0x2000) != 0 )
      {
        wcd9378_rx_connect_port(v5, 14, 0);
        _X8 = (unsigned __int64 *)(v6 + 456);
        __asm { PRFM            #0x11, [X8] }
        do
          v22 = __ldxr(_X8);
        while ( __stxr(v22 & 0xFFFFFFFFFFFFDFFFLL, _X8) );
      }
      if ( *(_BYTE *)(v6 + 392) == 1 )
      {
        snd_soc_component_update_bits(v5, 1075315732, 4, 0);
        wcd9378_rx_connect_port(v5, 16, 0);
      }
    }
    _X8 = (unsigned __int64 *)(v6 + 456);
    __asm { PRFM            #0x11, [X8] }
    do
      v12 = __ldxr(_X8);
    while ( __stxr(v12 & 0xFFFFFFFFFFFFEFFFLL, _X8) );
  }
  else if ( a3 == 1 )
  {
    v8 = v7;
    snd_soc_component_update_bits(v5, 1075314698, 64, 64);
    if ( (v8 & 1) != 0 )
    {
      wcd9378_sys_usage_auto_udpate(v5, 8, 1);
      snd_soc_component_update_bits(v5, 1075316163, 32, 32);
      snd_soc_component_update_bits(v5, 1075315050, 128, 128);
      if ( *(_DWORD *)(v6 + 372) )
        snd_soc_component_update_bits(v5, 1075315723, 64, 64);
      wcd9378_rx_connect_port(v5, 19, 1);
    }
    else
    {
      snd_soc_component_update_bits(v5, 1075315790, 4, 4);
      wcd9378_sys_usage_auto_udpate(v5, 11, 1);
      if ( *(_BYTE *)(v6 + 392) == 1 )
      {
        snd_soc_component_update_bits(v5, 1075315732, 4, 4);
        wcd9378_rx_connect_port(v5, 16, 1);
      }
      if ( (*(_QWORD *)(v6 + 456) & 0x2000) == 0 )
      {
        wcd9378_rx_connect_port(v5, 14, 1);
        _X8 = (unsigned __int64 *)(v6 + 456);
        __asm { PRFM            #0x11, [X8] }
        do
          v19 = __ldxr(_X8);
        while ( __stxr(v19 | 0x2000, _X8) );
      }
    }
  }
  return 0;
}
