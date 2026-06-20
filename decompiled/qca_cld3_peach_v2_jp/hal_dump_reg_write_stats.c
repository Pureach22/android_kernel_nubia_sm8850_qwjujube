__int64 __fastcall hal_dump_reg_write_stats(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // [xsp+0h] [xbp-30h]
  unsigned int v11; // [xsp+8h] [xbp-28h]
  unsigned int v12; // [xsp+10h] [xbp-20h]
  unsigned int v13; // [xsp+18h] [xbp-18h]
  unsigned int v14; // [xsp+20h] [xbp-10h]
  unsigned int v15; // [xsp+28h] [xbp-8h]

  v13 = a1[18610];
  v15 = a1[18612];
  v14 = a1[18611];
  v12 = a1[18609];
  v11 = a1[18608];
  v10 = a1[18607];
  return qdf_trace_msg(
           0x46u,
           8u,
           "%s: wstats: enq %u deq %u coal %u direct %u q_depth %u max_q %u sched-delay hist %u %u %u %u",
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           "hal_dump_reg_write_stats",
           a1[18602],
           a1[18603],
           a1[18604],
           a1[18605],
           v10,
           v11,
           v12,
           v13,
           v14,
           v15);
}
