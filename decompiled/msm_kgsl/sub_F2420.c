__int64 sub_F2420()
{
  __asm { UDOT            V23.4H, V27.8B, V13.4B[0] }
  return _bpf_trace_adreno_hw_preempt_token_submit();
}
