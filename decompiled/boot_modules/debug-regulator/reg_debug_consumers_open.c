__int64 __fastcall reg_debug_consumers_open(__int64 a1, __int64 a2)
{
  return single_open(a2, reg_debug_consumers_show, *(_QWORD *)(a1 + 696));
}
