__int64 __fastcall lpass_cdc_va_macro_init(__int64 a1)
{
  __int64 device_ptr; // x0
  __int64 v3; // x21
  __int64 v4; // x20
  unsigned int v5; // w0
  const char *v7; // x1
  unsigned int v8; // w19

  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 3);
  if ( !device_ptr )
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", "lpass_cdc_va_macro_init");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(device_ptr + 152);
  v4 = device_ptr;
  if ( !v3 )
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_init");
    return 4294967274LL;
  }
  *(_BYTE *)(v3 + 1536) = 0;
  *(_BYTE *)(v3 + 1580) = 0;
  *(_DWORD *)(v3 + 1520) = lpass_cdc_get_version(device_ptr);
  v5 = snd_soc_dapm_new_controls(a1 + 208, &lpass_cdc_va_macro_dapm_widgets, 31);
  if ( (v5 & 0x80000000) != 0 )
  {
    v7 = "%s: Failed to add controls\n";
  }
  else
  {
    v5 = snd_soc_dapm_add_routes(a1 + 208, &va_audio_map, 108);
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
        v5 = snd_soc_add_component_controls(a1, &lpass_cdc_va_macro_snd_controls, 10);
        if ( (v5 & 0x80000000) == 0 )
        {
          snd_soc_dapm_ignore_suspend(a1 + 208, "VA_AIF1 Capture");
          snd_soc_dapm_ignore_suspend(a1 + 208, "VA_AIF2 Capture");
          snd_soc_dapm_ignore_suspend(a1 + 208, "VA_AIF3 Capture");
          snd_soc_dapm_ignore_suspend(a1 + 208, "VA SWR_INPUT");
          snd_soc_dapm_sync(a1 + 208);
          *(_QWORD *)(v3 + 296) = v3;
          *(_BYTE *)(v3 + 1578) = 1;
          *(_BYTE *)(v3 + 304) = 0;
          *(_QWORD *)(v3 + 312) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 320) = v3 + 320;
          *(_QWORD *)(v3 + 328) = v3 + 320;
          *(_QWORD *)(v3 + 336) = &lpass_cdc_va_macro_tx_hpf_corner_freq_callback;
          init_timer_key(v3 + 344, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 416) = v3;
          *(_BYTE *)(v3 + 424) = 1;
          *(_QWORD *)(v3 + 432) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 440) = v3 + 440;
          *(_QWORD *)(v3 + 448) = v3 + 440;
          *(_QWORD *)(v3 + 456) = &lpass_cdc_va_macro_tx_hpf_corner_freq_callback;
          init_timer_key(v3 + 464, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 536) = v3;
          *(_BYTE *)(v3 + 544) = 2;
          *(_QWORD *)(v3 + 552) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 560) = v3 + 560;
          *(_QWORD *)(v3 + 568) = v3 + 560;
          *(_QWORD *)(v3 + 576) = &lpass_cdc_va_macro_tx_hpf_corner_freq_callback;
          init_timer_key(v3 + 584, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 656) = v3;
          *(_BYTE *)(v3 + 664) = 3;
          *(_QWORD *)(v3 + 672) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 680) = v3 + 680;
          *(_QWORD *)(v3 + 688) = v3 + 680;
          *(_QWORD *)(v3 + 696) = &lpass_cdc_va_macro_tx_hpf_corner_freq_callback;
          init_timer_key(v3 + 704, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 776) = v3;
          *(_DWORD *)(v3 + 784) = 0;
          *(_QWORD *)(v3 + 792) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 800) = v3 + 800;
          *(_QWORD *)(v3 + 808) = v3 + 800;
          *(_QWORD *)(v3 + 816) = lpass_cdc_va_macro_mute_update_callback;
          init_timer_key(v3 + 824, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 896) = v3;
          *(_DWORD *)(v3 + 904) = 1;
          *(_QWORD *)(v3 + 912) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 920) = v3 + 920;
          *(_QWORD *)(v3 + 928) = v3 + 920;
          *(_QWORD *)(v3 + 936) = lpass_cdc_va_macro_mute_update_callback;
          init_timer_key(v3 + 944, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 1016) = v3;
          *(_DWORD *)(v3 + 1024) = 2;
          *(_QWORD *)(v3 + 1032) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 1040) = v3 + 1040;
          *(_QWORD *)(v3 + 1048) = v3 + 1040;
          *(_QWORD *)(v3 + 1056) = lpass_cdc_va_macro_mute_update_callback;
          init_timer_key(v3 + 1064, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 1136) = v3;
          *(_DWORD *)(v3 + 1144) = 3;
          *(_QWORD *)(v3 + 1152) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 1160) = v3 + 1160;
          *(_QWORD *)(v3 + 1168) = v3 + 1160;
          *(_QWORD *)(v3 + 1176) = lpass_cdc_va_macro_mute_update_callback;
          init_timer_key(v3 + 1184, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 176) = v3;
          *(_QWORD *)(v3 + 192) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v3 + 200) = v3 + 200;
          *(_QWORD *)(v3 + 208) = v3 + 200;
          *(_QWORD *)(v3 + 216) = mute_stream_dec_unmute;
          init_timer_key(v3 + 224, &delayed_work_timer_fn, 0x200000, 0, 0);
          *(_QWORD *)(v3 + 168) = a1;
          snd_soc_component_update_bits(a1, 12496, 238, 204);
          snd_soc_component_update_bits(a1, 12500, 238, 204);
          snd_soc_component_update_bits(a1, 12504, 238, 204);
          return 0;
        }
        v7 = "%s: Failed to add snd_ctls\n";
      }
    }
  }
  v8 = v5;
  dev_err(v4, v7, "lpass_cdc_va_macro_init");
  return v8;
}
