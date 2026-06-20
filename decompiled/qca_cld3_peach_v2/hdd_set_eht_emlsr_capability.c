__int64 __fastcall hdd_set_eht_emlsr_capability(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w19
  __int64 *v11; // x22
  char is_hw_emlsr_capable; // w21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  v10 = *(unsigned __int8 *)(a2 + 4);
  v11 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: EMLSR capable: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_set_eht_emlsr_capability",
    *(unsigned __int8 *)(a2 + 4));
  is_hw_emlsr_capable = policy_mgr_is_hw_emlsr_capable(*v11);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: eMLSR - Config : %d,  HW support : %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "hdd_test_config_emlsr_mode",
    v10 != 0,
    is_hw_emlsr_capable & 1);
  if ( (is_hw_emlsr_capable & 1) != 0 )
    wlan_mlme_set_emlsr_mode_enabled(*v11, v10 != 0);
  return 0;
}
