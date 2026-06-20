__int64 __fastcall kgsl_pwrctrl_irq(__int64 result, char a2)
{
  int v2; // w8
  __int64 v3; // x19
  int v4; // w8
  __int64 v5; // x19
  int v6; // w8
  unsigned __int64 v13; // x8
  unsigned __int64 v16; // x8

  if ( *(_DWORD *)(result + 14168) || *(_DWORD *)(result + 8832) )
  {
    if ( (a2 & 1) != 0 )
    {
      _X9 = (unsigned __int64 *)(result + 9128);
      __asm { PRFM            #0x11, [X9] }
      do
        v13 = __ldxr(_X9);
      while ( __stlxr(v13 | 8, _X9) );
      __dmb(0xBu);
      if ( (v13 & 8) == 0 )
      {
        v2 = *(_DWORD *)(result + 8832);
        if ( v2 >= 1 )
        {
          v3 = result;
          enable_irq((unsigned int)v2);
          result = v3;
        }
        result = *(unsigned int *)(result + 14168);
        if ( (int)result >= 1 )
          return enable_irq(result);
      }
    }
    else
    {
      _X9 = (unsigned __int64 *)(result + 9128);
      __asm { PRFM            #0x11, [X9] }
      do
        v16 = __ldxr(_X9);
      while ( __stlxr(v16 & 0xFFFFFFFFFFFFFFF7LL, _X9) );
      __dmb(0xBu);
      if ( (v16 & 8) != 0 )
      {
        v4 = *(_DWORD *)(result + 14168);
        if ( v4 >= 1 )
        {
          v5 = result;
          disable_irq((unsigned int)v4);
          result = v5;
        }
        v6 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 16);
        result = *(unsigned int *)(result + 8832);
        if ( (v6 & 0xFFFF00) != 0 )
        {
          if ( (int)result >= 1 )
            return disable_irq_nosync();
        }
        else if ( (int)result >= 1 )
        {
          return disable_irq(result);
        }
      }
    }
  }
  return result;
}
