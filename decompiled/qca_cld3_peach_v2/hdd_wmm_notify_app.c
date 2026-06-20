__int64 __fastcall hdd_wmm_notify_app(
        _DWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // w3
  int v19; // w4
  size_t v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  __int64 v30; // x0
  _QWORD v31[8]; // [xsp+0h] [xbp-40h] BYREF

  v31[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: Entered, context %pK", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_wmm_notify_app", a1);
  if ( !a1 || a1[18] != 1464683864 )
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: Invalid QoS Context",
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               "hdd_wmm_notify_app");
    goto LABEL_6;
  }
  v18 = a1[4];
  v19 = a1[9];
  memset(v31, 0, 51);
  snprintf((char *)v31, 0x32u, "QCOM: TS change[%u: %u]", v18, v19);
  v20 = strnlen((const char *)v31, 0x33u);
  if ( v20 >= 0x34 )
  {
    v20 = _fortify_panic(2, 51, v20 + 1);
  }
  else if ( v20 != 51 )
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: Sending [%s]",
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               "hdd_wmm_notify_app",
               v31);
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v30 = _fortify_panic(4, 51, v20 + 1);
  return hdd_wmm_enable_inactivity_timer(v30);
}
