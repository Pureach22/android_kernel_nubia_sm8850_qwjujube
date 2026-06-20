__int64 __fastcall rmnet_ipa3_query_per_client_stats_v2(unsigned int *a1)
{
  unsigned int v2; // w3
  int v3; // w3
  unsigned int v4; // w3
  __int64 v5; // x8
  int lan_client_info; // w20
  __int64 v7; // x0
  __int64 v8; // x0
  int v9; // w28
  signed int v10; // w21
  __int64 v11; // x8
  unsigned int v12; // w27
  unsigned __int8 *v13; // x22
  unsigned __int8 *v14; // x20
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  char v21; // w10
  int v22; // w9
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  unsigned int v29; // w8
  _DWORD *v30; // x9
  __int64 v31; // x27
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  const char *v45; // x4
  long double v46; // q0
  __int64 v47; // x0
  const char *v48; // x4
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  unsigned int v62; // [xsp+2Ch] [xbp-24h]
  __int64 v63; // [xsp+30h] [xbp-20h] BYREF
  __int64 v64; // [xsp+38h] [xbp-18h]
  _DWORD *v65; // [xsp+40h] [xbp-10h]
  __int64 v66; // [xsp+48h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v64 = 0;
  v65 = nullptr;
  v63 = 0;
  if ( v2 >= 4 )
  {
    printk(&unk_3D6BB8, "rmnet_ipa3_query_per_client_stats_v2");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa-wan %s:%d Invalid Device type: %d\n",
        "rmnet_ipa3_query_per_client_stats_v2",
        6642,
        *a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa-wan %s:%d Invalid Device type: %d\n",
        "rmnet_ipa3_query_per_client_stats_v2",
        6642,
        *a1);
LABEL_116:
      v12 = -22;
      goto LABEL_98;
    }
LABEL_117:
    v12 = -22;
    goto LABEL_98;
  }
  v3 = *((unsigned __int8 *)a1 + 6);
  if ( v3 != 1 && v3 != 16 )
  {
    printk(&unk_3ED27E, "rmnet_ipa3_query_per_client_stats_v2");
    if ( ipa3_get_ipc_logbuf() )
    {
      v56 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v56,
        "ipa-wan %s:%d Invalid number of clients: %d\n",
        "rmnet_ipa3_query_per_client_stats_v2",
        6649,
        *((unsigned __int8 *)a1 + 6));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v57 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v57,
        "ipa-wan %s:%d Invalid number of clients: %d\n",
        "rmnet_ipa3_query_per_client_stats_v2",
        6649,
        *((unsigned __int8 *)a1 + 6));
      goto LABEL_116;
    }
    goto LABEL_117;
  }
  mutex_lock(rmnet_ipa3_ctx + 1200);
  v4 = *a1;
  if ( *a1 >= 4 )
    goto LABEL_127;
  v5 = rmnet_ipa3_ctx + 172LL * v4;
  if ( *(_DWORD *)(v5 + 1248) == -1 )
  {
    printk(&unk_3D94BA, "rmnet_ipa3_query_per_client_stats_v2");
    if ( ipa3_get_ipc_logbuf() )
    {
      v52 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v52,
        "ipa-wan %s:%d Device not initialized: %d\n",
        "rmnet_ipa3_query_per_client_stats_v2",
        6658,
        *a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v53 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v53,
        "ipa-wan %s:%d Device not initialized: %d\n",
        "rmnet_ipa3_query_per_client_stats_v2",
        6658,
        *a1);
    }
    goto LABEL_111;
  }
  if ( !*(_DWORD *)(v5 + 1256) )
  {
    printk(&unk_3F36CC, "rmnet_ipa3_query_per_client_stats_v2");
    if ( ipa3_get_ipc_logbuf() )
    {
      v54 = ipa3_get_ipc_logbuf();
      ipc_log_string(v54, "ipa-wan %s:%d No clients connected: %d\n", "rmnet_ipa3_query_per_client_stats_v2", 6665, *a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v55 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v55, "ipa-wan %s:%d No clients connected: %d\n", "rmnet_ipa3_query_per_client_stats_v2", 6665, *a1);
    }
    goto LABEL_111;
  }
  if ( *((_BYTE *)a1 + 6) == 1 )
  {
    lan_client_info = rmnet_ipa3_get_lan_client_info(v4, (unsigned __int8 *)a1 + 8);
    if ( (lan_client_info & 0x80000000) == 0 )
    {
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_11;
      goto LABEL_10;
    }
    printk(&unk_3A7CC8, "rmnet_ipa3_query_per_client_stats_v2");
    if ( ipa3_get_ipc_logbuf() )
    {
      v58 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v58,
        "ipa-wan %s:%d Client info not available return.\n",
        "rmnet_ipa3_query_per_client_stats_v2",
        6676);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v59 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v59,
        "ipa-wan %s:%d Client info not available return.\n",
        "rmnet_ipa3_query_per_client_stats_v2",
        6676);
    }
