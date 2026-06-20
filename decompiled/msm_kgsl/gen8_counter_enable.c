__int64 __fastcall gen8_counter_enable(__int64 a1, _QWORD *a2, unsigned int a3)
{
  __int64 v3; // x19
  __int64 result; // x0

  v3 = *a2 + 48LL * a3;
  result = gen8_perfcounter_update(a1, (int *)v3, 1, 0, a2[3]);
  if ( !(_DWORD)result )
    *(_QWORD *)(v3 + 32) = 0;
  return result;
}
