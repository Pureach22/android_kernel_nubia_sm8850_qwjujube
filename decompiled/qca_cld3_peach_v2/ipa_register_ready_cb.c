__int64 __fastcall ipa_register_ready_cb(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  const char *v10; // x2
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2
  unsigned int v21; // w0
  int v22; // w3
  int v23; // w4
  int v24; // w5
  int v25; // w6
  int v26; // w7
  __int64 v27; // x20
  __int64 v28; // x4
  __int64 v29; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w3
  int v39; // w4
  int v40; // w5
  int v41; // w6
  int v42; // w7
  char v43; // [xsp+0h] [xbp-10h]
  char v44; // [xsp+0h] [xbp-10h]
  _BYTE v45[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45[0] = 0;
  if ( (ipa_config_is_enabled() & 1) != 0 )
  {
    if ( !a1 )
    {
      v10 = "%s: User_data object is NULL";
      goto LABEL_7;
    }
    if ( (qdf_is_driver_state_module_stop() & 1) != 0 )
    {
      v10 = "%s: Driver modules stop in-progress or done";
LABEL_7:
      result = qdf_trace_msg(0x61u, 2u, v10, v2, v3, v4, v5, v6, v7, v8, v9, "ipa_register_ready_cb");
      goto LABEL_17;
    }
    qdf_mutex_acquire((__int64)&g_init_deinit_lock);
    if ( (qdf_is_driver_state_module_stop() & 1) != 0 )
    {
      v20 = "%s: Driver modules stop in-progress/done, releasing lock";
    }
    else
    {
      g_ipa_is_ready = 1;
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: IPA ready callback invoked: %s",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "ipa_register_ready_cb",
        "ipa_register_ready_cb");
      wlan_ipa_log_message(
        (int)"ipa_register_ready_cb",
        (int)"IPA ready callback invoked: %s",
        (int)"ipa_register_ready_cb",
        v22,
        v23,
        v24,
        v25,
        v26,
        v43);
      ipa_wdi_get_capabilities(v45);
      v27 = *(_QWORD *)a1;
      if ( !*(_QWORD *)a1 )
      {
        v20 = "%s: Psoc is NULL";
        v21 = 56;
        goto LABEL_15;
      }
      v28 = *(unsigned __int8 *)(v27 + 48);
      if ( *(_BYTE *)(a1 + 7457) == 1 )
      {
        qdf_trace_msg(
          0x61u,
          4u,
          "%s: ipa_obj hdl is true for psoc_id %d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "ipa_register_ready_cb",
          v28);
LABEL_16:
        result = qdf_mutex_release((__int64)&g_init_deinit_lock);
        goto LABEL_17;
      }
      *(_BYTE *)(a1 + 7456) = v28;
      v29 = *(_QWORD *)(v27 + 2120);
      if ( v29 )
      {
        if ( !(unsigned int)ipa_obj_setup(a1, v12, v13, v14, v15, v16, v17, v18, v19) )
        {
          if ( (unsigned int)ucfg_ipa_uc_ol_init(v27, v29) )
          {
            qdf_trace_msg(
              0x61u,
              2u,
              "%s: IPA ucfg_ipa_uc_ol_init failed",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "ipa_register_ready_cb");
            ipa_obj_cleanup(a1);
            g_ipa_is_ready = 0;
          }
          else
          {
            *(_BYTE *)(a1 + 7457) = 1;
            qdf_trace_msg(
              0x61u,
              4u,
              "%s: No. of instances added for IPA is %d",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "ipa_register_ready_cb",
              (unsigned __int8)++g_instances_added);
            wlan_ipa_log_message(
              (int)"ipa_register_ready_cb",
              (int)"No. of instances added for IPA is %d",
              (unsigned __int8)g_instances_added,
              v38,
              v39,
              v40,
              v41,
              v42,
              v44);
          }
          goto LABEL_16;
        }
        g_ipa_is_ready = 0;
        v20 = "%s: Failed to ipa_obj_setup";
      }
      else
      {
        v20 = "%s: QDF device context is NULL";
      }
    }
    v21 = 97;
LABEL_15:
    qdf_trace_msg(v21, 2u, v20, v12, v13, v14, v15, v16, v17, v18, v19, "ipa_register_ready_cb");
    goto LABEL_16;
  }
  result = qdf_trace_msg(
             0x61u,
             4u,
             "%s: IPA config is disabled",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "ipa_register_ready_cb");
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
