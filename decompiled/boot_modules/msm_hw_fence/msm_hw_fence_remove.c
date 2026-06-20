__int64 __fastcall msm_hw_fence_remove(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x4
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x30
  void *v18; // x0
  __int64 v19; // x2

  v6 = v5;
  if ( (~msm_hw_fence_debug_level & 0x10001) != 0 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_15:
    v17 = v6;
    v18 = &unk_22EB0;
    v19 = 885;
    return printk(v18, "msm_hw_fence_remove", v19, v17, a5);
  }
  printk(&unk_2B058, "msm_hw_fence_remove", 882, a4, a5);
  if ( !a1 )
    goto LABEL_15;
LABEL_3:
  v8 = *(_QWORD *)(a1 + 168);
  hw_fence_drv_data = v8;
  if ( !v8 )
  {
    v17 = v6;
    v18 = &unk_2645D;
    v19 = 892;
    return printk(v18, "msm_hw_fence_remove", v19, v17, a5);
  }
  v9 = *(_QWORD *)(v8 + 33704);
  if ( v9 && (unsigned int)qcom_unregister_ssr_notifier(v9, v8 + 33680) )
    printk(&unk_251E1, "msm_hw_fence_remove", 900, v6, v10);
  v11 = hw_fence_drv_data;
  v12 = *(_QWORD *)(hw_fence_drv_data + 33528);
  *(_BYTE *)(hw_fence_drv_data + 33520) = 0;
  if ( v12 )
  {
    kthread_stop(v12);
    v11 = hw_fence_drv_data;
  }
  *(_QWORD *)(a1 + 168) = 0;
  kfree(*(_QWORD *)(v11 + 648));
  kfree(*(_QWORD *)(hw_fence_drv_data + 40));
  kfree(*(_QWORD *)(hw_fence_drv_data + 72));
  v13 = hw_fence_drv_data;
  if ( *(_BYTE *)(hw_fence_drv_data + 464) == 1 )
  {
    free_pages_exact(*(_QWORD *)(hw_fence_drv_data + 312), *(_QWORD *)(hw_fence_drv_data + 416));
    v13 = hw_fence_drv_data;
  }
  result = kfree(v13);
  hw_fence_drv_data = -517;
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
    return printk(&unk_2388F, "msm_hw_fence_remove", 919, v15, v16);
  return result;
}
