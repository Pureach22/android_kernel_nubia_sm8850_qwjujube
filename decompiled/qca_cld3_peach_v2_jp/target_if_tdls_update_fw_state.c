__int64 __fastcall target_if_tdls_update_fw_state(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  int updated; // w0
  __int64 v13; // x4
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( a1 && (v10 = *(_QWORD *)(a1 + 2800)) != 0 && *(_QWORD *)(v10 + 16) )
  {
    updated = wmi_unified_update_fw_tdls_state_cmd();
    v13 = *a2;
    LODWORD(a2) = updated;
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: vdev_id %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_tdls_update_fw_state",
      v13);
    return (unsigned int)a2;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid WMI handle",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_tdls_update_fw_state");
    return 16;
  }
}
