__int64 __fastcall a6xx_rgmu_active_count_get(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w8
  unsigned int v10; // w9

  if ( !*(_QWORD *)(a1 + 11112) )
  {
    __break(0x800u);
    return (unsigned int)-22;
  }
  if ( (*(_QWORD *)(a1 - 16) & 4) != 0 )
    return (unsigned int)-22;
  if ( *(_DWORD *)(a1 + 11128) || (v1 = a1, v2 = a6xx_boot_0((_QWORD *)a1), a1 = v1, !v2) )
  {
    _X8 = (unsigned int *)(a1 + 11128);
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stxr(v10 + 1, _X8) );
    return 0;
  }
  return v2;
}
