_DWORD *__fastcall arm_64_lpae_alloc_pgtable_s1(__int64 a1, __int64 a2)
{
  _DWORD *result; // x0
  int v4; // w8
  __int64 v5; // x9
  unsigned int v6; // w8
  unsigned int v7; // w10
  unsigned int v8; // w8
  unsigned __int64 v9; // x9
  __int64 v10; // x11
  unsigned __int64 v11; // x9
  int v12; // w9
  unsigned __int64 v13; // t2
  unsigned int v14; // w8
  _DWORD *v15; // x20
  __int64 v16; // x8
  __int64 v17; // x8
  unsigned __int64 v18; // x9
  __int64 v19; // x8
  unsigned __int64 v20; // x12
  __int64 v21; // x9
  _DWORD *v22; // x19

  if ( (*(_QWORD *)(a1 + 8) & 0xFFFFFFFF7FFFFF9ELL) != 0 )
    return nullptr;
  result = (_DWORD *)arm_lpae_alloc_pgtable(a1, a2);
  if ( !result )
    return result;
  v4 = *(_DWORD *)(a1 + 80);
  if ( *(_BYTE *)(a1 + 32) == 1 )
  {
    v5 = *(_QWORD *)(a1 + 8);
    v6 = v4 & 0xFFFFF81F | 0x2E0;
    *(_DWORD *)(a1 + 80) = v6;
    if ( (v5 & 0x80000040) != 0 )
    {
      __break(0x800u);
LABEL_44:
      v22 = result;
      qcom_io_pgtable_allocator_unregister((unsigned int)result[56]);
      kfree(v22);
      return nullptr;
    }
  }
  else
  {
    v5 = *(_QWORD *)(a1 + 8);
    v7 = v4 & 0xFFFFF99F;
    v8 = v4 & 0xFFFFF99F | 0x40;
    if ( (v5 & 0x40) != 0 )
    {
      v6 = v8 & 0xFFFFF85F | 0x80;
    }
    else if ( (v5 & 0x80000000) != 0 )
    {
      v6 = v7 | 0x1C0;
    }
    else
    {
      v6 = v8 & 0xFFFFF85F;
    }
    *(_DWORD *)(a1 + 80) = v6;
  }
  v9 = v5 & 0x20;
  v10 = 8LL << result[52];
  switch ( v10 )
  {
    case 0x10000LL:
      if ( v9 )
        LODWORD(v11) = 24;
      else
        LODWORD(v11) = 8;
      goto LABEL_23;
    case 0x4000LL:
      if ( v9 )
        LODWORD(v11) = 8;
      else
        LODWORD(v11) = 16;
      goto LABEL_23;
    case 0x1000LL:
      v11 = v9 >> 1;
LABEL_23:
      v6 = v6 & 0xFFFFFFE7 | v11;
      *(_DWORD *)(a1 + 80) = v6;
      break;
  }
  HIDWORD(v13) = *(_DWORD *)(a1 + 28) - 32;
  LODWORD(v13) = HIDWORD(v13);
  v12 = v13 >> 1;
  if ( v12 <= 4 )
  {
    if ( v12 )
    {
      if ( v12 == 2 )
      {
        v14 = v6 & 0xFFFFFFF8 | 1;
      }
      else
      {
        if ( v12 != 4 )
          goto LABEL_44;
        v14 = v6 & 0xFFFFFFF8 | 2;
      }
    }
    else
    {
      v14 = v6 & 0xFFFFFFF8;
    }
  }
  else if ( v12 > 7 )
  {
    if ( v12 == 8 )
    {
      v14 = v6 & 0xFFFFFFF8 | 5;
    }
    else
    {
      if ( v12 != 10 )
        goto LABEL_44;
      v14 = v6 & 0xFFFFFFF8 | 6;
    }
  }
  else if ( v12 == 5 )
  {
    v14 = v6 & 0xFFFFFFF8 | 3;
  }
  else
  {
    if ( v12 != 6 )
      goto LABEL_44;
    v14 = v6 & 0xFFFFFFF8 | 4;
  }
  v15 = result;
  *(_DWORD *)(a1 + 80) = v14 & 0xFFFE07FF | (((0x1FFFFF * *(_DWORD *)(a1 + 24)) & 0x3F) << 11);
  *(_QWORD *)(a1 + 88) = 0xEFE4F404FF44LL;
  v16 = _arm_lpae_alloc_pages(result, 8LL << result[50], 3264, a1);
  result = v15;
  *((_QWORD *)v15 + 27) = v16;
  if ( !v16 )
    goto LABEL_44;
  __dsb(0xEu);
  v17 = (__int64)(*((_QWORD *)v15 + 27) << 8) >> 8;
  v18 = v17 + 0x8000000000LL;
  v19 = v17 - kimage_voffset;
  v20 = v18 >> 38;
  v21 = v18 + memstart_addr;
  if ( !v20 )
    v19 = v21;
  *(_QWORD *)(a1 + 72) = v19;
  return result;
}
