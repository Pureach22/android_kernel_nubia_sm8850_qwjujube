__int64 __fastcall wma_set_power_config(
        unsigned __int8 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 *v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(54, (__int64)"wma_set_power_config", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    goto LABEL_7;
  v21 = context;
  qdf_trace_msg(
    0x36u,
    4u,
    "%s: configuring power: %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wma_set_power_config",
    a2);
  v30 = *v21;
  if ( a2 >= 3 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid opm_mode: %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_convert_opm_mode",
      a2);
    a2 = 0;
  }
  if ( !_cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", v22, v23, v24, v25, v26, v27, v28, v29) )
  {
    result = 16;
    goto LABEL_9;
  }
  if ( (wma_is_vdev_valid(a1, v31, v32, v33, v34, v35, v36, v37, v38) & 1) != 0 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Set Sta Ps param vdevId %d Param %d val %d",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "wma_unified_set_sta_ps_param",
      a1,
      6,
      a2);
    result = wmi_unified_sta_ps_cmd_send(v30);
  }
  else
  {
LABEL_7:
    result = 4;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
