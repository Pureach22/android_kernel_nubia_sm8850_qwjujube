__int64 __fastcall adreno_suspend(__int64 a1)
{
  __int64 result; // x0
  unsigned int v9; // w9

  result = kgsl_pwrctrl_change_state(a1, 16);
  if ( !(_DWORD)result && *(_DWORD *)(a1 + 11120) == 16 )
  {
    _X8 = (unsigned int *)(a1 + 20412);
    __asm { PRFM            #0x11, [X8] }
    do
      v9 = __ldxr(_X8);
    while ( __stxr(v9 + 1, _X8) );
  }
  return result;
}
