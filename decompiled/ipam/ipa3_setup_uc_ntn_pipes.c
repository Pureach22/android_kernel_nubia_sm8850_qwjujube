__int64 __fastcall ipa3_setup_uc_ntn_pipes(unsigned int *a1, __int64 a2, __int64 a3, unsigned __int8 a4, __int64 a5)
{
  unsigned int ep_mapping; // w19
  _DWORD *v10; // x22
  unsigned int v11; // w21
  _DWORD *v12; // x23
  _DWORD *v13; // x24
  unsigned int v14; // w9
  unsigned int v15; // w0
  int v16; // w0
  __int64 v17; // x27
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  int v21; // w8
  unsigned int v22; // w0
  int v23; // w0
  __int64 v24; // x19
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 result; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  unsigned int v43; // w21
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  int v47; // w21
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x8
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  int v60; // w23
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x0
  char v68[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v69; // [xsp+28h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68[0] = 0;
  if ( !a1 )
  {
    printk(&unk_3DB00B, "ipa3_setup_uc_ntn_pipes");
    v34 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_69;
    v35 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v35 )
    {
      ipc_log_string(v35, "ipa %s:%d invalid input\n", "ipa3_setup_uc_ntn_pipes", 448);
      v34 = ipa3_ctx;
    }
    v36 = *(_QWORD *)(v34 + 34160);
    if ( v36 )
    {
      ipc_log_string(v36, "ipa %s:%d invalid input\n", "ipa3_setup_uc_ntn_pipes", 448);
      result = 4294967274LL;
    }
    else
    {
LABEL_69:
      result = 4294967274LL;
    }
    goto LABEL_104;
  }
  ep_mapping = ipa_get_ep_mapping(*a1);
  if ( ep_mapping == -1 || ep_mapping >= (unsigned int)ipa3_get_max_num_pipes() )
  {
    printk(&unk_3AD654, "ipa3_setup_uc_ntn_pipes");
    v28 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_51;
    v29 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v29 )
    {
      ipc_log_string(
        v29,
        "ipa %s:%d fail to alloc UL EP ipa_ep_idx_ul=%d\n",
        "ipa3_setup_uc_ntn_pipes",
        456,
        ep_mapping);
      v28 = ipa3_ctx;
    }
    v30 = *(_QWORD *)(v28 + 34160);
    if ( !v30 )
      goto LABEL_51;
    ipc_log_string(v30, "ipa %s:%d fail to alloc UL EP ipa_ep_idx_ul=%d\n", "ipa3_setup_uc_ntn_pipes", 456, ep_mapping);
    goto LABEL_40;
  }
  v10 = a1 + 24;
  v11 = ipa_get_ep_mapping(a1[24]);
  if ( v11 == -1 || v11 >= (unsigned int)ipa3_get_max_num_pipes() )
  {
    printk(&unk_3A76B7, "ipa3_setup_uc_ntn_pipes");
    v31 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_51;
    v32 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v32 )
    {
      ipc_log_string(v32, "ipa %s:%d fail to alloc DL EP ipa_ep_idx_dl=%d\n", "ipa3_setup_uc_ntn_pipes", 464, v11);
      v31 = ipa3_ctx;
    }
    v33 = *(_QWORD *)(v31 + 34160);
    if ( !v33 )
      goto LABEL_51;
    ipc_log_string(v33, "ipa %s:%d fail to alloc DL EP ipa_ep_idx_dl=%d\n", "ipa3_setup_uc_ntn_pipes", 464, v11);
LABEL_40:
    result = 4294967282LL;
    goto LABEL_104;
  }
  if ( ep_mapping >= 0x25 || v11 > 0x24 )
    __break(0x5512u);
  v12 = (_DWORD *)(ipa3_ctx + 168 + 480LL * ep_mapping);
  v13 = (_DWORD *)(ipa3_ctx + 168 + 480LL * v11);
  if ( *v12 | *v13 )
  {
    printk(&unk_3D64F2, "ipa3_setup_uc_ntn_pipes");
    v37 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v38 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v38 )
      {
        ipc_log_string(v38, "ipa %s:%d EP already allocated ul:%d dl:%d\n", "ipa3_setup_uc_ntn_pipes", 473, *v12, *v13);
        v37 = ipa3_ctx;
      }
      v39 = *(_QWORD *)(v37 + 34160);
      if ( v39 )
      {
        ipc_log_string(v39, "ipa %s:%d EP already allocated ul:%d dl:%d\n", "ipa3_setup_uc_ntn_pipes", 473, *v12, *v13);
        result = 4294967282LL;
        goto LABEL_104;
      }
    }
