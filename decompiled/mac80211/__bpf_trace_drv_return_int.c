__int64 __fastcall _bpf_trace_drv_return_int(__int64 a1, __int64 a2, unsigned int a3)
{
  return bpf_trace_run2(a1, a2, a3);
}
