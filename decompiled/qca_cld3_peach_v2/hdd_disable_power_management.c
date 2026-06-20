_QWORD *__fastcall hdd_disable_power_management(
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
  __int64 v19; // x19
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x0
  int v30; // w8
  __int64 v31; // x1

  result = _cds_get_context(61, (__int64)"hdd_disable_power_management", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v19 = (__int64)result;
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 104) + 123LL) == 2 )
    {
      v20 = dev_pm_qos_remove_notifier(*(_QWORD *)(a1 + 96), a1 + 1200, 1);
      if ( v20 )
        qdf_trace_msg(
          0x33u,
          3u,
          "%s: Failed to remove qos notifier, err = %d\n",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "hdd_wlan_unregister_pm_qos_notifier",
          v20);
      v29 = raw_spin_lock_irqsave(a1 + 1232);
      v30 = *(unsigned __int8 *)(a1 + 1224);
      v31 = v29;
      *(_QWORD *)(a1 + 1240) = v29;
      if ( v30 == 1 )
      {
        hif_rtpm_put(6, 8u);
        v31 = *(_QWORD *)(a1 + 1240);
        *(_BYTE *)(a1 + 1224) = 0;
      }
      raw_spin_unlock_irqrestore(a1 + 1232, v31);
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Dynamic Runtime PM disabled",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "hdd_wlan_unregister_pm_qos_notifier");
    }
    return (_QWORD *)hif_disable_power_management(v19);
  }
  return result;
}
