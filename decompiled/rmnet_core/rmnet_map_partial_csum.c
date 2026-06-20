__int64 __fastcall rmnet_map_partial_csum(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  unsigned __int64 v5; // t2
  __int64 result; // x0
  unsigned int v7; // w8
  __int64 v8; // x9
  __int16 v9; // w8
  char v10; // w9
  int v11; // w10

  v3 = *(_QWORD *)(a1 + 224);
  if ( *(_BYTE *)(a2 + 24) == 4 )
  {
    result = csum_tcpudp_nofold(
               *(unsigned int *)(v3 + 12),
               *(unsigned int *)(v3 + 16),
               (unsigned __int16)(*(_WORD *)(a1 + 112) - *(_WORD *)(a2 + 16)),
               *(unsigned __int8 *)(a2 + 25),
               0);
    HIDWORD(v5) = result;
    LODWORD(v5) = result;
    v7 = ((unsigned int)(v5 >> 16) + (unsigned int)result) >> 16;
  }
  else
  {
    result = csum_ipv6_magic(
               v3 + 8,
               v3 + 24,
               (unsigned __int16)(*(_WORD *)(a1 + 112) - *(_WORD *)(a2 + 16)),
               *(unsigned __int8 *)(a2 + 25),
               0);
    LOWORD(v7) = ~(_WORD)result;
  }
  v8 = v3 + *(unsigned __int16 *)(a2 + 16);
  if ( *(_BYTE *)(a2 + 25) == 6 )
  {
    *(_WORD *)(v8 + 16) = v7;
    v9 = 16;
  }
  else
  {
    *(_WORD *)(v8 + 6) = v7;
    v9 = 6;
  }
  v10 = *(_BYTE *)(a1 + 128);
  *(_WORD *)(a1 + 142) = v9;
  v11 = *(_DWORD *)(a1 + 216);
  *(_BYTE *)(a1 + 128) = v10 | 0x60;
  *(_WORD *)(a1 + 140) = *(_WORD *)(a1 + 224) + *(_WORD *)(a2 + 16) - v11;
  return result;
}
