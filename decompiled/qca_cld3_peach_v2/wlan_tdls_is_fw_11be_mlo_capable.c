__int64 __fastcall wlan_tdls_is_fw_11be_mlo_capable(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  char v11; // w8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xAu);
  if ( comp_private_obj )
  {
    v10 = comp_private_obj;
    qdf_trace_msg(
      0,
      8u,
      "%s: FW 11BE capability %d",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_tdls_is_fw_11be_mlo_capable",
      *(unsigned __int8 *)(comp_private_obj + 584));
    v11 = *(_BYTE *)(v10 + 584);
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: Failed to get tdls psoc component",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_tdls_is_fw_11be_mlo_capable");
    v11 = 0;
  }
  return v11 & 1;
}
