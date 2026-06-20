__int64 __fastcall ipa_fw_rejuvenate_send_msg(
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
  __int64 v9; // x0
  __int64 comp_private_obj; // x0
  const char *v12; // x2
  unsigned int v13; // w1

  if ( !a1 )
  {
    v12 = "%s: objmgr pdev is null!";
LABEL_7:
    v13 = 8;
    return qdf_trace_msg(0x61u, v13, v12, a2, a3, a4, a5, a6, a7, a8, a9, "ipa_fw_rejuvenate_send_msg");
  }
  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    v12 = "%s: objmgr psoc is null!";
    goto LABEL_7;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v9, 0x1Au);
  if ( comp_private_obj )
    return wlan_ipa_fw_rejuvenate_send_msg(comp_private_obj);
  v12 = "%s: IPA object is NULL";
  v13 = 2;
  return qdf_trace_msg(0x61u, v13, v12, a2, a3, a4, a5, a6, a7, a8, a9, "ipa_fw_rejuvenate_send_msg");
}
