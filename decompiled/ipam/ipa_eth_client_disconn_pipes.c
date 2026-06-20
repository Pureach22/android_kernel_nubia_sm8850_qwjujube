__int64 __fastcall ipa_eth_client_disconn_pipes(_DWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 *v5; // x19
  __int64 v6; // x20
  __int64 v7; // x0
  unsigned int v8; // w0
  __int64 v9; // x23
  __int64 ipa_client_type_from_pipe; // x0
  int ep_mapping; // w0
  __int64 v12; // x23
  __int64 v13; // x0
  int v14; // w0
  __int64 v15; // x0
  unsigned int v16; // w27
  unsigned __int8 v17; // w0
  __int64 v18; // x8
  __int64 v19; // x27
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  unsigned int v30; // w19
  unsigned __int64 v31; // x20
  __int64 v32; // x8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 result; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  unsigned int v53; // w10
  __int64 v54; // [xsp+8h] [xbp-18h] BYREF
  __int64 v55; // [xsp+10h] [xbp-10h]
  __int64 v56; // [xsp+18h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = 0;
  v55 = 0;
  if ( !a1 )
  {
    printk(&unk_3BC79A, "ipa_eth_client_disconn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_eth %s:%d null client", "ipa_eth_client_disconn_pipes", 719);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_86;
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_eth %s:%d null client", "ipa_eth_client_disconn_pipes", 719);
    goto LABEL_68;
  }
  if ( !ipa_eth_ctx )
  {
    printk(&unk_3AB226, "ipa_eth_client_disconn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v35 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v35,
        "ipa_eth %s:%d disconn called before register readiness\n",
        "ipa_eth_client_disconn_pipes",
        724);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_86;
    v36 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v36, "ipa_eth %s:%d disconn called before register readiness\n", "ipa_eth_client_disconn_pipes", 724);
    goto LABEL_68;
  }
  if ( (*(_BYTE *)(ipa_eth_ctx + 248) & 1) == 0 )
  {
    printk(&unk_3C249D, "ipa_eth_client_disconn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v37 = ipa3_get_ipc_logbuf();
      ipc_log_string(v37, "ipa_eth %s:%d disconn called before IPA eth ready\n", "ipa_eth_client_disconn_pipes", 729);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_86;
    v38 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v38, "ipa_eth %s:%d disconn called before IPA eth ready\n", "ipa_eth_client_disconn_pipes", 729);
LABEL_68:
    result = 4294967282LL;
    goto LABEL_55;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v2 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v2,
      "ipa_eth %s:%d ipa_eth disconn client %d inst %d, traffic %d\n",
      "ipa_eth_client_disconn_pipes",
      734,
      *a1,
      *((unsigned __int8 *)a1 + 4),
      a1[2]);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v3 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v3,
      "ipa_eth %s:%d ipa_eth disconn client %d inst %d, traffic %d\n",
      "ipa_eth_client_disconn_pipes",
      734,
      *a1,
      *((unsigned __int8 *)a1 + 4),
      a1[2]);
  }
  mutex_lock(ipa_eth_ctx + 192);
  v5 = (__int64 *)(a1 + 4);
  v6 = *((_QWORD *)a1 + 2);
  if ( (_DWORD *)v6 != a1 + 4 )
  {
    do
    {
      _X8 = (unsigned int *)*(unsigned int *)(v6 + 16);
      if ( !(_DWORD)_X8 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v9 = ipa3_get_ipc_logbuf();
          ipa_client_type_from_pipe = ipa_eth_get_ipa_client_type_from_pipe(v6);
          ep_mapping = ipa_get_ep_mapping(ipa_client_type_from_pipe);
          ipc_log_string(
            v9,
            "ipa_eth %s:%d Set holb on pipe = %d, pipe->dir = %d \n",
            "ipa_eth_client_disconn_pipes",
            744,
            ep_mapping,
            *(_DWORD *)(v6 + 16));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v12 = ipa3_get_ipc_logbuf_low();
          v13 = ipa_eth_get_ipa_client_type_from_pipe(v6);
          v14 = ipa_get_ep_mapping(v13);
          ipc_log_string(
            v12,
            "ipa_eth %s:%d Set holb on pipe = %d, pipe->dir = %d \n",
            "ipa_eth_client_disconn_pipes",
            744,
            v14,
            *(_DWORD *)(v6 + 16));
        }
        WORD2(v55) = 1;
        LODWORD(v54) = 0;
        v7 = ipa_eth_get_ipa_client_type_from_pipe(v6);
        v8 = ipa_get_ep_mapping(v7);
        ipa3_cfg_ep_holb(v8, &v54);
      }
      v6 = *(_QWORD *)v6;
    }
    while ( (__int64 *)v6 != v5 );
    v6 = *v5;
  }
  if ( (__int64 *)v6 != v5 )
  {
    while ( 1 )
    {
      if ( !v6 )
      {
        printk(&unk_3D9A89, "ipa_eth_client_disconnect_pipe");
        if ( ipa3_get_ipc_logbuf() )
        {
          v20 = ipa3_get_ipc_logbuf();
          ipc_log_string(v20, "ipa_eth %s:%d invalid pipe\n", "ipa_eth_client_disconnect_pipe", 495);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v21 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v21, "ipa_eth %s:%d invalid pipe\n", "ipa_eth_client_disconnect_pipe", 495);
        }
        goto LABEL_44;
      }
      if ( !*(_QWORD *)(v6 + 160) )
      {
        printk(&unk_3B9679, "ipa_eth_client_disconnect_pipe");
        if ( ipa3_get_ipc_logbuf() )
        {
          v22 = ipa3_get_ipc_logbuf();
          ipc_log_string(v22, "ipa_eth %s:%d invalid client\n", "ipa_eth_client_disconnect_pipe", 501);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v23 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v23, "ipa_eth %s:%d invalid client\n", "ipa_eth_client_disconnect_pipe", 501);
        }
        goto LABEL_44;
      }
      v15 = ipa_eth_get_ipa_client_type_from_pipe(v6);
      if ( (_DWORD)v15 == 134 )
        break;
      v16 = v15;
      if ( (pipe_connected[(unsigned __int8)client_to_pipe_index(v15)] & 1) == 0 )
      {
        printk(&unk_3DF894, "ipa_eth_client_disconnect_pipe");
        if ( ipa3_get_ipc_logbuf() )
        {
          v26 = ipa3_get_ipc_logbuf();
          ipc_log_string(v26, "ipa_eth %s:%d client not connected\n", "ipa_eth_client_disconnect_pipe", 512);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v27 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v27, "ipa_eth %s:%d client not connected\n", "ipa_eth_client_disconnect_pipe", 512);
        }
