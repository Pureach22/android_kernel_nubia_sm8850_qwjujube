__int64 __fastcall rmnet_ipa3_query_tethering_stats_modem(__int64 a1, char a2)
{
  unsigned __int64 v2; // x22
  __int64 v4; // x19
  char *v5; // x0
  char *v6; // x20
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int data_stats; // w0
  _QWORD *v10; // x27
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  int v14; // w28
  __int64 v15; // x10
  __int64 v16; // x9
  __int64 v17; // x11
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  _QWORD *v23; // x27
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  int v27; // w28
  __int64 v28; // x10
  __int64 v29; // x9
  __int64 v30; // x11
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  unsigned int v35; // w22
  __int64 v36; // x0
  __int64 v37; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v39; // x23
  __int64 (__fastcall *v40)(_QWORD); // x0

  LOBYTE(v2) = a2;
  v4 = _kmalloc_cache_noprof(sg_next, 3520, 8);
  if ( v4 )
  {
    while ( 1 )
    {
      v5 = (char *)_kmalloc_cache_noprof(dma_alloc_attrs, 3520, 2664);
      v6 = v5;
      if ( !v5 )
        break;
      *(_QWORD *)v4 = 1;
      memset(v5, 0, 0xA68u);
      if ( (v2 & 1) != 0 )
      {
        *(_WORD *)(v4 + 4) = 257;
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(
            ipc_logbuf,
            "ipa-wan %s:%d reset the pipe stats\n",
            "rmnet_ipa3_query_tethering_stats_modem",
            4810);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipa-wan %s:%d reset the pipe stats\n",
            "rmnet_ipa3_query_tethering_stats_modem",
            4810);
        }
      }
      data_stats = ipa3_qmi_get_data_stats(v4, (unsigned __int16 *)v6);
      if ( data_stats )
      {
        v35 = data_stats;
        printk(&unk_3C209D, "rmnet_ipa3_query_tethering_stats_modem");
        if ( ipa3_get_ipc_logbuf() )
        {
          v36 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v36,
            "ipa-wan %s:%d can't get ipa_qmi_get_data_stats\n",
            "rmnet_ipa3_query_tethering_stats_modem",
            4815);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v37 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v37,
            "ipa-wan %s:%d can't get ipa_qmi_get_data_stats\n",
            "rmnet_ipa3_query_tethering_stats_modem",
            4815);
        }
        goto LABEL_51;
      }
      if ( !a1 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v33 = ipa3_get_ipc_logbuf();
          ipc_log_string(v33, "ipa-wan %s:%d only reset modem stats\n", "rmnet_ipa3_query_tethering_stats_modem", 4820);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v34 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v34, "ipa-wan %s:%d only reset modem stats\n", "rmnet_ipa3_query_tethering_stats_modem", 4820);
        }
        goto LABEL_50;
      }
      if ( v6[824] && *((_DWORD *)v6 + 207) )
      {
        v2 = 0;
        v10 = v6 + 864;
        while ( v2 != 21 )
        {
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v11 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v11,
              "ipa-wan %s:%d Check entry(%d) dl_dst_pipe(%d)\n",
              "rmnet_ipa3_query_tethering_stats_modem",
              4834,
              v2,
              *((_DWORD *)v10 - 8));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v12 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v12,
              "ipa-wan %s:%d dl_p_v4(%lu)v6(%lu)\n",
              "rmnet_ipa3_query_tethering_stats_modem",
              4838,
              *(v10 - 3),
              *(v10 - 1));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v13 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v13,
              "ipa-wan %s:%d dl_b_v4(%lu)v6(%lu)\n",
              "rmnet_ipa3_query_tethering_stats_modem",
              4841,
              *(v10 - 2),
              *v10);
          }
          if ( (ipa3_get_client_uplink(*((_DWORD *)v10 - 8)) & 1) == 0 )
          {
            v14 = *(_DWORD *)(a1 + 32);
            if ( v14 == (unsigned int)ipa3_get_client(*((_DWORD *)v10 - 8)) )
            {
              v15 = *(_QWORD *)(a1 + 64);
              v16 = *(_QWORD *)(a1 + 88);
              v17 = *(_QWORD *)(a1 + 96);
              *(_QWORD *)(a1 + 56) += *(v10 - 3);
              v18 = v16 + *(v10 - 1);
              v19 = v17 + *v10;
              *(_QWORD *)(a1 + 88) = v18;
              v20 = *(v10 - 2);
              *(_QWORD *)(a1 + 96) = v19;
              *(_QWORD *)(a1 + 64) = v15 + v20;
            }
          }
          ++v2;
          v10 += 5;
          if ( v2 >= *((unsigned int *)v6 + 207) )
            goto LABEL_24;
        }
      }
      else
      {
LABEL_24:
        if ( ipa3_get_ipc_logbuf() )
        {
          v21 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v21,
            "ipa-wan %s:%d v4_rx_p(%lu) v6_rx_p(%lu) v4_rx_b(%lu) v6_rx_b(%lu)\n",
            "rmnet_ipa3_query_tethering_stats_modem",
            4863,
            *(_QWORD *)(a1 + 56),
            *(_QWORD *)(a1 + 88),
            *(_QWORD *)(a1 + 64),
            *(_QWORD *)(a1 + 96));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v22 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v22,
            "ipa-wan %s:%d v4_rx_p(%lu) v6_rx_p(%lu) v4_rx_b(%lu) v6_rx_b(%lu)\n",
            "rmnet_ipa3_query_tethering_stats_modem",
            4863,
            *(_QWORD *)(a1 + 56),
            *(_QWORD *)(a1 + 88),
            *(_QWORD *)(a1 + 64),
            *(_QWORD *)(a1 + 96));
        }
        if ( !v6[12] || !*((_DWORD *)v6 + 4) )
        {
LABEL_42:
          if ( ipa3_get_ipc_logbuf() )
          {
            v31 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v31,
              "ipa-wan %s:%d tx_p_v4(%lu)v6(%lu)tx_b_v4(%lu) v6(%lu)\n",
              "rmnet_ipa3_query_tethering_stats_modem",
              4901,
              *(_QWORD *)(a1 + 40),
              *(_QWORD *)(a1 + 72),
              *(_QWORD *)(a1 + 48),
              *(_QWORD *)(a1 + 80));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v32 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v32,
              "ipa-wan %s:%d tx_p_v4(%lu)v6(%lu)tx_b_v4(%lu) v6(%lu)\n",
              "rmnet_ipa3_query_tethering_stats_modem",
              4901,
              *(_QWORD *)(a1 + 40),
              *(_QWORD *)(a1 + 72),
              *(_QWORD *)(a1 + 48),
              *(_QWORD *)(a1 + 80));
          }
