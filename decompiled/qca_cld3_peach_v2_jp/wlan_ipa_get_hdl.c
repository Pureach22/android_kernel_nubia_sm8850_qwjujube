__int64 __fastcall wlan_ipa_get_hdl(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Au);
  if ( comp_private_obj )
    return *(unsigned int *)(comp_private_obj + 7460);
  qdf_trace_msg(
    0x61u,
    2u,
    "%s: IPA object is NULL for psoc_id[%d]",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "wlan_ipa_get_hdl",
    *(unsigned __int8 *)(a1 + 48));
  return 255;
}
