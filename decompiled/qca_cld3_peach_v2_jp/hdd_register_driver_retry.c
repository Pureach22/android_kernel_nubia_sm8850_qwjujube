__int64 hdd_register_driver_retry()
{
  unsigned int v0; // w21
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  unsigned int i; // w19
  unsigned int v10; // w0

  v0 = wlan_hdd_register_driver();
  if ( v0 == -11 )
  {
    for ( i = 0; ; ++i )
    {
      v0 = -11;
      qdf_trace_msg(
        0x33u,
        4u,
        "Retry Platform Driver Registration; errno:%d count:%d",
        v1,
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        4294967285LL,
        i);
      if ( i == 49 )
        break;
      msleep(100);
      v10 = wlan_hdd_register_driver();
      if ( v10 != -11 )
        return v10;
    }
  }
  return v0;
}
