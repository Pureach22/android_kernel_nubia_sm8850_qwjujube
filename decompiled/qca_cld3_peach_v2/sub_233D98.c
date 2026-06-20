__int64 sub_233D98()
{
  __int16 v0; // w28

  if ( (v0 & 0x400) != 0 )
    JUMPOUT(0x231154);
  return wmi_unified_peer_multi_rx_reorder_queue_setup_send();
}
