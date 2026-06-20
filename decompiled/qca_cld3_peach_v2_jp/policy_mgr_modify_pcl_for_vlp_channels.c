__int64 __fastcall policy_mgr_modify_pcl_for_vlp_channels(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _DWORD *v31; // x20
  __int64 result; // x0
  __int16 v33; // [xsp+4h] [xbp-Ch] BYREF
  char v34; // [xsp+6h] [xbp-Ah]
  __int64 v35; // [xsp+8h] [xbp-8h]

  LODWORD(v13) = a4;
  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v33 = 0;
  wlan_reg_read_current_country(a1, &v33, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !(unsigned __int8)wlan_reg_get_num_rules_of_ap_pwr_type(a2, 2u, v15, v16, v17, v18, v19, v20, v21, v22) )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Current country %.2s don't support VLP",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "policy_mgr_modify_pcl_for_vlp_channels",
      &v33);
LABEL_10:
    result = 4;
    goto LABEL_11;
  }
  if ( !(_DWORD)v13 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: invalid number of channel length",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "policy_mgr_modify_pcl_for_vlp_channels");
    goto LABEL_10;
  }
  v13 = (unsigned int)v13;
  v31 = (_DWORD *)(a3 + 4);
  do
  {
    if ( (wlan_reg_is_vlp_depriority_freq(a2, *(v31 - 1)) & 1) != 0 )
      *v31 = 175;
    --v13;
    v31 += 3;
  }
  while ( v13 );
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
