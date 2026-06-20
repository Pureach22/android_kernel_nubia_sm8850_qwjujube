__int64 __fastcall wma_vdev_set_param(
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
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(54, (__int64)"wma_is_vdev_valid", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !context )
    goto LABEL_6;
  if ( *((unsigned __int16 *)context + 81) <= a2 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev_id: %d is invalid, max_bssid: %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wma_is_vdev_valid",
      a2);
    goto LABEL_6;
  }
  if ( (*(_BYTE *)(context[65] + 488LL * a2 + 184) & 1) == 0 )
  {
LABEL_6:
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev_id: %d is not active reject the req: param id %d val %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wma_vdev_set_param",
      a2,
      a3,
      a4);
    result = 4;
    goto LABEL_7;
  }
  result = wmi_unified_vdev_set_param_send(a1);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
