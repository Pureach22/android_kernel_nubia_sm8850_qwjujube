__int64 ipa3_load_ipa_fw()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  int v3; // w0
  __int64 v4; // x8
  unsigned int v5; // w19
  const char *v6; // x20
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  int v11; // w0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  int fws; // w0
  int v16; // w19
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  int v20; // w0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 result; // x0
  int v27; // w19
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x1
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  const char *v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  int v45; // w19
  __int64 v46; // x8
  __int64 v47; // x0
  int v48; // w19
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  _QWORD v52[2]; // [xsp+0h] [xbp-10h] BYREF

  v52[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d Entry\n", "ipa3_load_ipa_fw", 8530);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d Entry\n", "ipa3_load_ipa_fw", 8530);
  }
  ipa3_inc_client_enable_clks_no_log();
  v3 = ipa3_attach_to_smmu();
  if ( v3 )
  {
    v27 = v3;
    printk(&unk_3BD56D, "ipa3_load_ipa_fw");
    v28 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v29 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v29 )
      {
        ipc_log_string(v29, "ipa %s:%d IPA attach to smmu failed %d\n", "ipa3_load_ipa_fw", 8536, v27);
        v28 = ipa3_ctx;
      }
      v30 = *(_QWORD *)(v28 + 34160);
      if ( v30 )
        ipc_log_string(v30, "ipa %s:%d IPA attach to smmu failed %d\n", "ipa3_load_ipa_fw", 8536, v27);
    }
    _ipa3_dec_client_disable_clks();
    goto LABEL_55;
  }
  v4 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 32248) == 3 )
  {
    v5 = *(_DWORD *)(ipa3_ctx + 32252);
    switch ( emulation_type )
    {
      case 17:
        v6 = "ipa/4.5/ipa_fws.elf";
        v52[0] = 0;
        if ( !ipa3_ctx )
          goto LABEL_28;
        goto LABEL_24;
      case 14:
        v6 = "ipa/4.0/ipa_fws.elf";
        v52[0] = 0;
        if ( !ipa3_ctx )
          goto LABEL_28;
        goto LABEL_24;
      case 13:
        v6 = "ipa/3.5.1/ipa_fws.elf";
        v52[0] = 0;
        if ( !ipa3_ctx )
          goto LABEL_28;
LABEL_24:
        v9 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v9 )
        {
          ipc_log_string(
            v9,
            "ipa %s:%d Manual FW loading (%s) process initiated\n",
            "ipa3_manual_load_ipa_fws",
            8363,
            v6);
          v4 = ipa3_ctx;
        }
        v10 = *(_QWORD *)(v4 + 34160);
        if ( v10 )
        {
          ipc_log_string(
            v10,
            "ipa %s:%d Manual FW loading (%s) process initiated\n",
            "ipa3_manual_load_ipa_fws",
            8363,
            v6);
          v4 = ipa3_ctx;
        }
        goto LABEL_28;
    }
  }
  else
  {
    if ( *(_DWORD *)(ipa3_ctx + 32256) || *(_DWORD *)(ipa3_ctx + 32240) >= 0xCu )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 48864);
      if ( v7 )
        LODWORD(v8) = ipa3_mdt_load_ipa_fws(v7);
      else
        LODWORD(v8) = ipa3_mdt_load_ipa_fws("ipa_fws");
      goto LABEL_49;
    }
    v5 = *(_DWORD *)(ipa3_ctx + 32252);
  }
  v6 = "ipa/ipa_fws.elf";
  v52[0] = 0;
  if ( ipa3_ctx )
    goto LABEL_24;
