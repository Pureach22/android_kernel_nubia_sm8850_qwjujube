__int64 __fastcall hw_fence_ipcc_enable_client_signal_pairs(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v7; // x6
  int v8; // w22
  unsigned int i; // w23
  __int64 v10; // x27
  int v11; // w8
  __int64 v12; // x5
  int v13; // w6
  unsigned int v14; // w24
  __int64 v15; // x21
  int v16; // w8
  __int64 v17; // x5
  int v18; // w6
  unsigned int v19; // w0
  __int64 v20; // x21
  const char *v21; // x0
  int v22; // w24
  __int64 v24; // x30
  const char *ipc_virt_client_name; // x0
  __int64 v26; // x4
  const char *v27; // x0
  __int64 v28; // [xsp+8h] [xbp-8h]

  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
  {
    printk(&unk_28570, "hw_fence_ipcc_enable_client_signal_pairs", 856, a4, a5);
    if ( a1 )
      goto LABEL_3;
LABEL_34:
    v24 = v28;
    goto LABEL_35;
  }
  if ( !a1 )
    goto LABEL_34;
LABEL_3:
  v7 = *(_QWORD *)(a1 + 648);
  if ( !*(_DWORD *)(a1 + 624) || !v7 || *(_DWORD *)(a1 + 60) <= a2 )
  {
    v24 = v28;
LABEL_35:
    printk(&unk_2359B, "hw_fence_ipcc_enable_client_signal_pairs", 863, v24, a1);
    return 4294967274LL;
  }
  v8 = *(_DWORD *)(v7 + 16LL * a2);
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
  {
    printk(&unk_239EB, "hw_fence_ipcc_enable_client_signal_pairs", 868, *(_QWORD *)(a1 + 608), a5);
    if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
    {
      ipc_virt_client_name = get_ipc_virt_client_name(v8);
      printk(&unk_26A53, "hw_fence_ipcc_enable_client_signal_pairs", 870, ipc_virt_client_name, v26);
    }
  }
  if ( *(_DWORD *)(a1 + 60) > a2 )
  {
    for ( i = a2; i < *(_DWORD *)(a1 + 60); ++i )
    {
      v10 = *(_QWORD *)(a1 + 648) + 16LL * (int)i;
      if ( *(_DWORD *)v10 != v8 )
        break;
      if ( (~msm_hw_fence_debug_level & 0x10001) != 0 )
      {
        v11 = *(_DWORD *)(a1 + 628);
        if ( (*(_BYTE *)(a1 + 33520) & 1) != 0 )
          goto LABEL_15;
      }
      else
      {
        v21 = get_ipc_virt_client_name(v8);
        printk(&unk_29141, "hw_fence_ipcc_enable_client_signal_pairs", 886, v21, i);
        v11 = *(_DWORD *)(a1 + 628);
        if ( (*(_BYTE *)(a1 + 33520) & 1) != 0 )
        {
LABEL_15:
          v12 = *(_QWORD *)(a1 + 608);
          v13 = *(_DWORD *)(a1 + 624);
          if ( v12 && v13 )
          {
            v14 = *(unsigned __int16 *)(v10 + 8) | (v11 << 16);
            v15 = v12 + (unsigned int)(*(_DWORD *)(a1 + 620) * v13) + (unsigned int)(*(_DWORD *)(v10 + 4) << 12);
            if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
              printk(&unk_242F0, "_enable_client_signal_pair", 790, v14, v15 + 20);
            writel_relaxed(v14, (unsigned int *)(v15 + 20));
          }
          else
          {
            printk(&unk_24325, "_enable_client_signal_pair", 783, v28, a1);
          }
          goto LABEL_20;
        }
      }
      if ( v8 != v11 )
        goto LABEL_15;
LABEL_20:
      v16 = *(_DWORD *)(a1 + 636);
      if ( *(_DWORD *)(a1 + 628) != v16 )
      {
        v17 = *(_QWORD *)(a1 + 608);
        v18 = *(_DWORD *)(a1 + 624);
        if ( v17 && v18 )
        {
          v19 = *(unsigned __int16 *)(v10 + 8) | (v16 << 16);
          v20 = v17 + (unsigned int)(*(_DWORD *)(a1 + 620) * v18) + (unsigned int)(*(_DWORD *)(v10 + 4) << 12);
          if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
          {
            v22 = *(unsigned __int16 *)(v10 + 8) | (v16 << 16);
            printk(&unk_242F0, "_enable_client_signal_pair", 790, v19, v20 + 20);
            v19 = v22;
          }
          writel_relaxed(v19, (unsigned int *)(v20 + 20));
        }
        else
        {
          printk(&unk_24325, "_enable_client_signal_pair", 783, v28, a1);
        }
      }
    }
  }
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
  {
    v27 = get_ipc_virt_client_name(v8);
    printk(&unk_259C2, "hw_fence_ipcc_enable_client_signal_pairs", 900, v27, a2);
  }
  return 0;
}
