__int64 __fastcall sub_AA99C(__int64 a1, __int64 a2)
{
  return _bpf_trace_mpath_evt(a1, a2 - 1024, *(_QWORD *)(a2 - 1024));
}