LABEL_28:
  v11 = request_firmware(v52, v6, *(_QWORD *)(v4 + 24));
  if ( v11 < 0 )
  {
    v16 = v11;
    printk(&unk_3EBDFC, "ipa3_manual_load_ipa_fws");
    v39 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v40 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v40 )
      {
        ipc_log_string(v40, "ipa %s:%d request_firmware failed, error %d\n", "ipa3_manual_load_ipa_fws", 8367, v16);
        v39 = ipa3_ctx;
      }
      v41 = *(_QWORD *)(v39 + 34160);
      if ( v41 )
      {
        ipc_log_string(v41, "ipa %s:%d request_firmware failed, error %d\n", "ipa3_manual_load_ipa_fws", 8367, v16);
        LODWORD(v8) = v16;
        goto LABEL_49;
      }
    }
    goto LABEL_92;
  }
  v12 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v13 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d FWs are available for loading\n", "ipa3_manual_load_ipa_fws", 8371);
      v12 = ipa3_ctx;
    }
    v14 = *(_QWORD *)(v12 + 34160);
    if ( v14 )
    {
      ipc_log_string(v14, "ipa %s:%d FWs are available for loading\n", "ipa3_manual_load_ipa_fws", 8371);
      v12 = ipa3_ctx;
    }
  }
  if ( *(_DWORD *)(v12 + 32248) == 3 )
  {
    fws = emulator_load_fws(v52[0], (unsigned int)dword_1F7DB4, (unsigned int)dword_1F7DB8, v5);
    if ( fws )
      goto LABEL_36;
  }
  else
  {
    fws = ipa3_load_fws(v52[0], (unsigned int)dword_1F7DB4, v5);
    if ( fws )
    {
LABEL_36:
      v16 = fws;
      printk(&unk_3BAAD1, "ipa3_manual_load_ipa_fws");
      v17 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v18 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v18 )
        {
          ipc_log_string(v18, "ipa %s:%d Manual IPA FWs loading has failed\n", "ipa3_manual_load_ipa_fws", 8384);
          v17 = ipa3_ctx;
        }
        v19 = *(_QWORD *)(v17 + 34160);
        if ( v19 )
          ipc_log_string(v19, "ipa %s:%d Manual IPA FWs loading has failed\n", "ipa3_manual_load_ipa_fws", 8384);
      }
LABEL_91:
      release_firmware(v52[0]);
LABEL_92:
      LODWORD(v8) = v16;
      goto LABEL_49;
    }
  }
  v20 = gsi_enable_fw((unsigned int)dword_1F7DB4, (unsigned int)dword_1F7DB8, v5);
  if ( v20 )
  {
    v16 = v20;
    printk(&unk_3B489D, "ipa3_manual_load_ipa_fws");
    v42 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v43 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v43 )
      {
        ipc_log_string(v43, "ipa %s:%d Failed to enable GSI FW\n", "ipa3_manual_load_ipa_fws", 8393);
        v42 = ipa3_ctx;
      }
      v44 = *(_QWORD *)(v42 + 34160);
      if ( v44 )
        ipc_log_string(v44, "ipa %s:%d Failed to enable GSI FW\n", "ipa3_manual_load_ipa_fws", 8393);
    }
    goto LABEL_91;
  }
  release_firmware(v52[0]);
  v21 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_48:
    LODWORD(v8) = 0;
    goto LABEL_49;
  }
  v22 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v22 )
  {
    ipc_log_string(v22, "ipa %s:%d Manual FW loading process is complete\n", "ipa3_manual_load_ipa_fws", 8400);
    v21 = ipa3_ctx;
  }
  v8 = *(_QWORD *)(v21 + 34160);
  if ( v8 )
  {
    ipc_log_string(v8, "ipa %s:%d Manual FW loading process is complete\n", "ipa3_manual_load_ipa_fws", 8400);
    goto LABEL_48;
  }
