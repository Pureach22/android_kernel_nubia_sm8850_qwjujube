__int64 __fastcall ieee80211_iterate_stations_mtx(
        __int64 result,
        __int64 (__fastcall *a2)(__int64, __int64 *),
        __int64 a3)
{
  __int64 *v3; // x21
  __int64 i; // x22

  v3 = *(__int64 **)(result + 1616);
  for ( i = result + 1616; v3 != (__int64 *)i; v3 = (__int64 *)*v3 )
  {
    if ( *((_BYTE *)v3 + 204) == 1 )
    {
      if ( *((_DWORD *)a2 - 1) != -372844944 )
        __break(0x8234u);
      result = a2(a3, v3 + 336);
    }
  }
  return result;
}
