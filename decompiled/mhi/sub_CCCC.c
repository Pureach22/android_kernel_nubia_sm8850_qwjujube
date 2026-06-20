__int64 sub_CCCC()
{
  __int64 v0; // x25

  if ( (v0 & 0x20000000000LL) == 0 )
    JUMPOUT(0xD1D4);
  return _bpf_trace_mhi_process_event_ring();
}
