void *__fastcall qcom_dma_alloc_from_pool(__int64 a1, size_t a2, _QWORD *a3)
{
  void *v5; // x19

  if ( atomic_pool )
  {
    v5 = (void *)gen_pool_alloc_algo_owner(
                   atomic_pool,
                   a2,
                   *(_QWORD *)(atomic_pool + 32),
                   *(_QWORD *)(atomic_pool + 40),
                   0);
    if ( v5 )
    {
      *a3 = (((unsigned __int64)gen_pool_virt_to_phys(atomic_pool, v5) >> 6) & 0x3FFFFFFFFFFFFC0LL)
          - ((__int64)memstart_addr >> 12 << 6)
          - 0x140000000LL;
      memset(v5, 0, a2);
    }
    if ( gen_pool_avail(atomic_pool) < (unsigned __int64)atomic_pool_size )
      queue_work_on(32, system_wq, &atomic_pool_work);
  }
  else
  {
    _warn_printk("coherent pool not initialised!\n");
    v5 = nullptr;
    __break(0x800u);
  }
  return v5;
}
