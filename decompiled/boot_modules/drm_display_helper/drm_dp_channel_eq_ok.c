__int64 __fastcall drm_dp_channel_eq_ok(__int64 a1, int a2)
{
  int v3; // w10
  unsigned int v4; // w11
  char v5; // w12
  _BOOL4 v6; // w8
  bool v7; // zf

  if ( (*(_BYTE *)(a1 + 2) & 1) == 0 )
    return 0;
  if ( a2 < 1 )
    return 1;
  v3 = 0;
  v4 = 0;
  do
  {
    v5 = v3 & 4;
    v3 += 4;
    v6 = ((*(unsigned __int8 *)(a1 + ((unsigned __int64)v4 >> 1)) >> v5) & 7) == 7;
    v7 = ((*(unsigned __int8 *)(a1 + ((unsigned __int64)v4 >> 1)) >> v5) & 7) != 7 || a2 - 1 == v4;
    ++v4;
  }
  while ( !v7 );
  return v6;
}
