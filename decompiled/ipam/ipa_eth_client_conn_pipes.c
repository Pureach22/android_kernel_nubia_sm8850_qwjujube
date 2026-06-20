__int64 __fastcall ipa_eth_client_conn_pipes(unsigned int *a1)
{
  signed int v2; // w24
  unsigned int v3; // w28
  unsigned int v4; // w22
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x22
  unsigned __int64 v8; // x23
  __int64 *v9; // x19
  __int64 v10; // x24
  unsigned int v11; // w25
  unsigned int ipa_client_type_from_pipe; // w0
  int v13; // w0
  int v14; // w19
  __int64 v15; // x0
  long double v16; // q0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v20; // x22
  unsigned __int64 StatusReg; // x28
  unsigned int v22; // w0
  unsigned int v23; // w23
  int v24; // w25
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  unsigned int v58; // w9
  unsigned int v59; // [xsp+8h] [xbp-58h]
  signed int v60; // [xsp+10h] [xbp-50h]
  char *v61; // [xsp+18h] [xbp-48h] BYREF
  __int64 (__fastcall *v62)(); // [xsp+20h] [xbp-40h]
  __int64 v63; // [xsp+28h] [xbp-38h]
  __int64 v64; // [xsp+30h] [xbp-30h]
  char s[8]; // [xsp+38h] [xbp-28h] BYREF
  __int64 v66; // [xsp+40h] [xbp-20h]
  __int64 v67; // [xsp+48h] [xbp-18h]
  __int64 v68; // [xsp+50h] [xbp-10h]
  __int64 v69; // [xsp+58h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || *a1 >= 6 )
  {
    printk(&unk_3A80A1, "ipa_eth_client_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_eth %s:%d null client or client type not defined",
        "ipa_eth_client_conn_pipes",
        669);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_77;
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa_eth %s:%d null client or client type not defined",
      "ipa_eth_client_conn_pipes",
      669);
    goto LABEL_76;
  }
  if ( !ipa_eth_ctx )
  {
    printk(&unk_3C5615, "ipa_eth_client_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v41 = ipa3_get_ipc_logbuf();
      ipc_log_string(v41, "ipa_eth %s:%d connect called before register readiness\n", "ipa_eth_client_conn_pipes", 673);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_77;
    v42 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v42, "ipa_eth %s:%d connect called before register readiness\n", "ipa_eth_client_conn_pipes", 673);
LABEL_76:
    result = 4294967282LL;
    goto LABEL_63;
  }
  if ( (*(_BYTE *)(ipa_eth_ctx + 248) & 1) == 0 )
  {
    printk(&unk_3FF555, "ipa_eth_client_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v43 = ipa3_get_ipc_logbuf();
      ipc_log_string(v43, "ipa_eth %s:%d conn called before IPA eth ready\n", "ipa_eth_client_conn_pipes", 678);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v44 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v44, "ipa_eth %s:%d conn called before IPA eth ready\n", "ipa_eth_client_conn_pipes", 678);
      goto LABEL_76;
    }
