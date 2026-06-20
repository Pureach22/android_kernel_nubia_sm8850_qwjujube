__int64 __fastcall sub_1A9B14(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned __int128 *v5; // x17
  __int64 v6; // kr08_8

  v6 = __ldaxp(v5) >> 64;
  return wlan_objmgr_register_peer_phymode_change_notify_handler(a1, a2, a3, a4, a5, v6);
}
