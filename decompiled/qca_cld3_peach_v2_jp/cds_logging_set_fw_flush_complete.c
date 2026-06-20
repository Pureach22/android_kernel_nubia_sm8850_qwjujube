__int64 __fastcall cds_logging_set_fw_flush_complete(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  v4 = gp_cds_context;
  if ( !gp_cds_context )
  {
    result = printk(&unk_94D98D, "cds_get_global_context", a3, a4);
    v4 = gp_cds_context;
    if ( !gp_cds_context )
      return qdf_trace_msg(
               0x38u,
               2u,
               "%s: cds context is Invalid",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "cds_is_fatal_event_enabled");
  }
  if ( *(_BYTE *)(v4 + 144) == 1 )
    return wlan_logging_set_fw_flush_complete();
  return result;
}
