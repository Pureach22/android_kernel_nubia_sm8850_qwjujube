__int64 __fastcall rmnet_shs_wq_update_hash_stats_debug(__int64 result, __int64 a2)
{
  unsigned int v2; // w8
  bool v3; // nf
  int v4; // w11
  int v5; // w8
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8

  if ( rmnet_shs_stats_enabled )
  {
    if ( result && a2 )
    {
      v2 = *(_DWORD *)(result + 312);
      if ( (v2 & 0x80000000) != 0 )
      {
        v3 = -rmnet_shs_flow_dbg_stats_idx_cnt < 0;
        v4 = rmnet_shs_flow_dbg_stats_idx_cnt & 0x1F;
        v5 = -rmnet_shs_flow_dbg_stats_idx_cnt++ & 0x1F;
        if ( v3 )
          v2 = v4;
        else
          v2 = -v5;
        *(_DWORD *)(result + 312) = v2;
      }
      if ( v2 > 0x1F )
        goto LABEL_24;
      rmnet_shs_flow_hash[v2] = *(unsigned int *)(result + 300);
      v6 = *(unsigned int *)(result + 312);
      if ( (unsigned int)v6 > 0x1F )
        goto LABEL_24;
      rmnet_shs_flow_proto[v6] = *(unsigned __int16 *)(a2 + 220);
      v7 = *(unsigned int *)(result + 312);
      if ( (unsigned int)v7 > 0x1F )
        goto LABEL_24;
      rmnet_shs_flow_inactive_tsec[v7] = *(_QWORD *)(result + 128) / 1000000000LL;
      v8 = *(unsigned int *)(result + 312);
      if ( (unsigned int)v8 > 0x1F )
        goto LABEL_24;
      rmnet_shs_flow_rx_bps[v8] = *(_QWORD *)(result + 168);
      v9 = *(unsigned int *)(result + 312);
      if ( (unsigned int)v9 > 0x1F )
        goto LABEL_24;
      rmnet_shs_flow_rx_pps[v9] = *(_QWORD *)(result + 160);
      v10 = *(unsigned int *)(result + 312);
      if ( (unsigned int)v10 > 0x1F )
        goto LABEL_24;
      rmnet_shs_flow_rx_bytes[v10] = *(_QWORD *)(result + 144);
      v11 = *(unsigned int *)(result + 312);
      if ( (unsigned int)v11 > 0x1F )
        goto LABEL_24;
      rmnet_shs_flow_rx_pkts[v11] = *(_QWORD *)(result + 136);
      v12 = *(unsigned int *)(result + 312);
      if ( (unsigned int)v12 > 0x1F )
        goto LABEL_24;
      rmnet_shs_flow_cpu[v12] = *(unsigned __int16 *)(result + 318);
      v13 = *(unsigned int *)(result + 312);
      if ( (unsigned int)v13 > 0x1F
        || (rmnet_shs_flow_cpu_recommended[v13] = *(unsigned __int16 *)(result + 316),
            v14 = *(unsigned int *)(result + 312),
            (unsigned int)v14 > 0x1F)
        || (rmnet_shs_flow_silver_to_gold[v14] = *(_QWORD *)(result + 8),
            v15 = *(unsigned int *)(result + 312),
            (unsigned int)v15 > 0x1F)
        || (rmnet_shs_flow_gold_to_silver[v15] = *(_QWORD *)(result + 16),
            v16 = *(unsigned int *)(result + 312),
            (unsigned int)v16 > 0x1F) )
      {
LABEL_24:
        __break(0x5512u);
        return rmnet_shs_wq_is_hash_rx_new_pkt();
      }
      else
      {
        rmnet_shs_flow_gold_balance[v16] = *(_QWORD *)(result + 24);
      }
    }
    else
    {
      ++qword_1A448;
    }
  }
  return result;
}
