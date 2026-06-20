__int64 __fastcall wma_set_power_config_ito(
        unsigned __int8 a1,
        unsigned __int16 a2,
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
  __int64 v21; // x19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(54, (__int64)"wma_set_power_config_ito", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: wma_handle is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_set_power_config_ito");
LABEL_6:
    result = 4;
    goto LABEL_8;
  }
  v21 = *context;
  if ( !_cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", v13, v14, v15, v16, v17, v18, v19, v20) )
  {
    result = 16;
    goto LABEL_8;
  }
  if ( (wma_is_vdev_valid(a1, v22, v23, v24, v25, v26, v27, v28, v29) & 1) == 0 )
    goto LABEL_6;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Set Sta Ps param vdevId %d Param %d val %d",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "wma_unified_set_sta_ps_param",
    a1,
    3,
    a2);
  result = wmi_unified_sta_ps_cmd_send(v21);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
