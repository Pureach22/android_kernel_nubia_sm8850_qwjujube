__int64 __fastcall set_wmm_rule(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 result; // x0
  unsigned int v7; // w8

  v5 = a1 + 4LL * (bswap32(*(unsigned __int16 *)(a3 + 18)) >> 16);
  result = valid_wmm(v5);
  if ( (result & 1) == 0 )
    return printk(&unk_B89A5);
  *(_WORD *)(a4 + 20) = ~(unsigned __int16)(-1 << (*(_BYTE *)v5 >> 4));
  *(_WORD *)(a4 + 22) = ~(unsigned __int16)(-1 << (*(_BYTE *)v5 & 0xF));
  *(_BYTE *)(a4 + 26) = *(_BYTE *)(v5 + 1);
  *(_WORD *)(a4 + 24) = 1000 * (bswap32(*(unsigned __int16 *)(v5 + 2)) >> 16);
  *(_WORD *)(a4 + 52) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 16) >> 4));
  *(_WORD *)(a4 + 54) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 16) & 0xF));
  *(_BYTE *)(a4 + 58) = *(_BYTE *)(v5 + 17);
  *(_WORD *)(a4 + 56) = 1000 * (bswap32(*(unsigned __int16 *)(v5 + 18)) >> 16);
  *(_WORD *)(a4 + 28) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 4) >> 4));
  *(_WORD *)(a4 + 30) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 4) & 0xF));
  *(_BYTE *)(a4 + 34) = *(_BYTE *)(v5 + 5);
  *(_WORD *)(a4 + 32) = 1000 * (bswap32(*(unsigned __int16 *)(v5 + 6)) >> 16);
  *(_WORD *)(a4 + 60) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 20) >> 4));
  *(_WORD *)(a4 + 62) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 20) & 0xF));
  *(_BYTE *)(a4 + 66) = *(_BYTE *)(v5 + 21);
  *(_WORD *)(a4 + 64) = 1000 * (bswap32(*(unsigned __int16 *)(v5 + 22)) >> 16);
  *(_WORD *)(a4 + 36) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 8) >> 4));
  *(_WORD *)(a4 + 38) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 8) & 0xF));
  *(_BYTE *)(a4 + 42) = *(_BYTE *)(v5 + 9);
  *(_WORD *)(a4 + 40) = 1000 * (bswap32(*(unsigned __int16 *)(v5 + 10)) >> 16);
  *(_WORD *)(a4 + 68) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 24) >> 4));
  *(_WORD *)(a4 + 70) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 24) & 0xF));
  *(_BYTE *)(a4 + 74) = *(_BYTE *)(v5 + 25);
  *(_WORD *)(a4 + 72) = 1000 * (bswap32(*(unsigned __int16 *)(v5 + 26)) >> 16);
  *(_WORD *)(a4 + 44) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 12) >> 4));
  *(_WORD *)(a4 + 46) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 12) & 0xF));
  *(_BYTE *)(a4 + 50) = *(_BYTE *)(v5 + 13);
  *(_WORD *)(a4 + 48) = 1000 * (bswap32(*(unsigned __int16 *)(v5 + 14)) >> 16);
  *(_WORD *)(a4 + 76) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 28) >> 4));
  *(_WORD *)(a4 + 78) = ~(unsigned __int16)(-1 << (*(_BYTE *)(v5 + 28) & 0xF));
  *(_BYTE *)(a4 + 82) = *(_BYTE *)(v5 + 29);
  v7 = 1000 * (bswap32(*(unsigned __int16 *)(v5 + 30)) >> 16);
  *(_BYTE *)(a4 + 92) = 1;
  *(_WORD *)(a4 + 80) = v7;
  return result;
}
