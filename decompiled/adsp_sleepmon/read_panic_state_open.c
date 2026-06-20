__int64 __fastcall read_panic_state_open(__int64 a1, __int64 a2)
{
  return single_open(a2, read_panic_state_show, *(_QWORD *)(a1 + 696));
}
