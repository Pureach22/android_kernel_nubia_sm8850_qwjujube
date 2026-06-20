__int64 __fastcall sub_9D060(__int64 a1, __int64 a2, __int64 a3, void *a4)
{
  __arm_mte_set_tag(&STACK[0xCA0], a4);
  return _bpf_trace_drv_wake_tx_queue();
}