LABEL_44:
        printk(&unk_3F3A86, "ipa_eth_client_disconn_pipes");
        if ( ipa3_get_ipc_logbuf() )
        {
          v28 = ipa3_get_ipc_logbuf();
          ipc_log_string(v28, "ipa_eth %s:%d pipe connect fails\n", "ipa_eth_client_disconn_pipes", 756);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v29 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v29, "ipa_eth %s:%d pipe connect fails\n", "ipa_eth_client_disconn_pipes", 756);
        }
        ((void (*)(void))ipa_assert)();
        goto LABEL_21;
      }
      if ( (unsigned int)ipa3_eth_disconnect(v6, v16) )
        goto LABEL_44;
      v17 = client_to_pipe_index(v16);
      v18 = ipa_eth_ctx;
      pipe_connected[v17] = 0;
      v19 = *(unsigned int *)(v6 + 168);
      raw_spin_lock(v18 + 280);
      idr_remove(ipa_eth_ctx + 256, v19);
      raw_spin_unlock(ipa_eth_ctx + 280);
LABEL_21:
      v6 = *(_QWORD *)v6;
      if ( (__int64 *)v6 == v5 )
        goto LABEL_48;
    }
    printk(&unk_3A5017, "ipa_eth_client_disconnect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v24 = ipa3_get_ipc_logbuf();
      ipc_log_string(v24, "ipa_eth %s:%d invalid client type\n", "ipa_eth_client_disconnect_pipe", 507);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v25 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v25, "ipa_eth %s:%d invalid client type\n", "ipa_eth_client_disconnect_pipe", 507);
    }
    goto LABEL_44;
  }
