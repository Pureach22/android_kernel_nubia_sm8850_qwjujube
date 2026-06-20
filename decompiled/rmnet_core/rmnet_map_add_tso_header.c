__int64 __fastcall rmnet_map_add_tso_header(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int16 v7; // w8
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 result; // x0
  __int64 v11; // x8

  if ( (*(_DWORD *)(a3 + 185) & 0x2001D00) != 0 )
  {
    v6 = skb_push(a1, 4);
    *(_DWORD *)v6 = 6;
    if ( (*(_BYTE *)(a2 + 11) & 0x10) != 0 && *(_DWORD *)(a1 + 144) == 14286874 )
    {
      ++*(_QWORD *)(a3 + 3096);
      v7 = *(_WORD *)v6 | 0xA000;
      *(_WORD *)v6 |= 0x2000u;
    }
    else
    {
      v7 = -32762;
    }
    *(_WORD *)(v6 + 2) = bswap32(*(unsigned __int16 *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 4LL)) >> 16;
    v8 = *(_QWORD *)(a1 + 216);
    v9 = *(unsigned int *)(a1 + 212);
    if ( (*(_BYTE *)(v8 + v9 + 24) & 8) != 0 )
    {
      *(_WORD *)v6 = v7;
      v8 = *(_QWORD *)(a1 + 216);
      v9 = *(unsigned int *)(a1 + 212);
    }
    result = 0;
    *(_BYTE *)(a1 + 128) &= 0x9Fu;
    *(_WORD *)(v8 + v9 + 4) = 0;
    *(_WORD *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 6LL) = 0;
    *(_DWORD *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 24LL) = 0;
    v11 = 3104;
  }
  else
  {
    result = 4294967274LL;
    v11 = 3112;
  }
  ++*(_QWORD *)(a3 + v11);
  return result;
}
