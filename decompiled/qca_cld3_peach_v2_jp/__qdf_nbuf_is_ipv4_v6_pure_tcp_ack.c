__int64 __fastcall _qdf_nbuf_is_ipv4_v6_pure_tcp_ack(__int64 a1)
{
  int v1; // w8
  __int64 v3; // x8
  int v4; // w9
  __int64 v5; // x9

  if ( (*(_BYTE *)(a1 + 68) & 4) != 0 )
    v1 = *(unsigned __int16 *)(a1 + 66);
  else
    v1 = 0;
  if ( (unsigned int)(*(_DWORD *)(a1 + 112) + v1) > 0x64 || *(_DWORD *)(a1 + 116) )
    return 0;
  v3 = *(_QWORD *)(a1 + 224);
  v4 = *(unsigned __int16 *)(v3 + 12);
  if ( v4 == 56710 )
  {
    if ( *(_BYTE *)(v3 + 20) == 6
      && ((*(unsigned __int8 *)(v3 + 66) >> 2) & 0x3C) == bswap32(*(unsigned __int16 *)(v3 + 18)) >> 16 )
    {
      v5 = 67;
      return (*(unsigned __int8 *)(v3 + v5) >> 4) & 1;
    }
    return 0;
  }
  if ( v4 != 8
    || *(_BYTE *)(v3 + 23) != 6
    || ((*(unsigned __int8 *)(v3 + 46) >> 2) & 0x3C) != (unsigned __int16)((bswap32(*(unsigned __int16 *)(v3 + 16)) >> 16)
                                                                         - 20) )
  {
    return 0;
  }
  v5 = 47;
  return (*(unsigned __int8 *)(v3 + v5) >> 4) & 1;
}
