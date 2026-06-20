__int64 __fastcall qcom_secure_system_heap_create(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x22
  __int64 v7; // x1
  __int64 v8; // x1
  __int64 result; // x0
  __int64 v10; // x22
  unsigned __int64 pools; // x0
  unsigned __int64 v12; // x0
  __int64 dev; // x0
  unsigned __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  __int64 (__fastcall **v17)(); // [xsp+8h] [xbp-18h]
  __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v5 = a3;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = nullptr;
  v18 = 0;
  v16 = 0;
  if ( (unsigned int)get_secure_vmid(a3) == -22 || _sw_hweight64(v5) != 1 )
  {
    printk(&unk_DED8, v7);
    goto LABEL_8;
  }
  if ( (unsigned int)dynamic_page_pool_init_shrinker() )
  {
LABEL_8:
    result = printk(&unk_D9B1, "qcom_secure_system_heap_create");
    goto LABEL_9;
  }
  if ( (create_prefetch_workqueue_registered & 1) == 0 )
  {
    prefetch_work = 0xFFFFFFFE00000LL;
    qword_D6D8 = (__int64)&qword_D6D8;
    qword_D6E0 = (__int64)&qword_D6D8;
    qword_D6E8 = (__int64)secure_system_heap_prefetch_work;
    init_timer_key(&unk_D6F0, &delayed_work_timer_fn, 0x200000, 0, 0);
    prefetch_wq = alloc_workqueue("system_secure_prefetch_wq", 6, 0);
    if ( !prefetch_wq )
    {
      printk(&unk_DFF7, v8);
      goto LABEL_8;
    }
    create_prefetch_workqueue_registered = 1;
  }
  v10 = _kmalloc_cache_noprof(of_platform_device_create, 3520, 32);
  if ( !v10 )
    goto LABEL_8;
  *(_DWORD *)(v10 + 8) = a3;
  pools = dynamic_page_pool_create_pools(a3, (__int64)free_secure_pages);
  *(_QWORD *)v10 = pools;
  if ( pools > 0xFFFFFFFFFFFFF000LL )
  {
LABEL_15:
    kfree(v10);
    goto LABEL_8;
  }
  v16 = a1;
  v17 = system_heap_ops_0;
  v18 = v10;
  v12 = dma_heap_add(&v16);
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    dynamic_page_pool_release_pools(*(__int64 **)v10);
    goto LABEL_15;
  }
  dev = dma_heap_get_dev(v12);
  dma_coerce_mask_and_coherent_0(dev);
  list_add(v10 + 16);
  result = printk(&unk_DAFC, "qcom_secure_system_heap_create");
  if ( a2 )
  {
    v16 = a2;
    v14 = dma_heap_add(&v16);
    if ( v14 < 0xFFFFFFFFFFFFF001LL )
    {
      v15 = dma_heap_get_dev(v14);
      dma_coerce_mask_and_coherent_0(v15);
      result = printk(&unk_DAFC, "qcom_secure_system_heap_create");
    }
    else
    {
      result = printk(&unk_E301, "qcom_secure_system_heap_create");
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
