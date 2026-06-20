__int64 __fastcall ipa_set_ap_ibss_fwd(
        __int64 a1,
        unsigned __int8 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const char *v11; // x2
  unsigned int v12; // w1
  __int64 result; // x0
  __int64 v14; // x20

  if ( !g_ipa_config || (*(_BYTE *)g_ipa_config & 1) == 0 )
  {
    v11 = "%s: ipa is disabled";
    v12 = 8;
    return qdf_trace_msg(0x61u, v12, v11, a4, a5, a6, a7, a8, a9, a10, a11, "ipa_set_ap_ibss_fwd");
  }
  v14 = *(_QWORD *)(a1 + 80);
  result = ipa_cb_is_ready();
  if ( (result & 1) != 0 )
  {
    result = wlan_objmgr_psoc_get_comp_private_obj(v14, 0x1Au);
    if ( !result )
    {
      v11 = "%s: IPA object is NULL";
      v12 = 2;
      return qdf_trace_msg(0x61u, v12, v11, a4, a5, a6, a7, a8, a9, a10, a11, "ipa_set_ap_ibss_fwd");
    }
    if ( a2 <= 4u )
      *(_BYTE *)(result + a2 + 7352) = a3 & 1;
  }
  return result;
}
