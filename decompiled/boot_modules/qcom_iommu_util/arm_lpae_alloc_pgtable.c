__int64 __fastcall arm_lpae_alloc_pgtable(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x9
  __int64 v4; // x10
  unsigned int v5; // w10
  __int64 v6; // x8
  unsigned int v7; // w9
  unsigned int v8; // w11
  __int64 result; // x0
  int v10; // w10
  unsigned __int64 v11; // x8
  int v12; // w11
  __int64 v13; // x12
  __int64 v14; // x13
  int v15; // w9
  int v16; // w10
  __int64 v17; // x19

  v1 = *(_QWORD *)(a1 + 16);
  v3 = 1075843072;
  if ( (v1 & 0x1000) != 0 )
    goto LABEL_11;
  if ( (v1 & 0xFFF) != 0 )
  {
    v4 = 1LL << ((unsigned __int8)__clz(*(_QWORD *)(a1 + 16) & 0xFFFLL) ^ 0x3Fu);
    if ( v4 == 4096 )
      goto LABEL_11;
  }
  else
  {
    if ( !v1 )
    {
LABEL_10:
      v3 = 0;
      goto LABEL_11;
    }
    v4 = v1 & -v1;
    if ( v4 == 4096 )
    {
LABEL_11:
      v5 = 48;
      goto LABEL_12;
    }
  }
  if ( v4 != 0x10000 )
  {
    if ( v4 == 0x4000 )
    {
      v5 = 48;
      v3 = 33570816;
      goto LABEL_12;
    }
    goto LABEL_10;
  }
  v3 = 536936448;
  if ( *(_DWORD *)(a1 + 28) > 0x30u )
    v3 = 0x40020010000LL;
  v5 = 52;
LABEL_12:
  v6 = v3 & v1;
  v8 = *(_DWORD *)(a1 + 24);
  v7 = *(_DWORD *)(a1 + 28);
  *(_QWORD *)(a1 + 16) = v6;
  if ( v8 >= v5 )
    v8 = v5;
  if ( v7 >= v5 )
    v7 = v5;
  *(_DWORD *)(a1 + 24) = v8;
  *(_DWORD *)(a1 + 28) = v7;
  if ( (v6 & 0x15000) != 0 )
  {
    result = _kmalloc_cache_noprof(memset, 3264, 256);
    if ( !result )
      return result;
    v10 = *(_DWORD *)(a1 + 24);
    v11 = __rbit64(*(_QWORD *)(a1 + 16));
    *(_QWORD *)(result + 128) = qcom_arm_lpae_map_pages;
    *(_QWORD *)(result + 136) = qcom_arm_lpae_unmap_pages;
    *(_DWORD *)(result + 248) = 0;
    LODWORD(v11) = __clz(v11);
    *(_QWORD *)(result + 144) = arm_lpae_iova_to_phys;
    *(_QWORD *)(result + 152) = 0;
    v12 = v11 - 3;
    v13 = *(_QWORD *)(a1 + 112);
    v14 = *(_QWORD *)(a1 + 120);
    v15 = (v10 - 4) / ((int)v11 - 3);
    v16 = v10 - v11;
    LODWORD(v11) = *(_DWORD *)(a1 + 128);
    *(_QWORD *)(result + 160) = 0;
    *(_QWORD *)(result + 168) = 0;
    v17 = result;
    *(_QWORD *)(result + 232) = v13;
    *(_QWORD *)(result + 240) = v14;
    *(_QWORD *)(result + 176) = 0;
    *(_QWORD *)(result + 184) = 0;
    *(_QWORD *)(result + 192) = 0;
    *(_DWORD *)(result + 224) = v11;
    *(_DWORD *)(result + 204) = 4 - v15;
    *(_DWORD *)(result + 208) = v12;
    *(_DWORD *)(result + 200) = v16 + v12 - v12 * v15;
    if ( !(unsigned int)qcom_io_pgtable_allocator_register((unsigned int)v11) )
      return v17;
    kfree(v17);
  }
  return 0;
}
