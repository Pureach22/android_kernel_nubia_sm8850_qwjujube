__int64 __fastcall sde_encoder_phys_cmd_wait_for_vblank(__int64 a1)
{
  __int64 result; // x0
  unsigned int v2; // w8
  int v3; // w9
  unsigned int v10; // w9
  _QWORD v11[5]; // [xsp+8h] [xbp-28h] BYREF

  v11[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[2] = 0;
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 664) == 3 )
    {
      result = 0;
    }
    else
    {
      v2 = *(_DWORD *)(a1 + 2692);
      if ( v2 <= 1 )
        v2 = 1;
      v3 = v2 * *(_DWORD *)(a1 + 992);
      _X8 = (unsigned int *)(a1 + 2728);
      v11[0] = a1 + 2736;
      v11[1] = a1 + 2728;
      v11[3] = v3;
      __asm { PRFM            #0x11, [X8] }
      do
        v10 = __ldxr(_X8);
      while ( __stxr(v10 + 1, _X8) );
      result = sde_encoder_helper_wait_for_irq((__int64 **)a1, 8u, v11);
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
