__int64 __fastcall target_if_cm_roam_offload_11k_params(
        __int64 a1,
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w19
  const char *v30; // x2
  unsigned int v31; // w1

  if ( (wmi_service_enabled(a1, 0x93u, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
  {
    v30 = "%s: FW doesn't support 11k offload";
    v31 = 2;
LABEL_7:
    qdf_trace_msg(0x49u, v31, v30, v12, v13, v14, v15, v16, v17, v18, v19, "target_if_cm_roam_offload_11k_params");
    return 0;
  }
  if ( *(_DWORD *)(a2 + 4) && !*(_BYTE *)(a2 + 32) )
  {
    v30 = "%s: SSID Len 0";
    v31 = 8;
    goto LABEL_7;
  }
  result = wmi_unified_offload_11k_cmd(a1, a2);
  if ( (_DWORD)result )
  {
    v29 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to send 11k offload command",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "target_if_cm_roam_offload_11k_params");
    return v29;
  }
  return result;
}
