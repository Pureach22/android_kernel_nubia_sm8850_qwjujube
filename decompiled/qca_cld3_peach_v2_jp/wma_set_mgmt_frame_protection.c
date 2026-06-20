__int64 __fastcall wma_set_mgmt_frame_protection(__int64 *a1)
{
  unsigned int v1; // w0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v1 = wmi_unified_pdev_param_send(*a1);
  if ( v1 )
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Failed to set QOS MFP/PMF (%d)",
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               "wma_set_mgmt_frame_protection",
               v1);
  else
    result = qdf_trace_msg(
               0x36u,
               8u,
               "%s: QOS MFP/PMF set",
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               "wma_set_mgmt_frame_protection");
  _ReadStatusReg(SP_EL0);
  return result;
}
