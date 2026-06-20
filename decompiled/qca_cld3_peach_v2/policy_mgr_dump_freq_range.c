_DWORD *__fastcall policy_mgr_dump_freq_range(
        _DWORD *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _DWORD *v9; // x19
  __int64 v10; // [xsp+0h] [xbp-10h]
  int v11; // [xsp+0h] [xbp-10h]
  __int64 v12; // [xsp+8h] [xbp-8h]
  int v13; // [xsp+8h] [xbp-8h]

  v9 = result;
  if ( result[301] | result[303] )
  {
    v13 = result[304];
    v11 = result[303];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_SMM",
                         0,
                         0,
                         v11,
                         v13);
  }
  if ( v9[305] | v9[307] )
  {
    LODWORD(v12) = v9[308];
    LODWORD(v10) = v9[307];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_SMM",
                         0,
                         1,
                         v10,
                         v12);
  }
  if ( v9[309] | v9[311] )
  {
    LODWORD(v12) = v9[312];
    LODWORD(v10) = v9[311];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_DBS",
                         1,
                         0,
                         v10,
                         v12);
  }
  if ( v9[313] | v9[315] )
  {
    LODWORD(v12) = v9[316];
    LODWORD(v10) = v9[315];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_DBS",
                         1,
                         1,
                         v10,
                         v12);
  }
  if ( v9[317] | v9[319] )
  {
    LODWORD(v12) = v9[320];
    LODWORD(v10) = v9[319];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_SBS",
                         2,
                         0,
                         v10,
                         v12);
  }
  if ( v9[321] | v9[323] )
  {
    LODWORD(v12) = v9[324];
    LODWORD(v10) = v9[323];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_SBS",
                         2,
                         1,
                         v10,
                         v12);
  }
  if ( v9[325] | v9[327] )
  {
    LODWORD(v12) = v9[328];
    LODWORD(v10) = v9[327];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_SBS_UPPER_SHARE",
                         3,
                         0,
                         v10,
                         v12);
  }
  if ( v9[329] | v9[331] )
  {
    LODWORD(v12) = v9[332];
    LODWORD(v10) = v9[331];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_SBS_UPPER_SHARE",
                         3,
                         1,
                         v10,
                         v12);
  }
  if ( v9[333] | v9[335] )
  {
    LODWORD(v12) = v9[336];
    LODWORD(v10) = v9[335];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_SBS_LOWER_SHARE",
                         4,
                         0,
                         v10,
                         v12);
  }
  if ( v9[337] | v9[339] )
  {
    LODWORD(v12) = v9[340];
    LODWORD(v10) = v9[339];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_SBS_LOWER_SHARE",
                         4,
                         1,
                         v10,
                         v12);
  }
  if ( v9[341] | v9[343] )
  {
    LODWORD(v12) = v9[344];
    LODWORD(v10) = v9[343];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_EMLSR",
                         5,
                         0,
                         v10,
                         v12);
  }
  if ( v9[345] | v9[347] )
  {
    LODWORD(v12) = v9[348];
    LODWORD(v10) = v9[347];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_EMLSR",
                         5,
                         1,
                         v10,
                         v12);
  }
  if ( v9[349] | v9[351] )
  {
    LODWORD(v12) = v9[352];
    LODWORD(v10) = v9[351];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_EMLSR_SINGLE",
                         6,
                         0,
                         v10,
                         v12);
  }
  if ( v9[353] | v9[355] )
  {
    LODWORD(v12) = v9[356];
    LODWORD(v10) = v9[355];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_EMLSR_SINGLE",
                         6,
                         1,
                         v10,
                         v12);
  }
  if ( v9[357] | v9[359] )
  {
    LODWORD(v12) = v9[360];
    LODWORD(v10) = v9[359];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_EMLSR_SPLIT",
                         7,
                         0,
                         v10,
                         v12);
  }
  if ( v9[361] | v9[363] )
  {
    LODWORD(v12) = v9[364];
    LODWORD(v10) = v9[363];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "MODE_EMLSR_SPLIT",
                         7,
                         1,
                         v10,
                         v12);
  }
  if ( v9[365] | v9[367] )
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE_CUR: mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         0);
  if ( v9[369] | v9[371] )
    return (_DWORD *)qdf_trace_msg(
                       0x4Fu,
                       8u,
                       "PLCY_MGR_FREQ_RANGE_CUR: mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       1);
  return result;
}
