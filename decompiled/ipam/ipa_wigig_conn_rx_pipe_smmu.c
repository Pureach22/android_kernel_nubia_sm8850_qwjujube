__int64 __fastcall ipa_wigig_conn_rx_pipe_smmu(_QWORD *a1, _DWORD *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v6; // w0
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  long double v10; // q0
  __int64 v11; // x0
  __int64 v12; // x0
  long double v13; // q0
  __int64 v14; // x0
  __int64 v15; // x24
  int v16; // w20
  __int64 *v17; // x22
  _QWORD *v18; // x21
  int v19; // w25
  __int64 v20; // x8
  __int64 v21; // x10
  __int64 v22; // x11
  __int64 v23; // x9
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x9
  char v29; // w8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  unsigned int v36; // w19
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  const char *v49; // [xsp+8h] [xbp-28h] BYREF
  long double (__fastcall *v50)(__int64, int); // [xsp+10h] [xbp-20h]
  __int64 v51; // [xsp+18h] [xbp-18h]
  __int64 v52; // [xsp+20h] [xbp-10h]
  __int64 v53; // [xsp+28h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 0;
  v52 = 0;
  v49 = nullptr;
  v50 = nullptr;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d \n", "ipa_wigig_conn_rx_pipe_smmu", 1399);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d \n", "ipa_wigig_conn_rx_pipe_smmu", 1399);
  }
  if ( !a1 || !a2 )
  {
    printk(&unk_3D458B, "ipa_wigig_conn_rx_pipe_smmu");
    if ( ipa3_get_ipc_logbuf() )
    {
      v32 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v32,
        "ipa_wigig %s:%d empty parameters. in=%pK out=%pK\n",
        "ipa_wigig_conn_rx_pipe_smmu",
        1402,
        a1,
        a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v33 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v33,
        "ipa_wigig %s:%d empty parameters. in=%pK out=%pK\n",
        "ipa_wigig_conn_rx_pipe_smmu",
        1402,
        a1,
        a2);
      result = 4294967274LL;
      goto LABEL_84;
    }
    goto LABEL_10;
  }
  if ( ipa_wigig_ctx )
  {
    v6 = ipa3_uc_state_check();
    if ( !v6 )
    {
      if ( (unsigned int)ipa_wigig_init_smmu_params() )
      {
LABEL_10:
        result = 4294967274LL;
        goto LABEL_84;
      }
      if ( (*(_BYTE *)(ipa_wigig_ctx + 908) & 1) != 0 )
      {
        v49 = "wigig";
        v50 = ipa_wigig_pm_cb;
        v51 = 0;
        v52 = 0;
        if ( (unsigned int)ipa_pm_register((__int64)&v49, (unsigned int *)(ipa_wigig_ctx + 64)) )
        {
          printk(&unk_3B3AE2, "ipa_wigig_conn_rx_pipe_smmu");
          if ( ipa3_get_ipc_logbuf() )
          {
            v41 = ipa3_get_ipc_logbuf();
            ipc_log_string(v41, "ipa_wigig %s:%d fail to register ipa pm\n", "ipa_wigig_conn_rx_pipe_smmu", 1431);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v42 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v42, "ipa_wigig %s:%d fail to register ipa pm\n", "ipa_wigig_conn_rx_pipe_smmu", 1431);
          }
        }
        else
        {
          if ( (unsigned int)ipa3_wigig_uc_msi_init(
                               1,
                               *(_QWORD *)(ipa_wigig_ctx + 72),
                               *(_QWORD *)(ipa_wigig_ctx + 80),
                               *(_QWORD *)(ipa_wigig_ctx + 88),
                               *(_QWORD *)(ipa_wigig_ctx + 96),
                               *(_QWORD *)(ipa_wigig_ctx + 104)) )
          {
            printk(&unk_3F0D59, "ipa_wigig_conn_rx_pipe_smmu");
            if ( ipa3_get_ipc_logbuf() )
            {
              v43 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v43,
                "ipa_wigig %s:%d failed configuring msi regs at uC\n",
                "ipa_wigig_conn_rx_pipe_smmu",
                1443);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v44 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v44,
                "ipa_wigig %s:%d failed configuring msi regs at uC\n",
                "ipa_wigig_conn_rx_pipe_smmu",
                1443);
            }
          }
          else
          {
            if ( (unsigned int)ipa3_conn_wigig_rx_pipe_i((__int64)a1, a2, (_QWORD *)(ipa_wigig_ctx + 912)) )
            {
              printk(&unk_3DD15A, "ipa_wigig_conn_rx_pipe_smmu");
              if ( ipa3_get_ipc_logbuf() )
              {
                v45 = ipa3_get_ipc_logbuf();
                ipc_log_string(v45, "ipa_wigig %s:%d fail to connect rx pipe\n", "ipa_wigig_conn_rx_pipe_smmu", 1449);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v46 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v46, "ipa_wigig %s:%d fail to connect rx pipe\n", "ipa_wigig_conn_rx_pipe_smmu", 1449);
              }
            }
            else
            {
              v8 = *(_QWORD *)(ipa_wigig_ctx + 912);
              if ( v8 )
                ipa_wigig_init_debugfs(v8);
              if ( ipa3_get_ipc_logbuf() )
              {
                v9 = ipa3_get_ipc_logbuf();
                ipc_log_string(v9, "ipa_wigig %s:%d \n", "ipa_wigig_store_rx_smmu_info", 1262);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v11 = ipa3_get_ipc_logbuf_low();
                v10 = ipc_log_string(v11, "ipa_wigig %s:%d \n", "ipa_wigig_store_rx_smmu_info", 1262);
              }
              if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD *, _QWORD, long double))ipa_wigig_store_pipe_smmu_info)(
                                    a1 + 2,
                                    0,
                                    v10) )
              {
                if ( (*(_BYTE *)(ipa_wigig_ctx + 909) & 1) != 0 )
                {
LABEL_35:
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v26 = ipa3_get_ipc_logbuf();
                    ipc_log_string(v26, "ipa_wigig %s:%d exit\n", "ipa_wigig_store_rx_smmu_info", 1275);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v27 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(v27, "ipa_wigig %s:%d exit\n", "ipa_wigig_store_rx_smmu_info", 1275);
                  }
                  v28 = ipa_wigig_ctx;
                  *(_QWORD *)(ipa_wigig_ctx + 112) = *a1;
                  v29 = *(_BYTE *)(v28 + 910) | 1;
                  *(_QWORD *)(v28 + 120) = a1[1];
                  *(_BYTE *)(v28 + 910) = v29;
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v30 = ipa3_get_ipc_logbuf();
                    ipc_log_string(v30, "ipa_wigig %s:%d exit\n", "ipa_wigig_conn_rx_pipe_smmu", 1469);
                  }
                  result = ipa3_get_ipc_logbuf_low();
                  if ( result )
                  {
                    v31 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(v31, "ipa_wigig %s:%d exit\n", "ipa_wigig_conn_rx_pipe_smmu", 1469);
                    result = 0;
                  }
                  goto LABEL_84;
                }
                if ( ipa3_get_ipc_logbuf() )
                {
                  v12 = ipa3_get_ipc_logbuf();
                  ipc_log_string(v12, "ipa_wigig %s:%d \n", "ipa_wigig_store_rx_buff_smmu_info", 1121);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v14 = ipa3_get_ipc_logbuf_low();
                  v13 = ipc_log_string(v14, "ipa_wigig %s:%d \n", "ipa_wigig_store_rx_buff_smmu_info", 1121);
                }
                v15 = ipa_wigig_ctx;
                v16 = *((_DWORD *)a1 + 30);
                if ( !(unsigned int)sg_alloc_table(ipa_wigig_ctx + 608, (unsigned int)v16, 3264, v13) )
                {
                  if ( v16 >= 1 )
                  {
                    v17 = (__int64 *)a1[14];
                    v18 = *(_QWORD **)(v15 + 608);
                    v19 = v16;
                    do
                    {
                      v20 = v17[3];
                      v21 = *v17;
                      v22 = v17[1];
                      v18[2] = v17[2];
                      v18[3] = v20;
                      *v18 = v21;
                      v18[1] = v22;
                      v18 = (_QWORD *)sg_next(v18);
                      --v19;
                      v17 = (__int64 *)sg_next(v17);
                    }
                    while ( v19 );
                  }
                  *(_DWORD *)(v15 + 616) = v16;
                  v23 = ipa_wigig_ctx;
                  *(_DWORD *)(v15 + 620) = *((_DWORD *)a1 + 31);
                  *(_QWORD *)(v23 + 624) = a1[16];
                  *(_DWORD *)(v23 + 632) = *((_DWORD *)a1 + 34);
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v24 = ipa3_get_ipc_logbuf();
                    ipc_log_string(v24, "ipa_wigig %s:%d exit\n", "ipa_wigig_store_rx_buff_smmu_info", 1131);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v25 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(v25, "ipa_wigig %s:%d exit\n", "ipa_wigig_store_rx_buff_smmu_info", 1131);
                  }
                  goto LABEL_35;
                }
                ipa_wigig_clean_pipe_info(0);
              }
              printk(&unk_3B3B0D, "ipa_wigig_conn_rx_pipe_smmu");
              if ( ipa3_get_ipc_logbuf() )
              {
                v47 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v47,
                  "ipa_wigig %s:%d fail to store smmu data for rx pipe\n",
                  "ipa_wigig_conn_rx_pipe_smmu",
                  1458);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v48 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(
                  v48,
                  "ipa_wigig %s:%d fail to store smmu data for rx pipe\n",
                  "ipa_wigig_conn_rx_pipe_smmu",
                  1458);
              }
              ipa3_disconn_wigig_pipe_i(0x56u, (__int64)(a1 + 2), (__int64)(a1 + 14));
            }
            ipa3_wigig_uc_msi_init(
              0,
              *(_QWORD *)(ipa_wigig_ctx + 72),
              *(_QWORD *)(ipa_wigig_ctx + 80),
              *(_QWORD *)(ipa_wigig_ctx + 88),
              *(_QWORD *)(ipa_wigig_ctx + 96),
              *(_QWORD *)(ipa_wigig_ctx + 104));
          }
          ((void (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(ipa_wigig_ctx + 64));
        }
      }
      else
      {
        printk(&unk_3FFBA8, "ipa_wigig_conn_rx_pipe_smmu");
        if ( ipa3_get_ipc_logbuf() )
        {
          v39 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v39,
            "ipa_wigig %s:%d IPA SMMU is disabled, wrong API used\n",
            "ipa_wigig_conn_rx_pipe_smmu",
            1421);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v40 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v40,
            "ipa_wigig %s:%d IPA SMMU is disabled, wrong API used\n",
            "ipa_wigig_conn_rx_pipe_smmu",
            1421);
        }
      }
      result = 4294967282LL;
      goto LABEL_84;
    }
    v36 = v6;
    printk(&unk_3FFB88, "ipa_wigig_conn_rx_pipe_smmu");
    if ( ipa3_get_ipc_logbuf() )
    {
      v37 = ipa3_get_ipc_logbuf();
      ipc_log_string(v37, "ipa_wigig %s:%d uC not ready\n", "ipa_wigig_conn_rx_pipe_smmu", 1413);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v38 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v38, "ipa_wigig %s:%d uC not ready\n", "ipa_wigig_conn_rx_pipe_smmu", 1413);
    }
    result = v36;
  }
  else
  {
    printk(&unk_3CE6D1, "ipa_wigig_conn_rx_pipe_smmu");
    if ( ipa3_get_ipc_logbuf() )
    {
      v34 = ipa3_get_ipc_logbuf();
      ipc_log_string(v34, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_conn_rx_pipe_smmu", 1407);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v35 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v35, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_conn_rx_pipe_smmu", 1407);
    }
    result = 0xFFFFFFFFLL;
  }
LABEL_84:
  _ReadStatusReg(SP_EL0);
  return result;
}
