__int64 __fastcall kgsl_mmu_get_mmutype(__int64 a1)
{
  if ( a1 )
    return *(unsigned int *)(a1 + 64);
  else
    return 1;
}