LABEL_51:
    result = 4294967282LL;
    goto LABEL_104;
  }
  memset((void *)(ipa3_ctx + 168 + 480LL * ep_mapping), 0, 0x1D8u);
  memset(v13, 0, 0x1D8u);
  ipa3_inc_client_enable_clks();
  *v12 = 1;
  v14 = *a1;
  *((_QWORD *)v12 + 18) = 0;
  *((_QWORD *)v12 + 46) = a3;
  *((_QWORD *)v12 + 47) = a2;
  v12[1] = v14;
  *((_QWORD *)v12 + 19) = 0;
  *((_QWORD *)v12 + 20) = 0;
  *((_QWORD *)v12 + 21) = 0;
  *((_QWORD *)v12 + 22) = 0;
  *((_QWORD *)v12 + 23) = 0;
  *((_QWORD *)v12 + 24) = 0;
  *((_QWORD *)v12 + 25) = 0;
  *((_QWORD *)v12 + 26) = 0;
  *((_QWORD *)v12 + 27) = 0;
  *((_QWORD *)v12 + 28) = 0;
  *((_QWORD *)v12 + 29) = 0;
  *((_QWORD *)v12 + 30) = 0;
  *((_QWORD *)v12 + 31) = 0;
  *((_QWORD *)v12 + 32) = 0;
  *((_QWORD *)v12 + 33) = 0;
  *((_QWORD *)v12 + 34) = 0;
  *((_QWORD *)v12 + 35) = 0;
  *((_QWORD *)v12 + 36) = 0;
  *((_QWORD *)v12 + 37) = 0;
  *((_QWORD *)v12 + 38) = 0;
  *((_QWORD *)v12 + 39) = 0;
  *((_QWORD *)v12 + 40) = 0;
  *((_QWORD *)v12 + 41) = 0;
  v12[36] = 1;
  v12[39] = a4;
  ipa_is_vlan_mode(0, v68);
  if ( v68[0] == 1 )
  {
    v12[47] = 0;
    *((_QWORD *)v12 + 20) = 0xE00000001LL;
  }
  if ( (unsigned int)ipa3_cfg_ep(ep_mapping, v12 + 36) )
  {
    printk(&unk_3DBEF2, "ipa3_setup_uc_ntn_pipes");
    v40 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v41 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v41 )
      {
        ipc_log_string(v41, "ipa %s:%d fail to setup ul pipe cfg\n", "ipa3_setup_uc_ntn_pipes", 501);
        v40 = ipa3_ctx;
      }
      v42 = *(_QWORD *)(v40 + 34160);
      if ( v42 )
        ipc_log_string(v42, "ipa %s:%d fail to setup ul pipe cfg\n", "ipa3_setup_uc_ntn_pipes", 501);
      v43 = -14;
    }
    else
    {
      v43 = -14;
    }
    goto LABEL_103;
  }
  v15 = ipa3_smmu_map_uc_ntn_pipes(a1, 1);
  if ( v15 )
  {
    v43 = v15;
    printk(&unk_3C4AFA, "ipa3_setup_uc_ntn_pipes");
    v44 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v45 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v45 )
      {
        ipc_log_string(v45, "ipa %s:%d failed to map SMMU for UL %d\n", "ipa3_setup_uc_ntn_pipes", 508, v43);
        v44 = ipa3_ctx;
      }
      v46 = *(_QWORD *)(v44 + 34160);
      if ( v46 )
        ipc_log_string(v46, "ipa %s:%d failed to map SMMU for UL %d\n", "ipa3_setup_uc_ntn_pipes", 508, v43);
    }
    goto LABEL_103;
  }
  v16 = ipa3_enable_data_path(ep_mapping);
  if ( v16 )
  {
    v47 = v16;
    printk(&unk_3CA48F, "ipa3_setup_uc_ntn_pipes");
    v48 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v49 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v49 )
      {
        ipc_log_string(
          v49,
          "ipa %s:%d Enable data path failed res=%d pipe=%d.\n",
          "ipa3_setup_uc_ntn_pipes",
          515,
          v47,
          ep_mapping);
        v48 = ipa3_ctx;
      }
      v50 = *(_QWORD *)(v48 + 34160);
      if ( v50 )
        ipc_log_string(
          v50,
          "ipa %s:%d Enable data path failed res=%d pipe=%d.\n",
          "ipa3_setup_uc_ntn_pipes",
          515,
          v47,
          ep_mapping);
    }
    v43 = -14;
    goto LABEL_102;
  }
  if ( (unsigned int)ipa3_uc_send_ntn_setup_pipe_cmd(a1, 2) )
  {
    printk(&unk_3CA4C4, "ipa3_setup_uc_ntn_pipes");
    v51 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v52 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v52 )
      {
        ipc_log_string(v52, "ipa %s:%d fail to send cmd to uc for ul pipe\n", "ipa3_setup_uc_ntn_pipes", 521);
        v51 = ipa3_ctx;
      }
      v53 = *(_QWORD *)(v51 + 34160);
      if ( v53 )
      {
        ipc_log_string(v53, "ipa %s:%d fail to send cmd to uc for ul pipe\n", "ipa3_setup_uc_ntn_pipes", 521);
LABEL_80:
        v43 = -14;
LABEL_101:
        ipa3_disable_data_path(ep_mapping);
LABEL_102:
        ipa3_smmu_map_uc_ntn_pipes(a1, 0);
LABEL_103:
        ipa3_dec_client_disable_clks();
        result = v43;
        goto LABEL_104;
      }
