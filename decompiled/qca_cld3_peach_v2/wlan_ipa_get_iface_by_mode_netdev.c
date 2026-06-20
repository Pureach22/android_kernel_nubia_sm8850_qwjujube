__int64 __fastcall wlan_ipa_get_iface_by_mode_netdev(__int64 a1, __int64 a2, unsigned __int8 a3, unsigned __int8 a4)
{
  if ( *(_DWORD *)(a1 + 1096) == a3 && *(_QWORD *)(a1 + 1088) == a2 && *(unsigned __int8 *)(a1 + 1116) == a4 )
    return a1 + 1064;
  if ( *(_DWORD *)(a1 + 1224) == a3 && *(_QWORD *)(a1 + 1216) == a2 && *(unsigned __int8 *)(a1 + 1244) == a4 )
    return a1 + 1192;
  if ( *(_DWORD *)(a1 + 1352) == a3 && *(_QWORD *)(a1 + 1344) == a2 && *(unsigned __int8 *)(a1 + 1372) == a4 )
    return a1 + 1320;
  return 0;
}