LABEL_111:
    mutex_unlock(rmnet_ipa3_ctx + 1200);
    v12 = -22;
    goto LABEL_98;
  }
  if ( *((_BYTE *)a1 + 5) && (rmnet_ipa3_check_any_client_inited(v4) & 1) != 0 )
  {
    printk(&unk_3B6215, "rmnet_ipa3_query_per_client_stats_v2");
    if ( ipa3_get_ipc_logbuf() )
    {
      v60 = ipa3_get_ipc_logbuf();
      ipc_log_string(v60, "ipa-wan %s:%d CLient not inited. Try again.\n", "rmnet_ipa3_query_per_client_stats_v2", 6688);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v61 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v61, "ipa-wan %s:%d CLient not inited. Try again.\n", "rmnet_ipa3_query_per_client_stats_v2", 6688);
    }
    mutex_unlock(rmnet_ipa3_ctx + 1200);
    v12 = -11;
    goto LABEL_98;
  }
  lan_client_info = -1;
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_10:
    v7 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v7,
      "ipa-wan %s:%d Query stats for client index (0x%x)\n",
      "rmnet_ipa3_query_per_client_stats_v2",
      6696,
      lan_client_info);
  }
LABEL_11:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v8 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v8,
      "ipa-wan %s:%d Query stats for client index (0x%x)\n",
      "rmnet_ipa3_query_per_client_stats_v2",
      6696,
      lan_client_info);
  }
  v62 = lan_client_info;
  if ( *a1 > 4 )
