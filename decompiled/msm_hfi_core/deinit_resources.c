__int64 __fastcall deinit_resources(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  unsigned int v8; // w0
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x21
  unsigned int v12; // w0
  __int64 v13; // x3
  __int64 v14; // x4
  unsigned int v15; // w21
  __int64 v16; // x3
  __int64 v17; // x4

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_18:
      printk(&unk_1905C, "deinit_resources", 725, v6, a5);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_1E83A, "deinit_resources", 716, a4, a5);
    if ( !a1 )
      goto LABEL_18;
  }
  if ( !*(_QWORD *)(a1 + 280) )
    goto LABEL_18;
  v8 = deinit_queues(1u, a1, a3, a4, a5);
  if ( v8 )
    printk(&unk_1AFCF, "deinit_resources", 731, v6, v8);
  v11 = *(_QWORD *)(a1 + 280);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1E83A, "hfi_destroy_resource_mem", 642, v9, v10);
  v12 = hfi_res_mem_op(a1, 3);
  if ( v12 || (v12 = unmap_res(a1, v11 + 8)) != 0 )
  {
    v15 = v12;
    printk(&unk_1E546, "deinit_resources", 737, v6, v12);
  }
  else
  {
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "hfi_destroy_resource_mem", 654, v13, v14);
    v15 = 0;
  }
  kfree(*(_QWORD *)(a1 + 280));
  *(_QWORD *)(a1 + 280) = 0;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "deinit_resources", 742, v16, v17);
  return v15;
}
