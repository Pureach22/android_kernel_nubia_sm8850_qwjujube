__int64 __fastcall list_rates_open(__int64 a1, __int64 a2)
{
  return single_open(a2, list_rates_show, *(_QWORD *)(a1 + 696));
}
