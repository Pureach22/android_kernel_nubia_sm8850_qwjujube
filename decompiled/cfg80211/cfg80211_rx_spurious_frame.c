__int64 __fastcall cfg80211_rx_spurious_frame(__int64 a1, __int64 a2, unsigned int a3)
{
  int v3; // w8
  char v5; // w0

  v3 = *(_DWORD *)(*(_QWORD *)(a1 + 992) + 8LL);
  if ( v3 == 3 || v3 == 9 )
  {
    v5 = ((__int64 (*)(void))_nl80211_unexpected_frame)();
  }
  else
  {
    __break(0x800u);
    trace_cfg80211_return_bool(0, a2, a2, a3);
    v5 = 0;
  }
  return v5 & 1;
}
