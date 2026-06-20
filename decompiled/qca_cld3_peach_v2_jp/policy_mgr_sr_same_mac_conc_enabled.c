__int64 __fastcall policy_mgr_sr_same_mac_conc_enabled(
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
  __int64 v9; // x8
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  char v19; // w0
  const char *v20; // x2

  if ( !a1 )
  {
    v20 = "%s: PSOC is NULL";
    goto LABEL_8;
  }
  v9 = *(_QWORD *)(a1 + 2800);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 16)) == 0 )
  {
    v20 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(0x68u, 2u, v20, a2, a3, a4, a5, a6, a7, a8, a9, "policy_mgr_sr_same_mac_conc_enabled");
    goto LABEL_9;
  }
  if ( (policy_mgr_get_same_mac_conc_sr_status(a1) & 1) == 0 )
  {
LABEL_9:
    v19 = 0;
    return v19 & 1;
  }
  v19 = wmi_service_enabled(v10, 0x11Bu, v11, v12, v13, v14, v15, v16, v17, v18);
  return v19 & 1;
}
