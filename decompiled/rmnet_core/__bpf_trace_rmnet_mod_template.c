__int64 __fastcall _bpf_trace_rmnet_mod_template(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned int a4,
        unsigned int a5)
{
  return bpf_trace_run8(a1, a2, a3, a4, a5);
}
