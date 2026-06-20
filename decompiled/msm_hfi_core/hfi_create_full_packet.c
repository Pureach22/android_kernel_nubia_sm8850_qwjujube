__int64 __fastcall hfi_create_full_packet(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  _DWORD *v6; // x21
  size_t v7; // x4
  int v8; // w22
  char *v9; // x8
  int v10; // w9
  __int64 v12; // x21
  __int64 v13; // x22
  __int64 v14; // x23
  void *v15; // x0
  const char *v16; // x1
  __int64 v17; // x2

  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v12 = a1;
    v13 = a2;
    v14 = v5;
    printk(&unk_1E83A, "hfi_create_full_packet", 85, a4, a5);
    a1 = v12;
    a2 = v13;
    v5 = v14;
    if ( v12 )
      goto LABEL_3;
LABEL_14:
    printk(&unk_1905C, "hfi_create_full_packet", 88, v5, a5);
    return 0xFFFFFFFFLL;
  }
  if ( !a1 )
    goto LABEL_14;
LABEL_3:
  if ( !a2 )
    goto LABEL_14;
  v6 = *(_DWORD **)a1;
  if ( !*(_QWORD *)a1 )
    goto LABEL_14;
  v7 = *(unsigned int *)(a1 + 8);
  if ( (unsigned int)v7 <= 0x1F )
  {
    v15 = &unk_1E620;
    v16 = "hfi_validate_cmd_buff_size";
    v17 = 25;
LABEL_18:
    printk(v15, v16, v17, v5, v7);
    return 0xFFFFFFFFLL;
  }
  v8 = *(_DWORD *)(a2 + 20) + 32;
  if ( (*v6 & 0xFFFFFFu) + v8 > (unsigned int)v7 )
  {
    printk(&unk_1ECDF, "hfi_validate_cmd_buff_size", 34, v5, v7);
    return 0xFFFFFFFFLL;
  }
  v9 = (char *)v6 + (*v6 & 0xFFFFFF);
  *((_QWORD *)v9 + 2) = 0;
  *((_QWORD *)v9 + 3) = 0;
  *(_QWORD *)v9 = 0;
  *((_QWORD *)v9 + 1) = 0;
  *(_DWORD *)v9 = v8 | (*(_DWORD *)(a2 + 16) << 21);
  *((_DWORD *)v9 + 1) = *(_DWORD *)a2;
  *((_DWORD *)v9 + 2) = *(_DWORD *)(a2 + 8);
  *((_DWORD *)v9 + 3) = *(_DWORD *)(a2 + 4);
  *((_DWORD *)v9 + 4) = *(_DWORD *)(a2 + 12);
  v7 = *(unsigned int *)(a2 + 20);
  if ( !(_DWORD)v7 )
    goto LABEL_10;
  if ( !*(_QWORD *)(a2 + 24) )
  {
    v15 = &unk_19219;
    v16 = "hfi_create_full_packet";
    v17 = 111;
    goto LABEL_18;
  }
  memcpy(v9 + 32, *(const void **)(a2 + 24), v7);
LABEL_10:
  *v6 += v8;
  v10 = msm_hfi_core_debug_level;
  ++v6[7];
  if ( (~v10 & 0x10001) == 0 )
    printk(&unk_1C28B, "hfi_create_full_packet", 122, a4, v7);
  return 0;
}
