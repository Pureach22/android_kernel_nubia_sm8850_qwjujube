__int64 __fastcall events_open(__int64 a1, __int64 a2)
{
  return single_open(a2, events_show, *(_QWORD *)(a1 + 696));
}
