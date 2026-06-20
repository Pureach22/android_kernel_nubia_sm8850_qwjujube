__int64 __fastcall tgt_if_regulatory_set_user_country_code(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w20
  __int64 pdev_by_id; // x0
  __int64 *v6; // x8
  __int64 v7; // x8
  __int64 v8; // x21
  unsigned int v9; // w19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  v4 = a2;
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, a2, 22);
  if ( pdev_by_id && (v6 = *(__int64 **)(pdev_by_id + 1240)) != nullptr && (v7 = *v6) != 0 )
  {
    v8 = pdev_by_id;
    v9 = wmi_unified_set_user_country_code_cmd_send(v7, v4, a3);
    if ( v9 )
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Set user country code failed,status %d",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "tgt_if_regulatory_set_user_country_code",
        v9);
    pdev_by_id = v8;
  }
  else
  {
    v9 = 16;
  }
  wlan_objmgr_pdev_release_ref(pdev_by_id, 22);
  return v9;
}
