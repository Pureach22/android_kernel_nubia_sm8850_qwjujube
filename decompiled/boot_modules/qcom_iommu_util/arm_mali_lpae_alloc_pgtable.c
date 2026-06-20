__int64 __fastcall arm_mali_lpae_alloc_pgtable(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x19
  __int64 v5; // x8
  __int64 v6; // x8
  unsigned __int64 v7; // x9
  __int64 v8; // x8
  unsigned __int64 v9; // x12
  __int64 v10; // x9

  if ( *(_QWORD *)(a1 + 8) || *(_DWORD *)(a1 + 24) > 0x30u || *(_DWORD *)(a1 + 28) > 0x28u )
    return 0;
  *(_QWORD *)(a1 + 16) &= 0x40201000uLL;
  result = arm_lpae_alloc_pgtable(a1, a2);
  if ( result )
  {
    if ( *(int *)(result + 204) >= 1 )
      *(_QWORD *)(result + 200) = 0;
    v4 = result;
    *(_QWORD *)(a1 + 80) = 8949128;
    v5 = _arm_lpae_alloc_pages(result, 8LL << *(_DWORD *)(result + 200), 3264, a1);
    result = v4;
    *(_QWORD *)(v4 + 216) = v5;
    if ( v5 )
    {
      __dsb(0xEu);
      v6 = (__int64)(*(_QWORD *)(v4 + 216) << 8) >> 8;
      v7 = v6 + 0x8000000000LL;
      v8 = v6 - kimage_voffset;
      v9 = v7 >> 38;
      v10 = v7 + memstart_addr;
      if ( !v9 )
        v8 = v10;
      *(_QWORD *)(a1 + 72) = v8 | 7;
    }
    else
    {
      qcom_io_pgtable_allocator_unregister(*(unsigned int *)(v4 + 224));
      kfree(v4);
      return 0;
    }
  }
  return result;
}
