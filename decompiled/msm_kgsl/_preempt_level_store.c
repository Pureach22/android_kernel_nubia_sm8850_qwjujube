__int64 __fastcall preempt_level_store(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x8
  int v3; // w2
  __int64 result; // x0
  int v5; // w9

  v2 = a1 + 20480;
  if ( *(_BYTE *)(a1 + 24024) == 1 )
  {
    if ( a2 >= 2 )
      v3 = 2;
    else
      v3 = a2;
    return adreno_power_cycle_u32(a1, (_DWORD *)(a1 + 20576), v3);
  }
  else
  {
    v5 = 2;
    result = 0;
    if ( a2 < 2 )
      v5 = a2;
    *(_DWORD *)(v2 + 96) = v5;
  }
  return result;
}