LABEL_49:
  if ( (_DWORD)v8 )
  {
    ++*(_DWORD *)(ipa3_ctx + 51392);
    _ipa3_dec_client_disable_clks();
    v23 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_56;
    v24 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v24 )
    {
      ipc_log_string(v24, "ipa %s:%d IPA firmware loading deffered to a work queue\n", "ipa3_load_ipa_fw", 8573);
      v23 = ipa3_ctx;
    }
    v25 = *(_QWORD *)(v23 + 34160);
    if ( !v25 )
      goto LABEL_56;
    ipc_log_string(v25, "ipa %s:%d IPA firmware loading deffered to a work queue\n", "ipa3_load_ipa_fw", 8573);
LABEL_55:
    v23 = ipa3_ctx;
LABEL_56:
    result = queue_delayed_work_on(32, *(_QWORD *)(v23 + 31952), &ipa3_fw_load_failure_handle, 125);
    goto LABEL_57;
  }
  _ipa3_dec_client_disable_clks();
  mutex_lock(ipa3_ctx + 45152);
  v31 = ipa3_ctx + 45152;
  *(_DWORD *)(ipa3_ctx + 45144) = 4;
  mutex_unlock(v31);
  printk(&unk_3C062B, v32);
  result = ipa3_post_init();
  if ( (_DWORD)result )
  {
    v45 = result;
    result = printk(&unk_3B77E6, "ipa3_load_ipa_fw");
    v46 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v47 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v47 )
      {
        ipc_log_string(v47, "ipa %s:%d IPA post init failed %d\n", "ipa3_load_ipa_fw", 8587, v45);
        v46 = ipa3_ctx;
      }
      result = *(_QWORD *)(v46 + 34160);
      if ( result )
        result = ipc_log_string(result, "ipa %s:%d IPA post init failed %d\n", "ipa3_load_ipa_fw", 8587, v45);
    }
  }
  else
  {
    v33 = ipa3_ctx;
    if ( *(_DWORD *)(ipa3_ctx + 32256) == 2 && (*(_DWORD *)(ipa3_ctx + 32248) | 2) != 3 )
    {
      if ( ipa3_ctx )
      {
        v34 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v34 )
        {
          ipc_log_string(v34, "ipa %s:%d Loading IPA uC via PIL\n", "ipa3_load_ipa_fw", 8595);
          v33 = ipa3_ctx;
        }
        v35 = *(_QWORD *)(v33 + 34160);
        if ( v35 )
          ipc_log_string(v35, "ipa %s:%d Loading IPA uC via PIL\n", "ipa3_load_ipa_fw", 8595);
      }
      ipa3_proxy_clk_vote(0);
      if ( *(_QWORD *)(ipa3_ctx + 48872) )
        v36 = *(const char **)(ipa3_ctx + 48872);
      else
        v36 = "ipa_uc";
      result = ipa3_mdt_load_ipa_fws(v36);
      if ( (_DWORD)result )
      {
        v48 = result;
        v49 = printk(&unk_3A639E, "ipa3_load_ipa_fw");
        v50 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v51 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v51 )
          {
            ipc_log_string(
              v51,
              "ipa %s:%d IPA uC loading process has failed result=%d\n",
              "ipa3_load_ipa_fw",
              8615,
              v48);
            v50 = ipa3_ctx;
          }
          v49 = *(_QWORD *)(v50 + 34160);
          if ( v49 )
            v49 = ipc_log_string(
                    v49,
                    "ipa %s:%d IPA uC loading process has failed result=%d\n",
                    "ipa3_load_ipa_fw",
                    8615,
                    v48);
        }
        result = ipa3_proxy_clk_unvote(v49);
      }
      else
      {
        v37 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v38 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v38 )
          {
            ipc_log_string(v38, "ipa %s:%d IPA uC loading succeeded\n", "ipa3_load_ipa_fw", 8619);
            v37 = ipa3_ctx;
          }
          result = *(_QWORD *)(v37 + 34160);
          if ( result )
            result = ipc_log_string(result, "ipa %s:%d IPA uC loading succeeded\n", "ipa3_load_ipa_fw", 8619);
        }
      }
    }
  }
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return result;
}
