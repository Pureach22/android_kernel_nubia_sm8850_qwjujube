__int64 __fastcall dbg_persist_max_min_open(__int64 a1, __int64 a2)
{
  return single_open(a2, dbg_persist_max_min_show, *(_QWORD *)(a1 + 696));
}