LABEL_77:
    result = 4294967282LL;
    goto LABEL_63;
  }
  *(_QWORD *)(ipa_eth_ctx + 304) = *((_QWORD *)a1 + 4);
  v2 = *a1;
  v3 = *((unsigned __int8 *)a1 + 4);
  v4 = a1[2];
  if ( ipa3_get_ipc_logbuf() )
  {
    v5 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v5,
      "ipa_eth %s:%d ipa_eth conn client %d inst %d, traffic %d\n",
      "ipa_eth_client_conn_pipes",
      686,
      v2,
      v3,
      v4);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v6,
      "ipa_eth %s:%d ipa_eth conn client %d inst %d, traffic %d\n",
      "ipa_eth_client_conn_pipes",
      686,
      v2,
      v3,
      v4);
  }
  mutex_lock(ipa_eth_ctx + 192);
  v7 = *a1;
  v63 = 0;
  v64 = 0;
  v61 = nullptr;
  v62 = nullptr;
  v67 = 0;
  v68 = 0;
  *(_QWORD *)s = 0;
  v66 = 0;
  if ( (unsigned int)v7 >= 6 )
  {
    printk(&unk_3F976F, "ipa_eth_pm_register");
    if ( ipa3_get_ipc_logbuf() )
    {
      v45 = ipa3_get_ipc_logbuf();
      ipc_log_string(v45, "ipa_eth %s:%d null client or eth client doesn't exist", "ipa_eth_pm_register", 579);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v46 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v46, "ipa_eth %s:%d null client or eth client doesn't exist", "ipa_eth_pm_register", 579);
    }
    goto LABEL_90;
  }
  v8 = *((unsigned __int8 *)a1 + 4);
  if ( v8 >= 2 )
    goto LABEL_95;
  if ( *(_DWORD *)(ipa_eth_ctx + 24LL * (unsigned int)v7 + 12LL * *((unsigned __int8 *)a1 + 4) + 52) )
    goto LABEL_14;
  snprintf(s, 0x20u, "ipa_eth_%d_%d", v7, v8);
  v61 = s;
  v62 = ipa_eth_pm_cb;
  v63 = 0;
  v64 = 0;
  if ( (unsigned int)ipa_pm_register(
                       (__int64)&v61,
                       (unsigned int *)(ipa_eth_ctx + 24LL * (unsigned int)v7 + 12LL * (unsigned int)v8 + 48)) )
  {
    printk(&unk_3C5691, "ipa_eth_pm_register");
    if ( ipa3_get_ipc_logbuf() )
    {
      v47 = ipa3_get_ipc_logbuf();
      ipc_log_string(v47, "ipa_eth %s:%d fail to register ipa pm\n", "ipa_eth_pm_register", 598);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v48 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v48, "ipa_eth %s:%d fail to register ipa pm\n", "ipa_eth_pm_register", 598);
    }
    goto LABEL_90;
  }
  if ( (unsigned int)ipa_pm_activate_sync(*(_DWORD *)(ipa_eth_ctx
                                                    + 24LL * (unsigned int)v7
                                                    + 12LL * (unsigned int)v8
                                                    + 48)) )
  {
    printk(&unk_3CE202, "ipa_eth_pm_register");
    if ( ipa3_get_ipc_logbuf() )
    {
      v49 = ipa3_get_ipc_logbuf();
      ipc_log_string(v49, "ipa_eth %s:%d fail to activate ipa pm\n", "ipa_eth_pm_register", 605);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v50 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v50, "ipa_eth %s:%d fail to activate ipa pm\n", "ipa_eth_pm_register", 605);
    }
LABEL_90:
    printk(&unk_3C2479, "ipa_eth_client_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v51 = ipa3_get_ipc_logbuf();
      ipc_log_string(v51, "ipa_eth %s:%d pm register failed\n", "ipa_eth_client_conn_pipes", 690);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v52 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v52, "ipa_eth %s:%d pm register failed\n", "ipa_eth_client_conn_pipes", 690);
    }
    mutex_unlock(ipa_eth_ctx + 192);
    result = 4294967282LL;
    goto LABEL_63;
  }
LABEL_14:
  v60 = v2;
  v9 = (__int64 *)(a1 + 4);
  v10 = *((_QWORD *)a1 + 2);
  if ( (unsigned int *)v10 != a1 + 4 )
  {
    while ( 1 )
    {
      if ( *(_DWORD *)(v10 + 16) != 1 )
      {
        v11 = *(_DWORD *)(ipa_eth_ctx + 24LL * (unsigned int)v7 + 12LL * (unsigned int)v8 + 48);
        ipa_client_type_from_pipe = ipa_eth_get_ipa_client_type_from_pipe(v10);
        v13 = ipa_pm_associate_ipa_cons_to_client(v11, ipa_client_type_from_pipe);
        if ( v13 )
          break;
      }
      v10 = *(_QWORD *)v10;
      if ( (__int64 *)v10 == v9 )
        goto LABEL_24;
    }
    v14 = v13;
    printk(&unk_3B6613, "ipa_eth_pm_register");
    if ( ipa3_get_ipc_logbuf() )
    {
      v15 = ipa3_get_ipc_logbuf();
      ipc_log_string(v15, "ipa_eth %s:%d fail to associate cons with PM %d\n", "ipa_eth_pm_register", 617, v14);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      v16 = ipc_log_string(v17, "ipa_eth %s:%d fail to associate cons with PM %d\n", "ipa_eth_pm_register", 617, v14);
    }
    v18 = ((__int64 (__fastcall *)(_QWORD, long double))ipa_pm_deregister)(
            *(unsigned int *)(ipa_eth_ctx + 24 * v7 + 12 * v8 + 48),
            v16);
    *(_DWORD *)(ipa_eth_ctx + 24 * v7 + 12 * v8 + 48) = 0;
    ((void (__fastcall *)(__int64))ipa_assert)(v18);
    goto LABEL_90;
  }
