bool __fastcall is_bss(__int64 a1, __int64 a2, void *s2, size_t n)
{
  __int64 v4; // x8
  unsigned __int64 v5; // x10
  _BYTE *v6; // x8
  _BYTE *v7; // x9
  __int64 v8; // x11
  _BOOL8 result; // x0

  if ( a2 && *(_DWORD *)a2 ^ *(_DWORD *)(a1 + 72) | *(unsigned __int16 *)(a2 + 4) ^ *(unsigned __int16 *)(a1 + 76) )
    return 0;
  if ( !s2 )
    return 1;
  v4 = *(_QWORD *)(a1 + 8);
  if ( !v4 )
    return 0;
  v5 = *(unsigned int *)(v4 + 24);
  if ( (unsigned int)v5 >= 2 )
  {
    v6 = (_BYTE *)(v4 + 29);
    v7 = &v6[v5];
    do
    {
      v8 = (unsigned __int8)v6[1];
      if ( v5 < v8 + 2 )
        break;
      if ( !*v6 )
      {
        result = 0;
        if ( v6 )
        {
          if ( v8 == n )
            return bcmp(v6 + 2, s2, n) == 0;
        }
        return result;
      }
      v6 += v8 + 2;
      v5 = v7 - v6;
    }
    while ( v7 - v6 > 1 );
  }
  return 0;
}
