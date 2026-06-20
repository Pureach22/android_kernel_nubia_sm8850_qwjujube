__int64 __fastcall wlan_hdd_set_mcc_p2p_quota(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v10; // x20
  int concurrency_mode; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int operating_chan_freq; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned __int8 v32; // w21
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x21
  unsigned int mcc_operating_channel; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned __int8 v51; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned __int8 v60; // w21
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w1

  if ( a1 )
  {
    v10 = *(__int64 **)(a1 + 24);
    if ( v10 )
    {
      concurrency_mode = policy_mgr_get_concurrency_mode(*v10);
      if ( (~concurrency_mode & 5) == 0 || (concurrency_mode & 9) == 9 )
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: STA & P2P are both enabled",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_hdd_set_mcc_p2p_quota");
        operating_chan_freq = hdd_get_operating_chan_freq((__int64)v10, *(_DWORD *)(a1 + 40));
        if ( operating_chan_freq )
        {
          v32 = wlan_reg_freq_to_chan(v10[1], operating_chan_freq, v24, v25, v26, v27, v28, v29, v30, v31);
          qdf_trace_msg(
            0x33u,
            4u,
            "%s: First connection channel No.:%d and quota:%dms",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "set_first_connection_operating_channel",
            v32,
            a2);
          a2 = v32 | (a2 << 8);
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s:  First adapter operating channel is invalid",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "set_first_connection_operating_channel");
        }
        v41 = v10[1];
        mcc_operating_channel = policy_mgr_get_mcc_operating_channel(*v10, *(_BYTE *)(*(_QWORD *)(a1 + 52832) + 8LL));
        v51 = wlan_reg_freq_to_chan(v41, mcc_operating_channel, v43, v44, v45, v46, v47, v48, v49, v50);
        if ( v51 )
        {
          v60 = v51;
          qdf_trace_msg(
            0x33u,
            4u,
            "%s: Second connection channel No.:%d and quota:%dms",
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            "set_second_connection_operating_channel",
            v51,
            a2);
          v69 = v60 | (a2 << 8);
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Second adapter operating channel is invalid",
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            "set_second_connection_operating_channel");
          v69 = a2;
        }
        return wlan_hdd_send_mcc_vdev_quota(a1, v69, v61, v62, v63, v64, v65, v66, v67, v68);
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: MCC is not active. Exit w/o setting latency",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_hdd_set_mcc_p2p_quota");
        return 0;
      }
    }
    else
    {
      qdf_trace_msg(0x33u, 2u, "%s: HDD context is null", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_set_mcc_p2p_quota");
      return 4294967274LL;
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid adapter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_set_mcc_p2p_quota");
    return 4294967282LL;
  }
}
