_QWORD *__fastcall wlan_hdd_txrx_pause_cb(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10,
        unsigned int a11)
{
  _QWORD *result; // x0

  result = _cds_get_context(51, (__int64)"wlan_hdd_txrx_pause_cb", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( result )
  {
    result = (_QWORD *)hdd_get_link_info_by_vdev(result);
    if ( result )
      return (_QWORD *)wlan_hdd_netif_queue_control(*result, a10, a11);
  }
  return result;
}
