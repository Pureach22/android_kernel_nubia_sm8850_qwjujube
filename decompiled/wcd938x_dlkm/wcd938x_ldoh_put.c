__int64 __fastcall wcd938x_ldoh_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 128);
  *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL) + 290LL) = *(_QWORD *)(a2 + 72) != 0;
  return 0;
}
