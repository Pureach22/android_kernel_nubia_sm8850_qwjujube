__int64 __fastcall hw_dma_fence_init(unsigned int *a1, __int64 a2, __int64 a3)
{
  _DWORD *v6; // x22
  __int64 v7; // x0
  __int64 v8; // x23

  v6 = (_DWORD *)_kmalloc_cache_noprof(_list_add_valid_or_report, 2336, 4);
  if ( !v6 )
    return -12;
  v7 = _kmalloc_cache_noprof(_arch_copy_to_user, 2336, 200);
  v8 = v7;
  if ( !v7 )
  {
    kfree(v6);
    return -12;
  }
  snprintf((char *)(v7 + 64), 0x40u, "hwfence:id:%d:ctx=%llu:seqno:%llu", *a1, a2, a3);
  *v6 = 0;
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
    printk(&unk_29D1D, "hw_dma_fence_init", 1483, *a1, a2);
  dma_fence_init(v8, &hw_fence_dbg_ops_0, v6, a2, a3);
  *(_QWORD *)(v8 + 128) = a1;
  return v8;
}
