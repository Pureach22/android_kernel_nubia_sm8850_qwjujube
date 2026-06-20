unsigned int *__fastcall cnss_pci_pm_runtime_get_noresume(unsigned int *result, unsigned int a2)
{
  unsigned int v5; // w9
  unsigned int v12; // w9
  unsigned int v14; // w10

  if ( result )
  {
    if ( a2 <= 1 )
    {
      _X8 = result + 42;
      __asm { PRFM            #0x11, [X8] }
      do
        v12 = __ldxr(_X8);
      while ( __stxr(v12 + 1, _X8) );
      _X9 = &result[a2 + 44];
      __asm { PRFM            #0x11, [X9] }
      do
        v14 = __ldxr(_X9);
      while ( __stxr(v14 + 1, _X9) );
      __isb(0xFu);
      *(_QWORD *)&result[2 * a2 + 48] = 10 * (_ReadStatusReg(CNTVCT_EL0) / 0xC0);
    }
    _X8 = (unsigned int *)(*(_QWORD *)result + 680LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v5 = __ldxr(_X8);
    while ( __stxr(v5 + 1, _X8) );
  }
  return result;
}
