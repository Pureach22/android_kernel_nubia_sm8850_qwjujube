__int64 __fastcall stm_char_mmap(__int64 a1, __int64 a2)
{
  _DWORD *v2; // x9
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 (*v5)(void); // x8
  __int64 v7; // x8
  __int64 v8; // x0

  v2 = *(_DWORD **)(a1 + 32);
  v3 = *(_QWORD *)v2;
  v4 = *(_QWORD *)(*(_QWORD *)v2 + 984LL);
  v5 = *(__int64 (**)(void))(v4 + 48);
  if ( !v5 )
    return 4294967201LL;
  if ( *(_QWORD *)(a2 + 80) || *(_QWORD *)(a2 + 8) - *(_QWORD *)a2 != *(_DWORD *)(v4 + 28) * v2[5] )
    return 4294967274LL;
  if ( *((_DWORD *)v5 - 1) != 1852061543 )
    __break(0x8228u);
  if ( !v5() )
    return 4294967274LL;
  _pm_runtime_resume(v3, 4);
  v7 = *(_QWORD *)(a2 + 16);
  v8 = a2;
  *(_QWORD *)(a2 + 24) = *(_QWORD *)(a2 + 24) & 0xFF9FFFFFFFFFFFE3LL | 0x6000000000000CLL;
  if ( (*(_QWORD *)(v7 + 136) & 1) == 0 )
  {
    __break(0x800u);
    v7 = *(_QWORD *)(a2 + 16);
  }
  if ( *(_DWORD *)(a2 + 40) != *(_DWORD *)(v7 + 224) )
  {
    _vma_start_write(a2);
    v8 = a2;
  }
  *(_QWORD *)(v8 + 32) |= 0x4044000uLL;
  *(_QWORD *)(v8 + 72) = stm_mmap_vmops;
  vm_iomap_memory();
  return 0;
}
