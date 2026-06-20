__int64 __fastcall handle3_egress_format(__int64 a1, __int64 a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 result; // x0
  __int64 v7; // x22
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  int v12; // w20
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned int v21; // w0
  unsigned int v22; // w19
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  unsigned int v27; // w0
  unsigned int v28; // w19
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d get RMNET_IOCTL_SET_EGRESS_DATA_FORMAT %x\n",
      "handle3_egress_format",
      1645,
      *(_DWORD *)(a2 + 4));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa-wan %s:%d get RMNET_IOCTL_SET_EGRESS_DATA_FORMAT %x\n",
      "handle3_egress_format",
      1645,
      *(_DWORD *)(a2 + 4));
  }
  if ( *(_BYTE *)(rmnet_ipa3_ctx + 1992) == 1 )
  {
    *(_BYTE *)(rmnet_ipa3_ctx + 1984) = 0;
    result = ipa3_qmi_set_aggr_info(1);
    *(_BYTE *)(rmnet_ipa3_ctx + 1993) = 1;
    return result;
  }
  if ( (unsigned int)ipa_get_ep_mapping(34) != -1 )
  {
    v7 = rmnet_ipa3_ctx;
    if ( (*(_BYTE *)(a2 + 4) & 0x10) != 0 )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v10 = ipa3_get_ipc_logbuf();
        ipc_log_string(v10, "ipa-wan %s:%d UL chksum set\n", "handle3_egress_format", 1667);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v11 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v11, "ipa-wan %s:%d UL chksum set\n", "handle3_egress_format", 1667);
      }
      *(_DWORD *)(v7 + 20) = 8;
      *(_DWORD *)(v7 + 160) = 1;
      *(_BYTE *)(v7 + 164) = 1;
    }
    else
    {
      *(_DWORD *)(rmnet_ipa3_ctx + 20) = 4;
    }
    v12 = *(_DWORD *)(a2 + 4);
    v13 = ipa3_get_ipc_logbuf();
    if ( (v12 & 4) != 0 )
    {
      if ( v13 )
      {
        v16 = ipa3_get_ipc_logbuf();
        ipc_log_string(v16, "ipa-wan %s:%d WAN UL Aggregation enabled\n", "handle3_egress_format", 1677);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v17 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v17, "ipa-wan %s:%d WAN UL Aggregation enabled\n", "handle3_egress_format", 1677);
      }
      *(_BYTE *)(v7 + 137) = 0;
      *(_DWORD *)(v7 + 40) = 2;
      *(_QWORD *)(v7 + 104) = 0x600000002LL;
      *(_WORD *)(v7 + 72) = 1;
      *(_DWORD *)(v7 + 68) = 0;
      *(_QWORD *)(v7 + 56) = 2;
      *(_BYTE *)(v7 + 64) = 1;
    }
    else
    {
      if ( v13 )
      {
        v14 = ipa3_get_ipc_logbuf();
        ipc_log_string(v14, "ipa-wan %s:%d WAN UL Aggregation disabled\n", "handle3_egress_format", 1698);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v15 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v15, "ipa-wan %s:%d WAN UL Aggregation disabled\n", "handle3_egress_format", 1698);
      }
      *(_DWORD *)(v7 + 104) = 0;
    }
    *(_BYTE *)(v7 + 256) = 0;
    *(_QWORD *)(v7 + 24) = 1;
    *(_QWORD *)(v7 + 96) = 0x2200000000LL;
    *(_QWORD *)(v7 + 200) = 0x100000000022LL;
    v18 = rmnet_ipa3_ctx;
    *(_QWORD *)(v7 + 208) = a1;
    *(_QWORD *)(v7 + 216) = apps_ipa_tx_complete_notify;
    mutex_lock(v18 + 1088);
    if ( *(_DWORD *)(rmnet_ipa3_ctx + 1056) )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v19 = ipa3_get_ipc_logbuf();
        ipc_log_string(v19, "ipa-wan %s:%d In SSR sequence/recovery\n", "handle3_egress_format", 1717);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v20 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v20, "ipa-wan %s:%d In SSR sequence/recovery\n", "handle3_egress_format", 1717);
      }
      mutex_unlock(rmnet_ipa3_ctx + 1088);
      return 4294967282LL;
    }
    v21 = ipa_setup_sys_pipe(v7 + 8, (unsigned int *)(rmnet_ipa3_ctx + 1080));
    if ( v21 )
    {
      v22 = v21;
      if ( (unsigned int)__ratelimit(&handle3_egress_format__rs, "handle3_egress_format") )
      {
        printk(&unk_3ADFA9, "handle3_egress_format");
        if ( !ipa3_get_ipc_logbuf() )
          goto LABEL_41;
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_41:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v24 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v24, "ipa-wan %s:%d failed to setup egress endpoint\n", "handle3_egress_format", 1724);
        }
        mutex_unlock(rmnet_ipa3_ctx + 1088);
        return v22;
      }
      v23 = ipa3_get_ipc_logbuf();
      ipc_log_string(v23, "ipa-wan %s:%d failed to setup egress endpoint\n", "handle3_egress_format", 1724);
      goto LABEL_41;
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v25 = ipa3_get_ipc_logbuf();
      ipc_log_string(v25, "ipa-wan %s:%d engress WAN pipe setup successfully\n", "handle3_egress_format", 1728);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v26 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v26, "ipa-wan %s:%d engress WAN pipe setup successfully\n", "handle3_egress_format", 1728);
    }
    if ( *(_BYTE *)(ipa3_ctx + 48858) == 1 )
    {
      v27 = ipa3_setup_apps_low_lat_prod_pipe(0, nullptr);
      if ( v27 )
      {
        v28 = v27;
        if ( (unsigned int)__ratelimit(&handle3_egress_format__rs_572, "handle3_egress_format") )
        {
          printk(&unk_3C5326, "handle3_egress_format");
          if ( !ipa3_get_ipc_logbuf() )
          {
LABEL_54:
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v30 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v30,
                "ipa-wan %s:%d failed to setup egress low lat endpoint\n",
                "handle3_egress_format",
                1733);
            }
LABEL_61:
            mutex_unlock(rmnet_ipa3_ctx + 1088);
            if ( !*(_DWORD *)(rmnet_ipa3_ctx + 1036) )
            {
              if ( ipa3_get_ipc_logbuf() )
              {
                v36 = ipa3_get_ipc_logbuf();
                ipc_log_string(v36, "ipa-wan %s:%d no UL-rules\n", "handle3_egress_format", 1757);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v37 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v37, "ipa-wan %s:%d no UL-rules\n", "handle3_egress_format", 1757);
              }
              goto LABEL_74;
            }
            if ( (*(_BYTE *)(ipa3_qmi_ctx + 28860) & 1) == 0 )
            {
              v33 = mutex_lock(rmnet_ipa3_ctx + 1136);
              v28 = ipa3_wwan_add_ul_flt_rule_to_ipa(v33);
              mutex_unlock(rmnet_ipa3_ctx + 1136);
            }
            if ( !v28 )
            {
              result = 0;
              *(_BYTE *)(rmnet_ipa3_ctx + 1049) = 1;
              goto LABEL_76;
            }
            if ( (unsigned int)__ratelimit(&handle3_egress_format__rs_574, "handle3_egress_format") )
            {
              printk(&unk_3ED443, "handle3_egress_format");
              if ( !ipa3_get_ipc_logbuf() )
              {
LABEL_68:
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v35 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(v35, "ipa-wan %s:%d install UL rules failed\n", "handle3_egress_format", 1752);
                }
LABEL_74:
                result = v28;
LABEL_76:
                *(_BYTE *)(rmnet_ipa3_ctx + 1048) = 1;
                return result;
              }
            }
            else if ( !ipa3_get_ipc_logbuf() )
            {
              goto LABEL_68;
            }
            v34 = ipa3_get_ipc_logbuf();
            ipc_log_string(v34, "ipa-wan %s:%d install UL rules failed\n", "handle3_egress_format", 1752);
            goto LABEL_68;
          }
        }
        else if ( !ipa3_get_ipc_logbuf() )
        {
          goto LABEL_54;
        }
        v29 = ipa3_get_ipc_logbuf();
        ipc_log_string(v29, "ipa-wan %s:%d failed to setup egress low lat endpoint\n", "handle3_egress_format", 1733);
        goto LABEL_54;
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v31 = ipa3_get_ipc_logbuf();
        ipc_log_string(v31, "ipa-wan %s:%d engress low lat pipe setup successfully\n", "handle3_egress_format", 1737);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v32 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v32, "ipa-wan %s:%d engress low lat pipe setup successfully\n", "handle3_egress_format", 1737);
      }
    }
    v28 = 0;
    goto LABEL_61;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v8 = ipa3_get_ipc_logbuf();
    ipc_log_string(v8, "ipa-wan %s:%d Embedded datapath not supported\n", "handle3_egress_format", 1661);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v9 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v9, "ipa-wan %s:%d Embedded datapath not supported\n", "handle3_egress_format", 1661);
  }
  return 4294967282LL;
}