LABEL_127:
    __break(0x5512u);
  if ( lan_client_info == -1 )
    v9 = 16;
  else
    v9 = lan_client_info + 1;
  if ( lan_client_info == -1 )
    v10 = 0;
  else
    v10 = lan_client_info;
  if ( v10 < v9 )
  {
    v11 = 172LL * *a1;
    v12 = 1;
    v13 = (unsigned __int8 *)(v11 + 2LL * v10 + rmnet_ipa3_ctx + 1389);
    v14 = (unsigned __int8 *)(v11 + 8LL * v10 + rmnet_ipa3_ctx + 1260);
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( !v14[7] && !*((_BYTE *)a1 + 5) )
        goto LABEL_24;
      if ( ipa3_get_ipc_logbuf() )
      {
        v15 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v15,
          "ipa-wan %s:%d Client MAC %02x:%02x:%02x:%02x:%02x:%02x\n",
          "rmnet_ipa3_query_per_client_stats_v2",
          6720,
          *v14,
          v14[1],
          v14[2],
          v14[3],
          v14[4],
          v14[5]);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v16 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v16,
          "ipa-wan %s:%d Client MAC %02x:%02x:%02x:%02x:%02x:%02x\n",
          "rmnet_ipa3_query_per_client_stats_v2",
          6720,
          *v14,
          v14[1],
          v14[2],
          v14[3],
          v14[4],
          v14[5]);
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v17 = ipa3_get_ipc_logbuf();
        ipc_log_string(v17, "ipa-wan %s:%d Lan client %d inited\n", "rmnet_ipa3_query_per_client_stats_v2", 6721, v10);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v18 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v18, "ipa-wan %s:%d Lan client %d inited\n", "rmnet_ipa3_query_per_client_stats_v2", 6721, v10);
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v19 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v19,
          "ipa-wan %s:%d Query stats ul/dl indices = %u/%u\n",
          "rmnet_ipa3_query_per_client_stats_v2",
          6724,
          *(v13 - 1),
          *v13);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v20 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v20,
          "ipa-wan %s:%d Query stats ul/dl indices = %u/%u\n",
          "rmnet_ipa3_query_per_client_stats_v2",
          6724,
          *(v13 - 1),
          *v13);
      }
      v64 = 0;
      v65 = nullptr;
      v21 = *((_BYTE *)a1 + 4);
      v63 = 0;
      LOBYTE(v63) = *(v13 - 1);
      v22 = *v13;
      BYTE2(v63) = v21;
      BYTE1(v63) = v22;
      if ( v22 - (unsigned __int8)v63 == 1 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v23 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v23,
            "ipa-wan %s:%d  Start/End %u/%u, num counters = %d\n",
            "rmnet_ipa_get_hw_fnr_stats_v2",
            5972,
            (unsigned __int8)v63,
            BYTE1(v63),
            2);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v24 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v24,
            "ipa-wan %s:%d  Start/End %u/%u, num counters = %d\n",
            "rmnet_ipa_get_hw_fnr_stats_v2",
            5972,
            (unsigned __int8)v63,
            BYTE1(v63),
            2);
        }
        v65 = (_DWORD *)_kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 32);
        if ( v65 )
        {
          if ( !(unsigned int)ipa_get_flt_rt_stats((unsigned __int8 *)&v63) )
          {
            if ( ipa3_get_ipc_logbuf() )
            {
              v25 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v25,
                "ipa-wan %s:%d ul: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                "rmnet_ipa_get_hw_fnr_stats_v2",
                5991,
                *((_QWORD *)v65 + 1),
                *v65,
                v65[1]);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v26 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v26,
                "ipa-wan %s:%d ul: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                "rmnet_ipa_get_hw_fnr_stats_v2",
                5991,
                *((_QWORD *)v65 + 1),
                *v65,
                v65[1]);
            }
            if ( ipa3_get_ipc_logbuf() )
            {
              v27 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v27,
                "ipa-wan %s:%d dl: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                "rmnet_ipa_get_hw_fnr_stats_v2",
                5995,
                *((_QWORD *)v65 + 3),
                v65[4],
                v65[5]);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v28 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v28,
                "ipa-wan %s:%d dl: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                "rmnet_ipa_get_hw_fnr_stats_v2",
                5995,
                *((_QWORD *)v65 + 3),
                v65[4],
                v65[5]);
            }
            if ( *((_BYTE *)a1 + 6) == 1 )
              v29 = 0;
            else
              v29 = v10;
            if ( v29 > 0xF )
              goto LABEL_127;
            v30 = v65;
            v31 = (__int64)&a1[10 * v29 + 2];
            *(_QWORD *)(v31 + 8) = *((_QWORD *)v65 + 1);
            *(_QWORD *)(v31 + 16) = *((_QWORD *)v30 + 3);
            LODWORD(v30) = *(_DWORD *)v14;
            *(_WORD *)(v31 + 4) = *((_WORD *)v14 + 2);
            *(_DWORD *)v31 = (_DWORD)v30;
            if ( ipa3_get_ipc_logbuf() )
            {
              v32 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v32,
                "ipa-wan %s:%d Client ipv4_tx_bytes = %llu, ipv4_rx_bytes = %llu\n",
                "rmnet_ipa3_query_per_client_stats_v2",
                6752,
                *(_QWORD *)(v31 + 8),
                *(_QWORD *)(v31 + 16));
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v33 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v33,
                "ipa-wan %s:%d Client ipv4_tx_bytes = %llu, ipv4_rx_bytes = %llu\n",
                "rmnet_ipa3_query_per_client_stats_v2",
                6752,
                *(_QWORD *)(v31 + 8),
                *(_QWORD *)(v31 + 16));
            }
            v12 = 0;
            goto LABEL_23;
          }
          printk(&unk_3B0A9C, "rmnet_ipa_get_hw_fnr_stats_v2");
          v36 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v37 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v37 )
            {
              ipc_log_string(v37, "ipa %s:%d Failed to request stats from h/w\n", "rmnet_ipa_get_hw_fnr_stats_v2", 5984);
              v36 = ipa3_ctx;
            }
            v38 = *(_QWORD *)(v36 + 34160);
            if ( v38 )
              ipc_log_string(v38, "ipa %s:%d Failed to request stats from h/w\n", "rmnet_ipa_get_hw_fnr_stats_v2", 5984);
          }
        }
        else
        {
          printk(&unk_3CAD12, "rmnet_ipa_get_hw_fnr_stats_v2");
          v39 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v40 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v40 )
            {
              ipc_log_string(
                v40,
                "ipa %s:%d Failed to allocate memory for query stats\n",
                "rmnet_ipa_get_hw_fnr_stats_v2",
                5979);
              v39 = ipa3_ctx;
            }
            v41 = *(_QWORD *)(v39 + 34160);
            if ( v41 )
              ipc_log_string(
                v41,
                "ipa %s:%d Failed to allocate memory for query stats\n",
                "rmnet_ipa_get_hw_fnr_stats_v2",
                5979);
          }
        }
      }
      else
      {
        printk(&unk_3D0E29, "rmnet_ipa_get_hw_fnr_stats_v2");
        if ( ipa3_get_ipc_logbuf() )
        {
          v34 = ipa3_get_ipc_logbuf();
          ipc_log_string(v34, "ipa-wan %s:%d Dont support more than 2 counter\n", "rmnet_ipa_get_hw_fnr_stats_v2", 5967);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v35 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v35, "ipa-wan %s:%d Dont support more than 2 counter\n", "rmnet_ipa_get_hw_fnr_stats_v2", 5967);
        }
      }
      printk(&unk_3AACF1, "rmnet_ipa3_query_per_client_stats_v2");
      if ( ipa3_get_ipc_logbuf() )
      {
        v42 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v42,
          "ipa-wan %s:%d Failed: Client type %d, idx %d\n",
          "rmnet_ipa3_query_per_client_stats_v2",
          6730,
          *a1,
          v10);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v43 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v43,
          "ipa-wan %s:%d Failed: Client type %d, idx %d\n",
          "rmnet_ipa3_query_per_client_stats_v2",
          6730,
          *a1,
          v10);
      }
