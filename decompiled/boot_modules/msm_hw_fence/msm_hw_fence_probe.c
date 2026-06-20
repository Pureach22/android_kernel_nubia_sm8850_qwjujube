__int64 __fastcall msm_hw_fence_probe(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  __int64 v8; // x3
  __int64 v9; // x4
  _QWORD *v10; // x0
  int v11; // w8
  unsigned int v12; // w0
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 result; // x0
  bool v16; // w10
  _QWORD *v17; // x0
  __int64 v18; // x8
  unsigned int v19; // w21
  __int64 v20; // x0
  __int64 v21; // x3
  __int64 v22; // x4
  __int64 v23; // x30
  unsigned int v24; // w19
  unsigned int v25; // w21

  v6 = v5;
  if ( (~msm_hw_fence_debug_level & 0x10001) != 0 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_28:
    printk(&unk_22EB0, "msm_hw_fence_probe", 855, v6, a5);
    return 4294967274LL;
  }
  printk(&unk_2B058, "msm_hw_fence_probe", 852, a4, a5);
  if ( !a1 )
    goto LABEL_28;
LABEL_3:
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,msm-hw-fence") )
  {
    if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
      printk(&unk_2B058, "msm_hw_fence_probe_init", 796, v8, v9);
    v10 = (_QWORD *)_kmalloc_large_noprof(33768, 3520);
    hw_fence_drv_data = (__int64)v10;
    if ( v10 )
    {
      *(_QWORD *)(a1 + 168) = v10;
      v11 = (unsigned __int8)hw_fence_driver_enable;
      *v10 = a1 + 16;
      if ( v11 == 1 )
      {
        v12 = hw_fence_init((__int64)v10);
        if ( !v12 )
        {
          _mutex_init(
            hw_fence_drv_data + 680,
            "&hw_fence_drv_data->clients_register_lock",
            &msm_hw_fence_probe_init___key);
          *(_BYTE *)(hw_fence_drv_data + 8) = 1;
LABEL_25:
          if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
          {
            printk(&unk_2388F, "msm_hw_fence_probe_init", 830, v13, v14);
            if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
              printk(&unk_2388F, "msm_hw_fence_probe", 864, v21, v22);
          }
          return 0;
        }
      }
      else
      {
        v16 = of_find_property(*(_QWORD *)(a1 + 760), "soccp_controller", 0) != 0;
        v17 = (_QWORD *)hw_fence_drv_data;
        *(_BYTE *)(hw_fence_drv_data + 33520) = v16;
        v12 = hw_fence_utils_alloc_mem(v17);
        if ( !v12 )
        {
          if ( (~msm_hw_fence_debug_level & 0x10004) == 0 )
            printk(&unk_21B4C, "msm_hw_fence_probe_init", 827, v13, v14);
          goto LABEL_25;
        }
        if ( (msm_hw_fence_probe_init___already_done & 1) == 0 )
        {
          msm_hw_fence_probe_init___already_done = 1;
          v25 = v12;
          printk(&unk_2171F, "msm_hw_fence_probe_init", 823, v6, v14);
          v12 = v25;
        }
      }
      v18 = hw_fence_drv_data;
      *(_QWORD *)(a1 + 168) = 0;
      v19 = v12;
      kfree(*(_QWORD *)(v18 + 648));
      kfree(*(_QWORD *)(hw_fence_drv_data + 40));
      v20 = hw_fence_drv_data;
      if ( *(_BYTE *)(hw_fence_drv_data + 464) == 1 )
      {
        free_pages_exact(*(_QWORD *)(hw_fence_drv_data + 312), *(_QWORD *)(hw_fence_drv_data + 416));
        v20 = hw_fence_drv_data;
      }
      kfree(v20);
      hw_fence_drv_data = -517;
      if ( (msm_hw_fence_probe_init___already_done_66 & 1) == 0 )
      {
        msm_hw_fence_probe_init___already_done_66 = 1;
        printk(&unk_25E0B, "msm_hw_fence_probe_init", 843, v6, v19);
      }
      result = v19;
    }
    else
    {
      result = 4294967284LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  if ( (msm_hw_fence_probe___already_done & 1) == 0 )
  {
    v23 = v6;
    v24 = result;
    msm_hw_fence_probe___already_done = 1;
    printk(&unk_25E0B, "msm_hw_fence_probe", 869, v23, (unsigned int)result);
    return v24;
  }
  return result;
}
