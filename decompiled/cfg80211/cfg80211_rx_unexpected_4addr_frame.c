__int64 __fastcall cfg80211_rx_unexpected_4addr_frame(__int64 a1)
{
  unsigned int v1; // w8
  bool v2; // cc
  int v3; // w8
  char v5; // w0

  v1 = *(_DWORD *)(*(_QWORD *)(a1 + 992) + 8LL);
  v2 = v1 > 9;
  v3 = (1 << v1) & 0x218;
  if ( v2 || v3 == 0 )
  {
    __break(0x800u);
    v5 = 0;
  }
  else
  {
    v5 = ((__int64 (*)(void))_nl80211_unexpected_frame)();
  }
  return v5 & 1;
}
