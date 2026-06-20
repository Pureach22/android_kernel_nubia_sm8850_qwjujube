__int64 __fastcall smmu_aspace_map_vma(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (*v6)(void); // x8
  __int64 result; // x0
  unsigned int v9; // w19
  __int64 v10; // x1
  unsigned int v16; // w9

  if ( !a1 || *(_BYTE *)(a1 + 268) != 1 )
    return 4294967274LL;
  v6 = *(__int64 (**)(void))(**(_QWORD **)(a1 + 256) + 48LL);
  if ( *((_DWORD *)v6 - 1) != 2114229419 )
    __break(0x8228u);
  result = v6();
  if ( !(_DWORD)result )
    *(_QWORD *)(a2 + 168) = *(_QWORD *)(*(_QWORD *)a3 + 16LL);
  _X8 = (unsigned int *)(a1 + 264);
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 + 1, _X8) );
  if ( !v16 )
  {
    v9 = result;
    v10 = 2;
    goto LABEL_15;
  }
  if ( (((v16 + 1) | v16) & 0x80000000) != 0 )
  {
    v9 = result;
    v10 = 1;
LABEL_15:
    refcount_warn_saturate(_X8, v10);
    return v9;
  }
  return result;
}
