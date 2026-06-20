__int64 __fastcall wma_send_multi_pdev_vdev_set_params(
        int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 result; // x0
  unsigned int v23; // w19
  const char *v24; // x2

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(53, (__int64)"wma_send_multi_pdev_vdev_set_params", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context
    && (v19 = context[2694]) != 0
    && (v20 = *(_QWORD *)(v19 + 2800)) != 0
    && (v21 = *(_QWORD *)(v20 + 16)) != 0 )
  {
    if ( a1 )
    {
      if ( a1 != 1 )
      {
        v23 = 16;
        v24 = "%s: Invalid param type";
        goto LABEL_14;
      }
      result = wmi_unified_multiple_vdev_param_send(v21);
      if ( (_DWORD)result )
      {
        v23 = result;
        v24 = "%s: failed to send multi vdev set params";
LABEL_14:
        qdf_trace_msg(0x36u, 2u, v24, v11, v12, v13, v14, v15, v16, v17, v18, "wma_send_multi_pdev_vdev_set_params");
        result = v23;
      }
    }
    else
    {
      result = wmi_unified_multiple_pdev_param_send(v21);
      if ( (_DWORD)result )
      {
        v23 = result;
        v24 = "%s: failed to send multi pdev set params";
        goto LABEL_14;
      }
    }
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
