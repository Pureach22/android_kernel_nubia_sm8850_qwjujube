__int64 __fastcall gmu_core_map_memdesc(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x4
  __int64 result; // x0
  __int64 v12; // x19
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  __int64 v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 + 96);
  if ( v7 )
  {
    v8 = *(unsigned int *)(a2 + 104);
    v9 = *(_QWORD *)(a2 + 40);
    v13 = 0;
    v14 = 0;
    result = sg_alloc_table_from_pages_segment(&v13, v7, v8, 0, v9, 0xFFFFFFFFLL, 3264);
    if ( (_DWORD)result )
      goto LABEL_8;
    v12 = kgsl_mmu_map_sg(a1, a3, v13, (unsigned int)v14, a4);
    sg_free_table(&v13);
  }
  else
  {
    v12 = kgsl_mmu_map_sg(a1, a3, **(_QWORD **)(a2 + 56), *(unsigned int *)(*(_QWORD *)(a2 + 56) + 8LL), a4);
  }
  if ( v12 )
    result = 0;
  else
    result = 4294967284LL;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
