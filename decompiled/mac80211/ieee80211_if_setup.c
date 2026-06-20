__int64 __fastcall ieee80211_if_setup(__int64 a1)
{
  __int64 result; // x0

  result = ether_setup();
  *(_QWORD *)a1 = *(_QWORD *)a1 & 0xFFFFFFFFFFF7F7FFLL | 0x80000;
  *(_QWORD *)(a1 + 8) = &ieee80211_dataif_ops;
  *(_BYTE *)(a1 + 1348) = 1;
  return result;
}
