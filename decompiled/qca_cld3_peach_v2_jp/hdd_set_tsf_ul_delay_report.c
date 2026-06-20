__int64 __fastcall hdd_set_tsf_ul_delay_report(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  __int64 (*v18)(void); // x8
  __int64 v19; // x20

  result = (__int64)_cds_get_context(71, (__int64)"hdd_set_tsf_ul_delay_report", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !result || !*(_QWORD *)result )
  {
    result = qdf_trace_msg(
               0x89u,
               2u,
               "%s: Invalid SOC instance",
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               "cdp_set_tsf_ul_delay_report");
LABEL_10:
    v19 = jiffies;
    if ( hdd_set_tsf_ul_delay_report___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: Set tsf report uplink delay failed",
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 "hdd_set_tsf_ul_delay_report");
      hdd_set_tsf_ul_delay_report___last_ticks = v19;
    }
    return result;
  }
  v17 = *(_QWORD *)(*(_QWORD *)result + 8LL);
  if ( !v17 )
    goto LABEL_10;
  v18 = *(__int64 (**)(void))(v17 + 208);
  if ( !v18 )
    goto LABEL_10;
  if ( *((_DWORD *)v18 - 1) != -254072184 )
    __break(0x8228u);
  result = v18();
  if ( (_DWORD)result )
    goto LABEL_10;
  return result;
}
