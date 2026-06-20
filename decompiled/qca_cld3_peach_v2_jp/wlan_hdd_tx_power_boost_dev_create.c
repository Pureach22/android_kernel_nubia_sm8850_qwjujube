__int64 wlan_hdd_tx_power_boost_dev_create()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  major = (unsigned int)device >> 20;
  minor = (device & 0xFFFFF) + 1;
  if ( (unsigned __int64)device_create(class, 0, ((device & 0xFFFFF) + 1) | device & 0xFFF00000, 0, "txpb") < 0xFFFFFFFFFFFFF001LL )
  {
    cdev_init(&tx_pb_cdev, &tx_power_boost_fops);
    qword_86A760 = (__int64)&_this_module;
    if ( (unsigned int)cdev_add(&tx_pb_cdev, minor | (unsigned int)(major << 20), 1) )
    {
      printk(&unk_8A71F5, v9, v10, v11);
      device_destroy(class, minor | (unsigned int)(major << 20));
      return 16;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: TPB: device '%s' major: %d minor: %d initialized",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_hdd_tx_power_boost_dev_create",
        "txpb",
        (unsigned int)major,
        (unsigned int)minor);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: TPB: device_create (%s) failed",
      v0,
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      "wlan_hdd_tx_power_boost_dev_create",
      "txpb");
    return 16;
  }
}
