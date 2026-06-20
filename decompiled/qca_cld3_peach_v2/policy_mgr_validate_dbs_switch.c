__int64 __fastcall policy_mgr_validate_dbs_switch(__int64 a1, unsigned int a2)
{
  unsigned int current_hw_mode; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w19
  __int64 result; // x0
  const char *v15; // x2
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x4
  __int64 v25; // [xsp+8h] [xbp-18h] BYREF
  __int64 v26; // [xsp+10h] [xbp-10h]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26 = 0;
  current_hw_mode = policy_mgr_get_current_hw_mode(a1, &v25);
  if ( current_hw_mode )
  {
    v13 = current_hw_mode;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: policy_mgr_get_current_hw_mode failed",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "policy_mgr_validate_dbs_switch");
    result = v13;
    goto LABEL_3;
  }
  if ( (a2 & 0xFFFFFFFE) == 6 )
  {
    if ( (policy_mgr_is_hw_sbs_capable(a1) & 1) == 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        4u,
        "%s: firmware is not sbs capable",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "policy_mgr_validate_dbs_switch");
      result = 11;
      goto LABEL_3;
    }
    if ( BYTE1(v26) )
    {
      v15 = "%s: current mode is already SBS";
LABEL_16:
      qdf_trace_msg(0x4Fu, 4u, v15, v5, v6, v7, v8, v9, v10, v11, v12, "policy_mgr_validate_dbs_switch");
      result = 6;
      goto LABEL_3;
    }
    goto LABEL_22;
  }
  if ( !HIBYTE(v25) )
  {
    if ( (a2 & 0xFFFFFFFE) == 4 )
    {
      v15 = "%s: current mode is already single MAC";
      goto LABEL_16;
    }
LABEL_22:
    result = 0;
    goto LABEL_3;
  }
  if ( (policy_mgr_is_2x2_5G_1x1_2G_dbs_capable(a1) & 1) != 0 || (policy_mgr_is_2x2_2G_1x1_5G_dbs_capable(a1) & 1) != 0 )
  {
    if ( (policy_mgr_dbs1_dbs2_need_action(a1, a2, &v25) & 1) == 0 )
    {
      result = 6;
      goto LABEL_3;
    }
    goto LABEL_22;
  }
  if ( a2 - 1 > 2 )
    goto LABEL_22;
  if ( HIBYTE(v25) )
    v24 = "dbs";
  else
    v24 = "non dbs";
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: driver is already in %s mode, no further action needed",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "policy_mgr_validate_dbs_switch",
    v24);
  result = 6;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
