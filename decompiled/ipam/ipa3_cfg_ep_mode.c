__int64 __fastcall ipa3_cfg_ep_mode(unsigned int a1, unsigned int *a2)
{
  unsigned int v4; // w23
  __int64 v5; // x8
  int v6; // w4
  __int64 v7; // x8
  int v8; // t1
  unsigned int v9; // w8
  int ep_mapping; // w0
  unsigned int v11; // w7
  unsigned int v12; // w8
  int v13; // w21
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x5
  const char *v17; // x6
  _BYTE *v18; // x10
  unsigned int v19; // w10
  unsigned int v20; // w11
  __int64 v21; // x0
  __int64 v22; // x5
  const char *v23; // x6
  __int64 v24; // x24
  int v25; // w8
  __int64 v26; // x8
  unsigned int v27; // w20
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 result; // x0
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
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  _QWORD v52[3]; // [xsp+18h] [xbp-18h] BYREF

  v52[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v52, 0, 12);
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    if ( a1 > 0x23 )
      goto LABEL_100;
    v4 = a1;
    goto LABEL_60;
  }
  if ( a1 >= 0x24 )
    goto LABEL_100;
  v4 = a1;
  v5 = ipa3_ctx + 480LL * a1;
  v8 = *(_DWORD *)(v5 + 168);
  v7 = v5 + 168;
  v6 = v8;
  if ( !a2 || !v6 )
  {
LABEL_60:
    printk(&unk_3AA881, "ipa3_cfg_ep_mode");
    v31 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v32 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v32 )
      {
        ipc_log_string(
          v32,
          "ipa %s:%d bad params clnt_hdl=%d , ep_valid=%d ep_mode=%pK\n",
          "ipa3_cfg_ep_mode",
          9421,
          a1,
          *(_DWORD *)(ipa3_ctx + 480LL * v4 + 168),
          a2);
        v31 = ipa3_ctx;
      }
      v33 = *(_QWORD *)(v31 + 34160);
      if ( v33 )
      {
        ipc_log_string(
          v33,
          "ipa %s:%d bad params clnt_hdl=%d , ep_valid=%d ep_mode=%pK\n",
          "ipa3_cfg_ep_mode",
          9421,
          a1,
          *(_DWORD *)(v31 + 480LL * v4 + 168),
          a2);
        result = 4294967274LL;
        goto LABEL_55;
      }
    }
    goto LABEL_99;
  }
  v9 = *(_DWORD *)(v7 + 4);
  if ( v9 <= 0x85 && (v9 & 1) != 0 )
  {
    printk(&unk_3B5BCA, "ipa3_cfg_ep_mode");
    v34 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v35 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v35 )
      {
        ipc_log_string(v35, "ipa %s:%d MODE does not apply to IPA out EP %d\n", "ipa3_cfg_ep_mode", 9426, a1);
        v34 = ipa3_ctx;
      }
      v36 = *(_QWORD *)(v34 + 34160);
      if ( v36 )
        ipc_log_string(v36, "ipa %s:%d MODE does not apply to IPA out EP %d\n", "ipa3_cfg_ep_mode", 9426, a1);
    }
    goto LABEL_99;
  }
  ep_mapping = ipa_get_ep_mapping(a2[1]);
  v12 = *a2;
  v11 = a2[1];
  v13 = ep_mapping;
  if ( ep_mapping == -1 )
  {
    if ( v12 != 3 )
      goto LABEL_13;
    printk(&unk_3A4649, "ipa3_cfg_ep_mode");
    v49 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v50 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v50 )
      {
        ipc_log_string(v50, "ipa %s:%d dst %d does not exist in DMA mode\n", "ipa3_cfg_ep_mode", 9432, a2[1]);
        v49 = ipa3_ctx;
      }
      v51 = *(_QWORD *)(v49 + 34160);
      if ( v51 )
        ipc_log_string(v51, "ipa %s:%d dst %d does not exist in DMA mode\n", "ipa3_cfg_ep_mode", 9432, a2[1]);
    }
LABEL_99:
    result = 4294967274LL;
    goto LABEL_55;
  }
  if ( v12 == 3 && v11 <= 0x85 && (v11 & 1) == 0 )
  {
    __break(0x800u);
    v11 = a2[1];
  }
LABEL_13:
  v14 = ipa3_ctx;
  if ( v11 <= 0x85 && (v11 & 1) != 0 )
  {
    if ( !ipa3_ctx )
      goto LABEL_39;
    goto LABEL_16;
  }
  if ( *(unsigned __int8 *)(ipa3_ctx + 32244) >= 0x18uLL )
