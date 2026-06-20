bool __fastcall _qdf_nbuf_dot11_data_is_icmpv6_pkt(char *a1)
{
  int v1; // w8
  int v2; // w10
  unsigned int v3; // w9
  unsigned int v4; // w12
  int v5; // w9
  int v6; // w8

  v1 = *a1;
  if ( v1 < 0 )
  {
    if ( a1[24] < 0 )
      v2 = 40;
    else
      v2 = 26;
  }
  else
  {
    v2 = 24;
  }
  v3 = (unsigned __int8)a1[1];
  v4 = v3 >> 3;
  v5 = (v3 >> 5) & 4;
  if ( *(unsigned __int16 *)&a1[(v5 | v2) + 6 + (v4 & 8)] != 56710 )
    return 0;
  if ( v1 < 0 )
  {
    if ( a1[24] < 0 )
      v6 = 40;
    else
      v6 = 26;
  }
  else
  {
    v6 = 24;
  }
  return a1[(v4 & 8 | v5) + 14 + v6] == 58;
}
