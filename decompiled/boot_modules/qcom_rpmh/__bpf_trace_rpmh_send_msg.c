__int64 __fastcall _bpf_trace_rpmh_send_msg(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  return bpf_trace_run6(a1, a2, a3, a4, a5, a6);
}
