__int64 __fastcall ieee80211_clear_tpe(__int64 result)
{
  *(_BYTE *)result = 0;
  *(_DWORD *)(result + 1) = 2139062143;
  *(_BYTE *)(result + 5) = 127;
  *(_BYTE *)(result + 14) = 0;
  *(_DWORD *)(result + 15) = 2139062143;
  *(_BYTE *)(result + 19) = 127;
  *(_BYTE *)(result + 28) = 0;
  *(_QWORD *)(result + 29) = 0x7F7F7F7F7F7F7F7FLL;
  *(_QWORD *)(result + 37) = 0x7F7F7F7F7F7F7F7FLL;
  *(_BYTE *)(result + 66) = 0;
  *(_QWORD *)(result + 67) = 0x7F7F7F7F7F7F7F7FLL;
  *(_QWORD *)(result + 75) = 0x7F7F7F7F7F7F7F7FLL;
  *(_BYTE *)(result + 7) = 0;
  *(_DWORD *)(result + 8) = 2139062143;
  *(_BYTE *)(result + 12) = 127;
  *(_BYTE *)(result + 21) = 0;
  *(_BYTE *)(result + 26) = 127;
  *(_DWORD *)(result + 22) = 2139062143;
  *(_BYTE *)(result + 47) = 0;
  *(_QWORD *)(result + 48) = 0x7F7F7F7F7F7F7F7FLL;
  *(_QWORD *)(result + 56) = 0x7F7F7F7F7F7F7F7FLL;
  *(_BYTE *)(result + 85) = 0;
  *(_QWORD *)(result + 86) = 0x7F7F7F7F7F7F7F7FLL;
  *(_QWORD *)(result + 94) = 0x7F7F7F7F7F7F7F7FLL;
  return result;
}
