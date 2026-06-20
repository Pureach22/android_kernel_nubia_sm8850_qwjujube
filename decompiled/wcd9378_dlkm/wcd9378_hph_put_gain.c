__int64 __fastcall wcd9378_hph_put_gain(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 128);
  *(_WORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL) + 364LL) = -384 * *(_WORD *)(a2 + 72);
  return 0;
}
