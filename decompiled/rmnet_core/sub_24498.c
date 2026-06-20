__int64 __usercall sub_24498@<X0>(__int64 a1@<X8>)
{
  char v1; // b23

  *(_BYTE *)(a1 + 3915) = v1;
  return _bpf_trace_dfc_adjust_grant();
}
