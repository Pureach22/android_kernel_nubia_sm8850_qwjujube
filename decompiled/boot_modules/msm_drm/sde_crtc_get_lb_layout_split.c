__int64 __fastcall sde_crtc_get_lb_layout_split(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x10
  __int64 *v4; // x9
  __int64 *v5; // x10
  __int64 result; // x0
  __int64 v7; // x12
  _DWORD *v8; // x12
  int v9; // w12

  v2 = *(_QWORD *)(a2 + 328);
  v3 = *(_QWORD *)(v2 + 8);
  v4 = *(__int64 **)(v3 + 840);
  v5 = (__int64 *)(v3 + 840);
  if ( v4 == v5 )
    return 0x7FFFFFFF;
  result = 0x7FFFFFFF;
  do
  {
    v7 = *((unsigned int *)v4 + 437);
    if ( ((*(_DWORD *)(a2 + 12) >> v7) & 1) != 0 )
    {
      v8 = *(_DWORD **)(*(_QWORD *)(v2 + 24) + 32 * v7 + 8);
      if ( v8 )
      {
        if ( v8[412] == 4 && v8[449] )
        {
          v9 = v8[8];
          if ( (int)result >= v9 )
            result = (unsigned int)v9;
          else
            result = (unsigned int)result;
        }
      }
    }
    v4 = (__int64 *)*v4;
  }
  while ( v4 != v5 );
  return result;
}
