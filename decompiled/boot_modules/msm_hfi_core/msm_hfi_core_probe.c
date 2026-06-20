__int64 __fastcall msm_hfi_core_probe(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x19
  int is_compatible; // w0
  __int64 v8; // x3
  int v9; // w8
  __int64 v10; // x21
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  unsigned int v15; // w0
  unsigned int v16; // w22
  __int64 v17; // x3
  __int64 result; // x0
  __int64 v19; // x30
  unsigned int v20; // w19

  v5 = v4;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_18:
    printk(&unk_1B666, "msm_hfi_core_probe", 63, v5);
    return 4294967274LL;
  }
  printk(&unk_1E83A, "msm_hfi_core_probe", 60, a4);
  if ( !a1 )
    goto LABEL_18;
LABEL_3:
  is_compatible = of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,msm-hfi-core");
  v9 = msm_hfi_core_debug_level;
  if ( !is_compatible )
    goto LABEL_15;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1E83A, "msm_hfi_core_probe_init", 22, v8);
  v10 = _kmalloc_cache_noprof(snprintf, 3520, 816);
  if ( !v10 )
  {
    printk(&unk_19FEC, "msm_hfi_core_probe_init", 26, v5);
    result = 4294967284LL;
    goto LABEL_23;
  }
  *(_DWORD *)(v10 + 232) = 1;
  *(_QWORD *)(v10 + 288) = of_device_get_match_data(a1 + 16);
  *(_QWORD *)(a1 + 168) = v10;
  *(_QWORD *)v10 = a1 + 16;
  v15 = hfi_core_init(v10, v11, v12, v13, v14);
  if ( !v15 )
  {
    v9 = msm_hfi_core_debug_level;
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      printk(&unk_1DB49, "msm_hfi_core_probe_init", 42, "msm_hfi_core_probe_init");
      v9 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      {
        printk(&unk_1C28B, "msm_hfi_core_probe_init", 43, v8);
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          goto LABEL_21;
        return 0;
      }
    }
LABEL_15:
    if ( (~v9 & 0x10001) == 0 )
    {
LABEL_21:
      printk(&unk_1C28B, "msm_hfi_core_probe", 72, v8);
      return 0;
    }
    return 0;
  }
  v16 = v15;
  *(_QWORD *)(a1 + 168) = 0;
  kfree(v10);
  if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
    printk(&unk_1F3FD, "msm_hfi_core_probe_init", 51, v16);
  result = v16;
  if ( v16 == -517 )
  {
    if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
      printk(&unk_1D2B7, "msm_hfi_core_probe", 77, v17);
    return 4294966779LL;
  }
LABEL_23:
  if ( (msm_hfi_core_probe___already_done & 1) == 0 )
  {
    v19 = v5;
    v20 = result;
    msm_hfi_core_probe___already_done = 1;
    printk(&unk_1B69B, "msm_hfi_core_probe", 79, v19);
    return v20;
  }
  return result;
}
