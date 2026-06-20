__int64 __fastcall hfi_append_packet_with_kv_pairs(
        __int64 a1,
        int a2,
        int a3,
        __int64 a4,
        unsigned int *a5,
        int a6,
        unsigned int a7)
{
  __int64 v7; // x30
  _DWORD *v11; // x26
  __int64 v12; // x4
  unsigned int v13; // w5
  unsigned int v14; // w8
  unsigned int v15; // w9
  unsigned int *v16; // x27
  unsigned int v17; // w10
  unsigned int v18; // w8
  __int64 v19; // x4
  char *v21; // x28
  int v22; // w24
  unsigned int v23; // w25
  unsigned int *v24; // x9
  _DWORD *v25; // x8
  unsigned __int64 v26; // x10
  size_t v27; // x23
  int v28; // w8
  __int64 v30; // x23
  int v31; // w24
  int v32; // w25
  unsigned int v33; // w26
  __int64 v34; // x27
  void *v35; // x0
  const char *v36; // x1
  __int64 v37; // x2
  __int64 v38; // [xsp+8h] [xbp-8h]

  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v30 = a1;
    v31 = a2;
    v32 = a3;
    v33 = a4;
    v34 = v7;
    printk(&unk_1E83A, "hfi_append_packet_with_kv_pairs", 343, a4, a5);
    v7 = v34;
    a1 = v30;
    a4 = v33;
    a3 = v32;
    a2 = v31;
    if ( v30 )
      goto LABEL_3;
LABEL_32:
    printk(&unk_1905C, "hfi_append_packet_with_kv_pairs", 345, v7, a5);
    return 0xFFFFFFFFLL;
  }
  if ( !a1 )
    goto LABEL_32;
LABEL_3:
  if ( !a5 )
    goto LABEL_32;
  v11 = *(_DWORD **)a1;
  if ( !*(_QWORD *)a1 )
    goto LABEL_32;
  v12 = *(unsigned int *)(a1 + 8);
  if ( (unsigned int)v12 <= 0x1F )
  {
    v35 = &unk_1E620;
    v36 = "hfi_validate_cmd_buff_size";
    v37 = 25;
LABEL_38:
    printk(v35, v36, v37, v7, v12);
    return 0xFFFFFFFFLL;
  }
  v13 = (*v11 & 0xFFFFFF) + a7;
  if ( v13 > (unsigned int)v12 )
  {
    v35 = &unk_1ECDF;
    v36 = "hfi_validate_cmd_buff_size";
    v37 = 34;
    goto LABEL_38;
  }
  v14 = v11[7];
  if ( !a7 || !v14 )
  {
    v35 = &unk_1AC2A;
    v36 = "hfi_get_sanitized_append_packet";
    v37 = 287;
    v12 = a7;
    goto LABEL_38;
  }
  v16 = v11 + 8;
  v15 = v11[8];
  v17 = v15 & 0x1FFFFF;
  if ( v14 >= 2 )
  {
    v18 = v14 - 1;
    do
    {
      v16 = (unsigned int *)((char *)v16 + v17);
      --v18;
      v15 = *v16;
      v17 = *v16 & 0x1FFFFF;
    }
    while ( v18 );
  }
  v19 = v15 >> 21;
  if ( (_DWORD)v19 != a3 || v16[1] != a2 )
  {
    printk(&unk_19A80, "hfi_get_sanitized_append_packet", 314, v7, v19);
    return 0xFFFFFFFFLL;
  }
  if ( HIBYTE(v13) || v17 + a7 >= 0x200000 )
  {
    v12 = v16[4];
    v35 = &unk_1C198;
    v36 = "hfi_get_sanitized_append_packet";
    v37 = 324;
    goto LABEL_38;
  }
  if ( !v16 )
    return 0xFFFFFFFFLL;
  v21 = (char *)v16 + (unsigned int)a4;
  if ( *((_DWORD *)v21 + 8) )
  {
    if ( !a6 )
      goto LABEL_28;
    goto LABEL_24;
  }
  *v16 = v15 + 4;
  *v11 += 4;
  v15 = *v16;
  if ( a6 )
  {
LABEL_24:
    v22 = 0;
    v23 = v15 & 0x1FFFFF;
    v38 = v7;
    while ( 1 )
    {
      v24 = &a5[4 * v22];
      v25 = (unsigned int *)((char *)v16 + v23);
      v26 = *v24;
      *v25 = v26;
      if ( !*((_QWORD *)v24 + 1) )
        break;
      v27 = (v26 >> 22) & 0x3FC;
      memcpy(v25 + 1, *((const void **)v24 + 1), v27);
      ++v22;
      v23 += v27 + 4;
      if ( a6 == v22 )
      {
        v15 = *v16;
        goto LABEL_28;
      }
    }
    v7 = v38;
    v35 = &unk_1C9EA;
    v36 = "hfi_append_packet_with_kv_pairs";
    v37 = 378;
    v12 = *a5;
    goto LABEL_38;
  }
LABEL_28:
  v28 = *((_DWORD *)v21 + 8);
  *v16 = v15 + a7;
  *((_DWORD *)v21 + 8) = v28 + a6;
  *v11 += a7;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "hfi_append_packet_with_kv_pairs", 390, a4, v19);
  return 0;
}
