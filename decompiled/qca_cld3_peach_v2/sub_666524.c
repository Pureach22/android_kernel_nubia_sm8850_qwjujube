__int64 __usercall sub_666524@<X0>(__int64 a1@<X8>)
{
  if ( a1 )
    return wifi_pos_get_tx_ops();
  else
    return hdd_capture_tsf_timer_expired_handler();
}
