__int64 __fastcall profile_groups_open(__int64 a1, __int64 a2)
{
  return single_open(a2, profile_groups_show, *(_QWORD *)(a1 + 696));
}
