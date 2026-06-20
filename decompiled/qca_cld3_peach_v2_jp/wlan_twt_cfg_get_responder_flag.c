__int64 __fastcall wlan_twt_cfg_get_responder_flag(__int64 a1, unsigned __int8 a2, _BYTE *a3)
{
  unsigned __int8 macid_by_vdev_id; // w0
  __int64 result; // x0
  unsigned __int8 v7; // w1

  macid_by_vdev_id = policy_mgr_mode_get_macid_by_vdev_id(a1, a2);
  if ( macid_by_vdev_id != 0xFF )
  {
    v7 = macid_by_vdev_id;
    return wlan_twt_cfg_get_mac_responder_flag(a1, v7, a3);
  }
  result = wlan_twt_cfg_get_mac_responder_flag(a1, 0, a3);
  if ( (*a3 & 1) == 0 )
  {
    result = wlan_twt_cfg_get_mac_responder_flag(a1, 1u, a3);
    if ( (*a3 & 1) == 0 )
    {
      v7 = 2;
      return wlan_twt_cfg_get_mac_responder_flag(a1, v7, a3);
    }
  }
  return result;
}
