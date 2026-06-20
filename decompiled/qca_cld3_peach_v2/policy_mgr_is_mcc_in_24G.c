bool __fastcall policy_mgr_is_mcc_in_24G(__int64 a1)
{
  __int64 *context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  int sta_p2p_conn_info; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w21
  unsigned int v21; // w20
  _BOOL8 result; // x0
  unsigned int v23; // w21
  unsigned int v24; // w20
  unsigned int v25; // w19
  __int64 v26; // [xsp+0h] [xbp-C0h] BYREF
  __int64 v27; // [xsp+8h] [xbp-B8h]
  __int64 v28; // [xsp+10h] [xbp-B0h]
  __int64 v29; // [xsp+18h] [xbp-A8h]
  __int64 v30; // [xsp+20h] [xbp-A0h]
  __int64 v31; // [xsp+28h] [xbp-98h]
  __int64 v32; // [xsp+30h] [xbp-90h]
  __int64 v33; // [xsp+38h] [xbp-88h]
  __int64 v34; // [xsp+40h] [xbp-80h]
  __int64 v35; // [xsp+48h] [xbp-78h]
  __int64 v36; // [xsp+50h] [xbp-70h]
  __int64 v37; // [xsp+58h] [xbp-68h]
  __int64 v38; // [xsp+60h] [xbp-60h]
  __int64 v39; // [xsp+68h] [xbp-58h]
  __int64 v40; // [xsp+70h] [xbp-50h]
  __int64 v41; // [xsp+78h] [xbp-48h]
  __int64 v42; // [xsp+80h] [xbp-40h]
  __int64 v43; // [xsp+88h] [xbp-38h]
  __int64 v44; // [xsp+90h] [xbp-30h]
  __int64 v45; // [xsp+98h] [xbp-28h]
  __int64 v46; // [xsp+A0h] [xbp-20h]
  __int64 v47; // [xsp+A8h] [xbp-18h]
  int v48; // [xsp+B0h] [xbp-10h]
  __int64 v49; // [xsp+B8h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  context = (__int64 *)policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "policy_mgr_is_mcc_in_24G",
      v26,
      v27,
      v28,
      v29,
      v30);
    goto LABEL_16;
  }
  sta_p2p_conn_info = policy_mgr_get_sta_p2p_conn_info(context, (__int64)&v26);
  if ( sta_p2p_conn_info == 1 )
  {
LABEL_16:
    result = 0;
    goto LABEL_17;
  }
  if ( sta_p2p_conn_info == 3 )
  {
    v23 = HIDWORD(v26);
    v24 = v31;
    v25 = HIDWORD(v35);
    if ( (HIDWORD(v26) != (_DWORD)v31 || HIDWORD(v26) != HIDWORD(v35))
      && v23 <= (unsigned int)wlan_reg_max_24ghz_chan_freq()
      && v24 <= (unsigned int)wlan_reg_max_24ghz_chan_freq() )
    {
      result = v25 <= (unsigned int)wlan_reg_max_24ghz_chan_freq();
      goto LABEL_17;
    }
    goto LABEL_16;
  }
  if ( sta_p2p_conn_info != 2 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: unexpected num_connections value %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "policy_mgr_is_mcc_in_24G",
      v26,
      v27,
      v28,
      v29,
      v30);
    goto LABEL_16;
  }
  v20 = HIDWORD(v26);
  v21 = v31;
  if ( HIDWORD(v26) == (_DWORD)v31
    || (policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(v26), v31) & 1) == 0
    || v20 > (unsigned int)wlan_reg_max_24ghz_chan_freq() )
  {
    goto LABEL_16;
  }
  result = v21 <= (unsigned int)wlan_reg_max_24ghz_chan_freq();
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
