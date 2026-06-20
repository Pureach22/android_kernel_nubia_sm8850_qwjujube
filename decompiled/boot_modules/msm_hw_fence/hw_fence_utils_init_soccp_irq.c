__int64 __fastcall hw_fence_utils_init_soccp_irq(__int64 a1)
{
  __int64 v1; // x30
  __int64 v2; // x20
  __int64 v4; // x4
  __int64 v5; // x7
  unsigned __int64 v6; // x21
  int v7; // w22
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x20
  __int64 v12; // x30
  void *v13; // x0
  __int64 v14; // x2
  __int64 v15; // [xsp+0h] [xbp-40h] BYREF
  __int64 v16; // [xsp+8h] [xbp-38h]
  __int64 v17; // [xsp+10h] [xbp-30h]
  __int64 v18; // [xsp+18h] [xbp-28h]
  __int64 v19; // [xsp+20h] [xbp-20h]
  __int64 v20; // [xsp+28h] [xbp-18h]
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v2 = v1;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v15 = 0;
  if ( !a1 || !*(_QWORD *)a1 || (*(_BYTE *)(a1 + 33520) & 1) == 0 )
  {
    printk(&unk_218BB, "hw_fence_utils_init_soccp_irq", 702, v1, a1);
    LODWORD(v6) = -22;
    goto LABEL_12;
  }
  _init_waitqueue_head(a1 + 33576, "&drv_data->soccp_wait_queue", &hw_fence_utils_init_soccp_irq___key);
  LODWORD(v6) = platform_get_irq(*(_QWORD *)a1 - 16LL, 0);
  if ( (v6 & 0x80000000) != 0 )
  {
    v12 = v2;
    v13 = &unk_262D9;
    v14 = 711;
    goto LABEL_17;
  }
  if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
    printk(&unk_23B2D, "hw_fence_utils_init_soccp_irq", 714, (unsigned int)v6, v4);
  v7 = devm_request_threaded_irq(
         *(_QWORD *)a1,
         (unsigned int)v6,
         hw_fence_soccp_irq_handler,
         0,
         4,
         "hwfence-driver",
         a1,
         v5,
         v15,
         v16,
         v17,
         v18,
         v19,
         v20,
         v21,
         v22);
  if ( (v7 & 0x80000000) == 0 )
  {
    v8 = kthread_create_on_node(hw_fence_soccp_listener, a1, 0xFFFFFFFFLL, "msm_hw_fence_soccp_listener");
    v6 = v8;
    if ( v8 < 0xFFFFFFFFFFFFF001LL )
    {
      wake_up_process(v8);
      *(_QWORD *)(a1 + 33528) = v6;
      _kthread_init_worker(&v15, "(&thread_priority_worker)->lock", &hw_fence_utils_init_soccp_irq___key_46);
      v9 = kthread_create_on_node(&kthread_worker_fn, &v15, 0xFFFFFFFFLL, "soccp_listener_thread_priority_work");
      if ( v9 >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_21E8A, "hw_fence_utils_init_soccp_irq", 737, v2, v9);
        LODWORD(v6) = 0;
        goto LABEL_12;
      }
      v10 = v9;
      wake_up_process(v9);
      *(_QWORD *)(a1 + 33560) = 0;
      *(_QWORD *)(a1 + 33568) = 0;
      *(_QWORD *)(a1 + 33536) = a1 + 33536;
      *(_QWORD *)(a1 + 33544) = a1 + 33536;
      *(_QWORD *)(a1 + 33552) = hw_fence_thread_priority_worker;
      kthread_queue_work(&v15, a1 + 33536);
      kthread_flush_work(a1 + 33536);
      kthread_stop(v10);
      goto LABEL_11;
    }
    v12 = v2;
    v13 = &unk_29EED;
    v14 = 726;
LABEL_17:
    printk(v13, "hw_fence_utils_init_soccp_irq", v14, v12, v4);
    goto LABEL_12;
  }
  printk(&unk_298D8, "hw_fence_utils_init_soccp_irq", 719, v2, (unsigned int)v6);
LABEL_11:
  LODWORD(v6) = v7;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v6;
}
