__int64 __fastcall ipa_wigig_conn_client_smmu(__int64 a1, int *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v6; // w0
  int v7; // w21
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w0
  unsigned int v11; // w21
  unsigned int v12; // w21
  __int64 result; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w19
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned int v32; // w21
  __int64 v33; // x0
  __int64 v34; // x24
  __int64 v35; // x0
  __int64 v36; // x0
  long double v37; // q0
  int v38; // w8
  unsigned int v39; // w27
  unsigned int v40; // w9
  __int64 v41; // x10
  __int64 v42; // x28
  __int64 v43; // x26
  int v44; // w25
  __int64 v45; // x21
  __int64 *v46; // x24
  _QWORD *v47; // x23
  int v48; // w22
  __int64 v49; // x8
  __int64 v50; // x10
  __int64 v51; // x11
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x21
  int v57; // w21
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // [xsp+18h] [xbp-38h]
  unsigned int v63; // [xsp+24h] [xbp-2Ch] BYREF
  _QWORD v64[5]; // [xsp+28h] [xbp-28h] BYREF

  v64[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v64, 0, 32);
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d \n", "ipa_wigig_conn_client_smmu", 1632);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d \n", "ipa_wigig_conn_client_smmu", 1632);
  }
  if ( !a1 || !a2 )
  {
    printk(&unk_3D458B, "ipa_wigig_conn_client_smmu");
    if ( ipa3_get_ipc_logbuf() )
    {
      v18 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v18,
        "ipa_wigig %s:%d empty parameters. in=%pK out=%pK\n",
        "ipa_wigig_conn_client_smmu",
        1635,
        (const void *)a1,
        a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v19 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v19,
        "ipa_wigig %s:%d empty parameters. in=%pK out=%pK\n",
        "ipa_wigig_conn_client_smmu",
        1635,
        (const void *)a1,
        a2);
      result = 4294967274LL;
      goto LABEL_22;
    }
