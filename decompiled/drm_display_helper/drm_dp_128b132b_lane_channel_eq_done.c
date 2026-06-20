bool __fastcall drm_dp_128b132b_lane_channel_eq_done(__int64 a1, int a2)
{
  int v3; // w10
  unsigned int v4; // w12
  char v5; // w13
  int v6; // w13
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
    v6 = (2 << v5) & *(unsigned __int8 *)(a1 + ((unsigned __int64)v4 >> 1));
    if ( v6 )
      v7 = a2 - 1 == v4;
    else
      v7 = 1;
    ++v4;
  }
  while ( !v7 );
  return v6 != 0;
}
