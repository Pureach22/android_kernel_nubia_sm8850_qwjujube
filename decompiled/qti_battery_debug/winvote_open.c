__int64 __fastcall winvote_open(__int64 a1, __int64 a2)
{
  return single_open(a2, winvote_show, *(_QWORD *)(a1 + 696));
}
