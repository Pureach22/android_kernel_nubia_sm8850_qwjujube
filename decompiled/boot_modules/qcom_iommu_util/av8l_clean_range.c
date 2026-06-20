__int64 __fastcall av8l_clean_range(__int64 result, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x21
  unsigned __int64 v5; // x20
  __int64 v6; // x22
  __int64 v7; // x1
  __int64 v8; // x8
  unsigned __int64 v9; // x9
  __int64 v10; // x8
  unsigned __int64 v11; // x12
  __int64 v12; // x9
  __int64 v13; // x1
  __int64 v14; // x8
  unsigned __int64 v15; // x12
  __int64 v16; // x9
  __int64 v17; // x8

  if ( (*(_BYTE *)(result + 32) & 1) != 0 )
    return result;
  v3 = *(_QWORD *)(result + 48);
  v5 = a2;
  result = is_vmalloc_addr(a2);
  if ( (result & 1) == 0 )
  {
    result = is_vmalloc_addr(v5);
    if ( (result & 1) != 0 )
    {
      result = vmalloc_to_page(v5);
      v13 = (v5 & 0xFFF) + ((result + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6);
      if ( (*(_BYTE *)(v3 + 844) & 0x40) != 0 )
        return result;
    }
    else
    {
      v14 = (__int64)(v5 << 8) >> 8;
      v15 = (unsigned __int64)(v14 + 0x8000000000LL) >> 38;
      v16 = memstart_addr + v14 + 0x8000000000LL;
      v17 = v14 - kimage_voffset;
      if ( v15 )
        v13 = v17;
      else
        v13 = v16;
      if ( (*(_BYTE *)(v3 + 844) & 0x40) != 0 )
        return result;
    }
    return _dma_sync_single_for_device(v3, v13, a3 - v5, 1);
  }
  if ( v5 < a3 )
  {
    while ( 1 )
    {
      v6 = a3 - v5 >= 4096 - (v5 & 0xFFF) ? 4096 - (v5 & 0xFFF) : a3 - v5;
      result = is_vmalloc_addr(v5);
      if ( (result & 1) == 0 )
        break;
      result = vmalloc_to_page(v5);
      v7 = (v5 & 0xFFF) + ((result + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6);
      if ( (*(_BYTE *)(v3 + 844) & 0x40) == 0 )
        goto LABEL_16;
LABEL_5:
      v5 += v6;
      if ( v5 >= a3 )
        return result;
    }
    v8 = (__int64)(v5 << 8) >> 8;
    v9 = v8 + 0x8000000000LL;
    v10 = v8 - kimage_voffset;
    v11 = v9 >> 38;
    v12 = memstart_addr + v9;
    if ( v11 )
      v7 = v10;
    else
      v7 = v12;
    if ( (*(_BYTE *)(v3 + 844) & 0x40) != 0 )
      goto LABEL_5;
LABEL_16:
    result = _dma_sync_single_for_device(v3, v7, v6, 1);
    goto LABEL_5;
  }
  return result;
}
