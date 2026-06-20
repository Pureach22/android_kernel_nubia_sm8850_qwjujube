__int64 __fastcall rmnet_shs_wq_get_max_allowed_pps(unsigned __int16 a1)
{
  if ( a1 < 8u )
    return (__int64)*(&rmnet_shs_cpu_rx_max_pps_thresh + a1);
  ++qword_1A440;
  return 0;
}
