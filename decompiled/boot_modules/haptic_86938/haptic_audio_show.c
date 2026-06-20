__int64 __fastcall haptic_audio_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "%d\n", *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 1272LL));
}
