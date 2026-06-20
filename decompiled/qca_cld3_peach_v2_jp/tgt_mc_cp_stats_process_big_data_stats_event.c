__int64 __fastcall tgt_mc_cp_stats_process_big_data_stats_event(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2
  __int64 result; // x0
  void (__fastcall *v22)(__int64, __int64); // x8
  __int64 v23; // x1
  _BYTE v24[4]; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-28h] BYREF
  void (__fastcall *v26)(__int64, __int64); // [xsp+10h] [xbp-20h]
  __int64 v27; // [xsp+18h] [xbp-18h]
  __int64 v28; // [xsp+20h] [xbp-10h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = nullptr;
  v24[0] = 0;
  if ( a2 )
  {
    if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 6, &v25) )
    {
      v20 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
LABEL_11:
      qdf_trace_msg(
        0x62u,
        2u,
        v20,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "tgt_mc_cp_stats_process_big_data_stats_event");
      result = 16;
      goto LABEL_12;
    }
    ucfg_mc_cp_stats_reset_pending_req(a1, 6, &v25, v24);
    v22 = v26;
    if ( !v26 || v24[0] != 1 )
    {
      v20 = "%s: callback to send big data stats not found";
      goto LABEL_11;
    }
    v23 = v25;
    if ( *((_DWORD *)v26 - 1) != -573201191 )
      __break(0x8228u);
    v22(a2, v23);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: invalid data",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tgt_mc_cp_stats_process_big_data_stats_event");
    result = 4;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
