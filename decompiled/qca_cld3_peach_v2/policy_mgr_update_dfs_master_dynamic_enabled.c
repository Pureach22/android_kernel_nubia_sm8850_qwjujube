__int64 __fastcall policy_mgr_update_dfs_master_dynamic_enabled(__int64 a1, char a2, unsigned __int16 *a3)
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
  __int64 v15; // x4
  __int64 v16; // x23
  int v17; // w19
  int v18; // w22
  __int64 v19; // x5
  __int64 v20; // x6
  unsigned int v21; // w21
  unsigned __int16 v22; // w9
  unsigned __int64 v23; // x19
  __int64 v24; // x22
  int *v25; // x25
  int v26; // w8
  char is_hw_dbs_capable; // w22
  unsigned __int64 v28; // x20
  __int64 v29; // x25
  unsigned int v30; // w26
  unsigned int v31; // w27
  int v32; // w28
  int v33; // w24
  __int64 v34; // x22
  char v35; // w8
  char v37; // [xsp+Ch] [xbp-84h]
  char v38; // [xsp+18h] [xbp-78h]
  char v39; // [xsp+1Ch] [xbp-74h]
  __int64 v40; // [xsp+20h] [xbp-70h]
  unsigned __int64 v41; // [xsp+28h] [xbp-68h]
  _QWORD v42[2]; // [xsp+30h] [xbp-60h]
  int v43; // [xsp+40h] [xbp-50h]
  _QWORD v44[5]; // [xsp+48h] [xbp-48h] BYREF
  _QWORD v45[2]; // [xsp+70h] [xbp-20h]
  int v46; // [xsp+80h] [xbp-10h]
  __int64 v47; // [xsp+88h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: pm_ctx is NULL",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_update_dfs_master_dynamic_enabled");
    v21 = 1;
    goto LABEL_55;
  }
  v15 = *(unsigned __int8 *)(context + 2212);
  v16 = context;
  if ( !*(_BYTE *)(context + 2212) )
  {
LABEL_11:
    v17 = *(unsigned __int8 *)(v16 + 2661);
    v18 = 0;
    *(_BYTE *)(v16 + 2661) = 0;
    v21 = 1;
    goto LABEL_52;
  }
  if ( (_DWORD)v15 != 2 )
  {
    if ( (_DWORD)v15 == 1 )
    {
      v17 = *(unsigned __int8 *)(context + 2661);
      v18 = 0;
      v19 = 0;
      v20 = 0;
      *(_BYTE *)(context + 2661) = 1;
      goto LABEL_51;
    }
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: sta_sap_scc_on_dfs_chnl %d unknown",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_update_dfs_master_dynamic_enabled");
    goto LABEL_11;
  }
  memset(v44, 0, sizeof(v44));
  v42[0] = 0;
  v42[1] = 0;
  v43 = 0;
  v37 = a2;
  if ( a3 && wlan_reg_is_5ghz_ch_freq(*a3) )
  {
    v22 = a3[3];
    v23 = 1;
    LODWORD(v44[0]) = *a3;
    LOWORD(v42[0]) = v22;
  }
  else
  {
    v23 = 0;
  }
  v46 = 0;
  v45[0] = 0;
  v45[1] = 0;
  qdf_mutex_acquire(v16 + 56);
  v24 = 0;
  v40 = 0;
  v41 = 0;
  v39 = 0;
  do
  {
    v25 = (int *)((char *)&pm_conc_connection_list + v24);
    if ( *((_BYTE *)&pm_conc_connection_list + v24 + 28) != 1 )
      goto LABEL_15;
    v26 = *v25;
    if ( (*v25 | 2) == 3 )
    {
      if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)((char *)&pm_conc_connection_list + v24 + 4)) )
      {
        if ( v23 > 9 )
          goto LABEL_56;
        *((_DWORD *)v44 + v23) = *(_DWORD *)((char *)&pm_conc_connection_list + v24 + 4);
        *((_WORD *)v42 + v23++) = *(_WORD *)((char *)&pm_conc_connection_list + v24 + 30);
        HIDWORD(v40) = 1;
        goto LABEL_15;
      }
      v26 = *v25;
    }
    if ( (v26 | 2) == 2 )
    {
      if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)((char *)&pm_conc_connection_list + v24 + 4)) )
      {
        if ( v41 > 4 )
          goto LABEL_56;
        *((_DWORD *)v45 + v41) = *(_DWORD *)((char *)&pm_conc_connection_list + v24 + 4);
        v39 = 1;
        ++v41;
      }
      else
      {
        LOBYTE(v40) = 1;
      }
    }
