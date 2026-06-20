__int64 __fastcall policy_mgr_incr_connection_count(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x23
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x24
  unsigned int v26; // w22
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  unsigned int connection_info; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w19
  unsigned int connection_table_entry_info; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w20
  unsigned int v56; // w23
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  int v73; // w24
  int v74; // w25
  bool is_24ghz_ch_freq; // w0
  unsigned __int8 *v76; // x8
  int bw; // w0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  _BYTE v86[4]; // [xsp+20h] [xbp-30h] BYREF
  _BYTE v87[4]; // [xsp+24h] [xbp-2Ch] BYREF
  __int64 v88; // [xsp+28h] [xbp-28h] BYREF
  __int64 v89; // [xsp+30h] [xbp-20h]
  __int64 v90; // [xsp+38h] [xbp-18h]
  int v91; // [xsp+40h] [xbp-10h]
  __int64 v92; // [xsp+48h] [xbp-8h]

  v92 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v91 = 0;
  v89 = 0;
  v90 = 0;
  v88 = 0;
  v87[0] = 0;
  v86[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: context is NULL",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_incr_connection_count");
    result = 16;
    goto LABEL_33;
  }
  v15 = context;
  v16 = policy_mgr_get_context(a1);
  if ( v16 )
  {
    v25 = v16;
    qdf_mutex_acquire(v16 + 56);
    v26 = BYTE4(qword_8D4F24) + BYTE4(qword_8D4F00) + BYTE4(qword_8D4F48) + BYTE4(qword_8D4F6C) + BYTE4(qword_8D4F90);
    qdf_mutex_release(v25 + 56);
    if ( v26 > *(unsigned __int8 *)(v15 + 2202) )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: exceeded max connection limit %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "policy_mgr_incr_connection_count");
      result = 16;
      goto LABEL_33;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "policy_mgr_get_connection_count");
    v26 = 0;
  }
  if ( a3 == 16 )
  {
    connection_info = wlan_nan_get_connection_info(a1, &v88);
    if ( connection_info )
    {
      v45 = connection_info;
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Can't get NAN Connection info",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "policy_mgr_incr_connection_count");
      result = v45;
      goto LABEL_33;
    }
    a3 = 5;
    goto LABEL_23;
  }
  connection_table_entry_info = policy_mgr_get_connection_table_entry_info(*(_QWORD *)(v15 + 8), a2, (__int64)&v88);
  if ( connection_table_entry_info )
  {
    v55 = connection_table_entry_info;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: can't find vdev_id %d in connection table",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "policy_mgr_incr_connection_count",
      a2);
    result = v55;
    goto LABEL_33;
  }
  if ( (int)a3 <= 1 )
  {
    if ( !a3 )
      goto LABEL_23;
    if ( a3 == 1 )
    {
      if ( (policy_mgr_is_vdev_ll_lt_sap(a1, (unsigned __int8)a2) & 1) != 0 )
        a3 = 6;
      else
        a3 = 1;
      goto LABEL_23;
    }
    goto LABEL_22;
  }
  if ( a3 - 2 >= 2 )
  {
    if ( a3 == 11 )
    {
      a3 = 4;
      goto LABEL_23;
    }
LABEL_22:
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Unsupported mode (%d)",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "policy_mgr_qdf_opmode_to_pm_con_mode",
      a3);
    a3 = 7;
  }
LABEL_23:
  v56 = HIDWORD(v89);
  if ( (unsigned int)policy_mgr_get_nss_for_vdev(a1, a3, v87, v86) )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Error in getting nss",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "policy_mgr_incr_connection_count");
    v73 = 0;
    v74 = 0;
  }
  else
  {
    v73 = wlan_reg_is_24ghz_ch_freq(v56) && v87[0] > 1u || wlan_reg_is_5ghz_ch_freq(v56) && v86[0] > 1u;
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v56);
    v76 = v86;
    if ( is_24ghz_ch_freq )
      v76 = v87;
    v74 = *v76;
  }
  bw = policy_mgr_get_bw(v90, v65, v66, v67, v68, v69, v70, v71, v72);
  policy_mgr_update_conc_list(a1, v26, a3, v56, bw, HIDWORD(v90), v73, v74, a2, 1, (a3 & 5) != 0, v91);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: Add at idx:%d vdev %d mac=%d",
    v78,
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    "policy_mgr_incr_connection_count",
    v26,
    a2,
    HIDWORD(v90));
  result = 0;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
