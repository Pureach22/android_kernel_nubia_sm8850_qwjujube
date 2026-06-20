__int64 __fastcall sub_AAA24(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  return _bpf_trace_rdev_return_int_mpath_info(a1, a2, a3, a4 & 0xE1FFFFFF | ((a2 & 0xF) << 25));
}
