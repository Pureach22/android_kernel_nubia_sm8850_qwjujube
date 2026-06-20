__int64 __fastcall hw_fence_ipcc_get_signaled_clients_mask(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  __int64 v4; // x21
  int v5; // w27
  unsigned int v6; // w0
  unsigned int v7; // w26
  char v8; // w25

  v3 = v1;
  if ( a1 && *(_DWORD *)(a1 + 624) && *(_DWORD *)(a1 + 632) && *(_DWORD *)(a1 + 636) && *(_BYTE *)(a1 + 33520) == 1 )
  {
    v4 = 0;
    v5 = 100;
    while ( 1 )
    {
      __dsb(0xFu);
      v6 = readl_relaxed(
             *(_QWORD *)(a1 + 608)
           + (unsigned int)(*(_DWORD *)(a1 + 632) << 12)
           + (unsigned int)(*(_DWORD *)(a1 + 624) * *(_DWORD *)(a1 + 620))
           + 16LL);
      if ( v6 == -1 )
        break;
      v7 = HIWORD(v6);
      v8 = v6;
      if ( (~msm_hw_fence_debug_level & 0x10040) == 0 )
        printk(&unk_24E95, "hw_fence_ipcc_get_signaled_clients_mask", 943, v6, v7);
      if ( *(_DWORD *)(a1 + 636) == v7 || *(_DWORD *)(a1 + 628) == v7 )
      {
        v4 |= 1LL << v8;
        if ( !--v5 )
          goto LABEL_15;
      }
      else
      {
        printk(&unk_20F9F, "hw_fence_ipcc_get_signaled_clients_mask", 947, v3, v7);
        if ( !--v5 )
        {
LABEL_15:
          printk(&unk_2AD11, "hw_fence_ipcc_get_signaled_clients_mask", 954, v3, 100);
          return v4;
        }
      }
    }
  }
  else
  {
    printk(&unk_285AC, "hw_fence_ipcc_get_signaled_clients_mask", 925, v1, a1);
    return -1;
  }
  return v4;
}
