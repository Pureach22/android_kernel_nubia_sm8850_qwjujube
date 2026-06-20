__int64 __fastcall sub_3A1AC(__int64 _X0)
{
  __asm { SUBG            X28, X0, #0x220, #0xC }
  return perf_trace_walt_active_load_balance();
}
