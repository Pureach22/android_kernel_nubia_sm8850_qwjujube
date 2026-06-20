__int64 __fastcall _qdf_nbuf_is_ipv4_igmp_leave_pkt(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w9
  __int64 v3; // x10
  unsigned __int8 *v4; // x9
  int v5; // w8
  int v6; // w10
  unsigned int v7; // w8
  unsigned __int8 *v8; // x9
  unsigned __int8 *v9; // x11

  v1 = *(_QWORD *)(a1 + 224);
  v2 = *(unsigned __int16 *)(v1 + 12);
  if ( v2 == 129 )
  {
    v3 = 18;
    if ( *(_WORD *)(v1 + 16) != 8 )
      return 0;
  }
  else
  {
    v3 = 14;
    if ( v2 != 8 )
      return 0;
  }
  v4 = (unsigned __int8 *)(v1 + v3 + 4LL * (*(_BYTE *)(v1 + v3) & 0xF));
  v5 = *v4;
  if ( v5 != 23 )
  {
    if ( v5 != 34 || !*((_WORD *)v4 + 3) )
      return 0;
    v6 = 0;
    v7 = __rev16(*((unsigned __int16 *)v4 + 3));
    v8 = v4 + 8;
    while ( 1 )
    {
      v9 = &v8[v6];
      if ( (*v9 & 0xFD) == 1 )
        break;
      --v7;
      v6 += 4 * (bswap32(*((unsigned __int16 *)v9 + 1)) >> 16) + 8;
      if ( !v7 )
        return 0;
    }
  }
  return 1;
}
