__int64 __fastcall _bpf_trace_rdev_set_power_mgmt(__int64 a1, __int64 a2, __int64 a3, char a4, unsigned int a5)
{
  return bpf_trace_run4(a1, a2, a3, a4 & 1, a5);
}
