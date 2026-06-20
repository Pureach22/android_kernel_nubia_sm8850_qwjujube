__int64 __fastcall wifi_pos_register_rx_ops(__int64 result)
{
  *(_QWORD *)(result + 376) = wifi_pos_oem_rsp_handler;
  *(_QWORD *)(result + 416) = wifi_pos_vdev_delete_all_ranging_peers;
  return result;
}
