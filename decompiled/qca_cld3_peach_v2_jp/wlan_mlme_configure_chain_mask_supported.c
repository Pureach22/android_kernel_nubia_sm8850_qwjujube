__int64 __fastcall wlan_mlme_configure_chain_mask_supported(__int64 a1)
{
  __int64 result; // x0
  unsigned __int8 *v3; // x22
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w20
  unsigned int v13; // w21
  bool is_hw_dbs_2x2_capable; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  _BYTE v24[4]; // [xsp+14h] [xbp-3Ch] BYREF
  _QWORD v25[4]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v26; // [xsp+38h] [xbp-18h]
  __int64 v27; // [xsp+40h] [xbp-10h]
  __int64 v28; // [xsp+48h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  memset(v25, 0, sizeof(v25));
  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    v3 = (unsigned __int8 *)result;
    v24[0] = 0;
    if ( (unsigned int)wma_get_caps_for_phyidx_hwmode(v25, 0, 0) )
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: couldn't get phy caps. skip chain mask programming",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "wlan_mlme_configure_chain_mask_supported");
LABEL_17:
      result = 0;
      goto LABEL_18;
    }
    if ( (unsigned int)v26 < 3 || HIDWORD(v26) < 3 || (unsigned int)v27 < 3 || HIDWORD(v27) <= 2 )
    {
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: firmware not capable. skip chain mask programming",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "wlan_mlme_configure_chain_mask_supported");
      goto LABEL_17;
    }
    v12 = v3[12];
    v13 = v3[1072];
    ucfg_policy_mgr_get_dual_mac_feature(a1, v24);
    is_hw_dbs_2x2_capable = policy_mgr_is_hw_dbs_2x2_capable(a1);
    if ( v3[2667] )
    {
      v23 = v24[0];
      if ( !v12 || v13 || !is_hw_dbs_2x2_capable && v24[0] != 1 )
        goto LABEL_16;
    }
    else if ( v13 )
    {
      v23 = v24[0];
LABEL_16:
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: Cannot configure chainmask enable_bt_chain_sep %d as_enabled %d enable_mimo %d hw_dbs_2x2_cap %d dual_mac_feature %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wlan_mlme_configure_chain_mask_supported",
        v12,
        v13,
        v23);
      goto LABEL_17;
    }
    result = 1;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
