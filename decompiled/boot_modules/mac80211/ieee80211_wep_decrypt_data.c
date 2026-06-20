__int64 __fastcall ieee80211_wep_decrypt_data(void *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  arc4_setkey(a1, a2, a3);
  arc4_crypt(a1, a4, a4, (unsigned int)(a5 + 4));
  memset(a1, 0, 0x408u);
  if ( ~(unsigned int)crc32_le(0xFFFFFFFFLL, a4, a5) == *(_DWORD *)(a4 + a5) )
    return 0;
  else
    return 0xFFFFFFFFLL;
}
