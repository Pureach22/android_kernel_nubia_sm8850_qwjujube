__int64 __fastcall ipa_uc_disconnect_ap(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  _DWORD *comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  v2 = *(_QWORD *)(a1 + 80);
  if ( (ipa_cb_is_ready(a1) & 1) == 0 )
    return 0;
  comp_private_obj = (_DWORD *)wlan_objmgr_psoc_get_comp_private_obj(v2, 0x1Au);
  if ( comp_private_obj )
    return wlan_ipa_uc_disconnect_ap(comp_private_obj, a2, v5, v6, v7, v8, v9, v10, v11, v12);
  qdf_trace_msg(0x61u, 2u, "%s: IPA object is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "ipa_uc_disconnect_ap");
  return 16;
}