LABEL_15:
    v24 += 36;
  }
  while ( v24 != 180 );
  qdf_mutex_release(v16 + 56);
  is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(a1);
  if ( (policy_mgr_is_hw_sbs_capable(a1) & 1) == 0 )
  {
    v35 = (v39 | (is_hw_dbs_capable ^ 1) & v40) ^ 1;
LABEL_47:
    v18 = HIDWORD(v40);
    v38 = v35;
    goto LABEL_48;
  }
  if ( !v41 )
  {
    v35 = 1;
    goto LABEL_47;
  }
  v18 = HIDWORD(v40);
  v28 = 0;
  v38 = 1;
  while ( 2 )
  {
    if ( !v23 )
      goto LABEL_30;
    if ( v28 > 4 )
    {
LABEL_56:
      __break(0x5512u);
      __break(1u);
    }
    v29 = 0;
    v30 = *((_DWORD *)v45 + v28);
    while ( 2 )
    {
      if ( v29 == 10 )
        goto LABEL_56;
      v31 = *((_DWORD *)v44 + v29);
      v32 = policy_mgr_2_freq_same_mac_in_dbs(a1, v30, v31);
      if ( (v32 & 1) != 0 )
        v33 = policy_mgr_2_freq_same_mac_in_sbs(a1, v30, v31);
      else
        v33 = 1;
      v34 = jiffies;
      if ( policy_mgr_2_freq_always_on_same_mac___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: freq1 %d freq2 %d: Same mac:: DBS:%d SBS:%d",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "policy_mgr_2_freq_always_on_same_mac",
          v30,
          v31,
          v32 & 1,
          v33 & 1);
        policy_mgr_2_freq_always_on_same_mac___last_ticks = v34;
        if ( (v32 & v33 & 1) != 0 )
          goto LABEL_43;
        goto LABEL_34;
      }
      if ( (v32 & v33 & 1) == 0 )
        goto LABEL_34;
LABEL_43:
      if ( (*((_WORD *)v42 + v29) & 6) == 0 )
      {
LABEL_34:
        if ( v23 == ++v29 )
          goto LABEL_29;
        continue;
      }
      break;
    }
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: sta %d ap(dfs) %d on same mac",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_update_dfs_master_dynamic_enabled",
      v30,
      v31);
    v38 = 0;
LABEL_29:
    v18 = HIDWORD(v40);
LABEL_30:
    if ( ++v28 != v41 )
      continue;
    break;
  }
LABEL_48:
  v21 = 1;
  v17 = *(unsigned __int8 *)(v16 + 2661);
  *(_BYTE *)(v16 + 2661) = (v38 & 1) == 0;
  if ( (v38 & 1) != 0 )
  {
    a2 = v37;
    goto LABEL_52;
  }
  v15 = *(unsigned __int8 *)(v16 + 2212);
  a2 = v37;
  v19 = v40 & 1;
  v20 = v39 & 1;
LABEL_51:
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: sta_sap_scc_on_dfs_chnl %d sta_on_2g %d sta_on_5g %d enable %d curr %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "policy_mgr_update_dfs_master_dynamic_enabled",
    v15,
    v19,
    v20,
    0,
    (v17 & 1) == 0);
  v21 = 0;
LABEL_52:
  if ( (v18 & ~(v17 ^ v21) & 1) != 0 || (a2 & 1) != 0 )
    tgt_dfs_radar_enable(*(_QWORD *)(v16 + 8), 0, 0, v21);
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return v21;
}
