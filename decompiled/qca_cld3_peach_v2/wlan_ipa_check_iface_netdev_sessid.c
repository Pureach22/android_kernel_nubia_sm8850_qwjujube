bool __fastcall wlan_ipa_check_iface_netdev_sessid(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  return *(_QWORD *)(a1 + 24) == a2 && *(unsigned __int8 *)(a1 + 52) == a3;
}