LABEL_74:
    result = 4294967274LL;
    goto LABEL_22;
  }
  if ( !ipa_wigig_ctx )
  {
    printk(&unk_3CE6D1, "ipa_wigig_conn_client_smmu");
    if ( ipa3_get_ipc_logbuf() )
    {
      v20 = ipa3_get_ipc_logbuf();
      ipc_log_string(v20, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_conn_client_smmu", 1640);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v21 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v21, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_conn_client_smmu", 1640);
    }
    result = 0xFFFFFFFFLL;
    goto LABEL_22;
  }
  if ( (*(_BYTE *)(ipa_wigig_ctx + 910) & 1) == 0 )
  {
    printk(&unk_3C5CE6, "ipa_wigig_conn_client_smmu");
    if ( ipa3_get_ipc_logbuf() )
    {
      v22 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v22,
        "ipa_wigig %s:%d must connect rx pipe before connecting any client\n",
        "ipa_wigig_conn_client_smmu",
        1648);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v23 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v23,
        "ipa_wigig %s:%d must connect rx pipe before connecting any client\n",
        "ipa_wigig_conn_client_smmu",
        1648);
      result = 4294967274LL;
      goto LABEL_22;
    }
    goto LABEL_74;
  }
  if ( (*(_BYTE *)(ipa_wigig_ctx + 908) & 1) == 0 )
  {
    printk(&unk_3FFBA8, "ipa_wigig_conn_client_smmu");
    if ( ipa3_get_ipc_logbuf() )
    {
      v24 = ipa3_get_ipc_logbuf();
      ipc_log_string(v24, "ipa_wigig %s:%d IPA SMMU is disabled, wrong API used\n", "ipa_wigig_conn_client_smmu", 1653);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_79;
    v25 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v25, "ipa_wigig %s:%d IPA SMMU is disabled, wrong API used\n", "ipa_wigig_conn_client_smmu", 1653);
    goto LABEL_58;
  }
  v6 = ipa3_uc_state_check();
  if ( !v6 )
  {
    if ( !(unsigned int)ipa_wigig_get_devname((__int64)v64) )
    {
      if ( !(unsigned int)ipa3_conn_wigig_client_i(
                            a1,
                            a2,
                            *(_QWORD *)(ipa_wigig_ctx + 112),
                            *(_QWORD *)(ipa_wigig_ctx + 120)) )
      {
        if ( (unsigned int)ipa_wigig_send_msg(40, (const char *)v64, a1 + 121, *a2, 0) )
        {
          printk(&unk_3A5654, "ipa_wigig_conn_client_smmu");
          if ( ipa3_get_ipc_logbuf() )
          {
            v54 = ipa3_get_ipc_logbuf();
            ipc_log_string(v54, "ipa_wigig %s:%d couldn't send msg to IPACM\n", "ipa_wigig_conn_client_smmu", 1681);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v55 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v55, "ipa_wigig %s:%d couldn't send msg to IPACM\n", "ipa_wigig_conn_client_smmu", 1681);
          }
          v12 = -14;
          goto LABEL_21;
        }
        v7 = *a2;
        if ( ipa3_get_ipc_logbuf() )
        {
          v8 = ipa3_get_ipc_logbuf();
          ipc_log_string(v8, "ipa_wigig %s:%d \n", "ipa_wigig_store_client_smmu_info", 1290);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v9 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v9, "ipa_wigig %s:%d \n", "ipa_wigig_store_client_smmu_info", 1290);
        }
        v63 = 0;
        v10 = ipa_wigig_client_to_idx(v7, &v63);
        if ( v10
          || (v11 = v63, (v10 = ((__int64 (__fastcall *)(__int64, _QWORD))ipa_wigig_store_pipe_smmu_info)(a1, v63)) != 0) )
        {
LABEL_20:
          v12 = v10;
          ipa_wigig_send_wlan_msg(1, (const char *)v64, (int *)(a1 + 121));
LABEL_21:
          ipa3_disconn_wigig_pipe_i(*a2, a1, a1 + 96);
          result = v12;
          goto LABEL_22;
        }
        if ( (*(_BYTE *)(ipa_wigig_ctx + 909) & 1) != 0 )
          goto LABEL_24;
        if ( ipa3_get_ipc_logbuf() )
        {
          v31 = ipa3_get_ipc_logbuf();
          ipc_log_string(v31, "ipa_wigig %s:%d \n", "ipa_wigig_store_tx_buff_smmu_info", 1155);
        }
        v32 = v11 - 1;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v33 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v33, "ipa_wigig %s:%d \n", "ipa_wigig_store_tx_buff_smmu_info", 1155);
        }
        if ( v32 >= 4 )
        {
          printk(&unk_3AE716, "ipa_wigig_store_tx_buff_smmu_info");
          if ( ipa3_get_ipc_logbuf() )
          {
            v60 = ipa3_get_ipc_logbuf();
            ipc_log_string(v60, "ipa_wigig %s:%d invalid tx index %d\n", "ipa_wigig_store_tx_buff_smmu_info", 1158, v32);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v61 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v61, "ipa_wigig %s:%d invalid tx index %d\n", "ipa_wigig_store_tx_buff_smmu_info", 1158, v32);
          }
          v57 = -22;
        }
        else
        {
          v34 = ipa_wigig_ctx + 24LL * v32 + 640;
          v35 = _kmalloc_noprof(16LL * *(unsigned int *)(a1 + 112), 3520);
          *(_QWORD *)v34 = v35;
          if ( v35 )
          {
            v36 = _kmalloc_noprof(8LL * *(unsigned int *)(a1 + 112), 3520);
            *(_QWORD *)(v34 + 8) = v36;
            if ( v36 )
            {
              if ( !*(_DWORD *)(a1 + 112) )
              {
                v40 = 0;
LABEL_92:
                *(_DWORD *)(v34 + 16) = v40;
                *(_DWORD *)(v34 + 20) = *(_DWORD *)(a1 + 116);
                if ( ipa3_get_ipc_logbuf() )
                {
                  v58 = ipa3_get_ipc_logbuf();
                  ipc_log_string(v58, "ipa_wigig %s:%d exit\n", "ipa_wigig_store_tx_buff_smmu_info", 1192);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v59 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(v59, "ipa_wigig %s:%d exit\n", "ipa_wigig_store_tx_buff_smmu_info", 1192);
                }
LABEL_24:
                if ( ipa3_get_ipc_logbuf() )
                {
                  v14 = ipa3_get_ipc_logbuf();
                  ipc_log_string(v14, "ipa_wigig %s:%d exit\n", "ipa_wigig_store_client_smmu_info", 1307);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v15 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(v15, "ipa_wigig %s:%d exit\n", "ipa_wigig_store_client_smmu_info", 1307);
                }
                *(_BYTE *)(ipa_wigig_ctx + 910) |= ipa_wigig_pipe_to_bit_val(*a2);
                ipa_wigig_store_client_mac(*a2, (int *)(a1 + 121));
                if ( ipa3_get_ipc_logbuf() )
                {
                  v16 = ipa3_get_ipc_logbuf();
                  ipc_log_string(v16, "ipa_wigig %s:%d exit\n", "ipa_wigig_conn_client_smmu", 1696);
                }
                result = ipa3_get_ipc_logbuf_low();
                if ( result )
                {
                  v17 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(v17, "ipa_wigig %s:%d exit\n", "ipa_wigig_conn_client_smmu", 1696);
                  result = 0;
                }
                goto LABEL_22;
              }
              v38 = 0;
              v39 = -1;
              v62 = v34;
              while ( 1 )
              {
                v41 = 16LL * v38;
                v42 = v38;
                v43 = *(_QWORD *)(a1 + 96) + v41;
                v44 = *(_DWORD *)(v43 + 8);
                v45 = *(_QWORD *)v34 + v41;
                if ( (unsigned int)sg_alloc_table(v45, (unsigned int)v44, 3264, v37) )
                  break;
                if ( v44 >= 1 )
                {
                  v46 = *(__int64 **)v43;
                  v47 = *(_QWORD **)v45;
                  v48 = v44;
                  do
                  {
                    v49 = v46[3];
                    v50 = *v46;
                    v51 = v46[1];
                    v47[2] = v46[2];
                    v47[3] = v49;
                    *v47 = v50;
                    v47[1] = v51;
                    v47 = (_QWORD *)sg_next(v47);
                    --v48;
                    v46 = (__int64 *)sg_next(v46);
                  }
                  while ( v48 );
                }
                *(_DWORD *)(v45 + 8) = v44;
                v34 = v62;
                ++v39;
                *(_DWORD *)(v45 + 12) = *(_DWORD *)(v43 + 12);
                *(_QWORD *)(*(_QWORD *)(v62 + 8) + 8 * v42) = *(_QWORD *)(*(_QWORD *)(a1 + 104) + 8 * v42);
                v38 = v42 + 1;
                v40 = *(_DWORD *)(a1 + 112);
                if ( (int)v42 + 1 >= v40 )
                  goto LABEL_92;
              }
              if ( (int)v42 - 1 >= 0 )
              {
                v56 = 16LL * v39;
                do
                {
                  sg_free_table(*(_QWORD *)v34 + v56, v37);
                  v56 -= 16;
                }
                while ( v56 != -16 );
              }
              kfree(*(_QWORD *)(v34 + 8));
              v57 = -22;
              *(_QWORD *)(v34 + 8) = 0;
            }
            else
            {
              v57 = -12;
            }
            kfree(*(_QWORD *)v34);
            *(_QWORD *)v34 = 0;
          }
          else
          {
            v57 = -12;
          }
        }
        ipa_wigig_clean_pipe_info(0);
        v10 = v57;
        goto LABEL_20;
      }
      printk(&unk_3D45BF, "ipa_wigig_conn_client_smmu");
      if ( ipa3_get_ipc_logbuf() )
      {
        v52 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v52,
          "ipa_wigig %s:%d fail to connect client. MAC [%X][%X][%X][%X][%X][%X]\n",
          "ipa_wigig_conn_client_smmu",
          1674,
          *(unsigned __int8 *)(a1 + 121),
          *(unsigned __int8 *)(a1 + 122),
          *(unsigned __int8 *)(a1 + 123),
          *(unsigned __int8 *)(a1 + 124),
          *(unsigned __int8 *)(a1 + 125),
          *(unsigned __int8 *)(a1 + 126));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v53 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v53,
          "ipa_wigig %s:%d fail to connect client. MAC [%X][%X][%X][%X][%X][%X]\n",
          "ipa_wigig_conn_client_smmu",
          1674,
          *(unsigned __int8 *)(a1 + 121),
          *(unsigned __int8 *)(a1 + 122),
          *(unsigned __int8 *)(a1 + 123),
          *(unsigned __int8 *)(a1 + 124),
          *(unsigned __int8 *)(a1 + 125),
          *(unsigned __int8 *)(a1 + 126));
        result = 4294967282LL;
        goto LABEL_22;
      }
LABEL_79:
      result = 4294967282LL;
      goto LABEL_22;
    }
    printk(&unk_3A8924, "ipa_wigig_conn_client_smmu");
    if ( ipa3_get_ipc_logbuf() )
    {
      v29 = ipa3_get_ipc_logbuf();
      ipc_log_string(v29, "ipa_wigig %s:%d couldn't get dev name\n", "ipa_wigig_conn_client_smmu", 1664);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_79;
    v30 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v30, "ipa_wigig %s:%d couldn't get dev name\n", "ipa_wigig_conn_client_smmu", 1664);
LABEL_58:
    result = 4294967282LL;
    goto LABEL_22;
  }
  v26 = v6;
  printk(&unk_3FFB88, "ipa_wigig_conn_client_smmu");
  if ( ipa3_get_ipc_logbuf() )
  {
    v27 = ipa3_get_ipc_logbuf();
    ipc_log_string(v27, "ipa_wigig %s:%d uC not ready\n", "ipa_wigig_conn_client_smmu", 1659);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v28 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v28, "ipa_wigig %s:%d uC not ready\n", "ipa_wigig_conn_client_smmu", 1659);
  }
  result = v26;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
