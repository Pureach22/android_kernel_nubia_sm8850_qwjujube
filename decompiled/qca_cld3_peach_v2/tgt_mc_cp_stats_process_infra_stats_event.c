__int64 __fastcall tgt_mc_cp_stats_process_infra_stats_event(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  void (__fastcall *v20)(unsigned int *, __int64); // x8
  __int64 v21; // x1
  __int64 v22; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v22 = 0;
    v23[0] = 0;
    if ( (unsigned int)wlan_cp_stats_infra_cp_get_context(a1, v23, &v22, a3, a4, a5, a6, a7, a8, a9, a10) )
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: ucfg_get_infra_cp_stats_context failed",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "tgt_mc_infra_cp_stats_extract_twt_stats");
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        8u,
        "%s: num_twt_infra_cp_stats = %d action %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "tgt_mc_infra_cp_stats_extract_twt_stats",
        a2[3],
        *a2);
      v20 = (void (__fastcall *)(unsigned int *, __int64))v23[0];
      if ( v23[0] )
      {
        v21 = v22;
        if ( *(_DWORD *)(v23[0] - 4LL) != -1974175017 )
          __break(0x8228u);
        v20(a2, v21);
      }
    }
    result = 0;
  }
  else
  {
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
