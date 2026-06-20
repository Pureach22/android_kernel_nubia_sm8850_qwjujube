__int64 __fastcall hfi_append_packet_with_kv_pairs(
        __int64 a1,
        int a2,
        int a3,
        unsigned int a4,
        __int64 a5,
        int a6,
        int a7)
{
  _DWORD *v8; // x23
  unsigned int v9; // w9
  unsigned int v11; // w8
  unsigned int v12; // w9
  unsigned int v14; // w10
  unsigned int *v15; // x24
  unsigned int v16; // w11
  unsigned int v17; // w9
  char *v18; // x25
  int v19; // w26
  unsigned int v20; // w27
  unsigned int *v21; // x9
  _DWORD *v22; // x8
  unsigned __int64 v23; // x10
  size_t v24; // x22
  int v25; // w8
  void *v27; // x0
  const char *v28; // x1

  if ( !a1 || !a5 || (v8 = *(_DWORD **)a1) == nullptr )
  {
    printk(&unk_265327, "hfi_append_packet_with_kv_pairs");
    return 0xFFFFFFFFLL;
  }
  v9 = *(_DWORD *)(a1 + 8);
  if ( v9 <= 0x1F )
  {
    v27 = &unk_261BBB;
    v28 = "hfi_validate_cmd_buff_size";
    goto LABEL_32;
  }
  v11 = (*v8 & 0xFFFFFF) + a7;
  if ( v11 > v9 )
  {
    v27 = &unk_27684F;
    v28 = "hfi_validate_cmd_buff_size";
    goto LABEL_32;
  }
  v12 = v8[7];
  if ( !a7 || !v12 )
  {
    v27 = &unk_2687BA;
    v28 = "hfi_get_sanitized_append_packet";
    goto LABEL_32;
  }
  v15 = v8 + 8;
  v14 = v8[8];
  v16 = v14 & 0x1FFFFF;
  if ( v12 >= 2 )
  {
    v17 = v12 - 1;
    do
    {
      v15 = (unsigned int *)((char *)v15 + v16);
      --v17;
      v14 = *v15;
      v16 = *v15 & 0x1FFFFF;
    }
    while ( v17 );
  }
  if ( v14 >> 21 != a3 || v15[1] != a2 )
  {
    printk(&unk_21D06C, "hfi_get_sanitized_append_packet");
    v27 = &unk_22DC8E;
    v28 = "hfi_get_sanitized_append_packet";
LABEL_32:
    printk(v27, v28);
    return 0xFFFFFFFFLL;
  }
  if ( HIBYTE(v11) || v16 + a7 >= 0x100000 )
  {
    v27 = &unk_21D0B0;
    v28 = "hfi_get_sanitized_append_packet";
    goto LABEL_32;
  }
  if ( v15 )
  {
    v18 = (char *)v15 + a4;
    if ( *((_DWORD *)v18 + 8) )
    {
      if ( !a6 )
        goto LABEL_24;
    }
    else
    {
      *v15 = v14 + 4;
      *v8 += 4;
      v14 = *v15;
      if ( !a6 )
      {
LABEL_24:
        v25 = *((_DWORD *)v18 + 8);
        *v15 = v14 + a7;
        *((_DWORD *)v18 + 8) = v25 + a6;
        *v8 += a7;
        return 0;
      }
    }
    v19 = 0;
    v20 = v14 & 0x1FFFFF;
    while ( 1 )
    {
      v21 = (unsigned int *)(a5 + 16LL * v19);
      v22 = (unsigned int *)((char *)v15 + v20);
      v23 = *v21;
      *v22 = v23;
      if ( !*((_QWORD *)v21 + 1) )
        break;
      v24 = (v23 >> 22) & 0x3FC;
      memcpy(v22 + 1, *((const void **)v21 + 1), v24);
      ++v19;
      v20 += v24 + 4;
      if ( a6 == v19 )
      {
        v14 = *v15;
        goto LABEL_24;
      }
    }
    v27 = &unk_276822;
    v28 = "hfi_append_packet_with_kv_pairs";
    goto LABEL_32;
  }
  return 0xFFFFFFFFLL;
}
