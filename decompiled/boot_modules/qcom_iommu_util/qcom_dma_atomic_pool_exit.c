__int64 __fastcall qcom_dma_atomic_pool_exit(__int64 a1)
{
  __int64 v2; // x19
  __int64 result; // x0
  unsigned __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x0

  v2 = atomic_pool_size;
  result = gen_pool_alloc_algo_owner(
             atomic_pool,
             atomic_pool_size,
             *(_QWORD *)(atomic_pool + 32),
             *(_QWORD *)(atomic_pool + 40),
             0);
  if ( result )
  {
    v4 = result;
    gen_pool_free_owner(atomic_pool, result, atomic_pool_size, 0);
    gen_pool_destroy(atomic_pool);
    v5 = vmalloc_to_page(v4);
    qcom_dma_common_free_remap(v4);
    if ( !a1 || (v6 = *(_QWORD *)(a1 + 704)) == 0 )
      v6 = qcom_dma_contiguous_default_area;
    return cma_release(v6, v5, (int)(v2 >> 12));
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
