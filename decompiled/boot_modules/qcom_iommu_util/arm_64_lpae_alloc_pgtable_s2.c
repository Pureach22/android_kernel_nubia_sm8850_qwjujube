_DWORD *__fastcall arm_64_lpae_alloc_pgtable_s2(__int64 a1, __int64 a2)
{
  _DWORD *result; // x0
  int v4; // w8
  int v5; // w8
  unsigned int v6; // w8
  __int64 v7; // x10
  int v8; // w9
  int v9; // w10
  unsigned __int64 v10; // t2
  unsigned int v11; // w8
  _DWORD *v12; // x20
  __int64 v13; // x8
  __int64 v14; // x8
  unsigned __int64 v15; // x9
  __int64 v16; // x8
  unsigned __int64 v17; // x12
  __int64 v18; // x9
  _DWORD *v19; // x19

  if ( *(_QWORD *)(a1 + 8) )
    return nullptr;
  result = (_DWORD *)arm_lpae_alloc_pgtable(a1, a2);
  if ( result )
  {
    if ( !result[51] )
    {
      v4 = result[50];
      if ( (unsigned __int64)(8LL << v4) <= 0x87 )
      {
        result[50] = result[52] + v4;
        result[51] = 1;
      }
    }
    if ( *(_BYTE *)(a1 + 32) )
      v5 = 736;
    else
      v5 = 64;
    v6 = *(_DWORD *)(a1 + 80) & 0xFFFFF81F | v5;
    *(_DWORD *)(a1 + 80) = v6;
    v7 = 8LL << result[52];
    v8 = result[51];
    switch ( v7 )
    {
      case 0x10000LL:
        v6 = v6 & 0xFFFFFAE7 | 8;
        break;
      case 0x4000LL:
        v6 = v6 & 0xFFFFFAE7 | 0x10;
        break;
      case 0x1000LL:
        LOBYTE(v8) = v8 + 1;
        v6 &= 0xFFFFFAE7;
        break;
      default:
        goto LABEL_17;
    }
    *(_DWORD *)(a1 + 80) = v6;
LABEL_17:
    HIDWORD(v10) = *(_DWORD *)(a1 + 28) - 32;
    LODWORD(v10) = HIDWORD(v10);
    v9 = v10 >> 1;
    if ( v9 <= 4 )
    {
      if ( v9 )
      {
        if ( v9 == 2 )
        {
          v11 = v6 & 0xFFFFFFF8 | 1;
        }
        else
        {
          if ( v9 != 4 )
            goto LABEL_37;
          v11 = v6 & 0xFFFFFFF8 | 2;
        }
      }
      else
      {
        v11 = v6 & 0xFFFFFFF8;
      }
    }
    else if ( v9 > 7 )
    {
      if ( v9 == 8 )
      {
        v11 = v6 & 0xFFFFFFF8 | 5;
      }
      else
      {
        if ( v9 != 10 )
          goto LABEL_37;
        v11 = v6 & 0xFFFFFFF8 | 6;
      }
    }
    else if ( v9 == 5 )
    {
      v11 = v6 & 0xFFFFFFF8 | 3;
    }
    else
    {
      if ( v9 != 6 )
        goto LABEL_37;
      v11 = v6 & 0xFFFFFFF8 | 4;
    }
    v12 = result;
    *(_DWORD *)(a1 + 80) = ((-8192 * *(_DWORD *)(a1 + 24)) & 0x7E000 | ((v8 & 3) << 11) | v11 & 0xFFF807FF) ^ 0x1800;
    v13 = _arm_lpae_alloc_pages(result, 8LL << result[50], 3264, a1);
    result = v12;
    *((_QWORD *)v12 + 27) = v13;
    if ( v13 )
    {
      __dsb(0xEu);
      v14 = (__int64)(*((_QWORD *)v12 + 27) << 8) >> 8;
      v15 = v14 + 0x8000000000LL;
      v16 = v14 - kimage_voffset;
      v17 = v15 >> 38;
      v18 = v15 + memstart_addr;
      if ( !v17 )
        v16 = v18;
      *(_QWORD *)(a1 + 72) = v16;
      return result;
    }
LABEL_37:
    v19 = result;
    qcom_io_pgtable_allocator_unregister((unsigned int)result[56]);
    kfree(v19);
    return nullptr;
  }
  return result;
}
