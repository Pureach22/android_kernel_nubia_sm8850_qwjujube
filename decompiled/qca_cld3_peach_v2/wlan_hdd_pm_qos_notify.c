__int64 __fastcall wlan_hdd_pm_qos_notify(
        __int64 a1,
        unsigned __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  bool v28; // w21
  __int64 v29; // x20
  __int64 v31; // x0
  int v32; // w8
  char v33; // w8

  if ( *(_DWORD *)(a1 + 264) != 1 )
  {
    v29 = jiffies;
    if ( wlan_hdd_pm_qos_notify___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Driver Module closed; skipping pm qos notify",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_hdd_pm_qos_notify");
      wlan_hdd_pm_qos_notify___last_ticks = v29;
      return 0;
    }
    return 0;
  }
  if ( !_cds_get_context(61, (__int64)"wlan_hdd_pm_qos_notify", a3, a4, a5, a6, a7, a8, a9, a10) )
    return 4294967274LL;
  v28 = hdd_is_any_sta_connected(a1 - 1200, v12, v13, v14, v15, v16, v17, v18, v19)
     || hdd_is_any_cli_connected(a1 - 1200, v20, v21, v22, v23, v24, v25, v26, v27);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: PM QOS update: runtime_pm_prevented %d Current value: %ld, is_any_sta_connected %d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "wlan_hdd_pm_qos_notify",
    *(unsigned __int8 *)(a1 + 24),
    a2,
    v28);
  v31 = raw_spin_lock_irqsave(a1 + 32);
  v32 = *(unsigned __int8 *)(a1 + 24);
  *(_QWORD *)(a1 + 40) = v31;
  if ( !v28 || (v32 & 1) != 0 || *(_QWORD *)(*(_QWORD *)(a1 - 1096) + 184LL) <= a2 )
  {
    if ( !v32 || *(_QWORD *)(*(_QWORD *)(a1 - 1096) + 184LL) > a2 )
      goto LABEL_17;
    hif_rtpm_put(6, 8u);
    v33 = 0;
  }
  else
  {
    hif_rtpm_get(3u, 8u);
    v33 = 1;
  }
  *(_BYTE *)(a1 + 24) = v33;
LABEL_17:
  raw_spin_unlock_irqrestore(a1 + 32, *(_QWORD *)(a1 + 40));
  return 0;
}
