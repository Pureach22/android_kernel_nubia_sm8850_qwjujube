__int64 __fastcall _bpf_trace_walt_newidle_balance(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        char a6)
{
  return bpf_trace_run6(a1, a2, a3, a4, a5 & 1, a6 & 1);
}
