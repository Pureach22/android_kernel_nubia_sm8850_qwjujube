__int64 __fastcall sub_40478(__int64 _X0)
{
  __asm { SUBG            X28, X0, #0x220, #0xC }
  return _bpf_trace_walt_active_load_balance();
}
