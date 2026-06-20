__int64 __fastcall stm_generic_set_options(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, __int64 a5)
{
  unsigned __int64 v12; // x10
  unsigned __int64 v15; // x10

  if ( a1 == 64 || !(unsigned int)*(_QWORD *)(*(_QWORD *)(a1 - 40) + 968LL) || *(_DWORD *)(a1 + 96) <= a3 )
    return -22;
  if ( a5 != 1 )
  {
    if ( !a5 )
    {
      _X9 = (unsigned __int64 *)(*(_QWORD *)(a1 - 8) + 8LL * (a3 >> 6));
      __asm { PRFM            #0x11, [X9] }
      do
        v12 = __ldxr(_X9);
      while ( __stxr(v12 | (1LL << a3), _X9) );
      return 0;
    }
    return -22;
  }
  _X9 = (unsigned __int64 *)(*(_QWORD *)(a1 - 8) + 8LL * (a3 >> 6));
  __asm { PRFM            #0x11, [X9] }
  do
    v15 = __ldxr(_X9);
  while ( __stxr(v15 & ~(1LL << a3), _X9) );
  return 0;
}
