__int64 __fastcall fwol_configure_hw_assist(__int64 a1, char a2)
{
  __int64 v2; // x1
  unsigned int v3; // w19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  if ( (a2 & 1) != 0 )
    v2 = 0x1000000CFLL;
  else
    v2 = 207;
  v3 = tgt_fwol_pdev_param_send(a1, v2, 0);
  if ( v3 )
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: wmi_pdev_param_disable_hw_assist failed %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "fwol_configure_hw_assist",
      v3);
  return v3;
}
