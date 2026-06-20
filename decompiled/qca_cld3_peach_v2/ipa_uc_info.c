__int64 __fastcall ipa_uc_info(
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
  const char *v9; // x2
  unsigned int v10; // w1
  __int64 result; // x0
  __int64 v12; // x19

  if ( !g_ipa_config || (*(_BYTE *)g_ipa_config & 1) == 0 )
  {
    v9 = "%s: ipa is disabled";
    v10 = 8;
    return qdf_trace_msg(0x61u, v10, v9, a2, a3, a4, a5, a6, a7, a8, a9, "ipa_uc_info");
  }
  v12 = *(_QWORD *)(a1 + 80);
  result = ipa_cb_is_ready();
  if ( (result & 1) != 0 )
  {
    if ( wlan_objmgr_psoc_get_comp_private_obj(v12, 0x1Au) )
      return wlan_ipa_uc_info();
    v9 = "%s: IPA object is NULL";
    v10 = 2;
    return qdf_trace_msg(0x61u, v10, v9, a2, a3, a4, a5, a6, a7, a8, a9, "ipa_uc_info");
  }
  return result;
}