LABEL_24:
  v59 = v3;
  _X8 = (unsigned int *)(ipa_eth_ctx + 24LL * (unsigned int)v7 + 12LL * (unsigned int)v8 + 52);
  __asm { PRFM            #0x11, [X8] }
  do
    v58 = __ldxr(_X8);
  while ( __stxr(v58 + 1, _X8) );
  v20 = *v9;
  if ( (__int64 *)*v9 != v9 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( !v20 )
      {
        printk(&unk_3D9A89, "ipa_eth_client_connect_pipe");
        if ( ipa3_get_ipc_logbuf() )
        {
          v27 = ipa3_get_ipc_logbuf();
          ipc_log_string(v27, "ipa_eth %s:%d invalid pipe\n", "ipa_eth_client_connect_pipe", 457);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v28 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v28, "ipa_eth %s:%d invalid pipe\n", "ipa_eth_client_connect_pipe", 457);
        }
        goto LABEL_53;
      }
      if ( !*(_QWORD *)(v20 + 160) )
      {
        printk(&unk_3B9679, "ipa_eth_client_connect_pipe");
        if ( ipa3_get_ipc_logbuf() )
        {
          v29 = ipa3_get_ipc_logbuf();
          ipc_log_string(v29, "ipa_eth %s:%d invalid client\n", "ipa_eth_client_connect_pipe", 462);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v30 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v30, "ipa_eth %s:%d invalid client\n", "ipa_eth_client_connect_pipe", 462);
        }
        goto LABEL_53;
      }
      v22 = ipa_eth_get_ipa_client_type_from_pipe(v20);
      if ( v22 == 134 )
        break;
      v23 = v22;
      if ( pipe_connected[(unsigned __int8)((__int64 (*)(void))client_to_pipe_index)()] == 1 )
      {
        printk(&unk_3FF61A, "ipa_eth_client_connect_pipe");
        if ( ipa3_get_ipc_logbuf() )
        {
          v33 = ipa3_get_ipc_logbuf();
          ipc_log_string(v33, "ipa_eth %s:%d client already connected\n", "ipa_eth_client_connect_pipe", 473);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v34 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v34, "ipa_eth %s:%d client already connected\n", "ipa_eth_client_connect_pipe", 473);
        }
LABEL_53:
        printk(&unk_3F3A86, "ipa_eth_client_conn_pipes");
        if ( ipa3_get_ipc_logbuf() )
        {
          v35 = ipa3_get_ipc_logbuf();
          ipc_log_string(v35, "ipa_eth %s:%d pipe connect fails\n", "ipa_eth_client_conn_pipes", 698);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v36 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v36, "ipa_eth %s:%d pipe connect fails\n", "ipa_eth_client_conn_pipes", 698);
        }
        ((void (*)(void))ipa_assert)();
        goto LABEL_28;
      }
      idr_preload(3264);
      raw_spin_lock(ipa_eth_ctx + 280);
      v24 = idr_alloc(ipa_eth_ctx + 256, v20, 0, 0, 10240);
      v25 = raw_spin_unlock(ipa_eth_ctx + 280);
      _ReadStatusReg(TPIDR_EL1);
      v26 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v26;
      if ( !v26 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule(v25);
      *(_DWORD *)(v20 + 168) = v24;
      if ( (unsigned int)ipa3_eth_connect(v20, v23) )
        goto LABEL_53;
      pipe_connected[(unsigned __int8)client_to_pipe_index(v23)] = 1;
LABEL_28:
      v20 = *(_QWORD *)v20;
      if ( (__int64 *)v20 == v9 )
        goto LABEL_58;
    }
    printk(&unk_3A5017, "ipa_eth_client_connect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v31 = ipa3_get_ipc_logbuf();
      ipc_log_string(v31, "ipa_eth %s:%d invalid client type\n", "ipa_eth_client_connect_pipe", 468);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v32 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v32, "ipa_eth %s:%d invalid client type\n", "ipa_eth_client_connect_pipe", 468);
    }
    goto LABEL_53;
  }
LABEL_58:
  if ( (unsigned int)v60 >= 6 || v59 > 1 )
LABEL_95:
    __break(0x5512u);
  v37 = ipa_eth_ctx;
  if ( (*(_BYTE *)(ipa_eth_ctx + 24LL * v60 + 12LL * v59 + 56) & 1) == 0 )
  {
    ((void (__fastcall *)(unsigned int *))ipa3_eth_debugfs_add_node)(a1);
    v37 = ipa_eth_ctx;
    *(_BYTE *)(ipa_eth_ctx + 24LL * v60 + 12LL * v59 + 56) = 1;
  }
  mutex_unlock(v37 + 192);
  result = 0;
LABEL_63:
  _ReadStatusReg(SP_EL0);
  return result;
}
