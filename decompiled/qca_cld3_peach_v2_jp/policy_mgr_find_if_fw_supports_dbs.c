__int64 __fastcall policy_mgr_find_if_fw_supports_dbs(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x8
  __int64 v11; // x0
  char v12; // w0
  const char *v13; // x2
  unsigned int v14; // w1

  if ( !policy_mgr_get_context(a1) )
  {
    v13 = "%s: Invalid Context";
    v14 = 2;
    goto LABEL_8;
  }
  if ( !a1 || (v10 = *(_QWORD *)(a1 + 2800)) == 0 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    v13 = "%s: Invalid WMI handle";
    v14 = 8;
LABEL_8:
    qdf_trace_msg(0x4Fu, v14, v13, v2, v3, v4, v5, v6, v7, v8, v9, "policy_mgr_find_if_fw_supports_dbs");
    v12 = 0;
    return v12 & 1;
  }
  v12 = wmi_service_enabled(v11, 0x55u, v2, v3, v4, v5, v6, v7, v8, v9);
  return v12 & 1;
}
