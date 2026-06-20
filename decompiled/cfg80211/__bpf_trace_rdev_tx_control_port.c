__int64 __fastcall _bpf_trace_rdev_tx_control_port(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        unsigned __int16 a7,
        char a8,
        unsigned int a9)
{
  return bpf_trace_run8(a1, a2, a3, a4, a5, a6, a7, a8 & 1, a9);
}
