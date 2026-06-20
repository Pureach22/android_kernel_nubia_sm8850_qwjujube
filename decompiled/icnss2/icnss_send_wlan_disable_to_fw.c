__int64 __fastcall icnss_send_wlan_disable_to_fw(__int64 a1)
{
  return wlfw_wlan_mode_send_sync_msg(a1, 4);
}
