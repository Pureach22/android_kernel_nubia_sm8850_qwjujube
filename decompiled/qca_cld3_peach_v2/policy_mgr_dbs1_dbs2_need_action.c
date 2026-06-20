__int64 __fastcall policy_mgr_dbs1_dbs2_need_action(__int64 a1, unsigned int a2, __int64 a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  const char *v23; // x2
  __int64 v24; // x4
  __int64 result; // x0

  if ( (policy_mgr_is_2x2_5G_1x1_2G_dbs_capable(a1) & 1) == 0 && (policy_mgr_is_2x2_2G_1x1_5G_dbs_capable(a1) & 1) == 0 )
    return 1;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: curr dbs action %d new action %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "policy_mgr_dbs1_dbs2_need_action",
    *(unsigned int *)(a3 + 12),
    a2);
  v22 = *(_DWORD *)(a3 + 12);
  if ( (a2 & 0xFFFFFFFE) == 0xA && v22 == 10 )
  {
    v23 = "%s: driver is already in DBS_5G_2x2_24G_1x1 (%d), no further action %d needed";
    v24 = 10;
LABEL_9:
    qdf_trace_msg(0x4Fu, 8u, v23, v14, v15, v16, v17, v18, v19, v20, v21, "policy_mgr_dbs1_dbs2_need_action", v24, a2);
    return 0;
  }
  result = 1;
  if ( (a2 & 0xFFFFFFFE) == 0xC && v22 == 12 )
  {
    v23 = "%s: driver is already in DBS_24G_2x2_5G_1x1 (%d), no further action %d needed";
    v24 = 12;
    goto LABEL_9;
  }
  return result;
}
