__int64 sub_214664()
{
  __int16 v0; // w28

  if ( (v0 & 0x400) != 0 )
    JUMPOUT(0x211A20);
  return wmi_unified_peer_multi_rx_reorder_queue_setup_send();
}
