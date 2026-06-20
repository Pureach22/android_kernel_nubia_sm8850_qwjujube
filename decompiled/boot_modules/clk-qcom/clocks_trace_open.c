__int64 __fastcall clocks_trace_open(__int64 a1, __int64 a2)
{
  return single_open(a2, clock_debug_trace, *(_QWORD *)(a1 + 696));
}
