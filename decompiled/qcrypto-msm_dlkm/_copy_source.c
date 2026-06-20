__int64 __fastcall copy_source(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x20
  unsigned int v5; // w21
  int v6; // w24
  __int64 v7; // x22
  __int64 v8; // x23
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x19

  *(_QWORD *)(a1 + 144) = *(_QWORD *)(a1 + 56);
  v2 = _kmalloc_noprof((unsigned int)(*(_DWORD *)(a1 + 48) + 64), 2336);
  *(_QWORD *)(a1 + 184) = v2;
  if ( !v2 )
  {
    printk(&unk_11EC3, 0);
    return 4294967284LL;
  }
  v3 = *(_QWORD *)(a1 + 56);
  LODWORD(v4) = *(_DWORD *)(a1 + 48);
  v5 = 0;
  if ( v3 && (int)v4 >= 1 )
  {
    v6 = 0;
    do
    {
      ++v6;
      LODWORD(v4) = v4 - *(_DWORD *)(v3 + 12);
      v3 = sg_next(v3);
    }
    while ( (int)v4 >= 1 && v3 );
    v4 = *(unsigned int *)(a1 + 48);
    if ( !v6 )
    {
      v5 = 0;
      if ( !(_DWORD)v4 )
        goto LABEL_12;
LABEL_15:
      printk(&unk_12B4A, v5);
      LODWORD(v4) = *(_DWORD *)(a1 + 48);
      goto LABEL_12;
    }
    v7 = *(_QWORD *)(a1 + 184);
    v8 = *(_QWORD *)(a1 + 56);
    v5 = 0;
    do
    {
      v9 = sg_copy_to_buffer(v8, 1, v7, v4);
      v7 += v9;
      v4 -= v9;
      v5 += v9;
      --v6;
      v8 = sg_next(v8);
    }
    while ( v6 );
    LODWORD(v4) = *(_DWORD *)(a1 + 48);
  }
  if ( (_DWORD)v4 != v5 )
    goto LABEL_15;
LABEL_12:
  result = 0;
  v11 = *(_QWORD *)(a1 + 184) & 0xFFFLL;
  *(_QWORD *)(a1 + 152) = ((unsigned __int64)(((__int64)(*(_QWORD *)(a1 + 184) << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                        - 0x13FFFFFFELL;
  v12 = a1 + 152;
  *(_DWORD *)(v12 + 8) = v11;
  *(_DWORD *)(v12 + 12) = v4;
  *(_QWORD *)(v12 - 96) = v12;
  return result;
}
