__int64 __fastcall dp_htt_tx_latency_stats_handler(__int64 result, __int64 a2)
{
  int v2; // w8
  unsigned int v3; // w22
  unsigned int *v4; // x21
  __int64 v5; // x19
  int v6; // w20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x1
  unsigned int v16; // w20
  _BYTE *v17; // x8
  int v18; // w8
  __int64 v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w4
  unsigned int *v29; // x21
  unsigned int v30; // t1
  __int64 v31; // x22
  unsigned int v32; // w23
  int v33; // w24
  unsigned int *v34; // x25
  __int64 v35; // x23
  __int64 v36; // [xsp+0h] [xbp-20h] BYREF
  __int64 v37; // [xsp+8h] [xbp-18h]
  __int64 v38; // [xsp+10h] [xbp-10h]
  __int64 v39; // [xsp+18h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
    v2 = *(unsigned __int16 *)(a2 + 66);
  else
    v2 = 0;
  v3 = *(_DWORD *)(a2 + 112) + v2;
  if ( v3 < 5 )
    goto LABEL_28;
  v4 = *(unsigned int **)(a2 + 224);
  v5 = *(_QWORD *)(result + 8);
  v37 = 0;
  v38 = 0;
  v36 = 0;
  v6 = (*v4 >> 8) & 3;
  result = wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v5 + 40));
  if ( (_DWORD)result )
  {
    if ( v6 )
      v15 = (unsigned int)(v6 - 1);
    else
      v15 = 0;
    v16 = ((__int64 (__fastcall *)(_QWORD, __int64))wlan_cfg_get_hw_mac_idx)(*(_QWORD *)(v5 + 40), v15);
    result = wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v5 + 40));
    if ( (_DWORD)result )
    {
      result = wlan_cfg_get_pdev_idx(*(_QWORD *)(v5 + 40), v16);
      if ( (_BYTE)result )
        goto LABEL_28;
    }
    v17 = *(_BYTE **)(v5 + 72);
    if ( !v17 || *v17 )
      goto LABEL_28;
  }
  else
  {
    v18 = v6 - 1;
    if ( !v6 )
      v18 = 0;
    if ( v18 )
      goto LABEL_28;
  }
  v19 = *(_QWORD *)(v5 + 72);
  if ( v19 )
  {
    ((void (__fastcall *)(__int64, __int64, unsigned int *, _QWORD))qdf_trace_hex_dump)(128, 4, v4, v3);
    v28 = v3 - 4;
    if ( (int)(v3 - 4) >= 1 )
    {
      v30 = *v4;
      v29 = v4 + 1;
      v31 = BYTE2(v30);
      v32 = (v30 >> 10) & 0xF;
      while ( 1 )
      {
        v33 = v28 - v31;
        if ( v28 < (unsigned int)v31 )
          break;
        v34 = v29;
        if ( (unsigned int)v31 <= 0x17 )
        {
          v34 = (unsigned int *)&v36;
          qdf_mem_set(&v36, 0x18u, 0);
          qdf_mem_copy(&v36, v29, (unsigned int)v31);
        }
        dp_tx_latency_stats_update_cca(v5, *v34, v32, v34 + 1, v34[5]);
        v29 = (unsigned int *)((char *)v29 + v31);
        v28 = v33;
        if ( v33 <= 0 )
          goto LABEL_27;
      }
      v35 = jiffies;
      if ( dp_htt_tx_latency_stats_handler___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: invalid payload size left %d - %d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_htt_tx_latency_stats_handler",
          v36,
          v37,
          v38,
          v39);
        dp_htt_tx_latency_stats_handler___last_ticks = v35;
      }
    }
LABEL_27:
    result = dp_tx_latency_stats_report(v5, v19);
  }
  else
  {
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: PDEV is NULL for pdev_id:%d",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "dp_htt_tx_latency_stats_handler",
               0,
               v36,
               v37,
               v38,
               v39);
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
