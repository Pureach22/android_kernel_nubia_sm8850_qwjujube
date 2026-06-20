__int64 __fastcall wma_unified_set_sta_ps_param(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( _cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", a5, a6, a7, a8, a9, a10, a11, a12) )
  {
    if ( (wma_is_vdev_valid(a2, v16, v17, v18, v19, v20, v21, v22, v23) & 1) != 0 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Set Sta Ps param vdevId %d Param %d val %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "wma_unified_set_sta_ps_param",
        a2,
        a3,
        a4);
      result = wmi_unified_sta_ps_cmd_send(a1);
    }
    else
    {
      result = 4;
    }
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
