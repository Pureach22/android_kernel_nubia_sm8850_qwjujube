__int64 __fastcall gmu_core_free_block(__int64 result, __int64 a2)
{
  __int64 v2; // x22
  unsigned int v3; // w8
  __int64 v4; // x20
  unsigned int v5; // w9
  unsigned int v6; // w10
  unsigned int v7; // w10
  unsigned int v8; // w10
  unsigned int v9; // w10
  int v10; // w9
  __int64 v12; // x20
  unsigned int v13; // w8
  __int64 v14; // x10
  unsigned int v15; // w10

  v2 = *(_QWORD *)(result + 8224);
  v3 = *(_DWORD *)(a2 + 184);
  v4 = *(_QWORD *)(a2 + 40);
  v5 = v3 + v4;
  if ( *(_DWORD *)v2 <= v3 && v5 <= *(_DWORD *)(v2 + 4) + *(_DWORD *)v2 )
    return result;
  v6 = *(_DWORD *)(v2 + 24);
  if ( v6 <= v3 && v5 <= *(_DWORD *)(v2 + 28) + v6 )
    return result;
  v7 = *(_DWORD *)(v2 + 48);
  if ( v7 <= v3 && v5 <= *(_DWORD *)(v2 + 52) + v7 )
    return result;
  v8 = *(_DWORD *)(v2 + 72);
  if ( v8 <= v3 && v5 <= *(_DWORD *)(v2 + 76) + v8 )
    return result;
  v9 = *(_DWORD *)(v2 + 96);
  if ( v9 > v3 )
    return result;
  if ( v5 > *(_DWORD *)(v2 + 100) + v9 )
    return result;
  v10 = **(_DWORD **)(result + 14264);
  if ( v10 == 203264 || (unsigned int)(v10 - 703) > 0xFFFFFF98 )
    return result;
  if ( v4 != iommu_unmap(*(_QWORD *)(result + 1552), *(unsigned int *)(a2 + 184), v4) )
    return kgsl_sharedmem_free(a2);
  raw_spin_lock(v2 + 108);
  v12 = *(_QWORD *)(v2 + 112);
  if ( !v12 )
    goto LABEL_22;
  v13 = *(_DWORD *)(a2 + 184);
  while ( 1 )
  {
    v15 = *(_DWORD *)(v12 + 24);
    if ( v13 + *(_DWORD *)(a2 + 40) > v15 )
      break;
    v14 = 16;
LABEL_17:
    v12 = *(_QWORD *)(v12 + v14);
    if ( !v12 )
      goto LABEL_22;
  }
  if ( *(_DWORD *)(v12 + 28) + v15 <= v13 )
  {
    v14 = 8;
    goto LABEL_17;
  }
  rb_erase(v12, v2 + 112);
LABEL_22:
  raw_spin_unlock(v2 + 108);
  kfree(v12);
  return kgsl_sharedmem_free(a2);
}
