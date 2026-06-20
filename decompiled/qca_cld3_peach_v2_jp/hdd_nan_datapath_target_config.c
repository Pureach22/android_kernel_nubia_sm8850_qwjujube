__int64 __fastcall hdd_nan_datapath_target_config(
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
  char v20; // w8
  __int64 v21; // x0
  unsigned int v22; // w21
  char datapath_enable; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  if ( (cfg_nan_get_datapath_enable(*(_QWORD *)a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
    v20 = *(_BYTE *)(a2 + 168);
  else
    v20 = 0;
  v21 = *(_QWORD *)a1;
  v22 = v20 & 1;
  *(_BYTE *)(a1 + 1462) = v20 & 1;
  datapath_enable = cfg_nan_get_datapath_enable(v21, v12, v13, v14, v15, v16, v17, v18, v19);
  return qdf_trace_msg(
           0x33u,
           8u,
           "%s: NAN Datapath Enable: %d (Host: %d FW: %d)",
           v24,
           v25,
           v26,
           v27,
           v28,
           v29,
           v30,
           v31,
           "hdd_nan_datapath_target_config",
           v22,
           datapath_enable & 1,
           *(unsigned __int8 *)(a2 + 168));
}
