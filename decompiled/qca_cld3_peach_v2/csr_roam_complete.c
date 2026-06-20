__int64 __fastcall csr_roam_complete(
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
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  const char *v20; // x2

  result = wlan_serialization_peek_head_active_cmd_using_psoc(
             *(_QWORD *)(a1 + 21624),
             0,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9);
  if ( !result )
  {
    v20 = "%s: Roam completion called but cmd is not active";
    return qdf_trace_msg(0x34u, 2u, v20, v11, v12, v13, v14, v15, v16, v17, v18, "csr_roam_complete");
  }
  v19 = *(_QWORD *)(result + 40);
  if ( !v19 )
  {
    v20 = "%s: sme_cmd is NULL";
    return qdf_trace_msg(0x34u, 2u, v20, v11, v12, v13, v14, v15, v16, v17, v18, "csr_roam_complete");
  }
  if ( *(_DWORD *)(v19 + 16) == 65537 )
  {
    csr_roam_process_results_default(a1, v19);
    return csr_release_command(a1, v19);
  }
  return result;
}
