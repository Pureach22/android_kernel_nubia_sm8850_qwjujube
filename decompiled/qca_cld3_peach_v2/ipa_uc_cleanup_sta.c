__int64 __fastcall ipa_uc_cleanup_sta(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 v3; // x21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 comp_private_obj; // x0
  const char *v16; // x2
  unsigned int v17; // w1

  v3 = *(_QWORD *)(a1 + 80);
  if ( (ipa_cb_is_ready(a1) & 1) != 0 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v3, 0x1Au);
    if ( comp_private_obj )
      return wlan_ipa_uc_cleanup_sta(comp_private_obj, a2, a3, v6, v7, v8, v9, v10, v11, v12, v13);
    v16 = "%s: IPA object is NULL";
    v17 = 2;
  }
  else
  {
    v16 = "%s: ipa is not ready";
    v17 = 8;
  }
  return qdf_trace_msg(0x61u, v17, v16, v6, v7, v8, v9, v10, v11, v12, v13, "ipa_uc_cleanup_sta");
}
