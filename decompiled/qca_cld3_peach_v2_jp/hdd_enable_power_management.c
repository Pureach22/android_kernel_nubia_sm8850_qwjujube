_QWORD *__fastcall hdd_enable_power_management(
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
  _QWORD *result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x0
  unsigned int v21; // w0
  const char *v22; // x2

  result = _cds_get_context(61, (__int64)"hdd_enable_power_management", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    hif_enable_power_management((__int64)result);
    v19 = *(_QWORD *)(a1 + 104);
    *(_DWORD *)(a1 + 1232) = 0;
    *(_QWORD *)(a1 + 1240) = 0;
    if ( *(_BYTE *)(v19 + 123) == 2 )
    {
      v20 = *(_QWORD *)(a1 + 96);
      *(_QWORD *)(a1 + 1200) = wlan_hdd_pm_qos_notify;
      v21 = dev_pm_qos_add_notifier(v20, a1 + 1200, 1);
      if ( v21 )
        return (_QWORD *)qdf_trace_msg(
                           0x33u,
                           2u,
                           "%s: Failed to register PM_QOS notifier: %d",
                           v11,
                           v12,
                           v13,
                           v14,
                           v15,
                           v16,
                           v17,
                           v18,
                           "hdd_wlan_register_pm_qos_notifier",
                           v21);
      v22 = "%s: PM QOS Notifier registered";
    }
    else
    {
      v22 = "%s: Dynamic Runtime PM disabled";
    }
    return (_QWORD *)qdf_trace_msg(
                       0x33u,
                       8u,
                       v22,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       "hdd_wlan_register_pm_qos_notifier");
  }
  return result;
}