LABEL_48:
  v30 = *a1;
  if ( *a1 >= 6u )
  {
    printk(&unk_3A80A1, "ipa_eth_pm_deregister");
    if ( ipa3_get_ipc_logbuf() )
    {
      v40 = ipa3_get_ipc_logbuf();
      ipc_log_string(v40, "ipa_eth %s:%d null client or client type not defined", "ipa_eth_pm_deregister", 637);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v41 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v41, "ipa_eth %s:%d null client or client type not defined", "ipa_eth_pm_deregister", 637);
    }
LABEL_81:
    printk(&unk_3CE19A, "ipa_eth_client_disconn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v46 = ipa3_get_ipc_logbuf();
      ipc_log_string(v46, "ipa_eth %s:%d pm deregister failed\n", "ipa_eth_client_disconn_pipes", 761);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v47 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v47, "ipa_eth %s:%d pm deregister failed\n", "ipa_eth_client_disconn_pipes", 761);
    }
    mutex_unlock(ipa_eth_ctx + 192);
LABEL_86:
    result = 4294967282LL;
    goto LABEL_55;
  }
  v31 = *((unsigned __int8 *)a1 + 4);
  if ( v31 < 2 )
  {
    v32 = ipa_eth_ctx;
    if ( *(_DWORD *)(ipa_eth_ctx + 48 + 24LL * v30 + 12LL * *((unsigned __int8 *)a1 + 4) + 4) != 1 )
    {
LABEL_54:
      _X8 = (unsigned int *)(v32 + 24LL * v30 + 12LL * (unsigned int)v31 + 52);
      goto LABEL_88;
    }
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa_eth_ctx
                                                                                                + 48
                                                                                                + 24LL * v30
                                                                                                + 12LL
                                                                                                * *((unsigned __int8 *)a1
                                                                                                  + 4))) )
    {
      printk(&unk_3CE253, "ipa_eth_pm_deregister");
      if ( ipa3_get_ipc_logbuf() )
      {
        v42 = ipa3_get_ipc_logbuf();
        ipc_log_string(v42, "ipa_eth %s:%d fail to deactivate ipa pm\n", "ipa_eth_pm_deregister", 648);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v43 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v43, "ipa_eth %s:%d fail to deactivate ipa pm\n", "ipa_eth_pm_deregister", 648);
      }
    }
    else
    {
      if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(ipa_eth_ctx
                                                                                              + 24LL * v30
                                                                                              + 12LL * (unsigned int)v31
                                                                                              + 48)) )
      {
        v32 = ipa_eth_ctx;
        goto LABEL_54;
      }
      printk(&unk_3B3577, "ipa_eth_pm_deregister");
      if ( ipa3_get_ipc_logbuf() )
      {
        v44 = ipa3_get_ipc_logbuf();
        ipc_log_string(v44, "ipa_eth %s:%d fail to deregister ipa pm\n", "ipa_eth_pm_deregister", 653);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v45 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v45, "ipa_eth %s:%d fail to deregister ipa pm\n", "ipa_eth_pm_deregister", 653);
      }
    }
    goto LABEL_81;
  }
  __break(0x5512u);
LABEL_88:
  __asm { PRFM            #0x11, [X8] }
  do
    v53 = __ldxr(_X8);
  while ( __stxr(v53 - 1, _X8) );
  mutex_unlock(ipa_eth_ctx + 192);
  result = 0;
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
