__int64 __fastcall sme_get_beaconing_concurrent_operation_channel(__int64 a1, unsigned int a2)
{
  unsigned int beaconing_concurrent_channel; // w21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  if ( (unsigned int)qdf_mutex_acquire(a1 + 12776) )
    return 0;
  beaconing_concurrent_channel = csr_get_beaconing_concurrent_channel(a1, a2);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Other Concurrent Chan_freq: %d skipped vdev_id %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "sme_get_beaconing_concurrent_operation_channel",
    beaconing_concurrent_channel,
    (unsigned __int8)a2);
  qdf_mutex_release(a1 + 12776);
  return beaconing_concurrent_channel;
}
