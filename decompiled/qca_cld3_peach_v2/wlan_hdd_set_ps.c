__int64 __fastcall wlan_hdd_set_ps(
        unsigned __int8 *a1,
        __int64 a2,
        char a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x23
  unsigned int v16; // w19
  bool is_vdev_associated; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x4
  __int64 v27; // x5
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x24
  __int64 v37; // x23
  __int64 v38; // x2
  __int64 v39; // x3

  v13 = *(_QWORD *)a1;
  v16 = wlan_hdd_set_powersave(a1, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
  is_vdev_associated = hdd_cm_is_vdev_associated(a1);
  v26 = a1[8];
  v27 = *(unsigned int *)(v13 + 40);
  if ( is_vdev_associated )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev[%d] mode %d enable dhcp protection",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_hdd_set_ps",
      v26,
      v27);
    v36 = *(_QWORD *)a1;
    v37 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
    if ( (a3 & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: DHCP stop indicated through power save",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_stop_dhcp_ind");
      sme_dhcp_stop_ind(*(_QWORD *)(v37 + 16), *(unsigned int *)(v36 + 40), a2, a1[8]);
      hdd_allow_suspend(0x12u);
      qdf_runtime_pm_allow_suspend((__int64 *)(v37 + 1664));
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: DHCP start indicated through power save",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_start_dhcp_ind");
      qdf_runtime_pm_prevent_suspend((__int64 *)(v37 + 1664));
      hdd_prevent_suspend_timeout(0x3E8u, 18, v38, v39);
      sme_dhcp_start_ind(*(_QWORD *)(v37 + 16), *(unsigned int *)(v36 + 40), a2, a1[8]);
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev[%d] mode %d disconnected ignore dhcp protection",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_hdd_set_ps",
      v26,
      v27);
  }
  return v16;
}
