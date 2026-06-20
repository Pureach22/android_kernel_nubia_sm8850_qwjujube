__int64 __fastcall rmnet_ipa3_query_per_client_stats(unsigned int *a1)
{
  int v1; // w22
  __int64 v2; // x26
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  int v6; // w3
  unsigned int v7; // w3
  __int64 v8; // x8
  unsigned int lan_client_info; // w0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  int *v17; // x20
  unsigned __int16 *v18; // x0
  unsigned __int16 *v19; // x21
  __int64 v20; // x0
  const char *v21; // x4
  __int64 v22; // x0
  const char *v23; // x4
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w8
  __int64 v27; // x0
  __int64 v28; // x0
  unsigned int per_client_packet_stats; // w0
  unsigned __int64 v30; // x27
  char *v31; // x25
  _QWORD *v32; // x22
  int v33; // w10
  __int64 v34; // x11
  __int64 v35; // x8
  __int64 v36; // x12
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // x8
  _QWORD *v42; // x10
  __int16 v43; // w9
  __int64 v44; // x0
  const char *v45; // x4
  long double v46; // q0
  __int64 v47; // x0
  const char *v48; // x4
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  unsigned int v55; // w19
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  unsigned __int64 StatusReg; // x21
  int v64; // w23
  __int64 (__fastcall *v65)(_QWORD); // x0
  __int64 v66; // x22
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  unsigned int v71; // [xsp+1Ch] [xbp-4h]

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d Client MAC %02x:%02x:%02x:%02x:%02x:%02x\n",
      "rmnet_ipa3_query_per_client_stats",
      6274,
      *((unsigned __int8 *)a1 + 8),
      *((unsigned __int8 *)a1 + 9),
      *((unsigned __int8 *)a1 + 10),
      *((unsigned __int8 *)a1 + 11),
      *((unsigned __int8 *)a1 + 12),
      *((unsigned __int8 *)a1 + 13));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa-wan %s:%d Client MAC %02x:%02x:%02x:%02x:%02x:%02x\n",
      "rmnet_ipa3_query_per_client_stats",
      6274,
      *((unsigned __int8 *)a1 + 8),
      *((unsigned __int8 *)a1 + 9),
      *((unsigned __int8 *)a1 + 10),
      *((unsigned __int8 *)a1 + 11),
      *((unsigned __int8 *)a1 + 12),
      *((unsigned __int8 *)a1 + 13));
  }
  if ( *a1 >= 4 )
  {
    printk(&unk_3D6BB8, "rmnet_ipa3_query_per_client_stats");
    if ( ipa3_get_ipc_logbuf() )
    {
      v49 = ipa3_get_ipc_logbuf();
      ipc_log_string(v49, "ipa-wan %s:%d Invalid Device type: %d\n", "rmnet_ipa3_query_per_client_stats", 6279, *a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v50 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v50, "ipa-wan %s:%d Invalid Device type: %d\n", "rmnet_ipa3_query_per_client_stats", 6279, *a1);
    }
    return 4294967274LL;
  }
  v6 = *((unsigned __int8 *)a1 + 6);
  if ( v6 != 1 && v6 != 16 )
  {
    printk(&unk_3ED27E, "rmnet_ipa3_query_per_client_stats");
    if ( ipa3_get_ipc_logbuf() )
    {
      v53 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v53,
        "ipa-wan %s:%d Invalid number of clients: %d\n",
        "rmnet_ipa3_query_per_client_stats",
        6286,
        *((unsigned __int8 *)a1 + 6));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v54 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v54,
        "ipa-wan %s:%d Invalid number of clients: %d\n",
        "rmnet_ipa3_query_per_client_stats",
        6286,
        *((unsigned __int8 *)a1 + 6));
    }
    return 4294967274LL;
  }
  mutex_lock(rmnet_ipa3_ctx + 1200);
  v7 = *a1;
  if ( *a1 > 3 )
    goto LABEL_116;
  v8 = rmnet_ipa3_ctx + 172LL * v7;
  if ( *(_DWORD *)(v8 + 1248) == -1 )
  {
    if ( (unsigned int)__ratelimit(&rmnet_ipa3_query_per_client_stats__rs, "rmnet_ipa3_query_per_client_stats") )
    {
      printk(&unk_3D94BA, "rmnet_ipa3_query_per_client_stats");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_24:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v13 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v13,
            "ipa-wan %s:%d Device not initialized: %d\n",
            "rmnet_ipa3_query_per_client_stats",
            6295,
            *a1);
        }
        goto LABEL_26;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_24;
    }
    v12 = ipa3_get_ipc_logbuf();
    ipc_log_string(v12, "ipa-wan %s:%d Device not initialized: %d\n", "rmnet_ipa3_query_per_client_stats", 6295, *a1);
    goto LABEL_24;
  }
  v2 = v8 + 1248;
  if ( !*(_DWORD *)(v8 + 1256) )
  {
    printk(&unk_3F36CC, "rmnet_ipa3_query_per_client_stats");
    if ( ipa3_get_ipc_logbuf() )
    {
      v51 = ipa3_get_ipc_logbuf();
      ipc_log_string(v51, "ipa-wan %s:%d No clients connected: %d\n", "rmnet_ipa3_query_per_client_stats", 6302, *a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v52 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v52, "ipa-wan %s:%d No clients connected: %d\n", "rmnet_ipa3_query_per_client_stats", 6302, *a1);
    }
    goto LABEL_26;
  }
  if ( *((_BYTE *)a1 + 6) == 1 )
  {
    lan_client_info = rmnet_ipa3_get_lan_client_info(v7, a1 + 2);
    if ( (lan_client_info & 0x80000000) == 0 )
    {
      v1 = lan_client_info;
      if ( lan_client_info > 0x10 )
        goto LABEL_116;
      if ( *((_BYTE *)a1 + 5) && *(_BYTE *)(v2 + 8LL * lan_client_info + 19) )
      {
        if ( (unsigned int)__ratelimit(&rmnet_ipa3_query_per_client_stats__rs_129, "rmnet_ipa3_query_per_client_stats") )
        {
          printk(&unk_3B0A6D, "rmnet_ipa3_query_per_client_stats");
          if ( !ipa3_get_ipc_logbuf() )
          {
LABEL_19:
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v11 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v11,
                "ipa-wan %s:%d Client not inited. Try again.\n",
                "rmnet_ipa3_query_per_client_stats",
                6327);
            }
LABEL_34:
            mutex_unlock(rmnet_ipa3_ctx + 1200);
            return 4294967285LL;
          }
        }
        else if ( !ipa3_get_ipc_logbuf() )
        {
          goto LABEL_19;
        }
        v10 = ipa3_get_ipc_logbuf();
        ipc_log_string(v10, "ipa-wan %s:%d Client not inited. Try again.\n", "rmnet_ipa3_query_per_client_stats", 6327);
        goto LABEL_19;
      }
      goto LABEL_36;
    }
    printk(&unk_3A7CC8, "rmnet_ipa3_query_per_client_stats");
    if ( ipa3_get_ipc_logbuf() )
    {
      v58 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v58,
        "ipa-wan %s:%d Client info not available return.\n",
        "rmnet_ipa3_query_per_client_stats",
        6314);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v59 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v59,
        "ipa-wan %s:%d Client info not available return.\n",
        "rmnet_ipa3_query_per_client_stats",
        6314);
    }
