__int64 __fastcall status_open(__int64 a1, __int64 a2)
{
  return single_open(a2, status_show, *(_QWORD *)(a1 + 696));
}
