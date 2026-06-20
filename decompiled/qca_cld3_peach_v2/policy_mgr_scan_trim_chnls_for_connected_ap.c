__int64 __fastcall policy_mgr_scan_trim_chnls_for_connected_ap(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // [xsp+8h] [xbp-18h] BYREF
  int v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 80);
  if ( !v1 )
    goto LABEL_4;
  v3 = *(_QWORD *)(a1 + 80);
  v22 = 0;
  v21 = 0;
  if ( (unsigned int)wlan_mlme_get_band_capability(v3, &v21) )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Could not get band capability",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "policy_mgr_scan_trim_chnls_for_connected_ap");
LABEL_4:
    result = 0;
    goto LABEL_5;
  }
  result = policy_mgr_mode_specific_connection_count(v1, 1, nullptr);
  HIDWORD(v21) = result;
  if ( (_DWORD)result )
  {
    LOWORD(v22) = 0;
    wlan_objmgr_pdev_iterate_obj_list(
      a1,
      2,
      (void (__fastcall *)(__int64, __int64, __int64))policy_mgr_fill_trim_chan,
      (__int64)&v21,
      0,
      0x18u);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: band_capability %d, sap_count %d, trim %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "policy_mgr_scan_trim_chnls_for_connected_ap",
      (unsigned int)v21,
      HIDWORD(v21),
      (unsigned __int16)v22);
    result = (unsigned __int16)v22;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