LABEL_50:
          v35 = 0;
LABEL_51:
          kfree(v4);
          goto LABEL_59;
        }
        v2 = 0;
        v23 = v6 + 32;
        while ( v2 != 21 )
        {
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v24 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v24,
              "ipa-wan %s:%d Check entry(%d) ul_dst_pipe(%d)\n",
              "rmnet_ipa3_query_tethering_stats_modem",
              4872,
              v2,
              *((_DWORD *)v23 - 2));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v25 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v25,
              "ipa-wan %s:%d ul_p_v4(%lu)v6(%lu)\n",
              "rmnet_ipa3_query_tethering_stats_modem",
              4876,
              *v23,
              v23[2]);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v26 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v26,
              "ipa-wan %s:%d ul_b_v4(%lu)v6(%lu)\n",
              "rmnet_ipa3_query_tethering_stats_modem",
              4879,
              v23[1],
              v23[3]);
          }
          if ( (ipa3_get_client_uplink(*((_DWORD *)v23 - 2)) & 1) != 0 )
          {
            v27 = *(_DWORD *)(a1 + 32);
            if ( v27 == (unsigned int)ipa3_get_client(*((_DWORD *)v23 - 2)) )
            {
              v28 = *(_QWORD *)(a1 + 48);
              v29 = *(_QWORD *)(a1 + 72);
              v30 = *(_QWORD *)(a1 + 80);
              *(_QWORD *)(a1 + 40) += *v23;
              *(_QWORD *)(a1 + 72) = v29 + v23[2];
              *(_QWORD *)(a1 + 48) = v28 + v23[1];
              *(_QWORD *)(a1 + 80) = v30 + v23[3];
            }
          }
          ++v2;
          v23 += 5;
          if ( v2 >= *((unsigned int *)v6 + 4) )
            goto LABEL_42;
        }
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v39 = *(_QWORD *)(StatusReg + 80);
      v40 = sg_next;
      *(_QWORD *)(StatusReg + 80) = &rmnet_ipa3_query_tethering_stats_modem__alloc_tag;
      v4 = _kmalloc_cache_noprof(v40, 3520, 8);
      *(_QWORD *)(StatusReg + 80) = v39;
      if ( !v4 )
        return (unsigned int)-12;
    }
    v35 = -12;
    v6 = (char *)v4;
LABEL_59:
    kfree(v6);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v35;
}
