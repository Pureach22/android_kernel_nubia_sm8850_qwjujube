__int64 __fastcall wlan_hdd_bus_resume_noirq(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _QWORD *v42; // x0
  __int64 v43; // x20
  unsigned int v44; // w19
  const char *v45; // x2

  context = _cds_get_context(51, (__int64)"wlan_hdd_bus_resume_noirq", a1, a2, a3, a4, a5, a6, a7, a8);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: starting bus_resume_noirq",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "wlan_hdd_bus_resume_noirq");
  if ( (cds_get_driver_state(v17, v18, v19, v20, v21, v22, v23, v24) & 8) != 0 )
    return 0;
  if ( !context )
    return 4294967277LL;
  if ( *((_DWORD *)context + 366) == 1 )
  {
    result = _wlan_hdd_validate_context(context, "wlan_hdd_bus_resume_noirq");
    if ( (_DWORD)result )
      return result;
    v42 = _cds_get_context(61, (__int64)"wlan_hdd_bus_resume_noirq", v34, v35, v36, v37, v38, v39, v40, v41);
    if ( !v42 )
      return 4294967274LL;
    v43 = (__int64)v42;
    ucfg_pmo_psoc_clear_target_wake_up(*context);
    v44 = hif_bus_resume_noirq(v43);
    v45 = "%s: bus_resume_noirq done";
  }
  else
  {
    v44 = 0;
    v45 = "%s: Driver Module closed return success";
  }
  qdf_trace_msg(0x33u, 8u, v45, v25, v26, v27, v28, v29, v30, v31, v32, "wlan_hdd_bus_resume_noirq");
  return v44;
}
