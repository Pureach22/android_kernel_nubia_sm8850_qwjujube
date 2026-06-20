unsigned int *__fastcall hfi_core_open_session(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  unsigned int v8; // w20
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  unsigned int *v12; // x21
  unsigned int v13; // w0
  __int64 v14; // x9

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1E83A, "hfi_core_open_session", 174, a4, a5);
    if ( a1 )
      goto LABEL_3;
LABEL_16:
    printk(&unk_19E9B, "hfi_core_open_session", 178, v6, a5);
    return nullptr;
  }
  if ( !a1 )
    goto LABEL_16;
LABEL_3:
  if ( !*(_QWORD *)(a1 + 8) )
    goto LABEL_16;
  v8 = *(_DWORD *)a1;
  if ( *(_DWORD *)a1 >= 4u )
    goto LABEL_16;
  if ( v8 == 1 && (msm_hfi_fail_client_0_reg & 1) != 0 )
    return nullptr;
  if ( *(_QWORD *)(drv_data + 176LL * v8 + 32) )
  {
    printk(&unk_1BCA7, "hfi_core_open_session", 192, v6, v8);
    return *(unsigned int **)(drv_data + 176LL * v8 + 32);
  }
  v12 = (unsigned int *)_kmalloc_cache_noprof(kfree, 3520, 16);
  if ( !v12 )
  {
    printk(&unk_1EC97, "hfi_core_open_session", 198, v6, v11);
    return v12;
  }
  if ( v8 != 3 )
  {
    v13 = set_power_vote(drv_data, 1, v9, v10, v11);
    if ( v13 )
    {
      printk(&unk_1C10C, "hfi_core_open_session", 205, v6, v13);
LABEL_22:
      kfree(v12);
      return nullptr;
    }
  }
  v14 = drv_data;
  *v12 = v8;
  *(_QWORD *)(v14 + 176LL * v8 + 32) = v12;
  *(_QWORD *)(drv_data + 176LL * v8 + 40) = **(_QWORD **)(a1 + 8);
  *(_QWORD *)(drv_data + 176LL * v8 + 48) = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL);
  if ( v8 != 3 && (unsigned int)power_init(v8, drv_data, v9, v10, v11) )
  {
    printk(&unk_1A8EE, "hfi_core_open_session", 220, v6, v8);
    goto LABEL_22;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "hfi_core_open_session", 225, v10, v11);
  return v12;
}
