__int64 __fastcall sub_751D8(__int64 a1, __int64 a2)
{
  _BYTE *v2; // x27
  _BYTE v3[10]; // q22
  _BYTE v4[10]; // q23
  _BYTE v5[10]; // q24
  _BYTE v6[10]; // q25

  *v2 = v3[9];
  v2[1] = v4[9];
  v2[2] = v5[9];
  v2[3] = v6[9];
  return ieee80211_rx_bss_put(a1, a2);
}
