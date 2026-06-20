__int64 __fastcall dump_queue_header(
        __int64 a1,
        int a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x30
  __int64 result; // x0
  __int64 queue_type; // x4

  if ( !a1 || !a6 || !a7 || !a8 )
    return printk(&unk_247BC, "_dump_queue_header", 792, v8, a1);
  result = hw_fence_get_queue_idx_ptrs();
  if ( (msm_hw_fence_debug_level & a2) != 0 && (msm_hw_fence_debug_level & 0x10000) != 0 )
  {
    queue_type = get_queue_type(a5);
    return printk(&unk_2903F, "_dump_queue_header", 802, a4, queue_type);
  }
  return result;
}
