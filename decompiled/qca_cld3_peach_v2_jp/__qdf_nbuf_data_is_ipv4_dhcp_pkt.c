bool __fastcall _qdf_nbuf_data_is_ipv4_dhcp_pkt(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x9
  __int64 v3; // x8
  unsigned __int16 *v4; // x9
  int v5; // w8
  int v6; // w9
  bool v7; // zf
  __int64 v10; // x9

  v1 = *(unsigned __int16 *)(a1 + 12);
  if ( v1 == 129 )
  {
    v10 = 16;
    goto LABEL_21;
  }
  if ( v1 == 43144 )
  {
    v10 = 20;
LABEL_21:
    if ( *(_WORD *)(a1 + v10) == 8 )
      goto LABEL_4;
    return 0;
  }
  if ( v1 != 8 )
    return 0;
LABEL_4:
  v2 = 14;
  if ( v1 == 43144 )
    v2 = 22;
  v7 = v1 == 129;
  v3 = 18;
  if ( !v7 )
    v3 = v2;
  v4 = (unsigned __int16 *)(a1 + v3 + 4LL * (*(_BYTE *)(a1 + v3) & 0xF));
  v5 = *v4;
  v6 = v4[1];
  v7 = v5 == 17152 && v6 == 17408;
  if ( v7 )
    return 1;
  return v5 == 17408 && v6 == 17152;
}
