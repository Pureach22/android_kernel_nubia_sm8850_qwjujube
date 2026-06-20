__int64 __fastcall lpass_cdc_rx_macro_iir_enable_audio_mixer_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  int v4; // w20
  unsigned int v5; // w8

  v2 = *(_QWORD *)(a1 + 120);
  v4 = *(_DWORD *)(v2 + 20);
  v5 = snd_soc_component_read(*(_QWORD *)(a1 + 128), ((*(_DWORD *)(v2 + 12) << 7) + 6692) & 0xFFFC);
  *(_QWORD *)(a2 + 72) = (v5 >> v4) & 1;
  return 0;
}
