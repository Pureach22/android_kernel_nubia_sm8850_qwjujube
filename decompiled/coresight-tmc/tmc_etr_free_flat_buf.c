__int64 __fastcall tmc_etr_free_flat_buf(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v3; // x21

  v1 = *(_QWORD **)(a1 + 56);
  if ( v1 && v1[1] )
  {
    v3 = *(_QWORD *)(*v1 + 96LL);
    dma_vunmap_noncontiguous(v3, v1[2]);
    dma_free_noncontiguous(v3, *(_QWORD *)(a1 + 16), v1[4], 2);
    v1[2] = 0;
    v1[4] = 0;
  }
  return kfree(v1);
}
