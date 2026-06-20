__int64 __fastcall kgsl_mmu_gpuaddr_in_range(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  if ( !a1 )
    return a1 & 1;
  v1 = *(_QWORD *)(a1 + 96);
  if ( v1 )
  {
    v2 = *(__int64 (**)(void))(v1 + 112);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != 576575921 )
        __break(0x8228u);
      LOBYTE(a1) = v2();
      return a1 & 1;
    }
  }
  return 0;
}
