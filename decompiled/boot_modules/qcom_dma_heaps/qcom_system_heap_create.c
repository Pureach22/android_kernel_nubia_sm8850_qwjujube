__int64 __fastcall qcom_system_heap_create(const char *a1, const char *a2, char a3)
{
  __int64 v6; // x22
  unsigned __int64 pools; // x1
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x23
  unsigned __int64 v10; // x0
  __int64 result; // x0
  __int64 dev; // x0
  unsigned __int64 v13; // x0
  __int64 v14; // x0
  const char *v15; // [xsp+8h] [xbp-58h] BYREF
  __int64 (__fastcall **v16)(); // [xsp+10h] [xbp-50h]
  __int64 v17; // [xsp+18h] [xbp-48h]
  _QWORD v18[2]; // [xsp+20h] [xbp-40h] BYREF
  int v19; // [xsp+30h] [xbp-30h]
  int v20; // [xsp+34h] [xbp-2Ch]
  __int64 v21; // [xsp+38h] [xbp-28h]
  __int64 v22; // [xsp+40h] [xbp-20h]
  __int64 v23; // [xsp+48h] [xbp-18h]
  __int64 v24; // [xsp+50h] [xbp-10h]
  __int64 v25; // [xsp+58h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = nullptr;
  v17 = 0;
  v15 = nullptr;
  if ( (unsigned int)dynamic_page_pool_init_shrinker() )
    goto LABEL_14;
  v6 = _kmalloc_cache_noprof(of_find_property, 3520, 16);
  if ( !v6 )
    goto LABEL_14;
  v15 = a1;
  v16 = system_heap_ops;
  v17 = v6;
  *(_DWORD *)v6 = a3 & 1;
  pools = dynamic_page_pool_create_pools(0, 0);
  *(_QWORD *)(v6 + 8) = pools;
  if ( pools >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_13:
    kfree(v6);
LABEL_14:
    result = printk(&unk_D9B1, "qcom_system_heap_create");
    goto LABEL_15;
  }
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v18[1] = 0;
  v20 = 0;
  v18[0] = 0;
  v19 = 10;
  v8 = kthread_create_on_node(system_heap_refill_worker, pools, 0xFFFFFFFFLL, "%s-pool-refill-thread", a1);
  v9 = v8;
  if ( v8 <= 0xFFFFFFFFFFFFF000LL )
  {
    wake_up_process(v8);
    if ( (unsigned int)sched_setattr(v9, v18) )
    {
      printk(&unk_DFB0, "system_heap_create_refill_worker");
      kthread_stop(v9);
      goto LABEL_12;
    }
    *(_QWORD *)(**(_QWORD **)(v6 + 8) + 56LL) = v9;
    *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 8) + 8LL) + 56LL) = v9;
    *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 8) + 16LL) + 56LL) = v9;
  }
  else
  {
    printk(&unk_DD11, "system_heap_create_refill_worker");
    if ( (_DWORD)v9 )
      goto LABEL_12;
  }
  v10 = dma_heap_add(&v15);
  if ( v10 >= 0xFFFFFFFFFFFFF001LL )
  {
    kthread_stop(*(_QWORD *)(**(_QWORD **)(v6 + 8) + 56LL));
LABEL_12:
    dynamic_page_pool_release_pools(*(_QWORD *)(v6 + 8));
    goto LABEL_13;
  }
  if ( (a3 & 1) != 0 )
  {
    dev = dma_heap_get_dev(v10);
    dma_coerce_mask_and_coherent(dev);
  }
  result = printk(&unk_DAFC, "qcom_system_heap_create");
  if ( a2 )
  {
    v15 = a2;
    v13 = dma_heap_add(&v15);
    if ( v13 < 0xFFFFFFFFFFFFF001LL )
    {
      v14 = dma_heap_get_dev(v13);
      dma_coerce_mask_and_coherent(v14);
      result = printk(&unk_DAFC, "qcom_system_heap_create");
    }
    else
    {
      result = printk(&unk_E301, "qcom_system_heap_create");
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
