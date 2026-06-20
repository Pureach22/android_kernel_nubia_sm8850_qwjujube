__int64 __fastcall dp_ipa_get_shared_mem_info(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x20
  __int64 v9; // x21
  __int64 v10; // x22
  __int64 v11; // x0
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20

  a5 = (unsigned int)a5;
  *(_QWORD *)(a2 + 32) = a3;
  *(_QWORD *)(a2 + 16) = (unsigned int)a5;
  v6 = 8;
  if ( !*(_BYTE *)(a1 + 608) )
    v6 = 0;
  *(_QWORD *)(a2 + v6) = a4;
  if ( *(_BYTE *)(a1 + 608) == 1 )
  {
    v7 = a4;
    if ( *(_QWORD *)(a1 + 616) )
    {
      v8 = a1;
      v9 = (unsigned int)a5;
      v10 = a4;
      v11 = iommu_iova_to_phys(*(_QWORD *)(a1 + 616), a4);
      a3 = *(_QWORD *)(a2 + 32);
      a4 = v10;
      a5 = v9;
      v7 = v11;
      a1 = v8;
    }
  }
  else
  {
    v7 = a4;
  }
  *(_QWORD *)a2 = v7;
  result = dma_get_sgtable_attrs(*(_QWORD *)(a1 + 40), a2 + 40, a3, a4, a5, 0);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Unable to get DMA sgtable",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "dp_ipa_get_shared_mem_info");
  if ( *(_DWORD *)(a2 + 48) )
  {
    result = *(_QWORD *)(a2 + 40);
    if ( result )
    {
      v21 = 1;
      do
      {
        *(_QWORD *)(result + 16) = *(unsigned int *)(result + 8)
                                 + (((*(_QWORD *)result & 0x3FFFFFFFFFFFFFCLL) - -64LL * (memstart_addr >> 12)) << 6)
                                 + 0x5000000000LL;
        result = sg_next();
        if ( v21 >= *(_DWORD *)(a2 + 48) )
          break;
        ++v21;
      }
      while ( result );
    }
  }
  return result;
}
