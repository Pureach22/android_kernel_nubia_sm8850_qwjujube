__int64 __fastcall wma_set_cts2self_for_p2p_go(__int64 *a1, unsigned int a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( (unsigned int)wmi_unified_pdev_param_send(*a1) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Fail to Set CTS2SELF for p2p GO %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wma_set_cts2self_for_p2p_go",
      a2);
    result = 16;
  }
  else
  {
    qdf_trace_msg(0x36u, 8u, "Successfully Set CTS2SELF for p2p GO %d", v3, v4, v5, v6, v7, v8, v9, v10, a2);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
