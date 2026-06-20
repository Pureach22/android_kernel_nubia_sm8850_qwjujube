_QWORD *__fastcall wlan_mlme_register_rx_ops(_QWORD *result)
{
  *result = wlan_mlme_set_peer_indicated_ch_width;
  return result;
}
