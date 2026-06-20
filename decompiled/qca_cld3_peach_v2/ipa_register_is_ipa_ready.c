__int64 __fastcall ipa_register_is_ipa_ready(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  int v11; // w3
  int v12; // w4
  int v13; // w5
  int v14; // w6
  int v15; // w7
  int v16; // w20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w2
  int v26; // w2
  int v27; // w3
  int v28; // w4
  int v29; // w5
  int v30; // w6
  int v31; // w7
  unsigned int ready; // w4
  const char *v33; // x2
  __int64 comp_private_obj; // x0
  __int64 v35; // x20
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  char vars0; // [xsp+0h] [xbp+0h]

  if ( (ipa_config_is_enabled() & 1) != 0 )
  {
    v10 = *(_QWORD *)(a1 + 80);
    if ( v10 )
    {
      v16 = *(_DWORD *)(cfg_psoc_get_values(v10) + 1112);
      if ( v16 == -286331154 )
      {
        v25 = 0;
      }
      else
      {
        if ( v16 == 125 )
          qdf_trace_msg(
            0x61u,
            2u,
            "%s: Invalid IPA Config 0x%x",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "get_ipa_config",
            125);
        if ( v16 == 6781 )
          v25 = 6781;
        else
          v25 = 637;
      }
      wlan_ipa_log_message(
        (int)"ipa_register_is_ipa_ready",
        (int)"IPA ini configuration: 0x%x",
        v25,
        v11,
        v12,
        v13,
        v14,
        v15,
        vars0);
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v10, 0x1Au);
      if ( comp_private_obj )
      {
        v35 = comp_private_obj;
        if ( *(_BYTE *)(comp_private_obj + 7457) == 1 )
        {
          qdf_trace_msg(
            0x61u,
            4u,
            "%s: ipa ready cb registered for psoc_id %d",
            v2,
            v3,
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            "ipa_register_is_ipa_ready",
            *(unsigned __int8 *)(v10 + 48));
          return 0;
        }
        ready = ipa_register_ipa_ready_cb(ipa_register_ready_cb, comp_private_obj);
        if ( !ready )
          return ready;
        if ( ready == -17 )
        {
          qdf_trace_msg(
            0x61u,
            4u,
            "%s: IPA is ready, invoke callback",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "ipa_register_is_ipa_ready");
          ipa_register_ready_cb(v35);
          return 0;
        }
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: Failed to check IPA readiness %d",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "ipa_register_is_ipa_ready");
        return 16;
      }
      v33 = "%s: IPA object is NULL";
    }
    else
    {
      v33 = "%s: PSOC object is NULL";
    }
    qdf_trace_msg(0x61u, 2u, v33, v2, v3, v4, v5, v6, v7, v8, v9, "ipa_register_is_ipa_ready");
    return 16;
  }
  qdf_trace_msg(0x61u, 4u, "%s: IPA config is disabled", v2, v3, v4, v5, v6, v7, v8, v9, "ipa_register_is_ipa_ready");
  wlan_ipa_log_message(
    (int)"ipa_register_is_ipa_ready",
    (int)"IPA config is disabled",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    vars0);
  return 0;
}
