__int64 __fastcall hfi_unpacker_get_packet_info(_DWORD **a1, unsigned int a2, __int64 a3)
{
  _DWORD *v3; // x11
  unsigned int v4; // w10
  unsigned __int64 v5; // x8
  int v6; // w12
  int v7; // w4
  _DWORD *v8; // x13
  unsigned int v9; // w3
  __int64 v10; // x9
  _DWORD *v11; // x8
  __int64 result; // x0
  int v13; // w9
  void *v14; // x0
  void *v15; // x0

  if ( !a1 || !a3 || (v3 = *a1) == nullptr )
  {
    v14 = &unk_253204;
LABEL_25:
    printk(v14, "hfi_unpacker_get_packet_info");
    return 0xFFFFFFFFLL;
  }
  v4 = a2 - 1;
  if ( a2 == 1 )
  {
    v5 = *v3 & 0xFFFFFF;
    if ( (unsigned int)v5 <= 0x3F )
    {
      printk(&unk_27CFDA, "hfi_sanitize_cmd_buff");
    }
    else
    {
      v6 = v3[7];
      if ( v6 )
      {
        v7 = 0;
        v8 = v3 + 8;
        v9 = 32;
        do
        {
          if ( (unsigned __int64)v9 + 32 > v5 )
          {
            printk(&unk_26882D, "hfi_sanitize_cmd_buff");
            goto LABEL_24;
          }
          v10 = *v8 & 0x1FFFFF;
          if ( (unsigned int)v10 <= 0x1F )
          {
            v15 = &unk_276895;
            goto LABEL_23;
          }
          ++v7;
          v9 += v10;
          v8 = (_DWORD *)((char *)v8 + v10);
        }
        while ( v6 != v7 );
        if ( (_DWORD)v5 != v9 )
          goto LABEL_20;
        goto LABEL_12;
      }
LABEL_20:
      v15 = &unk_22A6C9;
LABEL_23:
      printk(v15, "hfi_sanitize_cmd_buff");
    }
LABEL_24:
    v14 = &unk_265345;
    goto LABEL_25;
  }
  if ( v3[7] < a2 )
  {
    printk(&unk_2687FC, "hfi_unpacker_get_packet_info");
    return 0xFFFFFFFFLL;
  }
LABEL_12:
  v11 = v3 + 8;
  if ( a2 >= 2 )
  {
    do
    {
      --v4;
      v11 = (_DWORD *)((char *)v11 + (*v11 & 0x1FFFFF));
    }
    while ( v4 );
  }
  result = 0;
  *(_DWORD *)a3 = v11[1];
  *(_DWORD *)(a3 + 8) = v11[2];
  *(_DWORD *)(a3 + 4) = v11[3];
  *(_DWORD *)(a3 + 12) = v11[4];
  *(_DWORD *)(a3 + 16) = *v11 >> 21;
  v13 = (*v11 & 0x1FFFFF) - 32;
  *(_DWORD *)(a3 + 20) = v13;
  if ( v13 )
    *(_QWORD *)(a3 + 24) = v11 + 8;
  return result;
}
