_WORD *__fastcall rmnet_wlan_inet_proto_csum_replace4(_WORD *result, __int64 a2, int a3, unsigned int a4, char a5)
{
  unsigned int v5; // w8
  unsigned __int64 v6; // t2
  unsigned int v7; // w9
  bool v8; // cf
  unsigned int v9; // w9
  unsigned __int64 v10; // t2
  unsigned int v11; // w9
  unsigned int v12; // w8

  if ( (~*(unsigned __int8 *)(a2 + 128) & 0x60) != 0 )
  {
    v7 = -2 - a3 - (unsigned __int16)*result;
    v8 = v7 >= ~a3;
    v9 = v7 + a4;
    if ( !v8 )
      ++v9;
    if ( v9 < a4 )
      ++v9;
    HIDWORD(v10) = v9;
    LODWORD(v10) = v9;
    *result = ~(((unsigned int)(v10 >> 16) + v9) >> 16);
    if ( (*(_BYTE *)(a2 + 128) & 0x60) == 0x40 && (a5 & 1) != 0 )
    {
      v11 = -2 - a3 - *(_DWORD *)(a2 + 140);
      v12 = v11 + a4;
      if ( v11 < ~a3 )
        ++v12;
      if ( v12 < a4 )
        ++v12;
      *(_DWORD *)(a2 + 140) = ~v12;
    }
  }
  else if ( (a5 & 1) != 0 )
  {
    v5 = a4 + __CFADD__((unsigned __int16)*result, ~a3) + (unsigned __int16)*result + ~a3;
    if ( v5 < a4 )
      ++v5;
    HIDWORD(v6) = v5;
    LODWORD(v6) = v5;
    *result = ((unsigned int)(v6 >> 16) + v5) >> 16;
  }
  return result;
}