LABEL_26:
    mutex_unlock(rmnet_ipa3_ctx + 1200);
    return 4294967274LL;
  }
  if ( *((_BYTE *)a1 + 5) && (rmnet_ipa3_check_any_client_inited(v7) & 1) != 0 )
  {
    if ( (unsigned int)__ratelimit(&rmnet_ipa3_query_per_client_stats__rs_132, "rmnet_ipa3_query_per_client_stats") )
    {
      printk(&unk_3B6215, "rmnet_ipa3_query_per_client_stats");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_32:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v16 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v16,
            "ipa-wan %s:%d CLient not inited. Try again.\n",
            "rmnet_ipa3_query_per_client_stats",
            6339);
        }
        goto LABEL_34;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_32;
    }
    v15 = ipa3_get_ipc_logbuf();
    ipc_log_string(v15, "ipa-wan %s:%d CLient not inited. Try again.\n", "rmnet_ipa3_query_per_client_stats", 6339);
    goto LABEL_32;
  }
  v1 = -1;
LABEL_36:
  v17 = (int *)_kmalloc_cache_noprof(kfree, 3520, 12);
  if ( v17 )
  {
    while ( 1 )
    {
      v18 = (unsigned __int16 *)_kmalloc_cache_noprof(dma_alloc_attrs, 3520, 3600);
      v19 = v18;
      if ( !v18 )
      {
        printk(&unk_3F91BF, "rmnet_ipa3_query_per_client_stats");
        if ( ipa3_get_ipc_logbuf() )
        {
          v69 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v69,
            "ipa-wan %s:%d Can't allocate memory for stats message\n",
            "rmnet_ipa3_query_per_client_stats",
            6356);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v70 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v70,
            "ipa-wan %s:%d Can't allocate memory for stats message\n",
            "rmnet_ipa3_query_per_client_stats",
            6356);
        }
        mutex_unlock(rmnet_ipa3_ctx + 1200);
        kfree(v17);
        return 4294967284LL;
      }
      v17[2] = 0;
      *(_QWORD *)v17 = 0;
      memset(v18, 0, 0xE10u);
      if ( ipa3_get_ipc_logbuf() )
      {
        v20 = ipa3_get_ipc_logbuf();
        if ( *((_BYTE *)a1 + 4) )
          v21 = "Yes";
        else
          v21 = "No";
        ipc_log_string(v20, "ipa-wan %s:%d Reset stats: %s", "rmnet_ipa3_query_per_client_stats", 6365, v21);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v22 = ipa3_get_ipc_logbuf_low();
        if ( *((_BYTE *)a1 + 4) )
          v23 = "Yes";
        else
          v23 = "No";
        ipc_log_string(v22, "ipa-wan %s:%d Reset stats: %s", "rmnet_ipa3_query_per_client_stats", 6365, v23);
      }
      if ( *((_BYTE *)a1 + 4) )
      {
        *((_WORD *)v17 + 4) = 257;
        if ( ipa3_get_ipc_logbuf() )
        {
          v24 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v24,
            "ipa-wan %s:%d fetch and reset the client stats\n",
            "rmnet_ipa3_query_per_client_stats",
            6370);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v25 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v25,
            "ipa-wan %s:%d fetch and reset the client stats\n",
            "rmnet_ipa3_query_per_client_stats",
            6370);
        }
      }
      v26 = *a1;
      *v17 = v1;
      if ( v26 <= 3 )
        break;
