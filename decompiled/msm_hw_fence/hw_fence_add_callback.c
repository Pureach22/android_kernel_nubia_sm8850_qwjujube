__int64 __fastcall hw_fence_add_callback(__int64 a1, _QWORD *a2, unsigned __int64 a3)
{
  __int64 v3; // x30
  __int64 v4; // x21
  unsigned __int64 v7; // x24
  __int64 v9; // x20
  __int64 result; // x0
  unsigned int v11; // w22
  __int64 (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x19

  v4 = v3;
  if ( *(unsigned int *)(a1 + 16) <= a3 )
  {
    v13 = v3;
    printk(&unk_23ADB, "_get_hw_fence", 1135, v3, a3);
LABEL_16:
    printk(&unk_28BFE, "hw_fence_add_callback", 2632, v13, a3);
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(a1 + 64) + (a3 << 7);
  if ( !v7 )
  {
    v13 = v3;
    goto LABEL_16;
  }
  v9 = _kmalloc_cache_noprof(kfree, 2336, 40);
  if ( !v9 )
    return 4294967284LL;
  *(_QWORD *)(v9 + 24) = a1;
  *(_QWORD *)(v9 + 32) = a3;
  global_atomic_store(a1, v7 + 40, 1);
  *(_DWORD *)(v7 + 112) |= 0x40000000u;
  global_atomic_store(a1, v7 + 40, 0);
  result = hw_fence_interop_add_cb(a2, v9, msm_hw_fence_signal_callback);
  if ( !(_DWORD)result )
    return result;
  if ( (a2[6] & 1) == 0 )
  {
    v11 = result;
    v12 = *(__int64 (__fastcall **)(_QWORD))(a2[1] + 32LL);
    if ( !v12 )
      goto LABEL_17;
    if ( *((_DWORD *)v12 - 1) != 1879296680 )
      __break(0x8228u);
    if ( (v12(a2) & 1) == 0 )
    {
LABEL_17:
      printk(&unk_20AD4, "hw_fence_add_callback", 2656, v4, a2[4]);
      hw_fence_destroy_refcount(*(_QWORD *)(v9 + 24), *(_QWORD *)(v9 + 32), 0x40000000u);
      kfree(v9);
      return v11;
    }
    dma_fence_signal(a2);
  }
  if ( (~msm_hw_fence_debug_level & 0x10040) == 0 )
    printk(&unk_25502, "hw_fence_add_callback", 2651, a2[4], a2[5]);
  msm_hw_fence_signal_callback(a2, v9);
  return 0;
}
