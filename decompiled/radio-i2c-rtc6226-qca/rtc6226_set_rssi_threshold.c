__int64 __fastcall rtc6226_set_rssi_threshold(__int64 a1, __int16 a2)
{
  char v2; // w19
  __int64 result; // x0

  v2 = a2;
  *(_WORD *)(a1 + 1772) = *(_WORD *)(a1 + 1772) & 0xF0FF | (a2 << 6) & 0xFF00;
  result = rtc6226_set_register(a1, 5);
  *(_BYTE *)(a1 + 1761) = v2 & 0xFC;
  return result;
}
