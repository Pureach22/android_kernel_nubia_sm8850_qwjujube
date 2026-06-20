__int64 __fastcall wcd939x_hph_pcm_enable_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 128);
  *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL) + 280LL) = *(_QWORD *)(a2 + 72);
  return 0;
}
