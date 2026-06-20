__int64 __fastcall a6xx_counter_enable(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 v4; // x19
  __int64 result; // x0

  v4 = *(_QWORD *)a2 + 48LL * a3;
  if ( (*(_BYTE *)(a2 + 24) & 2) != 0 )
  {
    result = a6xx_perfcounter_update(a1, (unsigned int *)(*(_QWORD *)a2 + 48LL * a3), 1);
    if ( (_DWORD)result )
      return result;
  }
  else
  {
    kgsl_regmap_write(a1 + 13200, a4);
  }
  *(_QWORD *)(v4 + 32) = 0;
  return 0;
}
