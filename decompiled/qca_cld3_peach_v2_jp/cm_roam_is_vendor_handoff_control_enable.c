__int64 __fastcall cm_roam_is_vendor_handoff_control_enable(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20
  int vendor_handoff_control_caps; // w19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    v3 = *(unsigned __int8 *)(result + 7116);
    vendor_handoff_control_caps = wlan_mlme_get_vendor_handoff_control_caps(a1);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: ini flag:%d, fw caps:%d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "cm_roam_is_vendor_handoff_control_enable",
      v3,
      vendor_handoff_control_caps & 1);
    return vendor_handoff_control_caps & v3;
  }
  return result;
}
