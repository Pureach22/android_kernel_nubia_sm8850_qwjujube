__int64 __fastcall synx_test_open(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x0
  __int64 v4; // x4
  __int64 v5; // x5
  _QWORD *v6; // x20
  __int64 v7; // x8

  v3 = _kmalloc_cache_noprof(alt_cb_patch_nops, 3520, 8);
  v6 = (_QWORD *)v3;
  if ( v3 && v3 < 0xFFFFFFFFFFFFF001LL )
  {
    v7 = dma_fence_context_alloc(1);
    *(_QWORD *)(a2 + 32) = v6;
    *v6 = v7;
    return 0;
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_27579, &unk_29207, "synx_test_open", 325, v4, v5);
    return 4294967284LL;
  }
}
