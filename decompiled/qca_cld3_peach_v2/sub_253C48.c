__int64 sub_253C48()
{
  __int16 v0; // w28

  if ( (v0 & 0x400) != 0 )
    JUMPOUT(0x251004);
  return send_peer_multi_rx_reorder_queue_setup_cmd_tlv();
}
