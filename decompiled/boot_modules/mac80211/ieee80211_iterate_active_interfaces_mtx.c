__int64 __fastcall ieee80211_iterate_active_interfaces_mtx(
        __int64 a1,
        char a2,
        __int64 (__fastcall *a3)(__int64, char *, __int64 *),
        __int64 a4)
{
  return _iterate_interfaces(a1, a2 | 2u, a3, a4);
}
