__int64 __fastcall hdd_switch_sap_chan_freq(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 *v24; // x23
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  if ( (unsigned int)_hdd_validate_adapter(
                       *(_QWORD *)a1,
                       (__int64)"hdd_switch_sap_chan_freq",
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       a11,
                       a12) )
    return 4;
  v24 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  if ( (unsigned int)_wlan_hdd_validate_context(
                       (__int64)v24,
                       (__int64)"hdd_switch_sap_chan_freq",
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23) )
    return 4;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: chan freq:%d width:%d org bw %d",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "hdd_switch_sap_chan_freq",
    a2,
    a3,
    *(unsigned int *)(a1 + 744));
  return policy_mgr_change_sap_channel_with_csa(*v24, *(unsigned __int8 *)(a1 + 8), a2, a3, a4 & 1);
}
