__int64 __fastcall gmu_core_scale_gmu_frequency(__int64 result, int a2)
{
  int v2; // w9
  unsigned int v3; // w8
  int v4; // w9
  unsigned int v5; // w1
  unsigned int v6; // w8

  v2 = *(_DWORD *)(result + 8456);
  if ( v2 )
  {
    v3 = *(_DWORD *)(*(_QWORD *)(result + 10392) + 4LL * a2);
    v4 = v2 - 1 < v3;
    if ( *(_DWORD *)(result + 8460) - 1 < v3 )
      v4 = 2;
    if ( *(_DWORD *)(result + 8464) - 1 < v3 )
      v4 = 3;
    if ( *(_DWORD *)(result + 8468) - 1 < v3 )
      v4 = 4;
    if ( *(_DWORD *)(result + 8472) - 1 < v3 )
      v4 = 5;
    if ( *(_DWORD *)(result + 8476) - 1 < v3 )
      v4 = 6;
    if ( *(_DWORD *)(result + 8480) - 1 < v3 )
      v4 = 7;
    if ( *(_DWORD *)(result + 8484) - 1 < v3 )
      v4 = 8;
    if ( *(_DWORD *)(result + 8488) - 1 < v3 )
      v4 = 9;
    if ( *(_DWORD *)(result + 8492) - 1 < v3 )
      v4 = 10;
    if ( *(_DWORD *)(result + 8496) - 1 < v3 )
      v4 = 11;
    if ( *(_DWORD *)(result + 8500) - 1 < v3 )
      v4 = 12;
    if ( *(_DWORD *)(result + 8504) - 1 < v3 )
      v4 = 13;
    if ( *(_DWORD *)(result + 8508) - 1 < v3 )
      v4 = 14;
    if ( *(_DWORD *)(result + 8512) - 1 < v3 )
      v4 = 15;
    if ( *(_DWORD *)(result + 8516) - 1 >= v3 )
      v5 = v4;
    else
      v5 = 16;
    if ( v5 <= 0xF )
    {
      v6 = *(_DWORD *)(result + 8520);
      if ( v6 != v5 )
        return gmu_core_clock_set_rate(result, v5, v6);
    }
  }
  return result;
}
