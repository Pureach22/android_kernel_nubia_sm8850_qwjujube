__int64 __fastcall haptic_audio_time_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  __int64 v7; // [xsp+0h] [xbp-10h] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v7 = 0;
  if ( sscanf(s, "%d %d", &v7, (char *)&v7 + 4) == 2 )
    *(_QWORD *)(v5 + 1072) = v7;
  _ReadStatusReg(SP_EL0);
  return a4;
}
