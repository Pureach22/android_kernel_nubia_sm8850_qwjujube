__int64 __fastcall policy_mgr_get_hw_mode_idx_from_dbs_hw_list(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        unsigned int a17)
{
  unsigned int v19; // w26
  unsigned int v24; // w27
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  if ( a2 - 1 >= 4 )
    v19 = 0;
  else
    v19 = a2;
  if ( a4 - 1 >= 4 )
    v24 = 0;
  else
    v24 = a4;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: MAC0: TxSS=%d, RxSS=%d, BW=%d band=%d",
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    a16,
    "policy_mgr_get_hw_mode_idx_from_dbs_hw_list",
    v19,
    v19,
    a3,
    a6);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: MAC1: TxSS=%d, RxSS=%d, BW=%d",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "policy_mgr_get_hw_mode_idx_from_dbs_hw_list",
    v24,
    v24,
    a5);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: DBS=%d, Agile DFS=%d, SBS=%d",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "policy_mgr_get_hw_mode_idx_from_dbs_hw_list",
    a7,
    a8,
    a17);
  return policy_mgr_get_matching_hw_mode_index(a1, v19, v19, a3, v24, v24, a5, a6, a7, a8, a17);
}
