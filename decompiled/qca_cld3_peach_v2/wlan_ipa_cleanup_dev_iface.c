__int64 __fastcall wlan_ipa_cleanup_dev_iface(
        __int64 result,
        __int64 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 *v11; // x0

  if ( *(_QWORD *)(result + 1088) == a2 && *(unsigned __int8 *)(result + 1116) == a3 )
  {
    v11 = (__int64 *)(result + 1064);
    return wlan_ipa_cleanup_iface(v11, nullptr, a4, a5, a6, a7, a8, a9, a10, a11);
  }
  if ( *(_QWORD *)(result + 1216) == a2 && *(unsigned __int8 *)(result + 1244) == a3 )
  {
    v11 = (__int64 *)(result + 1192);
    return wlan_ipa_cleanup_iface(v11, nullptr, a4, a5, a6, a7, a8, a9, a10, a11);
  }
  if ( *(_QWORD *)(result + 1344) == a2 && *(unsigned __int8 *)(result + 1372) == a3 )
  {
    v11 = (__int64 *)(result + 1320);
    return wlan_ipa_cleanup_iface(v11, nullptr, a4, a5, a6, a7, a8, a9, a10, a11);
  }
  return result;
}
