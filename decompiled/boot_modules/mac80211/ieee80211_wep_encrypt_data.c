__int64 __fastcall ieee80211_wep_encrypt_data(void *a1, __int64 a2, unsigned int a3, __int64 a4, __int64 a5)
{
  int v8; // w19

  v8 = a5;
  *(_DWORD *)(a4 + a5) = ~(unsigned int)crc32_le(0xFFFFFFFFLL, a4, a5);
  arc4_setkey(a1, a2, a3);
  arc4_crypt(a1, a4, a4, (unsigned int)(v8 + 4));
  memset(a1, 0, 0x408u);
  return 0;
}
