__int64 __fastcall a5xx_counter_rbbm_enable(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  if ( a4 || **(_DWORD **)(a1 + 14264) != 540 )
    return a5xx_counter_inline_enable((__int64 *)a1, a2, a3, a4);
  else
    return 4294967274LL;
}
