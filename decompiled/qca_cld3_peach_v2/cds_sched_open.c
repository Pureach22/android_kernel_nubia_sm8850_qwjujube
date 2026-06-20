__int64 __fastcall cds_sched_open(
        __int64 a1,
        void *a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  qdf_trace_msg(0x38u, 8u, "%s: Opening the CDS Scheduler", a4, a5, a6, a7, a8, a9, a10, a11, "cds_sched_open");
  if ( a1 && a2 )
  {
    if ( a3 )
    {
      qdf_trace_msg(
        0x38u,
        8u,
        "%s: Incorrect CDS Sched Context size passed",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "cds_sched_open");
      return 4;
    }
    else
    {
      qdf_mem_set(a2, 0, 0);
      gp_cds_sched_context = (__int64)a2;
      qdf_trace_msg(
        0x38u,
        8u,
        "%s: CDS Scheduler successfully Opened",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "cds_sched_open");
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x38u, 2u, "%s: Null params being passed", v14, v15, v16, v17, v18, v19, v20, v21, "cds_sched_open");
    return 16;
  }
}