LABEL_116:
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v64 = v1;
      v65 = kfree;
      v66 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &rmnet_ipa3_query_per_client_stats__alloc_tag;
      v17 = (int *)_kmalloc_cache_noprof(v65, 3520, 12);
      *(_QWORD *)(StatusReg + 80) = v66;
      v1 = v64;
      if ( !v17 )
        goto LABEL_117;
    }
    v17[1] = *(_DWORD *)(rmnet_ipa3_ctx + 172LL * v26 + 1248);
    if ( ipa3_get_ipc_logbuf() )
    {
      v27 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v27,
        "ipa-wan %s:%d fetch the client stats for %d, %d\n",
        "rmnet_ipa3_query_per_client_stats",
        6378,
        *v17,
        v17[1]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v28 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v28,
        "ipa-wan %s:%d fetch the client stats for %d, %d\n",
        "rmnet_ipa3_query_per_client_stats",
        6378,
        *v17,
        v17[1]);
    }
    per_client_packet_stats = ipa3_qmi_get_per_client_packet_stats((__int64)v17, v19);
    if ( per_client_packet_stats )
    {
      v55 = per_client_packet_stats;
      printk(&unk_3E494B, "rmnet_ipa3_query_per_client_stats");
      if ( ipa3_get_ipc_logbuf() )
      {
        v56 = ipa3_get_ipc_logbuf();
        ipc_log_string(v56, "ipa-wan %s:%d can't get per client stats\n", "rmnet_ipa3_query_per_client_stats", 6382);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v57 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v57, "ipa-wan %s:%d can't get per client stats\n", "rmnet_ipa3_query_per_client_stats", 6382);
      }
      mutex_unlock(rmnet_ipa3_ctx + 1200);
      kfree(v17);
      kfree(v19);
      return v55;
    }
    else
    {
      v71 = v1;
      if ( v2 && *((_BYTE *)v19 + 4) && *((_DWORD *)v19 + 2) )
      {
        v30 = 0;
        v31 = (char *)(v19 + 20);
        v32 = a1 + 6;
        while ( 1 )
        {
          v33 = *((_DWORD *)v31 + 7);
          v34 = *((_QWORD *)v31 + 1);
          v35 = *(_QWORD *)v31 - *((_DWORD *)v31 + 6) * (unsigned int)*(unsigned __int8 *)(v2 + 4);
          v36 = *((_QWORD *)v31 - 1);
          *(v32 - 1) = *((_QWORD *)v31 - 2);
          *v32 = v35;
          v37 = v34 - v33 * (unsigned int)*(unsigned __int8 *)(v2 + 4);
          v32[1] = v36;
          v32[2] = v37;
          if ( ipa3_get_ipc_logbuf() )
          {
            v38 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v38,
              "ipa-wan %s:%d tx_b_v4(%lu)v6(%lu)rx_b_v4(%lu) v6(%lu)\n",
              "rmnet_ipa3_query_per_client_stats",
              6413,
              *(v32 - 1),
              v32[1],
              *v32,
              v32[2]);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v39 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v39,
              "ipa-wan %s:%d tx_b_v4(%lu)v6(%lu)rx_b_v4(%lu) v6(%lu)\n",
              "rmnet_ipa3_query_per_client_stats",
              6413,
              *(v32 - 1),
              v32[1],
              *v32,
              v32[2]);
          }
          v40 = *((unsigned int *)v31 - 6);
          if ( (unsigned int)v40 >= 0x10 )
            break;
          v41 = v2 + 12 + 8 * v40;
          v42 = v32 - 2;
          v43 = *(_WORD *)(v41 + 4);
          LODWORD(v41) = *(_DWORD *)v41;
          *((_WORD *)v42 + 2) = v43;
          *(_DWORD *)v42 = v41;
          if ( v30 <= 0xE )
          {
            ++v30;
            v31 += 56;
            v32 += 5;
            if ( v30 < *((unsigned int *)v19 + 2) )
              continue;
          }
          goto LABEL_70;
        }
        printk(&unk_3CDB66, "rmnet_ipa3_query_per_client_stats");
        if ( ipa3_get_ipc_logbuf() )
        {
          v60 = ipa3_get_ipc_logbuf();
          ipc_log_string(v60, "ipa-wan %s:%d Lan client index not valid.\n", "rmnet_ipa3_query_per_client_stats", 6420);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v61 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v61, "ipa-wan %s:%d Lan client index not valid.\n", "rmnet_ipa3_query_per_client_stats", 6420);
        }
        mutex_unlock(rmnet_ipa3_ctx + 1200);
        kfree(v17);
        v62 = kfree(v19);
        ((void (__fastcall *)(__int64))ipa_assert)(v62);
        return 4294967274LL;
      }
      else
      {
LABEL_70:
        if ( ipa3_get_ipc_logbuf() )
        {
          v44 = ipa3_get_ipc_logbuf();
          if ( *((_BYTE *)a1 + 5) )
            v45 = "Yes";
          else
            v45 = "No";
          ipc_log_string(v44, "ipa-wan %s:%d Disconnect clnt: %s", "rmnet_ipa3_query_per_client_stats", 6435, v45);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v47 = ipa3_get_ipc_logbuf_low();
          if ( *((_BYTE *)a1 + 5) )
            v48 = "Yes";
          else
            v48 = "No";
          v46 = ipc_log_string(v47, "ipa-wan %s:%d Disconnect clnt: %s", "rmnet_ipa3_query_per_client_stats", 6435, v48);
        }
        if ( *((_BYTE *)a1 + 5) )
          ((void (__fastcall *)(_QWORD, _QWORD, long double))rmnet_ipa3_delete_lan_client_info)(*a1, v71, v46);
        mutex_unlock(rmnet_ipa3_ctx + 1200);
        kfree(v17);
        kfree(v19);
        return 0;
      }
    }
  }
  else
  {
LABEL_117:
    printk(&unk_3F91BF, "rmnet_ipa3_query_per_client_stats");
    if ( ipa3_get_ipc_logbuf() )
    {
      v67 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v67,
        "ipa-wan %s:%d Can't allocate memory for stats message\n",
        "rmnet_ipa3_query_per_client_stats",
        6349);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v68 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v68,
        "ipa-wan %s:%d Can't allocate memory for stats message\n",
        "rmnet_ipa3_query_per_client_stats",
        6349);
    }
    mutex_unlock(rmnet_ipa3_ctx + 1200);
    return 4294967284LL;
  }
}
