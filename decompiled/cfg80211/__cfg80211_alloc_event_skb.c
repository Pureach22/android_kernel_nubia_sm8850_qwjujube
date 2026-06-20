__int64 __fastcall _cfg80211_alloc_event_skb(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        int a8)
{
  __int64 v9; // x7

  if ( !a1 )
  {
    __break(0x800u);
    JUMPOUT(0x473AC);
  }
  if ( a3 == 103 )
  {
    if ( (a6 & 0x80000000) == 0 && *(_DWORD *)(a1 + 1388) > (signed int)a6 )
    {
      v9 = *(_QWORD *)(a1 + 1376) + 8LL * a6;
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, int))_cfg80211_alloc_vendor_skb)(
               a1 - 992,
               a2,
               a7,
               a5,
               0,
               a3,
               a4,
               v9,
               a8);
    }
  }
  else if ( a3 == 45 && a6 == -1 )
  {
    v9 = 0;
    return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, int))_cfg80211_alloc_vendor_skb)(
             a1 - 992,
             a2,
             a7,
             a5,
             0,
             a3,
             a4,
             v9,
             a8);
  }
  __break(0x800u);
  return 0;
}
