bool __fastcall drm_dp_128b132b_lane_symbol_locked(_BYTE *a1, int a2)
{
  int v3; // w10
  int v4; // w8
  int v5; // w9
  char v6; // w11

  if ( a2 < 1 )
    return 1;
  if ( (*a1 & 4) == 0 )
    return 0;
  v3 = 1;
  v4 = 4;
  do
  {
    v5 = v3;
    if ( a2 == v3 )
      break;
    v6 = v4 & 4;
    v4 += 4;
    ++v3;
  }
  while ( (((unsigned __int8)a1[(unsigned __int64)(unsigned int)v5 >> 1] >> v6) & 4) != 0 );
  return v5 >= a2;
}
