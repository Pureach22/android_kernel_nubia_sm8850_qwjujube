__int64 __fastcall haptic_audio_time_show(__int64 a1, int a2, char *s)
{
  __int64 v3; // x20
  __int64 v5; // x22

  v3 = *(_QWORD *)(a1 + 152);
  v5 = snprintf(s, 0x1000u, "haptic_audio.delay_val=%dus\n", *(_DWORD *)(v3 + 1072));
  return v5 + snprintf(&s[v5], 4096 - v5, "haptic_audio.timer_val=%dus\n", *(_DWORD *)(v3 + 1076));
}
