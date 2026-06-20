__int64 __fastcall target_if_wifi_pos_oem_data_req(
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
  __int64 *v11; // x8
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int started; // w19
  const char *v22; // x2

  if ( a1 && (v11 = *(__int64 **)(a1 + 1232)) != nullptr )
    v12 = *v11;
  else
    v12 = 0;
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: Send oem data req to target",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "target_if_wifi_pos_oem_data_req");
  if ( !a2 || !*(_QWORD *)(a2 + 8) )
  {
    started = 4;
    v22 = "%s: oem_data_req is null";
    goto LABEL_11;
  }
  if ( !v12 )
  {
    started = 4;
    v22 = "%s: WMA closed, can't send oem data req cmd";
    goto LABEL_11;
  }
  started = wmi_unified_start_oem_data_cmd(v12);
  if ( started )
  {
    v22 = "%s: wmi cmd send failed";
LABEL_11:
    qdf_trace_msg(0x49u, 2u, v22, v13, v14, v15, v16, v17, v18, v19, v20, "target_if_wifi_pos_oem_data_req");
  }
  return started;
}
