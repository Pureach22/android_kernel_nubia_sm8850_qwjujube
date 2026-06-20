__int64 __fastcall ipa_wlan_evt(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        char a7)
{
  __int64 v7; // x25
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v7 = *(_QWORD *)(a1 + 80);
  if ( (ipa_cb_is_ready(a1) & 1) == 0 )
    return 0;
  if ( wlan_objmgr_psoc_get_comp_private_obj(v7, 0x1Au) )
    return wlan_ipa_wlan_evt(a2, a3, a4, a5, a6, a7 & 1);
  qdf_trace_msg(0x61u, 2u, "%s: IPA object is NULL", v14, v15, v16, v17, v18, v19, v20, v21, "ipa_wlan_evt");
  return 16;
}
