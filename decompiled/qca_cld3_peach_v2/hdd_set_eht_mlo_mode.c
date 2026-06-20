__int64 __fastcall hdd_set_eht_mlo_mode(
        __int64 *a1,
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
  __int64 v10; // x21
  int v11; // w19
  __int64 *v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  char is_hw_emlsr_capable; // w19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w1

  v10 = *a1;
  v11 = *(unsigned __int8 *)(a2 + 4);
  v12 = *(__int64 **)(*a1 + 24);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Configure EHT mode of operation: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_set_eht_mlo_mode",
    *(unsigned __int8 *)(a2 + 4));
  if ( (unsigned int)(v11 - 3) < 2 )
  {
    v30 = 3;
  }
  else if ( v11 == 1 )
  {
    v30 = 2;
  }
  else if ( v11 == 2 )
  {
    if ( !*(_DWORD *)(v10 + 40) )
    {
      is_hw_emlsr_capable = policy_mgr_is_hw_emlsr_capable(*v12);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: eMLSR - Config : %d,  HW support : %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_test_config_emlsr_mode",
        1,
        is_hw_emlsr_capable & 1);
      if ( (is_hw_emlsr_capable & 1) != 0 )
        wlan_mlme_set_emlsr_mode_enabled(*v12, 1);
      ucfg_mlme_set_bss_color_collision_det_sta(*v12, 0);
    }
    v30 = 4;
  }
  else
  {
    qdf_trace_msg(0x33u, 8u, "%s: Invalid EHT mode", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_get_cfg_eht_mode");
    v30 = 0;
  }
  wlan_mlme_set_eht_mode(*v12, v30);
  return 0;
}
