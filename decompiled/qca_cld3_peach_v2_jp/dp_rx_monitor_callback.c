__int64 dp_rx_monitor_callback()
{
  return ((__int64 (*)(void))dp_mon_rx_packet_cbk)();
}
