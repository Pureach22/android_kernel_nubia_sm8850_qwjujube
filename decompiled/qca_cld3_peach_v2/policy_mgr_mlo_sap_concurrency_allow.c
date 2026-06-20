__int64 __fastcall policy_mgr_mlo_sap_concurrency_allow(
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
  __int64 v10; // x0
  char v11; // w0
  const char *v12; // x2

  if ( !a1 )
  {
    v12 = "%s: PSOC is NULL";
    goto LABEL_7;
  }
  v9 = *(_QWORD *)(a1 + 2800);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 16)) == 0 )
  {
    v12 = "%s: wmi_handle is null";
LABEL_7:
    qdf_trace_msg(0x68u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "policy_mgr_mlo_sap_concurrency_allow");
    v11 = 0;
    return v11 & 1;
  }
  v11 = wmi_service_enabled(v10, 0x14Du, a2, a3, a4, a5, a6, a7, a8, a9);
  return v11 & 1;
}
