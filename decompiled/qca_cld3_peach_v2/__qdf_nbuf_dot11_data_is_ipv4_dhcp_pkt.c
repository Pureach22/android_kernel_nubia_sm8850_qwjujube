bool __fastcall _qdf_nbuf_dot11_data_is_ipv4_dhcp_pkt(char *a1)
{
  int v1; // w11
  int v2; // w8
  unsigned int v3; // w9
  unsigned int v4; // w12
  int v5; // w9
  int v6; // w10
  int v7; // w11
  char *v8; // x9
  int v9; // w8
  int v10; // w9

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
  v6 = v4 & 8;
  if ( v1 < 0 )
  {
    if ( a1[24] < 0 )
      v7 = 40;
    else
      v7 = 26;
  }
  else
  {
    v7 = 24;
  }
  if ( *(_WORD *)&a1[(v6 | v5) + 6 + v7] != 8 )
    return 0;
  v8 = &a1[4 * (a1[(v5 | v2) + 8 + v6] & 0xF) + 8 + (v5 | v2) + v6];
  v9 = *(unsigned __int16 *)v8;
  v10 = *((unsigned __int16 *)v8 + 1);
  if ( v9 == 17152 && v10 == 17408 )
    return 1;
  return v9 == 17408 && v10 == 17152;
}
