__int64 __fastcall policy_mgr_get_alternate_channel_for_sap(__int64 a1, unsigned int a2, unsigned int a3, int a4)
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
  __int64 v17; // x22
  unsigned int v18; // w25
  bool ap_6ghz_capable; // w24
  int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w25
  unsigned int v30; // w27
  unsigned int v31; // w23
  __int64 v32; // x28
  int v33; // w0
  unsigned int v34; // w0
  int v35; // w9
  int v36; // w8
  int v37; // w10
  int v38; // w11
  int v39; // w8
  int v40; // w9
  unsigned __int8 v41; // w2
  unsigned int v43; // [xsp+Ch] [xbp-244h]
  int v44; // [xsp+10h] [xbp-240h]
  unsigned __int8 v45[4]; // [xsp+14h] [xbp-23Ch] BYREF
  _QWORD v46[4]; // [xsp+18h] [xbp-238h] BYREF
  __int64 v47; // [xsp+38h] [xbp-218h] BYREF
  _QWORD v48[11]; // [xsp+40h] [xbp-210h] BYREF
  _QWORD v49[2]; // [xsp+98h] [xbp-1B8h]
  _DWORD s[102]; // [xsp+A8h] [xbp-1A8h] BYREF
  __int64 v51; // [xsp+240h] [xbp-10h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  *(_QWORD *)((char *)v49 + 6) = 0;
  v49[0] = 0;
  v47 = 0;
  memset(v48, 0, sizeof(v48));
  memset(v46, 0, sizeof(v46));
  v45[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "policy_mgr_get_alternate_channel_for_sap");
    v31 = 0;
    goto LABEL_50;
  }
  v17 = context;
  v44 = a4;
  v18 = policy_mgr_con_mode_by_vdev_id(a1, a2);
  ap_6ghz_capable = policy_mgr_get_ap_6ghz_capable(a1, a2, nullptr);
  qdf_mutex_acquire(v17 + 56);
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
    a1,
    (unsigned __int8)a2,
    v46,
    v45);
  v20 = ((__int64 (__fastcall *)(__int64, _QWORD, _DWORD *, char *, _QWORD *, __int64, _QWORD))policy_mgr_get_pcl)(
          a1,
          v18,
          s,
          (char *)&v47 + 4,
          v48,
          102,
          a2);
  v29 = 0;
  if ( v20 )
  {
    v43 = 0;
    v30 = 0;
    v31 = 0;
LABEL_40:
    v41 = v45[0];
    if ( !v45[0] )
      goto LABEL_42;
    goto LABEL_41;
  }
  v30 = 0;
  v31 = 0;
  v43 = 0;
  if ( !HIDWORD(v47) )
    goto LABEL_40;
  v32 = 0;
  v31 = 0;
  v30 = 0;
  v29 = 0;
  v43 = 0;
  while ( 1 )
  {
    if ( v32 == 102 )
    {
      __break(0x5512u);
      __break(1u);
    }
    v33 = s[v32];
    if ( v33 == a3
      || !ap_6ghz_capable && wlan_reg_is_6ghz_chan_freq(v33)
      || (unsigned int)policy_mgr_get_connection_count(a1)
      && (policy_mgr_are_2_freq_on_same_mac(a1, a3, s[v32]) & 1) != 0 )
    {
      goto LABEL_7;
    }
    v34 = s[v32];
    v35 = BYTE4(qword_8D4F00);
    v36 = BYTE4(qword_8D4F24);
    if ( HIDWORD(pm_conc_connection_list) != v34 )
      v35 = 0;
    v37 = BYTE4(qword_8D4F48);
    if ( HIDWORD(qword_8D4F0C) != v34 )
      v36 = 0;
    v38 = BYTE4(qword_8D4F6C);
    if ( HIDWORD(qword_8D4F30) != v34 )
      v37 = 0;
    if ( HIDWORD(qword_8D4F54) != v34 )
      v38 = 0;
    v39 = v36 + v35 + v37 + v38;
    v40 = HIDWORD(qword_8D4F78) == v34 ? BYTE4(qword_8D4F90) : 0;
    if ( v39 | v40 )
      break;
    if ( !v29 )
      v29 = s[v32];
    if ( !v30 )
    {
      if ( !wlan_reg_is_5ghz_ch_freq(v34) )
        goto LABEL_33;
      if ( (wlan_reg_is_dfs_in_secondary_list_for_freq(
              *(_QWORD *)(v17 + 8),
              s[v32],
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28)
          & 1) != 0 )
      {
        if ( !v43 )
          v43 = s[v32];
LABEL_33:
        v30 = 0;
        goto LABEL_35;
      }
      v30 = s[v32];
      if ( v44 == 1 )
        goto LABEL_40;
    }
LABEL_35:
    if ( !v31 )
    {
      if ( wlan_reg_is_6ghz_chan_freq(s[v32]) )
      {
        v31 = s[v32];
        if ( v44 == 2 )
          goto LABEL_40;
      }
      else
      {
        v31 = 0;
      }
    }
LABEL_7:
    if ( HIDWORD(v47) <= (unsigned int)++v32 )
      goto LABEL_40;
  }
  v29 = s[v32];
  v41 = v45[0];
  if ( v45[0] )
LABEL_41:
    policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)v46, v41, v21, v22, v23, v24, v25, v26, v27, v28);
LABEL_42:
  qdf_mutex_release(v17 + 56);
  if ( v44 == 1 )
  {
LABEL_45:
    v31 = v30;
    if ( !v30 )
    {
      if ( v43 )
        v31 = v43;
      else
        v31 = v29;
    }
  }
  else if ( v44 == 2 )
  {
    if ( !v31 )
      goto LABEL_45;
  }
  else
  {
    v31 = v29;
  }
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return v31;
}
