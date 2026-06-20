__int64 __fastcall wlan_tdls_handle_p2p_client_connect(__int64 a1)
{
  __int64 result; // x0

  result = policy_mgr_get_connection_count(a1);
  if ( (_DWORD)result )
    return wlan_tdls_post_set_off_channel_mode(a1);
  return result;
}
