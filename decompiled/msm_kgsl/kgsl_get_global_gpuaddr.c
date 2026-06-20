__int64 __fastcall kgsl_get_global_gpuaddr(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4, int a5)
{
  int v6; // w21
  __int64 v7; // x20
  unsigned int v16; // w9

  if ( *(_QWORD *)(a1 + 11112) )
  {
    if ( (unsigned __int64)(a3 - 0x100000000LL) >= 0xFFFFFFFF00000001LL )
    {
      v6 = a5 | 2;
      v7 = (a3 + 4095) & 0x1FFFFF000LL;
      kgsl_memdesc_init(a1, a2, a4);
      _X8 = (unsigned int *)(a2 + 48);
      __asm { PRFM            #0x11, [X8] }
      do
        v16 = __ldxr(_X8);
      while ( __stxr(v16 | v6, _X8) );
      *(_QWORD *)(a2 + 40) = v7;
      return kgsl_mmu_reserve_global_gpuaddr(a1, a2);
    }
    else
    {
      return 4294967274LL;
    }
  }
  else
  {
    __break(0x800u);
    return 4294967274LL;
  }
}
