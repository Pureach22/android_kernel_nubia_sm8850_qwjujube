__int64 __fastcall sde_copy_formats(__int64 a1, int a2, unsigned int a3, __int64 a4, unsigned int a5)
{
  unsigned __int64 v5; // x9
  _QWORD *v6; // x11
  unsigned __int64 v7; // x8
  __int64 v8; // x13

  if ( !a1 )
    return 0;
  if ( !a4 )
    return 0;
  v5 = (unsigned int)(a2 - 1);
  if ( (unsigned int)v5 <= a3 )
    return 0;
  if ( a5 )
  {
    v6 = (_QWORD *)(a1 + 16LL * a3);
    v7 = 0;
    do
    {
      if ( !*(_DWORD *)a4 )
        break;
      v8 = *(_QWORD *)(a4 + 8);
      ++v7;
      *v6 = *(_QWORD *)a4;
      v6[1] = v8;
      if ( v7 + a3 >= v5 )
        break;
      v6 += 2;
      a4 += 16;
    }
    while ( v7 < a5 );
    a3 += v7;
  }
  else
  {
    LODWORD(v7) = 0;
  }
  *(_DWORD *)(a1 + 16LL * a3) = 0;
  return (unsigned int)v7;
}
