__int64 __fastcall wlan_hdd_set_mas(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v10; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2
  const char *v21; // x2
  __int64 result; // x0
  __int64 v23; // x1
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  _BYTE v32[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  if ( !a1 )
  {
    v21 = "%s: Adapter is NULL";
LABEL_9:
    qdf_trace_msg(0x33u, 2u, v21, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_set_mas");
    result = 4294967274LL;
    goto LABEL_18;
  }
  v10 = *(__int64 **)(a1 + 24);
  if ( !v10 )
  {
    v21 = "%s: HDD context is null";
    goto LABEL_9;
  }
  if ( a2 )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Miracast is ON. Disable MAS and configure P2P quota",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_set_mas");
    ucfg_policy_mgr_get_mcc_adaptive_sch(*v10, v32);
    if ( v32[0] == 1 )
    {
      ucfg_policy_mgr_set_dynamic_mcc_adaptive_sch(*v10, 0);
      if ( (unsigned int)sme_set_mas(0) )
      {
        v20 = "%s: Failed to disable MAS";
LABEL_17:
        qdf_trace_msg(0x33u, 2u, v20, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_hdd_set_mas");
        result = 4294967285LL;
        goto LABEL_18;
      }
    }
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Set/reset P2P quota: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_hdd_update_mcc_p2p_quota",
      1);
    if ( *(_DWORD *)(a1 + 40) )
      v23 = 70;
    else
      v23 = 30;
    wlan_hdd_set_mcc_p2p_quota(a1, v23);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Miracast is OFF. Enable MAS and reset P2P quota",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_set_mas");
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Set/reset P2P quota: %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_hdd_update_mcc_p2p_quota",
      0);
    wlan_hdd_set_mcc_p2p_quota(a1, 50);
    ucfg_policy_mgr_get_mcc_adaptive_sch(*v10, v32);
    result = 0;
    if ( v32[0] == 1 )
    {
      ucfg_policy_mgr_set_dynamic_mcc_adaptive_sch(*v10, 1);
      result = sme_set_mas(1);
      if ( (_DWORD)result )
      {
        v20 = "%s: Failed to enable MAS";
        goto LABEL_17;
      }
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
