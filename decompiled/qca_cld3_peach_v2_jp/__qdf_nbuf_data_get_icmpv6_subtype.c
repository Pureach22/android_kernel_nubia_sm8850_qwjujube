__int64 __fastcall _qdf_nbuf_data_get_icmpv6_subtype(_BYTE *a1)
{
  int v1; // w8
  unsigned int v2; // w8

  v1 = (unsigned __int8)a1[54];
  if ( v1 == 58 )
  {
    if ( a1[20] )
      return 0;
    v1 = (unsigned __int8)a1[62];
  }
  v2 = v1 ^ 0x80;
  if ( v2 <= 8 )
    return dword_9DE234[v2];
  return 0;
}
