__int64 __fastcall enabled_clocks_open(__int64 a1, __int64 a2)
{
  return single_open(a2, enabled_clocks_show, *(_QWORD *)(a1 + 696));
}
