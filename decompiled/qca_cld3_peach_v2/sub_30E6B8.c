__int64 __fastcall sub_30E6B8(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  return wlan_hdd_send_avoid_freq_for_dnbs(a1, a2, a3, a4, a5, a6, a3 ^ (a8 << 43));
}
