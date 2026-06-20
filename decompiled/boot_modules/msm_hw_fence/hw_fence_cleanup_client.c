__int64 __fastcall hw_fence_cleanup_client(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x4

  mutex_lock(a1 + 680);
  *(_QWORD *)(*(_QWORD *)(a1 + 728) + 8LL * *a2) = 0;
  mutex_unlock(a1 + 680);
  if ( (~msm_hw_fence_debug_level & 0x10020) == 0 )
    printk(&unk_2363B, "hw_fence_cleanup_client", 1112, *a2, v4);
  return kfree(a2);
}
