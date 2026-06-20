__int64 __fastcall zs_shrinker_count(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x9
  __int64 v4; // x8
  unsigned __int64 v5; // x10
  __int64 v6; // x10
  unsigned __int64 v7; // x11
  unsigned __int64 v8; // x12
  bool v9; // cc
  unsigned __int64 v10; // x11

  result = 0;
  v3 = 255;
  v4 = *(_QWORD *)(a1 + 88);
  do
  {
    v6 = *(_QWORD *)(v4 + 8 * v3);
    if ( v3 - 1 == *(_DWORD *)(v6 + 212) )
    {
      v7 = *(_QWORD *)(v6 + 312);
      v8 = *(_QWORD *)(v6 + 320);
      v9 = v7 > v8;
      v10 = v7 - v8;
      if ( v9 )
        v5 = v10 / *(int *)(v6 + 204) * *(int *)(v6 + 208);
      else
        v5 = 0;
      result += v5;
    }
    --v3;
  }
  while ( v3 );
  return result;
}