LABEL_100:
      v43 = -14;
      goto LABEL_101;
    }
LABEL_98:
    v43 = -14;
    goto LABEL_101;
  }
  ipa3_install_dflt_flt_rules(ep_mapping);
  v17 = *(_QWORD *)(ipa3_ctx + 28632);
  *(_QWORD *)(a5 + 16) = v17
                       + (unsigned int)((__int64 (__fastcall *)(__int64, __int64, __int64))ipahal_get_reg_mn_ofst)(
                                         66,
                                         1,
                                         3);
  v12[112] |= 1u;
  v18 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v19 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v19 )
    {
      ipc_log_string(v19, "ipa %s:%d client %d (ep: %d) connected\n", "ipa3_setup_uc_ntn_pipes", 532, *a1, ep_mapping);
      v18 = ipa3_ctx;
    }
    v20 = *(_QWORD *)(v18 + 34160);
    if ( v20 )
      ipc_log_string(v20, "ipa %s:%d client %d (ep: %d) connected\n", "ipa3_setup_uc_ntn_pipes", 532, *a1, ep_mapping);
  }
  *v13 = 1;
  v21 = *v10;
  *((_QWORD *)v13 + 18) = 0;
  *((_QWORD *)v13 + 19) = 0;
  *((_QWORD *)v13 + 20) = 0;
  v13[1] = v21;
  *((_QWORD *)v13 + 21) = 0;
  *((_QWORD *)v13 + 22) = 0;
  *((_QWORD *)v13 + 23) = 0;
  *((_QWORD *)v13 + 24) = 0;
  *((_QWORD *)v13 + 25) = 0;
  *((_QWORD *)v13 + 26) = 0;
  *((_QWORD *)v13 + 27) = 0;
  *((_QWORD *)v13 + 28) = 0;
  *((_QWORD *)v13 + 29) = 0;
  *((_QWORD *)v13 + 30) = 0;
  *((_QWORD *)v13 + 31) = 0;
  *((_QWORD *)v13 + 32) = 0;
  *((_QWORD *)v13 + 33) = 0;
  *((_QWORD *)v13 + 34) = 0;
  *((_QWORD *)v13 + 35) = 0;
  *((_QWORD *)v13 + 36) = 0;
  *((_QWORD *)v13 + 37) = 0;
  *((_QWORD *)v13 + 38) = 0;
  *((_QWORD *)v13 + 39) = 0;
  *((_QWORD *)v13 + 40) = 0;
  *((_QWORD *)v13 + 41) = 0;
  v13[39] = a4;
  if ( (unsigned int)ipa3_cfg_ep(v11, v13 + 36) )
  {
    printk(&unk_3E6F01, "ipa3_setup_uc_ntn_pipes");
    v54 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v55 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v55 )
      {
        ipc_log_string(v55, "ipa %s:%d fail to setup dl pipe cfg\n", "ipa3_setup_uc_ntn_pipes", 543);
        v54 = ipa3_ctx;
      }
      v56 = *(_QWORD *)(v54 + 34160);
      if ( v56 )
      {
        ipc_log_string(v56, "ipa %s:%d fail to setup dl pipe cfg\n", "ipa3_setup_uc_ntn_pipes", 543);
        goto LABEL_80;
      }
      goto LABEL_100;
    }
    goto LABEL_98;
  }
  v22 = ipa3_smmu_map_uc_ntn_pipes(a1 + 24, 1);
  if ( v22 )
  {
    v43 = v22;
    printk(&unk_3A439A, "ipa3_setup_uc_ntn_pipes");
    v57 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v58 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v58 )
      {
        ipc_log_string(v58, "ipa %s:%d failed to map SMMU for DL %d\n", "ipa3_setup_uc_ntn_pipes", 550, v43);
        v57 = ipa3_ctx;
      }
      v59 = *(_QWORD *)(v57 + 34160);
      if ( v59 )
        ipc_log_string(v59, "ipa %s:%d failed to map SMMU for DL %d\n", "ipa3_setup_uc_ntn_pipes", 550, v43);
    }
    goto LABEL_101;
  }
  v23 = ipa3_enable_data_path(v11);
  if ( v23 )
  {
    v60 = v23;
    printk(&unk_3CA48F, "ipa3_setup_uc_ntn_pipes");
    v61 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v62 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v62 )
      {
        ipc_log_string(
          v62,
          "ipa %s:%d Enable data path failed res=%d pipe=%d.\n",
          "ipa3_setup_uc_ntn_pipes",
          557,
          v60,
          v11);
        v61 = ipa3_ctx;
      }
      v63 = *(_QWORD *)(v61 + 34160);
      if ( v63 )
        ipc_log_string(
          v63,
          "ipa %s:%d Enable data path failed res=%d pipe=%d.\n",
          "ipa3_setup_uc_ntn_pipes",
          557,
          v60,
          v11);
    }
    goto LABEL_97;
  }
  if ( (unsigned int)ipa3_uc_send_ntn_setup_pipe_cmd(a1 + 24, 1) )
  {
    printk(&unk_3ECC0C, "ipa3_setup_uc_ntn_pipes");
    v64 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v65 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v65 )
      {
        ipc_log_string(v65, "ipa %s:%d fail to send cmd to uc for dl pipe\n", "ipa3_setup_uc_ntn_pipes", 563);
        v64 = ipa3_ctx;
      }
      v66 = *(_QWORD *)(v64 + 34160);
      if ( v66 )
        ipc_log_string(v66, "ipa %s:%d fail to send cmd to uc for dl pipe\n", "ipa3_setup_uc_ntn_pipes", 563);
    }
    ipa3_disable_data_path(v11);
LABEL_97:
    ipa3_smmu_map_uc_ntn_pipes(a1 + 24, 0);
    v43 = -14;
    goto LABEL_101;
  }
  v24 = *(_QWORD *)(ipa3_ctx + 28632);
  *(_QWORD *)(a5 + 24) = v24
                       + (unsigned int)((__int64 (__fastcall *)(__int64, __int64, __int64))ipahal_get_reg_mn_ofst)(
                                         66,
                                         1,
                                         4);
  v13[112] |= 1u;
  ipa3_dec_client_disable_clks();
  v25 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_29:
    result = 0;
    goto LABEL_104;
  }
  v26 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v26 )
  {
    ipc_log_string(v26, "ipa %s:%d client %d (ep: %d) connected\n", "ipa3_setup_uc_ntn_pipes", 575, *v10, v11);
    v25 = ipa3_ctx;
  }
  result = *(_QWORD *)(v25 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d client %d (ep: %d) connected\n", "ipa3_setup_uc_ntn_pipes", 575, *v10, v11);
    goto LABEL_29;
  }
LABEL_104:
  _ReadStatusReg(SP_EL0);
  return result;
}