LABEL_100:
    __break(0x5512u);
  v18 = &ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244)];
  if ( v18[1716] == 1 )
  {
    v19 = *((_DWORD *)v18 + 434);
    if ( (v19 & 0x80000000) != 0 )
    {
      v13 = -1;
      if ( !ipa3_ctx )
        goto LABEL_39;
    }
    else
    {
      if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u )
        v20 = 31;
      else
        v20 = 36;
      if ( v19 >= v20 )
        v13 = -1;
      else
        v13 = v19;
      if ( !ipa3_ctx )
        goto LABEL_39;
    }
  }
  else
  {
    v13 = -1;
    if ( !ipa3_ctx )
      goto LABEL_39;
  }
LABEL_16:
  v15 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v15 )
  {
    v16 = *a2;
    if ( (unsigned int)v16 > 3 )
      v17 = "undefined";
    else
      v17 = off_1E4150[v16];
    ipc_log_string(
      v15,
      "ipa %s:%d pipe=%d mode=%d(%s), dst_client_number=%d\n",
      "ipa3_cfg_ep_mode",
      9445,
      a1,
      v16,
      v17,
      v11);
    v14 = ipa3_ctx;
  }
  v21 = *(_QWORD *)(v14 + 34160);
  if ( v21 )
  {
    v22 = *a2;
    if ( (unsigned int)v22 > 3 )
      v23 = "undefined";
    else
      v23 = off_1E4150[v22];
    ipc_log_string(
      v21,
      "ipa %s:%d pipe=%d mode=%d(%s), dst_client_number=%d\n",
      "ipa3_cfg_ep_mode",
      9445,
      a1,
      v22,
      v23,
      a2[1]);
    v14 = ipa3_ctx;
  }
LABEL_39:
  v24 = 480LL * a1;
  *(_QWORD *)(v14 + v24 + 400) = *(_QWORD *)a2;
  *(_DWORD *)(ipa3_ctx + v24 + 524) = v13;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v37 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v38 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v38 )
      {
        ipc_log_string(v38, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v37 = ipa3_ctx;
      }
      v39 = *(_QWORD *)(v37 + 34160);
      if ( v39 )
        ipc_log_string(v39, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v40 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v41 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v41 )
        {
          ipc_log_string(v41, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v40 = ipa3_ctx;
        }
        v42 = *(_QWORD *)(v40 + 34160);
        if ( v42 )
          ipc_log_string(v42, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
    }
  }
  ipa3_inc_client_enable_clks();
  v25 = *(_DWORD *)(ipa3_ctx + v24 + 524);
  *(_QWORD *)((char *)v52 + 4) = *(_QWORD *)a2;
  LODWORD(v52[0]) = v25;
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(46, a1, v52);
  v26 = ipa3_ctx;
  if ( (unsigned int)(*(_DWORD *)(ipa3_ctx + v24 + 172) - 62) > 9 )
    goto LABEL_53;
  if ( *a2 != 3 )
  {
    if ( *(_DWORD *)(ipa3_ctx + 32240) == 16 )
      v27 = 6;
    else
      v27 = 4;
    if ( !ipa3_ctx )
      goto LABEL_52;
LABEL_48:
    v28 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v28 )
    {
      ipc_log_string(v28, "ipa %s:%d  set sequencers to sequance 0x%x, ep = %d\n", "ipa3_cfg_ep_mode", 9471, v27, a1);
      v26 = ipa3_ctx;
    }
    v29 = *(_QWORD *)(v26 + 34160);
    if ( v29 )
      ipc_log_string(v29, "ipa %s:%d  set sequencers to sequance 0x%x, ep = %d\n", "ipa3_cfg_ep_mode", 9471, v27, a1);
    goto LABEL_52;
  }
  v27 = 0;
  if ( ipa3_ctx )
    goto LABEL_48;
LABEL_52:
  ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(55, 0, a1, v27);
  v26 = ipa3_ctx;
LABEL_53:
  if ( *(_DWORD *)(v26 + 34308) <= a1 )
  {
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v43 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v44 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v44 )
      {
        ipc_log_string(v44, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v43 = ipa3_ctx;
      }
      v45 = *(_QWORD *)(v43 + 34160);
      if ( v45 )
        ipc_log_string(v45, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v46 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v47 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v47 )
        {
          ipc_log_string(v47, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v46 = ipa3_ctx;
        }
        v48 = *(_QWORD *)(v46 + 34160);
        if ( v48 )
          ipc_log_string(v48, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
    }
  }
  ipa3_dec_client_disable_clks();
  result = 0;
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