LABEL_23:
      kfree(v65);
LABEL_24:
      ++v10;
      v13 += 2;
      v14 += 8;
      if ( v9 == v10 )
        goto LABEL_85;
    }
  }
  v12 = 1;
LABEL_85:
  if ( ipa3_get_ipc_logbuf() )
  {
    v44 = ipa3_get_ipc_logbuf();
    if ( *((_BYTE *)a1 + 5) )
      v45 = "Yes";
    else
      v45 = "No";
    ipc_log_string(v44, "ipa-wan %s:%d Disconnect clnt: %s", "rmnet_ipa3_query_per_client_stats_v2", 6760, v45);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v47 = ipa3_get_ipc_logbuf_low();
    if ( *((_BYTE *)a1 + 5) )
      v48 = "Yes";
    else
      v48 = "No";
    v46 = ipc_log_string(v47, "ipa-wan %s:%d Disconnect clnt: %s", "rmnet_ipa3_query_per_client_stats_v2", 6760, v48);
  }
  if ( *((_BYTE *)a1 + 5) )
    ((void (__fastcall *)(_QWORD, _QWORD, long double))rmnet_ipa3_delete_lan_client_info)(*a1, v62, v46);
  mutex_unlock(rmnet_ipa3_ctx + 1200);
LABEL_98:
  _ReadStatusReg(SP_EL0);
  return v12;
}
