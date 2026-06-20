__int64 __fastcall ipa_cleanup_dev_iface(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 v3; // x21
  __int64 result; // x0
  __int64 comp_private_obj; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  v3 = *(_QWORD *)(a1 + 80);
  result = ipa_cb_is_ready(a1);
  if ( (result & 1) != 0 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v3, 0x1Au);
    if ( comp_private_obj )
      return wlan_ipa_cleanup_dev_iface(comp_private_obj, a2, a3, v8, v9, v10, v11, v12, v13, v14, v15);
    else
      return qdf_trace_msg(
               0x61u,
               2u,
               "%s: IPA object is NULL",
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               "ipa_cleanup_dev_iface");
  }
  return result;
}
