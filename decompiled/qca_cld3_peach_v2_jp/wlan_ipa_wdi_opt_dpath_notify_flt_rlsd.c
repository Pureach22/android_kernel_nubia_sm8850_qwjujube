__int64 __fastcall wlan_ipa_wdi_opt_dpath_notify_flt_rlsd(int a1, __int64 a2)
{
  int v3; // w19
  _QWORD *v4; // x21
  _BYTE *v5; // x22
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w8
  const char *v15; // x2
  unsigned int v16; // w1
  char v17; // w19
  int v18; // w3
  int v19; // w4
  int v20; // w5
  int v21; // w6
  int v22; // w7
  __int64 result; // x0
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x0
  __int64 v34; // x19
  __int64 v35; // x0
  __int64 v36; // x8
  unsigned int (*v37)(void); // x8
  __int64 v38; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  v3 = a2;
  v4 = (_QWORD *)gp_ipa;
  v5 = (_BYTE *)(gp_ipa + 4096);
  qdf_event_set(gp_ipa + 8072, a2);
  v14 = (unsigned __int8)v5[3343];
  if ( v14 != 3 )
  {
    if ( (a1 || (v5[3485] & 1) == 0) && (v3 || (v5[3589] & 1) == 0) )
    {
      v5[3485] = 0;
      v17 = 1;
      v5[3589] = 0;
      if ( v14 == 1 )
        goto LABEL_10;
    }
    else
    {
      if ( v5[3419] != 1 )
      {
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: opt_dp: filter release failed, req src - %d",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "wlan_ipa_wdi_opt_dpath_notify_flt_rlsd");
        result = wlan_ipa_log_message(
                   (int)"wlan_ipa_wdi_opt_dpath_notify_flt_rlsd",
                   (int)"opt_dp: filter release failed, req src - %d",
                   (unsigned __int8)v5[3419],
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   vars0);
        goto LABEL_25;
      }
      v17 = 0;
      if ( v14 == 1 )
      {
LABEL_10:
        v15 = "%s: opt_dp: received delayed response, retry";
LABEL_31:
        v16 = 2;
        return qdf_trace_msg(
                 0x61u,
                 v16,
                 v15,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 "wlan_ipa_wdi_opt_dpath_notify_flt_rlsd");
      }
    }
    v24 = _qdf_mem_malloc(0x20u, "wlan_ipa_wdi_opt_dpath_notify_flt_rlsd", 7401);
    if ( v24 )
    {
      *(_BYTE *)(v24 + 1) = v17;
      *(_WORD *)(v24 + 2) = 10;
      v4[310] = v24;
      queue_work_on(32, system_wq, v4 + 304);
      if ( (v17 & 1) == 0 )
      {
        v15 = "%s: opt_dp: received filter release failure from FW";
        goto LABEL_31;
      }
      v5[3342] = 0;
      v33 = _qdf_mem_malloc(0x20u, "wlan_ipa_wdi_opt_dpath_notify_flt_rlsd", 7421);
      if ( !v33 )
      {
        v15 = "%s: Message memory allocation failed";
        goto LABEL_31;
      }
      v34 = v33;
      v35 = v4[182];
      if ( v35 && *(_QWORD *)v35 && (v36 = *(_QWORD *)(*(_QWORD *)v35 + 152LL)) != 0 )
      {
        v37 = *(unsigned int (**)(void))(v36 + 216);
        if ( !v37 )
          goto LABEL_23;
        if ( *((_DWORD *)v37 - 1) != 639071501 )
          __break(0x8228u);
        if ( !v37() )
        {
LABEL_23:
          qdf_trace_msg(
            0x61u,
            2u,
            "%s: IPA SMMU not mapped!!",
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            "wlan_ipa_wdi_opt_dpath_notify_flt_rlsd");
          _qdf_mem_free(v34);
LABEL_29:
          qdf_wake_lock_release((__int64)(v4 + 1024), 0x1Fu);
          v15 = "%s: opt_dp: Wakelock released";
          goto LABEL_3;
        }
      }
      else
      {
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v6, v7, v8, v9, v10, v11, v12, v13, "cdp_ipa_get_smmu_mapped");
      }
      *(_WORD *)(v34 + 2) = 12;
      v38 = v4[182];
      v4[332] = v34;
      cdp_ipa_set_smmu_mapped(v38, v6, v7, v8, v9, v10, v11, v12, v13);
      queue_work_on(32, system_wq, v4 + 326);
      goto LABEL_29;
    }
    result = qdf_trace_msg(
               0x61u,
               2u,
               "%s: Message memory allocation failed",
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               "wlan_ipa_wdi_opt_dpath_notify_flt_rlsd");
LABEL_25:
    v5[3343] = 1;
    return result;
  }
  v15 = "%s: opt_dp: filter released already";
LABEL_3:
  v16 = 8;
  return qdf_trace_msg(0x61u, v16, v15, v6, v7, v8, v9, v10, v11, v12, v13, "wlan_ipa_wdi_opt_dpath_notify_flt_rlsd");
}
