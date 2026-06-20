__int64 __fastcall cds_is_log_report_in_progress(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  char v5; // w8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  v4 = gp_cds_context;
  if ( gp_cds_context || (printk(&unk_A3062F, "cds_get_global_context", a3, a4), (v4 = gp_cds_context) != 0) )
  {
    v5 = *(_BYTE *)(v4 + 120);
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context is Invalid",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "cds_is_log_report_in_progress");
    v5 = 1;
  }
  return v5 & 1;
}
