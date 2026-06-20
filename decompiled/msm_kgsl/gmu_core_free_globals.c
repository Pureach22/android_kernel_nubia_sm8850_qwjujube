__int64 __fastcall gmu_core_free_globals(__int64 a1)
{
  unsigned __int64 v1; // x8
  unsigned __int64 v3; // x21
  __int64 v4; // x20
  __int64 v5; // x1
  __int64 result; // x0

  v1 = *(unsigned int *)(a1 + 8216);
  if ( (_DWORD)v1 )
  {
    v3 = 0;
    v4 = a1 + 1560;
    do
    {
      v5 = *(unsigned int *)(v4 + 184);
      if ( (_DWORD)v5 )
      {
        iommu_unmap(*(_QWORD *)(a1 + 1552), v5, *(_QWORD *)(v4 + 40));
        if ( (*(_DWORD *)(v4 + 48) & 0x200) != 0 )
          kgsl_sharedmem_free(v4);
        *(_QWORD *)(v4 + 192) = 0;
        *(_QWORD *)(v4 + 200) = 0;
        *(_QWORD *)(v4 + 176) = 0;
        *(_QWORD *)(v4 + 184) = 0;
        *(_QWORD *)(v4 + 160) = 0;
        *(_QWORD *)(v4 + 168) = 0;
        *(_QWORD *)(v4 + 144) = 0;
        *(_QWORD *)(v4 + 152) = 0;
        *(_QWORD *)(v4 + 128) = 0;
        *(_QWORD *)(v4 + 136) = 0;
        *(_QWORD *)(v4 + 112) = 0;
        *(_QWORD *)(v4 + 120) = 0;
        *(_QWORD *)(v4 + 96) = 0;
        *(_QWORD *)(v4 + 104) = 0;
        *(_QWORD *)(v4 + 80) = 0;
        *(_QWORD *)(v4 + 88) = 0;
        *(_QWORD *)(v4 + 64) = 0;
        *(_QWORD *)(v4 + 72) = 0;
        *(_QWORD *)(v4 + 48) = 0;
        *(_QWORD *)(v4 + 56) = 0;
        *(_QWORD *)(v4 + 32) = 0;
        *(_QWORD *)(v4 + 40) = 0;
        *(_QWORD *)(v4 + 16) = 0;
        *(_QWORD *)(v4 + 24) = 0;
        *(_QWORD *)v4 = 0;
        *(_QWORD *)(v4 + 8) = 0;
        v1 = *(unsigned int *)(a1 + 8216);
      }
      if ( v3 > 0x1E )
        break;
      ++v3;
      v4 += 208;
    }
    while ( v3 < v1 );
  }
  result = *(_QWORD *)(a1 + 1552);
  if ( result )
  {
    iommu_detach_device(result, *(_QWORD *)(a1 + 1544) + 16LL);
    result = iommu_domain_free(*(_QWORD *)(a1 + 1552));
    *(_QWORD *)(a1 + 1552) = 0;
  }
  *(_DWORD *)(a1 + 8216) = 0;
  return result;
}
