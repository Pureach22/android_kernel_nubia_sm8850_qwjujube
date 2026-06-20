__int64 __fastcall lpass_cdc_tx_macro_init(__int64 a1)
{
  __int64 device_ptr; // x0
  __int64 v3; // x21
  __int64 v4; // x20
  unsigned int v5; // w0
  const char *v7; // x1
  unsigned int v8; // w19

  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 0);
  if ( !device_ptr )
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", "lpass_cdc_tx_macro_init");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(device_ptr + 152);
  v4 = device_ptr;
  if ( !v3 )
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", "lpass_cdc_tx_macro_init");
    return 4294967274LL;
  }
  *(_DWORD *)(v3 + 2536) = lpass_cdc_get_version(device_ptr);
  v5 = snd_soc_dapm_new_controls(a1 + 208, &lpass_cdc_tx_macro_dapm_widgets, 41);
  if ( (v5 & 0x80000000) != 0 )
  {
    v7 = "%s: Failed to add controls\n";
  }
  else
  {
    v5 = snd_soc_dapm_add_routes(a1 + 208, &tx_audio_map, 214);
    if ( (v5 & 0x80000000) != 0 )
    {
      v7 = "%s: Failed to add routes\n";
    }
    else
    {
      v5 = snd_soc_dapm_new_widgets(*(_QWORD *)(a1 + 232));
      if ( (v5 & 0x80000000) != 0 )
      {
        v7 = "%s: Failed to add widgets\n";
      }
      else
      {
        v5 = snd_soc_add_component_controls(a1, &lpass_cdc_tx_macro_snd_controls, 29);
        if ( (v5 & 0x80000000) == 0 )
        {
          snd_soc_dapm_ignore_suspend(a1 + 208, "TX_AIF1 Capture");
          snd_soc_dapm_ignore_suspend(a1 + 208, "TX_AIF2 Capture");
          snd_soc_dapm_ignore_suspend(a1 + 208, "TX_AIF3 Capture");
          snd_soc_dapm_ignore_suspend(a1 + 208, "TX SWR_INPUT");
          snd_soc_dapm_sync(a1 + 208);
          *(_QWORD *)(v3 + 608) = v3;
          *(_BYTE *)(v3 + 616) = 0;
          *(_QWORD *)(v3 + 624) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 632) = v3 + 632;
          *(_QWORD *)(v3 + 640) = v3 + 632;
          *(_QWORD *)(v3 + 648) = &lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
          init_timer_key(v3 + 656, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_BYTE *)(v3 + 736) = 1;
          *(_QWORD *)(v3 + 728) = v3;
          *(_QWORD *)(v3 + 744) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 752) = v3 + 752;
          *(_QWORD *)(v3 + 760) = v3 + 752;
          *(_QWORD *)(v3 + 768) = &lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
          init_timer_key(v3 + 776, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_BYTE *)(v3 + 856) = 2;
          *(_QWORD *)(v3 + 848) = v3;
          *(_QWORD *)(v3 + 864) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 872) = v3 + 872;
          *(_QWORD *)(v3 + 880) = v3 + 872;
          *(_QWORD *)(v3 + 888) = &lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
          init_timer_key(v3 + 896, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 968) = v3;
          *(_BYTE *)(v3 + 976) = 3;
          *(_QWORD *)(v3 + 984) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 992) = v3 + 992;
          *(_QWORD *)(v3 + 1000) = v3 + 992;
          *(_QWORD *)(v3 + 1008) = &lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
          init_timer_key(v3 + 1016, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 1088) = v3;
          *(_BYTE *)(v3 + 1096) = 4;
          *(_QWORD *)(v3 + 1104) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 1112) = v3 + 1112;
          *(_QWORD *)(v3 + 1120) = v3 + 1112;
          *(_QWORD *)(v3 + 1128) = &lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
          init_timer_key(v3 + 1136, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 1208) = v3;
          *(_BYTE *)(v3 + 1216) = 5;
          *(_QWORD *)(v3 + 1224) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 1232) = v3 + 1232;
          *(_QWORD *)(v3 + 1240) = v3 + 1232;
          *(_QWORD *)(v3 + 1248) = &lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
          init_timer_key(v3 + 1256, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 1328) = v3;
          *(_BYTE *)(v3 + 1336) = 6;
          *(_QWORD *)(v3 + 1344) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 1352) = v3 + 1352;
          *(_QWORD *)(v3 + 1360) = v3 + 1352;
          *(_QWORD *)(v3 + 1368) = &lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
          init_timer_key(v3 + 1376, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 1448) = v3;
          *(_BYTE *)(v3 + 1456) = 7;
          *(_QWORD *)(v3 + 1464) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 1472) = v3 + 1472;
          *(_QWORD *)(v3 + 1480) = v3 + 1472;
          *(_QWORD *)(v3 + 1488) = &lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
          init_timer_key(v3 + 1496, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 1568) = v3;
          *(_DWORD *)(v3 + 1576) = 0;
          *(_QWORD *)(v3 + 1584) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 1592) = v3 + 1592;
          *(_QWORD *)(v3 + 1600) = v3 + 1592;
          *(_QWORD *)(v3 + 1608) = lpass_cdc_tx_macro_mute_update_callback;
          init_timer_key(v3 + 1616, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_DWORD *)(v3 + 1696) = 1;
          *(_QWORD *)(v3 + 1688) = v3;
          *(_QWORD *)(v3 + 1704) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 1712) = v3 + 1712;
          *(_QWORD *)(v3 + 1720) = v3 + 1712;
          *(_QWORD *)(v3 + 1728) = lpass_cdc_tx_macro_mute_update_callback;
          init_timer_key(v3 + 1736, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_DWORD *)(v3 + 1816) = 2;
          *(_QWORD *)(v3 + 1808) = v3;
          *(_QWORD *)(v3 + 1824) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 1832) = v3 + 1832;
          *(_QWORD *)(v3 + 1840) = v3 + 1832;
          *(_QWORD *)(v3 + 1848) = lpass_cdc_tx_macro_mute_update_callback;
          init_timer_key(v3 + 1856, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 1928) = v3;
          *(_DWORD *)(v3 + 1936) = 3;
          *(_QWORD *)(v3 + 1944) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 1952) = v3 + 1952;
          *(_QWORD *)(v3 + 1960) = v3 + 1952;
          *(_QWORD *)(v3 + 1968) = lpass_cdc_tx_macro_mute_update_callback;
          init_timer_key(v3 + 1976, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 2048) = v3;
          *(_DWORD *)(v3 + 2056) = 4;
          *(_QWORD *)(v3 + 2064) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 2072) = v3 + 2072;
          *(_QWORD *)(v3 + 2080) = v3 + 2072;
          *(_QWORD *)(v3 + 2088) = lpass_cdc_tx_macro_mute_update_callback;
          init_timer_key(v3 + 2096, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 2168) = v3;
          *(_DWORD *)(v3 + 2176) = 5;
          *(_QWORD *)(v3 + 2184) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 2192) = v3 + 2192;
          *(_QWORD *)(v3 + 2200) = v3 + 2192;
          *(_QWORD *)(v3 + 2208) = lpass_cdc_tx_macro_mute_update_callback;
          init_timer_key(v3 + 2216, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 2288) = v3;
          *(_DWORD *)(v3 + 2296) = 6;
          *(_QWORD *)(v3 + 2304) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 2312) = v3 + 2312;
          *(_QWORD *)(v3 + 2320) = v3 + 2312;
          *(_QWORD *)(v3 + 2328) = lpass_cdc_tx_macro_mute_update_callback;
          init_timer_key(v3 + 2336, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 2408) = v3;
          *(_DWORD *)(v3 + 2416) = 7;
          *(_QWORD *)(v3 + 2424) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 2432) = v3 + 2432;
          *(_QWORD *)(v3 + 2440) = v3 + 2432;
          *(_QWORD *)(v3 + 2448) = lpass_cdc_tx_macro_mute_update_callback;
          init_timer_key(v3 + 2456, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 128) = v3;
          *(_QWORD *)(v3 + 144) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 152) = v3 + 152;
          *(_QWORD *)(v3 + 160) = v3 + 152;
          *(_QWORD *)(v3 + 168) = mute_stream_dec_unmute;
          init_timer_key(v3 + 176, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 248) = v3;
          *(_QWORD *)(v3 + 264) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 272) = v3 + 272;
          *(_QWORD *)(v3 + 280) = v3 + 272;
          *(_QWORD *)(v3 + 288) = mute_stream_dec_unmute;
          init_timer_key(v3 + 296, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 368) = v3;
          *(_QWORD *)(v3 + 384) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 392) = v3 + 392;
          *(_QWORD *)(v3 + 400) = v3 + 392;
          *(_QWORD *)(v3 + 408) = mute_stream_dec_unmute;
          init_timer_key(v3 + 416, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 488) = v3;
          *(_QWORD *)(v3 + 504) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 512) = v3 + 512;
          *(_QWORD *)(v3 + 520) = v3 + 512;
          *(_QWORD *)(v3 + 528) = mute_stream_dec_unmute;
          init_timer_key(v3 + 536, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 120) = a1;
          snd_soc_component_update_bits(a1, 1068, 63, 10);
          return 0;
        }
        v7 = "%s: Failed to add snd_ctls\n";
      }
    }
  }
  v8 = v5;
  dev_err(v4, v7, "lpass_cdc_tx_macro_init");
  return v8;
}
