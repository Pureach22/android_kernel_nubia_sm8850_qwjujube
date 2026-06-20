bool __fastcall ipa_is_fw_wdi_activated(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  bool v10; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 comp_private_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v30; // x20

  if ( g_ipa_config && (*(_BYTE *)g_ipa_config & 1) != 0 )
  {
    if ( (ipa_cb_is_ready(a1) & 1) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Au);
      if ( comp_private_obj )
        return wlan_ipa_is_fw_wdi_activated(comp_private_obj);
      v30 = jiffies;
      if ( ipa_is_fw_wdi_activated___last_ticks_7 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: IPA object is NULL",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "ipa_is_fw_wdi_activated");
        v10 = 0;
        ipa_is_fw_wdi_activated___last_ticks_7 = v30;
        return v10;
      }
    }
    else
    {
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: ipa is not ready",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "ipa_is_fw_wdi_activated");
    }
    return 0;
  }
  v9 = jiffies;
  if ( ipa_is_fw_wdi_activated___last_ticks - jiffies + 125 >= 0 )
    return 0;
  qdf_trace_msg(0x61u, 8u, "%s: ipa is disabled", a2, a3, a4, a5, a6, a7, a8, a9, "ipa_is_fw_wdi_activated");
  v10 = 0;
  ipa_is_fw_wdi_activated___last_ticks = v9;
  return v10;
}
