__int64 __fastcall _bpf_trace_ipa3_replenish_rx_page_recycle(__int64 a1, unsigned int a2, __int64 a3, char a4)
{
  return bpf_trace_run3(a1, a2, a3, a4 & 1);
}
