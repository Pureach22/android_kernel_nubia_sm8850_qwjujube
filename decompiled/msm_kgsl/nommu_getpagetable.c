__int64 __fastcall nommu_getpagetable(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  _QWORD *v4; // x8
  __int64 v5; // x19

  result = kgsl_get_pagetable(0);
  if ( !result )
  {
    v3 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 192);
    if ( v3 )
    {
      *(_DWORD *)(v3 + 4) = 1;
      *(_QWORD *)(v3 + 40) = 0xFFFFFFFE00000LL;
      *(_DWORD *)v3 = 0;
      *(_QWORD *)(v3 + 48) = v3 + 48;
      *(_QWORD *)(v3 + 56) = v3 + 48;
      *(_QWORD *)(v3 + 64) = deferred_destroy_0;
      *(_QWORD *)(v3 + 112) = a1;
      *(_DWORD *)(v3 + 24) = 0;
      *(_DWORD *)(v3 + 72) = 0;
      *(_QWORD *)(v3 + 80) = 0;
      *(_QWORD *)(v3 + 88) = 0;
      v4 = *(_QWORD **)(a1 + 13056);
      for ( *(_QWORD *)(v3 + 96) = &nommu_pt_ops; v4 != (_QWORD *)(a1 + 13056); v4 = (_QWORD *)*v4 )
        *(v4 - 24) = *(unsigned int *)(*(_QWORD *)*(v4 - 20) + 8LL)
                   + (((**(_QWORD **)*(v4 - 20) & 0x3FFFFFFFFFFFFFCLL) - -64LL * (memstart_addr >> 12)) << 6)
                   + 0x5000000000LL;
      v5 = v3;
      kgsl_mmu_pagetable_add(v3, v3);
      return v5;
    }
    else
    {
      return -12;
    }
  }
  return result;
}
