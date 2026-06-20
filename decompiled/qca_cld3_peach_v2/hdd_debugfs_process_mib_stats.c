__int64 __fastcall hdd_debugfs_process_mib_stats(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  _DWORD *v11; // x9
  int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  unsigned int v22; // w1

  qdf_trace_msg(0x33u, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "hdd_debugfs_process_mib_stats");
  qdf_mutex_acquire((__int64)&mibstats_lock);
  if ( mib_stats_1 )
  {
    v11 = *(_DWORD **)(a10 + 112);
    scnprintf(
      mib_stats_1 + mib_stats_0,
      4096 - mib_stats_0,
      "dot11RTSSuccessCount %d \n"
      "dot11RTSFailureCount %d \n"
      "dot11QosFailedCount %d \n"
      "dot11QosRetryCount %d \n"
      "dot11QosTransmittedFrameCount %d \n"
      "dot11QosMPDUsReceivedCount %d \n"
      "dot11TransmittedAMPDUCount %d \n"
      "dot11QosACKFailureCount %d",
      v11[10],
      v11[11],
      v11[14],
      v11[15],
      v11[22],
      v11[24],
      v11[34],
      v11[20]);
    mib_stats_0 += v12;
    qdf_mutex_release((__int64)&mibstats_lock);
    v21 = "%s: exit";
    v22 = 8;
  }
  else
  {
    qdf_mutex_release((__int64)&mibstats_lock);
    v21 = "%s: MIB statistics buffer is NULL";
    v22 = 2;
  }
  return qdf_trace_msg(0x33u, v22, v21, v13, v14, v15, v16, v17, v18, v19, v20, "hdd_debugfs_process_mib_stats");
}
