__int64 __fastcall wlan_ipa_uc_rt_debug_host_dump(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int i; // w23
  _QWORD *v28; // x8

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 1464) + 1LL) & 1) == 0 )
    return qdf_trace_msg(
             0x61u,
             8u,
             "%s: IPA RT debug is not enabled",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "wlan_ipa_uc_rt_debug_host_dump");
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: ========= WLAN-IPA DEBUG BUF DUMP ==========\n",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_ipa_uc_rt_debug_host_dump");
  qdf_trace_msg(
    0x61u,
    4u,
    "%s:      TM     :   EXEP   :   DROP   :   NETS   :   FWOK:   TXFD   :   DSTR   :   DSCD\n",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "wlan_ipa_uc_rt_debug_host_dump");
  qdf_mutex_acquire(a1 + 7160);
  for ( i = 0; i != 30; ++i )
  {
    v28 = (_QWORD *)(a1
                   + 4336
                   + ((unsigned __int64)(i + *(_DWORD *)(a1 + 6256) - 30 * ((*(_DWORD *)(a1 + 6256) + i) / 0x1Eu)) << 6));
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: %12llu:%10llu:%10llu:%10llu:%10llu:%10llu:%10llu:%10llu\n",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_ipa_uc_rt_debug_host_dump",
      *v28,
      v28[1],
      v28[2],
      v28[3],
      v28[5],
      v28[6],
      v28[7],
      v28[4]);
  }
  return qdf_mutex_release(a1 + 7160);
}
