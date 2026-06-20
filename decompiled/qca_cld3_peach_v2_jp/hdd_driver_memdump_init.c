__int64 __fastcall hdd_driver_memdump_init(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x0
  _QWORD *v9; // x19
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  context = _cds_get_context(51, (__int64)"hdd_driver_memdump_init", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    return 4294967274LL;
  v9 = context;
  _mutex_init(context + 170, "&hdd_ctx->memdump_lock", &hdd_driver_memdump_init___key);
  v10 = proc_mkdir("debugdriver", 0);
  proc_dir_driver = v10;
  if ( v10 )
  {
    proc_file_driver = proc_create_data("driverdump", 292, v10, &driver_dump_fops, v9);
    if ( proc_file_driver )
      return 0;
    remove_proc_entry("driverdump", proc_dir_driver);
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Failed to create proc file",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "hdd_driver_memdump_init");
  return 4294967284LL;
}
