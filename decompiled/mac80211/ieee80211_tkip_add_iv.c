__int64 __fastcall ieee80211_tkip_add_iv(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  *(_BYTE *)(a1 + 2) = a3;
  *(_BYTE *)a1 = BYTE1(a3);
  *(_BYTE *)(a1 + 1) = BYTE1(a3) & 0x5F | 0x20;
  *(_BYTE *)(a1 + 3) = (*(_BYTE *)(a2 + 15) << 6) | 0x20;
  *(_DWORD *)(a1 + 4) = a3 >> 16;
  return a1 + 8;
}
