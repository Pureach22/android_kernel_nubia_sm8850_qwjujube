__int64 __fastcall stm_generic_link(__int64 a1, __int64 a2)
{
  __int64 v2; // x0

  if ( a1 == 64 )
    return 4294967274LL;
  v2 = *(_QWORD *)(a1 - 40);
  if ( !v2 )
    return 4294967274LL;
  else
    return coresight_enable_sysfs(v2, a2);
}
