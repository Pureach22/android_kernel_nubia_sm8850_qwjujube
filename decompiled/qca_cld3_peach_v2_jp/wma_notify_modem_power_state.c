__int64 __fastcall wma_notify_modem_power_state(
        __int64 *a1,
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
  __int64 v12; // x21
  unsigned int v13; // w22
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _DWORD *v23; // x8
  __int64 v24; // x20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w21
  __int64 v34; // x4
  const char *v35; // x2
  unsigned int v36; // w1

  qdf_trace_msg(
    0x36u,
    8u,
    "%s: WMA notify Modem Power State %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_notify_modem_power_state",
    *a2);
  v12 = *a1;
  v13 = *a2;
  v14 = wmi_buf_alloc_fl(*a1, 8u, "wma_unified_modem_power_state", 0x48u);
  if ( v14 )
  {
    v23 = *(_DWORD **)(v14 + 224);
    v24 = v14;
    *v23 = 17104900;
    v23[1] = v13;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Setting cmd->modem_power_state = %u",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wma_unified_modem_power_state",
      v13);
    v33 = wmi_unified_cmd_send_fl(
            v12,
            v24,
            8u,
            0x29001u,
            "wma_unified_modem_power_state",
            0x54u,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32);
    if ( !v33 )
    {
      v34 = *a2;
      v35 = "%s: Successfully notify Modem Power State %d";
      v36 = 8;
      goto LABEL_7;
    }
    wmi_buf_free();
  }
  else
  {
    v33 = -12;
  }
  v34 = *a2;
  v35 = "%s: Failed to notify Modem Power State %d";
  v36 = 2;
LABEL_7:
  qdf_trace_msg(0x36u, v36, v35, v15, v16, v17, v18, v19, v20, v21, v22, "wma_notify_modem_power_state", v34);
  return v33;
}
