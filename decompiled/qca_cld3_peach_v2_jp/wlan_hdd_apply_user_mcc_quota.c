__int64 __fastcall wlan_hdd_apply_user_mcc_quota(__int64 a1)
{
  __int64 *v1; // x22
  unsigned int user_mcc_duty_cycle_percentage; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w20
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x19
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  _BYTE v40[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v41[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(__int64 **)(a1 + 24);
  if ( v1 )
  {
    user_mcc_duty_cycle_percentage = wlan_mlme_get_user_mcc_duty_cycle_percentage(*v1);
    if ( !user_mcc_duty_cycle_percentage )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: no mcc/quota for mode %d, vdev_id : %u",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "wlan_hdd_apply_user_mcc_quota",
        *(unsigned int *)(a1 + 40),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL));
      goto LABEL_11;
    }
    v12 = user_mcc_duty_cycle_percentage;
    v13 = *v1;
    v40[0] = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enable : %d", v4, v5, v6, v7, v8, v9, v10, v11, "wlan_hdd_set_mcc_adaptive_sched", 0);
    ucfg_policy_mgr_get_mcc_adaptive_sch(v13, v40);
    if ( v40[0] == 1 )
    {
      ucfg_policy_mgr_set_dynamic_mcc_adaptive_sch(v13, 0);
      if ( (unsigned int)sme_set_mas(0) )
      {
LABEL_8:
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Fail to config mcc adaptive sched.",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_hdd_set_mcc_adaptive_sched");
LABEL_11:
        result = 0;
        goto LABEL_12;
      }
    }
    result = wlan_hdd_send_mcc_vdev_quota(a1, v12, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: Could not send quota",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wlan_hdd_apply_user_mcc_quota");
      v31 = *v1;
      v41[0] = 0;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: enable : %d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "wlan_hdd_set_mcc_adaptive_sched",
        1);
      ucfg_policy_mgr_get_mcc_adaptive_sch(v31, v41);
      if ( v41[0] != 1 )
        goto LABEL_11;
      ucfg_policy_mgr_set_dynamic_mcc_adaptive_sch(v31, 1);
      if ( !(unsigned int)sme_set_mas(1) )
        goto LABEL_11;
      goto LABEL_8;
    }
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
