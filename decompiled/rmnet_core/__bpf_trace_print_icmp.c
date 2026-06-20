__int64 __fastcall _bpf_trace_print_icmp(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        unsigned __int8 a4,
        unsigned __int16 a5)
{
  return bpf_trace_run6(a1, a2, a3, a4, a5);
}
