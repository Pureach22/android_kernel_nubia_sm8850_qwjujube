bool __fastcall msm_audio_ssr_compare(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 744);
  return v2 && v2 == a2;
}
