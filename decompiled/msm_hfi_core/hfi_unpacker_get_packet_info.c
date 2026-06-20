__int64 __fastcall hfi_unpacker_get_packet_info(
        _DWORD **a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        unsigned __int64 a5)
{
  __int64 v5; // x30
  _DWORD *v6; // x22
  unsigned int v7; // w21
  int v8; // w10
  int v9; // w6
  _DWORD *v10; // x9
  unsigned int v11; // w5
  __int64 v12; // x8
  _DWORD *v13; // x8
  int v14; // w9
  _DWORD **v16; // x21
  unsigned int v17; // w22
  __int64 v18; // x23
  __int64 v19; // x24
  void *v20; // x0
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x24
  __int64 v24; // x25
  __int64 v25; // x19
  void *v26; // x0
  __int64 v27; // x2
  unsigned int v28; // w23
  __int64 v29; // x24
  __int64 v30; // x25

  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v16 = a1;
    v17 = a2;
    v18 = a3;
    v19 = v5;
    printk(&unk_1E83A, "hfi_unpacker_get_packet_info", 216, a4, a5);
    a1 = v16;
    a2 = v17;
    v5 = v19;
    a3 = v18;
    if ( v16 )
      goto LABEL_3;
LABEL_26:
    v20 = &unk_1905C;
    v21 = 219;
    v22 = v5;
LABEL_34:
    printk(v20, "hfi_unpacker_get_packet_info", v21, v22, a5);
    return 0xFFFFFFFFLL;
  }
  if ( !a1 )
    goto LABEL_26;
LABEL_3:
  if ( !a3 )
    goto LABEL_26;
  v6 = *a1;
  if ( !*a1 )
    goto LABEL_26;
  v7 = a2 - 1;
  if ( a2 != 1 )
    goto LABEL_17;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v23 = a3;
    v24 = v5;
    printk(&unk_1E83A, "hfi_sanitize_cmd_buff", 133, a4, a5);
    a2 = 1;
    v5 = v24;
    a3 = v23;
  }
  a5 = *v6 & 0xFFFFFF;
  if ( (*v6 & 0xFFFFFFu) <= 0x3F )
  {
    v25 = v5;
    printk(&unk_1D745, "hfi_sanitize_cmd_buff", 137, v5, a5);
LABEL_33:
    v20 = &unk_1C149;
    v21 = 227;
    v22 = v25;
    goto LABEL_34;
  }
  v8 = v6[7];
  if ( !v8 )
  {
LABEL_29:
    v26 = &unk_1B209;
    v27 = 172;
LABEL_32:
    v25 = v5;
    printk(v26, "hfi_sanitize_cmd_buff", v27, v5, a5);
    goto LABEL_33;
  }
  v9 = 0;
  v10 = v6 + 8;
  v11 = 32;
  do
  {
    if ( (unsigned __int64)v11 + 32 > a5 )
    {
      v25 = v5;
      printk(&unk_1E2A6, "hfi_sanitize_cmd_buff", 153, v5, a5);
      goto LABEL_33;
    }
    v12 = *v10 & 0x1FFFFF;
    if ( (unsigned int)v12 <= 0x1F )
    {
      v26 = &unk_1E66F;
      v27 = 161;
      a5 = (unsigned int)v12;
      goto LABEL_32;
    }
    ++v9;
    v11 += v12;
    v10 = (_DWORD *)((char *)v10 + v12);
  }
  while ( v8 != v9 );
  if ( (_DWORD)a5 != v11 )
    goto LABEL_29;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v28 = a2;
    v29 = a3;
    v30 = v5;
    printk(&unk_1C28B, "hfi_sanitize_cmd_buff", 176, a4, a5);
    a2 = v28;
    v5 = v30;
    a3 = v29;
  }
LABEL_17:
  if ( v6[7] < a2 )
  {
    printk(&unk_1E5E1, "hfi_unpacker_get_packet_info", 234, v5, a2);
    return 0xFFFFFFFFLL;
  }
  v13 = v6 + 8;
  if ( a2 >= 2 )
  {
    do
    {
      --v7;
      v13 = (_DWORD *)((char *)v13 + (*v13 & 0x1FFFFF));
    }
    while ( v7 );
  }
  *(_DWORD *)a3 = v13[1];
  *(_DWORD *)(a3 + 8) = v13[2];
  *(_DWORD *)(a3 + 4) = v13[3];
  *(_DWORD *)(a3 + 12) = v13[4];
  *(_DWORD *)(a3 + 16) = *v13 >> 21;
  v14 = (*v13 & 0x1FFFFF) - 32;
  *(_DWORD *)(a3 + 20) = v14;
  if ( v14 )
    *(_QWORD *)(a3 + 24) = v13 + 8;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "hfi_unpacker_get_packet_info", 265, a4, a5);
  return 0;
}
