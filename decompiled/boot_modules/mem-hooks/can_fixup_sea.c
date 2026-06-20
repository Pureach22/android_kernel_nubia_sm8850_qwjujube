void __fastcall can_fixup_sea(__int64 a1, __int64 a2, int a3, __int64 a4, bool *a5)
{
  bool v6; // w8

  v6 = (*(_QWORD *)(a4 + 264) & 0xFLL) != 0 && (a3 & 0xFC000000) != 2214592512LL;
  *a5 = v6;
}
