__int64 __fastcall ucfg_fwol_psoc_open(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v10; // w19

  result = fwol_cfg_on_psoc_enable(a1);
  if ( (_DWORD)result )
  {
    v10 = result;
    qdf_trace_msg(0x66u, 2u, "%s: Failed to initialize FWOL CFG", v2, v3, v4, v5, v6, v7, v8, v9, "ucfg_fwol_psoc_open");
    return v10;
  }
  return result;
}
