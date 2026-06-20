__int64 __fastcall gen8_hwsched_active_count_get(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  unsigned int v10; // w9

  v2 = to_gen8_gmu(a1);
  if ( *(_QWORD *)(a1 + 11112) )
  {
    if ( (*(_QWORD *)(v2 + 1040) & 0x10) != 0 )
    {
      return 4294967274LL;
    }
    else if ( *(_DWORD *)(a1 + 11128) || (result = gen8_hwsched_boot((_QWORD *)a1), !(_DWORD)result) )
    {
      _X8 = (unsigned int *)(a1 + 11128);
      __asm { PRFM            #0x11, [X8] }
      do
        v10 = __ldxr(_X8);
      while ( __stxr(v10 + 1, _X8) );
      return 0;
    }
  }
  else
  {
    __break(0x800u);
    return 4294967274LL;
  }
  return result;
}
