__int64 __fastcall ieee80211_add_wmm_info_ie(__int64 a1, char a2)
{
  *(_BYTE *)(a1 + 8) = a2;
  *(_QWORD *)a1 = 0x10002F2500007DDLL;
  return a1 + 9;
}
