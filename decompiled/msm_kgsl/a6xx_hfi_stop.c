__int64 __fastcall a6xx_hfi_stop(__int64 a1)
{
  __int64 v2; // x19
  __int64 result; // x0
  unsigned __int64 v10; // x10

  v2 = to_a6xx_gmu(a1);
  result = kgsl_pwrctrl_axi(a1, 0);
  _X8 = (unsigned __int64 *)(v2 + 1296);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  return result;
}
