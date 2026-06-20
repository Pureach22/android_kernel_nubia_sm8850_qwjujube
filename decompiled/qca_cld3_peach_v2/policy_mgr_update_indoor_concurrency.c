__int64 __fastcall policy_mgr_update_indoor_concurrency(__int64 a1, unsigned int a2, unsigned int a3, int a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  __int64 v18; // x0
  int v19; // w8
  unsigned int bw_by_session_id; // w0
  unsigned int v21; // w23
  unsigned int v22; // w24
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  const char *v40; // x2
  const char *v41; // x3
  __int64 v42; // x0
  unsigned __int8 v43; // w1
  unsigned int v44; // w2
  unsigned int v45; // w3
  char v46; // w4
  __int64 v47; // [xsp+0h] [xbp-10h] BYREF
  __int64 v48; // [xsp+8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOBYTE(v47) = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v40 = "%s: Invalid pm context";
    v41 = "policy_mgr_update_indoor_concurrency";
LABEL_20:
    qdf_trace_msg(0x4Fu, 2u, v40, v9, v10, v11, v12, v13, v14, v15, v16, v41, v47, v48);
    goto LABEL_21;
  }
  v17 = context;
  ucfg_mlme_get_indoor_channel_support(a1, &v47);
  if ( (v47 & 1) != 0 )
    goto LABEL_21;
  v18 = policy_mgr_get_context(a1);
  if ( !v18 )
  {
    v40 = "%s: pm_ctx is NULL";
    v41 = "policy_mgr_get_sta_sap_scc_allowed_on_indoor_chnl";
    goto LABEL_20;
  }
  if ( *(_BYTE *)(v18 + 2214) != 1 )
    goto LABEL_21;
  v19 = wlan_get_opmode_from_vdev_id(*(_QWORD *)(v17 + 8), a2) & 0xFFFFFFFD;
  if ( a4 != 2 )
  {
    if ( v19 )
      goto LABEL_21;
  }
  if ( a4 == 2 && v19 != 1 || (unsigned int)a4 > 4 )
    goto LABEL_21;
  if ( ((1 << a4) & 0x19) != 0 )
  {
    HIDWORD(v47) = 0;
    policy_mgr_get_chan_by_session_id(a1, a2, (_DWORD *)&v47 + 1);
    bw_by_session_id = policy_mgr_get_bw_by_session_id(a1, a2);
    v21 = HIDWORD(v47);
    v22 = bw_by_session_id;
    if ( a4 == 3 )
      goto LABEL_12;
  }
  else
  {
    v22 = 8;
    v21 = a3;
  }
  if ( !wlan_reg_is_5ghz_ch_freq(v21) || (wlan_reg_is_freq_indoor() & 1) == 0 )
    goto LABEL_21;
  if ( a4 <= 1 )
  {
    if ( !a4 )
      goto LABEL_32;
    v42 = *(_QWORD *)(v17 + 8);
    v43 = a2;
    v44 = 0;
LABEL_35:
    v45 = 8;
    v46 = 0;
    goto LABEL_36;
  }
  if ( a4 == 2 )
  {
    if ( (unsigned int)policy_mgr_get_connection_count_with_ch_freq(v21) <= 1 )
    {
      v42 = *(_QWORD *)(v17 + 8);
      v43 = -1;
      v44 = v21;
      goto LABEL_35;
    }
LABEL_21:
    result = 0;
    goto LABEL_22;
  }
  if ( a4 == 4 )
  {
    wlan_reg_modify_indoor_concurrency(*(_QWORD *)(v17 + 8), a2, v21, v22, 1, v31, v32, v33, v34, v35, v36, v37, v38);
    goto LABEL_21;
  }
LABEL_12:
  if ( (!wlan_reg_is_5ghz_ch_freq(v21) || (wlan_reg_is_freq_indoor() & 1) == 0)
    && (!wlan_reg_is_5ghz_ch_freq(a3) || (wlan_reg_is_freq_indoor() & 1) == 0) )
  {
    goto LABEL_21;
  }
  wlan_reg_modify_indoor_concurrency(*(_QWORD *)(v17 + 8), a2, 0, 8u, 0, v23, v24, v25, v26, v27, v28, v29, v30);
  if ( (wlan_reg_is_freq_indoor() & 1) != 0 )
  {
LABEL_32:
    v42 = *(_QWORD *)(v17 + 8);
    v43 = a2;
    v44 = v21;
    v45 = v22;
    v46 = 1;
LABEL_36:
    wlan_reg_modify_indoor_concurrency(v42, v43, v44, v45, v46, v31, v32, v33, v34, v35, v36, v37, v38);
    result = 1;
    goto LABEL_22;
  }
  result = 1;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
