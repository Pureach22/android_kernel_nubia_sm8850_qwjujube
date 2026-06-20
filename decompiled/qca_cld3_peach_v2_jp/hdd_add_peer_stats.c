__int64 __fastcall hdd_add_peer_stats(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  __int64 v13; // x21
  __int64 v14; // x22
  _WORD *v15; // x22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w21
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 result; // x0
  unsigned __int8 v28; // w23
  const char *v29; // x2
  __int64 v30; // x21
  __int64 v31; // x22
  _WORD *v32; // x22
  unsigned __int8 v33; // w23
  int v34; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = *(_DWORD *)(a2 + 228);
  if ( (unsigned int)nla_put(a1, 4, 4, &v34) )
  {
    v12 = "%s: Failed to put rx_retry_cnt";
    goto LABEL_23;
  }
  v34 = *(_DWORD *)(a2 + 232);
  if ( (unsigned int)nla_put(a1, 5, 4, &v34) )
  {
    v12 = "%s: Failed to put rx_mc_bc_cnt";
    goto LABEL_23;
  }
  v34 = *(_DWORD *)(a2 + 236);
  if ( (unsigned int)nla_put(a1, 6, 4, &v34) )
  {
    v12 = "%s: Failed to put tx_retry_succeed";
    goto LABEL_23;
  }
  v34 = *(_DWORD *)(a2 + 240);
  if ( (unsigned int)nla_put(a1, 7, 4, &v34) )
  {
    v12 = "%s: Failed to put tx_retry_exhaust";
    goto LABEL_23;
  }
  v34 = *(_DWORD *)(a2 + 244);
  if ( (unsigned int)nla_put(a1, 8, 4, &v34) )
  {
    v12 = "%s: Failed to put tx_total_fw";
    goto LABEL_23;
  }
  v34 = *(_DWORD *)(a2 + 248);
  if ( (unsigned int)nla_put(a1, 9, 4, &v34) )
  {
    v12 = "%s: Failed to put tx_retry_fw";
    goto LABEL_23;
  }
  v34 = *(_DWORD *)(a2 + 252);
  if ( (unsigned int)nla_put(a1, 10, 4, &v34) )
  {
    v12 = "%s: Failed to put tx_retry_exhaust_fw";
    goto LABEL_23;
  }
  v34 = *(_DWORD *)(a2 + 256);
  if ( (unsigned int)nla_put(a1, 20, 4, &v34) )
  {
    v12 = "%s: Failed to put rx_fcs_count";
    goto LABEL_23;
  }
  v13 = *(_QWORD *)(a1 + 216);
  v14 = *(unsigned int *)(a1 + 208);
  if ( (nla_put(a1, 32819, 0, 0) & 0x80000000) != 0 || (v15 = (_WORD *)(v13 + v14)) == nullptr )
  {
    v12 = "%s: nla nest start for tx packets fail";
  }
  else
  {
    if ( *(_DWORD *)(a2 + 468) )
    {
      v34 = **(_DWORD **)(a2 + 480);
      if ( (unsigned int)nla_put(a1, 51, 4, &v34) )
      {
        v24 = 0;
LABEL_32:
        v29 = "%s: Failed to put tx_rate_count for MCS[%d]";
LABEL_33:
        qdf_trace_msg(0x33u, 2u, v29, v16, v17, v18, v19, v20, v21, v22, v23, "hdd_add_peer_stats", v24);
        v25 = *(_QWORD *)(a2 + 480);
        if ( !v25 )
          goto LABEL_25;
        goto LABEL_24;
      }
      v28 = 0;
      while ( 1 )
      {
        v24 = ++v28;
        if ( *(_DWORD *)(a2 + 468) <= (unsigned int)v28 )
          break;
        v34 = *(_DWORD *)(*(_QWORD *)(a2 + 480) + 4LL * v28);
        if ( (unsigned int)nla_put(a1, 51, 4, &v34) )
          goto LABEL_32;
      }
    }
    *v15 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v15;
    v30 = *(_QWORD *)(a1 + 216);
    v31 = *(unsigned int *)(a1 + 208);
    if ( (nla_put(a1, 32820, 0, 0) & 0x80000000) == 0 )
    {
      v32 = (_WORD *)(v30 + v31);
      if ( v32 )
      {
        if ( *(_DWORD *)(a2 + 472) )
        {
          v34 = **(_DWORD **)(a2 + 488);
          if ( (unsigned int)nla_put(a1, 51, 4, &v34) )
          {
            v24 = 0;
LABEL_44:
            v29 = "%s: Failed to put rx_rate_count for MCS[%d]";
            goto LABEL_33;
          }
          v33 = 0;
          while ( 1 )
          {
            v24 = ++v33;
            if ( *(_DWORD *)(a2 + 472) <= (unsigned int)v33 )
              break;
            v34 = *(_DWORD *)(*(_QWORD *)(a2 + 488) + 4LL * v33);
            if ( (unsigned int)nla_put(a1, 51, 4, &v34) )
              goto LABEL_44;
          }
        }
        *v32 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v32;
        hdd_free_tx_rx_pkts_per_mcs(a2);
        result = 0;
        goto LABEL_28;
      }
    }
    v12 = "%s: nla nest start for rx packets fail";
  }
LABEL_23:
  qdf_trace_msg(0x33u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "hdd_add_peer_stats");
  v25 = *(_QWORD *)(a2 + 480);
  if ( v25 )
  {
LABEL_24:
    _qdf_mem_free(v25);
    *(_QWORD *)(a2 + 480) = 0;
  }
LABEL_25:
  v26 = *(_QWORD *)(a2 + 488);
  if ( v26 )
  {
    _qdf_mem_free(v26);
    *(_QWORD *)(a2 + 488) = 0;
  }
  result = 4294967274LL;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
