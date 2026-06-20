__int64 *__fastcall cfg80211_init_wdev(__int64 *result)
{
  __int64 v1; // x9
  __int64 v2; // x10
  unsigned int v3; // w9

  result[18] = (__int64)(result + 18);
  result[19] = (__int64)(result + 18);
  *((_DWORD *)result + 40) = 0;
  result[6] = (__int64)(result + 6);
  result[7] = (__int64)(result + 6);
  result[27] = (__int64)(result + 27);
  result[28] = (__int64)(result + 27);
  *((_DWORD *)result + 58) = 0;
  result[30] = 0xFFFFFFFE00000LL;
  result[31] = (__int64)(result + 31);
  result[32] = (__int64)(result + 31);
  result[33] = (__int64)cfg80211_pmsr_free_wk;
  result[23] = (__int64)(result + 23);
  result[24] = (__int64)(result + 23);
  v1 = *result;
  result[25] = (__int64)cfg80211_cqm_rssi_notify_work;
  *((_BYTE *)result + 165) = (*(_BYTE *)(v1 + 100) & 0x10) != 0;
  *((_DWORD *)result + 42) = -1;
  v2 = -1LL << *(_DWORD *)(v1 + 1496);
  v3 = *((_DWORD *)result + 2);
  *((_DWORD *)result + 369) = ~(_DWORD)v2;
  if ( v3 <= 8 && ((1 << v3) & 0x106) != 0 && (*((_BYTE *)result + 65) & 1) == 0 )
    *(_QWORD *)result[4] |= 0x40uLL;
  result[13] = 0xFFFFFFFE00000LL;
  result[14] = (__int64)(result + 14);
  result[15] = (__int64)(result + 14);
  result[16] = (__int64)cfg80211_autodisconnect_wk;
  return result;
}
