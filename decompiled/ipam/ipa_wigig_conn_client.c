__int64 __fastcall ipa_wigig_conn_client(unsigned __int8 *a1, int *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x0
  unsigned int v7; // w21
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
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
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  unsigned int v29; // [xsp+14h] [xbp-2Ch] BYREF
  _QWORD v30[5]; // [xsp+18h] [xbp-28h] BYREF

  v30[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v30, 0, 32);
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d \n", "ipa_wigig_conn_client", 1550);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d \n", "ipa_wigig_conn_client", 1550);
  }
  if ( !a1 || !a2 )
  {
    printk(&unk_3D458B, "ipa_wigig_conn_client");
    if ( ipa3_get_ipc_logbuf() )
    {
      v11 = ipa3_get_ipc_logbuf();
      ipc_log_string(v11, "ipa_wigig %s:%d empty parameters. in=%pK out=%pK\n", "ipa_wigig_conn_client", 1553, a1, a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v12 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v12, "ipa_wigig %s:%d empty parameters. in=%pK out=%pK\n", "ipa_wigig_conn_client", 1553, a1, a2);
    }
    goto LABEL_60;
  }
  if ( ipa_wigig_ctx )
  {
    if ( (*(_BYTE *)(ipa_wigig_ctx + 910) & 1) == 0 )
    {
      printk(&unk_3C5CE6, "ipa_wigig_conn_client");
      if ( ipa3_get_ipc_logbuf() )
      {
        v15 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v15,
          "ipa_wigig %s:%d must connect rx pipe before connecting any client\n",
          "ipa_wigig_conn_client",
          1566);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v16 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v16,
          "ipa_wigig %s:%d must connect rx pipe before connecting any client\n",
          "ipa_wigig_conn_client",
          1566);
      }
      goto LABEL_60;
    }
    if ( *(_BYTE *)(ipa_wigig_ctx + 908) == 1 )
    {
      printk(&unk_3B3AAB, "ipa_wigig_conn_client");
      if ( ipa3_get_ipc_logbuf() )
      {
        v17 = ipa3_get_ipc_logbuf();
        ipc_log_string(v17, "ipa_wigig %s:%d IPA SMMU is enabled, wrong API used\n", "ipa_wigig_conn_client", 1571);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_49;
      v18 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v18, "ipa_wigig %s:%d IPA SMMU is enabled, wrong API used\n", "ipa_wigig_conn_client", 1571);
    }
    else if ( (unsigned int)ipa3_uc_state_check() )
    {
      printk(&unk_3FFB88, "ipa_wigig_conn_client");
      if ( ipa3_get_ipc_logbuf() )
      {
        v19 = ipa3_get_ipc_logbuf();
        ipc_log_string(v19, "ipa_wigig %s:%d uC not ready\n", "ipa_wigig_conn_client", 1576);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_49;
      v20 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v20, "ipa_wigig %s:%d uC not ready\n", "ipa_wigig_conn_client", 1576);
    }
    else
    {
      if ( !(unsigned int)ipa_wigig_get_devname(v30) )
      {
        if ( !(unsigned int)ipa3_conn_wigig_client_i(
                              (__int64)a1,
                              a2,
                              *(_QWORD *)(ipa_wigig_ctx + 112),
                              *(_QWORD *)(ipa_wigig_ctx + 120)) )
        {
          v6 = (unsigned int)*a2;
          v29 = 0;
          if ( (unsigned int)ipa_wigig_client_to_idx(v6, &v29) )
          {
            printk(&unk_3DFCDB, "ipa_wigig_conn_client");
            if ( ipa3_get_ipc_logbuf() )
            {
              v25 = ipa3_get_ipc_logbuf();
              ipc_log_string(v25, "ipa_wigig %s:%d couldn't acquire idx\n", "ipa_wigig_conn_client", 1595);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v26 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v26, "ipa_wigig %s:%d couldn't acquire idx\n", "ipa_wigig_conn_client", 1595);
            }
          }
          else
          {
            v7 = v29;
            ipa_wigig_store_pipe_info(a1, v29);
            if ( !(unsigned int)ipa_wigig_send_msg(40, (const char *)v30, (__int64)(a1 + 69), *a2, 0) )
            {
              *(_BYTE *)(ipa_wigig_ctx + 910) |= ipa_wigig_pipe_to_bit_val(*a2);
              ipa_wigig_store_client_mac((unsigned int)*a2, a1 + 69);
              if ( ipa3_get_ipc_logbuf() )
              {
                v8 = ipa3_get_ipc_logbuf();
                ipc_log_string(v8, "ipa_wigig %s:%d exit\n", "ipa_wigig_conn_client", 1614);
              }
              result = ipa3_get_ipc_logbuf_low();
              if ( result )
              {
                v10 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v10, "ipa_wigig %s:%d exit\n", "ipa_wigig_conn_client", 1614);
                result = 0;
              }
              goto LABEL_61;
            }
            printk(&unk_3A5654, "ipa_wigig_conn_client");
            if ( ipa3_get_ipc_logbuf() )
            {
              v27 = ipa3_get_ipc_logbuf();
              ipc_log_string(v27, "ipa_wigig %s:%d couldn't send msg to IPACM\n", "ipa_wigig_conn_client", 1604);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v28 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v28, "ipa_wigig %s:%d couldn't send msg to IPACM\n", "ipa_wigig_conn_client", 1604);
            }
            ipa_wigig_clean_pipe_info(v7);
          }
          ipa3_disconn_wigig_pipe_i(*a2, 0, 0);
LABEL_60:
          result = 4294967274LL;
          goto LABEL_61;
        }
        printk(&unk_3D45BF, "ipa_wigig_conn_client");
        if ( ipa3_get_ipc_logbuf() )
        {
          v23 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v23,
            "ipa_wigig %s:%d fail to connect client. MAC [%X][%X][%X][%X][%X][%X]\n",
            "ipa_wigig_conn_client",
            1590,
            a1[69],
            a1[70],
            a1[71],
            a1[72],
            a1[73],
            a1[74]);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v24 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v24,
            "ipa_wigig %s:%d fail to connect client. MAC [%X][%X][%X][%X][%X][%X]\n",
            "ipa_wigig_conn_client",
            1590,
            a1[69],
            a1[70],
            a1[71],
            a1[72],
            a1[73],
            a1[74]);
          result = 4294967282LL;
          goto LABEL_61;
        }
LABEL_49:
        result = 4294967282LL;
        goto LABEL_61;
      }
      printk(&unk_3A8924, "ipa_wigig_conn_client");
      if ( ipa3_get_ipc_logbuf() )
      {
        v21 = ipa3_get_ipc_logbuf();
        ipc_log_string(v21, "ipa_wigig %s:%d couldn't get dev name\n", "ipa_wigig_conn_client", 1581);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_49;
      v22 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v22, "ipa_wigig %s:%d couldn't get dev name\n", "ipa_wigig_conn_client", 1581);
    }
    result = 4294967282LL;
    goto LABEL_61;
  }
  printk(&unk_3CE6D1, "ipa_wigig_conn_client");
  if ( ipa3_get_ipc_logbuf() )
  {
    v13 = ipa3_get_ipc_logbuf();
    ipc_log_string(v13, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_conn_client", 1558);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v14 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v14, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_conn_client", 1558);
  }
  result = 0xFFFFFFFFLL;
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}
