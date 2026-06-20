__int64 __fastcall validate_he_capa(unsigned __int8 *a1)
{
  unsigned int v1; // w19
  unsigned int v2; // w9
  unsigned int v3; // w10
  int v4; // w9
  unsigned int v5; // w20
  unsigned __int8 v7; // w21

  v1 = *a1 - 4;
  if ( v1 < 0x11 )
    return 4294967274LL;
  v2 = a1[10];
  v3 = v2 >> 2;
  v4 = (v2 & 8) != 0 ? 8 : 4;
  v5 = v4 + (v3 & 4) + 17;
  if ( v5 > (unsigned __int8)v1 )
    return 4294967274LL;
  if ( (char)a1[16] < 0 )
  {
    if ( v5 >= (unsigned __int8)v1 )
      return 4294967274LL;
    v7 = a1[v5 + 4];
    v5 += ((unsigned int)(unsigned __int8)(_sw_hweight8(v7 & 0x78) * (6 * (v7 & 7) + 6) + 7) + 7) >> 3;
  }
  if ( (unsigned __int8)v5 > (unsigned int)(unsigned __int8)v1 )
    return 4294967274LL;
  else
    return 0;
}
