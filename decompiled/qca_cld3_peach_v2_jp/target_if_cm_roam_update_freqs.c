__int64 __fastcall target_if_cm_roam_update_freqs(
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
  _QWORD *v11; // x8
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x4
  unsigned int v23; // w19
  const char *v24; // x2

  v10 = *(_QWORD *)(a1 + 152);
  if ( !v10 )
  {
    v24 = "%s: PDEV is NULL";
    goto LABEL_8;
  }
  v11 = *(_QWORD **)(v10 + 1232);
  if ( !v11 || !*v11 )
  {
    v24 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v24, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cm_roam_get_wmi_handle_from_vdev");
    return 16;
  }
  result = wmi_unified_roam_scan_offload_chan_list_cmd(*v11, a2);
  if ( (_DWORD)result )
  {
    v22 = *a2;
    v23 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: vdev:%d Send channel list command failed",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_cm_roam_update_freqs",
      v22);
    return v23;
  }
  return result;
}
