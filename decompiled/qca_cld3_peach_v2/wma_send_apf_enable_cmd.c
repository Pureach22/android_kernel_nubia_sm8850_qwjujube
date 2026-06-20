__int64 __fastcall wma_send_apf_enable_cmd(
        __int64 a1,
        unsigned __int8 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v32; // x2
  const char *v33; // x2

  if ( (wma_is_vdev_valid(a2, a4, a5, a6, a7, a8, a9, a10, a11) & 1) == 0 )
    return 4;
  if ( (unsigned int)_wma_validate_handle(a1, "wma_send_apf_enable_cmd") )
    return 4;
  v22 = *(_QWORD *)a1;
  if ( (unsigned int)_wmi_validate_handle(
                       *(_QWORD *)a1,
                       (__int64)"wma_send_apf_enable_cmd",
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21) )
    return 4;
  if ( (*(_BYTE *)(a1 + 280) & 8) == 0 )
  {
    v32 = "%s: APF cababilities feature bit not enabled";
LABEL_10:
    qdf_trace_msg(0x36u, 2u, v32, v23, v24, v25, v26, v27, v28, v29, v30, "wma_send_apf_enable_cmd");
    return 16;
  }
  if ( (unsigned int)wmi_unified_send_apf_enable_cmd(v22) )
  {
    v32 = "%s: Failed to send apf enable/disable cmd";
    goto LABEL_10;
  }
  if ( (a3 & 1) != 0 )
    v33 = "%s: Sent APF Enable on vdevid: %d";
  else
    v33 = "%s: Sent APF Disable on vdevid: %d";
  qdf_trace_msg(0x36u, 8u, v33, v23, v24, v25, v26, v27, v28, v29, v30, "wma_send_apf_enable_cmd", a2);
  return 0;
}
